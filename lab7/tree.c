#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
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


void insertNode(struct Node * node, struct Data sdata)
{
	if (sdata.value < node->data.value)  
	{
		if (node->left == NULL)
		{
			struct Node * node1 = createNode(sdata);
			node1->parent = node;
			node->left=node1;

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
			struct Node * node1 = createNode(sdata);
			node1->parent = node;
			node->right=node1;
		}
		else
		{
			insertNode(node->right,sdata);
		}
	}
}


void display(struct Node * node)
{
	if (node->parent !=NULL)
	{
		if (node->left == NULL && node->right == NULL)
		{
			fprintf(stderr, "\nNode is : %d -> parent is : %d -> left child is : %s -> right child is : %s\n",node->data.value,node->parent->data.value,"NULL","NULL");
		}
		else if (node->left != NULL && node->right == NULL)
		{
			fprintf(stderr, "\nNode is : %d -> parent is : %d -> left child is : %d -> right child is : %s\n",node->data.value,node->parent->data.value,node->left->data.value,"NULL");
		}
		else if (node->left == NULL && node->right != NULL)
		{
			fprintf(stderr, "\nNode is : %d -> parent is : %d -> left child is : %s -> right child is : %d\n",node->data.value,node->parent->data.value,"NULL",node->right->data.value);
		}
		else if (node->left != NULL && node->right != NULL)
		{
			fprintf(stderr, "\nNode is : %d -> parent is : %d -> left child is : %d -> right child is : %d  \n",node->data.value,node->parent->data.value,node->left->data.value,node->right->data.value);
		}
	}
	else if (node->parent ==NULL)
	{
		if (node->left == NULL && node->right == NULL)
		{
			fprintf(stderr, "\nRoot Node is : %d -> left child is : %s -> right child is : %s\n",node->data.value,"NULL","NULL");
		}
		else if (node->left != NULL && node->right == NULL)
		{
			fprintf(stderr, "\nRoot Node is : %d -> left child is : %d -> right child is : %s\n",node->data.value,node->left->data.value,"NULL");
		}
		else if (node->left == NULL && node->right != NULL)
		{
			fprintf(stderr, "\nRoot Node is : %d -> left child is : %s -> right child is : %d\n",node->data.value,"NULL",node->right->data.value);
		}
		else if (node->left != NULL && node->right != NULL)
		{
			fprintf(stderr, "\nRoot Node is : %d -> left child is : %d -> right child is : %d  \n",node->data.value,node->left->data.value,node->right->data.value);
		}
	}

}


struct Node * searchNode(struct Node * node1, int search_value)
{
	struct Node * temp;
	if (search_value == node1->data.value)
	{
		return node1;
	}
	else if(search_value < node1->data.value)
	{
		if (node1->left != NULL)
		{
			temp = searchNode(node1->left,search_value);
			return temp;
		}
		else
		{
			//fprintf(stderr, "%s\n","Not Found" );
			return NULL;
		}
	}
	else if(search_value > node1->data.value)
	{
		if (node1->right != NULL)
		{
			temp = searchNode(node1->right,search_value);
			return temp;
		}
		else
		{
			//fprintf(stderr, "%s\n","Not Found" );
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
		if (temp !=NULL)
			return temp;
		else
			return NULL;
	}

}


void insert(struct Tree * bst, struct Data sdata)
{
	if (bst->root == NULL)	
	{
		struct Node * node = createNode(sdata);
		bst->root = node;			
	}
	else
	{
		struct Node * temp = search(bst,sdata.value);
		if (temp != NULL)
		{
			fprintf(stderr, "%d already exists in the Binary Tree\n",sdata.value);
		}
		else
		{
			insertNode(bst->root,sdata);
		}
	}	
}


void preordertraversal(struct Node * n)
{	
	fprintf(stderr, "%d \t\n", n->data.value );
	if (n->left != NULL)
	preordertraversal(n->left);
	
	if (n->right != NULL)
	preordertraversal(n->right);
}

void inordertraversal(struct Node * n)
{	
	if (n->left != NULL)
	inordertraversal(n->left);
	
	fprintf(stderr, "%d \t\n", n->data.value );
	
	if (n->right != NULL)
	inordertraversal(n->right);
}


void postordertraversal(struct Node * n)
{	
	if (n->left != NULL)
	postordertraversal(n->left);
	
	if (n->right != NULL)
	postordertraversal(n->right);
	
	fprintf(stderr, "%d \t\n", n->data.value );
}


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
struct Node * minValueNode(struct Node * node)
{
    struct Node * current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

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


void postorderdelete(struct Tree * binaryTree, struct Node * n)
{	
	if (n->left != NULL)
	{
		postorderdelete(binaryTree,n->left);
	}
	if (n->right != NULL)
	{
		postorderdelete(binaryTree,n->right);
	}
	if (n!=binaryTree->root)
	{
		removeLeaf(n);
	}
	else
	{
		free(n);
	}
}

delete(struct Tree * bst,int delete_value)
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
void deletetree(struct Tree * bst)
{
	if (bst->root == NULL)
	{
		free(bst);
	}
	else
	{
		postorderdelete(bst,bst->root);	
		if (bst)
		{
			free(bst);
		}			
	}
	
}