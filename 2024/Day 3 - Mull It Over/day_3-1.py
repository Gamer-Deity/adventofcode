import re

result = 0
with open("input.txt", "r") as file:
    input = file.read()

matches = re.findall("mul\(([0-9]+),([0-9]+)\)", input)
# print(matches)

for match in matches:
    result += int(match[0]) * int(match[1])

print(result)
