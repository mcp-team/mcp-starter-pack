# Written by: le-michael

n = int(raw_input())
word = raw_input()
k = int(raw_input())

def shift(w, k):
    if not w.isalpha(): return w
    if w.isupper(): return chr(ord('A') + (ord(w)-ord('A')+k)%26)
    return chr(ord('a') + (ord(w)-ord('a')+k)%26)

ans = ""
for w in word: ans += shift(w, k)
print ans
