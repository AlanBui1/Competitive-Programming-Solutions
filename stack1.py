from collections import deque

t, m = map(int, input().split())

dq = deque()

for i in range(t):
    name, op = input().split()

    if op == "in":
        dq.append(name)
    else:
        carLeaving = dq.pop()
        if carLeaving != name:
            dq.append(carLeaving)
        if m == 0:
            continue
        
        carLeaving = dq.popleft()
        # print(carLeaving, name)
        if carLeaving != name:
            dq.appendleft(carLeaving)
        else:
            m -= 1
    # print(dq)

    
for name in dq:
    print(name)