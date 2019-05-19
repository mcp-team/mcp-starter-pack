# Written by: le-michael

sizes = map(int,raw_input().split())
word = raw_input()
print max([sizes[ord(w)-ord('a')] for w in word]) * len(word)
