#include <iostream>
#include <string>
using namespace std;

/*
	���� ���Ḯ��Ʈ.
		���� : O(1)
		���ϴ� ��ġ Ž��,����,���� : O(n)
		Ž�� : O(n)
	
	���� ���Ḯ��Ʈ�� Head(���� ����Ű�� ��ġ)���� �ܹ������θ� �̵��� �� �����Ƿ�
		���ϴ� ���� Ž���� �� ������ �� ���� �����ϰų� �����ϴ� ���� ���� ����.
		
		
	���� ���Ḯ��Ʈ ���� (head, tail��ġ���� ����� link�� �̵��ϴ� �ڷᱸ��) 
		a) tail�� head�� ���� �ȴ�.
			(tail�� prev�� ����Ͽ� Ž���� �� �ִ�.)
			(head�� next�� ����Ͽ� Ž���� �� �մ�.)
		
		b) �Ϲ������� head�� ���Ӱ� �����Ǵ� newNode��
			NULL <- (prev)newNode(next) <=> (prev)head(next) -> NULL 
*/


/*Node Ŭ����: �ڱ��ڽ�(Node)�� Data���� �� ��带 �������� ����,����  ����� �ּڰ� ����*/
class Node {
public:
	int data;
	Node *prev , *next;
	
	Node()
	{
		this->data = 0;
		this->prev = this->next = NULL; //�ʱ�ȭ
	}
};



class DoubleLinkedList {
private:
	int size;               //���� ��� ��带 ������ �ִ��� ���� ����. 
	Node *head , *tail;     //head�� tail ��� ����.
	
public:
	DoubleLinkedList()
	{
		this->size = 0;
		this->head = this->tail = NULL;  //���� �ڱ� �ڽ��� Head���� Tail���� NULL������ �������. 
	}
	
	//head�� �� �߰�. 
	void addNodeToHead(int value) 
	{
		
		Node *newNode = new Node();
		newNode->data = value;
		
		//��� �ִ� ��쿡�� Head�� tail��� newNode�� ����Ŵ. 
		if(isEmpty())
		{
			head = tail = newNode;
		}
		else // [����] NULL<-(p)[newNode](n) <=> (p)[head](n)->NULL 
		{
			newNode->next = head;    // newNode�� ���� �ּڰ� = head 
			head->prev = newNode;    // head�� ���� �ּڰ� = newNode. 
			head = newNode;          //head�� �缳��. (����Ű�� ��ġ) 
		}
		
		this->size++;   //������ size�� ����. 
	}
	
	//tail�� ���ο� �� �߰�. 
	void addNodeToTail (int value)
	{
		Node *newNode = new Node();
		newNode->data = value;
		
		if(this->size == 0) //size == 0�̶� �ƹ��� ��尡 ������ �ǹ���.
		{
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
	
	//���ϴ� ��ġ�� ����� �����͸� ���ϴ� ������ ����.
	void changeNodeByLocation (int changePosition, int changeValue)
	{
		if(isEmpty() || changePosition > this->size || changePosition < 1)
		{
			return;
		}
			
			//Head, tail ��ġ�� �߿��� (����Ʈ����������) 
		Node *originHeadNodePosition = head;  //���� head��ġ�� ����ϴ� ����. 
		
		for(int i = 0 ; i < changePosition - 1 ; i++)
		{
			head = head->next; //head�� ���������� ��� �̵�. 
		}
		
		// �̵��� head�� ����Ű�� �ڷᱸ���� ���� ���� 
		head->data = changeValue;
		head = originHeadNodePosition; //����ص� head������ �ٽ� ����. 
	}
	
	
	//������ ��ġ�� ��带 �����ϴ� ���.
	void deleteNodeByLocation (int deletePosition)
	{
		if(isEmpty() || deletePosition < this->size || deletePosition < 1)
		{
			return;
		}
		
		Node *tempDeleteNodePosition;    //���� ����� ��ġ�� �ӽ÷� ������ ���. (Node ��ȯ�� ����) 
		Node *originHeadPosition = head; //Head��ġ ����ϴ� ����.
		
		
		// ��ġ��ŭ ��带 �̵���Ű��. 
		for (int i = 0 ; i < deletePosition - 1 ; i++)
		{
			head = head->next; 
		}
		
		
		//����� ���̽� (���� ó�� ��ġ�� ��� )
		if (deletePosition == 1)
		{
			//��尡 2�� �̻��� ��� 
			if(this->size > 1)
			{ 
				tempDeleteNodePosition = head; //�ӽ÷� ���� ��带 head�� ����Ű�� 
				head = head->next;             //head�� ��ġ�� ���� head�� �Ű��ݴϴ�.
				//head->prev = NULL;           //�����൵��. 
				delete(tempDeleteNodePosition); //(�߿�) �ʿ���������� ����. 
			}
			else
			{
				tempDeleteNodePosition = head;
				head = tail = NULL; //(��尡 �ϳ��ۿ� ������ �̰��� ���������Ƿ� ���NULL�� �������) 
				delete tempDeleteNodePosition;
			}
			
			this->size--;
		}
		//����� ���̽�2  (�������� �ִ� ���) 
		else if (deletePosition == this->size) 
		{
			tempDeleteNodePosition = head; //�ӽ� ��ҿ� head�� ��. 
			head = head->prev;             //head�� ���� �ּҷ� head�� �̵�������. 
			//head->next = NULL            //�����൵ �� 
			tail = head;                   //�� ��ġ�� tail�� ��.
			
			
			delete(tempDeleteNodePosition);
			
			head = originHeadPosition; //head�� ������ġ��
			this->size--; 
		 } 
		 //����� ���̽�3 (�߰��� �׳� �����ִ� ���) 
		 else
		 {
		 	head->prev->next = head->next;    //head�� prev�� �̵���Ų ��ġ�� next = head�� prev�� 
		 	head->next->prev = head->prev;    //head�� next�� �̵���Ų ��ġ�� prev = head�� next�� 
		 	
		 	tempDeleteNodePosition = head;    //�ӽ÷� ���� Node
			delete tempDeleteNodePosition;
			
			head = originHeadPosition;     //head�� ���� ��ġ�� �̵���Ű��. 
			this->size--; 
		 	
		 }
	}
	
	
//	//���� �����ϴ��� Ȯ�����ִ� �Լ� (head�� ������ġ�� �̵���Ű�� ���) 
	bool isSearchNodeByValue (int searchValue)
	{
		if(isEmpty())
		{
			return false;
		}
		
		Node *originHeadNodePosition = head;
		
		for(int i = 0 ; i < this->size ; i++)
		{
			if(head->data == searchValue) //�����ϴ� ���. 
			{
				head = originHeadNodePosition; //Head�� ������ġ�� �̵�. 
				return true;
			}
			head = head->next; //head�� ��� �̵� 
		} 
		return false;    //for���� �� ������������� == ����. 
	}
	
	
	//�ش� ��ġ�� ���� return
	int searchNodeByLocation (int searchLocation)
	{
		if (isEmpty() || searchLocation > this->size || searchLocation < 1)
		{
			return false;
		}
		
		Node *originHeadNodePosition = head;
		
		for (int i = 0 ; i < searchLocation - 1 ; i++)
		{
			head = head->next; //�ش� location���� head �̵�. 
		} 
		
		int tempResultData = head->data;  //�ش� searchLocation�� ������ �� 
		head = originHeadNodePosition;    //��� ����ġ ������ 
		 
		return tempResultData;
	}
	
	
	//head ���� ������ ���
	void print()
	{
		if (isEmpty())
			return;
			
		Node *originHeadNodePosition = head;
		
		for(int i = 0 ; i < size + 1 ; i++)
		{
			cout<<head->data<<"->";
			if(!head->next) break;  // Ž���� ������ "->" �� ������ �ϱ�����.
			head = head->next;      //��� next �������� ��� �̵�.
		}
		
		head = originHeadNodePosition; //��� ����ġ�� �̵�
		cout<<endl;
	 } 
	 
	 
	 //tail���� �ݴ�������� print
	 void printReverse()
	 {
	 	if (isEmpty())
	 		return;
	 		
	 	Node *originTailNodePosition = tail;
	 	
	 	for(int i = size ; i >= 0 ; i--)
	 	{
	 		cout<<tail->data<<"->";
	 		if(!tail->prev) break; //tail�� Ž���� ��ģ ��� 
	 		tail = tail->prev;     //tail�� prev���� �缳�� 
		 }
		 
		tail = originTailNodePosition;
		cout<<endl;
	 }
	 
	 
	 //isEmpty �Լ� (����ִ��� Ȯ��)
	 bool isEmpty()
	 {
	 	if (this->size == 0)
	 		return true;
	 		
	 	return false;
	 } 
	 
	 
	 
	 //����Ʈ ��� ���� 
	 void clearList ()
	 {
	 	Node *deleteNode;
	 	for(int i = 0 ; i < this->size-1 ; i++)
	 	{
	 		deleteNode = head;
	 		if (head->next == NULL) break;
	 		
	 		head = head->next;    // ��� next�������� �̵�. 
	 		delete deleteNode;    // ��� ���� ���� 
		}
		
		this->size = 0;
		head = tail = NULL; 
	 }
};






int main()
{
    // test
    DoubleLinkedList testList;
 
    testList.addNodeToHead(10);
    testList.addNodeToTail(20);
    testList.addNodeToHead(30);
 
    testList.print();
    testList.printReverse();
 
    testList.changeNodeByLocation(2,200);
    testList.deleteNodeByLocation(1);
 
    testList.print();
    cout << testList.isEmpty() << endl;
 
    cout << testList.searchNodeByLocation(2) << endl;
    cout << testList.isSearchNodeByValue(200) << endl;
    cout << testList.isSearchNodeByValue(201) << endl;
 
    testList.clearList();
 
    testList.print();
    cout << testList.isEmpty() << endl;
 
    testList.addNodeToHead(1);
    testList.addNodeToTail(2);
    testList.addNodeToHead(3);
 
    testList.print();
}

