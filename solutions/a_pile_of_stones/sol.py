# Written by: wyattwismer

n = int(raw_input())
h,mn = 0,0
for c in raw_input():
    h += 1 if c=='+' else -1
    mn = min(mn,h)
print -mn + h

