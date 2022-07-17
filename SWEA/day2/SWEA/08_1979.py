# 어디에 단어가 들어갈 수 있을까

def check(lst, k):
    cnt=[]
    temp=0
    for i in range(len(lst)):
        if lst[i]==1:
            temp+=1
        elif lst[i]==0:
            if temp!=0:
                cnt.append(temp)
            temp=0
        if i==len(lst)-1:
            if temp!=0:
                cnt.append(temp)
    return cnt

t=int(input())

for testcase in range(1, t+1):
    n, k = map(int, input().split())

    graph=[]
    for _ in range(n):
        temp=list(map(int, input().split()))
        graph.append(temp)

    result=0

    # 가로 찾기
    cnt=[]
    for i in range(n):
        cnt = check(graph[i], k)
        for i in range(len(cnt)):
            if cnt[i] == k:
                result += 1

    # 세로 찾기
    cnt=[]
    for i in range(n):
        temp = []
        for j in range(n):
            temp.append(graph[j][i])
        cnt = check(temp, k)
        for i in range(len(cnt)):
            if cnt[i] == k:
                result += 1

    print('#'+str(testcase), result)