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
	int agacdegeri();
	void agaccizdir();


};
#endif