#include "Linkedlist.hpp"
#include "Bst.hpp"
#include <iostream>
using namespace std;

LinkedList::ListeDugum::ListeDugum(){
    sonraki = nullptr;
}
LinkedList::ListeDugum::~ListeDugum() {
    sonraki = nullptr;
}
LinkedList::LinkedList(){
	head = NULL;
}

void LinkedList::Agacekle(BST agac) 
{ 	ListeDugum *yeni = new ListeDugum;
	yeni->Agac = agac;
	yeni->sonraki = NULL;
	 if (!head) {
        head = yeni;
        current = head;
    } else {
        ListeDugum* temp = head;
        while (temp->sonraki) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeni;
    }
}


LinkedList::~LinkedList()
{ 	ListeDugum *temp = head;
	while (temp != NULL)
	{ 	ListeDugum *temp2 = temp->sonraki;
		delete temp;
		temp = temp2;
	}
}

void LinkedList::AgacSil() {
    if (!current) {
        cout << " düğüm yok" << endl;
        return;
    }

    ListeDugum* silinecek = current;

    if (silinecek == head) {
        head = head->sonraki; 
        current = head;       
    } else {
        ListeDugum* temp = head; 
        while (temp && temp->sonraki != silinecek) {
            temp = temp->sonraki; 
        }
        if (temp && temp->sonraki == silinecek) {
            temp->sonraki = silinecek->sonraki;
        }
		if (silinecek->sonraki) {
    	current = silinecek->sonraki; 
		} else {
    	current = temp;
		
		}

    }
    delete silinecek;
}

void LinkedList::ileri() {
    if (current && current->sonraki) {
        current = current->sonraki; 
    } else {
        
    }
}
void LinkedList::tablociz(){
    cout << "Adres       | Toplam Değer | Sonraki Düğüm Adresi" << endl;
    cout << "----------------------------------------------" << endl;
    BST Agac;
    while (head != nullptr) {
        int treeValue = Agac.agacdegeri(head->Agac.kok,false); 
        cout << head << " | " << treeValue << " | ";
        
        if (head->sonraki != nullptr) {
            cout << head->sonraki;
        } else {
            cout << "NULL";
        }
        
        cout << endl;
        head = head->sonraki;  
    }
}