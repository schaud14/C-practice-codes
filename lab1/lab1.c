#include <stdio.h>
#include <math.h>

int main(){
printf("This is Assignment No 1: \n\n");

printf("Part A: \n\n");
//Hello World output:
        printf("Hello World!\n");
	


//Question 1:
	printf("\nQ1 : Evaluation of Arithmatic equations.\n\n");
        float val=2.55;
        double res1;
        res1=(3*pow(val,3))-(5*pow(val,2))+6;
        printf("Value of expression 3*x^3 - 5*x^2 + 6 at x=2.55 is : %lf\n",res1);
	sleep(2);

	float res2= (3.31*pow(10,-8) * 2.01*pow(10,-7))/( 7.16*pow(10,-6) + 2.01*pow(10,-8));
	printf("(3.31 * 10^-8 * 2.01 * 10^-7) / ((7.16 * 10^-6) + (2.01 * 10^-8)) = %g\n\n", res2);
	sleep(2);

//Question 2:
	printf("Finding Next Even Multiple(Manual input):\n\n" );
	int input1,input2,res3;
	printf("Enter an integer to be rounded off: ");
	scanf("%d",&input1);
	printf("Enter an integer: ");
	scanf("%d",&input2);
	res3=input1+input2-(input1%input2);
		if (res3%2==0)
			printf("Next even multiple= %d\n\n",res3);
		else
		{
			while (res3%2!=0)			
				{
				res3=res3+input2;				
				}		
			printf("Next even multiple= %d\n\n",res3);
			sleep(2);
		}

	
//Question 3:
	printf("Finding Next Even Multiple(For Provided inputs):\n\n" );
	int a1;
	int arr1[3]={365,12258,996};
	int arr2[3]={7,28,4};
	for ( a1=0;a1<3;a1++)
		{
		int res4=arr1[a1]+arr2[a1]-(arr1[a1]%arr2[a1]);
			if (res4%2==0)
				printf ("Next even multiple for %d and %d is : %d\n\n",arr1[a1],arr2[a1],res4);			
			else
				printf ("Next even multiple for %d and %d is : %d\n\n",arr1[a1],arr2[a1],res4+1);		
		sleep(2);
		}


//Question 4:
	printf("Conversion of Fahrenheit to Celcius:");
	int a2;
	float arr3[3]={100,32,-40};
	float arr4[3];
	printf("Values in degree Celcius is for given inputs of Fahrenheit are as : \n");
	printf("\tin deg Fahrenheit \t in deg Celcicus\n");
	for (a2=0;a2<3;a2++)
		{
		arr4[a2]=(arr3[a2]-32)/1.8;
		printf("\t%f \t\t %f \t\n",arr3[a2],arr4[a2]);		
		}
	sleep(2);

	
printf("\n\nPart B:\n");
//Question 5:
	long int large_num = 9838263505978427528U;
	int large_num_int=(int) large_num;
	char large_num_char=(char) large_num;
	double large_num_double=(double)large_num;

	printf("interger value(long int): %lu\n",large_num);
	printf("interger value(int): %d\n",large_num_int);
	printf("interger value(double): %.4f\n",large_num_double);
	printf("interger value(char): %c\n",large_num_char);

        getchar();
        return (0);
        }



