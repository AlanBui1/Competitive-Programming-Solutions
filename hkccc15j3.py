board = []
x = 0
pos1 = 0
pos2 = 0

ans = 0
n = [int(k) for k in input().split()]
for i in range(n[0]): 
  board.append (['0' for i in range(n[0])])
for i in range(0,n[1],1):
  queen = [int(l) for l in input().split()]
  board[queen[0]-1][queen[1]-1] = 'q'
  while x < n[0]:
    board[queen[0]-1][x] = 'q'
    board[x][queen[1]-1] = 'q'
    x+=1
  x = 0
  pos = [queen[0]-1,queen[1]-1]
  while pos[0] >= 0:
    if pos[1]+pos2 >= n[0]:
      break
    if pos[0]+pos1 < 0:
      break
    board[pos[0]+pos1][pos[1]+pos2] = 'q'
    pos1 -= 1
    pos2 += 1
  pos1 = 0
  pos2 = 0
  while pos[0] >= 0:
    if pos[1]+pos2 <0:
      break
    if pos[0]+pos1 >= n[0]:
      break
    board[pos[0]+pos1][pos[1]+pos2] = 'q'
    pos1 +=1
    pos2 -= 1
  pos1 = 0
  pos2 = 0
  while True:
    if pos[1]+pos1 < 0:
      break
    if pos[0] + pos1 <0:
      break
    board[pos[0]+pos1][pos[1]+pos1] = 'q'
    pos1 -= 1
  pos1 = 0
  pos2 = 0
  while True:
    if pos[0]+pos1 > n[0]-1:
      break
    if pos[1] + pos1 > n[0]-1:
      break
    board[pos[0]+pos1][pos[1]+pos2] = 'q'
    pos1 +=1
    pos2 +=1
  pos1 = 0
  pos2 = 0
for i in range(n[0]):
  ans += board[i].count('0')

print(ans)