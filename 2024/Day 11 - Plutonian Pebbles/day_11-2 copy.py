import time
start_time = time.time()

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class dll:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def insert_tail(self, node):
        self.size += 1
        if self.head == None:
            self.head = self.tail = node
            return
        else:
            self.tail.next = node
            self.tail = node
    
    def insert(self, node, new_node):
        self.size += 1
        if self.tail == node:
            self.tail = new_node
        new_node.next = node.next
        node.next = new_node

line = dll()
result = 0
with open("input.txt", "r") as f:
    for i in f.read().strip().split():
        node = Node(int(i))
        line.insert_tail(node)

for k in range(75):
    last_time = time.time()
    curr = line.head
    while curr:
        val = curr.data
        if val == 0:
            curr.data = 1
        else:
            s = str(val)
            l = len(s)
            if l % 2 == 0:
                curr.data = int(s[:l//2])
                line.insert(curr, Node(int(s[l//2:])))
                curr = curr.next
            else:
                curr.data = val * 2024
        curr = curr.next
    print(k, line.size, time.time() - last_time)

result = line.size

print(result)
print(time.time() - start_time)
