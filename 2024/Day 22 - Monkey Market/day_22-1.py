import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [int(line) for line in f.readlines()]

for num in input:
    for i in range(2000):
        num = ((num * 64) ^ num) % 16777216
        num = ((num // 32) ^ num) % 16777216
        num = ((num * 2048) ^ num) % 16777216
    result += num

print(result)
print(time.time() - start_time)
