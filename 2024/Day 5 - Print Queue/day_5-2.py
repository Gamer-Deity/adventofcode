rules = {}
updates = []
result = 0
with open("input.txt", "r") as file:
    for line in file:
        n1, n2 = line.strip().split('|')
        n1 = int(n1)
        n2 = int(n2)
        if n1 in rules.keys():
            rules[n1].append(n2)
        else:
            rules[n1] = [n2]

with open("input2.txt", "r") as file:
    for line in file:
        updates.append(line.strip().split(','))
for line in updates:
    for i in range(len(line)):
        line[i] = int(line[i])

for i in range(len(updates)):
    valid = True
    for j in range(len(updates[i]) - 1, -1, -1):
        if updates[i][j] not in rules.keys():
            continue
        for k in range(j):
            if updates[i][k] in rules[updates[i][j]]:
                valid = False
                l = j
                while l < len(updates[i]) and updates[i][l] in rules.keys() and updates[i][k] in rules[updates[i][l]]:
                    l += 1
                new_number = updates[i][k]
                updates[i].pop(k)
                updates[i].insert(l - 1, new_number)
                break
    if not valid:
        result += updates[i][len(updates[i]) // 2]

print(result)
