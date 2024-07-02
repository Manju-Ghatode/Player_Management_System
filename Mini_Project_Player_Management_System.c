#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Player{
	int jersey_no;
	char name[20];
	int matches;
	int runs;
	int wickets;
}Player;

void createPlayer(Player*);
void displayPlayer(Player*);
void searchPlayer(Player*);
int searchByJn(Player*,int);
int searchByName(Player*,char*);
void showOnePlayer(Player*, int);
void removePlayer(Player*,int); 
int updatePlayer(Player*,int);
void sortPlayer(Player*);
void sortByRunAsc(Player*);
void sortByRunDesc(Player*);    
void sortByWicketsAsc(Player*); 
void sortByWicketsDesc(Player*);
void hardCode();

int n=5;

int main()
{
	int ch, res;
	//Player * p1;
	//Player p1[15];
	
	Player*p1 = (Player*)malloc(n*sizeof(Player));
//	Player*p1= (Player*)calloc(n,sizeof(Player));   //working   //free(p1)-to remove
//	Player*p1=(Player*)realloc(sizeof(Player)*(n+num));
	hardCode(p1);

	do
	{
		printf("\n******WELCOME HERE******\n");
		printf("\n1.To Store Data \n2.To Display Data \n3.To Search data \n4.To Remove data \n5.To Update data \n6.To Sort data \n7.To Exit \n");
		printf("\nEnter the above choice:\n");
		scanf("%d", &ch);
		if(ch>7)
		{
			printf("Invalid choice.Please enter the correct choice.");
		}
		
		switch(ch)
		{
			case 1:
					createPlayer(p1);
				break;
				
			case 2: 
					displayPlayer(p1);
				break;
				
			case 3: 
					searchPlayer(p1);
				break;
				
			case 4: 
					removePlayer(p1,n);						
				break;
	
			case 5: 
					updatePlayer(p1,n);
				break;
				
			case 6: 
					sortPlayer(p1);
				break;
				
			case 7:
					printf("Exit. \n\n-------------THANK YOU !!!!------------- \n");		
		}
	}while(ch!=7);
}

void createPlayer(Player* p1)
{
	int i,m;
	char name[20];
	printf("Enter the  number of player you want:");
	scanf("%d",&m);
	printf("\nEnter the information for %d player:\n", m);
		for(i=n; i<(n+m); i++) {
		printf("\nEnter the information for [%d] player:",i+1);
		fflush(stdin);
		printf("\nEnetr the player name:");
		gets(p1[i].name);
		fflush(stdin);
		printf("Enetr the jersey no:");
		scanf("%d", &p1[i].jersey_no);
		printf("Enetr the matches:");
		scanf("%d", &p1[i].matches);
		printf("Enetr the runs:");
		scanf("%d", &p1[i].runs);
		printf("Enetr the wickts:\n");
		scanf("%d", &p1[i].wickets);
		}	
	printf("\n-----------------------------------------------------------------------------------------\n");
	n=n+m;
}

void displayPlayer(Player* p1)
{
	int i;
	printf("\nPlaese wait.......information display within in a second.\n");

	{
		printf("\n+----------------------------------------------------------------------------------------+ ");
		printf("\n|     Name            |  Jersey_no  |  Total Matches  |  Total runs   |   Total wickets  |");
		printf("\n+----------------------------------------------------------------------------------------+");
		
		for(i=0; i<n; i++)
		printf("\n| %19s | %10d | %16d | %13d | %16d |", p1[i].name,p1[i].jersey_no,p1[i].matches, p1[i].runs,p1[i].wickets );
		
//		printf("\n\nDisplay the Information of player [%d] :", i+1);
//		printf("\nName of player: %s", p1[i].name);
//		printf("\nJersey no. of player: %d", p1[i].jersey_no);
//		printf("\nNumber of matches: %d", p1[i].matches);
//		printf("\nNumber of runs: %d", p1[i].runs);
//		printf("\nNumber of wickets: %d", p1[i].wickets);
	}
	printf("\n+-----------------------------------------------------------------------------------------+\n");	
}

void searchPlayer(Player* p1)
{
	int i;
	int a,j,res;
	char name[20];
	printf("\n1.jersey no.\n2.name:");
	printf("\nSelect  the above option to be used to search a player:\n");
	scanf("%d",&a);
	if(a==1)
		{
			printf("\nEnter the jersey no. of player which is to be search:");
			scanf("%d",&j);
			res = searchByJn(p1,j);
			if(res==-1)
			{
				printf("\nRecord not found");
				printf("\n--------------------------------------------------------------------------------------------\n");

			}
			else 
    		{
    			showOnePlayer(p1,res);
    			//printf("\n---------------------------------------------------------------------------------");
			}
	}
	else if(a==2)
	{
		printf("\nEnter the name of player which is to be search:");
		fflush(stdin);
		gets(name);
		res = searchByName(p1,name);
		if(res==-1)
		{
			printf("Record not found");
			printf("\n--------------------------------------------------------------------------------------------\n");
		}
		else 
    		{
    			showOnePlayer(p1,res);
			}
	} 
	else 
		{ 
			printf("\nSorry......Invalid Choice.....Please choose the correct option from above.");
			printf("\n--------------------------------------------------------------------------------------------\n");
		}
}
int searchByJn(Player* p1,int j)
	{	
		int i;
		for(i=0;i<n;i++)
		{
			if(p1[i].jersey_no==0)
			{ 
				return i;
			}	
		}
		return -1;
	}

int searchByName(Player* p1,char* name)
 {
 		for(int i=0;i<n;i++)
		{
			if(strcasecmp(p1[i].name,name)==0)
			{ 
				return i;
			}
		}
		return -1;
}

void showOnePlayer(Player*p1, int res)

	{
		printf("\n+----------------------------------------------------------------------------------------+");
		
		printf("\n| %19s | %10d | %16d | %13d | %16d |", p1[res].name,p1[res].jersey_no,p1[res].matches, p1[res].runs,p1[res].wickets );
	
		printf("\n+-----------------------------------------------------------------------------------------+\n");
	}

void removePlayer(Player*p1,int m)
{
	int r,flag=0;
 	printf("Enter jersey no. of player to be deleted:");
 	scanf("%d",&r);
 	int j= searchByJn(p1,r);
  	if(j==-1)
  	{
  		printf("Player not found");
  		printf("\n---------------------------------------------------------------------------------\n");
	}
  	else
	  	{
  		for(int i=j;i<n-1;i++)
  		{
			p1[i]=p1[i+1];
	  	}
	  	n--;
	  	printf("\n.........Player remove successfully...............\n");
	  	printf("\n---------------------------------------------------------------------------------\n"); 	 	
  	}
  }
	
int updatePlayer(Player* p1,int n)
{
			int j;
			printf("Enter jersey no. of a player whose data is to be updated : ");
			scanf("%d",&j);
			int i=searchByJn(p1,j);
			if(i==-1)
			{
				printf("Record Not found");
				printf("\n-----------------------------------------------------------------------------\n");
			}
			else
			{
				int nm, nr, nw;
				printf("\nEnter current no. of runs: ");
				scanf("%d",&nr);
				p1[i].runs=p1[i].runs + nr;
	
				printf("\nEnter current no. of wickets: ");
				scanf("%d",&nw);
				p1[i].wickets=p1[i].wickets + nw;

				printf("\nEnter current no. of matches: ");
				scanf("%d",&nm);
				p1[i].matches=p1[i].matches + nm;
				printf("\n--------Player information update successfully------------\n");
				printf("\n\n----------------------------------------------------------------------------------------\n");
			}	
}
	
	
void sortPlayer(Player* p1) 
{
	int op,wickets,runs,sel;
	printf("Enter the below way you want to sort the palyers:\n");
	printf("\n1.By Runs \n2.By Wickets \n");	
	scanf("%d", &op);
	if(op==1)
			{
				printf("\nIn which way you want to sort the player select below choice:\n");
				printf("\n1.In ascending way \n2.In Decsending way:\n");
				scanf("%d", &sel);
				if(sel==1)
				{
					sortByRunAsc(p1);
				}
				else if(sel==2)
				{
					sortByRunDesc(p1);
				}
    		}
    else if(op==2)
    		{
    			printf("\nIn which way you want to sort the player select below choice:\n");
				printf("\n1.In ascending way \n2.In Decsending way:\n");
				scanf("%d", &sel);
				if(sel==1)
				{
					sortByWicketsAsc(p1);
				}
				else if(sel==2)
				{
					sortByWicketsDesc(p1);
				}
			}
}

void sortByRunAsc(Player* p1)
{
	Player x[15];
	for(int i=0;i<n;i++)
	{
		x[i] = p1[i];
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i].runs>x[j].runs)
			{
				Player temp= x[i];
				x[i]= x[j];
				x[j]= temp;
			} 
		}
	}
	printf("\nLowest 3 run scorers are as follow:\n");
 	//for (i=0;i<3;i++)
 	{
		printf("\n+----------------------------------------------------------------------------------------+ ");
		printf("\n|     Name            |  Jersey_no  |  Total Matches  |  Total runs   |   Total wickets  |");
		printf("\n+----------------------------------------------------------------------------------------+");
		
		for(i=0; i<3; i++)
		printf("\n| %19s | %10d | %16d | %13d | %16d |", x[i].name,x[i].jersey_no,x[i].matches, x[i].runs,x[i].wickets );
		
 	}
 		printf("\n+------------------------------------------------------------------------------------------\n");
}

void sortByRunDesc(Player* p1)
{
	Player x[15];
	for(int i=0;i<n;i++)
	{
		x[i] = p1[i];
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i].runs<x[j].runs)
			{
				Player temp= x[i];
				x[i]= x[j];
				x[j]= temp;
			} 
		}
	}
	printf("top 3 run scorers are as follow:");
 	//for (i=0;i<3;i++)
 	{
 		printf("\n+----------------------------------------------------------------------------------------+ ");
		printf("\n|     Name            |  Jersey_no  |  Total Matches  |  Total runs   |   Total wickets  |");
		printf("\n+----------------------------------------------------------------------------------------+");
		
		for(i=0; i<3; i++)
		printf("\n| %19s | %10d | %16d | %13d | %16d |", x[i].name,x[i].jersey_no,x[i].matches, x[i].runs,x[i].wickets );
			
 	}
 		printf("\n+-----------------------------------------------------------------------------------------+\n");
}
	
void sortByWicketsAsc(Player* p1)
{
	Player x[15];
	for(int i=0;i<n;i++)
	{
		x[i] = p1[i];
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i].wickets>x[j].wickets)
			{
				Player temp= x[i];
				x[i]= x[j];
				x[j]= temp;
			} 
		}
	}
	printf("\nLowest 3 Wickets scorers are as follow:");
 	//for (i=0;i<3;i++)
 	{
 		printf("\n+----------------------------------------------------------------------------------------+ ");
		printf("\n|     Name            |  Jersey_no  |  Total Matches  |  Total runs   |   Total wickets  |");
		printf("\n+----------------------------------------------------------------------------------------+");
		
		for(i=0; i<3; i++)
		printf("\n| %19s | %10d | %16d | %13d | %16d |", x[i].name,x[i].jersey_no,x[i].matches, x[i].runs,x[i].wickets );
		
 	}
 		printf("\n+----------------------------------------------------------------------------------------+\n");
}

void sortByWicketsDesc(Player* p1)
{	
	Player x[15];
	for(int i=0;i<n;i++)
	{
		x[i] = p1[i];
	}
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(x[i].wickets<x[j].wickets)
			{
				Player temp= x[i];
				x[i]= x[j];
				x[j]= temp;
			} 
		}
	}
	printf("\nTop 3 Wickets scorers are as follow:");
 	//for (i=0;i<3;i++)
 	{
 		printf("\n+----------------------------------------------------------------------------------------+ ");
		printf("\n|     Name            |  Jersey_no  |  Total Matches  |  Total runs   |   Total wickets  |");
		printf("\n+----------------------------------------------------------------------------------------+");
		
		for(i=0; i<3; i++)
		printf("\n| %19s | %10d | %16d | %13d | %16d |",x[i].name,x[i].jersey_no,x[i].matches, x[i].runs,x[i].wickets);
			
 	}
 		printf("\n+----------------------------------------------------------------------------------------+\n");
}

void hardCode(Player *p)
	{
		strcpy(p[0].name, "Virat Kohli");
		p[0].jersey_no =101;
		p[0].matches=100;
		p[0].runs=400;
		p[0].wickets=100;
		
		strcpy(p[1].name, "M.S Dhoni");
		p[1].jersey_no =102;
		p[1].matches=23;
		p[1].runs=100;
		p[1].wickets=200;
		
		strcpy(p[2].name, "Rohit Sharma");
		p[2].jersey_no =103;
		p[2].matches=45;
		p[2].runs=170;
		p[2].wickets=370;
		
		strcpy(p[3].name, "Dip Paliwal");
		p[3].jersey_no =18;
		p[3].matches=30;
		p[3].runs=2000;
		p[3].wickets=670;
		
		strcpy(p[4].name, "Mayank Narnaware");
		p[4].jersey_no =25;
		p[4].matches=10;
		p[4].runs=150;
		p[4].wickets=60;	
	}



