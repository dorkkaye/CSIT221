#include <windows.h>
#include <stdio.h>

void gotoxy(int x, int y)
{
	COORD p = {x, y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void boxDisplay(int height, int width, int x, int y)
{
	height = 6;
	width = 23;
	
	for(y = 0; y < height; y++)
	{
		for(x = 0; x < width; x++)
		{
			if(y == 0 || y == height - 1)
			{
				if(x == 0 && y == 0)
				{
					gotoxy(x + 2, y + 8);
					printf("%c",201);
				}
				else if(x == width-1 && y == 0)
				{
					gotoxy(x + 2,y + 8);
					printf("%c",187);
				}
				else if(x == 0 && y == height-1)
				{
					gotoxy(x + 2,y + 8);
					printf("%c",200);
				}
				else if(x == width-1 && y == height-1)
				{
					gotoxy(x + 2,y + 8);
					printf("%c",188);
				}
				else
				{
					gotoxy(x + 2,y + 8);
					printf("%c",205);
				}
				
			}
			else
			{
				if(x == 0 || x == width-1)
				{
					gotoxy(x + 2,y + 8);
					
					printf("%c",186);
				}
				else
				{
					printf(" ");
				}
			}
			
		}
		printf("\n");
	}
	
}

void initSeats(int seats[], int size)
{
	int i;
	
	//First Class
	for(i = 0; i < size / 2; i++)
		seats[i] = 0;
		
	//Economy
	for(i = size / 2; i < size; i++)
		seats[i] = 0;
}

void displaySeats(int seats[], int size)
{
	int i;
	int height, width, x, y;
	
	printf("First Class Section: ");
	//First Class
	for(i = 0; i < 5; i++)
		printf("[%d] ", seats[i]);
	
	printf("\nEconomy Section:     ");	
	//Economy
	for(i = 5; i < 10; i++)
		printf("[%d] ", seats[i]);
}

void boardPass(int seat)
{	
	int height, width, x, y;
	boxDisplay(height, width, x, y);
	
	gotoxy(7,9); 
	printf("Boarding Pass");
	
	if(seat + 1 < 6)
	{
		gotoxy(4,11); 
		printf("First Class Section");
	}	
	else
	{
		gotoxy(6,11); 
		printf("Economy Section");
	}
	
	gotoxy(10,12); 
	printf("Seat #%d", seat + 1);
}

int storage()
{
	int seat;
	
	boardPass(seat);
}

void exit(int status)
{
	exit(0);
}

int assignSeat(int st[], int seatType)
{
	int size, seat;
	
	//First Class Section
	if(seatType == 1)	
	{
		seat = assignFirstClass(st, size);
		if(seat == -1)
		{
			printf("\nAll seats are already taken, do you wish to be assigned in economy section (1 - yes | 0 - no): ");
			int choice;
			scanf("%d", &choice);
			if(choice == 1)
				seat = assignEconomy(st, size);
			else
			{
				printf("\n\nAll seats are already taken.\n");
				printf("Next flight is in 3 hours");
				exit(0);
			}
		}
	}	
	//Economy Section
	if(seatType == 2)
	{
		seat = assignEconomy(st, size);
		if(seat == -1)
		{
			printf("\nAll seats are already taken, do you wish to be assigned in first class section (1 - yes | 0 - no): ");
			int choice;
			scanf("%d", &choice);
			if(choice == 1)
			{
				seat = assignFirstClass(st, size);
			}
			else
			{
				printf("\n\nAll seats are already taken.\n");
				printf("Next flight is in 3 hours.");
				exit(0);
			}
		}
	}	 	

	if(seat != -1)
	{
		gotoxy(0, 16);
		displaySeats(st, size);
	}
	else
	{
		printf("\n\nAll seats are already taken.\n");
		printf("Next flight is in 3 hours.");
		exit(0);
	}

}

int assignFirstClass(int seats[], int size)
{
	int i;
	size = 10;	
	
	for(i = 0; i < size/2; i++)
	{
		if(seats[i] != 1)
		{
			seats[i] = 1;
			return i;
		}
	}
	
	return -1;
}

int assignEconomy(int seats[], int size)
{
	int i;
	size = 10;
	
	for(i = size/2; i < size; i++)
	{
		if(seats[i] != 1)
		{
			seats[i] = 1;
			return i;
		}
	}
	
	return -1;
}
