name = input().lower()

if "_" not in name:
    print("other user")
else:
    if name.count("_") == 1:
        if name[:5] == "darcy" and name[6:] == "liu":
            print("real")
        else:
            print("other user")
            
    elif name[:5] == "darcy" and name[len(name)-3:] == "liu" and name.count("_")+8 == len(name):
        print("fake")
    else:
        print("other user")