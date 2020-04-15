// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <vector>

using namespace std;

// #include <string>
// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TComboBox *ComboBox1;
	TEdit *Edit2;
	TMemo *Memo1;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TGroupBox *GroupBox2;
	TButton *Button2;
	TEdit *Edit6;
	TButton *Button4;
	TLabel *Label8;
	TGroupBox *GroupBox3;
	TLabel *Label9;
	TButton *Button5;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label10;
	TLabel *Label11;
	TButton *Button7;
	TEdit *Edit9;
	TButton *Button1;
	TButton *Button3;
	TLabel *Label13;
	TButton *Button6;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif

struct Sportsman {
	AnsiString country;
	AnsiString name;
	AnsiString team;
	int age;
	int weight;
	int hight;
	int play_number;
	Sportsman* next;
	Sportsman* prev;

	Sportsman(AnsiString c, AnsiString n, AnsiString t, int a, int w, int h,
		int p_n) : country(c), name(n), team(t), age(a), weight(w), hight(h),
		play_number(p_n), next(NULL), prev(NULL) {
	};

};

class MyList {

public:
	Sportsman* head;
	Sportsman* tail;

	MyList() {
		head == NULL, tail == NULL;
	};
	void Add(Sportsman * item);
	void Add(Sportsman * new_item, int index);
	void Remove(AnsiString name);
	Sportsman* Search(AnsiString name);
	void WeightCategory(int min, int max);
	void HightTeam(int min_hight);
	void YoungestTeam();

};
