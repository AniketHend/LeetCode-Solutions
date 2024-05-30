class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:

        n = len(dungeon)
        m = len(dungeon[0])

        @cache
        def dp(i, j):
            if i >= n or j >= m:
                return 1e9
            if i == n - 1 and j == m - 1:
                if dungeon[i][j] <= 0:
                    return (-dungeon[i][j]) + 1
                else:
                    return 1
            left = dp(i, j + 1)
            up = dp(i + 1, j)
            p = min(left, up) - dungeon[i][j]
            if p <= 0:
                return 1
            return p

        p = dp(0, 0)
        return p
