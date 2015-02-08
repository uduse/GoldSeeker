placeThread();
int facing = LEFT;
int initOxy = breathe();
const int contraction_factor = 40; // Smaller for more stable performace

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
		system( "clear" );
		//cout << "facing: " << facing << endl;
		//cout << "breathe: " << breathe() << endl;
		//cout << "x" << me->cave->playerBlock()->x; cout << endl;
		//cout << "y" << me->cave->playerBlock()->y; cout << endl;
		//backpack();
		sketchPad();
		//usleep( 500000 );
		cin.get();
	}
	if ( threadUsed() == 0 )
	{
		break;
	}

	// Thread Contraction
	else if ( threadUsed() >= initOxy / 20
			  && ( threadUsed() % ( initOxy / contraction_factor ) == 0 )
			  && rand() % ( initOxy * (int)log( initOxy ) / ( breathe() * (int)log( breathe() ) ) ) == 0 )
	{
		if ( markedLeft() && !markedRight() )
		{
			moveLeft();
			moveRight();
			//if ( moveRight() )
			//{
			//	moveDown();
			//	moveLeft();
			//}
			//facing = DOWN;
			facing = RIGHT;
		}
		else if ( markedUp() && !markedDown() )
		{
			moveUp();
			moveDown();
			//if ( moveDown() )
			//{
			//	moveLeft();
			//	moveUp();
			//}
			//facing = LEFT;
			facing = DOWN;
		}
		else if ( markedRight() && !markedLeft() )
		{
			moveRight();
			moveLeft();
			//if ( moveLeft() )
			//{
			//	moveUp();
			//	moveRight();
			//}
			//facing = UP;
			facing = LEFT;
		}
		else if ( markedDown() && !markedUp() )
		{
			moveDown();
			moveUp();
			//if ( moveUp() )
			//{
			//	moveRight();
			//	moveDown();
			//}
			//facing = RIGHT;
			facing = UP;
		}
	}
}

while ( retrieveThread( 1 ) )
{

}
sketchPad();
leave();
