import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [line.strip().split('-') for line in f.readlines()]

connections = {}
for pair in input:
    l = connections.get(pair[0], [])
    l.append(pair[1])
    connections[pair[0]] = l
    l = connections.get(pair[1], [])
    l.append(pair[0])
    connections[pair[1]] = l

groups = []
for computer, cons in connections.items():
    if computer[0] == 't':
        for i in range(len(cons)):
            for j in range(i, len(cons)):
                if cons[i] in connections[cons[j]]:
                    group = sorted([computer, cons[i], cons[j]])
                    if group not in groups:
                        groups.append(group)
                        result += 1

print(result)
print(time.time() - start_time)
