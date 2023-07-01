word = [k for k in input()]
word.sort()

def recur(has, left):
  if len(left) == 0:
    print(has)
    return
  for i in range(0,len(left),1):
    recur(has+str(left[i]) ,left[:i]+left[i+1:])
recur('',word)