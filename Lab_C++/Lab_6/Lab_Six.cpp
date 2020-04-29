// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lab_Six.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
My_Tree * ROOT = new My_Tree();
int amount = 6;

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
		Form1->Memo1->Lines->Add("Нет такого студента");

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

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	Memo1->Clear();
	StringGrid1->Cells[0][0] = "№";
	StringGrid1->Cells[1][0] = "Ф.И.О.";
	StringGrid1->Cells[2][0] = "№ студбилета";
	for (int i = 1; i <= amount; i++) {
		StringGrid1->Cells[0][i] = i;
	}
	StringGrid1->Cells[1][1] = "Кулевич А.О.";
	StringGrid1->Cells[2][1] = "95350088";
	StringGrid1->Cells[1][2] = "Круглая А.А.";
	StringGrid1->Cells[2][2] = "95350084";
	StringGrid1->Cells[1][3] = "Трофимук Г.А.";
	StringGrid1->Cells[2][3] = "95350151";
	StringGrid1->Cells[1][4] = "Лавренович А.Е.";
	StringGrid1->Cells[2][4] = "95350091";
	StringGrid1->Cells[1][5] = "Воробьев А.С.";
	StringGrid1->Cells[2][5] = "95350027";
	StringGrid1->Cells[1][6] = "Кукареко А.П.";
	StringGrid1->Cells[2][6] = "95350087";
	TInf A;
	A.FIO = StringGrid1->Cells[1][1];
	A.key = StrToInt(StringGrid1->Cells[2][1]);
	ROOT->Create(&(ROOT->Root), A);

	for (int i = 2; i <= amount; i++) {
		A.FIO = StringGrid1->Cells[1][i];
		A.key = StrToInt(StringGrid1->Cells[2][i]);
		ROOT->Add(ROOT->Root, A);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	TreeView1->Items->Clear();
	ROOT->ViewTree(ROOT->Root, -1);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {

	if (!(Edit1->Text == "") && !(Edit2->Text == "")) {
		amount++;
		StringGrid1->Cells[1][amount] = Edit1->Text;
		StringGrid1->Cells[2][amount] = Edit2->Text;
		StringGrid1->Cells[0][amount] = amount;
		TInf A;
		A.FIO = Edit1->Text;
		A.key = StrToInt(Edit2->Text);
		ROOT->Add(ROOT->Root, A);
	}
	else {
		ShowMessage("Вы не ввели все данные");
	}
	Edit1->Text == "";
	Edit2->Text == "";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender) {
	ROOT->DeleteTree(&(ROOT->Root));
	TreeView1->Items->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	if (!(Edit3->Text == ""))
		ROOT->Find(ROOT->Root, StrToInt(Edit3->Text));
	Edit3->Text == "";
}

// ---------------------------------------------------------------------------
void My_Tree:: DeleteNode(TTree**Root, int Key) {
	TTree* Del = (*Root), *Prev_Del = NULL, *R, *Prev_R;
	while (Del != NULL && Del->Inform.key != Key) {
		Prev_Del = Del;
		if (Del->Inform.key > Key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)  {
     Form1->Memo1->Lines->Add("Нет такого студента");
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

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	Memo1->Clear();
	if (!(Edit3->Text == "")) {
		ROOT->DeleteNode(&(ROOT->Root), StrToInt(Edit3->Text));

		for (int i = 1; i <= amount; i++) {
			if (StringGrid1->Cells[2][i] == StrToInt(Edit3->Text)) {

				for (int j = i + 1; j <= amount; j++, i++) {

					StringGrid1->Cells[1][i] = StringGrid1->Cells[1][j];
					StringGrid1->Cells[2][i] = StringGrid1->Cells[2][j];
				}
				StringGrid1->Cells[0][amount] = "";
				StringGrid1->Cells[1][amount] = "";
				StringGrid1->Cells[2][amount] = "";
				amount--;
				break;
			}

		}
		Edit3->Text = "";
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	Memo1->Clear();
	ROOT->Show_1(&(ROOT->Root));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	Memo1->Clear();
	ROOT->Show_2(&(ROOT->Root));
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender) {
	Memo1->Clear();
	ROOT->Show_3(&(ROOT->Root));
}

// ---------------------------------------------------------------------------
void Count(TTree* TRoot, int *count) {
	if (TRoot == NULL)
		return;
	if (TRoot->Left != NULL && TRoot->Right != NULL) {
		(*count)++;
		Count(TRoot->Left, &(*count));
		Count(TRoot->Right, &(*count));
	}
	else if (TRoot->Left == NULL) {
		Count(TRoot->Right, &(*count));
	}
	else if (TRoot->Right == NULL) {
		Count(TRoot->Left, &(*count));
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender) {
	Memo1->Clear();
	int amount_of_daughters = 0;
	Count(ROOT->Root, &amount_of_daughters);
	Memo1->Lines->Add(+ "  Результат: " + IntToStr(amount_of_daughters));
}
// ---------------------------------------------------------------------------
