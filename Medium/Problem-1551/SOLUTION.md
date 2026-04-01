# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Matemática. Ao ver os resultados de testcases de todos os números de 1 a dez reparei no padrão que se estava a formar. Em números pares verifiquei que os resultados estavam a seguir a seguinte ordem (1; 4; 9; 16). Lembrei-me logo de n^2.

# Approach
<!-- Describe your approach to solving the problem. -->
- Fazer print do array iniciando com a função.
- Inicialmente achei que houvesse diferença entre N's ímpares e pares devido à operação a menos feita pelos números ímpares, sendo que o valor intermédio, é o própio N, enquanto nos pares, este valor intermédio não existe e tem de ser alcançado por todos os números da lista.
- Por achar que esta diferença existia, planeava criar um if para os pares e um para os impares.
- Padrão resultado pares   : (1; 4; 9; 16; 25; ...)
- Padrão resultado ímpares : (2; 6; 12; 20; 30; ...)
- Após perder algum tempo à procura de aplicar isso em código, recordei que são duas operações feitas de um só vez por isso podemos simplesmente descontar metade da lista nas contas chegando assim à função $$ (n/2)^2 $$. 
- Ao dividir n/2 nos ímpares ficamos com valores como (1.5; 2.5; 3.5;4.5; 5.5) com os respetivos quadrados de (2.25; 6.25; 12.25; 20.25; 30.25). 
- Bastava converter de float para int que arredondado dá o resultado certo.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(1) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(1) $$

# Code
```python3 []
class Solution:
    def minOperations(self, n: int) -> int:
        return int(((n / 2) ** 2))

```