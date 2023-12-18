with open('maxcross.in', 'r') as file_in:
    n, k, b = map(int, list(file_in.readline().split()))
    bad = [0 for i in range(n)]
    for i in range(b):
        bad_idx = int(file_in.readline()) - 1
        bad[bad_idx] = 1

prefix = [0 for i in range(n+1)]
for i in range(1, n+1):
    prefix[i] = prefix[i-1] + bad[i-1]

# minimum bad to make 0 so that block of k with 0 bad
ans = n
for i in range(0, n+1-k):
    ans = min(ans, prefix[i+k] - prefix[i])

with open('maxcross.out', 'w') as file_out:
    file_out.write(str(ans) + '\n')