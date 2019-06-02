# Written by: wyattwismer

N  = 1000007
M  = 11
p  = [0]*N
ps = [[0]*N for i in xrange(M)] 

for i in xrange(2,N):
    if p[i] == 0:
        for j in xrange(i,N,i):
            p[j] += 1

for i in xrange(M):
    for j in xrange(1,N):
        ps[i][j] = ps[i][j-1] + int(p[j]==i)

T = int(raw_input())
for TT in xrange(T):
    a,b,n = map(int, raw_input().split())
    print ps[n][b] - ps[n][a-1]

