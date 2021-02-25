#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

public:
	Node()
	{
		data = 0;
		left = right = NULL;
	}

	Node(int value)
	{
		data = value;
		left = right = NULL;
	}
};


class DoubleList {
public:
	int size;
	Node* head;
	Node* tail;
	DoubleList()
	{
		size = 0;
		this->head = this->tail = NULL;
	}


	void insertHead(int value)
	{
		Node* newNode = new Node(value);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else
		{
			newNode->right = head;
			head->left = newNode;
			head = newNode;
		}
		this->size++;
	}


	void deleteNode(int index)
	{
		Node* original = head;
		Node* tempNode;

		//index�� 1������ ����.
		if (size < index || index < 0)
			return;
		for (int i = 0; i < index - 1; i++)
		{
			head = head->right;
		}

		//������ ��� 
		if (size == 1)
		{
			//�ϳ��� �ִ� ���
			head = tail = NULL;
		}
		else if (index == 1)
		{
			tempNode = head;
			head = head->right;
			head->left = NULL;
			delete tempNode;
		}
		else if (index == size)
		{
			tempNode = head;
			head = head->left;
			head->right = NULL;
			delete tempNode;

			tail = head;
			head = original;
		}
		else
		{
			tempNode = head;
			head->left->right = head->right;
			head->right->left = head->left;
			delete tempNode;

			head = original;
		}
		this->size--;
	}

	void printNode()
	{
		Node* original = head;

		while (head != NULL) //�Ǽ� ����. 
		{
			cout << head->data << "->";
			head = head->right;
		}
		head = original;
		cout << endl;
	}
};



int main()
{
	DoubleList exer;
	exer.insertHead(10);
	exer.insertHead(20);
	exer.insertHead(30);
	exer.printNode();

	exer.deleteNode(2);
	exer.printNode();


	/*
	Mistake Note
	1. head->left->right = head->right �κ� (head->right = head->left->right�� ���� �Ǽ�)
	2. while (head == NULL)�� ���� �Ǽ� 
	3. ������ �� , head�κ��� ������ ���� head = original�� �ϸ� �ȵȴ�. 
	4. ����, ���� �� size++, --�� ���ϴ� �Ǽ� �ݺ�. 
	
	*/
	return 1;
}
