#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/* Defining enum */
enum months
{
	January,February,March,April,May,June,July,August,September,October,November,December

};

int numSeconds(int , int , int );
/* Defining time Structure */
struct time
{
	int hours;
	int minutes;
	int seconds;
}timex[8],tdiff[4];

/* Function to calculate time difference */
struct time time_diff (struct time t1,struct time t2)
{
	struct time tdiff;
	int sec1,sec2,diff;
	sec1=numSeconds(t1.hours,t1.minutes,t1.seconds);
	sec2=numSeconds(t2.hours,t2.minutes,t2.seconds);
	if (sec1>sec2)	
		{
			diff=sec1-sec2;
		}
	else
		{
			diff=sec2-sec1;
		}

	if (diff < 60)
		{
			tdiff.hours=0;
			tdiff.minutes=0;
			tdiff.seconds=diff;
		}
	if (diff < 59 && diff < 3600)
		{
			tdiff.hours=0;
			tdiff.minutes= (int)(diff/60);
			tdiff.seconds=	diff - (int)tdiff.minutes*60;
		}
	
	if	(diff>3599)
		{
			tdiff.hours=(int)diff/3600;
			tdiff.minutes=(int)(diff/60-tdiff.hours*60);
			tdiff.seconds=diff - tdiff.hours*3600 - tdiff.minutes*60;
		}
	return tdiff;
}

/* Defining dateTime Structure */
struct dateTime
{
	enum months month;
	int day;
	int year;
	struct time timedate;
}dt[3];

/* Print Function for dateTime Structure */
void printdt(struct dateTime dt)
{
switch (dt.month){
	case 0: {printf("January %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 1: {printf("February %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 2: {printf("March %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 3: {printf("April %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 4: {printf("May %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 5: {printf("June %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 6: {printf("July %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 7: {printf("August %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 8: {printf("September %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 9: {printf("October %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 10: {printf("November %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	case 11: {printf("December %d %d %d:%02d\n", dt.day,dt.year, dt.timedate.hours,dt.timedate.minutes);break;}
	default: {printf("Error");}}
}



/* Structure for Team */
struct team
{
	int handicap;
	char* buffer;
	int score;
};

/* Function to Calculate scores */
int getScore(struct team *t1)
	{
	
	int random_no = rand() % 100;
	random_no=random_no + t1->handicap;
	return (random_no);
}

/* function game() returns winner between two */
struct team* game(struct team *t1,struct team *t2)
{
	t1->score=getScore(t1);
	t2->score=getScore(t2);

	if (t1->score > t2->score)
	{
		fprintf(stderr, "%-15s(%03d)\t %-15s(%03d)\t %-15s\n",t1->buffer,t1->score,t2->buffer,t2->score,t1->buffer );		
		return t1;
	}
	else if (t1->score < t2->score)	
		{
			fprintf(stderr, "%-15s(%03d)\t %-15s(%03d)\t %-15s\n",t1->buffer,t1->score,t2->buffer,t2->score,t2->buffer );
			return t2;
		}
		else
			game(t1,t2);
		

}

/*Function tournament() returns winner of the tournament */
struct team* tournament(struct team *tt1[])
	{
		int index ,count=1;
		struct team *winner[7];		
		for (index=0;index<8;index++)
		{	
			if (index<4)
				{	if (count==1)
					{
						fprintf(stderr, "\n-----------Round 1 -------:\n");
						fprintf(stderr, "Team 1\t\tScore \t Team 2 \tScore\t Winner\n------------------------------------------------------------\n" );
						count=2;
					}
					winner[index]=game(tt1[index],tt1[index+4]);
				}


			if (index>3 && index<6)
				{
					if (count==2)
						{
						fprintf(stderr, "\n-----------Round 2 -------:\n");
						fprintf(stderr, "Team 1\t\tScore \t Team 2 \tScore\t Winner\n------------------------------------------------------------\n" );
						count=3;
						}	
					winner[index] = game (winner[index-2],winner[index-2-2]);
				}


			if (index==6)
				{
					if (count==3)
						{
						fprintf(stderr, "\n-----------Round 3-------:\n");
						fprintf(stderr, "Team 1\t\tScore \t Team 2 \tScore\t Winner\n------------------------------------------------------------\n" );
						count++;	
						}
						winner[index] = game (winner[index-1],winner[index-2]);
				}
		}
	
	return winner[6];
}




/* Main Function */
int main()
{	int index,itr=0;

	timex[0].hours=1;timex[0].minutes=30;timex[0].seconds=45;
	timex[1].hours=16;timex[1].minutes=30;timex[1].seconds=45;
	timex[2].hours=1;timex[2].minutes=23;timex[2].seconds=01;
	timex[3].hours=12;timex[3].minutes=11;timex[3].seconds=12;
	timex[4].hours=00;timex[4].minutes=01;timex[4].seconds=01;
	timex[5].hours=23;timex[5].minutes=59;timex[5].seconds=59;
	timex[6].hours=12;timex[6].minutes=00;timex[6].seconds=00;
	timex[7].hours=12;timex[7].minutes=00;timex[7].seconds=00;
	
	dt[0].month=January;dt[0].day=19;dt[0].year=1809;dt[0].timedate.hours=12,dt[0].timedate.minutes=01;
	dt[1].month=November;dt[1].day=11;dt[1].year=1922;dt[1].timedate.hours=6,dt[1].timedate.minutes=00;
	dt[2].month=January;dt[2].day=6;dt[2].year=2000;dt[2].timedate.hours=8,dt[2].timedate.minutes=22;


	tdiff[0]=time_diff(timex[0],timex[1]);
	tdiff[1]=time_diff(timex[2],timex[3]);
	tdiff[2]=time_diff(timex[4],timex[5]);
	tdiff[3]=time_diff(timex[6],timex[7]);


fprintf(stderr, "/****************************** Part 1 ******************************/\n" );
fprintf(stderr, "/****************************** Part A ******************************/\n\n" );	
	int i=0;
	for (index=0 ; index<4; index++,itr+=2)
		{
		fprintf(stderr,"Time Difference between %02d:%02d:%02d and %02d:%02d:%02d is %02d:%02d:%02d\n",timex[itr].hours,timex[itr].minutes,timex[itr].seconds,timex[itr+1].hours,timex[itr+1].minutes,timex[itr+1].seconds, tdiff[index].hours,tdiff[index].minutes,tdiff[index].seconds);
		}
fprintf(stderr, "/****************************** Part B ******************************/\n\n" );
	printdt(dt[0]);
	printdt(dt[1]);
	printdt(dt[2]);
fprintf(stderr, "\n/****************************** Part 2 ******************************/\n\n" );	

	srand((unsigned)time(0));
	struct team *league[8];

	for (index=0;index<8;index++)
	{
		league[index]=malloc(sizeof(struct team));
	}
	
	league[0]->buffer = "India";league[0]->handicap =25;league[0]->score=0;
	league[1]->buffer = "Australia";league[1]->handicap =10;league[1]->score=0;
	league[2]->buffer = "South Africa";league[2]->handicap =5;league[2]->score=0;
	league[3]->buffer = "Shrilanka";league[3]->handicap =5;league[3]->score=0;
	league[4]->buffer = "New Zeland";league[4]->handicap =0;league[4]->score=0;
	league[5]->buffer = "Pakistan";league[5]->handicap =0;league[5]->score=0;
	league[6]->buffer = "Irland";league[6]->handicap =-5;league[6]->score=0;
	league[7]->buffer = "USA";league[7]->handicap =-10;league[7]->score=0;
	
	fprintf(stderr, "Starting tournament:\n"); 
		
	struct  team *tournamentWinner = tournament(league);
	fprintf(stderr, "-------------------------------------------------------\n");
	
	fprintf(stderr, "\n Tournament Winner is %s\n", tournamentWinner->buffer );

	return 0;
}

/* Function to Calcuate Number of seconds in given time */
int numSeconds(int hours, int minutes, int seconds)
{
	int total_sec=(hours*60*60)+(minutes*60)+(seconds);
	return total_sec;
}
