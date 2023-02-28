#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node(int d)
	{
		this->data = d;
		this->next = NULL;
	}
};

class Stack
{
public:
	Node *top = NULL;   // top == head    // imp to assign it to null else show error

    //insert at head
	void push(int d)
	{
		Node *temp = new Node(d);
		temp->next = top;
		top = temp;
	}

	void pop()
	{
		Node *temp = top;
		top = top->next;
		temp->next = NULL;
		delete temp;
	}

	void print()
	{
		Node *temp = top;

		while (temp != NULL)
		{
			if(temp != NULL)
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	s.print();

	s.pop();
	s.print();

	s.pop();
	s.print();

	s.pop();
	s.print();


	return 0;
}