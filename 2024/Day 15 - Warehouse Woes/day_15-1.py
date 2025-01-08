import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [[list(line) for line in block.split()] for block in f.read().split("\n\n")]
for i in range(1, len(input[1])):
    input[1][0].extend(input[1][i])
layout, movements = input[0], input[1][0]

for i in range(len(input[0])):
    for j in range(len(input[0][i])):
        if input[0][i][j] == '@':
            robot = [i, j]

moves = {'<': (0, -1), '^': (-1, 0), '>': (0, 1), 'v': (1, 0)}
for move in movements:
    movey, movex = moves[move]
    y, x = i, j = robot
    while layout[y][x] != '#' and layout[y][x] != '.':
        y += movey
        x += movex
    if layout[y][x] == '.':
        robot = i + movey, j + movex
        layout[y][x] = layout[robot[0]][robot[1]]
        layout[i][j] = '.'
        layout[robot[0]][robot[1]] = '@'

for i in range(len(layout)):
    for j in range(len(layout[i])):
        if layout[i][j] == 'O':
            result += 100 * i + j
for line in layout:
        print(line)

print(result)
print(time.time() - start_time)
