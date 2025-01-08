import re
import time
start_time = time.time()

with open("input.txt", "r") as f:
    input = f.read()

width, height = 101, 103 # 11, 7
matches = [tuple(map(int, match)) for match in re.findall("p=(\-?[0-9]+),(\-?[0-9]+) v=(\-?[0-9]+),(\-?[0-9]+)", input)]
with open("output.txt", "w") as f:
    for k in range(10000):
        ends = {}
        for px, py, vx, vy in matches:
            key = ((py + k * vy) % height, (px + k * vx) % width)
            ends[key] = ends.get(key, 0) + 1
        cmap = [width * ['.'] for i in range(height)]
        for (endy, endx), val in ends.items():
            cmap[endy][endx] = val
        bad = False
        for line in cmap:
            for c in line:
                if c != '.' and c != 1:
                    bad = True
        if not bad:
            f.write("\n" + str(k) + "\n")
            for line in cmap:
                for element in line:
                    f.write(str(element))
                f.write("\n")

print(time.time() - start_time)
