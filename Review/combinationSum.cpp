#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <utility>
#include <set>
const double PI = 3.14159265359;
#define mod 9E10 + 7
using namespace std;


/*void combinationSum(int idx, int sum, vector<int> arr, vector<int>& tmp, vector<vector<int>>& res) {
    if (sum == 0) {
        res.push_back(tmp);
        return;
    }

    while (idx < arr.size() && sum - arr[idx] >= 0) {
        tmp.push_back(arr[idx]);
        combinationSum(idx, sum - arr[idx], arr, tmp, res);
        idx++; tmp.pop_back();
    }
}*/

void Unique_combinationSum(int idx, int sum, vector<int> arr, vector<int>& tmp, vector<vector<int>>& res) {
    if (sum == 0) {
        res.push_back(tmp);
        return;
    }

    while (idx < arr.size() && sum - arr[idx] >= 0) {
        if (idx < arr.size() - 1 && arr[idx] == arr[idx + 1])
        {
            Unique_combinationSum(idx + 1, sum, arr, tmp, res);
        }
        //idx--;
        tmp.push_back(arr[idx]);
        Unique_combinationSum(idx + 1, sum - arr[idx], arr, tmp, res);
        idx++; tmp.pop_back();
    }
}

vector<vector<int>> solve(vector<int> arr, int target) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int idx = 0;
    vector<int> tmp;
    Unique_combinationSum(idx, target, arr, tmp, res);
    return res;
}
int main(){
    vector<int> arr{ 2,2,2,2};
    int target = 8;
    vector<vector<int>> arr_res = solve(arr, target);
    for (int i = 0; i < arr_res.size(); i++)
    {
        for (int j = 0; j < arr_res[i].size(); j++) {
            cout << arr_res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
