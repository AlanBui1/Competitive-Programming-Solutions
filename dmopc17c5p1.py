line = input()
lis = [["0", "O"], ["1", "l"], ["3", "E"], ["4", "A"], ["5", "S"], ["6", "G"], ["8", "B"], ["9", "g"]]

for x, y in lis:
    line = line.replace(x, y)
    
print(line)