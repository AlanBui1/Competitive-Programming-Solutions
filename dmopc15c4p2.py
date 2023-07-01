h, m = map(int, input().split())
n = int(input())
hours = n//60
mins = n%60
m += mins
if m >= 60:
    h += m//60
    m %= 60
    
h += hours
h %= 24
print(h, m)