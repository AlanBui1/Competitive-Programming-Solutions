w = float(input())
h = float(input())

h = h*h
bmi = w/h

if bmi < 18.5:
    print("Underweight")
if bmi > 25: 
    print("Overweight")
if bmi <= 25:
    if bmi >= 18.5:
        print("Normal weight")