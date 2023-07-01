L = int(input())
lis = []
final = 0
for i in range(0,L,1):
  word = input()
  final = word.split()
  print(final[1]*int(final[0]))