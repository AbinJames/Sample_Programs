def ascending(l):
    for i in range(1,len(l)):
        if (l[i-1]>l[i]):
            return False
    return True



def valley(l):
    if(len(l)<2):
        return False
    else:
        n=1
        k=1
        if (l[0] < l[1]):
            state=1
            n = 2
        elif (l[0] > l[1]):
            state = 0
            k = 2
        else:
            return False


        for i in range(2,len(l)):
            if (l[i - 1] < l[i]):
                if(state == 0):
                    state=1
                    n=2
                else:
                    n=n+1
            elif (l[i - 1] > l[i]):
                if (state == 1):
                    state = 0
                    k = 2
                else:
                    k=k+1
            else:
                return False
    if(k>=2 and n>=2):
        return True
    else:
        return False

def transpose(m):
    n=[]
    for i in range(len(m)):

        for j in range (len(m[i])):
            if(i==0):
                n=n+[[(m[i][j])]]
            else:
                n[j] = n[j] + [(m[i][j])]

    return n
