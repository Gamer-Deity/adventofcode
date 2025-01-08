import re
import time
start_time = time.time()

result = 0
with open("input.txt", "r") as f:
    input = f.read()

matches = re.findall("Button A: X\+([0-9]+), Y\+([0-9]+)\n"
                   + "Button B: X\+([0-9]+), Y\+([0-9]+)\n"
                   + "Prize: X=([0-9]+), Y=([0-9]+)", input)

for match in matches:
    x1, y1, x2, y2, X, Y = tuple(map(int, match))
    X, Y = 10000000000000 + X, 10000000000000 + Y
    b = int((Y * x1 - X * y1) / (y2 * x1 - y1 * x2))
    a = int((X - b * x2) / x1)
    if a * x1 + b * x2 == X and a * y1 + b * y2 == Y:
        result += 3 * a + b

print(result)
print(time.time() - start_time)

'''
x1, y1, x2, y2, X, Y != 0
ax1 + bx2 = X
ay1 + by2 = Y
<=>
a = (X - bx2) / x1
b = (Yx1 - Xy1) / (y2x1 - y1x2)
'''
