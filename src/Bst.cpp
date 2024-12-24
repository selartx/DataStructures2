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
                if (c < current->veri) {
                    current = current->sol;
                } else {
                    current = current->sag;
                }
                counter_level++;
            }
            newNode->level = counter_level; 
            if (c < parent->veri) {
                parent->sol = newNode;
            } else {
                parent->sag = newNode;
            }
        }
    }
}
void BST::agaccizdir() {
    if (!kok) {
        cout << "Ağaç boş." << endl;
        return;
    }

    const int maxNodes = 100; 

    AgacDugum* nodeArray[maxNodes];
    int start = 0; 
    int end = 0;   

    
    nodeArray[end++] = kok;

    while (start < end) {
        int currentLevel = nodeArray[start]->level;
        bool isNewLevel = true;

        int levelEnd = end; 
        while (start < levelEnd) {
            AgacDugum* current = nodeArray[start++];
            if (isNewLevel) {
                cout << "Level " << currentLevel << ": ";
                isNewLevel = false;
            }
            cout << current->veri << " ";

            if (current->sol) {
                current->sol->level = current->level + 1;
                nodeArray[end++] = current->sol;
            }
            if (current->sag) {
                current->sag->level = current->level + 1;
                nodeArray[end++] = current->sag;
            }
        }

        cout << endl;
    }
}
