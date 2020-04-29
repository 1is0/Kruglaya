// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;

	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

// ---------------------------------------------------------------------------
struct Node {
	int data;
	Node *Next, *Prev;
};

class QUEUE {
protected:
	Node*Head, *Tail;

public:
	QUEUE() : Head(NULL), Tail(NULL) {
	}
	~QUEUE();
	virtual void Show();

	void Add(int data) {
		Node* temp = new Node;
		temp->Next = NULL;
		temp->data = data;
		if (Head != NULL) {
			temp->Prev = Tail;
			Tail->Next = temp;
			Tail = temp;
		}
		else {
			temp->Prev = NULL;
			Head = Tail = temp;
		}
	};
	void DelN();

};

// ---------------------------------------------------------------------------
class My_QUEUE : public QUEUE {

public:

	Node* Find_Max();
	Node* Find_Min();
	void Insert_QUEUE(My_QUEUE* Input, Node* First, Node* Last);

	Node* HEAD() {
		return Head;
	};
	Node* TAIL();
};
#endif
