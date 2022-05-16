# view

for testcase in range(1, 11):
    n = int(input())

    # 빌딩 리스트 생성
    buildings = list(map(int, input().split()))
    # print(buildings)

    result = 0
    for i in range(n):
        b = buildings[i]
        if buildings[i] == 0:
            continue

        temp = 0
        while True:
            if b > buildings[i - 1] and b > buildings[i + 1] and b > buildings[i - 2] and b > buildings[i + 2]:
                temp += 1
                b = b - 1

            else:
                b = buildings[i]
                result += temp
                break

    print('#' + str(testcase), result)