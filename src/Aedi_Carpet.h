placeThread();
int facing = LEFT;
while ( threadUsed() + 1 < breathe() )
{
	lookAround();
	if ( lookLeft() && !markedLeft() )
	{
		moveLeft();
	}
	else if ( lookRight() && !markedRight() )
	{
		moveRight();
	}
	else if ( lookUp() && !markedUp() )
	{
		moveUp();
	}
	else if ( lookDown() && !markedDown() )
	{
		moveDown();
	}
	else
	{
		if ( !retrieveThread( 1 ) )
		{
			cout << "!!!" << endl;
		}
	}
	if ( breathe() % 1000 == 0 /*|| breathe() < 4201*/ )
	{
		system( "cls" );
		cout << "facing: " << facing << endl;
		cout << "breathe: " << breathe() << endl;
		cout << "x" << me->cave->playerBlock()->x; cout << endl;
		cout << "y" << me->cave->playerBlock()->y; cout << endl;
		backpack();
		sketchPad();
		//Sleep( 100 );
		//cin.get();
	}
	if ( threadUsed() == 0 )
	{
		break;
	}
}

sketchPad();
retrieveThread();
leave();