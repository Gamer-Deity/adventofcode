import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    raw_input = [line.strip() for line in f.readlines()]

input = [(len(raw_input[0]) + 2) * "#"]
for line in raw_input:
    input.append("#" + line + "#")
input.append((len(raw_input[0]) + 2) * "#")

def propagate_region(i, j):
    count = 0
    for k in range(4):
        y = i + ((k + 1) % 2 - k // 2)
        x = j + (0 if y != i else (2 * k - 3))
        if input[y][x] != input[i][j]:
            count += 1
        elif region_map[y][x] == -1:
            region_map[y][x] = region_map[i][j]
            propagate_region(y, x)
    regions[region_map[i][j]][0] += 1
    regions[region_map[i][j]][1] += count

def add_region(i, j):
    region_map[i][j] = len(regions)
    regions.append([0, 0, input[i][j]])
    propagate_region(i, j)

region_map = [len(input[i]) * [-1] for i in range(len(input))]
regions = []
for i in range(1, len(input) - 1):
    for j in range(1, len(input[i]) - 1):
        if region_map[i][j] == -1:
            add_region(i, j)

for region in regions:
    result += region[0] * region[1]

print(result)
print(time.time() - start_time)
