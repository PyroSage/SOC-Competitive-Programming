// def generate(self, numRows: int) -> List[List[int]]:
//         ans = [[1]]
//         for i in range(numRows - 1):
//             temp = [0] + ans[-1] + [0]
//             row = []
//             for j in range(len(ans[-1]) + 1):
//                 row.append(temp[j] + temp[j + 1])
//             ans.append(row)
//         return ans

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 0; i < numRows - 1; i++) {
            vector<int> temp = {0};
            temp.insert(temp.end(), ans.back().begin(), ans.back().end());  
            temp.push_back(0);
            vector<int> row;
            for (int j = 0; j < ans.back().size() + 1; j++) {
                row.push_back(temp[j] + temp[j + 1]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int>> ans = sol.generate(numRows);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}