//---------------------------------------------------------------------------

#ifndef MyQueueH
#define MyQueueH
#include "Queue.h"
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
//---------------------------------------------------------------------------
#endif
