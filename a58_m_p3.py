def hv(n, v):
    if n == 1:
        return v
    elif n == 2:
        return [v[0]+v[1], v[0]-v[1]]
    else:
        m = n//2
        a = hv(m, v[0:m])
        b = hv(m, v[m:n])
        p = [sum(x) for x in zip(a, b)]
        q = [x-y for x, y in zip(a, b)]
        return p+q

n = int(input())
v = [int(x) for x in input().split()]
ans = hv(n, v)
print(" ".join(str(x) for x in ans))
