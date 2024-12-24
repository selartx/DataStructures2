#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "Bst.hpp"
#include <iostream>

using namespace std;

class LinkedList
{ 
	public:
	struct ListeDugum{
		BST Agac;
		ListeDugum *sonraki;
		ListeDugum();
		~ListeDugum();
	};
	ListeDugum *head;
	ListeDugum *current;
	LinkedList();
	~LinkedList();
	void Agacekle(BST);
	void AgacSil();
	void ileri();
	void geri();
	void tablociz(int secilenIndex);
	void SeciliAgacCiz(int secilenIndex);

};

#endif