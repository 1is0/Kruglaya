#pragma once
#include <time.h>
typedef enum category {
	Conditional,
	On_Demand,
	Term_Deposits_Savings,
	Term_Deposits_Accumulative
}_category;
typedef enum period {
	Yearly,
	Quarterly,
	Mounthly,
	Weekly
}_period;
typedef enum currency {
	BYN,
	RYB,
	USD,
	EUR
}_currency;
typedef enum month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
}_month;
typedef struct date {
	int year;
	_month month;
	int day;

}_date;
typedef struct passport {
	char Surname[20];
	char Name[20];
	char Father_name[20];
	char Pasport_Index[20];
}_passport;
typedef struct operation {
	float money;
	_date when;
	struct operation* Next;
}_operation;
typedef struct deposit {
	_category Category;
	_period Period;
	_currency Currency;
	_operation* Operation;
	float Initial_deposit;
	_date start;
	_date end;
	float Interest_rate;
	struct deposit* Next;
	int amount_of_operation;
}Deposit;

typedef struct client {
	int Personal_Account_Number;
	Deposit* Deposits;
	_passport Passport;
	struct client* Next;
	int amount_deposits;
}Client;
typedef struct List {
	int amount;
	Client* Head;
	Client* Tail;
}ClientList;