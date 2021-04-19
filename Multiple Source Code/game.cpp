#include "game.hpp"

Game *Game__create(int gridSize, int gridWidth, int gridHeight)
{
    Game *g = (Game *)malloc(sizeof(Game *));
    g->gridSize = gridSize;
    g->gridWidth = gridWidth;
    g->gridHeight = gridHeight;	

    g->windowWidth = gridWidth * gridSize;
    g->windowHeight = gridHeight * gridSize;
    return g;
}

void Game__run(Game *g)
{
    initwindow(g->windowWidth, g->windowHeight, "RomeoSnake");
	
	Rendering__displayMenu("LoadingScreen");
	Rendering__displayMenu("MainMenu");
    Menu__cursorControlMenu("MainMenu");
}

void Game__addingScore(int score[], int addScore)
{
	score[0] = score[0] + addScore;
	for (int i = 0; i < 4;i++)
	{
		if (score[i] >= 10)
		{
			score[i] = 0;
			score[i+1] = score[i+1] + 1;
		}	
	}
}

char *Game__getPlayerName (int gridSize)
{
	int maxIndexOfName = 5, isEntered = 0;
	char *playerName = (char*) malloc (maxIndexOfName * (sizeof(char)));
	int arrayLength = 0;

	Rendering__inputName();
	
	while (isEntered == 0)
	{
		if (GetAsyncKeyState(KEY_A) && arrayLength < maxIndexOfName)
		{
			playerName[arrayLength] = 'A';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
		}
		else if (GetAsyncKeyState(KEY_B) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'B';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_C) && arrayLength < maxIndexOfName)
   	 	{
    		playerName[arrayLength] = 'C';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_D) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'D';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_E) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'E';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_F) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'F';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_G) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'G';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_H) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'H';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_I) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'I';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_J) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'J';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_K) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'K';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_L) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'L';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_M) && arrayLength < maxIndexOfName)
    	{
    		playerName[arrayLength] = 'M';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
    	}
		else if (GetAsyncKeyState(KEY_N) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'N';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_O) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'O';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_P) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'P';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_Q) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'Q';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_R) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'R';
	    	arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_S) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'S';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_T) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'T';
			arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_U) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'U';
			arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_V) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'V';
			arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_W) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'W';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_X) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'X';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_Y) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'Y';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_Z) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = 'Z';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_1) && arrayLength < maxIndexOfName)
		{
	    	playerName[arrayLength] = '1';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_2) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '2';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_3) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '3';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_4) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '4';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_5) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '5';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_6) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '6';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_7) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '7';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_8) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '8';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_9) && arrayLength < maxIndexOfName)
	    {
	    	playerName[arrayLength] = '9';
	    	arrayLength++;
        	Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(KEY_0) && arrayLength < maxIndexOfName)
	  	{
	    	playerName[arrayLength] = '0';
	    	arrayLength++;
			Rendering__characterInput (playerName, arrayLength, gridSize);
	    }
		else if (GetAsyncKeyState(VK_RETURN))
	    {
	    	if (arrayLength > 0) isEntered = 1;
	    	else
	    	{
	    		swapbuffers();
	    		readimagefile("sprite//menu//inputyourname.gif", 0  , 0 , 1300, 600);
	    		swapbuffers();
	    		delay(200);
	    		Rendering__inputName();
			}
	    }
	    else if (GetAsyncKeyState(VK_BACK))
	    {
	    	if (arrayLength > 0)
	    	{
	    		arrayLength--;
		    	playerName[arrayLength] = '\0';
		    	swapbuffers();
		    	readimagefile("sprite//other//Backspace.jpg", 550 + (arrayLength * gridSize) , 421, 550 + (arrayLength * gridSize) + gridSize, 421 + gridSize);
		    	swapbuffers();
			}
			if (arrayLength == 4)
			{
				swapbuffers();
				readimagefile("sprite//other//Deleteinput.jpg", 350 , 365, 900 + gridSize, 365 + 30);
				swapbuffers();				
			}
		}
	    else
	    {
	    	if (arrayLength >= maxIndexOfName)
	    	{
		    	swapbuffers();
		    	readimagefile("sprite//menu//characterfull.gif", 0  , 0 , 1300, 600);
		    	swapbuffers();
				delay(200);
			}
	    	
	    	playerName[arrayLength]='\0';
	    	isEntered = 0;
		}
		delay(200);
	}
	
	return playerName;
}

void Game__saveScore (int playerScore[], char *playerName)
{
	FILE *fPointer;
	int totalScore, satuan, puluhan, ratusan, ribuan, puluhribu;
	int indexarray = 0;
	
	if ((fPointer = fopen("data/ScoreData.txt","a+")) == NULL) {
		perror ("Error opening file\n");
		exit(1);
	}

	satuan    = playerScore[indexarray];
	puluhan   = playerScore[indexarray + 1] * 10;
	ratusan   = playerScore[indexarray + 2] * 100;
	ribuan    = playerScore[indexarray + 3] * 1000;
	puluhribu = playerScore[indexarray + 4] * 10000;
	
	totalScore = satuan + puluhan + ratusan + ribuan + puluhribu;
	fprintf(fPointer, "\n%s %d", playerName, totalScore);
	
	fclose(fPointer);
}

void Game__saveSortedScore (DataHighscore *data, int arrayLength)
{
	FILE *fPointer;
	if ((fPointer = fopen("data/HighscoreData.txt","w")) == NULL) {
		perror ("Error opening file\n");
		exit(1);
	}
	
	int i;
	
	for (i = 0; i < arrayLength; i++)
	{
		fprintf (fPointer, "%s %d", data[i].playerName, data[i].playerScore);
		if (i + 1 != arrayLength) fprintf (fPointer, "\n");
	}
	
	fclose(fPointer);
}

void Game__sortingScore()
{
	int arrayLength = getArrayLength();
	
	DataHighscore *data = Game__arrayCreate (arrayLength);
	HeapSortMax (data, arrayLength);
	Game__saveSortedScore (data, arrayLength);
}

int getArrayLength()
{
	FILE *fPointer;
	
	if ((fPointer = fopen("data/ScoreData.txt","r")) == NULL) {
		perror ("Error opening file\n");
		exit(1);
	}
    
	int arrayLength = 1;
	char temp = fgetc(fPointer);
	
	while (temp != EOF)
	{
		if (temp == '\n')
		{
			arrayLength++;
		}
		temp = fgetc(fPointer);
	}

	fclose (fPointer);
	return arrayLength;
}

DataHighscore *Game__arrayCreate (int arrayLength)
{
	FILE *fPointer;
	
	if ((fPointer = fopen("data/ScoreData.txt","r")) == NULL) {
		perror ("Error opening file\n");
		exit(1);
	}
	
	DataHighscore *data = (DataHighscore*) malloc (arrayLength * sizeof(DataHighscore));
	int i;
	
	for (i = 0; i < arrayLength; i++)
	{
		fscanf (fPointer, "%s %d", &data[i].playerName, &data[i].playerScore);
	}

	fclose (fPointer);
	return data;
}

void Game__classicNonObs()
{
	srand(time(NULL));
    
    LinkedList *l = LinkedList__create();
	SpriteHandler *sh = SpriteHandler__create(50);	// 50 = g->gridSize
    Snake__create(l);
    SnakeStats *ss = SnakeStats__create();
	
	Point apple[2], mouse, potion;
	FoodStats mousestats, potionstats;
	
	mousestats.randomChance = 100;
	mousestats.delayRespawn = 3000;
	mousestats.timer = 0;
	mousestats.isExist = 0;
	potionstats.randomChance = 100;
	potionstats.delayRespawn = 3000;
	potionstats.timer = 0;
	potionstats.isExist = 0;
	
	Data dataPlayer;
	
	for(int i = 0; i < 6; i++)
	{
		dataPlayer.score[i] = 0;
	}
	
	cleardevice();
	
	dataPlayer.playerName = Game__getPlayerName(50);	// 50 = g->gridSize
	swapbuffers();
	
	Rendering__boardGame();
	Rendering__playerName(dataPlayer.playerName, 40);	// 40 = g->gridSize 
	getimage(1075, 200, 1275, 200 + 50, sh->playerName);
	
	cleardevice();
	
	Rendering__displayMenu("LoadingScreen");
	
	for (int i = 0; i < 2; i++)
	{
		Food__getRandCoordNonObs(l, &apple[i], &mouse, &potion, "Apple");
		Rendering__food(sh, apple[i].coorX, apple[i].coorY, "Apple");
	}
	
	Food__getRandCoordNonObs(l, apple, &mouse, &potion, "Mouse");
	Food__getRandCoordNonObs(l, apple, &mouse, &potion, "Potion");
	
	Rendering__boardGame();
	putimage(1075, 200, sh->playerName, COPY_PUT);
    Rendering__backgroundMap(sh);
	Rendering__wallMap(sh);
	Rendering__barBoost(sh->barBoost, &ss->snakeBoostGauge, 0);
	Rendering__displayScore(sh, dataPlayer.score);
	
	Snake__controller(l, ss, 50);
	Rendering__snakeBody(l, sh);
	ss->snakeAlive = 1;		// 1 = Alive, 0 = Dead
	
    while (ss->snakeAlive == 1)
    {	
		cleardevice();
    	
    	Rendering__backgroundMap(sh);
		Rendering__wallMap(sh);
		Rendering__boardGame();
		putimage(1075, 200, sh->playerName, COPY_PUT);
		Rendering__barBoost(sh->barBoost, &ss->snakeBoostGauge, 0);
		Rendering__displayScore(sh, dataPlayer.score);
		
		for (int i = 0; i < 2; i++)
		{
			Rendering__food(sh, apple[i].coorX, apple[i].coorY, "Apple");	
		}
		
		/* =======	Checking Food Duration	======= */
		
		if (mousestats.delayRespawn <= 0)		//	Checking Mouse
		{
			if (mousestats.timer >= 0)
			{
				mousestats.randomChance = rand() %10;	
				mousestats.delayRespawn = 3000;
			}
			
			if (mousestats.randomChance < 5)
			{
				Rendering__food(sh, mouse.coorX, mouse.coorY, "Mouse");
				mousestats.isExist = 1;
				mousestats.timer = 5000; // 5 detik atau lebih
			}
			else
			{
				mousestats.timer = 5000; // 5 detik atau lebih
			}
		}
		
	 	if (mousestats.isExist == 1) 		
		{
			Rendering__food(sh, mouse.coorX, mouse.coorY, "Mouse");
		}
		
		/* ========================================== */
		
		if (potionstats.delayRespawn <= 0)		// Checking Potion
		{
			if (potionstats.timer >= 0)
			{
				potionstats.randomChance = rand() %50;	
				potionstats.delayRespawn = 3000;
			}
			
			if (potionstats.randomChance < 5)
			{
				Rendering__food(sh, potion.coorX, potion.coorY, "Potion");
				potionstats.isExist = 1;
				potionstats.timer = 5000; // 5 detik atau lebih
			}
			else
			{
				potionstats.timer = 5000; // 5 detik atau lebih
			}
		}
		
	 	if (potionstats.isExist == 1)
		{
			Rendering__food(sh, potion.coorX, potion.coorY, "Potion");
		}
		
		/* ========================================== */

		Food__checkDuration(l, apple, &mouse, &potion, &mousestats, &potionstats, ss->snakeSpeed);
		
		Snake__controller(l, ss, 50);
		Rendering__snakeBody(l, sh);
		
		Food__checkEatFoodNonObs(l, apple, &mouse, &potion, &dataPlayer, &mousestats, &potionstats, ss, sh->barBoost);
		Snake__collisionMaps(l);
		ss->snakeAlive = Snake__collisionBody(l);
		
		delay(ss->snakeSpeed);
		
		swapbuffers();
	}
	
	if (ss->snakeAlive == 0)		// Checking is snake still alive or not.
	{
		cleardevice();
		
		Rendering__backgroundMap(sh);
		Rendering__wallMap(sh);
		Rendering__boardGame();
		Rendering__barBoost(sh->barBoost, &ss->snakeBoostGauge, 0);
		Rendering__displayScore(sh, dataPlayer.score);
		Rendering__playerName(dataPlayer.playerName, 40);	// 40 = g->gridSize
		
		for (int i = 0; i < 2; i++)
		{
			Rendering__food(sh, apple[i].coorX, apple[i].coorY, "Apple");
		}
		if (mousestats.isExist == 1)
		{
			Rendering__food(sh, mouse.coorX, mouse.coorY, "Mouse");
		}
		if (potionstats.isExist == 1)
		{
			Rendering__food(sh, potion.coorX, potion.coorY, "Potion");
		}
		
		Snake__dyingCondition();
		Game__saveScore (dataPlayer.score, dataPlayer.playerName);
		Game__sortingScore();
		Rendering__gameOver();
		Rendering__lastScore(sh, dataPlayer.score);
		
		swapbuffers();
		delay(5000);
		cleardevice();
		exit(0);
	}
}

Stack *getPathFood(LinkedList *l, bool **arrayMap, Point appleCoord) {
	Queue *q = Queue__create();
	Tree *t = Tree__create();
	
	Point tempPoint;
	bool isPathed = false;
	
	NodeTree *newNodeTree = NodeTree__create(((SnakeBody *) l->head->value)->coord);
	Tree__addNode(t, newNodeTree, NULL);
	NodeQueue *newNodeQueue = NodeQueue__create(newNodeTree);
	Queue__pushNode(q, newNodeQueue);
	q->root->object->value.coorX = q->root->object->value.coorX / 50;
	q->root->object->value.coorY = q->root->object->value.coorY / 50;
	
	while (Queue__isEmpty(q) == false)
	{
		NodeQueue *nqPop = Queue__popNode(q);

		if ((isPathVisited(arrayMap, nqPop->object->value, "Up")) == false)
		{
			tempPoint.coorX = nqPop->object->value.coorX;
			tempPoint.coorY = nqPop->object->value.coorY - 1;
			
			if (tempPoint.coorX == appleCoord.coorX && tempPoint.coorY == appleCoord.coorY)
			{
				newNodeTree = NodeTree__create(&tempPoint);
				Tree__addNode(t, newNodeTree, nqPop->object);
				isPathed = true;
				break;
			}
			
			newNodeTree = NodeTree__create(&tempPoint);
			Tree__addNode(t, newNodeTree, nqPop->object);
			newNodeQueue = NodeQueue__create(newNodeTree);
			Queue__pushNode(q, newNodeQueue);
			updateArrayPath(arrayMap, tempPoint);
		}
		
		if ((isPathVisited(arrayMap, nqPop->object->value, "Down")) == false)
		{
			tempPoint.coorX = nqPop->object->value.coorX;
			tempPoint.coorY = nqPop->object->value.coorY + 1;
			
			if (tempPoint.coorX == appleCoord.coorX && tempPoint.coorY == appleCoord.coorY)
			{
				newNodeTree = NodeTree__create(&tempPoint);
				Tree__addNode(t, newNodeTree, nqPop->object);
				isPathed = true;
				break;
			}
			
			newNodeTree = NodeTree__create(&tempPoint);
			Tree__addNode(t, newNodeTree, nqPop->object);
			newNodeQueue = NodeQueue__create(newNodeTree);
			Queue__pushNode(q, newNodeQueue);
			updateArrayPath(arrayMap, tempPoint);
		}
		
		if ((isPathVisited(arrayMap, nqPop->object->value, "Left")) == false)
		{
			;tempPoint.coorX = nqPop->object->value.coorX - 1;
			tempPoint.coorY = nqPop->object->value.coorY;
			
			if (tempPoint.coorX == appleCoord.coorX && tempPoint.coorY == appleCoord.coorY)
			{
				newNodeTree = NodeTree__create(&tempPoint);
				Tree__addNode(t, newNodeTree, nqPop->object);
				isPathed = true;
				break;
			}
			
			newNodeTree = NodeTree__create(&tempPoint);
			Tree__addNode(t, newNodeTree, nqPop->object);
			newNodeQueue = NodeQueue__create(newNodeTree);
			Queue__pushNode(q, newNodeQueue);
			updateArrayPath(arrayMap, tempPoint);
		}
		
		if ((isPathVisited(arrayMap, nqPop->object->value, "Right")) == false)
		{
			tempPoint.coorX = nqPop->object->value.coorX + 1;
			tempPoint.coorY = nqPop->object->value.coorY;
			
			if (tempPoint.coorX == appleCoord.coorX && tempPoint.coorY == appleCoord.coorY)
			{
				newNodeTree = NodeTree__create(&tempPoint);
				Tree__addNode(t, newNodeTree, nqPop->object);
				isPathed = true;
				break;
			}
			
			newNodeTree = NodeTree__create(&tempPoint);
			Tree__addNode(t, newNodeTree, nqPop->object);
			newNodeQueue = NodeQueue__create(newNodeTree);
			Queue__pushNode(q, newNodeQueue);
			updateArrayPath(arrayMap, tempPoint);
		}
	}

	Stack *pathTrack = Stack__create();
	
	if (Queue__isEmpty (q) == true && isPathed == false)	// Kondisi tidak ada jalan menuju apel
	{
		Point snakePoint;
		snakePoint.coorX = ((SnakeBody *) l->head->value)->coord->coorX / 50;
		snakePoint.coorY = ((SnakeBody *) l->head->value)->coord->coorY / 50;
		
		while (snakePoint.coorX - appleCoord.coorX != 0 || snakePoint.coorY - appleCoord.coorY != 0)
		{
			if (snakePoint.coorX - appleCoord.coorX < 0)	// kanan
			{
				snakePoint.coorX++;
				newNodeTree = NodeTree__create(&snakePoint);
				newNodeQueue = NodeQueue__create(newNodeTree);
				Stack__addNode(pathTrack, newNodeQueue);
			}
			
			else if (snakePoint.coorX - appleCoord.coorX > 0)	// kiri	
			{
				snakePoint.coorX--;
				newNodeTree = NodeTree__create(&snakePoint);
				newNodeQueue = NodeQueue__create(newNodeTree);
				Stack__addNode(pathTrack, newNodeQueue);
			}
			
			else if (snakePoint.coorY - appleCoord.coorY > 0)	// atas
			{
				snakePoint.coorY--;
				newNodeTree = NodeTree__create(&snakePoint);
				newNodeQueue = NodeQueue__create(newNodeTree);
				Stack__addNode(pathTrack, newNodeQueue);
			}
			
			else if (snakePoint.coorY - appleCoord.coorY < 0)	// bawah
			{
				snakePoint.coorY++;
				newNodeTree = NodeTree__create(&snakePoint);
				newNodeQueue = NodeQueue__create(newNodeTree);
				Stack__addNode(pathTrack, newNodeQueue);
			}
		}
		
		pathTrack = Stack__reverse(pathTrack);
	}
	
	else if (isPathed == true)	// Kondisi mendapatkan jalan menuju apel
	{
		while (newNodeTree != t->root)
		{
			newNodeQueue = NodeQueue__create(newNodeTree);
			Stack__addNode(pathTrack, newNodeQueue);
			newNodeTree = newNodeTree->parent;
		}
	}
	
	return pathTrack;
}

void updateArraySnake(bool **arrayMap, LinkedList *l)
{
	Node *snake = (Node*) malloc (sizeof(Node));
	int tempX, tempY;
	int cols = 21, rows = 12;
	snake = l->head;
	
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
	    {	
	    	arrayMap[i][j] = false;
		}
	}
	
	for (int i = 0; i < rows; i++)
	{
		arrayMap[0][i] = true;
	}
	
	for (int i = 0; i < cols; i++)
	{
		arrayMap[i][0] = true;
	}
	
	for (int i = 0; i < rows; i++)
	{
		arrayMap[cols - 1][i] = true;
	}
	
	for (int i = 0; i < cols; i++)
	{
		arrayMap[i][rows - 1] = true;
	}
	
	while (snake != NULL)
	{
    	tempX = ((SnakeBody *)snake->value)->coord->coorX / 50;
    	tempY = ((SnakeBody *)snake->value)->coord->coorY / 50;
    	arrayMap[tempX][tempY] = true;
    	snake = snake->next;
	}
}

void updateArrayPath(bool **arrayMap, Point grid)
{
	arrayMap[grid.coorX][grid.coorY] = true;
}

bool isPathVisited(bool **arrayMap, Point grid, const char ket[6])
{
	if (((strcmp (ket, "Up")) == 0))
	{
		if (arrayMap[grid.coorX][grid.coorY - 1] == true)
		{
			return true;
		}
		return false;
	}
	
	if (((strcmp (ket, "Down")) == 0))
	{
		if (arrayMap[grid.coorX][grid.coorY + 1] == true)
		{
			return true;
		}
		
		return false;
	}
	
	if (((strcmp (ket, "Right")) == 0))
	{
		if (arrayMap[grid.coorX + 1][grid.coorY] == true)
		{
			return true;
		}
		
		return false;
	}
	
	if (((strcmp (ket, "Left")) == 0))
	{
		if (arrayMap[grid.coorX - 1][grid.coorY] == true)
		{
			return true;
		}
		
		return false;
	}
}

void Game__computerSnake()
{
	srand(time(NULL));
    
    LinkedList *l = LinkedList__create();
	SpriteHandler *sh = SpriteHandler__create(50);	// 50 = g->gridSize
    Snake__create(l);
    SnakeStats *ss = SnakeStats__create();
    ss->snakeSpeed = 0;
	
	Point apple, path;
	NodeQueue tempS;
	
	Food__getRandCoordApple (l, &apple);

	bool **arrayMap = Array__create();
	updateArraySnake(arrayMap, l);

	Stack *pathTrack = getPathFood(l, arrayMap, apple);
	Data dataPlayer;
	
	for(int i = 0; i < 6; i++)
	{
		dataPlayer.score[i] = 0;
	}
	
	Rendering__displayMenu("LoadingScreen");

	Rendering__appleComputerSnake (sh, apple.coorX, apple.coorY);
	
	Rendering__boardGame();
    Rendering__backgroundMap(sh);
	Rendering__wallMap(sh);
	Rendering__displayScore(sh, dataPlayer.score);
	
	ss->snakeAlive = 1;		// 1 = Alive, 0 = Dead
	
    while (ss->snakeAlive == 1)
    {	
		cleardevice();
		
    	Rendering__backgroundMap(sh);
		Rendering__wallMap(sh);
		Rendering__boardGame();
		Rendering__displayScore(sh, dataPlayer.score);
		
		Rendering__appleComputerSnake (sh, apple.coorX, apple.coorY);
		
		if (pathTrack->root == NULL)
		{
			updateArraySnake(arrayMap, l);
			pathTrack = getPathFood(l, arrayMap, apple);
		}
		
		tempS = Stack__getTop(pathTrack);
		path.coorX = tempS.object->value.coorX;
		path.coorY = tempS.object->value.coorY;
		Stack__pop(pathTrack);
		
		Snake__controllerComputer(l, ss, 50, path);
		Rendering__snakeBody(l, sh);
		
		Food__checkEatAppleComputerSnake(l, &apple, &dataPlayer, ss);
		
		ss->snakeAlive = Snake__collisionComputer(l);
				
		delay(ss->snakeSpeed);
		
		swapbuffers();
	}
	
	if (ss->snakeAlive == 0)		// Checking is snake still alive or not.
	{
		cleardevice();
		
		Rendering__backgroundMap(sh);
		Rendering__wallMap(sh);
		Rendering__boardGame();
		Rendering__displayScore(sh, dataPlayer.score);
		
		Rendering__appleComputerSnake (sh, apple.coorX, apple.coorY);
		
		Snake__dyingCondition();
		Rendering__gameOver();
		Rendering__lastScore(sh, dataPlayer.score);
		
		swapbuffers();
		delay(5000);
		cleardevice();
		exit(0);
	}
}
