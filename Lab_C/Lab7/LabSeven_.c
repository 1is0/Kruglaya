#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "LabSeven_.h"
Client* Person = NULL;
ClientList List = { 0, NULL, NULL };
_date Today;
Client* CheckClient() {
	Client* Temp = (Client*)malloc(sizeof(Client));
	if (Temp)return Temp;
	else {
		printf("\nОшибка с выделением  памяти");
		return NULL;
	}
}
Deposit* CheckDeposit() {
	Deposit* Temp = (Deposit*)malloc(sizeof(Deposit));
	if (Temp)return Temp;
	else {
		printf("\nОшибка с выделением  памяти");
		return NULL;
	}
}
_operation* CheckOperation() {
	_operation* Temp = (_operation*)malloc(sizeof(_operation));
	if (Temp)return Temp;
	else {
		printf("\nОшибка с выделением  памяти");
		return NULL;
	}
}
void ListInFile();
void Menu1();
void Add_deposit(Client** person, Deposit** deposit);
void Add_Client(Client* client);
void Add_Operation(Deposit** deposit, _operation** operation);
void DepositMenu();
void Initialize_Operation(float money, _operation** operation);
void Print(Client* person);
void PrintTime() {
	time_t s_time;
	struct tm* m_time;
	char str_t[128] = "";
	time(&s_time);
	m_time = localtime(&s_time);
	strftime(str_t, 128, "%x", m_time);
	printf("Сегодня %s\n", str_t);
	Today.day = m_time->tm_mday;
	Today.month = m_time->tm_mon + 1;
	Today.year = m_time->tm_year + 1900;

	return 0;
}
int monthdays(int month, int year) {
	if (month == 2 && year % 4 == 0) {
		return 29;
	}
	else if (month == 2) {
		return 28;
	}
	else if (month % 2 == 1 || month == 8 || month == 10 || month == 12) {
		return 31;
	}
	else return 30;
}
int Sure() {
	printf("\nВы уверены, что хотите это сделать? 1.Да / 2.Нет");
	return Choice(2);
}
void Date(_date* date) {
	printf("\nВведите год ");
	(*date).year = Choice(3000);
	printf("\nВведите месяц: ");
	(*date).month = Choice(12);
	int number_days = monthdays((*date).month, (*date).year);
	printf("\nВведите число: ");
	(*date).day = Choice(number_days);

}
void Exit() {
	ListInFile();
	switch (Sure()) {
	case 1: exit(-1); break;
	case 2: Main_Menu(); break;
	}
}
void Help() {
	printf("");
	char c;
	rewind(stdin);
	int p = 1;
	while (p == 1) {
		printf("\n\tВ данной программе вы можете создавать,изменять и удалять вклады.\n\tДля создания вклада перейдите в подменю \"Операции с вкладами -> Добавить вклад...\"\n\tДля проведения операций с вкладами перейдите в подменю \"Операции с вкладами -> Поиск вклада по номеру лицевого счёта...\"\n\tВ каждом подменю есть возможность вернуться назад, выбрав пункт \"Назад\"\n\t Для перевода денег с одного вклада на другой перейдите в подменю\"Перевод денег\"\n\tВоспользовавшись подменю\"Отчёты\" вы можете увидеть все операции проводимы с вкладами в этом году\n\tНажмите Enter,чтобы вернуться");
		if (getchar()) {
			p = 0;
		}
	}

}
void Input_deposit(Client** client) {
	Deposit* new_one = CheckDeposit();
	new_one->start = Today;
	printf("Категория вклада: 1.Условный 2.До востребования 3.Срочные депозиты. Сберегательный 4.Срочные депозиты. Накопительный");
	new_one->Category = Choice(4);
	if (new_one->Category == 1 || new_one->Category == 3 || new_one->Category == 4) {
		printf("\nДо какого числа будет существовать вклад ");
		Date(&new_one->end);
	}
	printf("\nДенежная единица: 1.BYN 2.RYB 3.USD 4.EUR");
	new_one->Currency = Choice(4);

	switch (new_one->Currency) {
	case 1:new_one->Interest_rate = 12, 5; break;
	case 2:new_one->Interest_rate = 10, 5; break;
	case 3:new_one->Interest_rate = 2, 5; break;
	case 4:new_one->Interest_rate = 1, 5; break;
	}

	printf("\nНачисление процентов: 1.Ежегодно 2.Ежеквартально 3.Ежемесячно 4.Еженедельно");
	new_one->Period = Choice(4);
	switch (new_one->Period) {

	case 1:new_one->Interest_rate *= 1; break;
	case 2:new_one->Interest_rate *= 0.85; break;
	case 3:new_one->Interest_rate *= 0.7; break;
	case 4:new_one->Interest_rate *= 0.5; break;
	}
	printf("\nКакую сумму вкладчик положит на вклад: ");
	while (!scanf_s("%f", &new_one->Initial_deposit)) {
		printf("\nПри вводе вы допустили ошибку, повторите попытку");
		rewind(stdin);
	}
	new_one->amount_of_operation = 0;
	new_one->Operation = NULL;
	Initialize_Operation(new_one->Initial_deposit, &new_one->Operation);
	Add_deposit(&(*client), &new_one);
}
void Add_Operation(Deposit** deposit, _operation** operation) {

	if ((*deposit)->Operation == NULL) {
		(*deposit)->Operation = (*operation);
		(*deposit)->Operation->Next = NULL;
	}
	else {
		_operation* temp = CheckOperation();
		temp = (*deposit)->Operation;
		while ((*deposit)->Operation->Next) {
			(*deposit)->Operation = (*deposit)->Operation->Next;
		}
		(*deposit)->Operation->Next = (*operation);
		(*deposit)->Operation->Next->Next = NULL;
		(*deposit)->Operation = temp;
	}

}
void Input() {
	printf("\nГлавное меню -> Операции с вкладами -> Добавление вклада -> Добавление нового клиента...\n");
	int amount_d;
	Client* New = CheckClient();
	printf("\t\t\tВведите данные\n");
	srand(time(NULL));
	New->Personal_Account_Number = rand() % 1000000 + 100000;
	printf("\nНомер лицевого счета:%d", New->Personal_Account_Number);
	printf("\nВведите паспортные данные:");
	printf("\nФ.И.О. : ");
	scanf("%s", New->Passport.Surname);
	scanf("%s", New->Passport.Name);
	scanf("%s", New->Passport.Father_name);
	printf("\nИндефикационный номер паспорта : ");
	scanf("%s", New->Passport.Index_Number);
	printf("\nСколько вкладов планируете открыть: ");
	scanf_s("%d", &(New->amount_deposits));
	New->Deposits = NULL;
	for (int i = 0; i < New->amount_deposits; i++) {
		printf("%d)", i + 1);
		Input_deposit(&New);
	}
	Add_Client(New);

}
Client* Find_Client() {
	if (Person != NULL) {

		int personal_number;
		printf("\nВведите номер лицевого счёта клиента: ");
		scanf_s("%d", &personal_number);
		while (Person) {
			if (Person->Personal_Account_Number == personal_number) {
				Client* Temp2 = Person;
				Person = List.Head;
				return Temp2;
			}
			Person = Person->Next;
		}
		Person = List.Head;
		printf("\nТакого лицевого счёта не существует\n");
	}
	printf("\nТакого лицевого счёта не существует\n");
	return NULL;


}
Deposit* Find_D(Client** client) {
	Deposit* TEMP = (*client)->Deposits;
	int choice = Choice((*client)->amount_deposits);
	for (int i = 0; i < choice - 1; i++)
	{
		(*client)->Deposits = (*client)->Deposits->Next;
	}
	Deposit* Result = (*client)->Deposits;
	(*client)->Deposits = TEMP;
	return Result;
}
float Money_Now(Deposit* deposit, int year, int month, int day) {
	float dif;
	switch (deposit->Period) {
	case 1: return deposit->Initial_deposit + (deposit->Initial_deposit * (deposit->Interest_rate / 100) * (year - deposit->start.year));
	case 2: return deposit->Initial_deposit + (deposit->Initial_deposit * (deposit->Interest_rate / 100) * (((year - deposit->start.year)) * 12 + abs(deposit->start.month - month)) / 4);
	case 3: return deposit->Initial_deposit + (deposit->Initial_deposit * (deposit->Interest_rate / 100) * (year - deposit->start.year) * 12 + abs(deposit->start.month - month));
	case 4: if (deposit->start.day > day)dif = monthdays(deposit->start.month, deposit->start.year) - deposit->start.day + day; else dif = day - deposit->start.day;  return deposit->Initial_deposit + (deposit->Initial_deposit * (deposit->Interest_rate / 100) * ((2020 - deposit->start.year) * 52 + abs(deposit->start.month - month) * 4 + dif / 7));
	}
}
void Add_deposit(Client** person, Deposit** deposit) {
	if ((*person)->Deposits == NULL) {
		(*deposit)->Next = NULL;
		(*person)->Deposits = (*deposit);
	}
	else
	{
		Deposit* TEMP = (*person)->Deposits;
		while ((*person)->Deposits->Next) {
			(*person)->Deposits = (*person)->Deposits->Next;
		}
		(*deposit)->Next = NULL;
		(*person)->Deposits->Next = CheckDeposit();
		(*person)->Deposits->Next = (*deposit);
		(*person)->Deposits = TEMP;

	}

}
void Initialize_Operation(float money, _operation** operation) {
	if ((*operation) == NULL) {
		(*operation) = CheckOperation();
		(*operation)->when = Today;
		(*operation)->Next = NULL;
		(*operation)->money = money;
	}
	else {
		_operation* temp = (*operation);
		while ((*operation)->Next) {
			(*operation) = (*operation)->Next;
		}
		(*operation)->Next = CheckOperation();
		(*operation)->Next->when = Today;
		(*operation)->Next->Next = NULL;
		(*operation)->Next->money = money;
		(*operation) = temp;
	}
}
char* Curr(_currency cur) {

	if (cur == 1) return "BYN";
	else if (cur == 2) return "RYB";
	else if (cur == 3) return "USD";
	else return "EUR";

}
char* Per(_period per) {
	if (per == 1) return "Ежегодно";
	else if (per == 2) return "Ежеквартально";
	else if (per == 3) return "Ежемесячно";
	else  return "Еженедельно";
}
char* Categ(_category cat) {
	if (cat == 1) return "Условный";
	else if (cat == 2) return "До востребования";
	else if (cat == 3) return "Срочный депозит. Сбережение";
	else return "Срочный депозит. Накопление";
}
void Print(Client* person) {

	Deposit* temp = person->Deposits;
	printf("\n       %-14d | %-14s %-14s %-14s  ", person->Personal_Account_Number, person->Passport.Surname, person->Passport.Name, person->Passport.Father_name);
	for (int i = 0; i < person->amount_deposits; i++) {

		printf("\n%d) Сумма на вкладе: %f", i + 1, person->Deposits->Initial_deposit);
		printf("\nПроцентная ставка: %f", person->Deposits->Interest_rate);
		printf("\nДенежная единица: %s", Curr(person->Deposits->Currency));
		printf("\nПериод начисления: %s", Per(person->Deposits->Period));
		printf("\nКатегория вклада: %s\n", Categ(person->Deposits->Category));
		person->Deposits = person->Deposits->Next;
	}
	person->Deposits = temp;
}
void Delete_Client(Client* client) {
	if (Person != 0) {
		if (Person->Personal_Account_Number == client->Personal_Account_Number) {
			List.Head = Person->Next;
			free(Person);
			Person = List.Head;
		}
		else {

			while (Person->Next->Personal_Account_Number != client->Personal_Account_Number) {
				Person = Person->Next;
			}
			Client* Temp = Person->Next->Next;
			free(Person->Next);
			Person->Next = Temp;
			Person = List.Head;
			free(Temp);
		}
		List.amount--;
		ListInFile();
	}
	else printf("\nСписок пуст\n");
}
void Delete_deposit(Client** client) {
	if (Person != NULL) {
		if ((*client)->Deposits != 0) {

			Print((*client));
			printf("Какой вклад удалить? ");
			int choice = Choice((*client)->amount_deposits);
			switch (Sure()) {
			case 1:
				if ((*client)->amount_deposits == 1) {
					(*client)->Deposits = NULL;

				}
				else if (choice == 1) {
					Deposit* Temp = (*client)->Deposits;
					(*client)->Deposits = (*client)->Deposits->Next;
					free(Temp);
				}
				else {
					Deposit* Temp = (*client)->Deposits;
					if (choice == (*client)->amount_deposits) {
						while ((*client)->Deposits->Next->Next) {
							(*client)->Deposits = (*client)->Deposits->Next;
						}
						Deposit* temp = (*client)->Deposits->Next;
						(*client)->Deposits->Next = NULL;
						free(temp);

					}
					else {
						for (int i = 0; i < choice - 1; i++) {
							(*client)->Deposits = (*client)->Deposits->Next;
						}
						Deposit* temp = (*client)->Deposits->Next;
						(*client)->Deposits->Next = (*client)->Deposits->Next->Next;
						free(temp);
					}
					(*client)->Deposits = Temp;

				};
				(*client)->amount_deposits--;
				if ((*client)->amount_deposits == 0)Delete_Client((*client)); break;
				ListInFile();

			case 2: Main_Menu(); break;
			}
		}
	}
	else {
		printf("\nСписок пуст\n");
	}

}
void Add_Client(Client* client) {
	if (Person == NULL) {
		Person = CheckClient();
		Person = client;
		List.Head = List.Tail = Person;
		Person->Next = NULL;
	}
	else {
		while (Person->Next) {
			Person = Person->Next;
		}
		Person->Next = client;
		Person->Next->Next = NULL;
		List.Tail = Person->Next;
		Person = List.Head;

	}
	List.amount++;
}
void Add() {
	printf("\nГлавное меню -> Операции с вкладами -> Добавление вклада...\n");
	printf("\n1.Новому клиенту\n2.Существующему клиенту\n3.Вернуться назад");
	switch (Choice(3)) {
	case 1:Input(); break;
	case 2: if (Person != NULL) { Client* Temp = Find_Client(); Temp->amount_deposits++; Input_deposit(&Temp); }
		  else {
		printf("\nСписок пуст, нажмите Enter,чтобы продолжить");
		rewind(stdin);
		getchar();
		Add();
	}; break;
	case 3: DepositMenu(); break;
	}
	ListInFile();
}
void Calculating(Client** client) {
	_date Date_;
	Print((*client));
	printf("\nВведите новую дату (например 23.06.2020) ");
	Date(&Date_);
	printf("\nВыберите вклад ");
	Deposit* TEMP = (*client)->Deposits;
	int choice = Choice((*client)->amount_deposits) - 1;
	for (int i = 0; i < choice; i++) {
		(*client)->Deposits = (*client)->Deposits->Next;
	}
	float sum = Money_Now((*client)->Deposits, Date_.year, Date_.month, Date_.day);
	printf("\nБудущее состояние вклада: %f %s ", sum, Curr((*client)->Deposits->Currency));
	(*client)->Deposits = TEMP;
}
void Supplement(Client** client) {
	Deposit* TEMP = (*client)->Deposits;
	printf("\nКакой вклад вы хотите пополнить ");
	int choice = Choice((*client)->amount_deposits) - 1;
	for (int i = 0; i < choice; i++) {
		(*client)->Deposits = (*client)->Deposits->Next;
	}
	if ((*client)->Deposits->Category != 3) {
		float sum;
		printf("\nНа этом вкладе денежная единица измеряется в %s.", Curr((*client)->Deposits->Currency));
		printf("\nСколько клиент хочет добавить на вклад?: ");
		while (!(scanf_s("%f", &sum))) {
			printf("\nВы допустили ошибку при вводе, повторите попытку");
			rewind(stdin);
		}
		switch (Sure()) {
		case 1:
			(*client)->Deposits->Initial_deposit = Money_Now((*client)->Deposits, Today.year, Today.month, Today.day) + sum;
			Initialize_Operation((*client)->Deposits->Initial_deposit, &((*client)->Deposits->Operation));
			(*client)->Deposits->amount_of_operation++;
			(*client)->Deposits = TEMP;
			ListInFile();
			break;
		case 2:; break;
		}
	}
	else {
		printf("\nКатегория этого вклада не допускает пополнения");
		(*client)->Deposits = TEMP;


	}
}
void Get_Cash(Client** client) {
	printf("\nС какого вклада вы хотите снять деньги ");
	Deposit* TEMP = Find_D(&(*client));
	printf("\nНа этом вкладе денежная единица измеряется в %s.", Curr(TEMP->Currency));

	if (TEMP->Category == 2 || TEMP->Category == 3) {
		float money;
		printf("\nСколько клиент хочет снять:  ");
		while (!scanf_s("%f", &money))
		{
			printf("\nПри вводе была допущена ошибка, повторите попытку ");
			rewind(stdin);
		}
		switch (Sure()) {
		case 1:

			if ((TEMP->Category == 2 && money < Money_Now(TEMP, Today.year, Today.month, Today.day)) || (TEMP->Category == 3 && money < (Money_Now(TEMP, Today.year, Today.month, Today.day) - TEMP->Initial_deposit))) {
				TEMP->Initial_deposit = Money_Now(TEMP, Today.year, Today.month, Today.day) - money;
				Initialize_Operation(TEMP->Initial_deposit, &(TEMP->Operation));
				TEMP->amount_of_operation++;
				ListInFile();
			}
			else {
				printf("\nНе достаточно средств для снятия");

			}; break;
		case 2:; break;
		}
	}
	else printf("\nКатегория данного вклада не позволяет снимать деньги");
}
int Choice(int amount) {
	printf("\nПоле для ввода :");
	int choice;
	while (!(scanf_s("%d", &choice)) || (choice > amount || choice < 1)) {
		printf("\nВы ввели недопустимое значение. Пожалуйста повторите ввод:  ");
		rewind(stdin);
	}
	return choice;
}
int Main_Menu() {

	printf("\n \tМеню \n");
	printf("1.Операции с вкладами\n2.Перевод денег\n3.Просмотр списка клиентов\n4.Отчёты\n5.Помощь\n6.Выход");
	return Choice(6);
}
void DepositMenu()
{

	int p = 1;
	Client* TEMP;
	while (p == 1) {
		printf("\nГлавное меню -> Операции с вкладами...\n ");
		printf("\n1.Поиск вклада по номеру лицевого счета\n2.Добавление вклада\n3.Удаление вклада\n4.Помощь\n5.Вернуться в главное меню\n6.Выход");
		switch (Choice(6)) {
		case 1: Menu1(); break;
		case 2:Add(); break;
		case 3:TEMP = Find_Client(); Delete_deposit(&TEMP); break;
		case 4:; break;
		case 5:main(); break;
		case 6:Exit(); break;

		}
	}
}
void Menu1() {
	if (Person != NULL) {

		printf("\nГлавное меню -> Операции с вкладами -> Поиск вклада по номеру лицевого счёта...\n");
		Client* client = Find_Client();
		Print(client);
		int p = 1;
		while (p == 1) {
			ListInFile();
			printf("\n1.Удаление вклада\n2.Пополнение вклада\n3.Снятие денег с вклада\n4.Высчитать сумму вклада на определенную дату\n5.Помощь\n6.Вернуться назад\n7.Выйти");
			switch (Choice(7)) {
			case 1:Delete_deposit(&client); break;
			case 2:Supplement(&client); break;
			case 3:Get_Cash(&client); break;
			case 4:Calculating(&client); break;
			case 5:Help(); break;
			case 6:DepositMenu(); break;
			case 7:Exit(); break;
			}

		}
	}
	else printf("\nСписок пуст");
}
void View_Client_List() {
	if (Person != NULL) {

		printf("\nНомер лицевого счёта  | Ф.И.О.:                                        ");
		while (Person) {
			Print(Person);
			Person = Person->Next;
		}
		Person = List.Head;
	}
	else {
		printf("\nСписок клиентов пуст");
	}
}
void ListInFile() {
	FILE* fin = fopen("Clients.bin", "wb");
	if (fin) {
		while (Person) {
			fwrite(Person, sizeof(Client), 1, fin);
			Deposit* Temp = Person->Deposits;
			for (int i = 0; i < Person->amount_deposits; i++) {
				fwrite(Person->Deposits, sizeof(Deposit), 1, fin);
				_operation* temp = Person->Deposits->Operation;
				for (int j = 0; j < Person->Deposits->amount_of_operation; j++) {
					fwrite(Person->Deposits->Operation, sizeof(_operation), 1, fin);
					Person->Deposits->Operation = Person->Deposits->Operation->Next;
				}
				Person->Deposits->Operation = temp;
				Person->Deposits = Person->Deposits->Next;
			}
			Person->Deposits = Temp;

			fputc('\n', fin);
			Person = Person->Next;
		}
		Person = List.Head;
	}
	fclose(fin);
}
void ListFromFile() {
	FILE* fout = fopen("Clients.bin", "rb");
	if (fout) {
		char* temp;
		int count = 0;
		while (!feof(fout)) {
			if (fgetc(fout) == '\n')
				count++;
		}
		fseek(fout, 0, 0);
		for (int i = 0; i < count; i++) {
			Client* TEMP = CheckClient();
			fread(TEMP, sizeof(Client), 1, fout);
			TEMP->Deposits = NULL;
			for (int i = 0; i < TEMP->amount_deposits; i++) {
				Deposit* Temp = CheckDeposit();
				fread(Temp, sizeof(Deposit), 1, fout);
				Temp->Operation = NULL;
				for (int j = 0; j < Temp->amount_of_operation; j++) {
					_operation* temp = CheckOperation();
					fread(temp, sizeof(_operation), 1, fout);
					Add_Operation(&Temp, &temp);
				}
				Add_deposit(&TEMP, &Temp);
			}
			Add_Client(TEMP);
			fgetc(fout);
		}
		fseek(fout, 0, 0);

		fclose(fout);
	}
}
void Transfer_Money() {
	if (Person && Person->Next) {
		printf("\nПервый клиент: ");
		Client* Client_1 = Find_Client();
		Print(Client_1);
		printf("\nВыберите вклад с которого нужно снять деньги: ");
		Deposit* deposit1 = Find_D(&Client_1);
		printf("\nВторой клиент: ");
		Client* Client_2 = Find_Client();
		Print(Client_2);
		printf("\nВыберите вклад на который перевести деньги: ");
		Deposit* deposit2 = Find_D(&Client_2);
		if (deposit1->Currency == deposit2->Currency) {
			if ((deposit1->Category == 2 || deposit1->Category == 3) && deposit2->Category != 3) {
				printf("\nВведите сумму, которую вы хотите перевести: ");
				float money;
				scanf("%f", &money);
				switch (Sure()) {
				case 1:
					if ((deposit1->Category == 2 && (money < Money_Now(deposit1, Today.year, Today.month, Today.day))) || (deposit1->Category == 3 && (money < (Money_Now(deposit1, Today.year, Today.month, Today.day) - deposit1->Initial_deposit)))) {
						deposit1->Initial_deposit = Money_Now(deposit1, Today.year, Today.month, Today.day) - money;
						deposit2->Initial_deposit = Money_Now(deposit2, Today.year, Today.month, Today.day) + money;
						Initialize_Operation(deposit1->Initial_deposit, &deposit1->Operation);
						deposit1->amount_of_operation++;
						Initialize_Operation(deposit2->Initial_deposit, &deposit2->Operation);
						deposit2->amount_of_operation++;
					}
					else {
						printf("\nНедостаточно средств.");
					}; break;
				case 2:; break;
				}

			}
			else {
				printf("\nКатегория вкладов не позволяет провести операцию");
			}

		}
		else {
			printf("\nНа вкладах деньги в разных валютах. Извините, но вы не можете провести операцию.");
		}



	}
	else {
		printf("\nВ списке недостаточно клиентов для проведения операции\n");

	}
	ListInFile();
}
void ShowReport() {
	if (Person != NULL) {
		Client* client = Find_Client();
		printf("\nВыберите вклад для отчёта: ");
		Deposit* deposit = Find_D(&client);
		printf("\nКлиент: %s %s %s.\n\tОтчёт по выбранному вкладу за последний год ", client->Passport.Surname, client->Passport.Name, client->Passport.Father_name);
		printf("\n\tСумма на вкладе - дата изменения\n");
		_operation* temp = deposit->Operation;
		while (deposit->Operation) {

			if ((Today.year - (deposit->Operation->when.year)) <= 1)
				printf("\n\t%-10f - %d.%d.%d ", deposit->Operation->money, deposit->Operation->when.day, deposit->Operation->when.month, deposit->Operation->when.year);
			deposit->Operation = deposit->Operation->Next;
		}
		printf("\n");
		deposit->Operation = temp;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	PrintTime();

	int p = 1;
	while (p == 1) {
		if (Person == NULL) {
			printf("\nВведите сегодняшнюю дату :\n");
			Date(&Today);
			ListFromFile();
		}
		rewind(stdin);
		switch (Main_Menu())
		{
		case 1:DepositMenu(); break;
		case 2:Transfer_Money(); break;
		case 3:View_Client_List(); break;
		case 4:ShowReport(); break;
		case 5:Help(); break;
		case 6:Exit(); break;

		}
	}
	return 0;
}

