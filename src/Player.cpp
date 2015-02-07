//#include "stdafx.h"
#include "Player.h"
#include "Constants.h"


Player::Player():goldCollected( 0 )
{

}

Player::Player( Cave* caveIn ) : goldCollected( 0 )
{
	this->cave = caveIn;
	threadPlaced = new bool[NUM_THREADS]{false};
	thread = new list<Block*>[NUM_THREADS];
}

Player::~Player()
{
}

bool Player::moveLeft()
{
	int status = cave->playerMoveLeft();
	bool moved = visit( status );
	if ( moved )
	{
		recordAll();
	}
	return moved;
}

bool Player::moveRight()
{
	int status = cave->playerMoveRight();
	bool moved = visit( status );
	if ( moved )
	{
		recordAll();
	}
	return moved;
}

bool Player::moveUp()
{
	int status = cave->playerMoveUp();
	bool moved = visit( status );
	if ( moved )
	{
		recordAll();
	}
	return moved;
}

bool Player::moveDown()
{
	int status = cave->playerMoveDown();
	bool moved = visit( status );
	if ( moved )
	{
		recordAll();
	}
	return moved;
}

bool Player::lookLeft()
{
	return cave->playerLookLeft();
}

bool Player::lookRight()
{
	return cave->playerLookRight();
}

bool Player::lookUp()
{
	return cave->playerLookUp();
}

bool Player::lookDown()
{
	return cave->playerLookDown();
}

bool Player::lookAround()
{
	bool left = lookLeft();
	bool right = lookRight();
	bool up = lookUp();
	bool down = lookDown();
	if ( left && right && up && down )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::runLeft()
{
	while ( moveLeft() )
	{

	}
}

void Player::runRight()
{
	while ( moveRight() )
	{

	}
}

void Player::runUp()
{
	while ( moveUp() )
	{

	}
}

void Player::runDown()
{
	while ( moveDown() )
	{

	}
}

bool Player::markedLeft()
{
	return cave->playerMarkedLeft();
}

bool Player::markedRight()
{
	return cave->playerMarkedRight();
}

bool Player::markedUp()
{
	return cave->playerMarkedUp();
}

bool Player::markedDown()
{
	return cave->playerMarkedDown();
}

bool Player::leave()
{
	return cave->playerLeave();
}

bool Player::visit( int status )
{
	switch ( status )
	{
	case -1:
		//cout << "Wall!" << endl;
		return false;
		break;

	case STATUS_EMPTY:
		return true;

	case STATUS_GOLD:
		goldCollected++;
		return true;

	default:
		return false;
	}
}

void Player::sketchPad() const
{
	cave->printTrails();
}

int Player::breathe() const
{
	return cave->getOxygen();
}

int Player::backpack() const
{
	if ( goldCollected <= 10 )
	{
		cout << "There're only " << goldCollected << " gold" << ( goldCollected <= 1 ? " " : "s" ) << " in your backpack" << endl;
	}
	else
	{
		cout << "There're " << goldCollected << " golds in your backpack!" << endl;
	}
	return goldCollected;
}

////   Balls of Thread    ///////////////////////////

bool Player::placeRedThread()
{
	return placeTread( RED );
}

bool Player::placeGreenThread()
{
	return placeTread( GREEN );
}

bool Player::placeBlueThread()
{
	return placeTread( BLUE );
}

bool Player::retrieveRedThread()
{
	return retrieveTread( RED );
}

bool Player::retrieveRedThread( int steps )
{
	return retrieveTread( RED, steps );
}

bool Player::retrieveGreenThread()
{
	return retrieveTread( GREEN );
}

bool Player::retrieveBlueThread()
{
	return retrieveTread( BLUE );
}

bool Player::placeTread( int color )
{
	if ( !threadPlaced[color] )
	{
		threadPlaced[color] = true;

		// Start by recording current location
		record( color );

		return true;
	}
	else
	{
		cout << "You have already placed this Ball of Thread!" << endl;
		return false;
	}
}

void Player::record( int color )
{
	//sketchPad();
	if ( threadPlaced[color] )
	{
		thread[color].push_front( cave->playerBlock() );
		thread[color].front()->threaded = true;

		if ( thread[color].size() > 2 )
		{
			// Rewind Threads to prevent loops
			if ( cave->newVisit != true )
			{
				for ( itr = ++thread[color].begin(); itr != thread[color].end(); itr++ )
				{
					if ( *itr == *thread[color].begin() )
					{
						for ( itr2 = thread[color].begin(); itr2 != itr; )
						{
							thread[color].front()->threaded = false;
							itr2++;
							thread[color].pop_front();
						}
						thread[color].front()->threaded = true;
						//thread[color].front()->threaded = false;
						//thread[color].pop_front();
						break;
					}
				}
			}

		}
	}
}

void Player::recordAll()
{
	for ( int index = 0; index < NUM_THREADS; index++ )
	{
		record( index );
	}
}

bool Player::retrieveTread( int color )
{
	if ( threadPlaced[color] )
	{
		threadPlaced[color] = false;

		// Pop current location
		if ( thread[color].size() >= 1 )
		{
			thread[color].front()->threaded = false;
			thread[color].pop_front();
		}

		while ( !thread[color].empty() )
		{
			thread[color].front()->threaded = false;
			int x = thread[color].front()->x;
			int y = thread[color].front()->y;
			int myX = cave->playerBlock()->x;
			int myY = cave->playerBlock()->y;

			if ( x > myX )
			{
				moveRight();
			}
			else if ( x < myX )
			{
				moveLeft();
			}
			else if ( y < myY )
			{
				moveUp();
			}
			else if ( y > myY )
			{
				moveDown();
			}

			//cout << "x: " << x << endl;
			//cout << "y: " << y << endl;
			thread[color].pop_front();
		}
		return true;
	}
	else
	{
		cout << "The ";
		switch ( color )
		{
		case RED:
			cout << "Red ";
			break;
		case GREEN:
			cout << "Green ";
			break;
		case BLUE:
			cout << "Blue ";
			break;
		default:
			break;
		}
		cout << "Ball of Thread isn't in use." << endl;
		return false;
	}

}

bool Player::retrieveTread( int color, int steps )
{
	if ( threadPlaced[color] )
	{
		threadPlaced[color] = false;

		// Pop current location
		if ( thread[color].size() >= 1 )
		{
			thread[color].front()->threaded = false;
			thread[color].pop_front();
		}

		while ( !thread[color].empty() && steps > 0 )
		{
			thread[color].front()->threaded = false;
			int x = thread[color].front()->x;
			int y = thread[color].front()->y;
			int myX = cave->playerBlock()->x;
			int myY = cave->playerBlock()->y;

			if ( x > myX )
			{
				moveRight();
			}
			else if ( x < myX )
			{
				moveLeft();
			}
			else if ( y < myY )
			{
				moveUp();
			}
			else if ( y > myY )
			{
				moveDown();
			}

			//cout << "x: " << x << endl;
			//cout << "y: " << y << endl;
			thread[color].pop_front();
			steps--;

			if ( thread[color].size() % 20 == 0 )
			{
				cin.get();
				sketchPad();
			}

		}

		if ( !thread[color].empty() )
		{
			threadPlaced[color] = true;
			record( color );
		}
		return true;
	}
	else
	{
		cout << "The ";
		switch ( color )
		{
		case RED:
			cout << "Red ";
			break;
		case GREEN:
			cout << "Green ";
			break;
		case BLUE:
			cout << "Blue ";
			break;
		default:
			break;
		}
		cout << "Ball of Thread isn't in use." << endl;
		return false;
	}
}

int Player::redThreadUsed()
{
	return thread[RED].size();
}

int Player::greenThreadUsed()
{
	return thread[GREEN].size();
}

int Player::blueThreadUsed()
{
	return thread[BLUE].size();
}
