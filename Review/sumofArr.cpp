#include <iostream>
#include <vector>
using namespace std;

int countwaySumArray(vector <int> arr, int x, int idx = 0)
{
	int res = arr[idx];
	if (x == res)
		return 1;
	if (x < res)
		return 0;
	if (idx >= arr.size())
		return 0;
	int a = countwaySumArray(arr , x - res, idx + 1);
	int b = countwaySumArray(arr, x, idx + 1);
	return a + b;
}

int main()
{
	vector <int> arr{ 1,2,1,3,4};
	int x = 4;
	cout << countwaySumArray(arr, x);
	return 0;
}
