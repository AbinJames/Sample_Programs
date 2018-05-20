def perfect(n):
    num = 0
    for i in range(1, n):
        if n % i == 0:
            num += i
    if n == num:
        return "true"
    else:
        return "false"


def depth(s):
    c = 0
    d = 0
    temp=0
    for i in s:
        if i == '(':
            c = c + 1
            d = d + 1
        elif i == ')':
            c = c - 1
        if c == 0:
            if d>=temp:
                temp=d
            d = 0

    return temp


def sumsquares(l):
    num = 0
    for i in l:
        f = 1
        for j in range(1, i):
            if j*j == i:
                f = 0
        if i == 1:
            f = 0
        if f == 0:
            num += i
    return num