n,m = [int(x) for x in input().split()]
nn = set([int(x) for x in input().split()])
mm = [int(x) for x in input().split()]

for i in mm:
    ans = "NO"
    for j in nn:
        if i-j in nn:
            ans = "YES"
            break
    print(ans)
