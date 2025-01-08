import time
start_time = time.time()

with open("input.txt", "r") as f:
    input = [list(map(int, line.split(','))) for line in f.readlines()]

moves = {'v': (1, 0), '^': (-1, 0), '<': (0, -1), '>': (0, 1)}
directions = ('>', '^', '<', 'v')
def move(pos, direction):
    return pos[0] + moves[direction][0], pos[1] + moves[direction][1]

def add_padding(array):
    new_array = [(len(array[0]) + 2) * "#"]
    for line in array:
        new_array.append(list("#" + "".join(line) + "#"))
    new_array.append((len(array[0]) + 2) * "#")
    return new_array

def fwrite_maze():
    with open("output.txt", "w") as f:
        input_print = [[c for c in line] for line in space]
        for [y, x], dir, score in agents:
            input_print[y][x] = directions[dir % 4]
        for line in input_print:
            f.write("".join(line) + "\n")
        f.write(str(count) + "\n")

        input_print = [[c for c in line] for line in score_space]
        for line in input_print:
            f.write(str(line) + "\n")
    time.sleep(0.1)

LIMIT = 1024 # 12
SIZE = 71 # 7
space = [SIZE * ['.'] for i in range(SIZE)]
for x, y in input[0:LIMIT]:
    space[y][x] = '#'
space = add_padding(space)

byte = LIMIT
while True:
    result = 0
    space[input[byte][1] + 1][input[byte][0] + 1] = '#'
    score_space = [(SIZE + 2) * [0] for i in range(SIZE + 2)]
    agents = [[(1, 1), 0, 0]] # [[pos, dir, score]]
    count = 0
    while len(agents) > 0:
        # print(len(agents), agents)
        # fwrite_maze()

        count += 1
        new_agents = []
        for i in range(len(agents)):
            [y, x], dir, score = agents[i]
            forks = []
            for k in range(4):
                _y, _x = move((y, x), directions[(dir + k) % 4])
                if k != 2 and space[_y][_x] != '#':
                    forks.append(((_y, _x), (dir + k) % 4, score + 1))
            for fork in forks:
                if (fork[0] != (len(space) - 2, len(space) - 2)) and (fork[2] < result or result == 0) and (fork[2] < score_space[fork[0][0]][fork[0][1]] or score_space[fork[0][0]][fork[0][1]] == 0):
                    new_agents.append(fork)
                    score_space[fork[0][0]][fork[0][1]] = fork[2]
                elif fork[0] == (len(space) - 2, len(space) - 2):
                    result = min(result, fork[2]) if result != 0 else fork[2]
        agents = new_agents
    # fwrite_maze()
    if result == 0:
        break
    # print(result, byte, input[byte])
    byte += 1

print(str(input[byte]).replace('[', '').replace(']', '').replace(' ', ''))
print(time.time() - start_time)
