/*
End Semester Project omputer Fundamentals 
BEE-1B
Ms. Samin Khaliq
------------------------------------------------------------------
Recursion Iterative Brute Force Algortihm for Sudoku Solver.
------------------------------------------------------------------
Umair Aftab (104)
Hassam Ali Khan (35)
-------------------------------------------------------------------

© Intellectual Property of 
Umair Aftab && Hassam Ali Khan 
*/






#include <iostream>
#include <time.h>
using namespace std;
float count=0 ;

//Set-up input grid and receive input
int input_grid[9][9]

	/*={
		{ 0 , 0 , 0 ,   0 , 0 , 5 ,   0 , 0 , 0 },
		{ 7 , 0 , 0 ,   0 , 0 , 0 ,   0 , 2 , 1 },
		{ 0 , 3 , 6 ,   0 , 0 , 8 ,   9 , 0 , 0 },

		{ 9 , 0 , 0 ,   0 , 8 , 0 ,   1 , 7 , 3 },
		{ 0 , 0 , 0 ,   0 , 0 , 0 ,   0 , 0 , 0 },
		{ 8 , 1 , 3 ,   0 , 6 , 0 ,   0 , 0 , 9 },

		{ 0 , 0 , 2 ,   3 , 0 , 0 ,   7 , 9 , 0 },
		{ 1 , 9 , 0 ,   0 , 0 , 0 ,   0 , 0 , 6 },
		{ 0 , 0 , 0 ,   6 , 0 , 0 ,   0 , 0 , 0 }

	}*/; 
// End of input grid

void user_input()
{
	int q[9];
	char input_row[11];
	for (int j=0 ;j< 9; j++)
	{
		char input_row[11];
		cout << endl<<"Please Enter row: "<<j;
		cin.getline(input_row,10);
		for (int x=0 ; x<10 ; x++) 
		{
			cout <<endl<< input_row[x];
		}
		cout <<"*****************"<<endl;
		for (int x=0 ; x<9 ; x++) 
		{
			q[x] =static_cast <int>(input_row[x]);
			//cout << q[x] <<endl ;
			
			if (q[x]==48)
			{ input_grid[j][x]=0;}
			if (q[x]==49)
			{ input_grid[j][x]=1;}
			if (q[x]==50)
			{ input_grid[j][x]=2;}
			if (q[x]==51)
			{ input_grid[j][x]=3;}
			if (q[x]==52)
			{ input_grid[j][x]=4;}
			if (q[x]==53)
			{ input_grid[j][x]=5;}
			if (q[x]==54)
			{ input_grid[j][x]=6;}
			if (q[x]==55)
			{ input_grid[j][x]=7;}
			if (q[x]==56)
			{ input_grid[j][x]=8;}
			if (q[x]==57)
			{ input_grid[j][x]=9;}
		}
		cout<<endl;
		
		
	}
		for (int x=0 ; x<9 ; x++)
		{
			for (int y=0 ; y<9 ; y++)
			{
				cout<<input_grid[x][y]<<" " ;
			}
			cout<<endl;
		}
		cout <<"*****************************************"<<endl;
}

//Sudoku Cell Class
struct Playing_grid {
	//Value of cell
	int number;
	//wether the number was a clue or not
	bool fixed;
} 
	grid[9][9];
//End of cell class

//load input_grid into grid struct;
void load_input(){
	
	//cycle through each cell
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			
			//if empty, flag as non-fixed
			if (input_grid[i][j] == 0){
				
				grid[i][j].fixed = false;
				grid[i][j].number = 0;
			}
			
			//else, flag as fixed, and assign the value found in the cell
			else{
				grid[i][j].fixed = true;
				grid[i][j].number = input_grid[i][j];
			}
		}
	}
}
//end load_input
				
//Print grid of any state
void print_grid() {
	
	//speaks for itself
	for (int i = 0; i < 9; i++)
	{
		
		for (int j = 0; j < 9; j++)
		{
			cout << grid[i][j].number << " ";
		}
		
		cout << endl;
	}
}
//End of print_grid()

//Check row eligibility function
bool check_row(int row, int column){

	//Cycle through row
	for (int i = 0; i < 9; i++){
			
		//Don't check for itself
		if (i != column){
				
			//If same number is found, return false
			if (grid[row][i].number == grid[row][column].number ){
				return false;
			}
		}
	}
		
	//if no identical value is found, return true
	return true;
	
} //End Check row

//Check column eligibility function
bool check_column(int row, int column){
	//Same basic functionality as the row checker, just cycling down a column
	//rather than across a row
		
	//Cycle through column
	for (int i = 0; i < 9; i++){
			
		//Don't check for itself
		if (i != row){
				
			//If same number is found, return false
			if (grid[i][column].number == grid[row][column].number ){
				return false;
			}
		}
	}
		
	//if no identical value is found, return true
	return true;
}
//End of check row

//Check 3x3 grid function
bool check_square(int row, int column){
	//Get the 3x3 square the cell we're testing is in
	int vsquare = row/3;
	int hsquare = column/3;
	
	//check to see if there is an identical element
	for (int i = vsquare * 3; i < (vsquare*3 + 3); i++){
		for (int j = hsquare * 3; j < (hsquare*3 + 3); j++){
			
			//Don't test itself
			if (!(i == row && j == column)){
				if (grid[ row ][ column ].number == grid[i][j].number){
				return false;
				}	
			}
		}	
	}
	return true;
}
//End of 3x3 check

//Recursive cell-solver - will do my best to explain
bool solve(int row, int column){
	count++;
	
	//in case the cell passed to function is fixed, go to next non-fixed cell
	while (grid[row][column].fixed == true){
		
		// try next cell
		column++;
		
		//if we're at end of row
		if(column > 8){
			column = 0;
			row++;
		}

		//if we're at end of puzzle and find a fixed number, break this solve();
		if (row > 8){
			return true;
		}
	}
	
	//once we have our cell coordinates, substitute in a number and check it
	for (int n = 1; n < 10; n++){
		int nextrow, nextcolumn;
		
		grid[row][column].number = n;
		
		//if good, solve the next one
		if ( check_column(row, column) && check_row(row, column) && check_square(row, column))
		{		
			//decide next cell
			nextrow = row;
			nextcolumn = column;
			
			nextcolumn++;
			
			//if end of row
			if(nextcolumn > 8){
			nextcolumn = 0;
			nextrow++;
			}
			
			//if end of puzzle
			if (nextcolumn == 0 && nextrow == 9){
				return true;
		}
			
			//If next cell checks, so does this one. This way all cells depend
			//on the validity of the last which in turn depends on the current
			//state of the previous 80 for loops.
			if(solve(nextrow, nextcolumn)){
				return true;
			}
		}
	}
	
	//if no solution to this cell was found, reset cell and return to previous
	//cell's for loop
	grid[row][column].number = 0;
	return false;
	
}
			

//speaks for itself
void main(){

	time_t start,end;
	double diff;
	
	user_input();
	load_input();
	
	time (&start);
	solve(0, 0);
	
	time (&end);
	diff=difftime (end ,start);
		
	print_grid();

	cout<<endl<<"Iterations performed: "<<count<<endl;
	cout<<"It took the solver: "<<diff<<" seconds to solve"<<endl;
	
	system ("PAUSE");
}//end main

