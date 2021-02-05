#include <iostream>
using namespace std;


class Node {
public:
	int data;
	Node *prev;
	Node *next;
	
	Node ()
	{
		this->data = 0;
		this->prev = this->next = NULL;
	}
};

class DoubleList {
public:
	int size;
	Node *head , *tail;
	
	
	DoubleList()
	{
		this->size = 0;
		this->head = this->tail = NULL;
	}
	
	
	void insert (int value)
	{
		
		Node *newNode = new Node();
		newNode->data = value;
		
		
		if(this->size == 0)
		{
			newNode->next = newNode->prev = NULL;
			head = tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		
		//�߿�
		this->size++;
	}
	
	void insertReverse (int value)
	{
		Node *newNode = new Node();
		newNode->data = value;
		
		if(this->size == 0)
		{
			newNode->next = newNode->prev = NULL;
			head = tail = newNode;
		}
		else
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		
		this->size++;
	}
	
	
	void deleteByIndex (int index)
	{
		if( index == 0 || index > this->size || this->size == 0)
			return;
			
		Node *originalHeadPosition = head;
		Node *tempNode;
		
		for (int i = 0 ; i < index-1 ; i++)
		{
			head = head->next;
		}
		
		//size == 1�̸� �׳� ����.
		if ( this->size == 1)
		{
			tempNode = head;
			head = tail = NULL;
			
			delete(tempNode);
			this->size--;
		}
		else if (index == 1)
		{
			tempNode = head;
			head = head->next;
			head->prev = NULL;  //�����൵��. 
			delete(tempNode);
			this->size--;
		}
		else if (index == this->size)
		{
			tempNode = head;
			head = head->prev;
			head->next = NULL;
			tail = head;          //tail�� head��ġ�� ��ȯ.
			head = originalHeadPosition;
			delete(tempNode);
			this->size--;
		}
		else //�߰��� �����ִ°��.
		{
			tempNode = head;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			
			head = originalHeadPosition;
			delete(tempNode);
			this->size--;
		}
	}
	
	void print()
	{
		Node *originalHeadPosition = head;   //Node�� ��������ߵ�. 
		
		while (head != NULL)
		{
			cout<<head->data<<"->";
			if(head->next == NULL)
			{
				cout<<endl;
			}
			head = head->next;
		}
		
		head = originalHeadPosition;
	}
};




int main (void)
{
	DoubleList exer;    //DoubleList *exer �ƴ�  
	exer.insert(10);
	exer.insert(20);
	exer.insertReverse(30);
	
	exer.print(); 
	exer.deleteByIndex(2);
	exer.print();
	
	return 1;
}
