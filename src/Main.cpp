#include "Linkedlist.hpp"
#include "Bst.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    LinkedList linkedList;
    char choice;
    int secilenIndex = 0; // Kullanıcının seçtiği düğümün indeksi
    const int maxGosterim = 10; // Bir sayfada gösterilecek maksimum düğüm sayısı
    int baslangicIndex = 0; // Mevcut sayfanın başlangıç indeksi

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
            yeniAgac.agacolustur(line);    // Yeni bir ağaç oluştur
            linkedList.Agacekle(yeniAgac); // Ağaçları bağlı listeye ekle
        }
    }

    file.close();

    bool devamEt = true;
    while (devamEt) {
        system("cls"); // Ekranı temizle (Windows). Linux/Unix için "clear" kullanılabilir.
        linkedList.tablociz(baslangicIndex, maxGosterim, secilenIndex); // Mevcut sayfanın tablosunu çiz
        linkedList.SeciliAgacCiz(secilenIndex); // Seçili düğümdeki ağacı çiz

        cout << "\nSeçenekler:\n";
        cout << "'a': Geri git\n";
        cout << "'d': İleri git\n";
        cout << "'q': Çıkış yap\n";
        cout << "'w': Ayna işlemi yap\n";
        cout << "Seçiminizi yapın: ";
        cin >> choice;

        switch (choice) {
            case 'a': // Geri git
                if (secilenIndex > 0) {
                    secilenIndex--; // Bir önceki düğüme geç
                    if (secilenIndex < baslangicIndex) {
                        baslangicIndex -= maxGosterim; // Bir önceki sayfaya geç
                        if (baslangicIndex < 0) baslangicIndex = 0; // Negatif olmamalı
                    }
                }
                break;

            case 'd': // İleri git
                if (secilenIndex + 1 < linkedList.DugumSayisi()) {
                    secilenIndex++; // Bir sonraki düğüme geç
                    if (secilenIndex >= baslangicIndex + maxGosterim) {
                        baslangicIndex += maxGosterim; // Bir sonraki sayfaya geç
                        if (baslangicIndex >= linkedList.DugumSayisi()) {
                            baslangicIndex = linkedList.DugumSayisi() - maxGosterim; // Son sayfayı aşma
                        }
                    }
                }
                break;

            case 'q': // Çıkış yap
                devamEt = false;
                break;

            case 'w': // Ayna işlemi yap
                linkedList.SeciliAgaciAynaYap(secilenIndex);
                break;

            default:
                cout << "Geçersiz seçim!" << endl;
                break;
        }
    }

    return 0;
}
