def frequency(l):
    num = []
    minfreqlist = []
    maxfreqlist = []
    d = {}
    for x in sorted(l):
        if x not in num:
            num = num + [x]
    for x in num:
        n = 0
        for y in sorted(l):
            if x==y:
                n = n + 1
        d[x]=n
    for x in d.keys():
        if d[x]==max(d.values()):
            maxfreqlist = maxfreqlist + [x]
        if d[x]==min(d.values()):
            minfreqlist = minfreqlist + [x]
    return sorted(minfreqlist), sorted(maxfreqlist)

def onehop(l) :
    des = []
    for x in sorted(l):
        for y in sorted(l):
            if x[1] == y[0]:
                if x[0]!= y[1]:
                    if (x[0],y[1]) not in des:
                        des = des + [(x[0],y[1])]
    return sorted(des)