#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxScore(std::string s) {
        int max = 0;
        int size = s.size();
        if (size >= 2 && size <= 500) {

            for (int i = 1 ; i < size; i++) {
                int countL = 0, countR = 0;
                
                for (int j = 0; j < i; j++) {
                    if (s[j] == '0') countL++;
                }
                for (int j = i; j < size; j++) {
                    if (s[j] == '1') countR++;
                }
                
                int curMax = countL + countR;
                if (curMax > max) max = curMax; 

                //std::cout << "L: " << left << " || " << "R: " << right << std::endl << "L:" << countL << " + " << "R:" << countR << " = " << max << std::endl; 
            }
            
        }
        
        return max;
    }
};

int main() {
    Solution sol;

    // Testes baseados nos teus exemplos
    std::cout << "Exemplo 1 (011101): " << sol.maxScore("011101") << " | Esperado: 5" << std::endl;
    std::cout << "Exemplo 2 (00111): " << sol.maxScore("00111") << " | Esperado: 5" << std::endl;
    std::cout << "Exemplo 3 (1111): " << sol.maxScore("1111") << " | Esperado: 3" << std::endl;

    return 0;
}
