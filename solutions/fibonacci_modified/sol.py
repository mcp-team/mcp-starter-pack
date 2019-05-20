# Written by: le-michael

def dyn_fib(t1, t2, n):
    table = [t1,t2]
    for i in range(1,n-1):
        table.append(table[i-1] + table[i]**2)
    return table[-1]

t1, t2, n = map(int,raw_input().split())
print dyn_fib(t1, t2, n)
