y = 0
x = 0
limitx, limity = map(int, input().split())

cx, cy = map(int, input().split())

while cx != 0 or cy != 0:
    x += cx
    y += cy
    
    if x > limitx:
        x = limitx
    elif x < 0:
        x = 0
    
    if y > limity:
        y = limity
    elif y < 0:
        y = 0
        
    print(x, y)
    
    cx, cy = map(int, input().split())