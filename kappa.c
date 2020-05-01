#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void print(char** table, int N, int M, int level, int score)
{
	int i, j;
	
	printf("   ");
	
	for (i = 1 ; i <= N ; i++)
	{
		if (i < 10){
		printf(" %d ", i);
		}
		else {
		printf(" %d", i);
		}
	}
	
	printf("\n");
	
	for (i = 0 ; i <= N ; i++)
	{
		printf("---");
	}
	
	printf("\n");
	
	for (i = 0 ; i < N ; i++)
	{
		if (i + 1 < 10) {
		printf(" %d|", i+1);
		}
		else {
		printf("%d|", i+1);
		}
		
		for (j = 0 ; j < M ; j++)
		{
			printf(" %c ", table[i][j]);
		}
		printf("\n");
	}
	
	printf("Level %d. Points %d.\n", level, score);
	printf("Make your move: ");
}


int bomb(char** table, int N, int M, int row, int col)
{
	int i, j, hit;
	
	if (row <= N && row > 0 && col <= M && col > 0)
	{
		row--;
		col--;
		if (table[row][col] == '.')
		{
			printf("You cannot bomb an empty tile!\n");
			return 0;
		}
	
		hit = 0;
		for (i = row - 1 ; i < row + 2 ; i++)
		{
			if (i < 0 || i >= N){
			continue;
			}
			
			for (j = col - 1 ; j < col + 2 ; j++)
			{
				if (j < 0 || j >= M){
				 continue;
				}
				
				if (table[i][j] != '.'){
					hit++;
					table[i][j] = '.';
				}
			}
		}
		return hit;
	}
	else {
		printf("Position is out of bounds!\n");
		return 0;
	}
}


void drop_tiles(char** tablo, int col, int N, int M)
{
	int i, j, k;
	
	col--;
	
	for (j = col - 1 ; j < col + 2 ; j++)
	{
		if (j < 0) continue;
		if (j >= M) return;
		
		for (k = 0 ; k < N ; k++)
		{
			for (i = N - 1 ; i > 0 ; i--)
			{
				if (tablo[i][j] == '.' && tablo[i-1][j] != '.'){
					tablo[i][j] = tablo[i-1][j];
					tablo[i-1][j] = '.';
				}
			}
		}
	}
}


int hammer(char** table, int N, int M, int row, int col, int color)
{
	
	if (row < N && row >= 0 && col < M && col >= 0) 
	{
		if (table[row][col] == '.'){
		return 0; 
		}
		
		if (color == 0)	{
		color = table[row][col];
		}
		else if (table[row][col] != color){
		return 0; 
		}
		
		table[row][col] = '.'; 
		
		return 1 + 
				hammer(table, N, M, row, col-1, color) 	+
				hammer(table, N, M, row, col+1, color)	+
				hammer(table, N, M, row-1, col, color)	+
				hammer(table, N, M, row+1, col, color)	; 
		
	}
	else return 0; 
}


void add(char** table, int N, int M, int row, int col, int color, int colors)
{
	int i, j, hit;
	
	if (row <= N && row > 0 && col <= M && col > 0 && color > 0 && color <= colors){
		row--;
		col--;
		
		if (table[row][col] != '.'){
			printf("You cannot add tile over another tile!\n");
			return;
		}
	
		table[row][col] = color + '0';
	}
	else if (color < 1 || color > colors){
		printf("Wrong color!\n");
	}
	else {
		printf("Position is out of bounds!\n");
	}
}


int main(){
	char** table = NULL;
	int i, j, N, M, colors, color, pos, row, col, level, score, remain;
	char move[15];
	
	srand(time(NULL));
	
	do{
		printf("Give rows (3-17): ");
		scanf("%s", move);
		N = atoi(move);
	}while (N < 1 || N > 17);
	
	do{
		printf("Give columns (3-17): ");
		scanf("%s", move);
		M = atoi(move);
	}while (M < 1 || M > 17);
	
	do{
		printf("Give colors (1-9): ");
		scanf("%s", move);
		colors = atoi(move);
	}while (colors < 1 || colors > 17);
	
	level = 1;
	score = 0;
		
	while (1){
	
		table = (char**)malloc(sizeof(char*) * N);
		if (table == NULL){
			printf("No memory\n");
			return 1;
		}
	
		for (i = 0 ; i < N ; i++){
			table[i] = (char*)malloc(sizeof(char) * N);
			if (table[i] == NULL){
				printf("No memory\n");
				return 1;
			}
		}
	
		for (i = 0 ; i < N ; i++){
			for (j = 0 ; j < M ; j++){
				table[i][j] = rand() % colors + '1';
			}
		}
	
		remain = N * M;
	
		do{
			print(table, N, M, level, score);
			scanf("%s", move);
		
			if (strcmp(move, "b") == 0 || strcmp(move, "B") == 0){
				scanf("%s", move);
				
				row = atoi(move);
				
				pos = 0;
				while (move[pos] != ',') pos++;
			
				col = atoi(&move[pos+1]); 
			
				pos = bomb(table, N, M, row, col);
				if (pos > 0){
					remain -= pos;
					pos *= pos * 2;
					score += pos * level;
					drop_tiles(table, col, N, M);							
				}
			}
			else if (strcmp(move, "a") == 0 || strcmp(move, "A") == 0){
				scanf("%s", move);
				
				row = atoi(move);
				
				pos = 0;
				while (move[pos] != ',') pos++;
			
				col = atoi(&move[pos+1]); 
				
				scanf("%s", move);
				color = atoi(move);
		
				add(table, N, M, row, col, color, colors);
				
				drop_tiles(table, col, N, M);				
			}
			else if (strcmp(move, "h") == 0 || strcmp(move, "H") == 0){
				scanf("%s", move);
				
				row = atoi(move);
				
				pos = 0;
				while (move[pos] != ',') pos++;
			
				col = atoi(&move[pos+1]); 
				
				pos = hammer(table, N, M, row-1, col-1, 0);
				if (pos > 0){
					remain -= pos;
					pos *= pos * 2;
					score += pos * level;
					drop_tiles(table, col, N, M);							
				}
								
			}
			else if (strcmp(move, "x") == 0 || strcmp(move, "X") == 0){
				break;
			}
			
		}while(remain > 0);
		
		for (i = 0 ; i < N ; i++) free(table[i]);
		free(table);
	
		if (N == 17 || M == 17 || strcmp(move, "x") == 0 || strcmp(move, "X") == 0) break;
	
		N++;
		M++;
		level++;
	}
	printf("\n\nLevels %d, points %d.\n\n", level, score);
	return 0;
}