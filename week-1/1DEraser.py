n = int(input())

for _ in range(n):
    r, k = map(int, input().split(" "))
    ls = input()
    count = 0
    i = 0
    while i < r:
        if ls[i] == 'B':
            count += 1
            i += k
        else:
            i += 1
    print(count)