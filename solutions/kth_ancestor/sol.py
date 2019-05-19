# Written by: le-michael
WIDTH = 20
HEIGHT = 100001
lookup = {}
for i in range(WIDTH): lookup[1 << i] = i

def search(curr, kth):
    if curr == 0 or kth == 0: return curr
    if tree[curr][0] == 0: return 0
    lsb = kth & -kth
    ind = lookup[lsb]
    return search(tree[curr][ind], kth^lsb)

def insert(x, y, ind):
    if ind == WIDTH: return
    tree[x][ind] = y
    insert(x, tree[y][ind], ind+1)

T = int(raw_input())
tree = [[0 for i in range(WIDTH)] for j in range(HEIGHT)]
for _ in range(T):
    P = int(raw_input())
    for i in range(HEIGHT):
        tree[i][0] = 0
    for p in range(P):
        x, y = map(int, raw_input().split())
        insert(x, y, 0)
    Q = int(raw_input())
    for q in range(Q):
        task = map(int, raw_input().split())
        if task[0] == 0:
            insert(task[2], task[1], 0)
        elif task[0] == 1:
            tree[task[1]][0] = 0
        else:
            print search(task[1], task[2])
