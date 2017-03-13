#ifndef _TREE_H
#define _TREE_H 

struct Data
{
	int value;
};

struct Node
{
	struct Node  * left;
	struct Node * right;
	struct Node * parent;
	struct Data data;
};


struct Tree
{
	struct Node * root;
};

struct Tree * createTree();
struct Node * createNode(struct Data );
void insert(struct Tree * , struct Data );
void insertNode(struct Node * , struct Data );

struct Node * search(struct Tree * , int );
struct Node * searchNode(struct Node * , int );
struct Node * minValueNode(struct Node * );

void preordertraversal(struct Node * );
void inordertraversal(struct Node * );
void postordertraversal(struct Node *);

//void delete(struct Tree * ,int );
void removeLeaf(struct Node * );
void shortcircuit(struct Node * );
void promotion(struct Node * );

void deletetree(struct Tree * );
void postorderdelete(struct Tree * , struct Node * );


//void display(struct Tree * );

#endif