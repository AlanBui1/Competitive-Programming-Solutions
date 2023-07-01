a = input()
s = a.find(' ')
s2 = a.find(' ',s + 1)

num = int(a[0:s])
num2 = int(a[s:s2])
num3 = int(a[s2:])



if num < num2 + num3:
    if num2 < num + num3:
        if num3 < num + num2:
            print("yes")
if num>=num2+num3:
    print("no")
if num2>=num3+num:
    print("no")
if num3>=num+num2:
    print("no")