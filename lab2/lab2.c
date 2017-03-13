#include <stdio.h>
#include<limits.h>

int main(){

	signed int num_min=INT_MIN,num_max=INT_MAX,num_1=2,num_2=255,num_3=32,num_4=-1,bit,temp,count=2,mask=1;
/* Printing first 20 Fibbonassi Numbers */
	printf("\n************Part 1************\n\n");

	int fibbo[20];
	fibbo[0]=0;
	fibbo[1]=1;
		
	printf("Fibbonassi Table\n\n");

	printf("      Iteration |   Fibbonassi Number\n   _____________|_____________________\n");
	printf("\t%d \t|\t %d\n",count-1,fibbo[0]);
	printf("\t%d \t|\t %d\n",count,fibbo[1]);

	while (count<20)
		{
		fibbo[count]=fibbo[count-1]+fibbo[count-2];
		printf("\t%d \t|\t %d\n",count+1,fibbo[count]);
		count++;
		}

/* Decimal to Binary Conversion of Given numbers */		
printf("\n\n************Part 2************\n\n");
printf("************Part A************\n\n");	
	
	
	printf("Decimal to binary Conversion \n");
	printf("    Decimal No  \t|   \t\tBinary Number\n   _____________________|_____________________________________________\n");
	//Converting decimal 2 to binary
	printf("\t%d \t\t|\t ",num_1);
	for (bit=31;bit>=0;bit--)
		{
		temp=num_1>>bit;
		if( temp & mask )
			{	printf("1");	}
		else
			{	printf("0");	}
		
		}
	printf("\n");
		

	//Converting decimal 255 to binary	
	printf("\t%d \t\t|\t ",num_2);
	for (bit=31;bit>=0;bit--)
		{
		temp=num_2>>bit;
		if( temp & mask )
			{	printf("1");	}
		else
			{	printf("0");	}
		
		}
	printf("\n");
	

	//Converting decimal 32 to binary	
	printf("\t%d \t\t|\t ",num_3);
	for (bit=31;bit>=0;bit--)
		{
		temp=num_3>>bit;
		if( temp & mask )
			{	printf("1");	}
		else
			{	printf("0");	}
			
		}
	printf("\n");
	

	//Converting decimal -1 to binary
	printf("\t%d \t\t|\t ",num_4);
	for (bit=31;bit>=0;bit--)
		{
		temp=num_4>>bit;
		if( temp & mask )
			{	printf("1");	}
		else
			{	printf("0");	}
		
		}
	printf("\n");
	

	//Converting decimal INT_MIN (-2147483648) to binary
	printf("\t%d \t|\t ",INT_MIN);
	for (bit=31;bit>=0;bit--)
		{
		temp=INT_MIN>>bit;
		if( temp & mask )
			{	printf("1");	}
		else
			{	printf("0");	}
		
		}
	printf("\n");
	

	//Converting decimal INT_MAX (2147483647) to binary
	printf("\t%d \t|\t ",INT_MAX);
	for (bit=31;bit>=0;bit--)
		{
		temp=INT_MAX>>bit;
		if( temp & mask )
			{	printf("1");	}
		else
			{	printf("0");	}
		
		}
	printf("\n");	

/*Printing Binary representation of any Random Number generated by rand() */
printf("\n\n************Part B************\n\n");
	
	srand((unsigned)time(0));
	int random_no = rand() * 2 + (INT_MIN);
	if(random_no<INT_MAX && random_no>INT_MIN)
		{
		printf("Random Number generated in decimal is %d\n",random_no);
		printf("Binary Conversion of generated Random Number is :  	");
		for (bit=31;bit>=0;bit--)
			{
			temp=random_no>>bit;
			if( temp & mask )
				{	printf("1");	}
			else
				{	printf("0");	}
			
			}	
		printf("\n\n\n");
		
		}	
	
	

return (0);

}	
 