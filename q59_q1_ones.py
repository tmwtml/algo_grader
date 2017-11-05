q = [0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111]

def ones(n):
    if n in range(1,7):
        #print("1 "*n)
        return n
    elif n in range(7,12):
        #print("11 " + "1 "*(11-n))
        return 13 - n
    else:
        k = 0
        for i in range(len(q)):
            if q[i] == n:
                #print(n)
                return i
            elif q[i] < n:
                k = i
        nk = n/q[k]
        if nk <= 5.55:      #5i+6
            #print("1"*k)
            return ones(n - q[k]) + k
        else:
            #print("1"*(k+1))
            return ones(q[k+1] - n) + k+1
        
n = int(input())
if(n == -1):
    for i in range(111):
        print(str(i) + " " + str(ones(i)))
else:
    print(ones(n))
