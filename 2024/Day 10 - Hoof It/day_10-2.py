import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [list(map(int, list(line.strip()))) for line in f.readlines()]

zeroes = []
for i in range(len(input)):
    for j in range(len(input[i])):
        if input[i][j] == 0:
            zeroes.append((i, j))

def count_score(curr, head):
    score = 0
    y, x = curr
    
    if input[y][x] == 9:
        trails = heads.get(head, [])
        if (y, x) not in trails:
            trails.append((y, x))
        heads[head] = trails
        return 1
    
    for k in range(4):
        i = ((k + 1) % 2 - k // 2)
        j = 0 if i != 0 else (2 * k - 3)
        i += y
        j += x
        if i >= 0 and j >= 0 and i < len(input) and j < len(input[i]):
            if input[i][j] == input[y][x] + 1:
                # print((y, x), input[y][x], (i, j), input[i][j], k)
                score += count_score((i, j), head)
    # print()
    return score

heads = {}
for zero in zeroes:
    result += count_score(zero, zero)

# for head, trails in heads.items():
#     print(head, trails)

print(result)
print(time.time() - start_time)
