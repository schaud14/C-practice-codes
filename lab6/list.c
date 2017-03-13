#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*--------- Vector Methods ---------*/

struct Vector * createVector()
{
	struct Vector * ptr = malloc (sizeof(struct Vector));
	if (ptr==NULL)
		exit(-1);
	
	ptr->list=NULL;
	ptr->maximum_size=0;
	ptr->current_size=0;
	return ptr;
}

void vectorInsertInc(struct Vector * V, int index, struct Data struct_value)
{
	if (V==NULL)
	{
		struct Data * L = malloc (1*sizeof(struct Data));
		V->list=L;
		V->current_size++;
		V->maximum_size++;
	}
	else
	{
		if (V->maximum_size > index)
		{
			V->list[index] = struct_value;
			V->current_size++;
		}
		else
		{	
			//while(V->maximum_size >= index)
				V->maximum_size++;
			struct Data * NL = malloc (V->maximum_size*sizeof(struct Data));
			memcpy(NL,V->list,V->current_size*sizeof(struct Data));
			free(V->list);
			V->list=NL;
			V->list[index]=struct_value;
			V->current_size++;
		}
	}
}

void vectorInsertGeo(struct Vector * V, int index, struct Data struct_value)
{
	if (V->maximum_size==0)
	{
		struct Data * L = malloc (1*sizeof(struct Data));
		V->list=L;
		V->current_size++;
		V->maximum_size++;
	}
	else
	{
		if (V->maximum_size > index)
		{
			V->list[index] = struct_value;
			V->current_size++;
		}
		else if (V->maximum_size <= index)
		{	
			//while (V->maximum_size >= index)
				V->maximum_size = V->maximum_size*2;
			struct Data * NL = malloc (V->maximum_size*sizeof(struct Data));
			memcpy(NL,V->list,V->current_size*sizeof(struct Data));
			free(V->list);
			V->list=NL;	
			V->list[index]=struct_value;
			V->current_size++;
		}
	}
}

void vectorRemove(struct Vector * V, int index)
{
	if (index < 0)
	{
		fprintf(stderr, "Index cannot be negative\n" );
	}
	else if (index <= V->current_size)
		{
			V->list[index].data=EMPTY;
		}
	else if (index > V->current_size)
		{
			fprintf(stderr, "Index Out of bound\n" );
		}
} 

int vectorRead(struct Vector * V, int index)
{
	if (index >= V->current_size)
		return -1;
	else
		return V->list[index].data;
}

void displayVector(struct Vector * V)
{
	int index=0;
	fprintf(stderr, "maximum_size is %d\n",V->maximum_size );
	while (index <= V->current_size)
	{
		fprintf(stderr, "%d\t",V->list[index] );
		index++;
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "current_size is %d\n",V->current_size );
	
	
}


/*--------- Linked List Methods ---------*/


struct List * newList()
{
    struct List * temp=malloc(sizeof(struct List));
    if( temp == NULL )
	{
		fprintf(stderr, "There is not enough space to allocate\n" );
		exit(0);	
	}

    temp->head=NULL;
    return temp;
}


struct Node * newNode(struct Data * d)
{
	struct Node * temp = malloc(sizeof(struct Node));
		if( temp == NULL )
		{
			fprintf(stderr, "There is not enough space to allocate\n" );
			exit(0);
		}
	temp->data_ptr=d;
	temp->next=NULL;
	temp->previous=NULL;
	return temp;
}

void listInsert( struct List * list, struct Data * data_ptr )
{
	struct Node * current = list->head;
	struct Node * p = newNode( data_ptr );
	if( current == NULL )
	{
		list->head = p;
		p->previous=NULL;
	}
	else
	{

		//printf( "current->next = %s\n", current->next );
		while(current->next != NULL)
		{
			current = current->next;
 
		}
		p->previous = current;
		current->next = p;
	}
	
}

int listIndexinsert( struct List * list, int insertion_index, struct Data * data_ptr )
{
	//fprintf(stderr, "%d\n",data_ptr->data);
	if( insertion_index < 1 )
	{
		fprintf(stderr, "The insertion index is out of bound\n" );
		return 0;
	}
	int index = 1, count = 0;
	struct Node * current = list->head;
	struct Node * n_node = newNode( data_ptr );
	struct Node * temp;
	if( current == NULL )
	{
		fprintf(stderr,"There is no node in the list to insert\n");
		return -1;
	}
	else
	{
		if( insertion_index == 1 )
		{			
			current->previous = n_node;
			n_node->next = current;
			list->head = n_node;
		}
		else
		{
			while( ( current->next != NULL ) && ( index < ( insertion_index - 1 ) ) )
			{
				current = current->next;
				temp = current;
				index = index + 1;
				count++;
			}

			if( index < ( insertion_index - 1 ) )
			{
				fprintf(stderr, "Unable to find the Insert index\n" );
				free(n_node->data_ptr);
				free(n_node);
				return -1;		
			}
			else
			{
				n_node->next = current->next;
				n_node->previous = temp;
				current->next = n_node;
			}
		}
	}
	//free(n_node->data_ptr);
	//free(n_node);
	//fprintf(stderr, "%d\n",data_ptr->data);
	return 1;
}

void display_list( struct List * list  )
{
	
	struct Node * current = list->head;
	int count = 1;
	fprintf(stderr, "List -> Head ->" );
	while( current != NULL )
	{
		fprintf(stderr, " [ %d : %d] -> ", count, current->data_ptr->data );
		current = current->next;
		count++;
	}
	fprintf(stderr, "NULL \n" );
}



void display_listb( struct List * list  )
{
	int count=1;
	struct Node * current = list->head;
	while( current->next != NULL )
	{
		current = current->next;
		count++;
	}
	fprintf(stderr, "List -> Head ->" );
	while( current != NULL )
	{
		fprintf(stderr, " [ %d : %d] -> ", count, current->data_ptr->data );
		current = current->previous;
		count--;
	}
	fprintf(stderr, "NULL \n" );
}



int listIndexDelete( struct List * list, int deletion_index )
{
	if( deletion_index < 0 )
	{
		fprintf( stderr,"The deletion index is out of bound\n" );
		return 0;
	}
	int index = 1, count = 0;
	struct Node * current = list->head;
	struct Node * d_node;
	if( current == NULL )
	{
		fprintf(stderr,"There is not node in the list to delete\n");
		return -1;
	}
	else
	{
		if( deletion_index == 1 )
		{
			d_node = current;
			if( d_node->next != NULL )
				d_node->next->previous = NULL;
			list->head = d_node->next;
		}
		else
		{
			while( ( current->next != NULL ) && ( index < ( deletion_index - 1 ) ) )
			{
				current = current->next;
				index = index + 1;
				count++;
			}

			if( index < ( deletion_index - 1 ) )
			{
				fprintf(stderr, "Unable to find the delete index\n" );
				return -1;		
			}
			else
			{
				if( current->next != NULL )
				{
					d_node = current->next;
					if( d_node->next != NULL )
						d_node->next->previous = current;
					current->next = d_node->next;
				}
				else
				{
					fprintf(stderr, "The deletion index is out of bound\n" );
					return -1;
				}
			}
		}
		free (d_node->data_ptr);
		free (d_node);
	}
	return 1;
}

void deleteList1(struct List * list)
{
	struct Node * current = list->head;
	struct Node * temp;
	while(current->next!=NULL)
	{
		list->head = current->next;
		current->next->previous=NULL;
		free(current->data_ptr);
		free(current);
		current=list->head;
	}
		free(list->head->data_ptr);
		free(list->head);
		free(list);	
}
void deleteList(struct List * list)
{
	struct Node * current = list->head;
	if (list->head ==NULL)
		free(list);

	else
	{
		while (current->next != NULL)
			current=current->next;

		while(current->previous!=NULL)
		{
				current=current->previous;
				free(current->next->data_ptr);
				free(current->next);		
		}
		free(list->head->data_ptr);
		free(list->head);
		free(list);
	}
}

struct Node * headnode( struct List * list )
{
	struct Node * current = list->head;
	if( current == NULL )
	{
		fprintf(stderr,"There is no node in the list\n");
		return current;
	}
	return current;
}


int searchForward( struct List * list, int scannum )
{
	struct Node * current = list->head;
	int count = 1;
	int steps = 1;
	while( current != NULL )
	{
		//printf( "The node at index %d has value = %d\n", count, current->data_ptr->data );
		if( current->data_ptr->data == scannum )
		{
			break;
		}
		current = current->next;
		//count++;
	}

	if( current == NULL )
	{
		fprintf(stderr, "The value was not found\n" );
	}
	else
	{
		current = list->head;
		while( current != NULL )
		{
			if( current->data_ptr->data != scannum )
			{
				//printf( "The value %d not found at index %d\n", scannum, count );
			}
			else
			{
				fprintf(stderr, "**The value %d found at index %d in %d iterations\n", scannum, count,steps );
				break;
			}
			++steps;
			current = current->next;
			++count;
		}
	}
	return 1;
}

int searchBackward( struct List * list, int scannum )
{
	int count =1,steps=1;
	struct Node * current = list->head;
	while( current->next != NULL )
	{
		current = current->next;
		count++;
	}

	
	while( current != NULL )
	{
		//printf( "The node at index %d has value = %d\n", count, current->data_ptr->data );
		if( current->data_ptr->data == scannum )
		{
			break;
		}
		current = current->previous;
		//count++;
	}

	if( current == NULL )
	{
		fprintf(stderr, "The value was not found\n" );
	}
	else
	{
		current = list->head;
		while( current->next != NULL )
		{
			current = current->next;
		}
		while( current != NULL )
		{

			if( current->data_ptr->data != scannum )
			{
				//printf( "The value %d not found at index %d\n", scannum, count );
			}
			else
			{
				fprintf(stderr, "**The value %d found at index %d in %d iterations\n", scannum, count,steps );
				break;
			}

			current = current->previous;
			--count;
			++steps;
		}
	}
	return 1;
}



/*--------- Stack and Queue Methods ---------*/

void push( struct Stack * stack, struct Data * data_ptr )
{
	struct Node * current = stack->list->head;
	struct Node * p = newNode( data_ptr );
	if( current == NULL )
	{
		stack->list->head = p;
	}
	else
	{

		//printf( "current->next = %s\n", current->next );
		while(current->next != NULL)
		{
			current = current->next;
 
		}
		current->next = p;
	}
}

int pop1( struct Stack * stack )
{
	int value;
	struct Node * temp = stack->list->head;
	if( temp == NULL )
	{
		fprintf(stderr,"Stack is empty\n");
		return -1;
	}
	else
	{
		value=temp->data_ptr->data;
		stack->list->head=temp->next;
		free(temp->data_ptr);
		free(temp);
	}
return value;
}

int push1( struct Stack * stack, struct Data * data_ptr )
{
	struct Node * current = stack->list->head;
	struct Node * new = newNode( data_ptr );
	struct Node * temp;
	if( current == NULL )
	{
		stack->list->head = new;
	}
	else
	{
	temp=stack->list->head;
	stack->list->head=new;
	new->next=temp;
	}
}

int pop( struct Stack * stack )
{
	int value;
	struct Node * current = stack->list->head;
	struct Node * temp;
	if( current == NULL )
	{
		fprintf(stderr,"Stack is empty\n");
		return -1;
	}
	else
	{
		while( ( current->next != NULL ) )
		{
			temp = current;
			current = current->next;
		}
		if (temp->next != NULL)
		{
		value = current->data_ptr->data;
		temp->next = NULL;
		free( current->data_ptr);
		free(current);
		}
		else
			if (temp->next == NULL)
			{
				value = current->data_ptr->data;
				//temp->next = NULL;
				free( current->data_ptr);
				free(current);

			}	
	}
	return value;
}



void enqueue( struct Queue * queue, struct Data * data_ptr )
{
	struct Node * current = queue->list->head;
	struct Node * p = newNode( data_ptr );
	if( current == NULL )
	{
		queue->list->head = p;
	}
	else
	{

		//printf( "current->next = %s\n", current->next );
		while(current->next != NULL)
		{
			current = current->next;
 
		}
		current->next = p;
	}
}

int dequeue( struct Queue * queue )
{
	int value;
	struct Node * current = queue->list->head;
	struct Node * temp;
	if( current == NULL )
	{
		fprintf(stderr,"Stack is empty\n");
		return -1;
	}
	else
	{
		value = current->data_ptr->data;
		temp = current->next;
		queue->list->head = temp;
	}
	free(current->data_ptr);
	free(current);
	return value;
}