// ---------------------------------------------------------------------------

#ifndef LabSevenH
#define LabSevenH

// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TMemo *Memo1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit3;
	TButton *Button1;
	TEdit *Edit4;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label3;
	TLabel *Label4;
	TRichEdit *RichEdit1;
	TLabel *Label5;
	TEdit *Edit5;
	TButton *Button5;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

// ---------------------------------------------------------------------------




#endif
