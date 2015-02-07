placeThread();
int facing = LEFT;
int initOxy = breathe();
const int contraction_factor = 50;

while ( threadUsed() + 1 < breathe() )
{
	lookAround();
	if ( !ahead( facing ) )
	{
		if ( !retrieveThread( 1 ) )
		{
			cout << "!!!" << endl;
		}
	}
	if ( breathe() % 100 == 0 /*|| breathe() < 4201*/ )
	{
		//system( "clear" );
		//cout << "facing: " << facing << endl;
		//cout << "breathe: " << breathe() << endl;
		//cout << "x" << me->cave->playerBlock()->x; cout << endl;
		//cout << "y" << me->cave->playerBlock()->y; cout << endl;
		//backpack();
		//sketchPad();
		//usleep( 500000 );
		//cin.get();
	}
	if ( threadUsed() == 0 )
	{
		break;
	}

	// Thread Contraction
	else if ( threadUsed() >= initOxy / 50
			  && ( threadUsed( ) % ( initOxy / contraction_factor ) == 0 )
			  && rand() % ( initOxy * (int)log( initOxy ) / ( breathe() * (int)log( breathe() ) ) ) == 0 )
	{
		if ( markedLeft() )
		{
			moveLeft();
			moveRight();
			facing = RIGHT;
		}
		else if ( markedUp() )
		{
			moveUp();
			moveDown();
			facing = DOWN;
		}
		else if ( markedRight() )
		{
			moveRight();
			moveLeft();
			facing = LEFT;
		}
		else if ( markedDown() )
		{
			moveDown();
			moveUp();
			facing = UP;
		}
	}
}

sketchPad();
retrieveThread();
leave();
