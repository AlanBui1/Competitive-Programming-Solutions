r, x, y = map(int, input().split())

smallest = int(1e9)
win = 0
for i in range(3):
    a, b, c = map(int, input().split())
    
    if c < smallest:
        smallest = c
        win = 0
        if r*r > ((a-x)*(a-x)) + ((b-y)*(b-y)):
            win = 1
        
if win:
    print("What a beauty!")
        
else:
    print("Time to move my telescope!")