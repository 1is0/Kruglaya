// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "MyHash.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Node** hashTable;
 int hashTableSize;
int i, *a, maxnum;
int check = 0;
My_Hash* obj = new My_Hash();


// ---------------------------------------------------------------------------


__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	Memo1->Clear();
	RichEdit1->Clear();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender) {
	Memo1->Clear();
    RichEdit1->Clear();
	if (!TryStrToInt(Edit1->Text, check) || !TryStrToInt(Edit2->Text, check)) {
		ShowMessage("You have input wrong integer value. \nPlease try again.");

	}
	else {
		if (Edit1->Text != "" && Edit2->Text != "") {

			maxnum = StrToInt(Edit1->Text);
			hashTableSize = StrToInt(Edit2->Text);
			a = new int[maxnum];
			hashTable = new Node*[hashTableSize];
			for (i = 0; i < hashTableSize; i++)
				hashTable[i] = NULL;
			for (i = 0; i < maxnum; i++)
				a[i] = rand() % 1000;
			for (i = 0; i < maxnum; i++) {
				obj->insertNode(a[i]);
				Memo1->Lines->Add(a[i]);
			}
		}
		else
			ShowMessage("You haven't input all data");
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	if (Edit5->Text != "" && TryStrToInt(Edit5->Text, check)) {
		int* temp = new int[maxnum];
		for (i = 0; i < maxnum; i++) {
			temp[i] = a[i];
		}
		delete[]a;
		maxnum++;
		a = new int[maxnum];
		for (i = 0; i < maxnum - 1; i++) {
			a[i] = temp[i];
		}
		a[maxnum - 1] = StrToInt(Edit5->Text);
		obj->insertNode(a[maxnum - 1]);
		Memo1->Clear();
		for (i = 0; i < maxnum; i++) {

			Memo1->Lines->Add(a[i]);
		}
		Button4Click(Sender);
		Edit5->Text = "";
	}
	else {
		ShowMessage("Please check input field and try again");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {

	if (Edit3->Text != "" && TryStrToInt(Edit3->Text, check)) {
		Node* find = new Node;
		find = obj->findNode(StrToInt(Edit3->Text));
		RichEdit1->Text = "";
		if(find){
		RichEdit1->Text = "Key{"+IntToStr((find->data)%hashTableSize+1)+"} - Item: "+IntToStr(find->data);
		}else {
         RichEdit1->Text = "There isn't such item";
		}
        Edit3->Text="";
	}
	else
		ShowMessage("Please check input field and try again ");
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	if (Edit4->Text != "" && TryStrToInt(Edit4->Text, check)) {
		bool flag =0;
		int* temp = new int[maxnum];
		for (i = 0; i < maxnum; i++) {
			temp[i] = a[i];
		}
		for (i = 0; i < maxnum; i++) {
			if (temp[i] == StrToInt(Edit4->Text)) {
			 flag =1;
				for (int j = i + 1; j < maxnum; i++, j++) {
					temp[i] = temp[j];
				}
				break;
			}

		}
		if(flag){
		delete[]a;
		maxnum--;
		a = new int[maxnum];
		for (i = 0; i < maxnum; i++) {
			a[i] = temp[i];
		}
		Memo1->Clear();
		for (i = 0; i < maxnum; i++) {

			Memo1->Lines->Add(a[i]);
		}
		obj->deleteNode(StrToInt(Edit4->Text));
		Button4Click(Sender);
		} else {
			RichEdit1->Text = "";
            	RichEdit1->Text = 	RichEdit1->Text + "There isn't such item";
        }
		Edit4->Text = "";

	}
	else
		ShowMessage("Please check input field and try again ");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {

	if (Edit1->Text == "" || Edit2->Text == "") {

		ShowMessage("You haven't input all data");
	}
	else {
		if (TryStrToInt(Edit1->Text, check) && TryStrToInt(Edit2->Text, check))
		{
				RichEdit1->Text = "";
			obj->Print(hashTableSize, hashTable);
		}
		else
			ShowMessage(
			"You have input wrong integer value. \nPlease try again.");
	}
}
// ---------------------------------------------------------------------------



