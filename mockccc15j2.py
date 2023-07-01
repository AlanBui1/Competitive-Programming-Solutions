p = int(input())
q = int(input())
w = int(input())
x=0
if p*((100-w)/100) + w <= q-.5:
    print("DROP THE COURSE")
else:
    x=(((q-0.5)-(p*((100-w)/100)))/(w/100))
    if x - int(x) != 0:
      x = int(x) + 1
    if x <= 0:
      x=0
    print(int(x))