def modexpo(x, n, k):
    if n == 0:
        return 1
    if n == 1:
        return x
    return (modexpo(x, n//2, k)**2 * modexpo(x, n%2, k))%k 

x,n,k = [int(x) for x in input().split(" ")]
print(modexpo(x%k,n,k))
