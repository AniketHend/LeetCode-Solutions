class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        @cache
        def dp(i, k):
            if i == len(piles) or k == 0:
                return 0

            prefixsum = 0
            res = dp(i + 1, k)
            for j in range(min(k, len(piles[i]))):
                prefixsum += piles[i][j]
                res = max(res, prefixsum + dp(i + 1, k - j - 1))
            return res

        return dp(0, k)
