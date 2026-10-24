class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        mod = 10**9 + 7

        def dfs(nums):
            N = len(nums)
            if N <= 2: return 1
            left = []
            right = []

            for i in range (1, N):
                if nums[i] < nums[0]:
                    left.append(nums[i])
                elif nums[0] < nums[i]:
                    right.append(nums[i])

            return (dfs(left) * dfs(right) * comb(N-1, len(left))) % mod

        return (dfs(nums) - 1) % mod