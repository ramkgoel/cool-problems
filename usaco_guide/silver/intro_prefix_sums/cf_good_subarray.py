from collections import defaultdict

t = int(input())
for _ in range(t):
    n = int(input())
    s = list(map(int, list(input())))
    for i in range(n):
        s[i] -= 1

    prefix = [0 for i in range(n+1)]
    freq = defaultdict(int)
    freq[0] = 1
    for i in range(1, n+1):
        prefix[i] = prefix[i-1] + s[i-1]
        freq[prefix[i]] += 1
    
    ans = 0
    for val in freq:
        ans += (freq[val]**2 - freq[val])//2 
    
    print(ans)
    

