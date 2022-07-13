# 최빈수

t = int(input())

for testcase in range(1, t + 1):
    tn = int(input())

    num_dict = dict()

    num_list = []
    num_list = list(map(int, input().split()))

    for i in range(1000):
        num_dict[num_list[i]] = 0
    for i in range(1000):
        num_dict[num_list[i]] += 1

    num_dict = sorted(num_dict.items(), key=lambda x: (-x[1], -x[0]))

    print('#' + str(testcase), num_dict[0][0])