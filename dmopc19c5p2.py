def solve():
    n, h = map(int, input().split())

    C = [input().split() for i in range(n)]
    E = [input().split() for i in range(n)]
    health = [h, h]

    lis =[]
    for i in range(n):
        lis.append(C[i])
        lis.append(E[i])
  
        
    for i in range(2*n):
        if i %2 == 0:
            player = 0
            opp = 1
        else:
            player = 1
            opp = 0

        action = lis[i][0]
        dmg = int(lis[i][1])

        if action == "A":
            if i == 0:
                health[opp] -= dmg

            elif lis[i-1][0] == "D":
                continue

            else:
                health[opp] -= dmg

        elif action == "D":
            if i == (2*n)-1:
                health[player] -= dmg
                
            elif lis[i+1][0] != "A":
                health[player] -= dmg

      

        if health[opp] <= 0:
            if player == 0:
                print("VICTORY")
            else:
                print("DEFEAT")
            return

        if health[player] <= 0:
            if player == 0:
                print("DEFEAT")
            else:
                print("VICTORY")
            return

      


    print("TIE")

solve()