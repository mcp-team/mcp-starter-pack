from collections import defaultdict
def valid(limit):
    for key in freq:
        if freq[key] > limit:
            return False
    return True
n = int(raw_input())
limit = n/4
gene = raw_input()
freq = defaultdict(int)
for char in gene:
    freq[char] += 1
p0,p1 = 0,0
ans = n+1
while p0 != n and p1 != n and p1 >= p0:
    if valid(limit):
        length = max(0,p1-p0)
        ans = min(length,ans)
        freq[gene[p0]] += 1
        p0 += 1
    else:
        curr = gene[p1]
        freq[curr] -= 1
        p1 += 1
print ans
