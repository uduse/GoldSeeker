#pragma once
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
//#include "Windows.h"
#include "Player.h"

//enum Complexity;

using namespace std;

struct Block
{
	//For Player
	bool visited;
	bool collided;

	int x;
	int y;
	char display;
	bool painted;
	bool goldCollected;
	bool threaded;

	// 0: Empty
	// 1: Gold
	// 2: Solid
	// 3: Rock
	// 4: Wall
	int status;

	Block();
	Block( int x, int y );

	int getStatus();
	void setStatus( int index );
	void assignDisplay();
	void assignDisplay( char ch );
	void print();
};

struct Brush
{
	int x;
	int y;
	int size;
	Brush( int x, int y, int size );

	void move( int x, int y );
	void print();
};

struct Object
{
	int x;
	int y;
	void set( int xIN, int yIN );
};

class Cave
{
public:
	bool newVisit;
	Cave();
	Cave( int width, int height, int c );
	~Cave();
	int getOxygen();
	void printCave();
	void printTrails();
	void printStats();
	void printCaveStatus();

	int playerMoveLeft();
	int playerMoveRight();
	int playerMoveUp();
	int playerMoveDown();
	bool playerLookLeft();
	bool playerLookRight();
	bool playerLookUp();
	bool playerLookDown();
	bool playerLeave();

	bool playerMarkedLeft();
	bool playerMarkedRight();
	bool playerMarkedUp();
	bool playerMarkedDown();

	Block* playerBlock();

	Block* playerBlockLeft();
	Block* playerBlockRight();
	Block* playerBlockUp();
	Block* playerBlockDown();

private:

	int col;
	int row;
	int mapSize;
	int oxygen;
	int numGolds;

	int paintedCount;

	int goldCollected;

	int seed;


	Block** map;
	Block* entrance;

	Object player;

	Brush* myBrush;

	queue<Block*> todo;

	void setBrush( int x, int y );
	void paint();
	void moveBrush( int x, int y );
	void moveBrushLeft();
	void moveBrushRight();
	void moveBrushUp();
	void moveBrushDown();
	void fillPainting();

	void PaintLeft();
	void PaintRight();
	void PaintUp();
	void PaintDown();

	// Refer to numeric keypad
	void Paint7();
	void Paint9();
	void Paint1();
	void Paint3();

	double fullness();
	void drawDetails();
	void queueAll();
	void queueEmpty();
	void queueWall( queue<Block*> &que );
	void queueSur( queue<Block*> &que, Block* target );
	void scatterGolds();
	void initPlayer();

	int playerVisit();

};

