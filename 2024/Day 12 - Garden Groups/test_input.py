import time
start_time = time.time()

with open("input.txt", "r") as f:
    input = [line.strip() for line in f.readlines()]

N = 25
with open("input_test.txt", "w") as f:
    for i in range(N-1):
        f.write(input[i][0:N])
        f.write('\n')
    f.write(input[N-1][0:N])

print(time.time() - start_time)
