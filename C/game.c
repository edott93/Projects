#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void populateboard(int ** grid,int height, int width)
{
	int x,y;
	for(x = 0; x < width; x++)
	 {
	 	for(y = 0; y < height; y++)
		{
			grid[x][y] = 0;

		}

	 }

}
int isFinished(int height, int width, int ** grid)
{
	int x,y;
	for(x = 0; x < width; x++)
	 {
		for(y = 0; y < height; y++)
		{
			if(grid[x][y] == 0)
				return 0;
		}
	 }
	 return 1;
}
void changeBoard(int xcoord, int ycoord, int ** grid, int width, int height)
{
	if(xcoord > width-1 || ycoord > height-1 || xcoord < 0 || ycoord < 0)
		return;
	grid[xcoord][ycoord] = !grid[xcoord][ycoord];
	if(xcoord-1 >= 0)
		grid[xcoord-1][ycoord] = !grid[xcoord-1][ycoord];
	if(xcoord+1 < width)
		grid[xcoord+1][ycoord] = !grid[xcoord+1][ycoord];
	if(ycoord -1 >= 0)
		grid[xcoord][ycoord-1] = !grid[xcoord][ycoord-1];
	if(ycoord + 1 < height)
		grid[xcoord][ycoord+1] = !grid[xcoord][ycoord+1];
	
}
void printBoard(int height, int width, int ** grid)
{
	int x,y = 0;
	for(x = 0; x < height; x++)
	{
		for(y = 0; y < width; y++)
		{
			if(grid[y][x])
				printf("1");
			else 
				printf("0");
		}
		printf("\n");
	}
}
int main()
{
	srand(time(NULL));
	int height, width;

	printf("Enter the x and y size of the board\n");
	scanf("%d",&width);
	scanf("%d",&height);

	int ** grid;
	
	
	grid = malloc(width * sizeof(int*));
	
	int i;
	for(i = 0; i < width; i++)
	{
		
		grid[i] = malloc(height * sizeof(int));
	}
	
	long long int program_counter =0;
	int finished = 0;
	int x,y;
	populateboard(grid,height,width);
	printBoard(height,width,grid);
	do{
		
		printf("Pick an x location\n");
		scanf("%d",&x);
		printf("Pick a y location\n");
		scanf("%d", &y);
		/*
		x = rand() % width;
		y = rand() % height;
		*/
		changeBoard(x-1,y-1,grid, width, height);
		finished = isFinished(height,width,grid);
		printf("\n");
		printBoard(height,width,grid);
		program_counter++;
	}while(!finished);
	printf("You won and it only took %lld tries!\n",program_counter);
	
	return 0;
}
