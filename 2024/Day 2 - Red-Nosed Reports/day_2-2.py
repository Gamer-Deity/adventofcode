input = []
result = 0
with open("input.txt", "r") as file:
    for line in file:
        input.append(line.strip().split())

for line in input:
    for i in range(len(line)):
        line[i] = int(line[i])

def checkLine(line):
    valid = True
    decreasing = True
    increasing = True

    for j in range(len(line) - 1):
        if line[j + 1] >= line[j]:
            decreasing = False
        if line[j + 1] <= line[j]:
            increasing = False
        if (abs(line[j + 1] - line[j]) > 3) or (not increasing and not decreasing):
            valid = False

    return valid

for i in range(len(input)):
    if checkLine(input[i]):
        result += 1
    else:
        for j in range(len(input[i])):
            # print(input[i], "|", input[i][0:j] + input[i][j + 1:], "|", checkLine(input[i][0:j] + input[i][j + 1:]))
            if checkLine(input[i][0:j] + input[i][j + 1:]):
                result += 1
                break

print(result)
