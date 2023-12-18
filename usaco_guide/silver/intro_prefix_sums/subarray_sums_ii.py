from collections import defaultdict 

# with open('input.in', 'r') as file_in:
#     n, x = map(int, list(file_in.readline().split()))
#     arr = map(int, list(file_in.readline().split()))

n, x = map(int, input().split())
arr = list(map(int, input().split()))

prefix = [0 for i in range(n+1)]
for i in range(1, n+1):
    prefix[i] = prefix[i-1] + arr[i-1]

targets = defaultdict(list)
for i in range(n+1):
    targets[prefix[i] + x].append(i)

ans = 0
for j in range(n+1):
    # for i in targets[prefix[j]]:
    #     if i < j:
    #         ans += 1
    #     else:
    #         break

    # find number of elements of targets[prefix[j]] which are less than j
    # will find first value >= j
    starts = targets[prefix[j]]
    if len(starts) == 0:
        continue 

    if starts[-1] < j:
        ans += len(starts)
    elif starts[0] >= j:
        ans += 0
    else:
        # at least one is >= j
        low, high = 0, len(starts) - 1
        while high - low > 1:
            mid = (high-low)//2 + low
            if starts[mid] < j:
                low = mid 
            else:
                high = mid 
        ans += (low+1)
    


print(ans)