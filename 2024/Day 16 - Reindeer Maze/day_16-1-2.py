import time
start_time = time.time()

result = 0
with open("input_ex.txt", "r") as f:
    input = [list(line.strip()) for line in f]

moves = {'v': (1, 0), '^': (-1, 0), '<': (0, -1), '>': (0, 1)}
directions = ('>', '^', '<', 'v')
def move(pos, direction):
    return pos[0] + moves[direction][0], pos[1] + moves[direction][1]

def fwrite_maze():
    with open("output.txt", "w") as f:
        input_print = [[c for c in line] for line in input]
        for i in range(len(input_print)):
            for j in range(len(input_print)):
                if (i, j) in optimal_path[1]:
                    input_print[i][j] = '+'
        for [y, x], dir, score, path in agents:
            input_print[y][x] = directions[dir % 4]
        for line in input_print:
            f.write("".join(line) + "\n")
        f.write(str(count))
    time.sleep(0.2)

agents = [[[len(input) - 2, 1], 0, 0, []]] # [[pos, dir, score, path]]
optimal_path = [0, []]
count = 0
while len(agents) > 0:
    count += 1
    new_agents = []
    min_score = result
    for i in range(len(agents)):
        [y, x], dir, score, path = agents[i]
        forks = []
        for k in range(4):
            _y, _x = move((y, x), directions[(dir + k) % 4])
            if k != 2 and input[_y][_x] != '#':
                forks.append(((_y, _x), dir + k, score + 1 + 1000 * (k % 2), path + [(_y, _x)]))
        for fork in forks:
            if (input[fork[0][0]][fork[0][1]] != 'E') and (fork[2] < result or result == 0) and (fork[0] not in path):
                new_agents.append(fork)
            elif input[fork[0][0]][fork[0][1]] == 'E':
                result = min(result, fork[2]) if result != 0 else fork[2]
                optimal_path[1] = fork[3]
            if result == 0 and (fork[2] < min_score or min_score == 0):
                min_score = fork[2]
                optimal_path[1] = fork[3]
    agents = new_agents
    # print(len(agents), agents)
    # fwrite_maze()
    if count % 50 == 0: print("Score:", result, "| Step:", count, "| Time:", time.time() - start_time)

print(result)
print(time.time() - start_time)
