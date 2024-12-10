input = []
result = 0
with open("input.txt", "r") as file:
    for line in file:
        input.append(line.strip().split())

for line in input:
    for i in range(len(line)):
        line[i] = int(line[i])

for i in range(len(input)):
    valid = True
    decreasing = True
    increasing = True
    for j in range(len(input[i]) - 1):
        if input[i][j + 1] >= input[i][j]:
            decreasing = False
        if input[i][j + 1] <= input[i][j]:
            increasing = False
        if abs(input[i][j + 1] - input[i][j]) > 3:
            valid = False
    if not increasing and not decreasing:
        valid = False
    if valid:
        result += 1

print(result)
