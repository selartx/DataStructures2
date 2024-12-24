#include "Bst.hpp"
#include <iostream>
#include <fstream>
using namespace std;

BST::AgacDugum::AgacDugum(){
	sol=NULL;
	sag=NULL;
    level=0;
}
BST::AgacDugum::~AgacDugum(){
	sol=NULL;
	sag=NULL;
    level=0;
}
BST::BST()
{ 	
	kok = NULL;
}
BST::~BST()
{ 	
	kok = NULL;
}

void BST::agacolustur(const string &veri) {
    for (char c : veri) {
        AgacDugum *newNode = new AgacDugum();
        newNode->veri = c;

        if (kok == nullptr) {
            kok = newNode;
            newNode->level = 0; 
        } else {
            AgacDugum *current = kok;
            AgacDugum *parent = nullptr;
            int counter_level = 0; 
            while (current != nullptr) {
                parent = current;
                if (c < current->veri) {  // ASCII değerine göre karşılaştırma
                    current = current->sol;
                } else {
                    current = current->sag;
                }
                counter_level++;
            }
            newNode->level = counter_level; 
            if (c < parent->veri) {  // ASCII değerine göre karşılaştırma
                parent->sol = newNode;
            } else {
                parent->sag = newNode;
            }
        }
    }
}

void BST::agaccizdir() {
    if (!kok) {
        cout << "Ağacı boş." << endl;
        return;
    }

    // Ağacın derinliğini bul
    int derinlik = agacDerinligi(kok);

    // Çizim için kullanılacak sabit boyutlu bir dizi
    const int genislik = 100; // Daha geniş bir değer Windows PowerShell tam ekranına uygun
    const int yukseklik = 40; // Derinlik seviyesini artır
    char ekran[yukseklik][genislik];

    // Diziyi boşluk karakterleri ile doldur
    for (int i = 0; i < yukseklik; i++) {
        for (int j = 0; j < genislik; j++) {
            ekran[i][j] = ' ';
        }
    }

    // Ağaç düğümlerini dizinin uygun pozisyonlarına yerleştir
    agaciDoldur(kok, ekran, 0, 0, genislik - 1, derinlik);

    // Diziyi ekrana yazdır
    for (int i = 0; i <= derinlik * 2; i++) {
        for (int j = 0; j < genislik; j++) {
            cout << ekran[i][j];
        }
        cout << endl;
    }
}

void BST::agaciDoldur(AgacDugum* node, char ekran[][100], int satir, int sol, int sag, int maxDerinlik) {
    if (!node || satir / 2 > maxDerinlik) return;

    int orta = (sol + sag) / 2;
    ekran[satir][orta] = node->veri; // Düğüm verisini yerleştir

    // Bağlantı çizgilerini ekle
    if (node->sol) {
        int solOrta = (sol + orta) / 2;
        for (int i = orta - 1; i > solOrta; i--) {
            ekran[satir + 1][i] = '.';
        }
        agaciDoldur(node->sol, ekran, satir + 2, sol, orta - 1, maxDerinlik);
    }
    if (node->sag) {
        int sagOrta = (orta + sag) / 2;
        for (int i = orta + 1; i < sagOrta; i++) {
            ekran[satir + 1][i] = '.';
        }
        agaciDoldur(node->sag, ekran, satir + 2, orta + 1, sag, maxDerinlik);
    }
}
int BST::agacdegeri(AgacDugum* dugum, bool isLeftChild = false) {
    if (!dugum) return 0;

    // Calculate values recursively for left and right subtrees
    int solDeger = agacdegeri(dugum->sol, true);  // Left child
    int sagDeger = agacdegeri(dugum->sag, false); // Right child

    // Add the current node's value based on whether it's a left or right child
    int currentValue = isLeftChild ? (dugum->veri * 2) : dugum->veri;

    // Return the total sum including left, right, and current node values
    return solDeger + sagDeger + currentValue;
}







int BST::agacDerinligi(AgacDugum* dugum) {
    if (dugum == nullptr) {
        return 0; // Boş ağaç için derinlik 0
    }
    // Sol ve sağ alt ağacın derinliklerini hesapla
    int solDerinlik = agacDerinligi(dugum->sol);
    int sagDerinlik = agacDerinligi(dugum->sag);
    // Daha derin olanı seç ve 1 ekle (mevcut düğüm için)
    return max(solDerinlik, sagDerinlik) + 1;
}
