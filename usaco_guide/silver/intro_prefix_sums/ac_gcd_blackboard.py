def gcd(a, b):
    if a >= b:
        a, b = b, a
    if a==0:
        return b 
    if a==1:
        return 1
    return gcd(b%a, a)

n = int(input())
arr = list(map(int, input().split()))

prefix_gcd = [0 for i in range(n+1)] # prefix_gcd[i] = gcd(arr[..i])
suffix_gcd = [0 for i in range(n+1)] # suffix_gcd[i] = gcd(arr[i..])

for i in range(1, n+1):
    prefix_gcd[i] = gcd(prefix_gcd[i-1], arr[i-1])

for i in range(n-1, -1, -1):
    suffix_gcd[i] = gcd(arr[i], suffix_gcd[i+1])

ans = 0
for i in range(n):
    # remove i. so :i and i+1:
    cur_gcd = gcd(prefix_gcd[i], suffix_gcd[i+1])
    ans = max(ans, cur_gcd)

print(ans)

