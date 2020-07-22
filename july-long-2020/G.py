def slope(n0,n1):
    return((int(H[n0-1])-int(H[n1-1]))/(n0-n1))

def maxGlide2(start, stop, flag):
    global H2
    global ans
    global maxi
    if(start == stop):
        y = sum(H2)
        if(y > maxi):
            maxi = y
            ans.append(list(H2))
    elif(start < stop):
        maxSlope=-10e10
        if(flag == 1):
            H2 = []
            maxi = 0
            ans = []
            H2.append(int(A[start-1]))
        for i in range(start+1, stop+1):
            s2=slope(start,i)
            if(int(H[start-1]) > int(H[i-1])):
                if(s2 >=maxSlope):
                    maxSlope=s2
                    H2.append(int(A[i-1]))
                    maxGlide2(i, stop, 0)
                    H2.pop()
            else:
                break
        if(flag == 1):
            H2.pop()
    else:
        minSlope=10e10
        if(flag == 1):
            H2 = []
            maxi = 0
            ans = []
            H2.append(int(A[start-1]))
        for i in range(start-1, stop-1, -1):
            s2=slope(start,i)
            if(int(H[start-1]) > int(H[i-1])):
                if(s2<=minSlope):
                    minSlope=s2
                    H2.append(int(A[i-1]))
                    maxGlide2(i, stop, 0)
                    H2.pop()
            else:
                break
        if(flag == 1):
            H2.pop()


def updater(b, c):
    A[b-1] = str(c)


H2 = []
maxi = 0
ans = []
w = input().split(" ")
N = int(w[0])
Q = int(w[1])
H = input().split(" ")
A = input().split(" ")
for i in range(Q):
    X = input().split(" ")
    if(X[0] == "1"):
        updater(int(X[1]), int(X[2]))
    else:
        maxGlide2(int(X[1]), int(X[2]), 1)
        if(maxi != 0):
            print(maxi)
        else:
            print(-1)
