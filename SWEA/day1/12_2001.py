# 문제명: 파리퇴치

t=int(input())
for testcase in range(1, t+1):
    n, m = map(int, input().split())

    n_list=[]
    for _ in range(n):
        temp=list(map(int, input().split()))
        n_list.append(temp)

    result=0
    for i in range(n-m+1):
        for j in range(n-m+1):
            temp=0
            for k in range(m):
                for l in range(m):
                    temp+=n_list[i+k][j+l]
            if result < temp:
                result=temp
    print('#'+str(testcase), result)
