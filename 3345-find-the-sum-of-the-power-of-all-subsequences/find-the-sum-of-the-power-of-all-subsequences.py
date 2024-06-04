
class Solution:
    def sumOfPower(self, nums: List[int], k: int) -> int:
        n = len(nums)
        MOD = 10**9 + 7

        @cache
        def dp(i: int, cs: int, count: int) -> int:
            if cs == k:
                return (2 ** (n - count))
            if i == n:
                return 0            
            if(cs > k) :
                return 0
            take = dp(i + 1, cs + nums[i], count + 1)
            nottake = dp(i + 1, cs, count)

            result = (take + nottake)
            return result

        return dp(0, 0, 0) % MOD
