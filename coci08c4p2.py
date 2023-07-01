days = ["Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday", "Wednesday"]

months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
d, m = map(int, input().split())
m -=1
d -= 1
curDay = sum(months[: m]) + d
curDay %= 7

print(days[curDay])