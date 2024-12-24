#ifndef BST_HPP
#define BST_HPP
#include <iostream>
using namespace std;

class BST
{ 	
	public:
	struct AgacDugum{
		char veri;
		int level;
		AgacDugum *sol;
		AgacDugum *sag;
		AgacDugum();
		~AgacDugum();
	};
	AgacDugum *kok;
	BST();
	~BST();
	void agacolustur(const string &veri);
	int agacdegeri(AgacDugum* dugum, bool isLeftChild) ;
	void agaccizdir();
	void agaciDoldur(AgacDugum* node, char ekran[][100], int satir, int sol, int sag, int maxDerinlik);
	int agacDerinligi(AgacDugum* dugum);
	void aynalama(AgacDugum* dugum);
	};
	
#endif