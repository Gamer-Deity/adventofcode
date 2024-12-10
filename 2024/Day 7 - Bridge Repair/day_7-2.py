with open("input.txt", "r") as file:
    input = [(line.strip()) for line in file.readlines()]

ops = [lambda a,b: a+b, lambda a,b: a*b, lambda a,b: int(str(a)+str(b))]

def test_ops(res, nums, op_num):
    ops_res = nums[0]
    for i in range(1, len(nums)):
        # print(ops[op_num % len(ops)], end='')
        ops_res = ops[op_num % len(ops)](ops_res, nums[i])
        op_num //= len(ops)
    # print("", ops_res)
    if ops_res == res:
        return ops_res
    return 0

def test_line(line):
    line = line.split(': ')
    res = int(line[0])
    nums = list(map(int, line[1].split(' ')))

    size = len(nums) - 1
    for op_num in range(len(ops) ** size):
        test_res = test_ops(res, nums, op_num)
        if test_res > 0:
            return test_res
    return 0

result = 0
for line in input:
    result += test_line(line)

print(result)
