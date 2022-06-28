#include <iostream>
#include <vector>

using namespace std;

void recur_dice(int n, int nums, vector<int> &tmp, vector<vector<int>>& arr) {
	if (tmp.size() == n) {
		arr.push_back(tmp);
		return;
	}
	
	while(nums <= 6) {
		tmp.push_back(nums);
		recur_dice(n ,nums, tmp, arr);
		nums++;
		tmp.pop_back();
	}
}
void diceRoll(int n) {
	vector<vector<int>> arr;
	vector<int> tmp;
	int nums = 1;
	recur_dice(n, nums, tmp, arr);
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n = 100;
	diceRoll(n);
	return 0;
}
