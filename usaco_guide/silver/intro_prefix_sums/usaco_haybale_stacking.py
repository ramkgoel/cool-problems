# with open('input.in', 'r') as file_in:
n, k = map(int, input().split())
# n, k = map(int, file_in.readline().split())

delta = [0 for i in range(n+1)] 
haybale = [0 for i in range(n)]
for i in range(k):
    l, r = list(map(int, input().split()))
    # l, r = map(int, file_in.readline().split())

    l -= 1
    r -= 1

    delta[l] += 1
    delta[r+1] -= 1

    # so sum(delta[..l]) = haybale[l]
    # haybale[r] = sum(delta[..r])

haybale[0] = delta[0]
for i in range(1, n):
    haybale[i] = haybale[i-1] + delta[i]

haybale.sort()
print(haybale[(n-1)//2])
