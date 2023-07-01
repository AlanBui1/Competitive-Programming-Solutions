s = 0
for i in range(0,10,1):
  word = input() 
  if word == "quit!":
    break
  for i in word:
    s = s + 1
  if s <= 4:
    print(word)
    s = 0
    continue
  if s > 4:
    if word[s-2] == 'o':
      if word[s-1] == 'r':
        if word[s-3] == 'a':
          print(word)
          s = 0
          continue
        if word[s-3] == "e":
          print(word)
          s = 0
          continue
        if word[s-3] == "i":
          print(word)
          s = 0
          continue
        if word[s-3] == "o":
          print(word)
          s = 0
          continue
        if word[s-3] == "u":
          print(word)
          s = 0
          continue
        if word[s-3] == "y":
          print(word)
          s = 0
          continue
        if word[s-3] != "a":
          print(word[0:s-1]+'u'+word[s-1])
          s = 0
          continue
    else:
      print(word)
      s = 0