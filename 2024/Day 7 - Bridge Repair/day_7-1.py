with open("input.txt", "r") as file:
    input = [(line.strip()) for line in file.readlines()]

def test_ops(res, nums, ops):
    i = 0
    ops_res = nums[0]
    while i < len(ops):
        if ops[i] == '+':
            ops_res += nums[i + 1]
        else:
            ops_res *= nums[i + 1]
        i += 1
    # print(ops_res, res)
    if ops_res == res:
        return ops_res
    return 0

def test_line(line):
    line = line.split(': ')
    res = int(line[0])
    nums = list(map(int, line[1].split(' ')))

    size = len(nums) - 1
    ops = list((size) * "+")
    while True:
        # print(ops)
        test_res = test_ops(res, nums, ops)
        if test_res > 0:
            return test_res
        
        if ops == list(size * "*"): break

        i = 0
        while(ops[i] == '*'):
            ops[i] = '+'
            i += 1
        ops[i] = '*'
    return 0

result = 0
for line in input:
    result += test_line(line)

print(result)
