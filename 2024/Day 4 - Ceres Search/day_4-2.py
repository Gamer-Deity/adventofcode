input = []
result = 0
with open("input.txt", "r") as file:
    for line in file:
        input.append(list(line.strip()))

for i in range(1, len(input) - 1):
    for j in range(1, len(input) - 1):
        if input[i][j] == 'A':
            diag1 = ''.join([input[i - 1][j - 1], input[i][j], input[i + 1][j + 1]])
            diag2 = ''.join([input[i + 1][j - 1], input[i][j], input[i - 1][j + 1]])
            # print(diag1, diag2, i + 1, j + 1, (diag1 == "MAS" or diag1 == "SAM") and (diag2 == "MAS" or diag2 == "SAM"))
            if (diag1 == "MAS" or diag1 == "SAM") and (diag2 == "MAS" or diag2 == "SAM"):
                result += 1

print(result)
