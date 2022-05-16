#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

struct cellT {
	int val;
	cellT* next;
};

bool Contains(cellT* list, cellT* sub)
{
	//Idea : Traversal each element in list (if element of list = element of sub => sub->next
	cellT* ptr = sub;
	int count = 0;
	while (ptr != nullptr)
	{
		count++;
		ptr = ptr->next;
	}
	int check = 0;
	while (list != nullptr)
	{
		if (sub != nullptr) {
			if (list->val == sub->val)
			{
				sub = sub->next;
				check++;
			}
		}
		list = list->next;
	}
	return (check == count) ? true : false;
}

cellT* insert(cellT* head, int x)
{
	cellT* ptr = new cellT;
	ptr->val = x;
	ptr->next = head;
	head = ptr;
	return head;
}

int main()
{
	cellT* list = nullptr;
	cellT* sub = nullptr;
	list = insert(list, 9);
	list = insert(list, 2);
	list = insert(list, 4);
	list = insert(list, 1);

	sub = insert(sub, 1);
	sub = insert(sub, 8);

	cout << Contains(list, sub);
	return 0;
}
