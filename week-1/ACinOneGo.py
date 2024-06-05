def gcd (a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    gcd = gcd(a, b)
    if gcd != 1:
        print(-1)
    else:
        print(a * b - a - b + 1)