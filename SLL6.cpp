#include<iostream>

using namespace std;

struct Topi{
	string merek, jenis;
	int ukuran;
	
	Topi *next;
	
};

Topi *head, *tail, *cur, *newNode,*del, *after;


void createSingleLinkedList(string merek, string jenis, int uK){
	head = new Topi();
	head->merek = merek;
	head->jenis = jenis;
	head->ukuran = uK;
	head->next = NULL;
	tail = head;
	
}

int countSingleLinkedList(){
	cur = head;
	int NO = 0;
	while(cur != NULL){
		NO++;
		cur = cur->next;
	}
	return NO;
}

void addFirst(string merek, string jenis, int uK){
	newNode = new Topi();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->ukuran = uK;
	newNode->next = head;
	head = newNode;
}

void addMiddle(string merek, string jenis, int uK, int posisi){
	newNode = new Topi();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->ukuran = uK;
	
	cur = head;
	int NO = 1;
	while(NO < posisi - 1 ){
		cur = cur->next;
		NO++;
	}
	
	newNode->next = cur->next;
	cur->next = newNode;
}

void removeMiddle(int posisi){
	if ( posisi < 1 || posisi > countSingleLinkedList() ){
		cout << "Posisi Diluar jangkauan " << endl;
	}else if( posisi == 1 || posisi == countSingleLinkedList() ){
		cout << "Posisi bukan posisi tengah " << endl;
	} else {
	int NO = 1;
	cur = head;
	while (NO <= posisi){
		if (NO == posisi -1){
			after = cur;
		}
		if (NO == posisi){
			del = cur;
		}
		cur = cur->next;
		NO++;
	}
	after->next = cur;
	delete del;
	}
}

void printSingleLinkedList(){
	cout << "Nomor data ada : " << countSingleLinkedList() << endl;
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
	
	addFirst("Consina", "Komando", 54);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("Hurley", "Trucker", 54, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("Champion", "Sport", 54, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeMiddle(2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
