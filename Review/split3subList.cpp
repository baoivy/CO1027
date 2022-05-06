#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};


Node* insert(Node* head, int x)
{
	Node* ptr = new Node;
	ptr->data = x;
	ptr->next = head;
	head = ptr;
	return head;
}


int sumAll(Node* head)
{
	int count = 0;
	Node* ptr = head;
	while (ptr != nullptr)
	{
		count += ptr->data;
		ptr = ptr->next;
	}
	return count;
}

bool split3List(Node* head)
{
	int sumAll1 = sumAll(head);
	Node* ptr1 = head;
	int sum1 = 0;
	while (ptr1->next->next != nullptr)
	{
		sum1 += ptr1->data;
		Node* ptr2 = ptr1->next;
		int sum2 = 0;
		while (ptr2->next != nullptr)
		{
			sum2 += ptr2->data;
			if (sum1 == sum2 && sum1 == (sumAll1 - sum1 - sum2))
			{
				return true;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
	return false;
}


int main()
{
	Node* head = nullptr;
	head = insert(head, 1);
	head = insert(head, 1);
	//head = insert(head, 1);
	//head = insert(head, 1);
	//head = insert(head, 2);
	//head = insert(head, 4);
	cout << split3List(head);
	return 0;
}
