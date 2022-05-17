# flatten
for testcase in range(1, 11):
    dump=int(input())
    box=list(map(int, input().split()))

    result=0
    for i in range(dump):
        box.sort(reverse=True)

        if box[0]-box[-1]<=1:
            result=box[0]-box[-1]
            break

        box[0]-=1
        box[-1]+=1


    # 마지막에 반드시 정렬을 해줘야 한다! (최종적으로는 최고점과 최저점의 차이를 또 구해야 하므로)
    box.sort(reverse=True)
    result=box[0]-box[-1]

    print('#'+str(testcase), result)
