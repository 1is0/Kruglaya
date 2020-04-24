#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>


struct tree_node
{
	char word[100];
	struct tree_node* left;
	struct tree_node* right;
};
struct tree_node* add(struct tree_node* root, char* word) {
	int temp;
	if (!root) {
		if (!(root = (struct tree_node*)malloc(sizeof(struct tree_node)))) {
			printf("Error with memory allocation");
		}
		else {
			root->left = root->right = NULL;
			strcpy(root->word, word);
		}
	}
	else if ((temp = strcmp(word, root->word)) < 0) {
		root->left = add(root->left, word);
	}
	else {
		root->right = add(root->right, word);
	}
	return root;
}
struct tree_node* CreateTree() {
	struct tree_node* Tree = NULL;
	char word[100];
	FILE* file;
	if (!(file = fopen("1.txt", "r"))) {
		printf("\nError.");
		char c = getchar();
		exit(-1);
	}


	while (fgets(word, 20, file)) {
		Tree = add(Tree, word);
	}
	fclose(file);
	return Tree;
}

int Check_Word(char* word) {
	char first = word[0];
	char last;
	int i;
	for (i = 0; word[i]; i++);
	last = word[i - 2];
	if (last == first) return 1;
	else return 0;
}
void Find(struct tree_node** Tree_1, struct tree_node** Tree_2)
{

	if ((*Tree_1) != NULL) {
		Find(&(*Tree_1)->left, &(*Tree_2));
		if (Check_Word((*Tree_1)->word)) {
			(*Tree_2) = add((*Tree_2), (*Tree_1)->word);
		}
		Find(&(*Tree_1)->right, &(*Tree_2));
	}

}

void Print_Tree(struct tree_node* tree) {
	if (tree != NULL) {
		Print_Tree(tree->left);
		printf("%s\n", tree->word);
		Print_Tree(tree->right);
	}
}

int main()
{
	struct tree_node* root = NULL;
	root = CreateTree();

	struct tree_node* Sorted_words = NULL;
	Find(&root, &Sorted_words);
	printf("Words start and end with the same letter:\n");
	Print_Tree(Sorted_words);
	return 0;
}



