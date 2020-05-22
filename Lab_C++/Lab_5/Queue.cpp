//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Queue.h"
#include "Main.h"


QUEUE::~QUEUE() {

	while (Head) {
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

void QUEUE::DelN() {
	if (Head == 0) {
		ShowMessage("Error, list is empty");
		return;
	}
	Node * temp;
	temp = Head->Next;
	delete Head;
	Head = temp;
}

void QUEUE::Show() {
	Node*temp = Tail;
	temp = Head;
	while (temp != NULL) {

		temp = temp->Next;
	}
}

//---------------------------------------------------------------------------
