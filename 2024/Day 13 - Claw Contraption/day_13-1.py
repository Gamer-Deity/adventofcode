import re
import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = f.read()

matches = re.findall("Button A: X\+([0-9]+), Y\+([0-9]+)\n"
                   + "Button B: X\+([0-9]+), Y\+([0-9]+)\n"
                   + "Prize: X=([0-9]+), Y=([0-9]+)", input)

for match in matches:
    combinations = []
    for i in range(100):
        for j in range(100):
            if i * int(match[0]) + j * int(match[2]) == int(match[4]) and i * int(match[1]) + j * int(match[3]) == int(match[5]):
                combinations.append(3 * i + j)
    if len(combinations) > 0:
        combinations.sort()
        result += combinations[0]

print(result)
print(time.time() - start_time)
