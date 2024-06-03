class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        @lru_cache(None)
        def recurse(idx, s1, s2):
            if idx == len(stones):
                return abs(s1 - s2)
            a = recurse(idx + 1, s1 + stones[idx], s2)
            b = recurse(idx + 1, s1, s2 + stones[idx])
            return min(a, b)
        return recurse(0, 0, 0)
