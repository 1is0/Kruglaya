// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Queue.h"
#include "MyQueue.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n, size, m = 1;
bool flag =0;
QUEUE object;
My_QUEUE obj1, obj2;

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
if(Edit1->Text!=""){
	if (m < n - 1) {
		int X = StrToInt(Edit2->Text);
		object.Add(X);
		StringGrid1->Cells[1][m] = X;
		m++;
	}
	else {
		int X = StrToInt(Edit2->Text);
		object.Add(X);
		StringGrid1->Cells[1][m] = X;
		m++;
		Button2->Enabled = False;
		Edit2->Enabled = False;
	}

	Edit2->Text = "";
}  else ShowMessage("Please input size of queue");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	object.DelN();

	for (int i = 1, j = m - 1; i <= m - 1; i++) {
		if (i == m - 1) {
			StringGrid1->Cells[1][i] = "";

		}
		else {

			StringGrid1->Cells[1][i] = StringGrid1->Cells[1][i + 1];
			StringGrid1->Cells[1][i + 1] = "";

		}
         m--;
		if (m < n + 1) {
			Button2->Enabled = True;
			Edit2->Enabled = True;
            Edit2->ReadOnly = False;
		}

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
		Button2->Enabled = True;
        Edit2->Enabled = True;
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
	StringGrid1->Cells[0][0] = "Number";
	StringGrid1->Cells[1][0] = "Value";
	StringGrid2->Cells[0][0] = "Number";
	StringGrid2->Cells[1][0] = "Value1";
	StringGrid2->Cells[2][0] = "Value2";
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
if(Edit3->Text!=""){	int x, y;
	srand(time(NULL));
	for (int i = 1; i < size; i++) {
		x = rand() % 50;
		y = rand() % 50;
		obj1.Add(x);
		obj2.Add(y);
		StringGrid2->Cells[1][i] = x;
		StringGrid2->Cells[2][i] = y;
	}
	flag =1;
    Edit3->Enabled = False;
}else ShowMessage("Please input size of queues");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
  if(flag){	size *= 2;
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
   else ShowMessage("Please create queues");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject * Sender) {
if(flag){
	obj1.~My_QUEUE();
	obj2.~My_QUEUE();

	Edit3->Text = "";
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < 3; j++)
			StringGrid2->Cells[j][i] = "";
	}
    Edit3->Enabled = True;
}else ShowMessage("Please Create queues");
}
// ---------------------------------------------------------------------------
