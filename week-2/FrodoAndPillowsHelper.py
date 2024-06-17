def find_max_value(n, m, k):
    m -= n  # Adjust the total resources since we already count 1 at each position.

    left = 0
    right = m

    while left < right:
        mid = (left + right + 1) // 2

        # Calculate the number of positions we can use on the left and right of `k`
        left_positions = min(k - 1, mid - 1)
        right_positions = min(n - k, mid - 1)
        # Calculate the resources needed to form the peak
        needed = (
            mid +  # Value at position `k`
            ((left_positions * mid) - ((left_positions + 1)*(left_positions) // 2)) +  # Sum on the left
            ((right_positions * mid)- ((right_positions + 1)*(right_positions) // 2))  # Sum on the right
        )
        print('Before')
        print(f'left_positions:{left_positions}, right_positions:{right_positions}')
        print(f'left:{left}, mid: {mid}, right:{right}')
        print(f'left_sum:{left_positions * (mid - left_positions + mid - 1) // 2},mid: {mid} ,right_sum:{right_positions * (mid - right_positions + mid - 1) // 2}')
        print(f'needed total sum:{needed}')
        # Adjust the search range based on the resources needed
        if needed > m:
            right = mid - 1
        else:
            left = mid
        print('After')
        print(f'left:{left}, mid: {mid}, right:{right}')

    return left + 1  # The maximum value we can place at position `k`

# Read input values
n, m, k = map(int, input().split())
print(find_max_value(n, m, k))
