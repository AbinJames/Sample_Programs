'''
def thirdmin(l):
  (mymin,mysecondmin,mythirdmin) = (1000000,1000000,1000000)
  for i in range(len(l)):
      for j in range(len(l)):
          if l[i]<l[j]:
              temp = l[i]
              l[i]= l[j]
              l[j]=temp
  (mymin, mysecondmin, mythirdmin) = (l[0],l[1],l[2])
  return(mythirdmin)
print(thirdmin([4,1,3,2]))
print(thirdmin([13,12,2,17,3,6,8,5]))
'''

#this is a large test case file

l = [(4,4),(4,1),(4,3)]
def stablesortbad(l):
  for j in range(len(l)-1):
    for i in range(len(l)-1):
      if l[i][0] >= l[i+1][0]:
        (l[i],l[i+1]) = (l[i+1],l[i])
  return(l)
print(stablesortbad(l))


def sumof3squares(n):
    for i in range(1,n):
        for j in range(1,n):
            for k in range(1,n):
                if n == (i*i+ j*j + k*k):
                    return True
    return False
print(sumof3squares(29))
print(sumof3squares(16))

def uncommon(l1,l2):
    l = []
    for i in l1:
        if i not in l2 and i not in l:
            l.append(i)
    for i in l2:
        if i not in l1 and i not in l:
            l.append(i)
    for i in range(len(l)):
        for j in range(len(l)):
            if l[i]<l[j]:
                temp = l[i]
                l[i] = l[j]
                l[j] = temp
    return(l)
print(uncommon([2,2,4],[1,3,3,4,5]))
print(uncommon([1,2,3],[1,1,2,3,3]))

def maxaverage(l):
    newl = []
    playersum = {}
    playercount = {}
    playeraverage = {}
    for i in range(len(l)):
        if l[i][0] not in playersum:
            playersum[l[i][0]] = l[i][1]
            playercount[l[i][0]] = 1
        else:
            playersum[l[i][0]] = playersum[l[i][0]] + l[i][1]
            playercount[l[i][0]] = playercount[l[i][0]] + 1
    maxscore = 0
    for i in playersum:
        playeraverage[i] = playersum[i]/ playercount[i]
        if playeraverage[i] > maxscore:
            maxscore = playeraverage[i]
    for i in playeraverage:
        if playeraverage[i] == maxscore:
            newl.append(i)
    for i in range(len(newl)):
        for j in range(len(newl)):
            if newl[i] < newl[j]:
                temp = newl[i]
                newl[i] = newl[j]
                newl[j] = temp
    return (newl)
print(maxaverage([('Kohli',73),('Ashwin',33),('Kohli',7),('Pujara',122),('Ashwin',90)]))
print(maxaverage([('Kohli',73),('Ashwin',33),('Kohli',7),('Pujara',22),('Ashwin',47)]))


pattern = input()
text =""
out = []
c = "text"
while( c != ""):
    c = input()
    text = text + c + "\n"
text = text.split("\n")
out = ""
for i in range(1,len(text)):
    if(text[i].find(pattern)!=-1):
        out = text[i]
print (out)


def evenpositions(l):
  if (len(l) < 1):
    return([])
  else:
    return([l[0]]+evenpositions(l[2:len(l)]))
print(evenpositions([8, 11, 8]))
print(evenpositions([19, 3, 44, 44, 3, 19]))