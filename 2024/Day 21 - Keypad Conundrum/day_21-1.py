import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = list(f.readlines())
nums = [int(line.replace('A', '')) for line in input]



print(result)
print(time.time() - start_time)
