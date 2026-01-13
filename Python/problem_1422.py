class Solution:
    def maxScore(self, s: str) -> int:
        max_val = 0
        n = len(s)
        
        for i in range(1, n):
            left = s[:i]
            right = s[i:]
            
            score = left.count('0') + right.count('1')
            
            if score > max_val:
                max_val = score
                
        return max_val

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Exemplo 1 (011101): {sol.maxScore('011101')} | Esperado: 5")
    print(f"Exemplo 2 (00111):  {sol.maxScore('00111')} | Esperado: 5")
    print(f"Exemplo 3 (1111):   {sol.maxScore('1111')} | Esperado: 3")