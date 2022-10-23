#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
	public:
		int data;
		Node * next;
		Node * prev;
		Node(int item){
			data=item;
			next=NULL;
			prev=NULL;
		}
};

class DoubleLinkedList{
	public:
		Node* head=NULL;
		void insertBeg(int);
		void insertEnd(int);
		void display();
		void deleteBeg();
		void deleteEnd();
};

void DoubleLinkedList::insertBeg(int item){
	Node * curr=new Node(item);
	if(head==NULL)
		head=curr;
	else{
		curr->next=head;
		head->prev=curr;
		head=curr;
	}
}

void DoubleLinkedList::insertEnd(int item){
	Node * curr=new Node(item);
	if(head==NULL){
		head=curr;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=curr;
	curr->prev=temp;
	return;
}

void DoubleLinkedList::display(){
	if(head==NULL){
		cout<<"List is empty";
		return;
	}
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}


void DoubleLinkedList::deleteBeg(){
	if(head==NULL){
		cout<<"List is Empty";
		return;
	}
	Node* temp=head;
	head=head->next;
	if(head!=NULL)
		head->prev=NULL;
	delete temp;
}

void DoubleLinkedList::deleteEnd(){
	if(head==NULL){
		cout<<"Empty list";
		return;
	}
	if(head->next==NULL){
		delete head;
		head=NULL;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->prev->next=NULL;
	delete temp;
	return;
}

int main(void){
	DoubleLinkedList L;
	int ch,item;
	while(1){
		cout<<"Enter your choice"<<endl;
		cout<<"1.Insert at beginning"<<endl;
        cout<<"2.Insert at End"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Delete at Beginning"<<endl;
        cout<<"5.Delete at End"<<endl;
        cout<<"6.EXIT"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the data to be inserted"<<endl;
				cin>>item;
				L.insertBeg(item);
				break;
				
			case 2:
				cout<<"Enter the item to be inserted at the end"<<endl;
				cin>>item;
				L.insertEnd(item);
				break;
				
			case 3:
				L.display();
				break;
				
			case 4:
				L.deleteBeg();
				break;
				
			case 5:
				L.deleteEnd();
				break; 
			
			case 6:
				exit(0);
		
			default:
				cout<<"Invalid choice"<<endl;
			}
	}
			
					
	
}
