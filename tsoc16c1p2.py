filename = input()
ind = filename.rfind(".")
if ind == -1:
    extension = input().lower()
    print('"'+filename+'"', "-", extension)
    
else:
    extension = filename[ind+1: ]
    print('"'+filename[0:ind]+'"', "-", extension)