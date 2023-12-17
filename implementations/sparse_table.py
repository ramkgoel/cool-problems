import math

# implement query-based sparse table (range minimum query)
# want min(arr[l:r]) for any given query l, r
arr = [1, 3, 4, 8, 6, 1, 4, 2]
n = len(arr)
queries = [[0, 2], [3, 7], [2, 3], [2, 4], [3, 5]]

# rmq[i][a] = min(arr[a: a+2**i])
# idea: instead of naively going through l..r, pair up the elements. then pair those up, etc. 

# rmq[i][a] = min(arr[a:a+2**i]) 
#           = min(arr[a:a+2**(i-1)], arr[a+2**(i-1):a+2**i]) = min(rmq[i-1][a], rmq[i-1][a+2**(i-1)])

# for min[l:r], it's min(min[l : l+2**k], min[r-2**k : r]), which works since 2**(k+1) >= r-l, so ranges overlap.

max_log = int(math.log(n, 2)) + 1
rmq = [[0 for a in range(n)] for i in range(max_log+3)]

rmq[0] = arr
for i in range(1, max_log+1): 
    for a in range(0, n - 2**i + 1): # [n-2**i, n)
        rmq[i][a] = min(rmq[i-1][a], rmq[i-1][a+2**(i-1)])

for l, r in queries:
    k = math.floor(math.log(r-l, 2))
    ans = min(rmq[k][l], rmq[k][r-2**k])
    print([l, r], ans)

