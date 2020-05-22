//---------------------------------------------------------------------------

#include "Hash.h"
#include "LabSeven.cpp"
void Hash::insertNode(int data) {
	Node*p, *p0 = new Node;
	hashTableIndex index;
	index = myhash(data);
	if ((p = new Node) == 0) {
		Form1->Memo1->Clear();
		Form1->Memo1->Lines->Add("There is error with memory allocation)");
	}
	p0 = hashTable[index];
	if (p0 != NULL) {
		if (p0->data < data) {
			p->Next = p0;
			hashTable[index] = p;
		}
		else {
			while (p0->Next)
				p0 = p0->Next;
			p0->Next = p;

		}
		p->data = data;
	}
	else {
		hashTable[index] = p;
		p->data = data;
	}

}

// ---------------------------------------------------------------------------
int Hash::myhash(int data) {
	return (data % hashTableSize);
}

// ---------------------------------------------------------------------------
void Hash::deleteNode(int data) {
	Node *p0, *p;
	hashTableIndex index;
	p0 = 0;
	index = myhash(data);
	p = hashTable[index];
	while (p && !(p->data == data)) {
		p0 = p;
		p = p->Next;
	}
	if (!p)
		return;
	if (p0)
		p0->Next = p->Next;
	else
		hashTable[index] = p->Next;
	free(p);

}

// ---------------------------------------------------------------------------
Node* Hash::findNode(int data) {
	Node*p;
	p = hashTable[myhash(data)];
	while (p && (p->data != data))
		p = p->Next;
	return p;
}

//---------------------------------------------------------------------------
