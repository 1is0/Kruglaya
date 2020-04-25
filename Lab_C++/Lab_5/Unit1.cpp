// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n, size, m = 1;
QUEUE object;
My_QUEUE obj1, obj2;

QUEUE::~QUEUE() {

	while (Head) {
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

void QUEUE::DelN() {
	if (Head == 0) {
		ShowMessage("Error, list is empty");
		return;
	}
	Node * temp;
	temp = Head->Next;
	delete Head;
	Head = temp;
}

void QUEUE::Show() {
	Node*temp = Tail;
	temp = Head;
	while (temp != NULL) {

		temp = temp->Next;
	}
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender) {
	if (!(Edit1->Text == "")) {
		n = StrToInt(Edit1->Text) + 1;
		StringGrid1->RowCount = n;
		for (int i = 1; i < n; i++)
			StringGrid1->Cells[0][i] = i;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	int X = StrToInt(Edit2->Text);
	object.Add(X);
	StringGrid1->Cells[1][m] = X;
	m++;
	Edit2->Text = "";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	try {
		object.DelN();
		if (m == 2) {
			Edit1->Text = "";
		}
		for (int i = 1, j = m - 1; i <= m - 1; i++) {
			if (i == m - 1) {
				StringGrid1->Cells[1][i] = "";
				StringGrid1->Cells[0][i] = "";

			}
			else {

				StringGrid1->Cells[1][i] = StringGrid1->Cells[1][i + 1];
				StringGrid1->Cells[1][i + 1] = "";
				StringGrid1->Cells[0][j] = "";
				Edit1->Text = m - 2;
			}
		}
		m--;
	}
	catch (...) {
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	try {

		object.~QUEUE();
		for (int i = 1; i < m; i++) {
			StringGrid1->Cells[1][i] = "";
		}
		m = 1;

	}
	catch (...) {
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Edit3Change(TObject *Sender) {
	if (!(Edit3->Text == "")) {
		size = StrToInt(Edit3->Text) + 1;
		StringGrid2->RowCount = size;
		for (int i = 1; i < size; i++)
			StringGrid2->Cells[0][i] = i;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	StringGrid1->Cells[0][0] = "Номер";
	StringGrid1->Cells[1][0] = "Значение";
	StringGrid2->Cells[0][0] = "Номер";
	StringGrid2->Cells[1][0] = "Значение1";
	StringGrid2->Cells[2][0] = "Значение2";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	int x, y;
	srand(time(NULL));
	for (int i = 1; i < size; i++) {
		x = rand() % 50;
		y = rand() % 50;
		obj1.Add(x);
		obj2.Add(y);
		StringGrid2->Cells[1][i] = x;
		StringGrid2->Cells[2][i] = y;
	}
}

// ---------------------------------------------------------------------------
Node* My_QUEUE::Find_Max() {
	Node*Temp = Head;
	Node* MAX = Head;
	while (Head->Next) {
		if (Head->Next->data > MAX->data) {
			MAX = Head->Next;
		}
		Head = Head->Next;
	}
	Head = Temp;
	return MAX;
}

// ---------------------------------------------------------------------------
Node* My_QUEUE::Find_Min() {
	Node* MIN = Head;
	Node*Temp = Head;
	while (Head->Next) {
		if (Head->Next->data < MIN->data) {
			MIN = Head->Next;
		}
		Head = Head->Next;
	}
	Head = Temp;
	return MIN;
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void My_QUEUE::Insert_QUEUE(My_QUEUE* Input, Node*First, Node*Last) {

	bool Position = 0;
	Node* Temp = Head;

	Head = First;
	while (Head) {
		if (Head == Last) {
			Position = 1;
		}
		Head = Head->Next;
	}
	Head = Temp;

	if (Position) {
		First->Next = (*Input).Head;
		(*Input).Head->Prev = First;
		Last->Prev = (*Input).Tail;
		(*Input).Tail->Next = Last;
	}
	else {
		Last->Next = (*Input).Head;
		(*Input).Head->Prev = Last;
		First->Prev = (*Input).Tail;
		(*Input).Tail->Next = First;
	}
	Head = Temp;
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	size *= 2;
	Node* First = obj1.Find_Max();
	Node* Last = obj1.Find_Min();
	Node*temp = obj1.HEAD();
	StringGrid2->RowCount = size;
	obj1.Insert_QUEUE(&obj2, First, Last);
	for (int i = 1; i < size, temp != NULL; i++) {
		StringGrid2->Cells[0][i] = i;
		StringGrid2->Cells[1][i] = temp->data;
		temp = temp->Next;
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject * Sender) {
	obj1.~My_QUEUE();
	obj2.~My_QUEUE();

	Edit3->Text = "";
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < 3; j++)
			StringGrid2->Cells[j][i] = "";
	}
}
// ---------------------------------------------------------------------------
