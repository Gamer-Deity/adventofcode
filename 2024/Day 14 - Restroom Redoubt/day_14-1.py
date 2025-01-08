import re
import time
start_time = time.time()

result = 1
with open("input.txt", "r") as f:
    input = f.read()

width, height = 101, 103 # 11, 7
half_width, half_height = width // 2, height // 2
matches = [tuple(map(int, match)) for match in re.findall("p=(\-?[0-9]+),(\-?[0-9]+) v=(\-?[0-9]+),(\-?[0-9]+)", input)]
ends = {}
regions = 4 * [0]
for px, py, vx, vy in matches:
    key = ((py + 100 * vy) % height, (px + 100 * vx) % width)
    ends[key] = ends.get(key, 0) + 1
for (endy, endx), val in ends.items():
    if endx != half_width and endy != half_height:
        regions[endx // (half_width + 1) + 2 * (endy // (half_height + 1))] += val

for region in regions:
    result *= region

print(result)
print(time.time() - start_time)

# Print map
cmap = [width * ['.'] for i in range(height)]
for (endy, endx), val in ends.items():
    cmap[endy][endx] = val
for i in range(len(cmap)):
    for j in range(len(cmap[i])):
        if i == half_height or j == half_width: cmap[i][j] = ' '
        print(cmap[i][j], end='')
    print()
