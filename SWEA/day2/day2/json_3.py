f1=open('test.json', 'r')
f2=open('output.txt', 'w')

txt = f1.read()
f2.write(txt)
print(txt)

f2.close()
f1.close()