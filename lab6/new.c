// #ifndef TREE_H
// #define TREE_H 
/*
----- Structure Definations
*/
#include <stdio.h>
#include <stdlib.h>

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

//#endif

/*
----- Method declarations
*/


// struct Tree * createTree();
// struct Node * createNode(struct Data );
// void insert(struct Tree * , struct Data );
// void insertNode(struct Node * , struct Data );

// struct Node * search(struct Tree * , int );
// struct Node * searchNode(struct Node * , int );
// struct Node * minValueNode(struct Node * );

// void preordertraversal(struct Node * );
// void inordertraversal(struct Node * );
// void postordertraversal(struct Node *);

// void delete(struct Tree * ,int );
// void removeLeaf(struct Node * );
// void shortcircuit(struct Node * );
// void promotion(struct Node * );

// void deletetree(struct Tree * );
// void postorderdelete(struct Tree * , struct Node * );


// void display(struct Tree * );




/*
----- Constructors
*/

struct Tree * createTree()
{
	struct Tree * newTree = malloc ( sizeof(struct Tree) );
	newTree -> root = NULL;
	return newTree;
}

struct Node * createNode(struct Data sdata)
{
	struct Node * newNode =  malloc ( sizeof (struct Node) );
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = sdata;
	return newNode;
}

/*
----- Insert Finctions
*/




void insertNode(struct Node * node, struct Data sdata)
{
	if (sdata.value < node->data.value)  
	{
		if (node->left == NULL)
		{
			struct Node * node = createNode(sdata);
			node->parent = node;
			node->left=node;

		}
		else
		{
			insertNode(node->left,sdata);
		}

	}
	else if (sdata.value > node->data.value)
	{
		if (node->right == NULL)
		{
			struct Node * node = createNode(sdata);
			node->parent = node;
			node->right=node;
		}
		else
		{
			insertNode(node->right,sdata);
		}
	}
}

void insert(struct Tree * bst, struct Data sdata)
{
	if (bst->root == NULL)	
	{
		/* --- Inserting at root node --- */
		struct Node * node = createNode(sdata);
		bst->root = node;			
	}
	else
	{
		/* --- Check for existing node --- */
		struct Node * temp = search(bst,sdata.value);
		if (temp != NULL)
		{
			fprintf(stderr, "%d already exists in the Binary Tree\n",sdata.value);
		}
		else
		{
		/* --- Inserting node --- */	
			insertNode(bst->root,sdata);
		}
	}	
}

/*
----- Search Methods
*/




struct Node * searchNode(struct Node * node, int search_value)
{
	struct Node * temp;
	if (search_value == node->data.value)
	{
		return node;
	}
	else if(search_value < node->data.value)
	{
		if (node->left != NULL)
		{
			temp = searchNode(node->left,search_value);
			return temp;
		}
		else
		{
			fprintf(stderr, "%s\n","Not Found" );
			return NULL;
		}
	}
	else if(search_value > node->data.value)
	{
		if (node->right != NULL)
		{
			temp = searchNode(node->right,search_value);
			return temp;
		}
		else
		{
			fprintf(stderr, "%s\n","Not Found" );
			return NULL;
		}
	}
}

struct Node * search(struct Tree * bst, int search_value)
{
	struct Node * temp;
	if (bst->root == NULL)
	{
		fprintf(stderr, "%s\n", "Tree Is EMPTY");
		return NULL;
	}
	else
	{
		temp = searchNode(bst->root,search_value);	
		return temp;
	}

}

/*--- function to find the successor node while deleting the two branch node ---*/
struct Node * minValueNode(struct Node * node)
{
    struct Node * current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}


/*
----- Traversal Methods
*/

/*--- Preorder Traversal ---*/
void preordertraversal(struct Node * node)
{	
	fprintf(stderr, "%d \t\n", node->data.value );
	if (node->left != NULL)
	preordertraversal(node->left);
	
	if (node->right != NULL)
	preordertraversal(node->right);
}

/*--- Inorder Traversal ---*/
void inordertraversal(struct Node * node)
{	
	if (node->left != NULL)
	inordertraversal(node->left);
	
	fprintf(stderr, "%d \t\n", node->data.value );
	
	if (node->right != NULL)
	inordertraversal(node->right);
}

/*--- Postorder Traversal ---*/
void postordertraversal(struct Node * node)
{	
	if (node->left != NULL)
	postordertraversal(node->left);
	
	if (node->right != NULL)
	postordertraversal(node->right);
	
	fprintf(stderr, "%d \t\n", node->data.value );
}

/*
----- Delete Methods for deleting node
*/

/*--- Delete function to call appropriate delete function ---*/


/*--- delete function to remove leaf node ---*/
void removeLeaf(struct Node * node)
{	
	struct Node * temp_parent = node->parent;
	if (temp_parent->left == node)
	{
		temp_parent->left = NULL;	
	}
	else if (temp_parent->right == node)
	{
		temp_parent->right = NULL;
	}
	free(node);
}

/*--- delete function to remove one branch node ---*/
void shortcircuit(struct Node * node)
{
	struct Node * temp_parent= node->parent;
	if(node->left == NULL)
	{
		if (temp_parent->left == NULL)
		{
			temp_parent->left = node->right;
		}
		else
		{	
			temp_parent->right= node->right;
		}
	}
	else
		if (temp_parent->right == NULL)
		{
			temp_parent->left = node->left;
		}
		else
		{	
			temp_parent->right= node->left;
		}
	free (node);
}


/*--- delete function to delete two branch node ---*/
void promotion(struct Node * node)
{
	struct Node * temp = minValueNode(node->right);	
	node->data.value = temp->data.value;
	if (temp->left == NULL && temp-> right != NULL)	
		shortcircuit(temp);
	else if (temp->left != NULL && temp-> right == NULL)	
		shortcircuit(temp);
	else if (temp->left == NULL && temp-> right == NULL)
		removeLeaf(temp);
}

void delete(struct Tree * bst,int delete_value)
{
	struct Node * delete_node = search(bst,delete_value);
	if (delete_node == NULL)
	{
		fprintf(stderr, "%s %d\n","No Node Found with value",delete_value );
	}
	else
	{
		if (delete_node->left == NULL && delete_node->right == NULL)
		{
			removeLeaf(delete_node);
		}
		else if(delete_node->left == NULL && delete_node->right != NULL)
		{
			shortcircuit(delete_node);
		}
		else if(delete_node->left != NULL && delete_node->right == NULL)
		{
			shortcircuit(delete_node);
		}
		else if(delete_node->left != NULL && delete_node->right != NULL)
		{
			promotion(delete_node);
		}

	}
}
/*
----- Delete Methods for deleting whole Binary Tree
*/

/*--- delete function to delete the binary tree with all nodes ---*/

/*--- delete function to delete all nodes in the binary seach tree ---*/
void postorderdelete(struct Tree * binaryTree, struct Node * node)
{	
	if (node->left != NULL)
	{
		postorderdelete(binaryTree, node->left);
	}
	if (node->right != NULL)
	{
		postorderdelete(binaryTree, node->right);
	}
	if (node != binaryTree->root)
	{
		removeLeaf(node);
	}
	else
	{
		free(node);
	}
}
void deletetree(struct Tree * bst)
{
	if (bst->root == NULL)
	{
		free(bst);
	}
	else
	{
		postorderdelete(bst,bst->root);
		if (bst->root == NULL)
		{
			free(bst);
		}			
	}
}


/*
----- 
*/

void display(struct Tree * bst)
{
	if (bst->root==NULL)
	{
		fprintf(stderr, "%s\n", "Tree Is EMPTY");
	}
	else
	{	

	}
}


int main()
{
	FILE * fptr=fopen("data.txt","r");
	struct Tree * binaryTree =  createTree();
	struct Data file_data;
	int input = 0;
  	int choice;
  	int delete_value;
  	int search_value;
  	
	while(1)
	{
		fprintf(stderr, "Enter choice to operate on Binary Tree\n" );
		fprintf(stderr, "1. Create Tree\n2. Insert Node\n3. Travarsal\n4. Delete Node\n5. Search Node\n6. Display\n7. Delete Tree and Exit\n" );
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
			{
				while (!feof (fptr))
			    {  
			    	fscanf (fptr, "%d", &input);      
			    	file_data.value=input;
			    	insert(binaryTree,file_data);
			    }
			    fprintf(stderr, "%s\n","Binary Tree Created using values in data.txt" );
			    break;
			}
			case 2:
			{
				fprintf(stderr, "Insert value to be inserted\n");	
				scanf ("%d", &input);      
			    file_data.value=input;
			    insert(binaryTree,file_data);
				break;
			}	
			case 3:
			{
				fprintf(stderr, "\nInsert Choice to select type of Travarsal\n");
				while (1)
				{	
					fprintf(stderr, "1. Preorder Traversal\n2. Inorder Traversal\n3. Postorder Traversal\n4. Back\n" );
					scanf("%d",&choice);
					switch (choice)
					{
						case 1:
						{ 
							fprintf(stderr, "%s\n","Preorder traversal is as follows:" );
							preordertraversal(binaryTree->root);
							fprintf(stderr, "\n");
							break;
						}
						case 2:
						{
							fprintf(stderr, "%s\n","Inorder traversal is as follows:" );	
							inordertraversal(binaryTree->root);
							fprintf(stderr, "\n");
							break;
						}
						case 3:
						{
							fprintf(stderr, "%s\n","Postorder traversal is as follows:" );	
							postordertraversal(binaryTree->root);
							fprintf(stderr, "\n");
							break;
						}
						case 4:
						{
							break;
						}
					}		
					break;
				}
				break;
			}

			case 4:
			{
				fprintf(stderr, "Enter value of node to be deleted\n" );	
				scanf("%d",&delete_value);
				delete(binaryTree,delete_value);
				break;
			}
			case 5:
			{
				fprintf(stderr, "Enter value to be searched in Binary Tree\n" );	
				scanf("%d",&search_value);
				search(binaryTree,search_value);
				break;
			}
			case 6:
			{
				// Display Binary Tree
				break;
			}
			case 7:
			{
				fclose(fptr);
				deletetree(binaryTree);
				//free(binaryTree->root);
				//if(binaryTree)
				//	free(binaryTree);
				exit(0);
			}
		}

	}
	return 0;
}