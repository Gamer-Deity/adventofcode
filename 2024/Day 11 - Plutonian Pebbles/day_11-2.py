import time
start_time = time.time()

result = 0
input = {}
with open("input.txt", "r") as f:
    for c in f.read().strip().split():
        input[int(c)] = input.get(int(c), 0) + 1

for k in range(75):
    new_input = {}
    for key, val in input.items():
        if key == 0:
            new_input[1] = new_input.get(1, 0) + val
        else:
            s = str(key)
            l = len(s)
            if l % 2 == 0:
                i1 = int(s[:l//2])
                i2 = int(s[l//2:])
                new_input[i1] = new_input.get(i1, 0) + val
                new_input[i2] = new_input.get(i2, 0) + val
            else:
                new_input[key * 2024] = new_input.get(key * 2024, 0) + val
    input = new_input
    # print(k, input)
# print()

for key in input.keys():
    result += input[key]
    
print(result)
print(time.time() - start_time)
