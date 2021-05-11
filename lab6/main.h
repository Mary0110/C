typedef struct tnode
{
  int data;           
  struct tnode *left;  
  struct tnode *right; 
}tnode;

void AddToSearchTree(tnode* node, void (*AddSearchNode)(int, tnode**), tnode** root);
void AddSearchNode(int data, tnode** node);
void AddNode(int data, tnode** node);
void printTree(tnode* node);