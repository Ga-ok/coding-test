# 문제명: 리스트 내 원소값 바꾸고 합 구하기 / list 기본

n_list=list(map(int, input().split()))
result=0
for i in range(len(n_list)):
    if n_list[i]==7:
        print('lucky')
    else:
        result+=n_list[i]
print(result)
