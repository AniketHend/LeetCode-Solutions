import math

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # Iterate over possible values of a from 0 to sqrt(c)
        for a in range(int(math.sqrt(c)) + 1):
            b_squared = c - a * a
            b = int(math.sqrt(b_squared))
            if b * b == b_squared:
                return True
        return False
