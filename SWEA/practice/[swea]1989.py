# 초심자의 회문검사

t=int(input())
for testcase in range(1, t+1):
    word=list(input())

    result=1
    # if word==word[::-1]:
    #     result=1

    for i in range(len(word)//2):
        if word[i]!=word[(-1*i)+1]:
            result=0
            break

    print('#'+str(testcase), result)