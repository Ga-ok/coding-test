# 문제명: 스파이 색출2

n_list = list(map(int, input().split()))

result=0
for i in range(len(n_list)-2):
    if n_list[i] == n_list[i+1] == n_list[i+2]:
        continue
    elif n_list[i] != n_list[i+1]:
        if n_list[i] == n_list[i+2]:
            result=n_list[i+1]
        else:
            result=n_list[i]
    elif n_list[i] == n_list[i+1]:
        result=n_list[i+2]

print(result)

