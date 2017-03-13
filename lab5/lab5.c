#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 30
#define JEDI_SIZE 6
int heap_usage=0;


/* Structure Definition*/
struct Names
{
	char *first_name;
	char *last_name;
	char *jedi_name;
};

/*------------Function to allocate memory to a pointer-------------*/
void * allocate(unsigned int size1)
{
	void * temp=malloc(size1);
		if (temp)
			{
				heap_usage=heap_usage+size1;
				//fprintf(stderr, "Memory allocated in this call : %d Heap usage used :%d\n",size1,heap_usage);
				return temp;
			}
		else
			{
				fprintf(stderr, "Error in allocation");
				return NULL;
			}	
}


/*------------Function to deallocate memory from a pointer-------------*/
void * deallocate(void * temp,unsigned int size1)
{
	if (temp)
	{
		free(temp);
		heap_usage=heap_usage-size1;
		//fprintf(stderr, "Memory deallocated in this call : %d Heap usage used :%d\n",size1,heap_usage);
		return NULL;
	}
	else
	{
		fprintf(stderr, "Invalid Pointer" );
		return NULL;
	}
}


/*-------------Function accepting a structure to Find jedi name for values in same-------------*/
struct Names jediname(struct Names name)
	{	
		int iter,iter1;
		for (iter=0;iter<3;iter++)
			{
				name.jedi_name[iter]=name.last_name[iter];
			}
		for (iter1=0;iter1<2;iter1++)
			{
				name.jedi_name[iter+iter1]=name.first_name[iter1];
			}
		name.jedi_name[iter+iter1]='\0';
		return name;
	}



int main()
{		
		size_t size=100;
		fprintf(stderr, "\nAt The start..Total Heap used: %d bytes\n\n",heap_usage);
		char *line=allocate(size);
		fprintf(stderr, "\nBefore Reading File...Total Heap used: %d bytes\n\n",heap_usage);
		fprintf(stderr, "\nLine No\t\tFirst Name\t\t\tLast Name \t\t\t\tJedi Name \t\t\tTotal Heap_usage\n");
		fprintf(stderr, "--------------------------------------------------------------------------------------------------------------------------------------------\n");
		int line_number=0;
		FILE* ptr=fopen("names.txt","r");
		struct Names name[85];


/*--------------File Rading Starts----------------*/
while(-1 != getline(&line, &size, ptr))
    {
    	
    	int iter=0,iter1=0;
    	name[line_number].first_name=allocate(NAME_SIZE);
    	name[line_number].last_name=allocate(NAME_SIZE);
    	name[line_number].jedi_name=allocate(JEDI_SIZE);
    		while (line[iter] != ',')
    			{
 	   				name[line_number].first_name[iter]=line[iter];
    				iter++;
    			}
    		if (line[iter]==',')
    			{
    				iter++;
       				while (line[iter] != '\n')
   					{
   						name[line_number].last_name[iter1]=line[iter];
   						iter++;iter1++;
    				}
    				name[line_number].last_name[iter1-1]='\0';
    			} // End of Inner While...First and last name Extracted
    			

    			/*----------------Call to Jediname()-----------------*/
		if (strlen(name[line_number].first_name)>1 && strlen(name[line_number].last_name)>2 )	
    		{	
    			name[line_number]=jediname(name[line_number]);
    			fprintf(stderr, "%-15d%-35s%-35s\t%-35s%-15d\n",line_number+1,name[line_number].first_name,name[line_number].last_name,name[line_number].jedi_name,heap_usage);
    		}
				
				/*----------------If length of names is not sufficient then no call to jediname() and prints "Invalid name"-----------*/    	
    	else
    		{
    		fprintf(stderr, "%-15d%-35s%-35s\tInvalid Name\t\t\t   %-15d\n",line_number+1,name[line_number].first_name,name[line_number].last_name,heap_usage);
   			}
   	
   		++line_number;
   	} //End Of outer While..File Reading end!!

	printf("\nAt End of file..Total Heap used: %d bytes\n", heap_usage);
	fclose(ptr);

/*-------------- Deallocation Of Memory ----------------*/

	int iter,heap_usage_old=heap_usage;
	for (iter=0;iter<line_number;iter++)
		{
			name[iter].first_name=deallocate(name[iter].first_name,NAME_SIZE);
			name[iter].last_name=deallocate(name[iter].last_name,NAME_SIZE);
			name[iter].jedi_name=deallocate(name[iter].jedi_name,JEDI_SIZE);
		}

	deallocate(line,size);
	fprintf(stderr, "\nTotal Heap freed: %d bytes\n\nAt the End..Total Heap used: %d bytes\n\n",heap_usage_old-heap_usage,heap_usage);
	return 0;
}
