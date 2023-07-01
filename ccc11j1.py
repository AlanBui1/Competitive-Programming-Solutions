lis = []
a = int(input())
b = int(input())

if a >= 3 and b <= 4:
    lis.append("TroyMartian")
if a <= 6 and b >= 2:
    lis.append("VladSaturnian")
if a <= 2 and b <= 3:
    lis.append("GraemeMercurian")
    
for i in lis:
    print(i)