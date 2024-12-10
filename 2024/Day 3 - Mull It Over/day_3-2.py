import re

result = 0
with open("input.txt", "r") as file:
    input = file.read()

matches = re.findall("|".join(["(do\(\))", "(don't\(\))", "mul\(([0-9]+),([0-9]+)\)"]), input)
# print(matches)

valid = True
for match in matches:
    if match[0]:
        valid = True
    if match[1]:
        valid = False
    if match[2] and valid:
        result += int(match[2]) * int(match[3])

print(result)
