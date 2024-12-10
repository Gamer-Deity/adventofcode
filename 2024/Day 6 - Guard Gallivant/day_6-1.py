input = []
passed = []
result = 0
with open("input.txt", "r") as file:
    for line in file:
        input.append(list(line.strip()))
        passed.append(list(line.strip()))

pos = [0, 0]
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
direction = 0
for i in range(len(input)):
    for j in range(len(input[i])):
        if input[i][j] == '^':
            pos = [i, j]
            passed[i][j] = '.'

running = True
while(running):
    next = [pos[0] + directions[direction % 4][0], pos[1] + directions[direction % 4][1]]
    if next[0] < 0 or next[0] >= len(input) or next[1] < 0 or next[1] >= len(input[0]):
        running = False
    if running and input[next[0]][next[1]] == '#':
        direction += 1
    else:
        if passed[pos[0]][pos[1]] == '.':
            passed[pos[0]][pos[1]] = 'X'
            result += 1
        pos[0] += directions[direction % 4][0]
        pos[1] += directions[direction % 4][1]

'''for line in passed:
    print(line)
print()'''

print(result)
