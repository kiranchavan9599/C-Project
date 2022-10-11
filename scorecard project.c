#include<stdio.h>
#include<string.h>
typedef struct player
{
	char name[20];
	int runs;
	int ball_played;
	int dot,one,two,three,four,six;
	float strike_rate;
	float over;
    int maiden;	
	int runs_given;
	int wickets;
	float economy;
		
}player;
void search_player(player*  , int );
void best_stike_rate(player*  , int );
void best_economy(player*  , int );
void maxsix(player*  , int );
void maxfour(player*  , int );
void maxwickets(player*  ,  int);
void maxrun(player*  , int );
void display_bowler(player* , int );
void store_details(player*  , int );
void display_batsman(player*  , int );
void main()
{
	player arr[100];
	int t;
	printf("Add a No. Of Players : ");
	scanf("%d",&t);
	printf("\n");
	store_details(arr,t);
	int choice;
	
	do
	{
		    printf("\n\n");
			printf("\n==================*WELCOME*==========================");
			printf("\n1. Batsman Scorecard");
			printf("\n2. Bowler Scorecard");
			printf("\n3. Maximum Runs");
			printf("\n4. Maximum 4s");
			printf("\n5. Maximum 6s ");
			printf("\n6. Maximum Wickets");
			printf("\n7. Best Strike Rate");
			printf("\n8. Best Economy");
			printf("\n9. Search Player");
			printf("\n10. Erase Previous Data And Add New Data");
			printf("\n11. Exit");
			printf("\n======================================================");
			printf("\n");
				printf("\nEnter a Choice : ");
	            scanf("%d",&choice);
	            
	            switch (choice)
	            {
	            	case 1 : display_batsman(arr , t);
	            	break;
	            	
	            	case 2 : display_bowler( arr ,  t);
	            	break;
	            	
	            	case 3 : maxrun( arr ,  t);
	            	break;
	            	
					case 4 : maxfour( arr , t );
	            	break;
	            	
	            	case 5 : maxsix( arr , t );
	            	break;
	            	
	            	case 6 : maxwickets( arr , t );
	            	break;
	            	
	            	case 7 : best_stike_rate( arr , t );
	            	break;
	            	
	            	case 8 : best_economy( arr , t );
	            	break;
	            	
	            	case 9 : search_player( arr ,  t);
	            	break;
	            
	            	case 10 : 
	            	
	            		    printf("***************************************");
	            		    printf("\n");
	            		    printf("\nEnter a No. Of Players : ");
	                        scanf("%d",&t);
	                        store_details(arr,t);
					        
	                 break;       
						
	            	case 11 :
	            	 printf("***************************************");
	            	 printf("\n");
					 printf("\n*****Thanks For Visiting*****");
	            	break;
	            	
	            	default: printf("Wrong Choice. Enter again\n");
                    break;
				}
				
	}
	while(choice!=11);
	


		
}
void store_details(player* arr , int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		printf("\n");
		printf("=============* ENTER DETAILS *=================");
		printf("\n");
		printf("\n%d). Enter a Player Name : ",i+1);		
		scanf("%s",&arr[i].name);
		printf("--------------------------------");
		printf("\nEnter a Dots Boll : ");
		scanf("%d",&arr[i].dot);
		printf("Enter a Runs Of Singles : ");
		scanf("%d",&arr[i].one);
		printf("Enter a Runs Of Doubles : ");
		scanf("%d",&arr[i].two);
		printf("Enter a Runs Of Three : ");
		scanf("%d",&arr[i].three);
		printf("Enter a Runs Of four : ");
		scanf("%d",&arr[i].four);
		printf("Enter a Runs Of six : ");
		scanf("%d",&arr[i].six);
		printf("------------------------------");
		printf("\nEnter a Over : ");
		scanf("%f",&arr[i].over);
		printf("Enter a Maiden Over : ");
		scanf("%d",&arr[i].maiden);
		printf("\nEnter Run Given : ");
		scanf("%d",&arr[i].runs_given);
		printf("\nEnter a Wicket Taken : ");
		scanf("%d",&arr[i].wickets);
		printf("\n");
    }
}
void display_batsman(player* arr , int t)
{

	int i;
	printf("\n");
	printf("===================*BATTING SCORECARD*=======================");
	printf("\nBatter\tR\tB\t4s\t6s\tSR");
	for(i=0;i<t;i++)
	{
		arr[i].runs=arr[i].one*1+arr[i].two*2+arr[i].three*3+arr[i].four*4+arr[i].six*6;
		arr[i].ball_played=arr[i].dot+arr[i].one+arr[i].two+arr[i].three+arr[i].four+arr[i].six;
		
		if(arr[i].runs==0)
		{
			arr[i].strike_rate=0;
		}
		else
		{
			arr[i].strike_rate=100*arr[i].runs/arr[i].ball_played;
		}
		
printf("\n%s\t%d\t%d\t%d\t%d\t%0.1f",arr[i].name,arr[i].runs,arr[i].ball_played,arr[i].four,arr[i].six,arr[i].strike_rate);
	
	
	}
}
void display_bowler(player* arr, int t)
{
	int i;
	printf("\n===================*BOWLING SCORECARD*=======================");
	printf("\nBowler\tO\tM\tR\tW\tER");
	for(i=0;i<t;i++)
	{
		
			
		if(arr[i].over==0)
		{
			arr[i].economy=0;
		}
		else
		{
		
			arr[i].economy=arr[i].runs_given/arr[i].over;	
		}
		printf("\n%s\t%0.1f\t%d\t%d\t%d\t%0.2f",arr[i].name,arr[i].over,arr[i].maiden,arr[i].runs_given,arr[i].wickets,	arr[i].economy);
		
	}
}
void maxrun(player* arr , int t)
{
	int max=0;
	int i ;
	char y[20];
	for(i=0;i<t;i++)
	{
		arr[i].runs=arr[i].one*1+arr[i].two*2+arr[i].three*3+arr[i].four*4+arr[i].six*6;
		
		if(arr[i].runs>max)
		{
			max=arr[i].runs;
		}
	}
	for(i=0;i<t;i++)
	{
		if(max==arr[i].runs)
		{
			strcpy(y,arr[i].name);
		
		}
	}
	printf("\n\n");	
	printf("**********************************************");
	printf("\nMaximum Run Made By %s ",y);
	printf("He Made %d Run ",max);
	printf("\n*********************************************");
	
	
	
}
void maxwickets(player* arr , int t)
{
	int max=0;
	int i ;
	char y[20];
	for(i=0;i<t;i++)
	{
		
		if(arr[i].wickets>max)
		{
			max=arr[i].wickets;
		}
	}
		
	for(i=0;i<t;i++)
	{
		if(max==arr[i].wickets)
		{
			strcpy(y,arr[i].name);
		
		}
	}
	printf("\n\n");	
	printf("****************************************************");
	printf("\nMaximum Wicket  Taken By %s ",y);
	printf("He take %d Wickets ",max);
	printf("\n***************************************************");

}
void maxfour(player* arr , int t)
{
	int max=0;
	int i ;
	char y[20];
	for(i=0;i<t;i++)
	{
	
		if(arr[i].four>max)
		{
			max=arr[i].four;
		}
	}
		
	for(i=0;i<t;i++)
	{
		if(max==arr[i].four)
		{
			strcpy(y,arr[i].name);
		
		}
	}
	printf("\n\n");	
	printf("********************************************");
	printf("\nMaximum Four  Hit By %s ",y);
	printf("He Hits %d four",max);
	printf("\n********************************************");

}
void maxsix(player* arr , int t)
{
	int max=0;
	int i ;
	char y[20];
	for(i=0;i<t;i++)
	{
	
		if(arr[i].six>max)
		{
			max=arr[i].six;
		}
	}
		
	for(i=0;i<t;i++)
	{
		if(max==arr[i].six)
		{
			strcpy(y,arr[i].name);
		
		}
	}
	printf("\n\n");	
	printf("****************************************************");
	printf("\nMaximum six  Hit By %s ",y);
	printf("He Hits %d six",max);
	printf("\n****************************************************");

}
void best_stike_rate(player* arr , int t)
{
	float max=0;
	int i,j ;
	char y[20];
	
	for(i=0;i<t;i++)
	{	arr[i].runs=arr[i].one*1+arr[i].two*2+arr[i].three*3+arr[i].four*4+arr[i].six*6;
		arr[i].ball_played=arr[i].dot+arr[i].one+arr[i].two+arr[i].three+arr[i].four+arr[i].six;
		
		if(arr[i].runs==0)
		{
			arr[i].strike_rate=0;
		}
		else
		{
			arr[i].strike_rate=100*arr[i].runs/arr[i].ball_played;
		}
		
		
		if(arr[i].strike_rate>max)
		{
			max=arr[i].strike_rate;
		}
	
	}
	
		
					
	for(i=0;i<t;i++)
	{
		if(max==arr[i].strike_rate)
		{
			strcpy(y,arr[i].name);
			j=i;
		
		}
	}
	printf("\n\n");
	printf("************************************************************");
	printf("\n@@@@@@@@ Best Strike Rate @@@@@@@@@");
	printf("\nName : %s ",arr[j].name);
	printf("\nTotal Runs he Made : %d",arr[j].runs);
	printf("\nTotal Ball He Played : %d",arr[j].ball_played);
	printf("\n Strike Rate : %0.1f ",arr[j].strike_rate);
	
	printf("\n************************************************************");
}
void best_economy(player* arr , int t)
{
		float min=arr[0].economy;
	int i ,j;
	char y[20];
	for(i=0;i<t;i++)
	{
	  
		
		if(arr[i].over==0)
		{
			arr[i].economy=0;
		}
		else
		{
			arr[i].economy=arr[i].runs_given/arr[i].over;	
		}
	
		
		if(arr[i].economy<min)
		{
			min=arr[i].economy;
		}
	}
		
	for(i=0;i<t;i++)
	{
		if(min==arr[i].economy)
		{
			strcpy(y,arr[i].name);
			j=i;
		
		}
	}
	printf("\n\n");	
	printf("****************************************************");
	printf("\n@@@@@@@@ Best Economy @@@@@@@@@");
	printf("\nName : %s ",arr[j].name);
	printf("\nOver : %0.1f",arr[j].over);
	printf("\nRun Given  : %d",arr[j].runs_given);
	printf("\nEconomy : %0.1f ",arr[j].economy);
	printf("\n**************************************************");
	
}
void search_player(player* arr , int t)
{
	
	char s_name[20];
	printf("\n");
	int f=1;
	printf(" Player Details You Need : ");
	scanf("%s",&s_name);
	int i;
	for(i=0;i<t;i++)
	{
		arr[i].runs=arr[i].one*1+arr[i].two*2+arr[i].three*3+arr[i].four*4+arr[i].six*6;
		arr[i].ball_played=arr[i].dot+arr[i].one+arr[i].two+arr[i].three+arr[i].four+arr[i].six;
		if(arr[i].over==0)
		{
			arr[i].economy=0;
		}
		else
		{
			arr[i].economy=arr[i].runs_given/arr[i].over;	
		}
		
		
		if(arr[i].runs==0)
		{
			arr[i].strike_rate=0;
		}
		else
		{
			arr[i].strike_rate=100*arr[i].runs/arr[i].ball_played;
		}
		
		
		if(stricmp(arr[i].name,s_name)==0)
		{  
		    printf("\n");
		printf("=============* PLAYERS DETAILS *=================");
		printf("\n");
		printf("\nPlayer Name : %s ",arr[i].name);
		printf("\n");
				
		printf("\n------------* Batting Details *------------------");
		printf("\nTotal Runs  : %d",arr[i].runs);
		printf("\nBall Played : %d",arr[i].ball_played);
		printf(" \nFour : %d",arr[i].four);
		printf("\nSix : %d",arr[i].six);
		printf("\nStrike Rate : %0.1f",arr[i].strike_rate);
		printf("\n");
		
		printf("\n------------* Bowling Details *------------------");
		printf("\nOver : %0.1f",arr[i].over);
		printf("\nEnter a Maiden Over : %d",arr[i].maiden);
		printf("\nRun Given : %d",arr[i].runs_given);
		printf("\nWicket Taken : %d ",arr[i].wickets);
		printf("\nEconomy : %0.1f",arr[i].economy);
		
		printf("\n");
		f=0;

	

	   }
    }
    if(f==1)
	{
		printf(" Record Not Found! Please Enter correct Name.");
	}
}


