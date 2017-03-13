#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
	FILE * fptr=fopen("data.txt","r");
	struct Tree * binaryTree = createTree();
	struct Data file_data;
	int input = 0;
  	int choice;
  	int delete_value;
  	int search_value;
  	
	while(1)
	{
		fprintf(stderr, "Enter choice to operate on Binary Tree\n" );
		fprintf(stderr, "1. Create Tree\n2. Insert Node\n3. Travarsal\n4. Delete Node\n5. Search Node\n6. Delete Tree and Exit\n" );
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
				struct Node * temp = search(binaryTree,search_value);
				if (temp != NULL)
					display(temp);
				else
					fprintf(stderr, "%s\n","Node Not Present in Tree" );
				break;
			}
			case 6:
			{
				fclose(fptr);
				deletetree(binaryTree);	
				exit(0);
			}
		}

	}
	return 0;
}