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

#include "Ahead.h" //DELETE

using namespace std;

void intro()
{
	//======================================================================================================//
	//								
	//  You are an enthuastic gold seeker and you want to make a fortune by
	//  collecting golds left in a cave by ancient pirates.
	//  
	//  You found the entrance of the cave, and you know you can't stay in
	//  the cave forever to find all golds because oxygen in the cave 
	//  is limited and you want to get out the cave alive.
	//  
	//  So, you decided to develop an effecient way to explore the cave
	//  as much as possible and collect as many golds as possible before the
	//  cave run out of oxygen.
	//  															
	//======================================================================================================//

	//====================================//
	//  Your Moves
	//====================================//


	// You look in a certain direction.
	// return true when no wall
	bool lookLeft();
	bool lookRight();
	bool lookUp();
	bool lookDown();

	// You gaze in four directions.
	//
	// return true if anyone of the directions is a wall
	bool lookAround();


	// You walk towards a certain direction for one step.
	// Since it requires movement, the total oxygen in
	// the cave would decrease by 1.
	//
	// return false when you can't make that move because
	// there's a wall
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();


	// You look at your Sketch Pad, and check if a certain place
	// next to you has been visited.
	//
	// return true if visitied
	bool markedLeft();
	bool markedRight();
	bool markedUp();
	bool markedDown();

	// You leave the cave through the entrance
	// with all your golds in your backpack, alive.
	//
	// return false when you are not next to the entrance
	bool leave();


	// You take a breathe and detect the richness of
	// oxygen in the air with your well-trainted lungs.
	//
	// return amount of oxygen available in the cave
	int breathe();

	// You open your backpack and check the amount of
	// gold in that.
	//
	// retunr gold you collected.
	int backpack();


	// You are a skilled artist with perfect
	// space perception. During your exploration,
	// you mark all places you have been and
	// all walls you have noticed on your Sketch Pad.
	//
	// You look at your sketchPad closely,
	// with all details in eyes.
	// print the map you created for the cave
	void sketchPad();

	// You check your sketch pad and find out what
	// places you have been.
	//
	// return true if the place next to you in a
	// certain direction has been visited by you.
	bool markedLeft();
	bool markedRight();
	bool markedUp();
	bool markedDown();


	// You learned from the story about Theseus
	// and the Minotaur, so you brought with you
	// a Ball of Thread.
	//
	// You can place it at your current location, and
	// when you retrieve it, it will bring you back given
	// steps, or all the way back to where you placed it.
	//
	//
	// Since you're smart enough, you always rewind
	// useless threads to prevent loops whenever you
	// step back to somewhere you have placed thread on.
	//
	// return false when placing a ball that has been used
	bool placeThread();

	// The thread brings you all the way back to where
	// you placed it, then you pick up the thread.
	// return false when the ball is still in your hand
	bool retrieveThread();

	// The thread brings you back certain steps, you won't
	// pick up the thread in this case.
	// return false when the ball is still in your hand
	bool retrieveThread( int steps );

	// You take notes about the amount of threads of a
	// certain ball is used.
	// Since you're good at math, you converse the amount
	// of threads used based on oxyen.
	// So retrieving one unit of thread would cost
	// one unit of oxygen.
	//
	// return amount threads used
	int threadUsed();


}

void explore()
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
	//        Sean Davis' Note
	//====================================//


	//// Place the red ball in front of the entrance
	//placeRedThread();

	//// Search until oxygen is just enough for retreating
	//while ( redThreadUsed() < breathe() )
	//{
	//	switch ( rand() % 4 )
	//	{
	//	case 0:
	//		moveDown();
	//		break;
	//	case 1:
	//		moveRight();
	//		break;
	//	case 2:
	//		moveLeft();
	//		break;
	//	case 3:
	//		moveUp();
	//		break;
	//	}
	//	lookAround();
	//}

	//// Safety first, go back to entrance and leave the cave
	//retrieveRedThread();
	//leave();

	//// Enjoy the sketch after gets home.
	//sketchPad();

	//====================================//
	//  However, you think you can do better
	//  than your friend, and here's your
	//  approach:
	//====================================//

#include "Aedi_Circular.h"
	//#include "Aedi_Carpet.h"

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

	Cave newAdvanture( row, col, complexity );
	me = new Player( &newAdvanture );

	//newAdvanture.printCave();

	explore();

	newAdvanture.printCave();

	return 0;
}