# 문제명: 1대1 가위바위보 / if문

n1, n2 = map(int, input().split())

if n1 == 1 and n2 == 3:
    print('A')
elif n1 == 3 and n2 == 1:
    print('B')
else:
    if n1 > n2:
        print('A')
    else:
        print('B')