# 최대상금

t=int(input())


def recur(cnt, n):

    global answer
    if cnt==n:
        temp=''.join(number)
        if answer < temp:
            answer = temp
        return
    else:
        for i in range(len(number)):
            for j in range(i+1, len(number)):
                number[i], number[j]=number[j], number[i]
                temp=''.join(number)

                if visited.get((temp, cnt), 1):
                    visited[(temp, cnt)]=0
                    recur(cnt+1, n)
                number[i], number[j] = number[j], number[i]

for testcase in range(1, t+1):
    number, n = input().split()
    n=int(n)
    number=list(number)

    visited={}
    answer = '000000'

    recur(0, n)

    print('#'+str(testcase), answer)