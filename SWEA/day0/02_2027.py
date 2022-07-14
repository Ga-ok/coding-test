# 문제명: 대각선 출력하기 / print문

# print문을 이용한 풀이
#print('#++++')
#print('+#+++')
#print('++#++')
#print('+++#+')
#print('++++#')

# 반복문을 이용한 풀이
for i in range(5):
    for j in range(5):
        if i==j:
            print('#', end='')
        else:
            print('+', end='')
    print()
