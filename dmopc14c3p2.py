n = int(input())
conv = {"AC":0, "WA":1, "TLE":2, "IR":3}
cnt = [0,0,0,0]
lis = [input() for i in range(n)]
for i in lis:
    cnt[conv[i]]+=1

WaToAc = cnt[1]*3//10
IR = 0

for i in range(n):
    if lis[i] == "AC":
        print("AC")
    elif lis[i] == "WA":
        if WaToAc > 0:
            print("AC")
            WaToAc -= 1
        else:
            print("WA")
    elif lis[i] == "TLE":
        print("WA")
    else:
        if IR < 10:
            print("AC")
        elif IR < 20:
            print("WA")
        else:
            print("IR")
        IR+=1