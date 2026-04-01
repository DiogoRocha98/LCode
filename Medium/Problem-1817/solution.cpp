#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> result(k, 0);
        map<int, set<int>> uniqueUserMins;
        for (const auto& log : logs) {
            uniqueUserMins[log[0]].insert(log[1]);
        }
        for (const auto& [key, value] : uniqueUserMins) {
        result[value.size() - 1]++;
        }
        return result;
    }
};
