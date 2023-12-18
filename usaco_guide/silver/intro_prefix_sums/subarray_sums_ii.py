from collections import defaultdict 

# with open('input.in', 'r') as file_in:
#     n, x = map(int, list(file_in.readline().split()))
#     arr = map(int, list(file_in.readline().split()))

n, x = map(int, input().split())
arr = list(map(int, input().split()))

prefix_dict = defaultdict(int)
prefix_dict[0] = 1
ans = 0

prefix_sum = 0
for i in range(1, n+1):
    prefix_sum += arr[i-1]
    ans += prefix_dict[prefix_sum - x] # the number of previous prefixes that equaled prefix[i] - x
    prefix_dict[prefix_sum] += 1 # this line needs to come _after_ the above since if x=0, then above would include the null subarray

print(ans)