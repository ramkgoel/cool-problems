with open('hps.in', 'r') as file_in:
    n = int(file_in.readline().strip())
    # convert list to which letters beat it (P means S beats it, H means P beats it, S means H beats it)
    convert = {'P': 'S', 'H': 'P', 'S': 'H'}
    arr = [None for i in range(n)]
    for i in range(n):
        char = file_in.readline().strip()
        arr[i] = convert[char]

    prefixP = [0 for i in range(n+1)]
    prefixH = [0 for i in range(n+1)]
    prefixS = [0 for i in range(n+1)] #prefixS[i] = num S's in 0:i

    for i in range(1, n+1):
        prefixP[i] = prefixP[i-1] + (1 if arr[i-1] == 'P' else 0)
        prefixH[i] = prefixH[i-1] + (1 if arr[i-1] == 'H' else 0)
        prefixS[i] = prefixS[i-1] + (1 if arr[i-1] == 'S' else 0)

    ans = 0
    for i in range(0, n+1):
        for first in [prefixP, prefixH, prefixS]:
            for second in [prefixP, prefixH, prefixS]:
                ans = max(ans, first[i] + (second[n] - second[i]))

with open('hps.out', 'w') as file_out:
    file_out.write(str(ans) + '\n')
    
