class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total_chalk = sum(chalk)
        resto = k % total_chalk
        for i, x in enumerate(chalk):
            if(resto < x):
                return i
            resto -= x
        return 0