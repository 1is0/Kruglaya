// ---------------------------------------------------------------------------

#include <vcl.h>
#include <list>
#include <string>
#include <iostream>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
MyList*List1 = new MyList();
int amount = 0;
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void MyList::Add(Sportsman* new_item) {
	if (!head)
		head = new_item;
	else
		tail->next = new_item;
	tail = new_item;

}

Sportsman* MyList::Search(AnsiString name) {

	Sportsman* current = List1->head;
	while (current) {
		if (current->name == name)
			return current;
		current = current->next;
	};

	return NULL;
}

void MyList::Add(Sportsman* new_item, int index) {
	if (!head) {
		head = new_item;
		tail = new_item;
	}
	else if (index == 0) {
		new_item->next = head;
		head = new_item;
	}

	else {
		Sportsman* current = head;
		for (int i = 1; i < index && current->next; i++) {
			current = current->next;
		}

		if (!current->next) {
			tail = new_item;
		}

		new_item->next = current->next;
		current->next = new_item;

	}

}

void MyList::Remove(AnsiString name) {
	if (!List1->head) {
		ShowMessage("В списке нет элементов");
		return;
	}
	else if (name == List1->head->name) {
		Sportsman* old_item = List1->head;
		List1->head = head->next;
		delete old_item;
		return;
	}
	else {
		Sportsman* prev = List1->head;
		Sportsman* current = List1->head->next;
		for (int i = 1; current; i++) {
			if (name == current->name) {
				if (!current->next)
					tail = prev;

				prev->next = current->next;
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		}
	}
}

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	Memo1->Clear();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	if (!(ComboBox1->Text == "") && (!(Edit9->Text == "")) &&
		(!(Edit1->Text == "")) && (!(Edit2->Text == "")) &&
		(!(Edit3->Text == "")) && (!(Edit4->Text == "")) &&
		(!(Edit5->Text == ""))) {

		UnicodeString country = Edit9->Text;
		AnsiString Country = country;

		UnicodeString team = Edit1->Text;
		AnsiString Team = team;

		UnicodeString name = ComboBox1->Text;
		AnsiString Name = name;

		int play_Num = StrToInt(Edit2->Text);

		int Age = StrToInt(Edit3->Text);

		int Hight = StrToInt(Edit4->Text);

		int Weight = StrToInt(Edit5->Text);

		Sportsman * sportsman = new Sportsman(Country, Name, Team, Age, Weight,
			Hight, play_Num);

		List1->Add(sportsman);
		ComboBox1->Items->Add(Name);
		ComboBox1->Text = " ";
		Edit9->Clear();
		Edit1->Clear();
		Edit2->Clear();
		Edit3->Clear();
		Edit4->Clear();
		Edit5->Clear();

	}
	else {
		ShowMessage("Вы не ввели все данные");
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Select(TObject *Sender) {
	UnicodeString name = ComboBox1->Text;
	AnsiString Name = name;
	Sportsman* find = List1->Search(Name);

	Edit1->Text = find->team;
	Edit9->Text = find->country;
	Edit2->Text = IntToStr(find->play_number);
	Edit3->Text = IntToStr(find->age);
	Edit4->Text = IntToStr(find->hight);
	Edit5->Text = IntToStr(find->weight);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender) {
	Memo1->Clear();
	if (!List1->head) {
		ShowMessage("В списке никого нет");
	}

	Sportsman* temp = List1->head;
	while (temp) {
		Memo1->Show();
		Memo1->Lines->Add(temp->name);

		temp = temp->next;
	}

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender) {
	if (!(ComboBox1->ItemIndex == -1)) {
		UnicodeString name = ComboBox1->Text;
		AnsiString Name = name;
		List1->Remove(Name);
		ComboBox1->DeleteSelected();
		ComboBox1->Text = " ";
		Edit9->Clear();
		Edit1->Clear();
		Edit2->Clear();
		Edit3->Clear();
		Edit4->Clear();
		Edit5->Clear();
	}
	else {
		ShowMessage("Вы не выбрали игрока для удаления");
	}
}

// ---------------------------------------------------------------------------
void MyList::WeightCategory(int min, int max) {
	if (!List1) {
		ShowMessage("Список пуст");
	}
	Form1->Memo1->Clear();
	Sportsman* current = List1->head;
	int i = 1;
	while (current) {
		if (current->weight >= min && current->weight <= max) {
			Form1->Memo1->Lines->Add("Ф.И.О.: " + current->name);
			Form1->Memo1->Lines->Add("Страна: " + current->country);
			Form1->Memo1->Lines->Add("Название команды: " + current->team);
			UnicodeString age = IntToStr(current->age);
			AnsiString Age = age;
			UnicodeString weight = IntToStr(current->weight);
			AnsiString Weight = weight;
			UnicodeString hight = IntToStr(current->hight);
			AnsiString Hight = hight;
			Form1->Memo1->Lines->Add("Возраст: " + Age);
			Form1->Memo1->Lines->Add("Вес: " + Weight + "кг" +
				" Рост: " + Hight);
			Form1->Memo1->Lines->Add(" ");

		}
		current = current->next;
		i++;
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	if (!(Edit6->Text == "") && !(Edit8->Text == "")) {
		int min = StrToInt(Edit6->Text);
		int max = StrToInt(Edit8->Text);
		List1->WeightCategory(min, max);
	}

}

// ---------------------------------------------------------------------------
void MyList::HightTeam(int min_hight) {

	Sportsman* current = List1->head;
	bool decision = 1;

	while (current) {
		AnsiString Team = current->team;
		Sportsman* temp = current;
		if (current->hight >= min_hight) {
			int count = 0;

			// Sportsman* temp = current;

			while (current) { // amount of gamers in team
				if (current->team == Team) {
					count++;
				}
				current = current->next;
			}
			current = temp;
			while (temp) { // check if all are higher than min_high
				if (temp->team == Team) {
					for (int i = 0; i < count; i++) {
						if (temp->hight < min_hight) {
							decision = 0;
						}
					}
				}

				temp = temp->next;
			}

			temp = current;
			if (decision) {
				Form1->Memo1->Lines->Add("           " + Team + ":");
				while (count) {

					Form1->Memo1->Lines->Add("Ф.И.О.: " + temp->name);
					Form1->Memo1->Lines->Add("Страна: " + temp->country);
					UnicodeString age = IntToStr(temp->age);
					AnsiString Age = age;
					UnicodeString weight = IntToStr(temp->weight);
					AnsiString Weight = weight;
					UnicodeString hight = IntToStr(temp->hight);
					AnsiString Hight = hight;
					Form1->Memo1->Lines->Add("Возраст: " + Age);
					Form1->Memo1->Lines->Add
						("Вес: " + Weight + "кг" + " Рост: " + Hight);
					Form1->Memo1->Lines->Add(" ");

					temp = temp->next;
					count--;
				}
			}
		}
		temp = current;
		while (current->team == temp->team) {
			current = current->next;
			if (!current || current->team != temp->team) {
				break;

			}
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	Memo1->Clear();
	if (!List1) {
		ShowMessage("Список пуст");
	}
	else {
		int min = StrToInt(Edit7->Text);
		List1->HightTeam(min);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	Memo1->Clear();
}

// ---------------------------------------------------------------------------
void MyList::YoungestTeam() {
	Sportsman* current = List1->head;
	Sportsman* youngest = current;

	while (current) {
		if (current->age < youngest->age) {
			Sportsman* temp = current;
			current = youngest;
			youngest = temp;
		}
		current = current->next;
	}
	Form1->Memo1->Lines->Add("Информация о самой молодой команде");
	Form1->Memo1->Lines->Add("  Название: " + youngest->team);
	current = List1->head;
	while (current) {
		if (current->team == youngest->team) {
			Form1->Memo1->Lines->Add("Ф.И.О.: " + current->name);
			Form1->Memo1->Lines->Add("Страна: " + current->country);
			UnicodeString age = IntToStr(current->age);
			AnsiString Age = age;
			UnicodeString weight = IntToStr(current->weight);
			AnsiString Weight = weight;
			UnicodeString hight = IntToStr(current->hight);
			AnsiString Hight = hight;
			Form1->Memo1->Lines->Add("Возраст: " + Age);
			Form1->Memo1->Lines->Add("Вес: " + Weight + "кг" +
				" Рост: " + Hight);
			Form1->Memo1->Lines->Add(" ");
		}
		current = current->next;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	Memo1->Clear();
	if (!List1) {
		ShowMessage("Список пуст");
	}
	else {

		List1->YoungestTeam();
	}
}
// ---------------------------------------------------------------------------
