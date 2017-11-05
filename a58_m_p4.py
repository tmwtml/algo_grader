n,m,k = [int(x) for x in input().split()]
v0 = []
v1 = []
for i in range(k):
    d,e,l = [int(x) for x in input().split()]
    if e == 0:
        v0[2] = l
    else:
        v1[3] = l

#for i in range(k):
print(v0)
print(v1)
