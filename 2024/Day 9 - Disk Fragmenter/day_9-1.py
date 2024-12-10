import time
start_time = time.time()

result = 0
with open("input_ex.txt", "r") as f:
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

def checkSum(size, i, j):
    if size == 0: return 0
    val = i
    i0 = sum(in_files[0:(j + 1)]) + sum(in_free[0:j]) + in_free[j] - free[j]
    i1 = i0 + size - 1
    res = val * (i1 + i0) * (i1 - i0 + 1) // 2
    # print(res, result + res, free, files, i0)
    return res

i = len(files) - 1
j = 0
while j < len(free):
    size = min(free[j], files[i])
    result += checkSum(size, i, j)
    free[j] -= size
    files[i] -= size
    if free[j] == 0:
        j += 1
    if files[i] == 0:
        i -= 1
        free.pop(len(free) - 1)

for k in range(i + 1):
    result += checkSum(files[k], k, k - 1)

print(result)
print(time.time() - start_time)
