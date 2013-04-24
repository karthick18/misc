package main
import (
	"queue"
	"fmt")

type Profile struct {
	queue.List //embedded field
	name string
	email string
}

// Implement the get list method for the queue value
func (p *Profile) ListGet() *queue.List {
	return &p.List
}

func dumpProfile(val queue.ListElement) {
	p := val.(*Profile)
	fmt.Printf("Name [%s], Email [%s]\n", p.name, p.email)
}

func findProfile(key queue.ListElement, val queue.ListElement) bool { 
	p := val.(*Profile)
	k := key.(*Profile)
	return k.name == p.name
}

func testQueue(count int, kind int, s string) {
	var q *queue.Queue = queue.NewQueue(kind)
	if count == 0 { 
		count = 100
	}
	profiles := make([]Profile, count)
	for i := range profiles {
		p := &profiles[i]
		p.name = fmt.Sprintf("name_%d", i)
		p.email = fmt.Sprintf("name_%d@gmail.com", i)
		q.Add(p)
	}
	fmt.Println("Dumping", s)
	q.Iterate(dumpProfile)
	//throw out half of them
	for i := range profiles[:cap(profiles)/2] {
		//make a key for delete
		p := &Profile{name:fmt.Sprintf("name_%d", i)}
		v := q.FindAndDel(p, findProfile)
		p = v.(*Profile)
		fmt.Printf("Deleted element [%s]\n", p.name)
		//q.Del(&profiles[i])
	}
	fmt.Println("Dumping", s)
	q.Iterate(dumpProfile)
}	

func main() {
	count := 100
	testQueue(count, queue.Fifo, "Fifo")
	testQueue(count, queue.Lifo, "Lifo")
}
