// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form.h"
#include "Struct_Stack.cpp"
// ---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
int Amount = 6;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	Edit1->Text = "a*(b+c)/(d-e)";
	Edit2->Text = "";
	char a = 'a';

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	Stack* t;
	begin = NULL;
	char symbol, a;
	String InStr, OutStr;
	OutStr = "";
	Edit2->Text = "";
	InStr = Edit1->Text;
	znak << '*' << '/' << '+' << '-' << '^';
	for (int k = 1, len = InStr.Length() + 1; k < len; k++) {
		symbol = InStr[k];
		if (symbol == '(') {
			begin = InStack(begin, symbol);
		}
		else if (symbol == ')') {
			while ((begin->inform) != '(') {
				begin = OutStack(begin, &a);
				OutStr += a;
			}
			begin = OutStack(begin, &a);
		}
		else if (symbol >= 'a' && symbol <= 'z')
			OutStr += symbol;
		else if (znak.Contains(symbol)) {

			while (begin != NULL && Prioritet(begin->inform) >=
				Prioritet(symbol)) {
				begin = OutStack(begin, &a);
				OutStr += a;
			}
			begin = InStack(begin, symbol);
		}
	}
	while (begin != NULL) {
		begin = OutStack(begin, &a);
		if (a != '(')
			OutStr += a;
	}
	Edit2->Text = OutStr;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	char ch;
	String OutStr = Edit2->Text;
	for (int i = 1; i < Amount; i++) {

		if (i == 1) {
			ch = 'a';
			if (Edit4->Text != "") {
				mas[int(ch)] = StrToFloat(Edit4->Text);
			}
			else   	mas[int(ch)] = 0;
		}
		else if (i == 2) {
			ch = 'b';
			if (Edit5->Text != "" ) {
				mas[int(ch)] = StrToFloat(Edit5->Text);
			}
			else   	mas[int(ch)] = 0;
		}
		else if (i == 3) {
			ch = 'c';
			if (Edit6->Text != "") {
				mas[int(ch)] = StrToFloat(Edit6->Text);
			}
			else   	mas[int(ch)] = 0;
		}
		else if (i == 4) {
			ch = 'd';
			if (Edit7->Text != "") {
				mas[int(ch)] = StrToFloat(Edit7->Text);
			}
			else   	mas[int(ch)] = 0;
		}
		else if (i == 5) {
			ch = 'e';
		if (Edit8->Text != "") {
				mas[int(ch)] = StrToFloat(Edit8->Text);
			}
			else   	mas[int(ch)] = 0;
		}
		// ch = StringGrid1->Cells[i][0][1];

		// mas[int(ch)] = StrToFloat(StringGrid1->Cells[i][1]);
	}
	Edit3->Text = FloatToStr(Rezult(OutStr));
}
// ---------------------------------------------------------------------------
