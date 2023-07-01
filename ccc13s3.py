team = int(input())
games = int(input())
left = 6-games

points = [0,0,0,0]
matches = [[1,2,3], [0,2,3], [0,1,3], [0,1,2]]

for i in range(games):
    team1, team2, p1, p2 = map(int, input().split())
    matches[team1-1].remove(team2-1)
    matches[team2-1].remove(team1-1)
    if p1 == p2:
        points[team1-1] += 1
        points[team2-1] += 1
    elif p1 > p2:
        points[team1-1] += 3
    else:
        points[team2-1] += 3

gamesleft = [[] for i in range(left)]
x=0

for j in range(4):
    game = matches[j]
    for i in game:
        gamesleft[x].append((i, 3))
        gamesleft[x].append((j, 3))
        gamesleft[x].append((i, j, 1))
        matches[j].remove(i)
        matches[i].remove(j)
        x+=1
        
for j in range(4):
    game = matches[j]
    for i in game:
        gamesleft[x].append((i, 3))
        gamesleft[x].append((j, 3))
        gamesleft[x].append((i, j, 1))
        matches[j].remove(i)
        matches[i].remove(j)
        x+=1
wins = 0

def solve(allGames, standings):
    global wins
    
    for game in allGames:
        if len(game) == 2:
            standings[game[0]] += 3
        else:
            standings[game[0]] += 1
            standings[game[1]] += 1
    
    if standings[team-1] == max(standings) and standings.count(standings[team-1]) == 1:
        wins += 1

def specsolve(allGames, standings):
    global wins
    gam = allGames   
    if len(gam) == 2:
        standings[gam[0]] += 3
    else:
        standings[gam[0]] += 1
        standings[gam[1]] += 1

    if standings[team-1] == max(standings) and standings.count(standings[team-1]) == 1:
        wins += 1
if left == 1:
    game1 = gamesleft[0]
    for i in game1:
        pts = points.copy()
        specsolve(i, pts)

elif left == 2:
    game1 = gamesleft[0]
    game2 = gamesleft[1]
    for i in game1:
        for k in game2:
            pts = points.copy()
            solve([i, k], pts)

elif left == 3:
    game1 = gamesleft[0]
    game2 = gamesleft[1]
    game3 = gamesleft[2]
    for i in game1:
        for k in game2: 
            for l in game3:
                pts = points.copy()
                solve([i, k, l], pts)

elif left == 4:
    game1 = gamesleft[0]
    game2 = gamesleft[1]
    game3 = gamesleft[2]
    game4 = gamesleft[3]
    for i in game1:
        for k in game2: 
            for l in game3:
                for j in game4: 
                    pts = points.copy()
                    solve([i, k, l, j], pts)

elif left == 5:
    game1 = gamesleft[0]
    game2 = gamesleft[1]
    game3 = gamesleft[2]
    game4 = gamesleft[3]
    game5 = gamesleft[4]
    for i in game1:
        for k in game2: 
            for l in game3:
                for j in game4: 
                    for m in game5:
                        pts = points.copy()
                        solve([i, k, l, j, m], pts)

else:
    game1 = gamesleft[0]
    game2 = gamesleft[1]
    game3 = gamesleft[2]
    game4 = gamesleft[3]
    game5 = gamesleft[4]
    game6 = gamesleft[5]
    for i in game1:
        for k in game2: 
            for l in game3:
                for j in game4: 
                    for m in game5:
                        for h in game6:
                            pts = points.copy()
                            solve([i, k, l, j, m,h], pts)

print(wins)