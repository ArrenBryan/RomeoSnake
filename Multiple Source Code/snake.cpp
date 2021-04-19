#include "snake.hpp"

void Snake__create(LinkedList *l)
{
	SnakeBody *tempValue;
	void *tempValuePtr;
	Node *newNode;

	tempValue = SnakeHead__valueCreate();
	tempValuePtr = tempValue;
	newNode = Node__create(tempValuePtr);
	
	LinkedList__addNode(l, newNode);
	
	Snake__eatingProcess(l);
	Snake__eatingProcess(l);
}

SnakeStats *SnakeStats__create()
{
	SnakeStats *ss = (SnakeStats *)malloc(sizeof(SnakeStats));
	
	if (ss == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
    
    ss->snakeAlive = 1;
    ss->snakeSpeed = 90;
    ss->snakeBoostGauge = 40;
    
	return ss;
}

SnakeBody *SnakeHead__valueCreate()
{
	int randDir = rand() %3 + 1;
	SnakeBody *snakeHead;
	
	snakeHead = (SnakeBody *)malloc(sizeof(SnakeBody));
	snakeHead->coord = (Point *)malloc(sizeof(Point));
	
	snakeHead->coord->coorX = 1000 / 2; // 500x is default position (on middle of the map)
	snakeHead->coord->coorY = 600 / 2; // 300y is default position (on middle of the map)
    snakeHead->turn = noDirection; // current turn of snake (0 means noDirection)

    if (randDir == 1) snakeHead->direction = right; // current direction of snake
	else if (randDir == 2) snakeHead->direction = left; // current direction of snake
	else if (randDir == 3) snakeHead->direction = up; // current direction of snake
	else if (randDir == 4) snakeHead->direction = right; // current direction of snake
	
	return snakeHead;
}

SnakeBody *SnakeBody__valueCreate(LinkedList *l)
{
	SnakeBody *snakeBody;
	Point addPoint;
	
	snakeBody = (SnakeBody *)malloc(sizeof(SnakeBody));
	snakeBody->coord = (Point *)malloc(sizeof(Point));
	
	if (((SnakeBody*) l->head->value)->direction == right)
    { 
        addPoint.coorX = -50;
        addPoint.coorY = 0;
    }
    else if (((SnakeBody*) l->head->value)->direction == left)
    { 
        addPoint.coorX = 50;
        addPoint.coorY = 0;
    }
    else if (((SnakeBody*) l->head->value)->direction == up)
    { 
        addPoint.coorX = 0;
        addPoint.coorY = 50;
    }
    else if (((SnakeBody*) l->head->value)->direction == down)
    { 
        addPoint.coorX = 0;
        addPoint.coorY = -50;
    }
	
    snakeBody->coord->coorX = ((SnakeBody*)l->tail->value)->coord->coorX + addPoint.coorX;
    snakeBody->coord->coorY = ((SnakeBody*)l->tail->value)->coord->coorY + addPoint.coorY;
    snakeBody->turn = ((SnakeBody*)l->tail->value)->turn;
    snakeBody->direction = ((SnakeBody*)l->tail->value)->direction;

	return snakeBody;
}

void Snake__updateCoord(LinkedList *l, Point addPoint)
{
	Node *curr = (Node *)malloc(sizeof(Node));

    if (curr == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }

    curr = l->tail;
	
	while (curr->prev != NULL) 
	{
		((SnakeBody*) curr->value)->coord->coorX = ((SnakeBody*) curr->prev->value)->coord->coorX;
		((SnakeBody*) curr->value)->coord->coorY = ((SnakeBody*) curr->prev->value)->coord->coorY;
		((SnakeBody*) curr->value)->turn = ((SnakeBody*) curr->prev->value)->turn;
		((SnakeBody*) curr->value)->direction = ((SnakeBody*) curr->prev->value)->direction;
		curr = curr->prev;
	}
	
	((SnakeBody*) curr->value)->coord->coorX = ((SnakeBody*) curr->value)->coord->coorX + addPoint.coorX;
	((SnakeBody*) curr->value)->coord->coorY = ((SnakeBody*) curr->value)->coord->coorY + addPoint.coorY;
}

void Snake__controller(LinkedList *l, SnakeStats *ss, int gridSize)
{
    Direction button;
	Point addPoint;
    
	Node *kepala = (Node *)malloc(sizeof(kepala));
    kepala = l->head;
	
	if ((GetAsyncKeyState(VK_RIGHT)) && (((SnakeBody *) kepala->value)->direction != left) && (((SnakeBody *) kepala->value)->direction != right)) 
    {
        button = right; // arrow right is control key for turning right
    }
    else if ((GetAsyncKeyState(VK_LEFT)) && (((SnakeBody *) kepala->value)->direction != right) && (((SnakeBody *) kepala->value)->direction != left))
    {
        button = left; // arrow left is control key for turning left
    }
    else if ((GetAsyncKeyState(VK_UP)) && (((SnakeBody *) kepala->value)->direction != down) && (((SnakeBody *) kepala->value)->direction != up))
    {
        button = up; // arrow up is control key for turning upward
    }
    else if ((GetAsyncKeyState(VK_DOWN)) && (((SnakeBody *) kepala->value)->direction != up) && (((SnakeBody *) kepala->value)->direction != down))
    {
        button = down; // arrow down is control key for turning downward
    }
    else if (((GetAsyncKeyState(VK_SPACE))) && (ss->snakeBoostGauge > 0))
    {
    	ss->snakeSpeed = 40;
    	ss->snakeBoostGauge = ss->snakeBoostGauge - 1;
    	button = noDirection;
	}
    else
    {
        button = noDirection;
        ss->snakeSpeed = 90;
    }

    switch (button)
    {
    case noDirection:
    {
        if (((SnakeBody *) kepala->value)->direction == right)
        {
            addPoint.coorX = 50;
            addPoint.coorY = 0;
            ((SnakeBody *) kepala->value)->turn = noDirection;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorX != 1000)
            {
                readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_kanan.gif", 50, ((SnakeBody *) kepala->value)->coord->coorY, 50 + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == left)
        {
            addPoint.coorX = -50;
            addPoint.coorY = 0;
            ((SnakeBody *) kepala->value)->turn = noDirection;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorX != 0)
            {
                readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_kiri.gif", 950, ((SnakeBody *) kepala->value)->coord->coorY, 950 + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == up)
        {
            addPoint.coorX = 0;
            addPoint.coorY = -50;
            ((SnakeBody *) kepala->value)->turn = noDirection;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorY != 0)
            {
                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, 600, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, 600 + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == down)
        {
            addPoint.coorX = 0;
            addPoint.coorY = 50;
            ((SnakeBody *) kepala->value)->turn = noDirection;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorY != 650)
            {
                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, 50, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, 50 + gridSize);
            }
        }
        break;
    }
    case right:
    {
        if (((SnakeBody *) kepala->value)->direction == up)
        {
            addPoint.coorX = 50;
            addPoint.coorY = 0;
            ((SnakeBody *) kepala->value)->turn = right;
            ((SnakeBody *) kepala->value)->direction = right;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorX != 1000)
            {
                readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_kanan.gif", 50, ((SnakeBody *) kepala->value)->coord->coorY, 50 + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == down)
        {
            addPoint.coorX = 50;
            addPoint.coorY = 0;
            ((SnakeBody *) kepala->value)->turn = down;
            ((SnakeBody *) kepala->value)->direction = right;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorX != 1000)
            {
                readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_kanan.gif", 50, ((SnakeBody *) kepala->value)->coord->coorY, 50 + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
        }
        break;
    }
    case left:
    {
        if (((SnakeBody *) kepala->value)->direction == up)
        {
            addPoint.coorX = -50;
            addPoint.coorY = 0;
            ((SnakeBody *) kepala->value)->turn = left;
            ((SnakeBody *) kepala->value)->direction = left;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorX != 0)
            {
                readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_kiri.gif", 950, ((SnakeBody *) kepala->value)->coord->coorY, 950 + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == down)
        {
            addPoint.coorX = -50;
            addPoint.coorY = 0;
            ((SnakeBody *) kepala->value)->turn = up;
            ((SnakeBody *) kepala->value)->direction = left;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorX != 0)
            {
                readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_kiri.gif", 950, ((SnakeBody *) kepala->value)->coord->coorY, 950 + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
        }
        break;
    }
    case up:
    {
        if (((SnakeBody *) kepala->value)->direction == right)
        {
            addPoint.coorX = 0;
            addPoint.coorY = -50;
            ((SnakeBody *) kepala->value)->turn = up;
            ((SnakeBody *) kepala->value)->direction = up;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorY != 0)
            {
                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, 600, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, 600 + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == left)
        {
            addPoint.coorX = 0;
            addPoint.coorY = -50;
            ((SnakeBody *) kepala->value)->turn = down;
            ((SnakeBody *) kepala->value)->direction = up;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorY != 0)
            {
                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, 600, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, 600 + gridSize);
            }
        }
        break;
    }
    case down:
    {
        if (((SnakeBody *) kepala->value)->direction == right)
        {
            addPoint.coorX = 0;
            addPoint.coorY = 50;
            ((SnakeBody *) kepala->value)->turn = left;
            ((SnakeBody *) kepala->value)->direction = down;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorY != 650)
            {
                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, 50, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, 50 + gridSize);
            }
        }
        else if (((SnakeBody *) kepala->value)->direction == left)
        {
            addPoint.coorX = 0;
            addPoint.coorY = 50;
            ((SnakeBody *) kepala->value)->turn = right;
            ((SnakeBody *) kepala->value)->direction = down;
            
			Snake__updateCoord(l, addPoint);
			
            if (((SnakeBody *) kepala->value)->coord->coorY != 650)
            {
                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
            }
            else
            {
                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, 50, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, 50 + gridSize);
            }
        }
        break;
    }
    }
}

void Snake__controllerComputer(LinkedList *l, SnakeStats *ss, int gridSize, Point tempS)
{
    Direction button;
	Point addPoint;
    
	Node *kepala = (Node *)malloc(sizeof(kepala));
    kepala = l->head;
    
    int tempX = (((SnakeBody *) kepala->value)->coord->coorX/50) - tempS.coorX;
    int tempY = (((SnakeBody *) kepala->value)->coord->coorY/50) - tempS.coorY;
	
	if (tempX > 0)
	{
		if (((SnakeBody *) kepala->value)->direction == left || ((SnakeBody *) kepala->value)->direction == right)
		{
			button = noDirection;
		}
		else
		{
			button = left;
		}
	}
	else if (tempX < 0)
	{
		if (((SnakeBody *) kepala->value)->direction == right || ((SnakeBody *) kepala->value)->direction == left)
		{
			button = noDirection;
		}
		else
		{
			button = right;
		}
	}
	else if (tempY < 0)
	{
		if (((SnakeBody *) kepala->value)->direction == down || ((SnakeBody *) kepala->value)->direction == up)
		{
			button = noDirection;
		}
		else
		{
			button = down;
		}
	}
	else if (tempY > 0)
	{
		if (((SnakeBody *) kepala->value)->direction == up || ((SnakeBody *) kepala->value)->direction == down)
		{
			button = noDirection;
		}
		else
		{
			button = up;
		}	
	}
    else
    {
        button = noDirection;
        ss->snakeSpeed = 90;
    }

    switch (button)
    {
	    case noDirection:
	    {
	        if (((SnakeBody *) kepala->value)->direction == right)
	        {
	            addPoint.coorX = 50;
	            addPoint.coorY = 0;
	            ((SnakeBody *) kepala->value)->turn = noDirection;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorX != 1000)
	            {
	                readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == left)
	        {
	            addPoint.coorX = -50;
	            addPoint.coorY = 0;
	            ((SnakeBody *) kepala->value)->turn = noDirection;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorX != 0)
	            {
	                readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == up)
	        {
	            addPoint.coorX = 0;
	            addPoint.coorY = -50;
	            ((SnakeBody *) kepala->value)->turn = noDirection;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorY != 0)
	            {
	                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == down)
	        {
	            addPoint.coorX = 0;
	            addPoint.coorY = 50;
	            ((SnakeBody *) kepala->value)->turn = noDirection;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorY != 650)
	            {
	                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        break;
	    }
	    case right:
	    {
	        if (((SnakeBody *) kepala->value)->direction == up)
	        {
	            addPoint.coorX = 50;
	            addPoint.coorY = 0;
	            ((SnakeBody *) kepala->value)->turn = right;
	            ((SnakeBody *) kepala->value)->direction = right;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorX != 1000)
	            {
	                readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == down)
	        {
	            addPoint.coorX = 50;
	            addPoint.coorY = 0;
	            ((SnakeBody *) kepala->value)->turn = down;
	            ((SnakeBody *) kepala->value)->direction = right;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorX != 1000)
	            {
	                readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        break;
	    }
	    case left:
	    {
	        if (((SnakeBody *) kepala->value)->direction == up)
	        {
	            addPoint.coorX = -50;
	            addPoint.coorY = 0;
	            ((SnakeBody *) kepala->value)->turn = left;
	            ((SnakeBody *) kepala->value)->direction = left;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorX != 0)
	            {
	                readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == down)
	        {
	            addPoint.coorX = -50;
	            addPoint.coorY = 0;
	            ((SnakeBody *) kepala->value)->turn = up;
	            ((SnakeBody *) kepala->value)->direction = left;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorX != 0)
	            {
	                readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        break;
	    }
	    case up:
	    {
	        if (((SnakeBody *) kepala->value)->direction == right)
	        {
	            addPoint.coorX = 0;
	            addPoint.coorY = -50;
	            ((SnakeBody *) kepala->value)->turn = up;
	            ((SnakeBody *) kepala->value)->direction = up;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorY != 0)
	            {
	                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == left)
	        {
	            addPoint.coorX = 0;
	            addPoint.coorY = -50;
	            ((SnakeBody *) kepala->value)->turn = down;
	            ((SnakeBody *) kepala->value)->direction = up;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorY != 0)
	            {
	                readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        break;
	    }
	    case down:
	    {
	        if (((SnakeBody *) kepala->value)->direction == right)
	        {
	            addPoint.coorX = 0;
	            addPoint.coorY = 50;
	            ((SnakeBody *) kepala->value)->turn = left;
	            ((SnakeBody *) kepala->value)->direction = down;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorY != 650)
	            {
	                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        else if (((SnakeBody *) kepala->value)->direction == left)
	        {
	            addPoint.coorX = 0;
	            addPoint.coorY = 50;
	            ((SnakeBody *) kepala->value)->turn = right;
	            ((SnakeBody *) kepala->value)->direction = down;
	            
				Snake__updateCoord(l, addPoint);
				
	            if (((SnakeBody *) kepala->value)->coord->coorY != 650)
	            {
	                readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + gridSize, ((SnakeBody *) kepala->value)->coord->coorY + gridSize);
	            }
	        }
	        break;
	    }
    }
}

void Snake__dyingCondition()
{
	for (int j = 0; j < 20; j++)
	{
		delay(100);
		swapbuffers();
		delay(100);
	}
}

int Snake__collisionBody(LinkedList *l)
{
	int snakeAlive = 1;
	Node *kepala = (Node *)malloc(sizeof(kepala));
	Node *body = (Node *)malloc(sizeof(body));
	
	if ((kepala == NULL) || (body == NULL))
    {
        printf("Allocation Error!");
        exit(1);
    }
    
    kepala = l->head;
    body = l->head->next;
    
    while (body != NULL)
	{
    	if (((SnakeBody *) kepala->value)->coord->coorX == ((SnakeBody *) body->value)->coord->coorX && ((SnakeBody *) kepala->value)->coord->coorY == ((SnakeBody *) body->value)->coord->coorY)
    	{
    		if (((SnakeBody *) kepala->value)->direction == right)
    		{
    			readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
			if (((SnakeBody *) kepala->value)->direction == left)
			{
				readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
			if (((SnakeBody *) kepala->value)->direction == down)
			{
				readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
    		if (((SnakeBody *) kepala->value)->direction == up)
    		{
    			readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
    		snakeAlive = 0;
		}
		
    	body = body->next;
	}
	
	return snakeAlive;
}

int Snake__collisionComputer(LinkedList *l)
{
	Node *kepala = (Node *)malloc(sizeof(Node));
	kepala = l->head;
	int snakeAlive = 1;
	
	if (((SnakeBody *) kepala->value)->coord->coorX >= 1000 && ((SnakeBody *) kepala->value)->direction == right)
    {
        snakeAlive = 0;
		return snakeAlive;
    }
    else if (((SnakeBody *) kepala->value)->coord->coorY >= 650 && ((SnakeBody *) kepala->value)->direction == down)
    {
        snakeAlive = 0;
		return snakeAlive;	
    }
    else if (((SnakeBody *) kepala->value)->coord->coorX <= 0 && ((SnakeBody *) kepala->value)->direction == left)
    {
        snakeAlive = 0;
		return snakeAlive;
    }
    else if (((SnakeBody *) kepala->value)->coord->coorY <= 0 && ((SnakeBody *) kepala->value)->direction == up)
    {
        snakeAlive = 0;
		return snakeAlive;
    }
    
	Node *body = (Node *)malloc(sizeof(body));
    
    kepala = l->head;
    body = l->head->next;
    
    while (body != NULL)
	{
    	if (((SnakeBody *) kepala->value)->coord->coorX == ((SnakeBody *) body->value)->coord->coorX && ((SnakeBody *) kepala->value)->coord->coorY == ((SnakeBody *) body->value)->coord->coorY)
    	{
    		if (((SnakeBody *) kepala->value)->direction == right)
    		{
    			readimagefile("sprite//snake//head_kanan.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
			if (((SnakeBody *) kepala->value)->direction == left)
			{
				readimagefile("sprite//snake//head_kiri.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
			if (((SnakeBody *) kepala->value)->direction == down)
			{
				readimagefile("sprite//snake//head_bawah.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
    		if (((SnakeBody *) kepala->value)->direction == up)
    		{
    			readimagefile("sprite//snake//head_atas.gif", ((SnakeBody *) kepala->value)->coord->coorX, ((SnakeBody *) kepala->value)->coord->coorY, ((SnakeBody *) kepala->value)->coord->coorX + 50, ((SnakeBody *) kepala->value)->coord->coorY + 50);
			}
			
    		snakeAlive = 0;
		}
		
    	body = body->next;
	}
    
    return snakeAlive;
}

void Snake__collisionMaps(LinkedList *l)
{
	Node *kepala = (Node *)malloc(sizeof(Node));
	kepala = l->head;
	
	if (((SnakeBody *) kepala->value)->coord->coorX >= 1000 && ((SnakeBody *) kepala->value)->direction == right)
    {
        ((SnakeBody *) kepala->value)->coord->coorX = 50;
    }
    else if (((SnakeBody *) kepala->value)->coord->coorY >= 650 && ((SnakeBody *) kepala->value)->direction == down)
    {
        ((SnakeBody *) kepala->value)->coord->coorY = 50;	
    }
    else if (((SnakeBody *) kepala->value)->coord->coorX <= 0 && ((SnakeBody *) kepala->value)->direction == left)
    {
        ((SnakeBody *) kepala->value)->coord->coorX = 950;
    }
    else if (((SnakeBody *) kepala->value)->coord->coorY <= 0 && ((SnakeBody *) kepala->value)->direction == up)
    {
        ((SnakeBody *) kepala->value)->coord->coorY = 600;
    }
}

void Snake__eatingProcess(LinkedList *l)
{
	SnakeBody *tempValue;
	void *tempValuePtr;
	Node *newNode;
	
	tempValue = SnakeBody__valueCreate(l);
	tempValuePtr = tempValue;
	newNode = Node__create(tempValuePtr);
	
	LinkedList__addNode(l, newNode);
}

/* =============================================================================================== */

void Food__getRandCoordNonObs(LinkedList *l, Point *apple, Point *mouse, Point *potion, const char ket[8])
{
	if ((strcmp (ket, "Apple")) == 0)
	{
		apple->coorX = rand() %18 + 1;
		apple->coorY = rand() %9 + 1;	
	}
	
	else if ((strcmp (ket, "Mouse")) == 0)
	{
		mouse->coorX = rand() %18 + 1;
		mouse->coorY = rand() %9 + 1;
	}
	
	else if ((strcmp (ket, "Potion")) == 0)
	{
		potion->coorX = rand() %18 + 1;
		potion->coorY = rand() %9 + 1;
	}
	
	Food__checkCollisionNonObs(l, &*apple, &*mouse, &*potion, ket);
}

void Food__checkCollisionNonObs(LinkedList *l, Point *apple, Point *mouse, Point *potion, const char ket[8])
{
	Node *curr = (Node *)malloc(sizeof(Node));

    if (curr == NULL)
    {
        printf("Allocation Error!");
        exit(1);
	}
	
	curr = l->head;
	
    while (curr->next != NULL){
		if (
			((((SnakeBody *) curr->value)->coord->coorX == apple->coorX * 50) && (((SnakeBody *) curr->value)->coord->coorY == apple->coorY * 50)) ||
			(apple->coorX * 50 == potion->coorX * 50 && apple->coorY * 50 == potion->coorY * 50) ||
			(apple->coorX * 50 == mouse->coorX * 50 && apple->coorY * 50 == mouse->coorY * 50) ||
			(mouse->coorX * 50 == potion->coorX * 50 && mouse->coorY * 50 == potion->coorY * 50)
			)
		{	
			Food__getRandCoordNonObs(l, &*apple, &*mouse, &*potion, ket);
		}
		curr = curr->next;	
	}
}

void Food__checkEatFoodNonObs(LinkedList *l, Point *apple, Point *mouse, Point *potion, Data *dataPlayer, FoodStats *mousestats, FoodStats *potionstats, SnakeStats *ss, void* barBoost)
{
	for(int i = 0; i < 2; i++)	// Eating Apple
	{
		if (apple[i].coorX * 50 == ((SnakeBody *) l->head->value)->coord->coorX && apple[i].coorY * 50 == ((SnakeBody *) l->head->value)->coord->coorY)
		{
			Game__addingScore(dataPlayer->score, 1);
			Food__getRandCoordNonObs(l, &apple[i], mouse, potion, "Apple");
			Snake__eatingProcess(l);
		}	
	}
	
	if (mouse->coorX * 50 == ((SnakeBody *) l->head->value)->coord->coorX && mouse->coorY * 50 == ((SnakeBody *) l->head->value)->coord->coorY)
	{
		Game__addingScore(dataPlayer->score, 2);
		mousestats->delayRespawn = 3000;
		mousestats->timer = 0;
		mousestats->isExist = 0;
		Food__getRandCoordNonObs(l, &apple[0], mouse, potion, "Mouse");
		Snake__eatingProcess(l);
	}
	
	if (potion->coorX * 50 == ((SnakeBody *) l->head->value)->coord->coorX && potion->coorY * 50 == ((SnakeBody *) l->head->value)->coord->coorY)
	{
		potionstats->delayRespawn = 3000;
		potionstats->timer = 0;
		potionstats->isExist = 0;
		Food__getRandCoordNonObs(l, &apple[0], mouse, potion, "Potion");
		Rendering__barBoost(barBoost, &ss->snakeBoostGauge, 1);
	}
	
}

void Food__checkDuration(LinkedList *l, Point *apple, Point *mouse, Point *potion, FoodStats *mousestats, FoodStats *potionstats, int snakeSpeed)
{
	if (mousestats->timer <= 0)
	{
		Food__getRandCoordNonObs(l, &apple[0], mouse, potion, "Mouse");
		mousestats->isExist = 0;
	}
	else
	{
		if (mousestats->isExist == 1)
		{
			mousestats->timer = mousestats->timer - snakeSpeed; 		
		}
	}
	
	if (mousestats->isExist == 1)
	{
		mousestats->delayRespawn = 3000;
	}
	else
	{
		mousestats->delayRespawn = mousestats->delayRespawn - snakeSpeed;
	}
	
	/* ========================================== */
	
	if (potionstats->timer <= 0)
	{	
		Food__getRandCoordNonObs(l, &apple[0], mouse, potion, "Potion");
		potionstats->isExist = 0;
	}
	else
	{ 	
		if (potionstats->isExist == 1)
		{
			potionstats->timer = potionstats->timer - snakeSpeed; 	
		}
	}
	if (potionstats->isExist == 1)
	{
		potionstats->delayRespawn = 3000;
	}
	else
	{
		potionstats->delayRespawn = potionstats->delayRespawn - snakeSpeed;
	}
}

void Food__getRandCoordApple(LinkedList *l, Point *apple)
{
	apple->coorX = rand() %18 + 1;
	apple->coorY = rand() %9 + 1;
	
	Food__checkCollisionAppleNonObs(l, &*apple);
}

void Food__checkCollisionAppleNonObs(LinkedList *l, Point *apple)
{
	Node *curr = (Node *)malloc(sizeof(Node));

    if (curr == NULL)
    {
        printf("Allocation Error!");
        exit(1);
	}
	
	curr = l->head;
	
    while (curr->next != NULL){
		if (
			((((SnakeBody *) curr->value)->coord->coorX == apple->coorX * 50) &&
			(((SnakeBody *) curr->value)->coord->coorY == apple->coorY * 50)) 
			)
		{	
			Food__getRandCoordApple(l, &*apple);
		}
		curr = curr->next;	
	}
}

void Food__checkEatAppleComputerSnake(LinkedList *l, Point *apple, Data *dataPlayer, SnakeStats *ss)
{
	if (apple->coorX * 50 == ((SnakeBody *) l->head->value)->coord->coorX && apple->coorY * 50 == ((SnakeBody *) l->head->value)->coord->coorY)
	{
		Game__addingScore(dataPlayer->score, 1);
		Food__getRandCoordApple(l, &*apple);
		Snake__eatingProcess(l);
	}
}

/* =============================================================================================== */
