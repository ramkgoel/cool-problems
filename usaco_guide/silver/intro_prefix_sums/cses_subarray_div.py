# with open('input.in', 'r') as file_in:
#     n = int(file_in.readline())
#     arr = map(int, list(file_in.readline().split()))

n = int(input())
arr = list(map(int, input().split()))

prefix = [0 for i in range(n+1)]
freq = [0 for i in range(n)]
freq[0] = 1
for i in range(1, n+1):
    prefix[i] = (prefix[i-1] + arr[i-1]) % n
    freq[prefix[i]] += 1

ans = 0
for i in range(n):
    ans += (freq[i]**2 - freq[i])//2

print(ans)    
