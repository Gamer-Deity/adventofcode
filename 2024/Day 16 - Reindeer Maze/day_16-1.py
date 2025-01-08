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
        for [y, x], dir, score in agents:
            input_print[y][x] = directions[dir % 4]
        for line in input_print:
            f.write("".join(line) + "\n")
        f.write(str(count) + "\n")

        for line in score_map:
            f.write(str(line) + "\n")
    time.sleep(0.1)

agents = [[(len(input) - 2, 1), 0, 0]] # [[pos, dir, score]]
score_map = [len(line) * [0] for line in input]
count = 0
while len(agents) > 0:
    count += 1
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
            if (fork[2] < result or result == 0) and (fork[2] < score_map[fork[0][0]][fork[0][1]] or score_map[fork[0][0]][fork[0][1]] == 0):
                score_map[fork[0][0]][fork[0][1]] = fork[2]
                if input[fork[0][0]][fork[0][1]] != 'E': 
                    new_agents.append(fork)
                else:
                    result = min(result, fork[2]) if result != 0 else fork[2]
    agents = new_agents
    # print(len(agents), agents)
    # fwrite_maze()
    # if count % 50 == 0: print("Score:", result, "| Step:", count, "| Time:", time.time() - start_time)

print(result)
print(time.time() - start_time)
