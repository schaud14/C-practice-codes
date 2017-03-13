#include <stdio.h>
#include <math.h>
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
	printf("score is : %d\n",random_no);
	random_no=random_no + t1->handicap;
	printf("score is : %d\n",random_no);
	return (random_no);
}

/* function game() returns winner between two */
struct team* game(struct team *t1,struct team *t2)
{
	t1->score=getScore(t1);
	t2->score=getScore(t2);

	if (t1->score > t2->score)
	{
		fprintf(stderr, "%-15s\t %-15s\t %-15s\n",t1->buffer,t2->buffer,t1->buffer );		
		return t1;
	}
	else if (t1->score < t2->score)	
		{
			fprintf(stderr, "%-15s\t %-15s\t %-15s\n",t1->buffer,t2->buffer,t2->buffer );
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
						fprintf(stderr, "Team 1\t\t Team 2 \t\t Winner\n-------------------------------------------------------\n" );
						count=2;
					}
					winner[index]=game(tt1[index],tt1[index+4]);
				}


			if (index>3 && index<6)
				{
					if (count==2)
						{
						fprintf(stderr, "\n-----------Round 2 -------:\n");
						fprintf(stderr, "Team 1\t\t Team 2 \t\t Winner\n-------------------------------------------------------\n" );
						count=3;
						}	
						//fprintf(stderr,"-------------------------------------------------------\n" );
					winner[index] = game (winner[index-2],winner[index-2-2]);
				}


			if (index==6)
				{
					if (count==3)
						{
						fprintf(stderr, "\n-----------Round 3-------:\n");
						fprintf(stderr, "Team 1\t\t Team 2 \t\t Winner\n-------------------------------------------------------\n" );
						count++;	
						}
						//fprintf(stderr, "-------------------------------------------------------\n");
					winner[index] = game (winner[index-1],winner[index-2]);
				}
		}
	
	return winner[6];
}


int main() 
{
	int index;
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
	fprintf(stderr, "tournament Winner is %s\n", tournamentWinner->buffer );
	
	return 0;
	
}


