bool ahead( int &facing )
{
	switch ( facing )
	{
	case LEFT:
		if ( !markedUp() && lookUp() )
		{
			moveUp();
			facing = UP;
			return true;
		}
		else if ( !markedLeft() && lookLeft() )
		{
			moveLeft();
			facing = LEFT;
			return true;
		}
		else if ( !markedDown() && lookDown() )
		{
			moveDown();
			facing = DOWN;
			return true;
		}
		else
		{
			facing = DOWN;
			return false;
		}
		break;
	case RIGHT:
		if ( !markedDown() && lookDown() )
		{
			moveDown();
			facing = DOWN;
			return true;
		}
		else if ( !markedRight() && lookRight() )
		{
			moveRight();
			facing = RIGHT;
			return true;
		}
		else if ( !markedUp() && lookUp() )
		{
			moveUp();
			facing = UP;
			return true;
		}
		else
		{
			facing = UP;
			return false;
		}
		break;
	case UP:
		if ( !markedRight() && lookRight() )
		{
			moveRight();
			facing = RIGHT;
			return true;
		}
		else if ( !markedUp() && lookUp() )
		{
			moveUp();
			facing = UP;
			return true;
		}
		else if ( !markedLeft() && lookLeft() )
		{
			moveLeft();
			facing = LEFT;
			return true;
		}
		else
		{
			facing = LEFT;
			return false;
		}
		break;
	case DOWN:
		if ( !markedLeft() && lookLeft() )
		{
			moveLeft();
			facing = LEFT;
			return true;
		}
		else if ( !markedDown() && lookDown() )
		{
			moveDown();
			facing = DOWN;
			return true;
		}
		else if ( !markedRight() && lookRight() )
		{
			moveRight();
			facing = RIGHT;
			return true;
		}
		else
		{
			facing = RIGHT;
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}