//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#ifndef QueueH
#define QueueH
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
//---------------------------------------------------------------------------
#endif
