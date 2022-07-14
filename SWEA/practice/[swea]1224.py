# 계산기 2

from collections import deque
for testcase in range(1, 11):
    sentence_len=int(input())
    sentence=list(input())

    # 중위표기식을 후위표기식으로 변환
    pre_out = {
        '(':3,
        '+':1,
        '*':2
    }

    pre_in = {
        '(': 0,
        '+': 1,
        '*': 2
    }

    result=[]
    stack=deque()
    for s in sentence:
        if s in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            result.append(s)
        elif s ==')':
            while True:
                item = stack.pop()
                if item=='(':
                    break
                result.append(item)
        elif s in pre_out.keys():
            if len(stack)==0 or pre_in[stack[-1]] < pre_out[s]:
                stack.append(s)
            else:
                while True:
                    if len(stack)==0 or pre_in[stack[-1]] < pre_out[s]:
                        stack.append(s)
                        break
                    result.append(stack.pop())


    while len(stack)>0:
        result.append(stack.pop())

    # 후위표기식 계산
    for s in result:
        if s not in pre_out.keys():
            stack.append(s)
        else:
            item1=int(stack.pop())
            item2=int(stack.pop())

            if s == '+':
                stack.append(item1+item2)
            elif s == '*':
                stack.append(item1*item2)

    print("#"+str(testcase), stack.pop())


