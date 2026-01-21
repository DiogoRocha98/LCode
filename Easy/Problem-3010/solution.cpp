#include <iostream>
#include <vector>
#include <climits>


class Solution {
public:
    int minimumCostSimpler(std::vector<int>& nums) {
        int min1 = INT_MAX; 
        int min2 = INT_MAX;

        for (size_t i = 1; i < nums.size(); i++) 
        {
            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            } else if (nums[i] < min2) {
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    };

    int minimumCost(std::vector<int>& nums) {
        // Dividir array em 3 sub-arrays. O primeiro elemento é o custo do array.
        // Objetivo de encontrar os 3 subarrays, onde a soma dos custos é a menor.
        // O primeiro elemento do array original vai fazer parte da solução obrigatóriamente. Tenho de encontrar agora os 2 minimos.
        int size = nums.size();
        
        if(size == 3) {
            return nums[0] + nums[1] + nums[2];
        }
        
        int min1 = nums[1], min2 = nums[2];
  
        for(int i = 3; i < size; i++) {
            if(nums[i] <= min1) {
                if(min1 <= min2) {
                    min2 = min1;
                    min1 = nums[i];
                } else {
                    min1 = nums[i];
                }
            } else if(nums[i] <= min2) {
                min2 = nums[i];
            } else {
                continue;
            }
        }
        return nums[0] + min1 + min2;
    }
};

int main() {
    Solution sol;

    // Exemplo 1:
    std::vector<int> nums1 = {3,4,1,5,6,2,5,2,6};
    std::cout << "Exemplo 1 {3,4,1,5,6,2,5,2,6} | Esperado: (3+1+2) = 6; Resultado: " << sol.minimumCost(nums1); 
}