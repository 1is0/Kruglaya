// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Lab_Six.h"
#include "MyTree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
My_Tree * ROOT = new My_Tree();
int amount = 6;
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
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	Memo1->Clear();
	StringGrid1->Cells[0][0] = "¹";
	StringGrid1->Cells[1][0] = "Pers. Data";
	StringGrid1->Cells[2][0] = "¹ ticket";
	for (int i = 1; i <= amount; i++) {
		StringGrid1->Cells[0][i] = i;
	}
	StringGrid1->Cells[1][1] = "Kulevich À.Î.";
	StringGrid1->Cells[2][1] = "95350088";
	StringGrid1->Cells[1][2] = "Kruglaya À.À.";
	StringGrid1->Cells[2][2] = "95350084";
	StringGrid1->Cells[1][3] = "Trofimuk G.À.";
	StringGrid1->Cells[2][3] = "95350151";
	StringGrid1->Cells[1][4] = "Lavrenovich À.Å.";
	StringGrid1->Cells[2][4] = "95350091";
	StringGrid1->Cells[1][5] = "Vorobiov À.Ñ.";
	StringGrid1->Cells[2][5] = "95350027";
	StringGrid1->Cells[1][6] = "Kukareko À.P.";
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

		int temp = 0;
		if (TryStrToInt((Edit2->Text), temp)) {
			amount++;
			StringGrid1->Cells[1][amount] = Edit1->Text;
			StringGrid1->Cells[2][amount] = Edit2->Text;
			StringGrid1->Cells[0][amount] = amount;
			TInf A;
			A.FIO = Edit1->Text;
			TryStrToInt((Edit2->Text), A.key);
			ROOT->Add(ROOT->Root, A);
			Edit1->Text = "";
			Edit2->Text = "";
		}
		else {
			Edit2->Text = "";
			ShowMessage(
				"You have input wrong value of student's number. \nPlease try again.");
		}

	}
	else {
		ShowMessage("You haven't input all data ");
	}

}

// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	int temp = 0;
	if ((Edit3->Text != "") && TryStrToInt(Edit3->Text, temp)) {
		ROOT->Find(ROOT->Root, StrToInt(Edit3->Text));
	}
	else {
		ShowMessage("Please Check input field. \nInput data correctly.");
	}
	Edit3->Text == "";
}

// ---------------------------------------------------------------------------


// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {

	Memo1->Clear();
	int temp = 0;
	if ((Edit3->Text != "" && TryStrToInt(Edit3->Text, temp))) {
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
	else {
		ShowMessage("Please Check input field. \nInput data correctly.");
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

void __fastcall TForm1::Button9Click(TObject *Sender) {
	Memo1->Clear();
	int amount_of_daughters = 0;
	Count(ROOT->Root, &amount_of_daughters);
	Memo1->Lines->Add(+ "  Result: " + IntToStr(amount_of_daughters));
}
// ---------------------------------------------------------------------------
