import time
start_time = time.time()

def add_padding(array):
    new_array = [(len(array[0]) + 2) * "#"]
    for line in array:
        new_array.append("#" + line + "#")
    new_array.append((len(array[0]) + 2) * "#")
    return new_array

def propagate_region(i, j):
    for k in range(4):
        y = i + ((k + 1) % 2 - k // 2)
        x = j + (0 if y != i else (2 * k - 3))
        if input[y][x] == input[i][j] and region_map[y][x] == -1:
            region_map[y][x] = region_map[i][j]
            propagate_region(y, x)
    regions[region_map[i][j]][0] += 1

def add_region(i, j):
    region_map[i][j] = len(regions)
    regions.append([0, 0, input[i][j], (i, j)])
    propagate_region(i, j)

def count_sides(i, j):
    sides = count = 0
    for k in range(4):
        y = i - 1 + k // 3
        x = j - 1 + k % 3
        if input[y][x] == input[i][j] and region_map[y][x] == region_map[i][j]:
            count += 10 ** k
    match(count):
        case 1011 | 1010:
            sides = -2
        case 1101 | 1001 | 110 | 11:
            sides = 2
        case 111 | 101 | 100 | 1 | 0:
            sides = 4
    return sides

result = 0
with open("input.txt", "r") as f:
    raw_input = [line.strip() for line in f.readlines()]

input = add_padding(raw_input)
region_map = [len(input[i]) * [-1] for i in range(len(input))]
regions = []
for i in range(1, len(input) - 1):
    for j in range(1, len(input[i]) - 1):
        if region_map[i][j] == -1:
            add_region(i, j)
for i in range(1, len(input) - 1):
    for j in range(1, len(input[i]) - 1):
        regions[region_map[i][j]][1] += count_sides(i, j)

for region in regions:
    result += region[0] * region[1]

#print(regions)
#for line in region_map:
#    print(line)

print(result)
print(time.time() - start_time)
