#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countElementsEfficient(vector<int>& nums, int k) {
        int size = nums.size();
        if (k <= 0) return size;
        if (k >= size) return 0;

        sort(nums.begin(), nums.end()); // (O(N log N)) - Memória conttígua e evito gastar memória no mapa

        int limit = nums[size - k]; // encontra o k-ésimo maior elemento  
        
        auto it = lower_bound(nums.begin(), nums.end(), limit); // Binary Search (O(N log N)) - Devolve iterador referente á posição anterior ao limite

        return distance(nums.begin(), it); // calcula a distância entre o ínicio e a tal posição limite
    }

    int countElementsMapMoreEfficient(vector<int>& nums, int k) {
        if(k >= nums.size()) {
            return 0;
        }

        unordered_map<int, int> freq; // (HashMap - O(N), mais eficiente que o Map (Árvore binária de procura))
        for(int num : nums) {
            freq[num]++;
        }

        vector<int> uniqueKeys; // (Memória contígua, mais eficiente que o Set (Árvore binária de procura))
        uniqueKeys.reserve(freq.size());
        for (auto const& [value, count] : freq) { // const - valor que não vai ser alterado / & - evita criar cópias, e vai direto ao valor já guardado em memória.
            uniqueKeys.push_back(value);
        }

        sort(uniqueKeys.rbegin(), uniqueKeys.rend()); // (O(U log U)) dentro do limite do Time Limit Exceeded (< O(N²))

        int total = nums.size();
        int remainingK = k;
        for (int val : uniqueKeys) {
            if (remainingK <= 0) break;
            int count = freq[val];
            remainingK -= count;
            total -= count;
        }

        return total;
    }

    int countElementsOriginal(vector<int>& nums, int k) {
        if(k >= nums.size()) {
            return 0;
        }

        map<int, int> nrMap;
        set<int> orderedSet;
        int total = nums.size();
        int remainingK = k;
        set<int>::reverse_iterator rit;

        for(int num : nums) 
        {
            if(nrMap.contains(num)) {
                nrMap[num]++;
            }
            else {
                nrMap[num] = 1;
                orderedSet.insert(num);
            }
        }

        /*for(auto num : nrMap) {
            cout << num.first << " : " << num.second << endl;
        }
        cout << "[ ";
        for(auto num : orderedSet) {
            if (num == *orderedSet.rbegin()) {
                //cout << num << " ]" << endl;
            }
            //cout << num << ", ";
        }*/
        
        for (rit = orderedSet.rbegin(); rit != orderedSet.rend(); rit++) {
            if (remainingK <= 0) break;
            int freqLast = nrMap[*rit];
            remainingK -= freqLast;
            total -= freqLast;
        }

        return total;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3,1,2};
    cout << "Exemplo 1 (nums=[3,1,2], k=1): " << endl << sol.countElementsEfficient(nums1,1) 
         << " | Esperado: 2" << endl;

    vector<int> nums2 = {5,5,5};
    cout << "Exemplo 2 (nums=[5,5,5], k=2): " << endl << sol.countElementsEfficient(nums2,2) 
         << " | Esperado: 0" << endl;

    vector<int> nums3 = {3,3,2,9,3,1,2,7,8,2,2,6,5,5,8,3,6,7,7,4,4,8,3,1,8,6,9};
    cout << "Exemplo 2 (nums=[3,3,2,9,3,1,2,7,8,2,2,6,5,5,8,3,6,7,7,4,4,8,3,1,8,6,9], k=2): " << endl << sol.countElementsEfficient(nums3,2) 
         << " | Esperado: 25" << endl;
}