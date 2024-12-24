#include "Bst.hpp"
#include "Linkedlist.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    LinkedList linkedList;
    char choice;
    int secilenIndex = 0;
    const int toplamDugum = 10;

    ifstream file("agaclar.txt"); // Dosyayı açıyoruz
    if (!file.is_open()) {
        cerr << "Dosya açılamadı!" << endl;
        return 1;
    }

    // Dosyadan ağaçları okuyup listeye ekleme
    string line;
    cout << "Dosyadan ağaçlar okunuyor..." << endl;
    while (getline(file, line)) {
        if (!line.empty()) {
            BST yeniAgac;
            yeniAgac.agacolustur(line); // Yeni bir ağaç oluştur
            linkedList.Agacekle(yeniAgac); // Ağaçları bağlı listeye ekle
        }
    }

    file.close();

    bool devamEt = true;
    while (devamEt) {
        system("cls"); // Ekranı temizle (Windows). Linux/Unix için "clear" kullanılabilir.
        linkedList.tablociz(secilenIndex); // Tabloyu çiz
        linkedList.SeciliAgacCiz(secilenIndex); // Seçili düğümdeki ağacı çiz

        cout << "\nSeçenekler:\n";
        cout << "'a': Geri git\n";
        cout << "'d': İleri git\n";
        cout << "'q': Çıkış yap\n";
        cout << "Seçiminizi yapın: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                if (secilenIndex > 0) {
                    secilenIndex--;
                }
                break;

            case 'd':
                if (secilenIndex < toplamDugum - 1) {
                    secilenIndex++;
                }
                break;

            case 'q':
                devamEt = false;
                break;

            default:
                cout << "Geçersiz seçenek!" << endl;
                break;
        }
    }

    return 0;
}

