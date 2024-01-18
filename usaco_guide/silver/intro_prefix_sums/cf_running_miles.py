def solve(n, arr):
    best3 = [n-3, n-2, n-1]
    dp = (arr[best3[0]] + arr[best3[1]] + arr[best3[2]]) - 2 # dp[n-2] -----> dp[l] = best in arr[l..]
    for i in range(n-3, -1, -1):
        # compute best from i..
        
        # case 1: don't use i
        candidate1 = dp - 1

        # case 2: use i. then have to test



t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(n, arr))
