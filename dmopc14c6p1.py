n = int(input())
lis = [input() for i in range(n)]
flag = False
for i in range(1, n-1):
    if lis[i] == "Bessarion":
        if lis[i-1] == "Bayview" and lis[i+1] == "Leslie":
            flag = 1
        if lis[i-1] == "Leslie" and lis[i+1] == "Bayview":
            flag = 1

if not flag:
    print("N")
else:
    print("Y")