class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:

        @cache
        def f(index, target):
            if target == 0:
                return ""
            if target < 0 or index < 0:
                return "0"

            # picking up the current digit
            pick = str(index + 1) + f(index, target - cost[index])
            # excluding current digit
            non_pick = f(index - 1, target)
            # answer not found on picking current digit
            if "0" in pick and "0" in non_pick:
                return "0"
            if "0" in pick:
                return non_pick
            # answer not found on excluding current digit
            elif "0" in non_pick:
                return pick
            else:
                if len(pick) > len(non_pick):
                    return pick
                elif len(pick) < len(non_pick):
                    return non_pick
                else:
                    return pick

        result = f(len(cost) - 1, target)
        return result if result != "0" else "0"
