// ---------------------------------------------------------------------------

#include "Struct_Stack.h"
#include "Form.h"
int Prioritet(char);
Stack* InStack(Stack*, char);
Stack* OutStack(Stack*, char*);
double mas[201];
Set<char, 0, 255>znak;

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
// ---------------------------------------------------------------------------
#pragma package(smart_init)
