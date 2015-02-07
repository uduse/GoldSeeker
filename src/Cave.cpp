//#include "stdafx.h"
#include "Constants.h"
#include "Cave.h"
#include <iomanip>




char color_blue[] = { 0x1b, '[', '0', ';', '3', '4', 'm', 0 };
char color_red[] = { 0x1b, '[', '0', ';', '3', '1', 'm', 0 };
char color_yellow[] = { 0x1b, '[', '0', ';', '3', '3', 'm', 0 };


char color_bold_blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
char color_bold_red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
char color_bold_yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };

char color_white_red[] = { 0x1b, '[', '0', ';', '3', '7', ';', '4', '1', 'm', 0 };

char color_red_yellow[] = { 0x1b, '[', '1', ';', '3', '1', ';', '4', '3', 'm', 0 };
char color_white_blue[] = { 0x1b, '[', '1', ';', '3', '7', ';', '4', '4', 'm', 0 };
char color_blue_green[] = { 0x1b, '[', '1', ';', '3', '4', ';', '4', '2', 'm', 0 };


char color_normal[] = { 0x1b, '[', '0', ';', '3', '9', 'm', 0 };





//cout << blue << "This text should be blue" << normal << endl;

using namespace std;

Cave::Cave()
{
}

Cave::Cave( int rowIn, int colIn, int c )
:newVisit( true ), col( colIn ), row( rowIn ), mapSize( colIn*rowIn ),
oxygen( rowIn*colIn * FULLNESS_FACTOR * OXYGEN_RICHNESS / 10 ),
numGolds( 0 ), paintedCount( 0 ), goldCollected( 0 )
{

	int brushSize = c / 10.0 * (double)mapSize / (double)4000;

	myBrush = new Brush( 0, 0, brushSize );

	map = new Block*[row];
	for ( int i = 0; i < row; i++ )
	{
		map[i] = new Block[col];
	}

	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			map[i][j].x = j;
			map[i][j].y = i;
		}
	}

	int brushRandX = MAP_MARGIN + myBrush->size + rand() % ( col - 2 * MAP_MARGIN - myBrush->size * 2 );
	int brushRandY = MAP_MARGIN + myBrush->size + rand() % ( row - 2 * MAP_MARGIN - myBrush->size * 2 );
	setBrush( brushRandX, brushRandY );
	fillPainting();
	drawDetails();
	scatterGolds();
	initPlayer();
	//printCave();
	//printCaveStatus();
}

Cave::~Cave()
{
}


////   Player Operations    ///////////////////////////

void Cave::initPlayer()
{
	player.set( entrance->x, entrance->y + 1 );
	playerBlock()->visited = true;
}

// if can't move, return -1, otherwise, return even number

int Cave::playerMoveLeft()
{
	if ( playerLookLeft() )
	{
		player.x -= 1;
		return playerVisit();
	}
	else
	{
		return -1;
	}
}

int Cave::playerMoveRight()
{
	if ( playerLookRight() )
	{
		player.x += 1;
		return playerVisit();
	}
	else
	{
		return -1;
	}
}

int Cave::playerMoveUp()
{
	if ( playerLookUp() )
	{
		player.y -= 1;
		return playerVisit();
	}
	else
	{
		return -1;
	}
}

int Cave::playerMoveDown()
{
	if ( playerLookDown() )
	{
		player.y += 1;
		return playerVisit();
	}
	else
	{
		return -1;
	}
}

bool Cave::playerLookLeft()
{
	Block* target = &map[player.y][player.x - 1];
	if ( target->status == STATUS_SOLID )
	{
		target->collided = true;
	}
	return target->status < STATUS_SOLID ? true : false;
}

bool Cave::playerLookRight()
{
	Block* target = &map[player.y][player.x + 1];
	if ( target->status == STATUS_SOLID )
	{
		target->collided = true;
	}
	return target->status < STATUS_SOLID ? true : false;
}

bool Cave::playerLookUp()
{
	Block* target = &map[player.y - 1][player.x];
	if ( target->status == STATUS_SOLID )
	{
		target->collided = true;
	}
	return target->status < STATUS_SOLID ? true : false;
}

bool Cave::playerLookDown()
{
	Block* target = &map[player.y + 1][player.x];
	if ( target->status == STATUS_SOLID )
	{
		target->collided = true;
	}
	return target->status < STATUS_SOLID ? true : false;
}

bool Cave::playerMarkedLeft()
{
	return playerBlockLeft()->visited || playerBlockLeft()->collided;
}

bool Cave::playerMarkedRight()
{
	return playerBlockRight()->visited || playerBlockRight()->collided;
}

bool Cave::playerMarkedUp()
{
	return playerBlockUp()->visited || playerBlockUp()->collided;
}

bool Cave::playerMarkedDown()
{
	return playerBlockDown()->visited || playerBlockDown()->collided;
}

int Cave::playerVisit()
{
	oxygen--;
	if ( oxygen < 0 )
	{
		printTrails();
		cout << "You are suffocated to death!" << endl;
		cout << "You have collected " << goldCollected <<
			( goldCollected <= 1 ? " golds " : " gold " ) << endl;

		if ( goldCollected >= 1 )
		{
			cout << "But unfortunately you won't have chance to use "
				<< ( goldCollected <= 1 ? "it." : "them." ) << endl; cout << endl;
		}
		exit( 0 );
	}

	Block* target = &map[player.y][player.x];
	target->visited == true ? newVisit = false : newVisit = true;
	target->visited = true;
	switch ( target->status )
	{
	case STATUS_EMPTY:
		return STATUS_EMPTY;

	case STATUS_GOLD:
		goldCollected++;
		target->goldCollected = true;
		target->setStatus( STATUS_EMPTY );
		return STATUS_GOLD;

	case STATUS_ENTRANCE:
		cout << "Exit!!" << endl;
		printCave();
		printTrails();
		exit( 0 );
		return STATUS_ENTRANCE;

	default:
		cout << "Default";
		return STATUS_EMPTY;
	}
}

bool Cave::playerLeave()
{
	if ( abs( player.x - entrance->x ) + abs( player.y - entrance->y ) == 1 )
	{
		cout << "You left the cave with " << goldCollected << " gold" << ( goldCollected > 1 ? "s " : " " ) << "in your backpack!" << endl;
		cout << endl;
		return true;
	}
	else
	{
		cout << "Can't leave because you're not next to the exit!!" << endl;
		return false;
	}
}

////   Painting    ///////////////////////////

void Cave::setBrush( int x, int y )
{
	myBrush->move( x, y );
	paint();
}

void Cave::fillPainting()
{
	int action = 0;
	//int lastAction = 0;
	while ( fullness() < FULLNESS_FACTOR )
	{
		//myBrush->print();
		//printCave();
		//cin.get();
		action = rand() % 8;
		//action += lastAction;
		//action %= 8;
		//lastAction = action;
		//cout << "action: " << action << endl;

		for ( int times = 0; times < rand() % BRUSH_STREAK_FACTOR + 1; times++ )
		{
			switch ( action )
			{
			case 0:
				PaintLeft();
				break;
			case 1:
				PaintRight();
				break;
			case 2:
				PaintUp();
				break;
			case 3:
				PaintDown();
				break;
			case 4:
				Paint7();
				break;
			case 5:
				Paint9();
				break;
			case 6:
				Paint1();
				break;
			case 7:
				Paint3();
				break;
			default:
				break;
			}
		}
	}
}

double Cave::fullness()
{

	// WAY TO SLOW!!!!
	//queueAll();
	//int count = 0;
	//while ( !todo.empty() )
	//{
	//	if ( todo.front()->painted )
	//	{
	//		count++;
	//	}
	//	todo.pop();
	//}
	//return (double)count / (double)mapSize;

	return (double)paintedCount / (double)mapSize;
}

void Cave::scatterGolds()
{
	queueEmpty();
	while ( !todo.empty() )
	{
		if ( rand() % 1000 < GOLD_RICHNESS * 1000 )
		{
			todo.front()->setStatus( STATUS_GOLD );
			numGolds++;
		}
		todo.pop();
	}
}

void Cave::moveBrushLeft()
{
	moveBrush( myBrush->x - 1, myBrush->y );
	paint();
}

void Cave::moveBrushRight()
{
	moveBrush( myBrush->x + 1, myBrush->y );
	paint();
}

void Cave::moveBrushUp()
{
	moveBrush( myBrush->x, myBrush->y - 1 );
	paint();
}

void Cave::moveBrushDown()
{
	moveBrush( myBrush->x, myBrush->y + 1 );
	paint();
}

void Cave::moveBrush( int x, int y )
{
	if ( x >= MAP_MARGIN + myBrush->size
		 && x < col - MAP_MARGIN - myBrush->size
		 && y >= MAP_MARGIN + myBrush->size
		 && y < row - MAP_MARGIN - myBrush->size )
	{
		myBrush->move( x, y );
	}
	else
	{
	}
}

void Cave::drawDetails()
{
	//bool entranceAssigned = false;
	queue<Block*> que;
	queue<Block*> entranceQueue;


	queueWall( que );
	while ( !que.empty() )
	{
		//printCave();
		Block* target = que.front();
		int left = map[target->y][target->x - 1].getStatus();
		int right = map[target->y][target->x + 1].getStatus();
		int up = map[target->y - 1][target->x].getStatus();
		int down = map[target->y + 1][target->x].getStatus();

		if ( left == STATUS_SOLID && right == STATUS_SOLID )
		{
			if ( up == STATUS_SOLID || down == STATUS_SOLID )
			{
				// X X X
				// X - X
				//
				target->assignDisplay( WALL_HORIZONTAL );
				if ( up == STATUS_SOLID )
				{
					entranceQueue.push( target );
				}
			}
			else
			{
				//
				// X = X
				//
				target->assignDisplay( WALL_HORIZONTAL_CORRIDOR );
			}
		}
		else if ( up == STATUS_SOLID && down == STATUS_SOLID )
		{
			if ( left == STATUS_SOLID || right == STATUS_SOLID )
			{
				//   X X
				//   | X
				//   X X
				target->assignDisplay( WALL_VERTICAL );
			}
			else
			{
				//   X
				//   |
				//   X
				target->assignDisplay( WALL_VERTICAL_CORRIDOR );
			}
		}
		else if ( ( left == STATUS_SOLID && up == STATUS_SOLID )
				  || ( right == STATUS_SOLID && down == STATUS_SOLID ) )
		{
			target->assignDisplay( WALL_1 );
		}
		else if ( ( left == STATUS_SOLID && down == STATUS_SOLID )
				  || ( right == STATUS_SOLID && up == STATUS_SOLID ) )
		{
			target->assignDisplay( WALL_3 );
		}
		else if ( left == STATUS_SOLID )
		{
			target->assignDisplay( WALL_SINGLE_RIGHT );
		}
		else if ( right == STATUS_SOLID )
		{
			target->assignDisplay( WALL_SINGLE_LEFT );
		}
		else if ( down == STATUS_SOLID )
		{
			target->assignDisplay( WALL_SINGLE_UP );
		}
		else if ( up == STATUS_SOLID )
		{
			target->assignDisplay( WALL_SINGLE_DOWN );
		}
		else
		{
			target->assignDisplay( WALL_ALONE );
		}

		que.pop();
	}


	//====================================//
	//  Randomly generate an entrance
	//====================================//
	int size = entranceQueue.size() - 1;
	if ( size > 2 )
	{
		int entrancePos = rand() % size;
		entranceQueue.pop();
		for ( int i = 0; i < entrancePos; i++ )
		{
			entranceQueue.pop();
		}
		entranceQueue.front()->setStatus( STATUS_ENTRANCE );
		entrance = entranceQueue.front();
		entrance->visited = true;
	}
	entranceQueue.emplace();


}

void Cave::paint()
{
	int startX = myBrush->x - myBrush->size;
	int startY = myBrush->y - myBrush->size;

	for ( int i = 0; i < myBrush->size * 2 + 1; i++ )
	{
		for ( int j = 0; j < myBrush->size * 2 + 1; j++ )
		{

			int currentX = startX + i;
			int currentY = startY + j;

			if ( abs( currentX - myBrush->x ) + abs( currentY - myBrush->y ) <= myBrush->size // get diamond shaped
				 && abs( myBrush->y - currentY ) <= myBrush->size - myBrush->size / 3 // trim diamond
				 && abs( myBrush->x - currentX ) <= myBrush->size - myBrush->size / 3 )
			{
				//map[currentY][currentX].display = EMPTY;
				Block* currentBlock = &map[currentY][currentX];
				if ( currentBlock->painted == false )
				{
					map[currentY][currentX].painted = true;
					currentBlock->setStatus( STATUS_EMPTY );// make = empty
					paintedCount++;
				}
			}

		}
	}
}

void Cave::PaintLeft()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		moveBrushLeft();
	}
}

void Cave::PaintRight()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		moveBrushRight();
	}
}

void Cave::PaintUp()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		moveBrushUp();
	}
}

void Cave::PaintDown()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		moveBrushDown();
	}
}

void Cave::Paint7()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		i % 2 == 0 ? moveBrushLeft() : moveBrushUp();
	}
}

void Cave::Paint9()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		i % 2 == 0 ? moveBrushRight() : moveBrushUp();
	}
}

void Cave::Paint1()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		i % 2 == 0 ? moveBrushLeft() : moveBrushDown();
	}
}

void Cave::Paint3()
{
	for ( int i = 0; i < myBrush->size * BRUSH_LENGTH; i++ )
	{
		i % 2 == 0 ? moveBrushRight() : moveBrushDown();
	}
}

////   Helpers    ///////////////////////////

void Cave::queueAll()
{
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			todo.push( &map[i][j] );
		}
	}
}

void Cave::queueEmpty()
{
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			Block* target = &map[i][j];
			if ( target->status == STATUS_EMPTY )
			{
				todo.push( target );
			}
		}
	}
}

void Cave::queueWall( queue<Block*> &que )
{
	queueAll();
	while ( !todo.empty() )
	{
		Block* target = todo.front();

		//if ( target->x == 5 && target->y == 6 )
		//{
		//	cout << "F" << endl;
		//}
		// If on margin, then give up
		if ( target->x == 0 || target->y == 0 || target->x == col - 1 || target->y == row - 1 )
		{
			todo.pop();
			continue;
		}
		if ( target->status == STATUS_SOLID )
		{
			int solidCount = 0;
			queue<Block*> que2;
			queueSur( que2, target );

			while ( !que2.empty() )
			{
				Block* neighbor = que2.front();
				if ( neighbor->status == STATUS_SOLID )
				{
					solidCount++;
				}
				que2.pop();
			}
			if ( solidCount >= 0 && solidCount < 4 )
			{
				que.push( target );
			}
		}
		todo.pop();
	}
}

void Cave::queueSur( queue<Block*> &que, Block* target )
{
	if ( target->x > 0 && target->x < col - 1 && target->y > 0 && target->y < row - 1 )
	{
		que.push( &map[target->y + 1][target->x] );
		que.push( &map[target->y - 1][target->x] );
		que.push( &map[target->y][target->x + 1] );
		que.push( &map[target->y][target->x - 1] );
	}
}

Block* Cave::playerBlock()
{
	return &map[player.y][player.x];
}

Block* Cave::playerBlockLeft()
{
	return &map[player.y][player.x - 1];
}

Block* Cave::playerBlockRight()
{
	return &map[player.y][player.x + 1];
}

Block* Cave::playerBlockUp()
{
	return &map[player.y - 1][player.x];
}

Block* Cave::playerBlockDown()
{
	return &map[player.y + 1][player.x];
}

int Cave::getOxygen()
{
	return oxygen;
}

////   Printers    ///////////////////////////

void Cave::printCave()
{
	//HANDLE  hConsole;
	//hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

	//cout << " ";
	//for ( int x = 0; x < 16; x++ )
	//{
	//	cout << hex << x;
	//}

	cout << endl;
	for ( int i = 0; i < row; i++ )
	{
		//i < 16 ? cout << hex << i : cout << " ";

		for ( int j = 0; j < col; j++ )
		{
			//if ( myBrush->x == j && myBrush->y == i )
			//{
			//	//SetConsoleTextAttribute( hConsole, 12 );
			//	cout << " ";
			//	//SetConsoleTextAttribute( hConsole, 7 );
			//}
			//else 
			if ( player.x == j && player.y == i )
			{
				//SetConsoleTextAttribute( hConsole, 207 );
				cout << color_red_yellow << (char)DISPLAY_PLAYER << color_normal;
				//SetConsoleTextAttribute( hConsole, 7 );
			}
			else
			{
				Block* target = &map[i][j];
				switch ( target->status )
				{
				case STATUS_EMPTY:
					cout << target->display;
					break;
				case STATUS_SOLID:
					cout << target->display;
					break;
				case STATUS_GOLD:
					//SetConsoleTextAttribute( hConsole, 14 );
					cout << color_bold_yellow;
					cout << target->display;
					cout << color_normal;
					//SetConsoleTextAttribute( hConsole, 7 );
					break;
				case STATUS_ENTRANCE:
					//SetConsoleTextAttribute( hConsole, 252 );
					cout << color_blue_green << (char)DISPLAY_ENTRANCE << color_normal;
					//cout << target->display;
					//SetConsoleTextAttribute( hConsole, 7 );
					break;
				default:
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl;
	printStats();
}

void Cave::printCaveStatus()
{
	//HANDLE  hConsole;
	//hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	cout << endl;
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			cout << map[i][j].status;
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}

void Cave::printStats()
{
	int totalOxy = (int)( row*col * FULLNESS_FACTOR * OXYGEN_RICHNESS ) / 10;
	cout << "Oxygen: " << oxygen << "/" << totalOxy
		<< " ( " << setprecision( 2 ) << (double)( 100 * oxygen / totalOxy ) << "% )" << endl;
	cout << "Golds: " << goldCollected << "/" << numGolds
		<< " ( " << setprecision( 2 ) << (double)( 100 * goldCollected / numGolds ) << "% )" << endl;
	cout << endl;

	int oxygenBonus;

	const int bonus_Threshold = 2;
	const int bonus_factor = 3;
	if ( totalOxy / oxygen >= bonus_Threshold )
	{
		oxygenBonus = (double)(oxygen)*GOLD_RICHNESS / bonus_factor;
	}
	else
	{
		oxygenBonus = (double)( totalOxy / bonus_Threshold )*GOLD_RICHNESS / bonus_factor;
	}

	int score = goldCollected + oxygenBonus;

	cout << "Score: " << score;
	cout << endl;
	cout << endl;
}

void Cave::printTrails()
{
	//HANDLE  hConsole;
	//hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

	//cout << " ";
	//for ( int x = 0; x < 16; x++ )
	//{
	//	cout << hex << x;
	//}

	cout << endl;
	for ( int i = 0; i < row; i++ )
	{
		//i < 16 ? cout << hex << i : cout << " ";

		for ( int j = 0; j < col; j++ )
		{
			if ( player.x == j && player.y == i )
			{
				//SetConsoleTextAttribute( hConsole, 207 );
				cout << color_red_yellow << (char)DISPLAY_PLAYER << color_normal;
				//SetConsoleTextAttribute( hConsole, 7 );
			}
			else
			{
				Block* target = &map[i][j];
				if ( target == entrance )
				{
					//SetConsoleTextAttribute( hConsole, 252 );
					cout << color_blue_green << (char)DISPLAY_ENTRANCE << color_normal;
					//SetConsoleTextAttribute( hConsole, 7 );
				}
				else if ( target->collided )
				{
					//SetConsoleTextAttribute( hConsole, 12 );
					cout << color_red;
					cout << DISPLAY_COLLIDE << color_normal;
					cout << color_normal;
					//SetConsoleTextAttribute( hConsole, 7 );
				}
				else if ( target->threaded )
				{
					cout << color_white_blue;
					cout << DISPLAY_THREAD;
					cout << color_normal;
				}
				else if ( target->goldCollected )
				{
					//if ( target->threaded )
					//{
					//SetConsoleTextAttribute( hConsole, 144 );
					//}

					cout << color_yellow;
					cout << DISPLAY_GOLD;
					cout << color_normal;
					//SetConsoleTextAttribute( hConsole, 7 );
				}
				else if ( target->visited )
				{
					//if ( target->threaded )
					//{
					//SetConsoleTextAttribute( hConsole, 144 );
					//}
					cout << DISPLAY_TRACE;
					//SetConsoleTextAttribute( hConsole, 7 );
				}
				//else if ( target->status == STATUS_ENTRANCE )
				//{
				//	//SetConsoleTextAttribute( hConsole, 252 );
				//	cout << entrance->display;
				//	//SetConsoleTextAttribute( hConsole, 7 );
				//}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	cout << endl; cout << endl;
}

Brush::Brush( int x, int y, int size )
{
	this->x = x;
	this->y = y;
	this->size = size;
}

void Brush::print()
{
	cout << "Brush" << endl;
	cout << "x >> " << x << endl;
	cout << "y >> " << y << endl;
}

void Brush::move( int x, int y )
{
	this->x = x;
	this->y = y;
}

//Block::Block( int x, int y )
//{
//	this->x = x;
//	this->y = y;
//	painted = false;
//}

Block::Block()
{
	setStatus( STATUS_SOLID );
	painted = false;
	collided = false;
	visited = false;
	goldCollected = false;
}

int Block::getStatus()
{
	return status;
}

void Block::assignDisplay()
{
	// 0: Empty
	// 1: Gold
	// 2: Solid
	// 3: Rock
	// 4: Wall

	switch ( status )
	{
	case STATUS_EMPTY:
		display = DISPLAY_EMPTY;
		break;
	case STATUS_GOLD:
		display = DISPLAY_GOLD;
		break;
	case STATUS_SOLID:
		display = DISPLAY_SOLID;
		break;
	case STATUS_ENTRANCE:
		display = DISPLAY_ENTRANCE;
		break;
	default:
		break;
	}
}

void Block::assignDisplay( char ch )
{
	display = ch;
}

void Block::setStatus( int index )
{
	status = index;
	assignDisplay();
}

void Block::print()
{
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "status: " << status << endl;
	cout << "display: " << display << endl;
	cout << "painted: " << painted << endl;
}

void Object::set( int xIN, int yIN )
{
	x = xIN;
	y = yIN;
}
