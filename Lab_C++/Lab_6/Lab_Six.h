// ---------------------------------------------------------------------------

#ifndef Lab_SixH
#define Lab_SixH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <string.h>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TStringGrid *StringGrid1;
	TTreeView *TreeView1;
	TMemo *Memo1;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TEdit *Edit3;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button9;
	TLabel *Label7;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

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
#endif
