n = int(input())
for i in range(n):
    s = input()
    if 'M' in s and 'C' in s:
        print('NEGATIVE MARKS')
    elif 'M' in s and 'C' not in s:
        print('FAIL')
    elif 'C' in s and 'M' not in s:
        print('FAIL')
    else:
        print('PASS')