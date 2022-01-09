#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nrows 30	//Gobally defining Nrows to be equal to 30
#define Ncols 30	//Gobally defining Ncols to be equal to 30

void ReadInitialState(int InputArray[Nrows][Ncols])	//ReadInititalState Purpose: Reads in a text file and stores it into a 2D Array.
{
    FILE *InputFile; 
    InputFile = fopen("InitialState_6.txt", "r");	//Open's the text file named: InitialState_2.txt. "r" specifies read mode
    int n, m;	//Initializes integer variables: n & m
    
	if (InputFile == NULL)
    {
        printf("\nError Reading File\n");		//Prints "Error Reading File" if the input file isn't opened correctly
    }
    
	else	//If opened correctly the nested for loop executes
    {
        for (n = 0; n < Nrows; n++)		
        {
            for (m = 0; m < Ncols; m++)
            {
            	fscanf(InputFile, "%d,", &InputArray[n][m]);	// Scans in the values of InputFile and stores it into the 2D Array
            }
        }
    }
    
	fclose(InputFile);		//Closes the InputFile
}

void DisplayGen(int Generation[Nrows][Ncols])	//DisplayGen Purpose: Prints a 2D Array to the terminal output
{
	int n, m;		//Initializes integer variables: n & m
		//Nested for loop to print the 2D Array
		for (n = 0; n < Nrows; n++)   
        {
            for (m = 0; m < Ncols; m++)
            {
				if (Generation[n][m]== 1)	//If the value of the Array is 1 execute the following print statement
				{
					printf("\033[31m%d \033[0m", Generation[n][m]);	//Prints the value of the 2D Array (1) in red 
				}
				else //If the value of the Array is not 1 (aka 0) execute the following print statement
				{
					printf("\033[34m%d \033[0m", Generation[n][m]);	//Prints the value of the 2D Array (0) in blue
				}
            }
			printf("\n");	//Makes the output look cleaner
        }

	printf("\n\n");	//Makes the output look cleaner
}

void ComputeNextGen(int ArrayCurrentGen[Nrows][Ncols], int ArrayNextGen[Nrows][Ncols])
{
	int n, m;	//Initializes integer variables: n & m
	for (n = 1; n < Nrows-1; ++n)	//Nested for loop to count the number of alive cells
	{
		for (m = 1; m < Ncols-1; ++m)
		{
				int count = 0;
				//Checks the neighbors of each respective cell and counts the number of alive cells surrounding it
				count += ArrayCurrentGen[n - 1][m + 1];	//Checks diagonal top right neighbor
				count += ArrayCurrentGen[n - 1][m - 1];	//Checks diagonal top left neighbor	
				count += ArrayCurrentGen[n + 1][m - 1];	//Checks diagonal bottom left neighbor
				count += ArrayCurrentGen[n + 1][m + 1];	//Checks diagonal bottom right neighbor
				count += ArrayCurrentGen[n][m - 1];		//Checks directly left neighbor
				count += ArrayCurrentGen[n + 1][m];		//Checks directly bottom neighbor	
				count += ArrayCurrentGen[n - 1][m];		//Checks directly top neighbor	
            	count += ArrayCurrentGen[n][m + 1];		//Checks directly right neighbor
			
			if  (((ArrayCurrentGen[n][m] == 1) && ((count == 2  )|| (count == 3)))|| (count == 3))		//If an alive cell is surrounded by 2 or 3 alive cells or if a dead cell is surrounded by 3 alive cells the following condition executes
			{
				ArrayNextGen[n][m] = 1;		//Set the value of the cell to 1 (alive)
			}
			else //If an alive cell isn't surrounded by the the above conditions then it must die thus the following condition executes
			{
				ArrayNextGen[n][m] = 0;		//Set the value of the cell to 0 (dead)
			}
		}
	}
}

void ResetGen(int ArrayCurrentGen[Nrows][Ncols], int ArrayNextGen[Nrows][Ncols])	//ResetGen Purpose: Copies ArrayNextGen to ArrayCurrentGen, and resets ArrayNextGen to zero (the value of the dead cells)
{
	int n,m;	//Initializes integer variables: n & m
	
	for (int n=0; n < Nrows; n++)
	{
  		for (int m=0; m < Ncols; m++)
  		{
    		ArrayCurrentGen[n][m] = ArrayNextGen[n][m];	//Nested for loop that copies ArrayNextGen to ArrayCurrentGen
			ArrayNextGen[n][m] = 0;	//Sets every value in ArrayNextGen equal to 0
  		}
	}	
}

int main(void)
{
	int i, numberArray[Nrows][Ncols], ArrayNextGen[Nrows][Ncols] = {0};	//Initializes the variables i & v and the 2D Array numberArray. Aslo initializes 2D 30x30 Array ArrayNextGen and sets each value equal to 0
    printf("\n\033[31mInitial State:\n\033[0m");	//Prints "Initial State:" in red
	ReadInitialState(numberArray);			//Calls the ReadInitialState function
    DisplayGen(numberArray);	//Calls the DisplayGen function
		for(i=1; i<13; ++i)	//for loop to display 8 generations of the input
		{
	   		printf("\033[31mComputed Generation %i:\n\033[0m", i);	//Prints the label "Computed Generation " in red
			ComputeNextGen(numberArray, ArrayNextGen);	//Calls the ComputeNextGen function
	   		ResetGen(numberArray, ArrayNextGen);	//Calls the ResetGen function
	   		DisplayGen(numberArray);	//Calls the DisplayGen function
   		} 
}