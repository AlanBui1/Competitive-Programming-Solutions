num = 0
m = int(input())
def recur(has, n):
  global num
  if int(has) >= n:
    num+=1
    return
  recur(has+'2',n)
  recur(has+'3',n)

recur('2',m)
recur('3',m)
print(num-2)