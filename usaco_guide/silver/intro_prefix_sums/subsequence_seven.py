with open('div7.in', 'r') as file_in:
    n = int(file_in.readline().strip())
    prefix = [0 for i in range(n+1)]  # prefix[i] = sum(0:i)

    first = [-1 for i in range(7)]
    last = [-1 for i in range(7)]

    for i in range(1, n+1):
        val = int(file_in.readline().strip())
        prefix[i] = (prefix[i-1] + val) % 7
        if first[prefix[i]] == -1:
            first[prefix[i]] = i

    for i in range(n, -1, -1):
        if last[prefix[i]] == -1:
            last[prefix[i]] = i

    max_dist = 0
    for res in range(7):
        if last[res] != -1 and first[res] != -1:
            dist = last[res] - first[res]
            max_dist = max(max_dist, dist)

with open('div7.out', 'w') as file_out:
    file_out.write(str(max_dist) + '\n')
