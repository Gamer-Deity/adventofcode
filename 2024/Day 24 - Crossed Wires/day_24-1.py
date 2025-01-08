import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [line.strip().split('-') for line in f.readlines()]



print(result)
print(time.time() - start_time)
