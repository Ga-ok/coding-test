# 계산기 2

from collections import deque

for testcase in range(1, 11):
    sentence_len=int(input())
    sentence=list(input())

    pre = {
        '+' : 1,
        '*' : 2
    }

    result=[]
    stack=deque()

    # 중위표기식을 후위표기식으로 변환
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
                    else:
                        item = stack.pop()
                        result.append(item)


    while len(stack)>0:
        item = stack.pop()
        result.append(item)


    # 후위표기식을 계산
    for s in result:
        if s not in pre.keys():
            stack.append(s)
        else:
            item1 = int(stack.pop())
            item2 = int(stack.pop())

            if s=='*':
                stack.append(item1*item2)
            elif s=='+':
                stack.append(item1+item2)

    print("#"+str(testcase), stack.pop())