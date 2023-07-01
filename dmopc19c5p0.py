def solve():
    n, c=  map(int, input().split())

    for i in range(n):
        name, score = input().split()
        if int(score) > c:
            print(name, "will advance")
        else:
            print(name, "will not advance")
  
solve()