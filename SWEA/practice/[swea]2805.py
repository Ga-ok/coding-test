# 농작물 수확하기

t=int(input())
for testcase in range(1, t+1):
    n=int(input())

    graph=[]
    for i in range(n):
        temp=list(input())
        for j in range(len(temp)):
            temp[j]=int(temp[j])
        graph.append(temp)

    start=n//2
    end=n//2

    result=0
    for i in range(n):
        for j in range(start, end+1):
            result+=graph[i][j]
            print(i, j)

        if i <= n//2:
            start-=1
            end+=1
        else:
            start+=1
            end-=1


    print('#'+str(testcase),result)