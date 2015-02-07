#include "Player.h"

//====================================//
//  This Header is used to make your 
//  life easier.
//  Instead of me.move(), you only need
//  move() to do the same job.
//====================================//

Player* me;

bool lookLeft()
{
	return me->lookLeft();
}
bool lookRight()
{
	return me->lookRight();
}
bool lookUp()
{
	return me->lookUp();
}
bool lookDown()
{
	return me->lookDown();
}
bool lookAround()
{
	return me->lookAround();
}
bool moveLeft()
{
	return me->moveLeft();
}
bool moveRight()
{
	return me->moveRight();
}
bool moveUp()
{
	return me->moveUp();
}
bool moveDown()
{
	return me->moveDown();
}
bool markedLeft()
{
	return me->markedLeft();
}
bool markedRight()
{
	return me->markedRight();
}
bool markedUp()
{
	return me->markedUp();
}
bool markedDown()
{
	return me->markedDown();
}
bool leave()
{
	return me->leave();
}
int breathe()
{
	return me->breathe();
}
int backpack()
{
	return me->backpack();
}
void sketchPad()
{
	return me->sketchPad();
}
bool placeThread()
{
	return me->placeRedThread();
}
bool retrieveThread()
{
	return me->retrieveRedThread();
}
bool retrieveThread( int steps )
{
	return me->retrieveRedThread( steps );
}
int threadUsed()
{
	return me->redThreadUsed();
}


//int greenThreadUsed()
//{
//	return me->greenThreadUsed();
//}
//int blueThreadUsed()
//{
//	return me->blueThreadUsed();
//}

//bool placeGreenThread()
//{
//	return me->placeGreenThread();
//}
//bool placeBlueThread()
//{
//	return me->placeBlueThread();
//}

//bool retrieveGreenThread()
//{
//	return me->retrieveGreenThread();
//}
//bool retrieveBlueThread()
//{
//	return me->retrieveBlueThread();
//}

//void runLeft()
//{
//	return me->runLeft();
//}
//void runRight()
//{
//	return me->runRight();
//}
//void runUp()
//{
//	return me->runUp();
//}
//void runDown()
//{
//	return me->runDown();
//}
