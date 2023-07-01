s = int(input())
w = int(input())

if 20 <= s <= 23 and 6 <= w <= 9 and 8 <= (24 + w - s) <= 10:
    print("Healthy")
else:
    print("Unhealthy")