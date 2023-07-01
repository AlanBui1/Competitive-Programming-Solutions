word = input()
s = 0
x = 0
for i in word:
  s = s + 1
for i in range(0,s,1):
  if word [i] != "I":
    if word [i] != "O":
      if word[i] != "S":
        if word[i] != "H":
          if word [i] != 'Z':
            if word [i] != "X":
              if word[i] != "N":
                x = 1
  else: x = 0
if x == 1:
  print("NO")
if x == 0:
  print("YES")