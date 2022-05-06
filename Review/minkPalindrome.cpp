#include <iostream>
#include <vector>
#include <string>
using namespace std;

int kPali(string str, string str1, int m, int n)
{
	if (m == 0)
		return n;

	if (n == 0)
		return m;

	if (str[m - 1] == str1[n - 1])
		return kPali(str, str1, m - 1, n - 1);
	
	return 1 + min(kPali(str, str1, m - 1, n), kPali(str, str1, m, n - 1));
}


int palindrome(string str, int k)
{
	string str1 = string(str.rbegin(), str.rend());
	return kPali(str, str1, str.length(), str1.length()) / 2;

}

int main()
{
	string str = "aderbcghbaj";
	cout << palindrome(str,0);

	return 0;
}
