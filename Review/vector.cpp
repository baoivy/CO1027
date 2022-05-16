#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

double Similarity(vector<char>& v1, vector<char>& v2)
{
	vector <char>::iterator it1 = v1.begin();
	vector <char>::iterator it2 = v2.begin();
	int count = 0;
	while (it1 != v1.end() - 1 || it2 != v2.end() - 1)
	{
		if (*it1 == *it2) {
			it1++; it2++;
			count++;
		}
		else if (*it1 > *it2 || it1 == v1.end() - 1) {
			it2++;
		}
		else if(*it1 < *it2 || it2 == v2.end() - 1) {
			it1++;
		}
	}
	double average = (v1.size() + v2.size()) / 2.0;
	return (double)count / average;
}
int main()
{
	vector <char> v1{'j','k','k'};
	vector <char> v2{'a','k'};
	cout << Similarity(v1, v2);
}
