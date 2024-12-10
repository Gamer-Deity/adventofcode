result = 0
with open("input.txt", "r") as file:
    input = file.readlines()

left = []
right = []

for i in input:
    line = i.split()
    left.append(int(line[0]))
    right.append(int(line[1]))

left.sort()
right.sort()

for i in range(len(left)):
    count = 0
    for j in range(len(right)):
        if left[i] == right[j]:
            count += 1
    result += left[i] * count

print(result)
