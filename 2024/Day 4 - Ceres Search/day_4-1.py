import re

input = []
result = 0
with open("input.txt", "r") as file:
    for line in file:
        input.append(list(line.strip()))

for line in input:
    result += len(re.findall("XMAS", ''.join(line))) + len(re.findall("SAMX", ''.join(line)))

_input = [['' for i in range(len(input))] for j in range(len(input))]
for i in range(len(input)):
    for j in range(len(input)):
        _input[j][i] = input[i][j]
for line in _input:
    result += len(re.findall("XMAS", ''.join(line))) + len(re.findall("SAMX", ''.join(line)))

for i in range(len(input) - 3):
    for j in range(len(input) - 3):
        k = 0
        diag = ""
        while k < 4:
            diag += input[i + k][j + k]
            k += 1
        if diag == "XMAS" or diag == "SAMX":
            result += 1

for i in range(len(input) - 3):
    for j in range(len(input) - 3):
        k = 0
        diag = ""
        while k < 4:
            diag += input[len(input) - 1 - (i + k)][(j + k)]
            k += 1
        if diag == "XMAS" or diag == "SAMX":
            result += 1

print(result)
