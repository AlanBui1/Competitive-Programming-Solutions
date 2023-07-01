line1 = input()
line2 = input()
line3 = input()
line4 = input()
x = 0
s1 = int(line1.find(' '))
s2 = int(line1.find(' ',s1 + 1))
s3 = int(line1.find(' ',s2 + 1))

ss1 = int(line2.find(' '))
ss2 = line2.find(' ',ss1 + 1)
ss3 = line2.find(' ',ss2 + 1)

sss1 = line3.find(' ')
sss2 = line3.find(' ',sss1 + 1)
sss3 = line3.find(' ',sss2 + 1)

ssss1 = line4.find(' ')
ssss2 = line4.find(' ',ssss1 + 1)
ssss3 = line4.find(' ',ssss2 + 1)

num1 = int(line1[0:s1]) + int(line1[s1:s2]) + int(line1[s2:s3]) + int(line1[s3:])


num2 = int(line2[0:ss1]) + int(line2[ss1:ss2]) + int(line2[ss2:ss3]) + int(line2[ss3:])


num3 = int(line3[0:sss1]) + int(line3[sss1:sss2]) + int(line3[sss2:sss3]) + int(line3[sss3:])


num4 = int(line4[0:ssss1]) + int(line4[ssss1:ssss2]) + int(line4[ssss2:ssss3]) + int(line4[ssss3:])


v1 = int(line1[0:s1]) + int(line2[0:ss1]) + int(line3[0:sss1]) + int(line4[0:ssss1]) 
v2 = int(line1[s1:s2]) + int(line2[ss1:ss2]) + int(line3[sss1:sss2]) + int(line4[ssss1:ssss2]) 
v3 = int(line1[s2:s3]) + int(line2[ss2:ss3]) + int(line3[sss2:sss3]) + int(line4[ssss2:ssss3]) 
v4 = int(line1[s3:]) + int(line2[ss3:]) + int(line3[sss3:]) + int(line4[ssss3:])



if num1 == num2:
  if num1 == num3:
    if num1 == num4:
      if num1 == v1:
        if num1 ==v2:
          if num1 ==v3:
            if num1 ==v4: 
              x = 1

if x == 1:
  print("magic")
if x!= 1:
  print("not magic")