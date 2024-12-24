#include "Linkedlist.hpp"
#include "Bst.hpp"
#include <iostream>
#include <iomanip>
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
void LinkedList::tablociz(int secilenIndex) {
    ListeDugum *temp = head;
    int count = 0;

    // Genişlik ayarı (10 değer yan yana sığdırmak için)
    const int alanGenisligi = 12;
    const int boslukGenisligi = 1; // Düğümler arası boşluk
    const int toplamDugum = 10;

    // 1. Satır: Düğüm adreslerini yazdır
    temp = head;
    count = 0;
    while (temp != nullptr && count < toplamDugum) {
        cout << ". " << setw(alanGenisligi - 2) << temp << " .";
        cout << string(boslukGenisligi, ' '); // Fazladan boşluk ekle
        temp = temp->sonraki;
        count++;
    }
    cout << endl;

    // 2. Satır: Düğümlerdeki ağaç verilerini yazdır
    temp = head;
    count = 0;
    while (temp != nullptr && count < toplamDugum) {
        int agacDegeri = temp->Agac.agacdegeri(temp->Agac.kok, false);
        cout << ". " << setw(alanGenisligi - 2) << agacDegeri << " .";
        cout << string(boslukGenisligi, ' '); // Fazladan boşluk ekle
        temp = temp->sonraki;
        count++;
    }
    cout << endl;

    // 3. Satır: Sonraki düğüm adreslerini yazdır
    temp = head;
    count = 0;
    while (temp != nullptr && count < toplamDugum) {
        if (temp->sonraki != nullptr) {
            cout << ". " << setw(alanGenisligi - 2) << temp->sonraki << " .";
        } else {
            cout << ". " << setw(alanGenisligi - 2) << "NULL" << " .";
        }
        cout << string(boslukGenisligi, ' '); // Fazladan boşluk ekle
        temp = temp->sonraki;
        count++;
    }
    cout << endl;

    // 4. Satır: Seçim göstergesi
    temp = head;
    count = 0;
    while (count < toplamDugum) {
        if (count == secilenIndex) {
            cout << string(alanGenisligi - 2, '^') << " "; // Seçim göstergesi
        } else {
            cout << string(alanGenisligi - 2, ' ');
        }
        cout << string(boslukGenisligi, ' '); // Fazladan boşluk ekle
        count++;
    }
    cout << endl;
}
void LinkedList::SeciliAgacCiz(int secilenIndex) {
    ListeDugum* temp = head;
    int count = 0;

    // Seçilen index'e kadar ilerle
    while (temp != nullptr && count < secilenIndex) {
        temp = temp->sonraki;
        count++;
    }

    // Geçerli düğüm varsa ağacı çiz
    if (temp != nullptr) {
        temp->Agac.agaccizdir(); // Mevcut agaccizdir fonksiyonunu çağır
    } else {
        cout << "Seçili düğüm bulunamadı." << endl;
    }
}


