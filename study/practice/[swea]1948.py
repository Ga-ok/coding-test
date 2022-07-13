# 날짜 계산기

t=int(input())
for testcase in range(1, t+1):
    date={1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}

    x1, y1, x2, y2 = map(int, input().split())

    result=0
    result+= (date[x1]-y1)

    if x1!=x2:
        for i in range(x1+1, x2):
            result+=date[i]

    result+= y2

    print('#'+str(testcase), result)
