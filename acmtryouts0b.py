n = int(input())
word = ''
for i in range(n):  
  x = int(input())
  word1 = input()
  word2 = input()
  while x > 0:
    word = word + word2[x-1]
    word = word + word1[x-1]
    x -= 1
  print(word)
  word = ''