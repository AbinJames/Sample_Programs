def palindrome(X, Y, N):
    L = [[0 for x in range(N + 1)] for x in range(N + 1)]
    maxL = 0
    c = 0,0
    for i in range(N + 1):
        for j in range(N + 1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif X[i - 1] == Y[j - 1]:
                L[i][j] = L[i - 1][j - 1] + 1
                if L[i][j] > maxL:
                    maxL = L[i][j]
                    c = i,j
    i = c[1]-1
    word = ""
    while maxL != 0:
        word = Y[i]+word
        i = i-1
        maxL = maxL-1
    return(word)


N = int(input())
word = input()
palin = palindrome(word, word[::-1], N)
print(len(palin))
print(palin)