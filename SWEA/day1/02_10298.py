# 문제명: 세 개의 입력 값, 같은지 출력하기 / if elif

n1, n2, n3 = map(int, input().split())
if n1==n2==n3:
    print('모두 같다')
elif n1!=n2 and n1!=n3 and n2!=n3:
    print('모두 다르다')
else:
    print('일부 같다')
