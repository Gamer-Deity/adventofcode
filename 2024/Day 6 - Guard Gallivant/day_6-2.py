input = []
passed = {}
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]
result = 0

with open("input.txt", "r") as file:
    for line in file:
        input.append(list(line.strip()))

def checkLoop(x, y):
    direction = 0
    _passed = {}
    pos = [0, 0]
    _input = [[char for char in line] for line in input]
    for i in range(len(input)):
        for j in range(len(input[i])):
            if input[i][j] == '^':
                pos = [i, j]

    if x >= 0 and y >= 0 and (x, y) != (pos[0], pos[1]):
        _input[x][y] = 'O'

    loop = False
    running = True
    __input = [[char for char in line] for line in _input]
    while(running):
        __input[pos[0]][pos[1]] = ['^', '>', 'v', '<'][direction % 4]
        next = [pos[0] + directions[direction % 4][0], pos[1] + directions[direction % 4][1]]
        if next[0] < 0 or next[0] >= len(_input) or next[1] < 0 or next[1] >= len(_input[0]):
            running = False
        if running and (_input[next[0]][next[1]] == '#' or _input[next[0]][next[1]] == 'O'):
            direction += 1
        else:
            if (pos[0], pos[1]) not in _passed:
                _passed[(pos[0], pos[1])] = [0, 0, 0, 0]
            _passed[(pos[0], pos[1])][direction % 4] += 1
            if _passed[(pos[0], pos[1])][direction % 4] > 1:
                running = False
                loop = True
            pos[0] += directions[direction % 4][0]
            pos[1] += directions[direction % 4][1]

    return loop, _passed, __input

loop, passed, _input = checkLoop(-1, -1)

count = 0
obst_tries = []
for coord, dir in passed.items():
    count += 1
    if not (coord[0] <= 0 or coord[0] >= len(input) - 1 or coord[1] <= 0 or coord[1] >= len(input[0]) - 1):
        for i in range(len(dir)):
            x = coord[0] + directions[i][0]
            y = coord[1] + directions[i][1]
            if dir[i] > 0 and (x, y) not in obst_tries:
                obst_tries.append((x, y))
                loop, _passed, _input = checkLoop(x, y)
                if loop:
                    result += 1
                    # print(count, result)
                    '''for line in _input:
                        print(line)
                    print(count, result, coord, dir)
                    print()'''

print(result)
