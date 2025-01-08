import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [list(line.strip()) for line in f]

moves = {'v': (1, 0), '^': (-1, 0), '<': (0, -1), '>': (0, 1)}
directions = ('>', '^', '<', 'v')
def move(pos, direction):
    return pos[0] + moves[direction][0], pos[1] + moves[direction][1]

def fwrite_maze():
    with open("output.txt", "w") as f:
        input_print = [[c for c in line] for line in input]
        for (y, x), dir, score, path in agents:
            input_print[y][x] = directions[dir % 4]
        for line in input_print:
            f.write("".join(line) + "\n")
        f.write(str(count) + "\n")
    time.sleep(0.1)

agents = [[(len(input) - 2, 1), 0, 0]] # [[pos, dir, score]]
score_map = [len(line) * [0] for line in input]
while len(agents) > 0:
    new_agents = []
    min_score = result
    for i in range(len(agents)):
        (y, x), dir, score = agents[i]
        forks = []
        for k in range(4):
            _y, _x = move((y, x), directions[(dir + k) % 4])
            if k != 2 and input[_y][_x] != '#':
                forks.append(((_y, _x), dir + k, score + 1 + 1000 * (k % 2)))
        for fork in forks:
            if (fork[2] < result or result == 0) and (fork[2] <= score_map[fork[0][0]][fork[0][1]] or score_map[fork[0][0]][fork[0][1]] == 0):
                score_map[fork[0][0]][fork[0][1]] = fork[2]
                if input[fork[0][0]][fork[0][1]] != 'E': 
                    new_agents.append(fork)
                else:
                    result = min(result, fork[2]) if result != 0 else fork[2]
    agents = new_agents

pos = (1, len(input[1]) - 2)
paths = []
optimal_paths = set()
for k in range(4):
    y, x = move(pos, directions[k])
    if score_map[y][x] == score_map[pos[0]][pos[1]] - 1:
        agents.append(((y, x), k, 1, [(pos[0], pos[1]), (y, x)])) # [[pos, dir, score, path]]

count = 0
while len(agents) > 0:
    count += 1
    new_agents = []
    for i in range(len(agents)):
        (y, x), dir, score, path = agents[i]
        forks = []
        for k in range(4):
            _y, _x = move((y, x), directions[(dir + k) % 4])
            if k != 2 and input[_y][_x] != '#':
                forks.append(((_y, _x), (dir + k) % 4, score + 1 + 1000 * (k % 2), path + [(_y, _x)]))
        for fork in forks:
            if score_map[fork[0][0]][fork[0][1]] == score_map[y][x] - 1 or score_map[fork[0][0]][fork[0][1]] == score_map[y][x] - 1001 or score_map[fork[0][0]][fork[0][1]] == score_map[y][x] + 999:
                new_agents.append(fork)
            if fork[0] == (len(input) - 2, 1):
                paths.append((fork[2] + 1000 * (dir % 2), fork[3]))
    agents = new_agents
    # fwrite_maze()

paths.sort()
optimal_paths.update(set(paths[0][1]))
i = 1
while i < len(paths) and paths[i - 1][0] == paths[i][0]:
    optimal_paths.update(set(paths[i][1]))
    i += 1
for y, x in optimal_paths:
    input[y][x] = 'O'
# fwrite_maze()

print(len(optimal_paths))
print(time.time() - start_time)
