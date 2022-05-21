# string

for testcase in range(1, 11):
    tn = int(input())
    search = input()
    sentence = input()

    result=0
    for i in range(sentence):
        if search[0]==sentence[i]:
            if sentence[i:i+len(search)]==search:
                result+=1

    result2=0
    result2=sentence.count(search)

    print('#'+str(testcase), result2)


