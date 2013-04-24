// To use this package :
// mkdir -p $HOME/go_workspace/src/queue
// export GOPATH=$HOME/go_workspace/
// cp -v queue.go $GOPATH/src/queue
// ( cd $GOPATH/src/; go install queue )
// then do an import "queue" in your source to use

package queue

type QueueMethods interface {
	Initialize(kind int)
	Add(val ListElement)
	Del(val ListElement)
	Iterate(Callback func(val ListElement))
	Find(key ListElement, findCallback func(val1 ListElement, val2 ListElement) bool) ListElement
	FindAndDel(key ListElement, findCallback func(val1 ListElement, val2 ListElement) bool) ListElement
}

const (
	Fifo = 1
	Lifo = 2
)

type Queue struct {
	head *List
	tail **List
	nodes int
	kind int
}

type ListElement interface {
	ListGet() *List
}

type List struct {
	next *List
	pprev **List
	val ListElement
}

func (queue *Queue) Initialize(kind int) {
	queue.head = nil
	queue.tail = &queue.head
	queue.nodes = 0
	queue.kind = kind
}

func NewQueue(kind int) *Queue {
	q := new(Queue)
	q.Initialize(kind)
	return q
}

func (queue *Queue) Iterate(Callback func(ListElement)) { 
	var next *List
	for iter := queue.head; iter != nil; iter = next {
		next = iter.next
		Callback(iter.val)
	}
}

func (queue *Queue) Add(val ListElement) {
	element := val.ListGet()
	element.val = val
	switch queue.kind {
	case Fifo: 
		element.next = nil
		element.pprev = queue.tail
		*queue.tail = element
		queue.tail = &element.next
	case Lifo:
		element.next = queue.head
		if element.next != nil {
			element.next.pprev = &element.next
		}
		element.pprev = queue.tail
		*element.pprev = element
	}
	queue.nodes++
}

func (queue *Queue) Del(val ListElement) {
	if queue.nodes == 0 {
		return
	}
	element := val.ListGet()
	if element.pprev != nil {
		if element.next != nil {
			element.next.pprev = element.pprev
		} else {
			if queue.kind == Fifo {
				queue.tail = element.pprev
			}
		}
		*element.pprev = element.next
		element.next = nil
		element.pprev = nil
		queue.nodes--
	}
}

func (queue *Queue) Find(key ListElement, findCallback func(ListElement, ListElement) bool) ListElement {
	for iter := queue.head; iter != nil; iter = iter.next {
		if findCallback(key, iter.val) { 
			return iter.val
		}
	}
	return nil
}

func (queue *Queue) FindAndDel(key ListElement, findCallback func(ListElement, ListElement) bool) ListElement {
	val := queue.Find(key, findCallback)
	if val == nil {
		return val
	}
	queue.Del(val)
	return val
}