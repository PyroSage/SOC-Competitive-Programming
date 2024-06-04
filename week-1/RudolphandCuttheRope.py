n = int(input())

for i in range(n):
    r = int(input())
    count = 0
    for _ in range(r):
        a, b = map(int, input().split())
        if a > b:
            count += 1
    print(count)
    