//---------------------------------------------------------------------------


#include "MyQueue.h"
#include "Queue.h"
#include "Main.h"
// ---------------------------------------------------------------------------
Node* My_QUEUE::Find_Max() {
	Node*Temp = Head;
	Node* MAX = Head;
	while (Head->Next) {
		if (Head->Next->data > MAX->data) {
			MAX = Head->Next;
		}
		Head = Head->Next;
	}
	Head = Temp;
	return MAX;
}

// ---------------------------------------------------------------------------
Node* My_QUEUE::Find_Min() {
	Node* MIN = Head;
	Node*Temp = Head;
	while (Head->Next) {
		if (Head->Next->data < MIN->data) {
			MIN = Head->Next;
		}
		Head = Head->Next;
	}
	Head = Temp;
	return MIN;
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void My_QUEUE::Insert_QUEUE(My_QUEUE* Input, Node*First, Node*Last) {

	bool Position = 0;
	Node* Temp = Head;

	Head = First;
	while (Head) {
		if (Head == Last) {
			Position = 1;
		}
		Head = Head->Next;
	}
	Head = Temp;

	if (Position) {
		First->Next = (*Input).Head;
		(*Input).Head->Prev = First;
		Last->Prev = (*Input).Tail;
		(*Input).Tail->Next = Last;
	}
	else {
		Last->Next = (*Input).Head;
		(*Input).Head->Prev = Last;
		First->Prev = (*Input).Tail;
		(*Input).Tail->Next = First;
	}
	Head = Temp;
}

// ---------------------------------------------------------------------------
//---------------------------------------------------------------------------

