#include <iostream>
#include <string>

using namespace std;



class Node
{
public:
	int data;
	Node* next;
};

class List
{
public:

	Node* head;
	Node* current;
	Node* pre;

	List();
	~List();

	void addNode(int data);
	void delNode(int data);
	void prtList();
};

List::List() {
	head = NULL;
	current = NULL;
	pre = NULL;
}

List::~List() {
	cout << "list deleted" << endl;
}

void List::addNode(int data)
{
	//add new node
	Node* n = new Node();

	if (head == NULL)
	{
		// empty list
		head = n;
	}
	else 
	{
		// link to the list
		current = head;
		while (current->next != NULL)
		{
			// advance  in the list
			current = current->next;
		}
		current->next = n;
	}
	n->data = data;
	n->next = NULL;
}

void List::delNode(int data) {
	// delete data from the whole list
	Node* delPtr = NULL; // free the memory
	current = head; 
	pre = head;

	while (current != NULL)
	{
		if (current->data == data)
		{
			if (current == head)
			{                 // delete the head
				delPtr = head;
				head = head->next;
				current = head;
				pre = head;
				delete delPtr;
			}
			else
			{
				pre->next = current->next;
				delPtr = current;
				current = current->next;
				delete delPtr;
			}
		}
		else
		{
			pre = current;
			current = current->next;
		}
	}
}

void List::prtList() {
	// Print to console the All data in the List
	if (head == NULL)
	{
		cout << " No item in the list" << endl;
	}
	else
	{
		current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}	
}

int main()
{
	List* list=new List;
	//  create a linked list       
	cout << "***************************" << endl;
	cout << "**** Create Linked List****" << endl;
	cout << "***************************" << endl;

	for (int i = 1; i <= 100; i++)   // input data from '1' to '100' separated by '0'
	{
		list->addNode(0);
		list->addNode(i);
	}
	list->prtList();     // Display function
	list->delNode(0);   // Delete zero '0'
	cout << "***************************" << endl;
	cout << "**** delete zero ****" << endl;
	cout << "***************************" << endl;
	list->prtList();   // Display resutls
	cout << "***************************" << endl;
	cout << "**** delete Linked list ****" << endl;
	cout << "***************************" << endl;
	delete list;

	cin.get();
	return 0;
}