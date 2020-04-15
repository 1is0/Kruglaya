// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct Stack {
	char inform;
	Stack* next;
}*begin;

int Prioritet(char);
Stack* InStack(Stack*, char);
Stack* OutStack(Stack*, char*);
double Rezult(String);
double mas[201];
Set<char, 0, 255>znak;
int Amount = 6;

// ---------------------------------------------------------------------------
double Rezult(String Str) {
	char ch, ch1, ch2;
	float op1, op2, rez;
	znak << '*' << '/' << '+' << '-' << '^';
	char chr = 'e' + 1;
	for (int i = 1, len = Str.Length(); i <= len; i++) {
		ch = Str[i];
		if (!znak.Contains(ch)) {
			begin = InStack(begin, ch);
		}
		else {
			begin = OutStack(begin, &ch1);
		
			begin = OutStack(begin, &ch2);
			op1 = mas[int(ch2)];
			op2 = mas[int(ch1)];
			switch (ch) {
			case '+':
				rez = op1 + op2;
				break;
			case '-':
				rez = op1 - op2;
				break;
			case '*':
				rez = op1 * op2;
				break;
			case '/':
				rez = op1 / op2;
				break;
			case '^':
				rez = pow(op1, op2);
				break;

			}
			mas[int(chr)] = rez;
			begin = InStack(begin, chr);
			chr++;
		}

	}
	return rez;

}

// ---------------------------------------------------------------------------
int Prioritet(char a) {
	switch (a) {
	case '^':
		return 4;
	case '*':
	case '/':
		return 3;
	case '-':
	case '+':
		return 2;
	case '(':
		return 1;

	}
	return 0;
}

// ---------------------------------------------------------------------------
Stack* InStack(Stack* p, char inf) {
	Stack* t = new Stack;
	t->inform = inf;
	t->next = p;
	return t;

}

// ---------------------------------------------------------------------------
Stack* OutStack(Stack* p, char *out) {
	Stack *t = p;
	*out = p->inform;
	p = p->next;
	delete t;
	return p;
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {
	Edit1->Text = "a*(b+c)/(d-e)";
	Edit2->Text = "";
	char a = 'a';
	StringGrid1->Cells[0][0] = "Перемен.";
	StringGrid1->Cells[0][1] = "Значен.";
	for (int i = 1; i < Amount; i++) {
		StringGrid1->Cells[i][0] = a++;

	}
	StringGrid1->Cells[1][1] = 0.4;
	StringGrid1->Cells[2][1] = 2.3;
	StringGrid1->Cells[3][1] = 6.7;
	StringGrid1->Cells[4][1] = 5.8;
	StringGrid1->Cells[5][1] = 9.1;

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
	for (int k = 1, len = InStr.Length(); k < len; k++) {
		symbol = InStr[k];
		if (symbol == '(') {
			begin = InStack(begin, symbol);
		}

		if (symbol == ')') {
			while ((begin->inform) != '(') {
				begin = OutStack(begin, &a);
				OutStr += a;
			}
			begin = OutStack(begin, &a);
		}
		if (symbol >= 'a' && symbol <= 'z')
			OutStr += symbol;
		if (znak.Contains(symbol)) {

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

		ch = StringGrid1->Cells[i][0][1];

		mas[int(ch)] = StrToFloat(StringGrid1->Cells[i][1]);
	}
	Edit3->Text = FloatToStr(Rezult(OutStr));
}
// ---------------------------------------------------------------------------
