def dfs(row, col, n, m):
    if row < 0 or row >= n: return 0
    if col < 0 or col >= m: return 0
    if grid[row][col] == 0: return 0
    grid[row][col] = 0
    moves = [(0,1),(0,-1),(1,0),(-1,0),(1,1),(1,-1),(-1,1),(-1,-1)]
    total = 0
    for move in moves:
        total += dfs(row + move[0], col + move[1], n, m)
    return 1 + total
    
n = int(raw_input())
m = int(raw_input())
grid = []
for _ in range(n):
    grid.append(map(int,raw_input().split()))

ans = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 1:
            ans = max(dfs(i, j, n, m), ans)
print ans