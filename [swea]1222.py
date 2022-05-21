# 계산기 1

from collections import deque

for testcase in range(1, 11):
    sentence_len = int(input())
    sentence = list(input())

    pre = {
        '+' : 1
    }

    # 중위표기식을 후위표기식으로 변환
    result=[]
    stack=deque()
    for s in sentence:
        if s not in pre.keys():
            result.append(s)
        else:
            if len(stack)==0 or pre[stack[-1]] < pre[s]:
                stack.append(s)
            else:
                while True:
                    if len(stack)==0 or pre[stack[-1]] < pre[s]:
                        stack.append(s)
                        break
                    item = stack.pop()
                    result.append(item)

    while len(stack)>0:
        item = stack.pop()
        result.append(item)

    # 후기표기식 계산
    for s in result:
        if s not in pre.keys():
            stack.append(s)
        else:
            item2=int(stack.pop())
            item1=int(stack.pop())

            if s == '+':
                result2=(item1+item2)
                stack.append(result2)

    print('#'+str(testcase), stack.pop())


