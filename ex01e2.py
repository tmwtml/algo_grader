def mcs(a, i, j):
    if i >= j:
        return a[i]
    mid = (i+j)//2
    x = mcs(a, i, mid)
    y = mcs(a, mid+1, j)
    z1 = a[mid]
    z2 = a[mid]
    s = 0
    for k in range(mid, j+1):
        s += a[k]
        if s > z2:
            z2 = s
    s = 0
    for k in range(mid, i-1, -1):
        s += a[k]
        if s > z1:
            z1 = s
    z = z1 + z2 - a[mid]
    return max(z,max(x,y))

n = int(input())
a = [int(x) for x in input().split()]
print(mcs(a, 0, n-1))
