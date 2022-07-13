# 괄호 짝짓기

from collections import deque

for testcase in range(1, 11):
    str_len = int(input())
    sentence = list(input())

    dq = deque()
    sentence_dict = {
        '{': 1,
        '}': -1,
        '[': 2,
        ']': -2,
        '(': 3,
        ')': -3,
        '<': 4,
        '>': -4
    }

    result = 0
    for s in sentence:
        if sentence_dict[s] > 0:
            dq.append(sentence_dict[s])
        else:
            temp = dq.pop()

            if sentence_dict[s] == -temp:
                result = 1
            else:
                result = 0
                break

    if len(dq) == 0:
        result = 1

    print('#' + str(testcase), result)

