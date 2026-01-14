#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int chalkReplacerOtimizado(vector<int>& chalk, int k) {
        // 1. Usar long long para evitar overflow na soma (long é inconsistente pois depende de sistema para sistema(32 ou 64 bits))
        long long total_chalk = 0;
        for (int c : chalk) total_chalk += c;

        // 2. Otimização com módulo
        // k passa a ser apenas o que sobra para a última volta
        long long resto = k % total_chalk;

        // 3. Iterar diretamente no vector (sem gastar memória com queue)
        for (int i = 0; i < chalk.size(); i++) {
            if (resto < chalk[i]) {
                return i;
            }
            resto -= chalk[i];
        }

        return 0;
    }

    int chalkReplacer(vector<int>& chalk, int k) {
        if (chalk.size() == 1) {
            return 0;
        }

        queue<int> q;
        int size = chalk.size();
        int res = -1;
        int total_chalk = 0;
        for (int chalk_used : chalk) {
            total_chalk += chalk_used;
        }

        int resto = k % total_chalk; // útil para eficiencia, pois salta logo para a última rotação 
        
        if (resto == 0) {
            return 0; // significa que vai ser o primeiro estudante
        }


        while(resto > 0) {
            for (int i = 0; i < size; i++) {
                //cout << chalk[i] << " entered the queue!" << endl;
                q.push(chalk[i]);
            }

            // tenho de guardar a posição do vetor quando este chega a zero.
            // chalk.size - queue.size
            while(!q.empty()) {
                int chalk_used = q.front();
                //cout << "- Student number " << size - q.size() << " uses " << chalk_used << " chalk, so k = " << k - chalk_used << endl;
                q.pop();
                
                
                // há giz mas tem de pedir
                if (resto < chalk_used) {
                    //cout << "Size: " << q.size() << endl;
                    res = size - (q.size() + 1);
                    return res;
                } 
                // giz acaba, próximo estudante tem de pedir
                else if(resto == chalk_used) {
                    //cout << "Size: " << q.size() << endl;
                    if (q.empty()) {
                        return 0 ;   
                    }
                    res = size - q.size();
                    return res;
                    
                } 
                else {
                    resto -= chalk_used;
                }
            }

        }
        
        return res;
    }
};

int main() {
    Solution sol;

    // Exemplo 1
    vector<int> chalk1 = {5, 1, 5};
    int k1 = 22;
    cout << "Exemplo 1 (chalk=[5,1,5], k=22): " << sol.chalkReplacer(chalk1, k1) 
         << " | Esperado: 0" << endl;

    // Exemplo 2
    vector<int> chalk2 = {3, 4, 1, 2};
    int k2 = 25;
    cout << "Exemplo 2 (chalk=[3,4,1,2], k=25): " << sol.chalkReplacer(chalk2, k2) 
         << " | Esperado: 1" << endl;

    return 0;
}