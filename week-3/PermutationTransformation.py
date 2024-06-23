
class Solution:
    def update(self, ls, arr, level):
        if len(ls) == 0:
            return
        max_size = max(ls)
        max_index = ls.index(max_size)
        arr[max_size] = level
        self.update(ls[:max_index], arr, level+1)
        self.update(ls[max_index+1:], arr, level+1)
        return

    def permutationTransformation(self, n, ls):
        arr = {}
        self.update(ls, arr, 0)
        return arr


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        ls = list(map(int, input().split()))
        s = Solution()
        arr = s.permutationTransformation(n, ls)
        for i in range(n):
            print(arr[ls[i]], end=' ')
        print()
        