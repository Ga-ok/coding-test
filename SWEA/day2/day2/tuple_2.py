def run(a):
    for i in a:
        print(i)

def abc():
    return 1, 2, 3, 4

def run2():
    return 1, 2, 3

run((1, 2, 3, 4, 5))

print(abc())

b, c, d = run2()
print(b, c, d)

