from datetime import datetime, timedelta

s = int(input())

line = input().split()
date = [int(i) for i in line[0].split("/")]
tim = [int(i) for i in line[1].split(":")]

original = datetime(year = date[0], month = date[1], day = date[2], hour = tim[0], minute = tim[1], second = tim[2])
newtime = original - timedelta(hours = s)
newtime = str(newtime)
print(newtime[0:4]+'/'+newtime[5:7]+'/'+newtime[8:10]+' '+newtime[11:13]+':'+newtime[14:16]+':'+newtime[17:])