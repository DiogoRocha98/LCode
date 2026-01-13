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

/*
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3

Example 2:

Input: s = "00111"
Output: 5
Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5

Example 3:

Input: s = "1111"
Output: 3

Constraints:

    2 <= s.length <= 500
    The string s consists of characters '0' and '1' only.

*/