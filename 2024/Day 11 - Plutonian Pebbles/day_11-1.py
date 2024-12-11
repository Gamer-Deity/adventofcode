import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [int(c) for c in f.read().strip().split()]

for k in range(25):
    new_input = []
    for i in range(len(input)):
        val = input[i]
        if val == 0:
            new_input.append(1)
        else:
            s = str(val)
            l = len(s)
            if l % 2 == 0:
                new_input.append(int(s[:l//2]))
                new_input.append(int(s[l//2:]))
            else:
                new_input.append(val * 2024)
    input = new_input

result = len(input)

print(result)
print(time.time() - start_time)
