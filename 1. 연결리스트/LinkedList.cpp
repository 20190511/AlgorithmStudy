#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int m;
	Node *link;
	
	Node (int a = 0){
		m = a;
		link = NULL;
	}
	
	//�ٽ� �Լ�. 
	void insert(Node *newNode)
	{
		newNode->link = link;  //newNode�� link�� ���� �ּҷ� ����. 
		link = newNode;        //���ο� �ּҰ��� ����. 
	}
	
	void pop ()
	{
		if(link != NULL)
		{
			cout<<"remove value = "<<link->m<<endl;
			link = link->link; //��ũ�� �������� �̵�. 
		}
	}
	
	void display () 
	{
		Node *p = link;
		while (p != NULL)
		{
			cout<<p->m<< "->";
			p = p->link;
		}
		cout<<endl;
	}
	
	
	//���ϴ� �� ��ġ ��ȣ ã��. 
	int find (int value)
	{
		Node *remove = link;
		int index = 0;
		while (remove != NULL)
		{
			if(remove->m == value)
			{
				cout<<"Index Number of value (" <<value<<") is = "<<index<<endl;
				//remove = remove->link;
				break;
			}
			remove = remove->link;
			index++;
		}
		
		return index;
	}
};


int main ()
{
	Node head;
	head.insert(new Node(10));
	head.link->insert(new Node(9));  //insert format1 
	head.insert(new Node(5));        //insert format2
	head.insert(new Node(24));
	
		//���� HEAD�� 24�� ��ġ�ϰ� ������ 24->5->9->10�� ������ Ž���ϰԵȴ�. 
	
	//head.pop();
	head.display();
	head.find(10);
	return 0;
}

