# n = int(input())

# for _ in range(n):
#     i, j = map(int, input().split(" "))
#     in_column = 0
#     if i >= j:
#         max, min = i, j
#         in_column = 1
#     else:
#         max, min = j, i
#     max_parity = max & 1
#     if max_parity == in_column:
#         print((max * max) - max + 1 - (max - min))
#     else:
#         print((max * max) + 1 - min)
    
def spiral(i , j):
    in_column = 0
    if i >= j:
        max, min = i, j
        in_column = 1
    else:
        max, min = j, i
    max_parity = max & 1
    max_square = max * max
    if max_parity == in_column:
        return max_square - max + 1 - (max - min)
    else:
        return max_square + 1 - min

for i in range(1, 10):
    for j in range(1, 10):
        print(spiral(i, j), end=" ")
    print()