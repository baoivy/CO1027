#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

queue<int> ExtractStrand(queue<int>& q)
{
	queue <int> res;
	int tmp = q.front();
	q.pop();
	res.push(tmp);
	while (!q.empty()) {
		int tmp1 = q.front();
		if (tmp <= q.front() && tmp1 >= res.back())
		{
			res.push(q.front());
		}
		//int tmp = q.front();
		q.pop();
	}
	return res;
}
int main()
{
	queue <int> q;
	q.push(2);
	q.push(1);
	q.push(7);
	q.push(12);
	q.push(13);
	q.push(10);
	q = ExtractStrand(q);
	
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
