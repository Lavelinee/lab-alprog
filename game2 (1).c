#include <stdio.h>
#include <conio.h>

char map[20][20];
char player = '^', food = 'o';
char tail[10] = {'*','*','*','*','*','*','*','*','*','*'};
int y = 12;
int x = 3;
int a[100];
int b[100];
char walk;

void generateMap(int p, int q, int R){
	int i,j;
	for(i=0; i<100; i++){
		for(j=0; j<100; j++){
			map[i][j] = ' ';
		}
	}
	map[0][0] = '+';
	map[99][0] = '+';
	map[99][99] = '+';
	map[0][99] = '+';
	for(i=1; i<99; i++){
		map[i][0] = '|';
		map[i][99]= '|';
	}
	for(j=1; j<99; j++){
		map[0][j] = '=';
		map[99][j] = '=';
	}
	map[y][x] = player;
	for(i=0; i<R; i++){
		map[a[i]][b[i]] = tail[i];
	}
	map[p][q] = food;
}

void outputMap(int score){
	int i,j;
	for(i=0; i<99; i++){
		for(j=0; j<99; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	printf("Score: %d\n", score);
}

int main(){
	int i,j,n = 0, p = 10, q = 10, rand = 2, R = 1;
	int score = 0;
	system("color a");
	do {
		system("cls");
		generateMap(p,q,R);  // Corrected function name
		outputMap(score);
		walk = getch();
		for(i=9; i>0; i--){
			a[i]= a[i-1]; b[i] = b[i-1];
		}
		a[0] = y; b[0] = x;
		switch(walk){
			case 'w':
				if(map[y-1][x] == ' '){
					y--;
					map[y][x] = player;
				}
				else if(map[y-1][x] == food){
					p *= (rand + y * 3); q *= (rand + x * 9);
					if(p >= 99) p %= 13;p++;
					if(q >= 99) q %= 16;q++;
					score++;
					R++;		
				}
				player = '^';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
				break;
			case 's':
				if(map[y+1][x] == ' '){
					y++;
					map[y][x] = player;
				}
				else if(map[y + 1][x] == food){
					p *= (rand + y * 6); q *= (rand + x * 8);
					if(p>=99) p%= 18;p++;
					if(q>=99) q%= 15;q++;
					score++;
					R++;
				}
				player = 'v';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
				break;
			case 'a':
				if(map[y][x-1] == ' '){
					x--;
					map[y][x] = player;
				}
				else if(map[y][x-1] == food){
					p *= (rand + y * 5); q *= (rand + x * 7);
					if(p>=99) p%= 18;p++;
					if(q>=99) q%= 17;q++;
					score++;
					R++;
				}
				player = '<';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
				break;
			case 'd':
				if(map[y][x+1] == ' '){
					x++;
					map[y][x] = player;
				}
				else if(map[y][x+1] == food){
					p *= (rand + y * 2); q *= (rand + x * 3);
					if(p>=99) p%= 18;p++;
					if(q>=99) q%= 18;q++;
					score++;
					R++;
				}
				player = '>';
				for(i=0; i<R; i++){
					for(j=0; j<R; j++){
						map[a[i]][b[j]] = tail[n];
						n++;
					}
				}
				break;
		}
	}while(score < 101);
	
	system("cls");
	printf("\t\t+==================================+\n");
	printf("\t\t|        CONGRATULATION !!!        |\n");
	printf("\t\t+==================================+\n");
	printf("Your Score : %d\n", score);
	getch();
	
	return 0;
}

