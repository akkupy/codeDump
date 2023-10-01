import random
class Node:
    def __init__(self, value):
        self.value = value
        self.children = []
    def add_child(self, child):
        self.children.append(child)
    def bfs(self):
        queue = [self]
        visited = set()
        while queue:
            node = queue.pop(0)
            if node not in visited:
                visited.add(node)
                for child in node.children:
                    queue.append(child)
        return visited
root = Node(random.randint(1, 100))
for i in range(10):
    child = Node(random.randint(1, 100))
    root.add_child(child)
# Perform a breadth-first search on the tree
visited = root.bfs()
for node in visited:
    print(node.value)
