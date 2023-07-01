import math

del_cost, ins_cost, rep_cost = map(int, input().split())
word1, word2 = map(str, input().split())

distance = [[math.inf for i in range(len(word2)+1)] for k in range(len(word1)+1)] 
distance[0][0] = 0

for i in range(len(word1)+1):
  for k in range(len(word2)+1):
    if i == 0 and k == 0:
      continue
    delete = math.inf
    insert = math.inf
    replace = math.inf

    if i > 0:
      delete = distance[i-1][k]+del_cost

    if k > 0:
      insert = distance[i][k-1]+ins_cost

    if i > 0 and k > 0:
      if word1[i-1] == word2[k-1]:
        replace = distance[i-1][k-1]  
      else:
        replace = distance[i-1][k-1]+rep_cost

    distance[i][k] = min(delete, insert, replace)

print(distance[i][k])