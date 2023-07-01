def solve():
    a = input()
    b = input()
    cnt = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            cnt += 1

    if cnt == 1:
        print("LARRY IS SAVED!")
    else:
        print("LARRY IS DEAD!")
  
solve()