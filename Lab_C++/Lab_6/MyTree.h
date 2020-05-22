//---------------------------------------------------------------------------

#ifndef MyTreeH
#define MyTreeH
#include <System.Classes.hpp>
// ---------------------------------------------------------------------------
struct TInf {
	int key;
	String FIO;
};

struct TTree {
	TInf Inform;
	TTree* Left;
	TTree* Right;
};

class My_Tree {

public:
	TTree* Root;

	My_Tree() : Root(NULL) {
	}

	void Create(TTree**P, TInf Inf) {
		(*P) = new TTree;
		(*P)->Inform = Inf;
		(*P)->Left = NULL;
		(*P)->Right = NULL;
	}

	void Add(TTree* Troot, TInf Inf) {

		TTree* temp = Troot, *temp_root;
		bool branch;
		while (temp != NULL) {
			temp_root = temp;
			branch = (Inf.key < temp->Inform.key);
			if (branch)
				temp = temp->Left;
			else
				temp = temp->Right;
		}
		Create(&temp, Inf);
		if (branch)
			temp_root->Left = temp;
		else
			temp_root->Right = temp;
	};
	void ViewTree(TTree*, int);
	void Find(TTree* Root, int Key);

	void DeleteTree(TTree** tree) {
		if (*tree == NULL)
			return;
		DeleteTree(&(*tree)->Left);
		DeleteTree(&(*tree)->Right);
		delete(*tree);
		(*tree) = NULL;
	}

	void DeleteNode(TTree**Root, int Key);

	void Show_1(TTree**);
	void Show_2(TTree**);
	void Show_3(TTree**);

};
//---------------------------------------------------------------------------
#endif
