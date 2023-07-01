verb = input()
obj = input()
subject = ""

if obj[-1] == "e":
    subject = "la"
elif obj[-1] == "s":
    subject = "les"
else:
    subject = "le"
print(verb+"-tu "+subject+" "+obj+" ?")