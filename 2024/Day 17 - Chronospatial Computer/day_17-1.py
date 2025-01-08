import time
start_time = time.time()

combo = [lambda: 0, lambda: 1, lambda: 2, lambda: 3, lambda: A, lambda: B, lambda: C]
def op(o, x):
    global i, A, B, C, result
    match(o):
        case 0:
            A = A // 2 ** combo[x]()
        case 1:
            B = B ^ x
        case 2:
            B = combo[x]() % 8
        case 3:
            if A != 0:
                i = x - 2
        case 4:
            B = B ^ C
        case 5:
            result.append(combo[x]() % 8)
        case 6:
            B = A // 2 ** combo[x]()
        case 7:
            C = A // 2 ** combo[x]()

A = 66245665 # 729
B = C = 0
P = [2,4,1,7,7,5,1,7,4,6,0,3,5,5,3,0] # [0,1,5,4,3,0]
result = []
i = 0
while i < len(P):
    op(P[i], P[i + 1])
    # print(i, A, B, C, result)
    i += 2

print(str(result).replace('[', '').replace(']', '').replace(' ', ''))
print(time.time() - start_time)
