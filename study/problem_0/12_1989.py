# 문제명: 초심자의 회문 검사 / for문 돌리기 응용

t=int(input())
for testcase in range(1, t+1):
    word=input()
    word_pal=''
    for i in range(len(word)-1, -1, -1):
        word_pal+=word[i]

    if word==word_pal:
        print('#'+str(testcase), 1)
    else:
        print('#'+str(testcase), 0)
