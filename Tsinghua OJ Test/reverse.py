a = input().split()
a = [int(str(i)[::-1]) for i in a]
a.sort()
print(a[1])