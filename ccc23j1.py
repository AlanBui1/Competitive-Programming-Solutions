pdelivered = int(input())
obstacles = int(input())

points = 50*pdelivered - 10*obstacles

if pdelivered > obstacles:
    points += 500

print(points)