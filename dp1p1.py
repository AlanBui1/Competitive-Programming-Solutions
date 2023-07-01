n = int(input())
arr = [int(input()) for i in range(n)]

if n == 2:
    print(max(arr[0], arr[1]))
elif n == 3:
    print(max(arr[0]+arr[2], arr[1]))

else:
    arr[-3] = arr[-3]+arr[-1]
    for i in range(n-4, -1, -1):
        arr[i] += max(arr[i+2], arr[i+3])

    print(max(arr[0], arr[1]))