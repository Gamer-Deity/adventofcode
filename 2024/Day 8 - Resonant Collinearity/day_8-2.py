with open("input.txt", "r") as f:
    input = [list(line.strip()) for line in f.readlines()]

antennas = {}
for i in range(len(input)):
    for j in range(len(input[i])):
        if input[i][j] != '.':
            antenna = antennas.get(input[i][j], [])
            antenna.append((i, j))
            antennas[input[i][j]] = antenna

def add_pos(pos1, pos2):
    return (pos1[0] + pos2[0], pos1[1] + pos2[1])

def sub_pos(pos1, pos2):
    return (pos1[0] - pos2[0], pos1[1] - pos2[1])

antinodes = {}
valid_antinodes = {}
for type, positions in antennas.items():
    if len(positions) == 1:
        continue
    for pos1 in positions:
        for pos2 in positions:
            if pos1 == pos2:
                continue
            pos11 = pos1
            while pos11[0] >= 0 and pos11[0] < len(input) and pos11[1] >= 0 and pos11[1] < len(input[0]):
                antinodes[pos11] = antinodes.get(pos11, 0) + 1
                pos11 = add_pos(pos11, sub_pos(pos1, pos2))
            pos22 = pos2
            while pos22[0] >= 0 and pos22[0] < len(input) and pos22[1] >= 0 and pos22[1] < len(input[0]):
                antinodes[pos22] = antinodes.get(pos22, 0) + 1
                pos22 = add_pos(pos22, sub_pos(pos2, pos1))

for antinode in antinodes.keys():
    if antinode[0] >= 0 and antinode[0] < len(input) and antinode[1] >= 0 and antinode[1] < len(input[0]):
        valid_antinodes[antinode] = antinodes[antinode]

result = len(valid_antinodes.keys())

for antinode in valid_antinodes: input[antinode[0]][antinode[1]] = '#'
for line in input: print(line)

print(result)
