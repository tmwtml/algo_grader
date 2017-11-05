n = int(input())
f = [0,1]
i = 2
while len(f) < n+1 :
    f.append(f[i-1] + f[i-2])
    i += 1
    
print(f[n])
