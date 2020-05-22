 #include "LabSeven.h"
 #include "MyHash.h"




// ---------------------------------------------------------------------------
 void My_Hash::Print(int a, Node** b) {

	for (int i = a - 1; i >= 0; i--) {
		Node* Temp = b[i];

		Form1->RichEdit1->Text = Form1->RichEdit1->Text + IntToStr(i + 1) + ":";
		while (Temp) {

			Form1->RichEdit1->Text = Form1->RichEdit1->Text +
				IntToStr(Temp->data) + "->";
			Temp = Temp->Next;
		}
		Form1->RichEdit1->Lines->Add("");
	}
}

// ---------------------------------------------------------------------------
