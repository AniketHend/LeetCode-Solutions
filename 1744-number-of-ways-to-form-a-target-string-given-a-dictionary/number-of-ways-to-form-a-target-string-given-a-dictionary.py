class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        n = len(words)

        counts = defaultdict(Counter)
        for word in words:
            for j in range(len(word)):
                counts[j][word[j]] += 1
        @cache
        def dp(i, k):
            if k == len(target):
                return 1
            if i >= len(words[0]):
                return 0
            pick = 0
            if target[k] in counts[i]:
                pick = (pick + counts[i][target[k]] * dp(i + 1, k + 1)) % 1000000007
            pick = (pick + dp(i + 1, k)) % 1000000007
            return pick

        return dp(0, 0)
