x = input()
y = input()

if x != 'red':
    if x != 'green':
        if x != 'white':
            print("Boring...")

if x == 'red':
    if y == 'red':
        print("Jingle Bells")
    elif y == 'green':
        print("Jingle Bells")
    elif y == 'white':
        print("Jingle Bells")
    elif y != 'red':
        print("Boring...")

if x == 'green':
    if y == 'red':
        print("Jingle Bells")
    elif y == 'green':
        print("Jingle Bells")
    elif y == 'white':
        print("Jingle Bells")
    elif y != 'red':
        print("Boring...")
        
if x == 'white':
    if y == 'red':
        print("Jingle Bells")
    elif y == 'green':
        print("Jingle Bells")
    elif y == 'white':
        print("Jingle Bells")
    elif y != 'red':
        print("Boring...")