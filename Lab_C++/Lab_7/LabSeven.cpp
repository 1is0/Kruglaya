// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LabSeven.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Node** hashTable;
int hashTableSize;
int i, *a, maxnum;
My_Hash* obj = new My_Hash();

// ---------------------------------------------------------------------------
void Hash::insertNode(int data) {
	Node*p, *p0 = new Node;
	hashTableIndex index;
	index = myhash(data);
	if ((p = new Node) == 0) {
		Form1->Memo1->Clear();
		Form1->Memo1->Lines->Add("Не хватает памяти(Insert)");
	}
	p0 = hashTable[index];
	if (p0 != NULL) {
		if (p0->data < data) {
			p->Next = p0;
			hashTable[index] = p;
		}
		else {
			while (p0->Next)
				p0 = p0->Next;
			p0->Next = p;

		}
		p->data = data;
	}
	else {
		hashTable[index] = p;
		p->data = data;
	}

}

// ---------------------------------------------------------------------------
int Hash::myhash(int data) {
	return (data % hashTableSize);
}

// ---------------------------------------------------------------------------
void Hash::deleteNode(int data) {
	Node *p0, *p;
	hashTableIndex index;
	p0 = 0;
	index = myhash(data);
	p = hashTable[index];
	while (p && !(p->data == data)) {
		p0 = p;
		p = p->Next;
	}
	if (!p)
		return;
	if (p0)
		p0->Next = p->Next;
	else
		hashTable[index] = p->Next;
	free(p);

}

// ---------------------------------------------------------------------------
Node* Hash::findNode(int data) {
	Node*p;
	p = hashTable[myhash(data)];
	while (p && (p->data != data))
		p = p->Next;
	return p;
}

// ---------------------------------------------------------------------------
void My_Hash::Print() {
	Form1->RichEdit1->Text = "";
	for (i = hashTableSize - 1; i >= 0; i--) {
		Node* Temp = hashTable[i];

		Form1->RichEdit1->Text = Form1->RichEdit1->Text + IntToStr(i + 1) + ":";
		while (Temp) {

			Form1->RichEdit1->Text =
				Form1->RichEdit1->Text + IntToStr(Temp->data) + "->";
			Temp = Temp->Next;
		}
		Form1->RichEdit1->Lines->Add("");
	}
}

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
	if (Edit1->Text != "" && Edit1->Text != "") {

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
		ShowMessage("Вы не ввели нужные данные");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	if (Edit5->Text != "") {
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
		ShowMessage("Вы не ввели данные");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (Edit3->Text != "") {
		Node* find = new Node;
		find = obj->findNode(StrToInt(Edit3->Text));
		RichEdit1->Text = "";
		RichEdit1->Text = IntToStr(find->data);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	if (Edit4->Text != "") {

		int* temp = new int[maxnum];
		for (i = 0; i < maxnum; i++) {
			temp[i] = a[i];
		}
		for (i = 0; i < maxnum; i++) {
			if (temp[i] == StrToInt(Edit4->Text)) {
				for (int j = i + 1; j < maxnum; i++, j++) {
					temp[i] = temp[j];
				}
				break;
			}

		}
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
		Edit4->Text = "";
		Button4Click(Sender);
	}
}
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
   obj->Print();
}
//---------------------------------------------------------------------------

