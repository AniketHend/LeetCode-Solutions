# class Solution:
#     def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
#         @lru_cache(None)

#         def dp(i, g, p):
#             if i == len(profit):
#                 if p >= minProfit and g <= n:
#                     return 1
#                 return 0
#             if g > n:
#                 return 0

#             include = dp(i + 1, g + group[i], p + profit[i])
#             exclude = dp(i + 1, g, p)
#             return include + exclude

#         return dp(0, 0, 0) % (10**9 + 7)
class Solution:
    def profitableSchemes(self, n: int, minProfit: int, group: List[int], profit: List[int]) -> int:
        
        @lru_cache(None)
        
        def dfs(i,pro,people):
            if i>=len(group):
                return pro>=minProfit

            ways = 0

            if people+group[i]<=n:
                ways+=dfs(i+1,min(minProfit,pro+profit[i]),people+group[i])

            ways+=dfs(i+1,pro,people)

            return ways
            
        return dfs(0,0,0)%(10**9+7)