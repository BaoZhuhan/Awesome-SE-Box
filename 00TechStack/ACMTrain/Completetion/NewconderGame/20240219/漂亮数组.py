def max_beautiful_subarrays(a, k):
    n = len(a)
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        dp[i] = dp[i - 1]
        sum = 0
        for j in range(i, 0, -1):
            sum += a[j - 1]
            if sum % k == 0:
                dp[i] = max(dp[i], dp[j - 1] + 1)
    return dp[n]

list1 = input().split(' ')
n = int(list1[0])
k = int(list1[1])

list2 = input().split(' ')
a = []
for i in range(n):
    a.append(int(list2[i]))

print(max_beautiful_subarrays(a,k))