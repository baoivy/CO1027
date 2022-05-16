#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

string compress(string str)
{
	for (int i = 0; i < str.length() - 1; i++)
	{
		int count = 0;
		while (str[i] == str[i + 1]) {
			str.erase(i, 1);
			count++;
		}
		if (count + 1 > 1)
			str.insert(i,to_string(count + 1));
	}
	return str;
}

int main()
{
	string str = "Oooga boooga boooga";
	cout << compress(str);
  return 0;
}
