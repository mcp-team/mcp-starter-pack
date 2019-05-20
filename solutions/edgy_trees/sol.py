# Written by: le-michael

MOD = 1000000007

def find(x):
  if parent[x] != x:
    parent[x] = find(parent[x])
  return parent[x]

def union(x, y):
  x_par = find(x)
  y_par = find(y)
  if x_par != y_par:
    parent[x_par] = y_par
    size[y_par] += size[x_par]
    size[x_par] = 0

n, k = map(int, raw_input().split())
parent = [i for i in range(n)]
size = [1 for i in range(n)]
sol = n**k
for _ in range(n-1):
    x, y, c = map(int, raw_input().split())
    if c == 0:
        union(x-1, y-1)

for elm in size:
  sol -= elm**k

print sol%MOD
