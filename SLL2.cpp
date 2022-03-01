#include<iostream>

using namespace std;

struct Topi{
	string merek, jenis;
	int ukuran;
	
	Topi *next;
	
};

Topi *head, *tail, *cur, *newNode;


void createSingleLinkedList(string merek, string jenis, int uK){
	head = new Topi();
	head->merek = merek;
	head->jenis = jenis;
	head->ukuran = uK;
	head->next = NULL;
	tail = head;
	
}

void addLast(string merek, string jenis, int uK){
	newNode = new Topi();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->ukuran = uK;
	newNode->next = NULL;
	tail->next = newNode;
	tail=newNode;
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout << "Merek Topi : "<< cur->merek <<endl;
		cout << "Jenis Topi : "<< cur->jenis <<endl;
		cout << "Ukuran Topi : "<< cur->ukuran <<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("Cheva Hat", "Fedora", 54);
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addLast("Consina", "Komando", 54);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	
	
}
