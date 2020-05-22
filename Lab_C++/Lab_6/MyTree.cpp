//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyTree.h"
#include "Lab_Six.h"
//---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
void My_Tree::ViewTree(TTree* tree, int kl) {
	if (tree == NULL)
		return;
	if (kl == -1)
		Form1->TreeView1->Items->AddFirst(NULL,
		tree->Inform.FIO + "=" + IntToStr(tree->Inform.key));
	else
		Form1->TreeView1->Items->AddChildFirst
			(Form1->TreeView1->Items->Item[kl],
		tree->Inform.FIO + "=" + IntToStr(tree->Inform.key));
	kl++;
	ViewTree(tree->Left, kl);
	ViewTree(tree->Right, kl);
	kl--;

}

// ---------------------------------------------------------------------------
void My_Tree::Show_1(TTree** tree) {
	if (*tree == NULL)
		return;
	Form1->Memo1->Lines->Add((*tree)->Inform.FIO + " " + (*tree)->Inform.key);
	Show_1((&(*tree)->Left));
	Show_1((&(*tree)->Right));
}

// ---------------------------------------------------------------------------
void My_Tree::Show_2(TTree** tree) {
	if (*tree == NULL)
		return;
	Show_2((&(*tree)->Left));
	Show_2((&(*tree)->Right));
	Form1->Memo1->Lines->Add((*tree)->Inform.FIO + " " + (*tree)->Inform.key);
}

// ---------------------------------------------------------------------------
void My_Tree::Show_3(TTree** tree) {
	if (*tree == NULL)
		return;
	Show_3((&(*tree)->Left));
	Form1->Memo1->Lines->Add((*tree)->Inform.FIO + " " + (*tree)->Inform.key);
	Show_3((&(*tree)->Right));

}

// ---------------------------------------------------------------------------
void My_Tree::Find(TTree* Root, int Key) {
	String Name;
	String KEY;
	Form1->Memo1->Clear();
	bool being = 0;
	if (Root == NULL) {
		Form1->Memo1->Lines->Add("There isn't such student");

		return;
	}
	else if (Root->Inform.key == Key) {
		Name = Root->Inform.FIO;
		KEY = IntToStr(Root->Inform.key);
	}
	else if (Root->Inform.key > Key) {
		Find(Root->Left, Key);
		return;
	}
	else {
		Find(Root->Right, Key);
		return;
	}
	Form1->Memo1->Clear();
	Form1->Memo1->Lines->Add(Name + " " + KEY);
}

void My_Tree::DeleteNode(TTree**Root, int Key) {
	TTree* Del = (*Root), *Prev_Del = NULL, *R, *Prev_R;
	while (Del != NULL && Del->Inform.key != Key) {
		Prev_Del = Del;
		if (Del->Inform.key > Key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) {
		Form1->Memo1->Lines->Add("There isn't such student");
		return;
	}

	if (Del->Right == NULL)
		R = Del->Left;
	else if (Del->Left == NULL)
		R = Del->Right;
	else {
		Prev_R = Del;
		R = Del->Left;
		while (R->Right != NULL) {
			Prev_R = R;
			R = R->Right;
		}
		if (Prev_R == Del)
			R->Right = Del->Right;
		else {
			R->Right = Del->Right;
			Prev_R->Right = R->Left;
			R->Left = Prev_R;
		}
	}
	if (Prev_Del == NULL) {
		(*Root) = Prev_Del = R;
	}
	else if (Del->Inform.key < Prev_Del->Inform.key)
		Prev_Del->Left = R;
	else
		Prev_Del->Right = R;
	delete Del;
};