a, b = input().split()

def rev(s):
    ret = ""
    for i in range(len(s)-1, -1, -1):
        ret += s[i]
    return int(ret)

a, b = map(rev, [a, b])
print(max(a, b))