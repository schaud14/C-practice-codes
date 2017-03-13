#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.c"
#include <time.h>
#include <sys/time.h>
int main()
{
	srand((unsigned) time(NULL));
	int choice, i,removeindex;
	while( 1 )
	{
		printf( "\nSelect Operation....\n" );
		printf( "1.Vectors\n2.Linked List\n3.Stack and Queue\n4.Exit\n" );
		scanf( "%d", &choice );
		if( choice == 1 ) // Vectors
		{	struct timeval start, stop;
			int flag=0;
			struct Vector * Vptr = createVector();
			struct Data data_obj;
			while(1)
			{
				printf( "\n1.Insert Incremental\n2.Insert Geometric\n3.Read Vector\n4.Remove Index\n5.Go Back\n" );
				scanf( "%d", &choice );
				if (choice==1)
				{
					int count=0;
					gettimeofday(&start, NULL);
					for (i=0;i<10000;i++)
					{
						int randnum = rand() % 100;
						//data_ptr = malloc(sizeof(struct Data));
						data_obj.data=randnum;
						vectorInsertInc(Vptr,i,data_obj);

					}
					gettimeofday(&stop, NULL);
					time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
					time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
					time_t final_time = stop_time - start_time; 
				 	double t =  difftime( stop_time,  start_time);
				 	fprintf(stderr, "Time required is : %lf\n",t );
				 	free(Vptr->list);
					free(Vptr);
				 	//printf("maximum_size of Vector is %d\n",Vptr->maximum_size );
				 	//displayVector(Vptr);
				 	break;
				}

				else if(choice ==2)
				{
					gettimeofday(&start, NULL);
					for (i=0;i<10000;i++)
					{
						int randnum = rand() % 100;
						//data_ptr = malloc(sizeof(struct Data));
						data_obj.data=randnum;
						vectorInsertGeo(Vptr,i,data_obj);
					}
					gettimeofday(&stop, NULL);
					time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
					time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
					time_t final_time = stop_time - start_time; 
				 	double t =  difftime( stop_time,  start_time);
					fprintf(stderr, "Time required is : %lf\n",t );
					free(Vptr->list);
					free(Vptr);
					//printf("maximum_size of Vector is %d\n",Vptr->maximum_size );
					//displayVector(Vptr);
					break;
				}	
				else if (choice==3)
				{
					for (i=0;i<20;i++)
					{
						if (flag==0){
						int randnum = rand() % 100;
						data_obj.data=randnum;
						vectorInsertInc(Vptr,i,data_obj);
						if (i==19)flag=1;
						}
						printf("%d\t" ,vectorRead(Vptr,i));

					}
					printf("\n");
				}	
				else if (choice==4)
				{
					printf("Enter and index to be removed\n" );
					scanf( "%d", &removeindex );
					//for (i=0;i<20;i++)
					{
						vectorRemove(Vptr,removeindex);
					}
					//displayVector(Vptr);
				}
				//printf("\n" );
				
				else
				{
					free(Vptr->list);
					free(Vptr);
					break;
				}

			}
		}
		else if( choice == 2 ) //Linked List
		{
			while( 1 )
			{
				int uinsertindex, uinsertnumber;
					struct List * lpointer = newList();
					int randnum, scannum;
					struct Data * data_ptr;
					for( i=1; i<=10; i++ )
					{
						randnum = rand() % 100;
						data_ptr = malloc(sizeof(struct Data)); 
						data_ptr->data=randnum;
						listInsert ( lpointer, data_ptr );	
					}

					printf( "\nList from front : \n" );
					display_list( lpointer );

					printf( "\nList from back\n" );
					display_listb( lpointer );

					while( 1 )
					{
						printf( "\nSelect Operation in Doubly Linked list....\n" );
						printf( "1.Insert\n2.Delete\n3.First element of List\n4.Search element in List\n5.Go Back\n" );
						scanf( "%d", &choice );

						if( choice == 1 )
						{
							//insert
							printf( "\nEnter the index to insert in the linked list...\n" );
							scanf( "%d", &uinsertindex );
							printf( "\nEnter the number to insert in the linked list...\n" );
							scanf( "%d", &uinsertnumber );
							data_ptr = malloc(sizeof(struct Data)); 
							data_ptr->data=uinsertnumber;
							listIndexinsert( lpointer, uinsertindex, data_ptr );
							printf( "\nDisplay List after insertion...\n" );
							display_list( lpointer );
						}
						else if( choice == 2 )
						{
							//delete
							printf( "\nEnter the index to delete from the linked list...\n" );
							scanf( "%d", &uinsertindex );
							listIndexDelete( lpointer, uinsertindex );
							printf( "\nDisplay List after deletion...\n" );
							display_list( lpointer );
						}
						else if( choice == 3 )
						{
							//first value
							struct Node * first = headnode( lpointer );
							if( first != NULL )
								printf( "\nThe value of first node in the linked list is %d\n", first->data_ptr->data );
						}
						else if( choice == 4 )
						{
							printf( "\nEnter the number to search in the list\n" );
							scanf( "%d", &scannum );
							printf( "\nSearch from Forward\n" );
							searchForward( lpointer, scannum );
							printf( "\nSearch from Backward\n" );
							searchBackward( lpointer, scannum );
						}
						else if( choice == 5 )
						{
							deleteList1(lpointer);
							//free(lpointer);//	
							break;
						}
					}
				break;
				}
		}
		else if( choice == 3 ) //Stack and Queue
		{
			printf( "\nelect Operation in Linked list....\n" );
			printf( "1.Stack\n2.Queue\n" );
			scanf( "%d", &choice );
			int value;
			if( choice == 1 )
			{
				//stack
				struct Stack * stack = malloc( sizeof( struct Stack ) );
				stack->list = newList();
				struct Data * data_ptr;
				printf( "Enter number to add on stack\n" );
				for( i=1; i<=5; i++ )
				{
					scanf( "%d", &value );
					data_ptr = malloc(sizeof(struct Data)); 
					data_ptr->data=value;
					push1( stack, data_ptr );
				}

				printf( "The number on stack are...\n" );
				for( i=1; i<=5; i++ )
				{
					value = pop1( stack );
					printf( "%d\n", value );
				}
				// value = stack->list->head->data_ptr->data;
				// printf("%d\n", value );
				// free(stack->list->head->data_ptr);
				// free(stack->list->head);
			free(stack->list);
			free(stack);
			}
			else
			{
				struct Queue * queue = malloc( sizeof( struct Queue ) );
				queue->list = newList();
				struct Data * data_ptr;
				printf( "Enter number to add in queue\n" );
				for( i=1; i<=5; i++ )
				{
					scanf( "%d", &value );
					data_ptr = malloc(sizeof(struct Data)); 
					data_ptr->data=value;
					enqueue( queue, data_ptr );
				}

				printf( "The number in queue are...\n" );
				for( i=1; i<=5; i++ )
				{
					value = dequeue( queue );
					printf( "%d\n", value );
				}
				free(queue->list);
				free(queue);
			}
		}
		else
		{
			if( choice != 4 ) //Exit
				printf( "The selection is invalid\n" );
			exit(0);
		}
	}
	return 0;
}