from datetime import datetime, timedelta
new = []
x = [int(k) for k in (input().split())]
y = [int(k) for k in (input().split())]
time = [int(k) for k in (input().split(':'))]
dist = abs(y[0]-x[0]) + abs((y[1])-x[1])

original = datetime(year=time[0], month=time[1], day=time[2], hour=time[3], minute=time[4], second=time[5])
newtime = original + timedelta(seconds = dist)
newtime = str(newtime)
print(newtime[0:4]+':'+newtime[5:7]+':'+newtime[8:10]+':'+newtime[11:13]+':'+newtime[14:16]+':'+newtime[17:])