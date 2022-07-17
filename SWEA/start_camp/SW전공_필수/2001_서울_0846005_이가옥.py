# 서울_임베디드_21반_이가옥

# SW전공_필수 문제풀이
# 2001. 파리퇴치

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
                    temp+=n_list[i+k][j+l] # temp에 죽은 파리의 개수를 저장하고,
            if result < temp: # 최댓값 갱신을 통해 죽은 파리 개수의 최댓값을 구한다.
                result=temp
    print('#'+str(testcase), result)
