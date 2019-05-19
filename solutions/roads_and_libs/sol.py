def find(x):
    if x!= parent[x]:
        parent[x] = find(parent[x])
    return parent[x]

def union(x,y):
    global groups
    x_root = find(x)
    y_root = find(y)
    
    if x_root != y_root:
        groups -= 1
        parent[x_root] = y_root
    
q = int(raw_input())
for a0 in range(q):
    cities,roads,clibs,croads = map(int,raw_input().split())
    groups = cities
    parent = [i for i in range(cities)]
    for a1 in range(roads):
        inp = lambda x : int(x) - 1
        x,y =  map(inp,raw_input().split())
        union(x,y)
    if clibs <= croads:
        print clibs * cities
    else:
        print groups*clibs + (cities - groups)* croads
