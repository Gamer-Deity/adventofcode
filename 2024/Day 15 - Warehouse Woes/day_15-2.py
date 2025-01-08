import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [[list(line) for line in block.split()] for block in f.read().split("\n\n")]
for i in range(1, len(input[1])):
    input[1][0].extend(input[1][i])
layout, movements = [], input[1][0]
for i in range(len(input[0])):
    layout.append([])
    for j in range(len(input[0][i])):
        layout[i].append(input[0][i][j])
        match(input[0][i][j]):
            case '@':
                robot = [i, len(layout[i]) - 1]
                layout[i].append('.')
            case 'O':
                layout[i][len(layout[i]) - 1] = '['
                layout[i].append(']')
            case _:
                layout[i].append(input[0][i][j])

def check_move(pos, dir):
    y, x = pos[0] + dir, pos[1]
    match(layout[y][x]):
        case '#':
            return False
        case '.':
            return True
        case '[':
            return check_move((y, x), dir) and check_move((y, x + 1), dir)
        case ']':
            return check_move((y, x), dir) and check_move((y, x - 1), dir)    

def make_move(pos, dir):
    y, x = pos[0], pos[1]
    match(layout[y + dir][x]):
        case '[':
            make_move((y + dir, x), dir)
            make_move((y + dir, x + 1), dir)
        case ']':
            make_move((y + dir, x), dir)
            make_move((y + dir, x - 1), dir)
    layout[y + dir][x] = layout[y][x]
    layout[y][x] = '.'

def print_layout():
    for line in layout:
        print(line)
    print()

moves = {'<': (0, -1), '^': (-1, 0), '>': (0, 1), 'v': (1, 0)}
for move in movements:
    # print(move, moves[move], robot)
    # print_layout()
    movey, movex = moves[move]
    y, x = i, j = robot
    if movey == 0:
        while layout[y][x] != '#' and layout[y][x] != '.':
            x += movex
        if layout[y][x] == '.':
            aux = layout[i][j]
            k = j + movex
            while k != x + movex:
                aux2 = aux
                aux = layout[i][k]
                layout[i][k] = aux2
                k += movex
            layout[robot[0]][robot[1]] = '.'
            robot = i + movey, j + movex
            layout[robot[0]][robot[1]] = '@'
    else:
        if(check_move(robot, moves[move][0])):
            make_move(robot, moves[move][0])
            robot = i + movey, j + movex

print_layout()

for i in range(len(layout)):
    for j in range(len(layout[i])):
        if layout[i][j] == '[':
            result += 100 * i + j

print(result)
print(time.time() - start_time)
