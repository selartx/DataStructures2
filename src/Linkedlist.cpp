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
void LinkedList::tablociz(int baslangicIndex, int maxGosterim, int secilenIndex) {
    ListeDugum* temp = head;
    const int alanGenisligi = 15; // Hücre genişliği
    int toplamDugumSayisi = DugumSayisi();

    // Başlangıç indeksi geçersizse düzelt
    if (baslangicIndex < 0) baslangicIndex = 0;
    if (baslangicIndex >= toplamDugumSayisi) baslangicIndex = toplamDugumSayisi - maxGosterim;

    // Bitiş düğüm indeksini belirle
    int bitisIndex = min(baslangicIndex + maxGosterim, toplamDugumSayisi);

    // Göstermek için başlangıç düğümüne ilerle
    for (int i = 0; i < baslangicIndex && temp != nullptr; i++) {
        temp = temp->sonraki;
    }

    // 1. Satır: Düğüm adreslerini yazdır
    for (int i = baslangicIndex; i < bitisIndex && temp != nullptr; i++) {
        cout << setw(alanGenisligi) << temp;
        temp = temp->sonraki;
    }
    cout << endl;

    // 2. Satır: Düğümlerdeki veri değerlerini yazdır
    temp = head;
    for (int i = 0; i < baslangicIndex && temp != nullptr; i++) {
        temp = temp->sonraki;
    }
    for (int i = baslangicIndex; i < bitisIndex && temp != nullptr; i++) {
        cout << setw(alanGenisligi) << temp->Agac.agacdegeri(temp->Agac.kok, false);
        temp = temp->sonraki;
    }
    cout << endl;

    // 3. Satır: Sonraki düğüm adreslerini yazdır
    temp = head;
    for (int i = 0; i < baslangicIndex && temp != nullptr; i++) {
        temp = temp->sonraki;
    }
    for (int i = baslangicIndex; i < bitisIndex && temp != nullptr; i++) {
        if (temp->sonraki) {
            cout << setw(alanGenisligi) << temp->sonraki;
        } else {
            cout << setw(alanGenisligi) << "NULL";
        }
        temp = temp->sonraki;
    }
    cout << endl;

    // 4. Satır: Seçim göstergesi
    for (int i = baslangicIndex; i < bitisIndex; i++) {
        if (i == secilenIndex) {
            cout << setw(alanGenisligi) << "^"; // Seçim göstergesi
        } else {
            cout << setw(alanGenisligi) << " ";
        }
    }
    cout << endl;
}

void LinkedList::SeciliAgaciAynaYap(int secilenIndex) {
    ListeDugum* temp = head;
    int count = 0;

    while (temp != nullptr && count < secilenIndex) {
        temp = temp->sonraki;
        count++;
    }

    if (temp != nullptr) {
        temp->Agac.aynalama(temp->Agac.kok);
        cout << "Seçili düğümün ağacı aynalandı." << endl;
    } else {
        cout << "Seçili düğüm bulunamadı." << endl;
    }
}
int LinkedList::DugumSayisi() {
    int count = 0;
    ListeDugum* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->sonraki;
    }
    return count;
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