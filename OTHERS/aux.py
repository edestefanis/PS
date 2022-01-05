

arr = [int(_) for _ in raw_input().split()]

s = ""
for i in arr:
    i -= 20
    s = s + str(unichr(ord('a')+i))

print s
