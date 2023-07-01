def solve():
    line = input()
    
    cnt = sum([line.count(x) for x in "aeiouy"])
    
    if cnt >= 2:
        print("good")
    else:
        print("bad")
    
solve()