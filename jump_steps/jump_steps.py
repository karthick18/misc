# You are given a list of numbers and a starting position.
# Your goal is to find a sequence of jumps from the starting position to the end of the list.
# A valid jump at any position must be between zero and the value at that position in the list, i.e. list[pos], inclusive.
# You must return a list of valid jumps in sequence that lead to the end of the list, or null if no such sequence exists.
# The list can have negative numbers as well that needs to be handled
# The goal is to find minimum number of jumps to reach the end of the list that can also include negative numbers.

from collections import defaultdict

class StepGraph(object):

    def __init__(self, array):
        self.graph = defaultdict(list)
        self.array = array
        self.stop_index = len(array)
        for index in xrange(self.stop_index):
            self.add(index)

    def add(self, index):
        step = 1
        value = self.array[index]
        if value < 0:
            step = -1
        for i in xrange(0, value, step):
            next_index = i + step + index
            self.add_connection(index, next_index)

    def add_connection(self, index, next_index):
        if next_index < 0:
            return
        if next_index >= self.stop_index:
            next_index = self.stop_index
        self.graph[index].append(next_index)

    #find the shortest path from start index to the end index
    def find_shortest_path(self, start_index, path = []):
        path = path + [start_index]
        if start_index == self.stop_index:
            return path
        if start_index not in self.graph:
            return None
        value = self.array[start_index]
        if value == 0:
            return None
        shortest = None
        for next_index in self.graph[start_index]:
            if next_index in path:
                continue
            new_path = self.find_shortest_path(next_index, path)
            if new_path:
                if not shortest or len(new_path) < len(shortest):
                    shortest = new_path

        return shortest

    def steps_to_end_of_list(self, start_pos = 0):
        shortest_path = self.find_shortest_path(start_pos)
        if shortest_path:
            return self.path_to_steps(shortest_path)
        else:
            return None

    @classmethod
    def path_to_steps(cls, shortest_path):
        steps_taken = []
        #just skip the first step which is our own start position
        if len(shortest_path) > 1:
            last_pos = shortest_path[0]
            for pos in shortest_path[1:]:
                steps_taken.append(pos - last_pos)
                last_pos = pos
        else:
            steps_taken.append(0)

        return steps_taken

if __name__ == '__main__':
    sequence = ( (0, (1, 2, 0) ),
                 (0, (2, 3, 0, 2, 2) ),
                 (2, (1, 7, 2, 2, -4, 1, 1, 4, -2, 1, 1) ),
                 ## negative inputs
                 (0, (1, 2, 0, 0, 2, 3, 4, 6, 7, 5) ),
                 (0, (1, 3, 0, 1, -2, 2, 3, 4, 6, 7, 5) ),
                 )
    for start_pos, array in sequence:
        step_graph = StepGraph(array)
        steps = step_graph.steps_to_end_of_list(start_pos)
        if steps:
            print('%s' %(steps))
        else:
            print('No path found from position: %d for list %s' %(start_pos, array))
