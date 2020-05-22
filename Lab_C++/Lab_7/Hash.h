//---------------------------------------------------------------------------

#ifndef HashH
#define HashH

#include <System.Classes.hpp>
#include "LabSeven.h"
typedef int hashTableIndex;
typedef struct Node_ {
	int data;
	struct Node_* Next;

} Node;

class Hash {
public :

	int myhash(int);
	void deleteNode(int);
	Node* findNode(int);
    void insertNode(int);

};
//---------------------------------------------------------------------------
#endif
