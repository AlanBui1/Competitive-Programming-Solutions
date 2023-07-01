import sys
n = int(input())

arr= []

p1 = 1; p2 = 2

print("?", p1, p2)
response = int(input())
print("?", p2, p1)
response2 = int(input())

arr.append(response2//(-2))
arr = [response+arr[0]] + arr
curArr = [arr[1]*(-2), arr[0]*2]

p1=2
p2=3
if n == 2:
    print("!", *arr)

elif n == 3:
  
    print("?", p2, p1)
  
    R = int(input())

    arr.append(R+curArr[1])

    print("!", *arr)

else:
    while len(arr) < n:
      
        print("?", p2, p1)

        response = int(input())

        arr.append(response+curArr[-1])

        curArr.append(arr[-1] + curArr[-1])

        p2+=1
        p1+=1

    print("!", *arr)