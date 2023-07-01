r, c = map(int, input().split())
art = [input() for k in range(r)]
top = input()
bot = input()
print(art[0])
x1 = (c - len(top))//2
ret = [i for i in art[1][:x1] + top + art[1][x1+len(top):]]
for i in range(x1, x1+len(top)):
    if ret[i] == "_":
        ret[i] = art[1][i]
print(*ret, sep="")

for i in range(2, r-2):
    print(art[i])
x2 = (c-len(bot))//2

ret = [i for i in art[r-2][ :x2] + bot + art[r-2][x2+len(bot):]]
for i in range(x2, x2+len(bot)):
    if ret[i] == "_":
        ret[i] = art[-2][i]
print(*ret, sep="")
print(art[-1])