#pragma once

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+1
#define COLS COL+1
#define EASY 10


void menu();
void menu2();
void game();
void InitBoard(char board[ROWS][COLS], int row, int col, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int SeekMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int not_mine);
int MarkMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int ismine);