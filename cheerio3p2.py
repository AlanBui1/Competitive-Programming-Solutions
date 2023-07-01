n = int(input())
line = input()
ammo = 0
oppammo = 0
pts =0
moves = []
for i in line:
    if i == "R":
        oppammo += 1
        if ammo > 0:
            pts+= 1
            ammo -= 1
            moves.append("F")
        else:
            ammo += 1
            moves.append("R")
    elif i == 'F':
        if oppammo == 0:
            if ammo > 0:
                pts += 1
                ammo -= 1
                moves.append("F")
            else:
                ammo += 1
                moves.append("R")
        else:
            oppammo -= 1
            moves.append("B")
    else:
        ammo += 1
        moves.append("R")

print(pts)