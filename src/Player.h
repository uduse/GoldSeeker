#pragma once
#include "Cave.h"
#include <list>


class Cave;
class Block;
using namespace std;



class Player
{
public:
	Player();
	Player( Cave* caveIn );
	~Player();


	bool lookLeft();
	bool lookRight();
	bool lookUp();
	bool lookDown();
	bool lookAround();

	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();

	void runLeft();
	void runRight();
	void runUp();
	void runDown();

	bool leave();

	int breathe() const;
	int backpack() const;

	void sketchPad() const;

	bool markedLeft();
	bool markedRight();
	bool markedUp();
	bool markedDown();

	bool placeRedThread();
	bool placeGreenThread();
	bool placeBlueThread();

	bool retrieveRedThread();
	bool retrieveRedThread( int steps );
	bool retrieveGreenThread();
	bool retrieveBlueThread();

	int redThreadUsed();
	int greenThreadUsed();
	int blueThreadUsed();

private:
	Cave* cave;
	int goldCollected;

	bool* threadPlaced;
	bool newVisit;

	bool placeTread( int index );
	bool retrieveTread( int index );
	bool retrieveTread( int index, int steps );
	list<Block*>* thread;
	list<Block*>::iterator itr;
	list<Block*>::iterator itr2;

	bool visit( int status );
	void record( int index );
	void recordAll();
};

