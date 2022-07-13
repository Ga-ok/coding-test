# 암호생성기

from collections import deque
for testcase in range(1, 11):
    tn=int(input())
    temp=list(map(int, input().split()))

    pwd=deque()
    pwd.extend(temp)
    while True:

        flag=0
        for i in range(1, 6):
            item = pwd.popleft()
            item -= i
            if item <= 0:
                item = 0
                pwd.append(item)
                flag=1
                print('for문 stop!')
                break
            pwd.append(item)

        print(pwd)
        if flag==1:
            break

    result=''
    for p in pwd:
        result+=str(p)+' '

    print('#'+str(testcase), result)
