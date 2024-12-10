import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [int(c) for c in f.read().strip()]

in_files = []
in_free = []
for i in range(len(input)):
    if i % 2 == 0:
        in_files.append(input[i])
    else:
        in_free.append(input[i])
# print("Files:", in_files)
# print("Free:", in_free)

files = in_files.copy()
free = in_free.copy()

def checkSum(size, i, j, flag):
    if size == 0: return 0
    val = i
    i0 = sum(in_files[0:(j + 1)]) + sum(in_free[0:j]) + in_free[j] - free[j] * flag
    i1 = i0 + size - 1
    res = val * (i1 + i0) * (i1 - i0 + 1) // 2
    # print(res, result + res, free, files, i0, i, j)
    return res

i = len(files) - 1
while i >= 0:
    j = 0
    while j < i:
        size = min(free[j], files[i])
        if size == files[i]:
            result += checkSum(size, i, j, 1)
            free[j] -= size
            files[i] -= size
            break
        j += 1
    i -= 1

for k in range(len(files)):
    if files[k] != 0:
        result += checkSum(files[k], k, k - 1, 0)

print(result)
print(time.time() - start_time)
