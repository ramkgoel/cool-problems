n, q = map(int, input().split())
a = list(map(int, input().split()))

cur = 0
prefix = [0 for i in range(n+1)] # prefix[i] = sum[0:i]
for i in range(n):
    cur += a[i]
    prefix[i+1] = cur

for i in range(q):
    l, r = map(int, input().split())
    print(prefix[r] - prefix[l])
