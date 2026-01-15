from collections import Counter

class Solution:
    def countElements(self, nums: list[int], k: int) -> int:
        if k >= len(nums):
            return 0  
        
        freq = Counter(nums)
        # print(f"Dicionário de frequências: {freq}")
        
        ordUniqueKeys = sorted(freq.keys())
        # print(f"Elementos Únicos ordenados: {ordUniqueKeys}")   
        
        total = len(nums)
        remainingK = k
        for num in reversed(ordUniqueKeys):
            if remainingK <= 0: 
                break
            freqLast = freq[num]
            # print(f"Freq elemento {ordUniqueKeys[listPos]}: {freqLast}") # Último elemento da lista.
            remainingK -= freqLast
            # print(f"K restante: {remainingK}") # Se sobrar k, vou ter de descer mais um elemento e subtrair todas as suas cópias ao total de qualificados
            total -= freqLast
            # print(f"Novo total de elemento qualificados: {total}")
            
        return total
        

if __name__ == "__main__":
    sol = Solution()
    
    print(f"Exemplo 1 ([3,1,2] ; 1): {sol.countElements([3,1,2], 1)} | Esperado: 2")
    print(f"Exemplo 2 ([5,5,5] ; 2): {sol.countElements([5,5,5], 2)} | Esperado: 0")
    print(f"Exemplo 3 ([332931278,226558367,744830869] ; 2): {sol.countElements([332931278,226558367,744830869], 2)} | Esperado: 1")
    print(f"Exemplo 4 ([3,3,2,9,3,1,2,7,8,2,2,6,5,5,8,3,6,7,7,4,4,8,3,1,8,6,9] ; 2): {sol.countElements([3,3,2,9,3,1,2,7,8,2,2,6,5,5,8,3,6,7,7,4,4,8,3,1,8,6,9], 2)} | Esperado: 25")