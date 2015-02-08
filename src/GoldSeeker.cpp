/*!
* \project: GoldSeeker
*
* \date: 2015/01/29-2015/02/01 ~20 hours
*
* \author: Uduse
* \contact: wzy950618@gmail.com
*
* \Description:
* A program made as an interface for competitions of CS Club at UC Davis.
* Competitors will write a short algorithm in 2~3 hours, controlling the
* charactor to collect as many golds as possible in a randomly generated
* cave with limited oxygen.
*
*/

//#include "stdafx.h"
#include "Constants.h"
#include "GoldSeeker.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Cave.h"
#include <ctime>
#include <unistd.h>
#include <math.h>

using namespace std;

void example()
{
	//====================================//
	//  Your experienced friend helped you 
	//  to create an approach to search in a cave
	//  and gave you his note.
	//  
	//  He always make sure he survives, so
	//  he retreats when he thinks the
	//  oxygen is just enough for retrieving 
	//  through the threads he placed infront 
	//  of the entrance.
	//  
	//  However, he likes to follow his
	//  instinct and walk around randomly,
	//  hoping at some point he will get
	//  lucky.
	//====================================//

	//====================================//
	//        Tom Riddle's Note
	//====================================//

	// Place the red ball in front of the entrance
	placeThread();

	// Search until oxygen is just enough for retreating
	while ( threadUsed() < breathe() )
	{
		// Look around and check walls
		lookAround();

		// Follow your heart and move randomly
		switch ( rand() % 4 )
		{
		case 0:
			moveDown();
			break;
		case 1:
			moveRight();
			break;
		case 2:
			moveLeft();
			break;
		case 3:
			moveUp();
			break;
		}

		// For every 50 steps, 
		// take a break and check the Sketch Pad
		if ( breathe() % 50 == 0 )
		{
			system( "clear" ); // Clear Screen
			sketchPad();
			usleep( 100000 );  // Pause for 1ms
			//cin.get()  // Pause until Enter is pressed
		}
	}

	// Safety first, go back to entrance and leave the cave
	retrieveThread(); // Retrieve all the way back
	leave();

	// Enjoy the sketch after gets home.
	system( "clear" );
	sketchPad();
}

void explore()
{
	//====================================//
	//  However, you think you can do better
	//  than your friend, and here's your
	//  approach:
	//====================================//
	


}


void driver( int row, int col, int complexity )
{
	Cave newAdvanture( row, col, complexity );
	me = new Player( &newAdvanture );

	example();
	//explore();
	newAdvanture.printCave();
}


int main( int argc, char* argv[] )
{
	int seed;
	int sizeChoice;
	int complexChoice;
	int complexity;
	int row;
	int col;

	// If two additional command line parameters are passed,
	// 1. Map Size
	// 2. Complexity
	// And the seed will be randomly generated.
	// 
	// If three additional command line parameters are passed,
	// 1. Seed
	// 2. Map Size
	// 3. Complexity

	if ( argc == 3 )
	{
		seed = time( NULL ) % 1000;
		sizeChoice = atoi( argv[1] );
		complexChoice = atoi( argv[2] );
		srand( seed );
	}
	else if ( argc == 4 )
	{
		seed = atoi( argv[1] );
		sizeChoice = atoi( argv[2] );
		complexChoice = atoi( argv[3] );
		srand( seed );
	}
	else
	{
		//====================================//
		//  Seeding
		//====================================//

		cout << endl; cout << endl;
		cout << "===   Seed   ===" << endl; cout << endl;
		cout << "Your Choice >> ";
		cin >> seed;
		cout << endl; cout << endl;

		//seed = time( NULL ) % 1000;
		srand( seed );

		//====================================//
		//  Map Size Input
		//====================================//
		while ( true )
		{
			cout << "===   Map Size   ===" << endl;
			cout << "1. Small" << endl;
			cout << "2. Medium" << endl;
			cout << "3. Large" << endl;
			cout << "4. Extra Large" << endl; cout << endl;
			cout << "Your Choice >> ";
			cin >> sizeChoice;
			if ( sizeChoice < 1 || sizeChoice > 4 )
			{
				cout << "Invalid Input, please retry" << endl; cout << endl;
			}
			else
			{
				break;
			}
		}
		cout << endl; cout << endl;

		//====================================//
		//  Map Complexity Input
		//====================================//

		while ( true )
		{
			cout << "===   Map Complexity   ===" << endl;
			cout << "1. Simple" << endl;
			cout << "2. Medium" << endl;
			if ( sizeChoice >= MEDIUM )
			{
				cout << "3. Complex" << endl;
				if ( sizeChoice >= EXTRA_LARGE )
				{
					cout << "4. Extra Complex" << endl;
				}
			}
			cout << endl;

			cout << "Your Choice >> ";
			cin >> complexChoice;
			if ( complexChoice < 1 || complexChoice > 4
				 || ( sizeChoice < MEDIUM && complexChoice > 2 )
				 || ( sizeChoice < EXTRA_LARGE && complexChoice >3 ) )
			{
				cout << "Invalid Input, please retry." << endl; cout << endl;
			}
			else
			{
				break;
			}
		}

		cout << endl; cout << endl;
	}


	switch ( complexChoice )
	{
	case SIMPLE:
		complexity = BRUSH_SIMPLE;
		break;
	case FAIR:
		complexity = BRUSH_FAIR;
		break;
	case COMPLEX:
		complexity = BRUSH_COMPLEX;
		break;
	case EXTRA_COMPLEX:
		complexity = BRUSH_EXTRA_COMPLEX;
		break;
	default:
		break;
	}

	switch ( sizeChoice )
	{
	case SMALL:
		row = CAVE_SMALL_ROW;
		col = CAVE_SMALL_COL;
		break;
	case MEDIUM:
		row = CAVE_MEDIUM_ROW;
		col = CAVE_MEDIUM_COL;
		break;
	case LARGE:
		row = CAVE_LARGE_ROW;
		col = CAVE_LARGE_COL;
		break;
	case EXTRA_LARGE:
		row = CAVE_EXTRA_LARGE_ROW;
		col = CAVE_EXTRA_LARGE_COL;
		break;
	default:
		row = CAVE_SMALL_ROW;
		col = CAVE_SMALL_COL;
		break;
	}

	//====================================//
	//  Driver
	//====================================//

	driver( row, col, complexity );

	return 0;
}

