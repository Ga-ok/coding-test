# 문제명: 리스트값 바꾸기 / list 기본

n=int(input())
n_list=list(map(int, input().split()))

n_list[n]='change'

for i in range(len(n_list)):
    print(n_list[i], end=' ')
