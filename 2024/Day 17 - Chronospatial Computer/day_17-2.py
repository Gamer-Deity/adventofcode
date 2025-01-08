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
            output.append(combo[x]() % 8)
        case 6:
            B = A // 2 ** combo[x]()
        case 7:
            C = A // 2 ** combo[x]()

B = A % 8
B = B ^ 7
C = A // 2 ** B
B = B ^ 7
B = B ^ C
A = A // 8
out = B % 8
A == 0: loop  

11111 101
00000 111
11111 010



B = A & 8
B = B ^ 7
C = A >> B
B = B ^ 7
B = B ^ C
A = A >> 3
out = B & 8
A == 0: loop

A = B = C = 0
P = [2,4,1,7,7,5,1,7,4,6,0,3,5,5,3,0] # [0,3,5,4,3,0] - 117440
result = -1
output = []
while output != P:
    result += 1
    output = []
    A = result
    i = 0
    while i < len(P):
        op(P[i], P[i + 1])
        # print(i, A, B, C, result)
        i += 2
        if output != P[0:len(output)]:
            break
    if result % 1000000 == 0: print(result, time.time() - start_time)

print(result)
print(time.time() - start_time)
