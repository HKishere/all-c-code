#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ROW 3;
#define MAX_COL 3;
char ches[3][3];
int menu() {
		while (1) {
			int choose;
			printf("******************\n");
			printf("***** 1.play *****\n");
			printf("***** 2.exit *****\n");
			printf("******************\n");
			printf("please enter your choose:");
			scanf("%d", &choose);
			if (choose == 2) {
				printf("goodbye!\n");
				system("pause");
				return  1;
			}
			else if (choose != 1) {
				printf("illegal input ! please enter again:\n");
			}
			else {
				break;
			}
		}
	return 0;
}
int printboard() {
	printf(" - - -\n");
	printf("|%c|%c|%c|\n", ches[0][0], ches[0][1], ches[0][2]);
	printf(" - - -\n");
	printf("|%c|%c|%c|\n", ches[1][0], ches[1][1], ches[1][2]);
	printf(" - - -\n");
	printf("|%c|%c|%c|\n", ches[2][0], ches[2][1], ches[2][2]);
	printf(" - - -\n");
	return 0;
}
int playermove() {
	int row, col;
	while (1) {
		getchar();/*Çå³ýÊäÈë»º³åÇø*/
		printf("please enter the coordinate you want to place your chess,use ','to separate :\n ");
		scanf("%d,%d", &row, &col);
		if (row > 3 || row < 0 || col>3 || col < 0) {
			printf("please enter the correct coordinate!\n");
			continue;
		}
		if (ches[row - 1][col - 1] == '\0') {
			ches[row - 1][col - 1] = 'X';
			printf("player place the chess in'%d,%d\n'", row, col); 
			break;
		}
		else {
			printf("The coordinate you enter has been occupied !\n");
			continue;
		}
	}
	printboard();
	return 0;
}
int winner_checker() {
	char playerwin[3] = { 'X','X','X' };
	char computerwin[3] = { 'O','O','O' };
	if (strcmp(ches[0],playerwin)==0||strcmp(ches[1],playerwin)==0||strcmp(ches[2],playerwin)==0||(ches[0][0]=='X'&&ches[1][0]=='X'&&ches[2][0])||ches[0][1]=='X'&&ches[1][1]=='X'&&ches[2][1])||ches[0][2]=='X'&&ches[1][2]=='X'&&ches[2][2])){
		return 0;//0 mean player win
	}
	else if (ches[0][0]=='X'&&ches[1][1]=='X'&&ches[2][2]=='X'){
		return 0;
	}
	if (strcmp(ches[0],computerwin)==0||strcmp(ches[1],computerwin)==0||strcmp(ches[2],computerwin)==0)||(ches[0][0]=='O'&&ches[1][0]=='O'&&ches[2][0])||ches[0][1]=='O'&&ches[1][1]=='O'&&ches[2][1])||ches[0][2]=='O'&&ches[1][2]=='O'&&ches[2][2]){
		return 1;// 1 means computer win
	}else if (ches[0][0] == 'O'&&ches[1][1] == 'O'&&ches[2][2] == 'O'){
		return 1;
	}
	return 2;
}
int computermove() {
	/*srand((unsigned int)time(0));*/
	while (1) {
		int col = rand() % 3 + 1;
		int row = rand() % 3 + 1;
		if (ches[row - 1][col - 1] == '\0') {
			ches[row - 1][col - 1] = 'O';
			printf("computer place the chess in'%d,%d'\n", row, col);
			break;
		}
		else {
			continue;
		}	
	}
	printboard();
	return 0;
}
int game() {
	int win=100;
	while(1){
		printboard();
		playermove();
		win=winner_checker();
		if(win==1){
			printf("computer win!\n");
			break;
		}
		else if(win==0){
		 	printf("player win\n");
		 	break;
		}
		computermove();
		winner_checker();
		if(win==1){
			printf("computer win!");
			break;
		}
		else if(win==0){
		 	printf("player win");
		 	break;
		}
	}
	return 0;
}
int main (){
	if (menu()==1){
		return 0;
	}
	game();
	system("pause");
	return 0;
}
