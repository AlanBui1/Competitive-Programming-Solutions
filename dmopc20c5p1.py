def solve():
    s = str(input())
    t = str(input())
    moves = len(s)+len(t)

    for i in range(min(len(s), len(t))):
        if s[i] == t[i]:
            moves -= 2
        else:
            break

    print(moves)
  
solve()