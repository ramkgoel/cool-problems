with open('bcount.in', 'r') as file_in:
    with open('bcount.out', 'w') as file_out:
        n, q = map(int, file_in.readline().split())

        num1 = [0 for _ in range(n+2)]
        num2 = [0 for _ in range(n+2)]
        num3 = [0 for _ in range(n+2)]  # num3[i] = number of 3s in vals[0:i]

        for i in range(1, n+1):
            val = int(file_in.readline())
            num1[i] = num1[i-1] + (1 if val == 1 else 0)
            num2[i] = num2[i-1] + (1 if val == 2 else 0)
            num3[i] = num3[i-1] + (1 if val == 3 else 0)

        num1[-1], num2[-1], num3[-1] = num1[-2], num2[-2], num3[-2]

        for _ in range(q):
            l, r = map(int, file_in.readline().split())
            l -= 1
            r -= 1
            ans1, ans2, ans3 = num1[r+1] - num1[l], num2[r+1] - num2[l], num3[r+1] - num3[l]
            file_out.write(f"{ans1} {ans2} {ans3}\n")
