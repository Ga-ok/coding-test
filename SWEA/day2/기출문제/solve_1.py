data=input()
key=input()

ori=""
i=0
for chr in data:
    if i != len(key):
        if key[i]==chr:
            i+=1
            continue
    print(chr, end=' ')