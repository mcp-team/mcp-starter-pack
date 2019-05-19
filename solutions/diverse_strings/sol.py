# Written by: le-michael

def solve(w):
    if len(w) == 1: return "Yes"
    if len(set(w)) != len(w): return "No"
    list_w = list(w)
    list_w.sort()
    for i in range(len(w)-1):
        if abs(ord(list_w[i]) - ord(list_w[i+1])) != 1:
            return "No"
    return "Yes"

n = int(raw_input())
for _ in range(n):
    w = raw_input()
    print solve(w)
