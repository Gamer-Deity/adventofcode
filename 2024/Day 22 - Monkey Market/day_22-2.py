import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = [int(line) for line in f.readlines()]

def next_secret(num):
    num = ((num * 64) ^ num) % 16777216
    num = ((num // 32) ^ num) % 16777216
    return ((num * 2048) ^ num) % 16777216

secrets = []
changes = []
for i in range(len(input)):
    secrets.append([])
    changes.append([])
    num = input[i]
    for j in range(2000):
        new_num = next_secret(num)
        secrets[i].append(new_num % 10)
        changes[i].append(new_num % 10 - num % 10)
        num = new_num

sequences = {}
for i in range(len(secrets)):
    past_sequences = []
    for j in range(len(changes[i]) - 3):
        sequence = tuple(changes[i][j:j + 4])
        if sequence not in past_sequences:
            past_sequences.append(sequence)
            sequences[sequence] = sequences.get(sequence, 0) + secrets[i][j + 3]
    if i % 50 == 0: print(f"{i}/{len(secrets)} - {time.time() - start_time}")

result = max(sequences.values())

print(result)
print(time.time() - start_time)
