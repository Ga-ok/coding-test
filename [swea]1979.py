# 어디에 단어가 들어갈 수 있을까
t=int(input())
for testcase in range(1, t+1):
    n, k = map(int, input().split())

    graph=[]
    for _ in range(n):
        temp=list(map(int,input().split()))
        graph.append(temp)

    result=0
    # 가로 확인
    for i in range(n):
        cnt=0
        for j in range(n):
            if graph[i][j]==1:
                cnt+=1
                if cnt == k:
                    result+=1
                elif cnt > k:
                    result-=1
                    cnt=0
            elif graph[i][j]!=1:
                cnt=0

    # 세로 확인
    for i in range(n):
        cnt=0
        for j in range(n):
            if graph[j][i]==1:
                cnt+=1
                if cnt == k:
                    result+=1
                elif cnt > k:
                    result-=1
                    cnt=0
            elif graph[j][i]!=1:
                cnt=0


    print('#'+str(testcase), result)