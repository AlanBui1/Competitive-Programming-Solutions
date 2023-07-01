orig = [int(i) for i in input().split(":")]
want = [int(i) for i in input().split(":")]

tim1 = orig[0] * 3600 + orig[1]*60 + orig[2]
tim2 = want[0] * 3600 + want[1]*60 + want[2]
print(tim2-tim1)