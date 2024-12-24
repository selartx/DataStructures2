//buraya ui ekliyeyim bir de yapılacak işlemler falan çağırılsın
#include "Bst.hpp"
#include <iostream>
using namespace std;

int main() {
    // BST sınıfından bir ağaç oluştur
    BST agac;

    // Ağaç oluşturma: Örnek veriyle ağacı inşa ediyoruz
    string veri = "PmIugSwc4xB"; // Karışık karakterler (string ve int değeri gibi)
    agac.agacolustur(veri);

    // Ağaç çizdirme: Seviyelere göre ağaç çıktısını alıyoruz
    cout << "Oluşturulan Ağacın Seviyelere Göre Çizimi:" << endl;
    agac.agaccizdir();

    // Eğer daha fazla test yapmak isterseniz, farklı veri setleriyle çalışabilirsiniz
    cout << "\nBaşka bir veri setiyle ağacı yeniden oluşturup çizdiriyoruz:" << endl;
    BST yeniAgac;
    string yeniVeri = "AHz57kLd"; // Farklı bir veri seti
    yeniAgac.agacolustur(yeniVeri);
    yeniAgac.agaccizdir();

    return 0;
}
