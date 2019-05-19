# Written by: le-michael

t = int(raw_input())
for a0 in range(t):
    n,m = map(int,raw_input().split())
    graph = {}
    for a1 in range(m):
        getIn = lambda x : int(x) - 1
        x,y = map(getIn,raw_input().split())
        if x not in graph:
            graph[x] = set()
        if y not in graph:
            graph[y] = set()
        graph[x].add(y)
        graph[y].add(x)
        
    start = int(raw_input()) - 1
    distances = [-1 for x in range(n)]
    distances[start] = 0
    q = [start]
    unvisited = set(range(n))
    unvisited.remove(start)
    while unvisited:
        vertex = q.pop(0)
        t_un = set(unvisited)
        if vertex in graph:
            for node in unvisited:
                if node not in graph[vertex]:
                    if distances[node] == -1:
                        q.append(node)
                        t_un.remove(node)
                        distances[node] = distances[vertex] + 1
        else:
            for node in unvisited:
                if distances[node] == -1:
                    q.append(node)
                    t_un.remove(node)
                    distances[node] = distances[vertex] + 1
        unvisited = set(t_un)
            
    del distances[start]
    print ' '.join(map(str,distances))
