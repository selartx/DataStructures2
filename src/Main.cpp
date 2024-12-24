//buraya ui ekliyeyim bir de yapılacak işlemler falan çağırılsın
#include "Bst.hpp"
#include "Linkedlist.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	LinkedList linkedList; 
    BST agac;
	ifstream file("agaclar.txt"); // Dosyayı açıyoruz
    if (!file.is_open()) {
        cerr << "Dosya açılamadı!" << endl;
        return 1;
    }
	agac.agacolustur("PIBmug4wScx"); // Ağacı oluştur
	agac.agaccizdir(); // Ağacı ekrana yazdır
    cout << "Toplam değer: " << agac.agacdegeri(agac.kok,false) << endl;



    return 0;
}
