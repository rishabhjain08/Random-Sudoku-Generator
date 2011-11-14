#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>


int gotoxy(int,int);

int xcord=110;

////////////////////////////////////////////////////////////////////////////
						//			  //
int line,x,y,l;					//	    MACROS	  //
						//			  //
						////////////////////////////
#define hline for(line=1;line<=64;line++)\
		printf("%c",95);


#define vline(x,y,l)	for(line=1;line<=l;line++)\
			{\
			gotoxy(x,y+line-1);\
			printf("%c",124);\
			}
			
			

#define dashhline 	for(line=1;line<=64;line++)\
			printf("~");
		
#define dashvline(x,y,l,type)	for(line=1;line<=l;line++)\
				{\
				gotoxy(x,y+line-1);\
				if(type==1)\
				printf("{");\
				else\
				printf("}");\
				}
						////////////////////////////
						//			  //	
						//	END OF MACROS	  //
						//			  //			
////////////////////////////////////////////////////////////////////////////	
			          
			           
/////////////////////////////////////////////////////////////////////////////
									/////
struct locate								/////
		{				/////////////////////////////
		int x,y;			//			/////
		}location;			//     Declarations	/////
						//			/////
struct retrace					/////////////////////////////
		{							/////
		int _i,_j;						/////
		}fretrace;						/////
									/////
struct linearization							/////
		{							/////
		int itsi,itsj,linearval;				/////
		}linear[82];						/////
									/////
									/////
struct retrace func(int *,int,int);					/////
									/////
int linearval(int,int);							/////
									/////
int check(int,int);							/////
									/////
struct locate grid(int,int);						/////
									/////
int s[10][10];								/////
									/////
//int linear[82];							/////
									/////
int welcome[10][10];							/////
									/////
int a[10][10];								/////
									/////
int filla[10][10];							/////
									/////
int initial();								/////
									/////
char getch(void);							/////
									/////
int output(void);							/////
									/////
int viewthesol(void);							/////
									/////
int makeasudoku(void);							/////
									/////
int fillthesudoku(void);						/////
									/////
int filling[10][10];							/////
									/////
int diff,removenum;							/////
									/////
/////////////////////////////////////////////////////////////////////////////







int initial()

	{

	int _i_,_j_;

			for(_i_=1;_i_<=9;_i_++)
				{
					for(_j_=1;_j_<=9;_j_++)
						{
							welcome[_i_][_j_]=0;
						}
				}


///////////////////////////for loop to convert 2-D array into linear one////////////////////////////

int position=0;

			for(_i_=1;_i_<=9;_i_++)
				{
					for(_j_=1;_j_<=9;_j_++)
						{
							position++;
				
								linear[position].itsi=_i_;
								linear[position].itsj=_j_;
						
										linear[position].linearval=position;
						}
				}	

/////////////////////////////////////////////////////////////////////////////////////////////////

//array for filling

			for(_i_=1;_i_<=9;_i_++)
				{
					for(_j_=1;_j_<=9;_j_++)
						{
							filling[_i_][_j_]=0;
						}
				}
			
////////////////////////////////////////////////////////////////////////////////////////////////

			for(_i_=1;_i_<=9;_i_++)
				{
					for(_j_=1;_j_<=9;_j_++)
						{
							s[_i_][_j_]=1;
						}
				}
			
////////////////////////////////////////////////////////////////////////////////////////////////

			for(_i_=1;_i_<=81;_i_++)
	
				linear[_i_].linearval=0;

////////////////////////////////////////////////////////////////////////////////////////////////	
	
	
	}













///////////////////////////////////main function starts////////////////////////////////////





char name[40];

int rep=0;





int main()

{


srand((unsigned)time(NULL));



////////to initialize element of welcome array to zero//////

			initial();
			
///////////////////////////////////////////////////////////

/////////////////////////////////////////////////menu////////////////////////////////////////////////////////////////
															
															
while(rep==0)
{															system("clear");

printf("\nSUDOKU\n");

hline

printf("\n\n1. NEW GAME");

printf("\n\n2. INSTRUCTIONS");

printf("\n\n3. ABOUT");

printf("\n\n4. EXIT\n");


printf("\n\nEnter your choice : ");
char c=getch();

while(c>52||c<49)
c=getch();

system("clear");

switch(c)

	{
	
case '1':


printf("The programm generates a random sudoku and allows user to fill it\n\n");
	printf("Enter your name : ");
		gets(name);

printf("\n\nSelect the difficulty level : ");
printf("\n\n\n1. Beginner");
printf("\n\n2. Mature");
printf("\n\n3. Expert");
printf("\n\n\nEnter your choice : ");
diff=40+(getch()-49)*3;

while(diff!=40&&diff!=43&&diff!=46)
diff=40+(getch()-49)*3;


printf("\n\n\nHi! %s. Please wait while the programm generates a sudoku.\n\n\nIt will roughly take 5-10 seconds.",name);
	printf("\n\n\nPress any key to continue.........");
		getch();

rep=1;

system("clear");

break;


case '2':

printf("\nINSTRUCTIONS");

printf("\n");
hline
printf("\n");

printf("\n1. Scoring is done out of 100 and for every wrong entry 1 is deducted.");

printf("\n\n2. The user should use the following keys to navigate inside the sudoku\n\n\n\n");

printf("				W	\n");
printf("\n			A	S	D");

printf("\n\n\n\n3. Press I whilie playing to view the Instructions");

printf("\n\n4. Press F while playing to automatically fill the sudoku");

printf("\n\n5. Press V while playing to view the solution of sudoku");

printf("\n\n6. Press E while playing to exit the game");

getch();

break;


case '3':

printf("\nABOUT");

printf("\n");
hline
printf("\n");

printf("\n1. This program uses the computer to generate a random sudoku using the logics of sudoku.");
printf("\n\n2. The number of numbers being removed is also random and the positions where the zeros occur is also random.\n\n");
printf("3. This game has three levels of difficulty viz. Beginner, Mature, Expert.");

getch();

system("clear");


printf("\nMADE BY");

printf("\n");
hline
printf("\n");

printf("\nRISHABH JAIN");

printf("\n\nUndergraduate, Computer Science and Engineering Department, IIT Delhi");

printf("\n\nEmail-id : rishabhiitd10@gmail.com");

getch();

break;



case '4':

exit(2);




}//end of switch

}//end of while


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


s[1][1]=1+rand()%9;

//

int i,j;

for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
			{
							
			
					int dontrepeat[9]={0,0,0,0,0,0,0,0,0};
			
				while(check(i,j)==0)
			
					{ 
					
						newm:{}
					
							////////////////////
					
						int _count_=0,_k_;
			
						for(_k_=0;_k_<=8;_k_++)
			
								{
								if(dontrepeat[_k_]>=1)
								_count_++;
								}
					
			
						if(_count_==9)
				
						{
							i=func(dontrepeat,i,j)._i;
							j=func(dontrepeat,i,j)._j;
						}

						///////////////////
	
						 int m;
				
							 while(1)
						
							 {
							 m=rand()%9;
							 if(dontrepeat[m]==0)
							 break;
							 }
					 
						
						dontrepeat[m]++;
							if(dontrepeat[m]>1)
									goto newm;

									   
					s[i][j]=1+m;
					
				}

			}
	}

//


//recheck after sudoku has been made
int wow=0;

int i__1,j__1;

for(i__1=1;i__1<=9;i__1++)
{
for(j__1=1;j__1<=9;j__1++)
{
if(check(i__1,j__1)==1)
wow++;
}
}

if(wow!=81)
main();


makeasudoku();


}//end of main









int check(int i,int j)

	{

		int number=0,count=0;

			int _i,_j;
			
			for(_i=grid(i,j).y;_i<grid(i,j).y+3;_i++)
				{
	
					for(_j=grid(i,j).x;_j<grid(i,j).x+3;_j++)
						{
	
						if(s[i][j]!=s[_i][_j])
						count++;
							

						number++;

						if(_i==i&&_j==j)
						goto out;



						}
						
				}



	out:{}


			if(count==(number-1))
				
				{
				
					int number1=0,count1=0,_i;

												
						for(_i=1;_i<=i;_i++)
		
							{
		
								if(s[_i][j]!=s[i][j])
								count1=count1+1;
		
									if(_i==i)
									{
										number1=_i;
										goto out1;
									}

							}

		
	out1:{}
			
							if(count1==(number1-1))
		
								{
								
									int _j,number2_=0,count2_=0;

									for(_j=1;_j<=j;_j++)
									
										{

											if(s[i][_j]!=s[i][j])
												count2_=count2_+1;
										
											if(_j==j)
											{
												number2_=_j;
												goto out2;
											}

										}


	out2:{}
								
									if(count2_==(number2_-1))
					
										{
											a[i][j]=s[i][j];
											return 1;
										}

									else
	
										{
											return 0;
										}






								}

							else
							
								{
									return 0;
								}


				}//end of if

	
			else
			
				{
					return 0;
				}



}//end of check function








struct locate grid(int i,int j)

	{

	int x,y;

		if(i<=3&&i>=1)
		y=1;
	
			else if(i>=4&&i<=6)
			y=4;
	
				else if(i>=7&&i<=9)
				y=7;
	
		if(j<=3&&j>=1)
		x=1;
	
			else if(j>=4&&j<=6)
			x=4;
	
				else if(j>=7&&j<=9)
				x=7;


	location.x=x;
	location.y=y;
	
	return location;

	}
	
	
	
	

struct retrace func(int *dontrepeat,int i,int j)

	{
		welcome[i][j]++;

			int k;

			for(k=0;k<=8;k++)
				dontrepeat[k]=0;


				fretrace._i=linear[linearval(i,j)-welcome[i][j]].itsi;
				fretrace._j=linear[linearval(i,j)-welcome[i][j]].itsj;

	
			if(fretrace._j<=0||fretrace._i<=0)
			main();

	return fretrace;

	}//end of func
	
	
	
	
	

int linearval(int i,int j)

	{

		int position=0,i_,j_;

		for(i_=1;i_<=9;i_++)
		
			{
			
				for(j_=1;j_<=9;j_++)
		
					{
						position++;
				
						if(i_==i&&j_==j)
						goto _out_;
					}
		
			}
	_out_:{}

	return position;

	}









int makeasudoku(void)

	{

		int i,j;	
	
		for(i=1;i<=9;i++)
	
			{
		
				for(j=1;j<=9;j++)

					{

						filla[i][j]=a[i][j];
			
					}

			}


	removenum=diff+rand()%10; /////////////////DUFFICULTY LEVEL//////////////


	donem:{}


			
	int t=1,empty=0;


		while(empty!=removenum)

			{

				while(1)
		
					{

						t=1+rand()%81;
						linear[t].linearval++;

						if(linear[t].linearval==1)
						goto deciderem;

					}


				deciderem:{}

			filla[linear[t].itsi][linear[t].itsj]=0;
			
			empty++;
	}


	fillthesudoku();

}







int fillthesudoku(void)

	{

		int i_1,j_1;

		for(i_1=1;i_1<=9;i_1++)

			{

				for(j_1=1;j_1<=9;j_1++)

					{

						filling[i_1][j_1]=filla[i_1][j_1];

					}

			}

system("clear");

	output();
	


int i=1,j=1,tot,remi,remj;
float score=0;
char pos;

	
	
while(1)

	{
	
		gotoxy(1,5);
		printf("Your score is %.1f",score);
		
		gotoxy(1,1);
		printf("Hi, %s.",name);

	
		gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
	
			pos=getch();
			
				if(pos=='d'||pos=='D')
		
					{
						tot=linearval(i,j);
						tot++;
						
						
						if(tot>81)
						tot=tot%81;
						
						i=linear[tot].itsi;
						j=linear[tot].itsj;
												
						gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
					
						
					
					}

		
				else if(pos=='a'||pos=='A')
		
					{
						tot=linearval(i,j);
						tot--;
						
						if(tot<1)
						tot=tot+81;
						
						i=linear[tot].itsi;
						j=linear[tot].itsj;
												
						gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
						
					}
					
						

				else if(pos=='w'||pos=='W')
		
					{
						
						i=i-1;
						
						if(i<1)
						i=i+9;
												
											
						gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
						
					}
					
					
					
				else if(pos=='S'||pos=='s')
		
					{
						
						i=i+1;
						
						if(i>9)
						i=i-9;
												
						
						gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
						
					}
					

				else if(pos<=57&&pos>=49)
				
					{	
					
						int flag=0;
					
						if(filling[i][j]==0&&filla[i][j]==0)
						flag=1;
						
						gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
							
						int wronginput=0;

						do
					
						{
					
						if(wronginput>0)
							{
								remi=i;remj=j;
								gotoxy(1,1);
								printf("\nNot a valid entry");
								i=remi;j=remj;
							}
											
																																
							filling[i][j]=pos-48;
											
									
								if(filla[i][j]==0)
					
									{
					
									gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
									printf(" ");
											
									gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
									printf("%d",filling[i][j]);
					
									}
																			
							wronginput++;
											
						}while(filling[i][j]>9||filling[i][j]<0);


							if(filling[i][j]!=a[i][j]&&filling[i][j]!=0&&filla[i][j]==0)
							
								{
									score--;
									
									remi=i;remj=j;
							
										gotoxy(1,8);
										printf("\nWrong entry\n");
							
										gotoxy(1,5);
										printf("Your score is %.1f",score);
							
									i=remi;j=remj;
												
										
									getch();
										
										
									remi=i;remj=j;
									
										gotoxy(1,8);
										printf("\n           \n");
									
									i=remi;j=remj;
									
									
											
									filling[i][j]=filla[i][j];
											
									gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
									printf(" ");
								
									if(filling[i][j]!=0)
								
										{
								
										gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
										printf("%d",filling[i][j]);
								
										}
										
																
											
								}	
										
					
					if(filling[i][j]!=0&&filla[i][j]==0&&flag==1)
					score=score+100/(81-((diff-49)*3+40));
					
					
											
											
    ////////////////////////////keeps a track of your progress//////////////////////////////////////////////
										
						int done=0,equali,equalj;

						for(equali=1;equali<=9;equali++)
					
							{
					
								for(equalj=1;equalj<=9;equalj++)
					
									{
					
									if(filling[equali][equalj]==a[equali][equalj])
									done++;
					
									}
							}



										if(done==81)

											{
											
												getch();	
												
												system("clear");

						printf("\n\nCongratulations..... %s. You have solved the sudoku.\n\nYour score was %.1f",name,score);
	
							printf("\n\nDo you want to solve another sudoku (y\\n) : ");


											char q;

											scanf("%c",&q);

											if(q=='y'||q=='Y')
											{
											rep=0;
											main();
											}
											
											else
											exit(2);	
											
											}
											
					}
					
					
					
				else if(pos=='I'||pos=='i')
					
					{
					
						system("clear");
							
						printf("\nINSTRUCTIONS");

						printf("\n");
						hline
						printf("\n");	

						printf("\n1. Scoring is done out of 100 and for every wrong entry 1 is deducted.");

						printf("\n\n2. The user should use the following keys to navigate inside the sudoku\n\n\n\n");

						printf("				W	\n");
						printf("\n			A	S	D");

						printf("\n\n\n\n3. Press I whilie playing to view the Instructions");

						printf("\n\n4. Press F while playing to automatically fill the sudoku");

						printf("\n\n5. Press V while playing to view the solution of sudoku");

						printf("\n\n6. Press E while playing to exit the game");

						getch();
						
						system("clear");
						
						remi=i;
						remj=j;
						output();
						i=remi;
						j=remj;
						gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
							
					}
	
						
						
					else if(pos=='f'||pos=='F')
					
						{
							
							system("clear");


							printf("Are you sure you want to fill the sudoku in that case game will be over (y\\n) ??? : ");
							
							char q;
							
							q=getch();
							
							if(q=='y'||q=='Y')
							
							{
							
							system("clear");
							
							int a,b;
							
							for(a=1;a<10;a++)
							
								{
								
									for(b=1;b<10;b++)
									
										{
										
											filling[a][b]=s[a][b];
											
										}
								
								}
						
						
							
														
							score=0;
							
														
							remi=i;
							remj=j;
							output();
							i=remi;
							j=remj;
							
							getch();
							
							system("clear");
							
							printf("Do you want to solve another sudoku (y\\n) : ");


											char q;

											q=getch();
											
											if(q=='y'||q=='Y')
											{
											rep=0;
											main();
											}
											
											else
											exit(2);	
						
						
						}
						
						else
						
						{
						
						
							remi=i;
							remj=j;
							output();
							i=remi;
							j=remj;
						
						
							gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
							
						}
						
						
						
						
						}
						
						
					else if(pos=='e'||pos=='E')
					
						{
						
							system("clear");
							
							printf("Are you sure you want to exit (y\\n) ??? : ");
							
							char q;
							
							q=getch();
							
							if(q=='y'||q=='Y')
							{
							system("clear");
							exit(3);
							}
							
							else
							
							{
							
								system("clear");
						
								remi=i;
								remj=j;
								output();
								i=remi;
								j=remj;
		
								gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
							
							}
							
						
						}
						
						
					else if(pos=='v'||pos=='V')
					
						{
						
							system("clear");
																				
									viewthesol();
									getch();
							
							system("clear");
							
							gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
							
							remi=i;
								remj=j;
									output();    
								i=remi;
							j=remj;
							
							gotoxy(xcord-55+7*(j-1),6+(i-1)*3);
							
									
					
						}








	}//end of while

	}//end of function



#define MAX_SCREEN_AREA 100

int gotoxy(int x, int y)

	{

		char essq[MAX_SCREEN_AREA]={0}; // String variable to hold the escape sequence
		sprintf(essq, "\033[%d;%df", y,x);
		printf("%s", essq);
		return 0;
	} 




int output(void)

	{

		system("clear");
		
		gotoxy(1,3);
		
		printf("Your you are playing a ");
		
			if((diff-40)/3+1==1)
			printf("beginner level");
			
			if((diff-40)/3+1==2)
			printf("mature level");
		
			if((diff-40)/3+1==3)
			printf("expert level");
		
		
		gotoxy(1,7);
		printf("Press I to view the instructions");
				
		gotoxy(1,9);
		
		printf("Result");		
		
		
		gotoxy(xcord-56,2);
	
		printf("  1      2      3      4      5      6      7      8      9");                            

			int counter=3;

				gotoxy(xcord-58,counter);
				hline

					printf("\n");
					counter++;

						printf("\n\n");
						counter=counter+2;


		int i1,j1;

		for(i1=1;i1<=9;i1++)

			{
		
			gotoxy(xcord-62,counter);
			printf("%d   ",i1);
			
				for(j1=1;j1<=9;j1++)
	
					{
	
						if(filling[i1][j1]!=0)
						printf("   %d   ",filling[i1][j1]);
	
						else
						printf("       ",filling[i1][j1]);
				
					}//end of inner for
	
						printf("\n");counter=counter+1;
		  	
		
		
								if(i1==3||i1==6)
		
									{
										gotoxy(xcord-58,counter);
										dashhline
									}
									
								else
		
									{
										gotoxy(xcord-58,counter);	
										hline
									}	
		
						printf("\n\n\n\n");counter=counter+2;

			}//end of outer for

		int m;

		for(m=0;m<10;m++)
			
			{

				if(m==3)
				dashvline(xcord-58+m*7,4,28,1)

				if(m==6)
				dashvline(xcord-58+m*7,4,28,2)
	
				if(m!=3&&m!=6)
				vline(xcord-58+m*7,4,28)


			}

	return 0;

	}





int viewthesol (void)

	{

		gotoxy(xcord-56+20,2);
		
		printf("Solution of Sudoku");
		
		gotoxy(xcord-56,5);
	
		printf("  1      2      3      4      5      6      7      8      9");                            

			int counter=6;

				gotoxy(xcord-58,counter);
				hline

					printf("\n");
					counter++;

						printf("\n\n");
						counter=counter+2;


		int i1,j1;

		for(i1=1;i1<=9;i1++)

			{
		
			gotoxy(xcord-62,counter);
			printf("%d   ",i1);
			
				for(j1=1;j1<=9;j1++)
	
					{
	
						printf("   %d   ",s[i1][j1]);
	
										
					}//end of inner for
	
						printf("\n");counter=counter+1;
		  	
		
		
								if(i1==3||i1==6)
		
									{
										gotoxy(xcord-58,counter);
										dashhline
									}
									
								else
		
									{
										gotoxy(xcord-58,counter);	
										hline
									}	
		
						printf("\n\n\n\n");counter=counter+2;

			}//end of outer for

		int m;

		for(m=0;m<10;m++)
			
			{

				if(m==3)
				dashvline(xcord-58+m*7,7,28,1)

				if(m==6)
				dashvline(xcord-58+m*7,7,28,2)
	
				if(m!=3&&m!=6)
				vline(xcord-58+m*7,7,28)


			}

	return 0;

	}









char getch(void)

	{
	
	struct termios oldt,
	newt;

	char ch;
	
		tcgetattr( STDIN_FILENO, &oldt );
		newt = oldt;
		newt.c_lflag &= ~( ICANON | ECHO );
		tcsetattr( STDIN_FILENO, TCSANOW, &newt );
		
		ch = getchar();

		tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
	return ch;
	}

