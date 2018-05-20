# Dynamic programming implementation of LCS problem

# Returns length of LCS for X[0..m-1], Y[0..n-1]
def lcs(X, Y, m, n):
    L = [[0 for x in range(n + 1)] for x in range(m + 1)]
    maxL = 0
    c = 0,0
    # Following steps build L[m+1][n+1] in bottom up fashion. Note
    # that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for i in range(m + 1):
        for j in range(n + 1):
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
    print("Longest common substring is",word)




# Driver program
X = "secretary"
Y = "secret"
m = len(X)
n = len(Y)
lcs(X, Y, m, n)