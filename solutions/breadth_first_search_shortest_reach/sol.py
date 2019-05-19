# Written by: le-michael

q = int(raw_input())
inp = lambda x: int(x)-1
for _ in range(q):
    n, m = map(int,raw_input().split())
    graph = {}
    for _ in range(m):
        x, y = map(inp,raw_input().split())
        if x not in graph:
            graph[x] = set()
        if y not in graph:
            graph[y] = set()
        graph[x].add(y)
        graph[y].add(x)

    ans = [-1 for i in range(n)]
    start = int(raw_input()) - 1
    
    if start in graph:
        q = [start]
        ans[start] = 0
        while q:
            curr = q.pop(0)
            for node in graph[curr]:
                if ans[node] == -1:
                    ans[node] = ans[curr] + 6
                    q.append(node)
    ans.pop(start)
    print ' '.join(map(str,ans))
