#include <graphics.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define NOTHITBUTTON 0
#define ARROWRIGHT 77
#define ARROWLEFT 75
#define ARROWUP 72
#define ARROWDOWN 80
#define ENTER 13
#define ESC 27

#define DEVICEWIDTH 1300
#define DEVICEHEIGHT 700
#define MAXBARPOTION 40

#define SIZESPRITE 50
#define SIZEWIDTH 1300
#define SIZEHEIGHT 700

typedef struct Point
{
    int coorX;
    int coorY;
} Point;

typedef struct DataUlar
{
	int coorX;
    int coorY;	
	int turn;	
    int direction;
} DataUlar;

typedef DataUlar valuetype;

typedef struct Node
{
    valuetype val;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *newLinkedList();
void InitializationNode(LinkedList *l);
void AddFirstNode(LinkedList *l, DataUlar tempKepalaUlar);
void AddLastNode(LinkedList *l, Point addPoint);
void UpdateCoorSnake(LinkedList *l, DataUlar tempKepalaUlar);
void RenderingBodySnake(LinkedList *l);
void RenderingTembok();
void Controller(LinkedList *l);
void CollisionMaps(LinkedList *l);
void SpriteHandler(int option);
void PutApple(int randXapple, int randYapple);
void PutMouse(int randXmouse, int randYmouse);
void GetRandFood(Point coordObstacle[], int *randXapple, int *randYapple, int *randXmouse, int *randYmouse, int *randXPotion, int *randYPotion, LinkedList *l, char food);
void DeadSnake(int option);
void GetHitBody(LinkedList *l, Point coordObstacle[]);
void RenderingBar(int potion);
void Renderingbg(int option);
void RenderingSkor(int skor[]);
void TambahSkor(int skor[], int tambahSkor);;
void PLAY(int option);
void ProsesMakan(LinkedList *l, Point addPoint);
void Loading();

//variable global
int mati=0;
int fillthebar=40;
int kecepatan=175;

/*	Sprite Handler	*/
void *mapEasy;
void *apple;
void *mouse;
void *potion;
void *bodyHorizontal;
void *bodyVertical;
void *tailKanan;
void *tailKiri;
void *tailAtas;
void *tailBawah;
void *bodyTurn1;
void *bodyTurn2;
void *bodyTurn3;
void *bodyTurn4;
void *bargame;
void *rumput_bg;
void *langit_bg;
void *angkasa_bg;
void *GambarSkor[10];
void *obstacle[8];
void *obstacle_pagar;
void *obstacle_awan;
void *obstacle_meteor;

//Modul berhubungan dengan Menu Utama
void MainMenu();
void MenuCursor();
void EnterButtonMenuCondition(int x, int y);

//Modul berhubungan dengan Arcade di Single Player
void ArcadeLevelMenuScreen();
void ArcadeLevelMenuCursor();
void CursorArrowMenuCondition(int *x, int *y);

//Modul berhubungan dengan pemilihan single / multiplayer
void ChoosePlayer();
void ChoosePlayerCursor();
void ChoosePlayerEnterCondition(int *x, int *y);

//Modul berhubungan dengan pemilihan Survival / Arcade di Single player
void SinglePlayerMenu();
void SinglePlayerMenuCursor();
void SinglePlayerMenuCondition(int *x, int *y);

void EnterButtonMenuCondition_Arcade(int x, int y);	
void Obstacle_Medium(Point coordObstacle[]);
void Obstacle_Hard(Point coordObstacle[]);
void Obstacle_Expert(Point coordObstacle[]);

void Help();

int main(){
    initwindow(DEVICEWIDTH, DEVICEHEIGHT);
    Loading();
	MainMenu();
    MenuCursor();
    getch();
}

void MainMenu(){
    readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
    readimagefile("sprite//menu//Title.gif"		  , 350, 50, 950, 500);
    readimagefile("sprite//menu//Start Game.gif"	  , 400, 530, 200, 470);
    readimagefile("sprite//menu//Score Button.gif"  , 400, 620, 200, 680);
    readimagefile("sprite//menu//Help Button.gif"   , 700, 530, 500, 470);
    readimagefile("sprite//menu//Quit Button.gif"   , 700, 620, 500, 680);
}

void ArcadeLevelMenuScreen() {
	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	readimagefile("sprite//menu//title select.gif"  , 350, 50, 950, 500);	//	Diganti sama stage select
	readimagefile("sprite//menu//button_easy.gif"   , 400, 530, 200, 470);
	readimagefile("sprite//menu//button_medium.gif" , 400, 620, 200, 680);
	readimagefile("sprite//menu//button_hard.gif"   , 700, 530, 500, 470);
	readimagefile("sprite//menu//button_expert.gif" , 700, 620, 500, 680);
	readimagefile("sprite//menu//esc.gif"           , 1200, 560, 1275, 610);
	readimagefile("sprite//menu//button_back.gif"   , 1200, 610, 1275, 685);
}

void ChoosePlayer(){
	readimagefile("sprite//menu//Title Screen 2.gif"	   	, 0, 0, 1300, 700);
    readimagefile("sprite//menu//Title.gif"		  		, 350, 50, 950, 500);
    readimagefile("sprite//menu//button_single_player.gif", 280, 550, -20, 470);
	readimagefile("sprite//menu//button_multi_player.gif"	, 700, 550, 400, 470);
	readimagefile("sprite//menu//esc.gif"           		, 1200, 560, 1275, 610);
	readimagefile("sprite//menu//button_back.gif"   		, 1200, 610, 1275, 685);	
}

void ChoosePlayerCursor(){
	int button;
    int x, y;

    x = 200;
    y = 560;

    readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);
    swapbuffers();
   
    while (1)
    {
        if (GetAsyncKeyState(VK_RIGHT))
		{
		    button = ARROWRIGHT; 
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
		    button = ARROWLEFT;
		}
		else if (GetAsyncKeyState(VK_UP)) 
		{
		    button = ARROWUP;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
		    button = ARROWDOWN; 
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
		    button = ENTER; 
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
		    button = ESC; 
		}
        switch (button)
        {
	        case ARROWRIGHT:
	        {
	            cleardevice();
	            ChoosePlayer();
	            x = x + 420;
	            
				if (x > 620){
					x = 620;
				}
				
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);
	            swapbuffers();
	            break;
	        }
	        case ARROWLEFT:
	        {
	            cleardevice();
	            ChoosePlayer();
	            x = x - 420;
	            
				if (x < 200){
	            	x = 200;
				}
				
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);
	            swapbuffers();
	            break;
	        }
	        case ENTER:
	        {
	            ChoosePlayerEnterCondition(&x, &y);
	
	            break;
	        }
	        case ESC :
	        {
	        	cleardevice();
	        	MainMenu();
	        	MenuCursor();
			}
        }
	}
}

void ChoosePlayerEnterCondition(int *x, int *y){
	if((*x == 200) && (*y == 560)){
		cleardevice();
		SinglePlayerMenu();
		SinglePlayerMenuCursor();
	}
	else if((*x == 620) && (*y == 560)){
		cleardevice();							
	}
}

void SinglePlayerMenu(){
	readimagefile("sprite//menu//Title Screen 2.gif"	   	, 0, 0, 1300, 700);
    readimagefile("sprite//menu//Title.gif"		  		, 350, 50, 950, 500);
    readimagefile("sprite//menu//button_arcade.gif"		, 700, 550, 400, 470);
	readimagefile("sprite//menu//button_classic.gif"		, 280, 550, -20, 470);
	readimagefile("sprite//menu//esc.gif"           		, 1200, 560, 1275, 610);
	readimagefile("sprite//menu//button_back.gif"   		, 1200, 610, 1275, 685);
}

void SinglePlayerMenuCursor(){
	
	int button;
    int x, y;

    x = 200;
    y = 560;

    readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);
    swapbuffers();
   
    while (1)
    {
        if (GetAsyncKeyState(VK_RIGHT))
		{
		    button = ARROWRIGHT; 
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
		    button = ARROWLEFT;
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
		    button = ENTER; 
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
		    button = ESC; 
		}
		
        switch (button)
        {
	        case ARROWRIGHT:
	        {
	            cleardevice();
	            SinglePlayerMenu();
	            x = x + 420;
	            
				if (x > 620){
					x = 620;
				}
				
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);
	            swapbuffers();
	            break;
	        }
	        case ARROWLEFT: 
	        {
	            cleardevice();
	            SinglePlayerMenu();
	            x = x - 420;
	            
				if (x < 200){
	            	x = 200;
				}
				
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);
	            swapbuffers();
	            break;
	        }
	        case ENTER:
	        {
	            SinglePlayerMenuCondition(&x, &y);
	
	            break;
	        }
	        case ESC :
	        {
	        	cleardevice();
	        	ChoosePlayer();
	        	ChoosePlayerCursor();
			}
        }
	}
}

void SinglePlayerMenuCondition(int *x, int *y){
	
	if ((*x == 200) && (*y == 560)){
		cleardevice();
		ArcadeLevelMenuScreen();
		ArcadeLevelMenuCursor();
	}
	else if ((*x == 620) && (*y == 560)){
		cleardevice();					
	}
}

void MenuCursor(){
    int button;
    int x, y;

    x = 340;
    y = 540;

    readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
    swapbuffers();

    while (1)
    {
        if (GetAsyncKeyState(VK_RIGHT))
		{
		    button = ARROWRIGHT; 
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
		    button = ARROWLEFT;
		}
		else if (GetAsyncKeyState(VK_UP)) 
		{
		    button = ARROWUP;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
		    button = ARROWDOWN; 
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
		    button = ENTER; 
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
		    button = ESC; 
		}
        switch (button)
        {
        case ARROWRIGHT: //right
        {
            cleardevice();
            MainMenu();
            x = x + 300;
			CursorArrowMenuCondition( &x, &y);
            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
            swapbuffers();
            break;
        }
        case ARROWLEFT: //left
        {
            cleardevice();
            MainMenu();
            x = x - 300;
			CursorArrowMenuCondition( &x, &y);
            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
            swapbuffers();
            break;
        }
        case ARROWUP: //up
        {
            cleardevice();
            MainMenu();
            y = y - 80;
			CursorArrowMenuCondition( &x, &y);
            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
            swapbuffers();
            break;
        }
        case ARROWDOWN: //down
        {
            cleardevice();
            y = y + 80;
			CursorArrowMenuCondition( &x, &y);
            MainMenu();
            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
            swapbuffers();
            break;
        }
        case ENTER:
        {
            EnterButtonMenuCondition(x, y);
            break;
        }

        }
    }
}

void ArcadeLevelMenuCursor(){
    int button;
    int x, y;

    x = 340;
    y = 540;

    readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
    swapbuffers();

    while (1)
    {
        if (GetAsyncKeyState(VK_RIGHT))
		{
		    button = ARROWRIGHT; 
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
		    button = ARROWLEFT;
		}
		else if (GetAsyncKeyState(VK_UP)) 
		{
		    button = ARROWUP;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
		    button = ARROWDOWN; 
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
		    button = ENTER; 
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
		    button = ESC; 
		}
		
        switch (button)
        {
	        case ARROWRIGHT: 
	        {
	            cleardevice();
	            ArcadeLevelMenuScreen();
	            x = x + 300;
				CursorArrowMenuCondition( &x, &y);
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
	            swapbuffers();
	            break;
	        }
	        case ARROWLEFT:
	        {
	            cleardevice();
	            ArcadeLevelMenuScreen();
	            x = x - 300;
				CursorArrowMenuCondition( &x, &y);
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
	            swapbuffers();
	            break;
	        }
	        case ARROWUP: 
	        {
	            cleardevice();
	            ArcadeLevelMenuScreen();
	            y = y - 80;
				CursorArrowMenuCondition( &x, &y);
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
	            swapbuffers();
	            break;
	        }
	        case ARROWDOWN: 
	        {
	            cleardevice();
	            y = y + 80;
				CursorArrowMenuCondition( &x, &y);
	            ArcadeLevelMenuScreen();
	            readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);
	            swapbuffers();
	            break;
	        }
	        case ENTER:
	        {
	            EnterButtonMenuCondition_Arcade(x, y);
	
	            break;
	        }
	        case ESC :
	        {
	        	cleardevice();
				SinglePlayerMenu();
				SinglePlayerMenuCursor();
			}
        }
    }
}

	void CursorArrowMenuCondition(int *x, int *y){
 
 			if (*y > 620)
            {
                *y = 620;
            }
            if (*y < 540)
            {
                *y = 540;
            }
            if (*x > 640)
            {
                *x = 640;
            }
            if (*x < 340)
            {
                *x = 340;
            }
                
}

void EnterButtonMenuCondition(int x, int y){

	if ((x == 340) && (y == 540))
    {
		cleardevice();
		ChoosePlayer();
	    ChoosePlayerCursor();
	}
    else if ((x == 640) && (y == 540))
    {
        Help();				
    }
    else if ((x == 340) && (y == 620))
    {
        MainMenu();				//	Diganti sama score
    }
    else if ((x == 640) && (y == 620))
    {
		exit(0);
    }
	
}

void EnterButtonMenuCondition_Arcade(int x, int y){
	mati = 0;
		if ((x == 340) && (y == 540))
    {
    	PLAY(1); 
	}
    else if ((x == 640) && (y == 540))
    {
        PLAY(3); 			
    }
    else if ((x == 340) && (y == 620))
    {
        PLAY(2); 
    }
    else if ((x == 640) && (y == 620))
    {
		PLAY(4);
    }
	
}

LinkedList *newLinkedList()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));

    if (l == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }

    l->head = NULL;
    return l;
}

void InitializationNode(LinkedList *l)
{
    DataUlar tempKepalaUlar;
	Point addPoint;
    
    tempKepalaUlar.coorX = 1000 / 2; // 500x is default position (on middle of the map)
    tempKepalaUlar.coorY = 600 / 2; // 300y is default position (on middle of the map)
    tempKepalaUlar.turn = 0; // current turn of snake (0 means NOTHITBUTTON)
    
	tempKepalaUlar.direction = 1; // current direction of snake (right)

    if (tempKepalaUlar.direction == RIGHT)
    { /* Right = 1 */
        addPoint.coorX = -50;
        addPoint.coorY = 0;
    }
    else if (tempKepalaUlar.direction == LEFT)
    { /* LEFT = 2 */
        addPoint.coorX = 50;
        addPoint.coorY = 0;
    }
    else if (tempKepalaUlar.direction == UP)
    { /* UP = 3 */
        addPoint.coorX = 0;
        addPoint.coorY = 50;
    }
    else if (tempKepalaUlar.direction == DOWN)
    { /* DOWN = 4 */
        addPoint.coorX = 0;
        addPoint.coorY = -50;
    }

    AddFirstNode(l, tempKepalaUlar);
    AddLastNode(l, addPoint);
    AddLastNode(l, addPoint);
	AddLastNode(l, addPoint);
}

void AddFirstNode(LinkedList *l, DataUlar tempKepalaUlar)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }

    newNode->val.coorX = tempKepalaUlar.coorX;
    newNode->val.coorY = tempKepalaUlar.coorY;
    newNode->val.turn = tempKepalaUlar.turn;
    newNode->val.direction = tempKepalaUlar.direction;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    l->head = newNode;
    l->tail = newNode;
}

void AddLastNode(LinkedList *l, Point addPoint)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *curr = (Node *)malloc(sizeof(Node));

    if ((newNode == NULL) && (curr == NULL))
    {
        printf("Allocation Error!");
        exit(1);
    }

    curr = l->tail;

    curr->next = newNode;
    newNode->val.coorX = curr->val.coorX + addPoint.coorX;
    newNode->val.coorY = curr->val.coorY + addPoint.coorY;
    newNode->val.turn = curr->val.turn;
    newNode->val.direction = curr->val.direction;
    newNode->next = NULL;
    newNode->prev = curr;
    
    l->tail = newNode;
}

void UpdateCoorSnake(LinkedList *l, Point addPoint)
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
		curr->val.coorX = curr->prev->val.coorX;
		curr->val.coorY = curr->prev->val.coorY;
		curr->val.turn = curr->prev->val.turn;
		curr->val.direction = curr->prev->val.direction;
		curr = curr->prev;
	}
	
	curr->val.coorX = curr->val.coorX + addPoint.coorX;
	curr->val.coorY = curr->val.coorY + addPoint.coorY;
}

void Controller(LinkedList *l)
{
    int button;
	Point addPoint;
    
	Node *kepala = (Node *)malloc(sizeof(kepala));
    kepala = l->head;
    
    
	
	if ((GetAsyncKeyState(VK_RIGHT)) && (kepala->val.direction != LEFT) && (kepala->val.direction != RIGHT)) 
    {
        button = RIGHT; // arrow right is control key for turning right
    }
    else if ((GetAsyncKeyState(VK_LEFT)) && (kepala->val.direction != RIGHT) && (kepala->val.direction != LEFT))
    {
        button = LEFT; // arrow left is control key for turning left
    }
    else if ((GetAsyncKeyState(VK_UP)) && (kepala->val.direction != DOWN) && (kepala->val.direction != UP))
    {
        button = UP; // arrow up is control key for turning upward
    }
    else if ((GetAsyncKeyState(VK_DOWN)) && (kepala->val.direction != UP) && (kepala->val.direction != DOWN))
    {
        button = DOWN; // arrow down is control key for turning downward
    }
    else if((GetAsyncKeyState(VK_SPACE)) && (fillthebar>0))
    {
    	kecepatan=40;
    	fillthebar-=1;	
    	button = NOTHITBUTTON;
	}
    else
    {
        button = NOTHITBUTTON;
        kecepatan=90;
    }

    switch (button)
    {
    case NOTHITBUTTON:
    {
        if (kepala->val.direction == RIGHT)
        {
            addPoint.coorX = 50;
            addPoint.coorY = 0;
            kepala->val.turn = 0;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorX != 1000)
            {
                readimagefile("sprite//snake//head_kanan.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_kanan.gif", 50, kepala->val.coorY, 50 + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        else if (kepala->val.direction == LEFT)
        {
            addPoint.coorX = -50;
            addPoint.coorY = 0;
            kepala->val.turn = 0;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorX != 0)
            {
                readimagefile("sprite//snake//head_kiri.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_kiri.gif", 950, kepala->val.coorY, 950 + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
           
        	RenderingBodySnake(l);
        }
        else if (kepala->val.direction == UP)
        {
            addPoint.coorX = 0;
            addPoint.coorY = -50;
            kepala->val.turn = 0;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorY != 0)
            {
                readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, 600, kepala->val.coorX + SIZESPRITE, 600 + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        else if (kepala->val.direction == DOWN)
        {
            addPoint.coorX = 0;
            addPoint.coorY = 50;
            kepala->val.turn = 0;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorY != 650)
            {
                readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, 50, kepala->val.coorX + SIZESPRITE, 50 + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        break;
    }
    case RIGHT:
    {
        if (kepala->val.direction == UP)
        {
            addPoint.coorX = 50;
            addPoint.coorY = 0;
            kepala->val.turn = 1;
            kepala->val.direction = RIGHT;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorX != 1000)
            {
                readimagefile("sprite//snake//head_kanan.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_kanan.gif", 50, kepala->val.coorY, 50 + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        else if (kepala->val.direction == DOWN)
        {
            addPoint.coorX = 50;
            addPoint.coorY = 0;
            kepala->val.turn = 4;
            kepala->val.direction = RIGHT;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorX != 1000)
            {
                readimagefile("sprite//snake//head_kanan.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_kanan.gif", 50, kepala->val.coorY, 50 + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        break;
    }
    case LEFT:
    {
        if (kepala->val.direction == UP)
        {
            addPoint.coorX = -50;
            addPoint.coorY = 0;
            kepala->val.turn = 2;
            kepala->val.direction = LEFT;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorX != 0)
            {
                readimagefile("sprite//snake//head_kiri.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_kiri.gif", 950, kepala->val.coorY, 950 + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        else if (kepala->val.direction == DOWN)
        {
            addPoint.coorX = -50;
            addPoint.coorY = 0;
            kepala->val.turn = 3;
            kepala->val.direction = LEFT;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorX != 0)
            {
                readimagefile("sprite//snake//head_kiri.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_kiri.gif", 950, kepala->val.coorY, 950 + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        break;
    }
    case UP:
    {
        if (kepala->val.direction == RIGHT)
        {
            addPoint.coorX = 0;
            addPoint.coorY = -50;
            kepala->val.turn = 3;
            kepala->val.direction = UP;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorY != 0)
            {
                readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, 600, kepala->val.coorX + SIZESPRITE, 600 + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        else if (kepala->val.direction == LEFT)
        {
            addPoint.coorX = 0;
            addPoint.coorY = -50;
            kepala->val.turn = 4;
            kepala->val.direction = UP;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorY != 0)
            {
                readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, 600, kepala->val.coorX + SIZESPRITE, 600 + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        break;
    }
    case DOWN:
    {
        if (kepala->val.direction == RIGHT)
        {
            addPoint.coorX = 0;
            addPoint.coorY = 50;
            kepala->val.turn = 2;
            kepala->val.direction = DOWN;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorY != 650)
            {
                readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, 50, kepala->val.coorX + SIZESPRITE, 50 + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        else if (kepala->val.direction == LEFT)
        {
            addPoint.coorX = 0;
            addPoint.coorY = 50;
            kepala->val.turn = 1;
            kepala->val.direction = DOWN;
            
			UpdateCoorSnake(l, addPoint);
			
            if (kepala->val.coorY != 650)
            {
                readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
            }
            else
            {
                readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, 50, kepala->val.coorX + SIZESPRITE, 50 + SIZESPRITE);
            }
            
            RenderingBodySnake(l);
        }
        break;
    }
    }
}

void CollisionMaps(LinkedList *l)
{
	Node *kepala = (Node *)malloc(sizeof(Node));
	kepala = l->head;
	
	if (kepala->val.coorX >= 1000 && kepala->val.direction == RIGHT)
    {
        kepala->val.coorX = 50;
    }
    else if (kepala->val.coorY >= 650 && kepala->val.direction == DOWN)
    {
        kepala->val.coorY = 50;
    }
    else if (kepala->val.coorX <= 0 && kepala->val.direction == LEFT)
    {
        kepala->val.coorX = 950;
    }
    else if (kepala->val.coorY <= 0 && kepala->val.direction == UP)
    {
        kepala->val.coorY = 600;
    }
}

void SpriteHandler(int option)
{
	unsigned int tempSizing;
	tempSizing = imagesize(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	
	/* Sprite Handler for Easy Map */
	readimagefile("sprite//maps//easy_map.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	mapEasy = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, mapEasy);
	cleardevice();
	
	/* Sprite Handler for Rumput */
	readimagefile("sprite//maps//rumput.gif",600,600,600 + SIZESPRITE, 600 + SIZESPRITE);
	rumput_bg = malloc(tempSizing);
	getimage(600,600,600 + SIZESPRITE, 600 + SIZESPRITE, rumput_bg);
	cleardevice();
	
	/* Sprite Handler for Angkasa */
	readimagefile("sprite//maps//angkasa.gif",600,600,600 + SIZESPRITE, 600 + SIZESPRITE);
	angkasa_bg = malloc(tempSizing);
	getimage(600,600,600 + SIZESPRITE, 600 + SIZESPRITE, angkasa_bg);
	cleardevice();
	
	/* Sprite Handler for Langit */
	readimagefile("sprite//maps//langit.gif",600,600,600 + SIZESPRITE, 600 + SIZESPRITE);
	langit_bg = malloc(tempSizing);
	getimage(600,600,600 + SIZESPRITE, 600 + SIZESPRITE, langit_bg);
	cleardevice();
	
	/* Sprite Handler for Langit */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//PAGAR//obstacle_pagar_normal.gif",600,600,600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle_pagar = malloc(tempSizing);
	getimage(600,600,600 + SIZESPRITE, 600 + SIZESPRITE, obstacle_pagar);
	cleardevice();
	
	/* Sprite Handler for Langit */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//awan.gif",600,600,600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle_awan = malloc(tempSizing);
	getimage(600,600,600 + SIZESPRITE, 600 + SIZESPRITE, obstacle_awan);
	cleardevice();
	
	/* Sprite Handler for Langit */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//meteor.gif",600,600,600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle_meteor = malloc(tempSizing);
	getimage(600,600,600 + SIZESPRITE, 600 + SIZESPRITE, obstacle_meteor);
	cleardevice();
	
	
	/* Sprite Handler for Apple */
	readimagefile("sprite//food//apple.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	apple = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, apple);
	cleardevice();
	
	/* Sprite Handler for Mouse */
	readimagefile("sprite//food//mouse.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	mouse = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, mouse);
	cleardevice();
	
	/* Sprite Handler for Body Horizontal */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//body_horizontal.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	bodyHorizontal = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, bodyHorizontal);
	cleardevice();
	
	/* Sprite Handler for Body Vertical */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//body_vertical.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	bodyVertical = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, bodyVertical);
	cleardevice();
	
	/* Sprite Handler for Tail Kanan */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//tail_kanan.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	tailKanan = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, tailKanan);
	cleardevice();
	
	/* Sprite Handler for Tail Kiri */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//tail_kiri.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	tailKiri = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, tailKiri);
	cleardevice();
	
	/* Sprite Handler for Tail Atas */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//tail_atas.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	tailAtas = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, tailAtas);
	cleardevice();
	
	/* Sprite Handler for Tail Bawah */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//tail_bawah.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	tailBawah = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, tailBawah);
	cleardevice();
	
	/* Sprite Handler for Body Turn 1 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//body_turn1.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	bodyTurn1 = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, bodyTurn1);
	cleardevice();
	
	/* Sprite Handler for Body Turn 2 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//body_turn2.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	bodyTurn2 = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, bodyTurn2);
	cleardevice();
	
	/* Sprite Handler for Body Turn 3 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//body_turn3.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	bodyTurn3 = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, bodyTurn3);
	cleardevice();
	
	/* Sprite Handler for Body Turn 1 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//snake//body_turn4.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	bodyTurn4 = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, bodyTurn4);
	cleardevice();
	
	/* Sprite Handler for Apple */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//food//apple.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	apple = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, apple);
	cleardevice();
	
	/* Sprite Handler for Mouse */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//food//mouse.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	mouse = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, mouse);
	cleardevice();
	
	/* Sprite Handler for Potion */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//food//potion.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	potion = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, potion);
	cleardevice();
	
	/* Sprite Handler for Bar */
	setfillstyle(1,GREEN);
	bar(600 , 600, 600 + (SIZESPRITE/2/5), 600 + (SIZESPRITE/2/2));
	bargame = malloc(tempSizing);
	getimage(600, 600, 600 + (SIZESPRITE/2/5), 600 + (SIZESPRITE/2/2)+20,bargame);
	cleardevice();
	
	/* Sprite Handler for Skor 0*/
	readimagefile("sprite//Angka//0.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[0] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[0]);
	cleardevice();
	
	/* Sprite Handler for Skor 1*/
	readimagefile("sprite//Angka//1.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[1] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[1]);
	cleardevice();
	
	/* Sprite Handler for Skor 2*/
	readimagefile("sprite//Angka//2.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[2] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[2]);
	cleardevice();
	
	/* Sprite Handler for Skor 3*/
	readimagefile("sprite//Angka//3.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[3] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[3]);
	cleardevice();
	
	/* Sprite Handler for Skor 4*/
	readimagefile("sprite//Angka//4.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[4] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[4]);
	cleardevice();
	
	/* Sprite Handler for Skor 5*/
	readimagefile("sprite//Angka//5.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[5] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[5]);
	cleardevice();
		
	/* Sprite Handler for Skor 6*/
	readimagefile("sprite//Angka//6.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[6] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[6]);
	cleardevice();
	
	/* Sprite Handler for Skor 7*/
	readimagefile("sprite//Angka//7.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[7] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[7]);
	cleardevice();
	
	/* Sprite Handler for Skor 8*/
	readimagefile("sprite//Angka//8.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[8] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[8]);
	cleardevice();
	
	/* Sprite Handler for Skor 9*/
	readimagefile("sprite//Angka//9.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	GambarSkor[9] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, GambarSkor[9]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 1 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				putimage(600, 600, obstacle_pagar, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				putimage(600, 600, obstacle_awan, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				putimage(600, 600, obstacle_meteor, COPY_PUT);
				break;
			}
	}
	obstacle[0] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[0]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 2 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_normal_bright.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[1] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[1]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 3 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkanan.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[2] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[2]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 4 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkanan_bright.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[3] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[3]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 5 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkiri.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[4] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[4]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 6 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkiri_bright.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[5] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[5]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 7 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_vertical.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[6] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[6]);
	cleardevice();
	
	/* Spriie Handler for Obstacle 8 */
	switch(option){
		case 1:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 2:
			{
				putimage(600, 600, rumput_bg, COPY_PUT);
				break;
			}
		case 3:
			{
				putimage(600, 600, langit_bg, COPY_PUT);
				break;
			}
		case 4:
			{
				putimage(600, 600, angkasa_bg, COPY_PUT);
				break;
			}
	}
	readimagefile("sprite//obstacle//pagar//obstacle_pagar_vertical_darkl.gif", 600 , 600, 600 + SIZESPRITE, 600 + SIZESPRITE);
	obstacle[7] = malloc(tempSizing);
	getimage(600, 600, 600 + SIZESPRITE, 600 + SIZESPRITE, 	obstacle[7]);
	cleardevice();
	
	
}

void RenderingBodySnake(LinkedList *l)
{
    Node *curr = (Node *)malloc(sizeof(Node));

    if (curr == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }

    curr = l->head->next;
    
    /* 	Rendering Body's Snake 	*/
    while (curr->next != NULL) 
	{
    	if (curr->val.turn == 0 && (curr->val.direction == RIGHT || curr->val.direction == LEFT))
    	{
    		putimage(curr->val.coorX, curr->val.coorY, bodyHorizontal, COPY_PUT);
		}
		else if (curr->val.turn == 0 && (curr->val.direction == UP || curr->val.direction == DOWN))
		{
			putimage(curr->val.coorX, curr->val.coorY, bodyVertical, COPY_PUT);
		}
		
		if (curr->val.turn == 1)
		{
			putimage(curr->val.coorX, curr->val.coorY, bodyTurn1, COPY_PUT);
		}
		else if (curr->val.turn == 2)
		{
			putimage(curr->val.coorX, curr->val.coorY, bodyTurn2, COPY_PUT);
		}
		else if (curr->val.turn == 3)
		{
			putimage(curr->val.coorX, curr->val.coorY, bodyTurn3, COPY_PUT);
		}
		else if (curr->val.turn == 4)
		{
			putimage(curr->val.coorX, curr->val.coorY, bodyTurn4, COPY_PUT);
		}
		
		curr = curr->next;
	}
	
    /* 	Rendering Tail's Snake 	*/
    if (curr->val.direction == RIGHT)
    { /* RIGHT = 1 */
		putimage(curr->val.coorX, curr->val.coorY, tailKanan, COPY_PUT);
    }
    else if (curr->val.direction == LEFT)
    { /* LEFT = 2 */
		putimage(curr->val.coorX, curr->val.coorY, tailKiri, COPY_PUT);
    }
    else if (curr->val.direction == UP)
    { /* UP = 3 */
    	putimage(curr->val.coorX, curr->val.coorY, tailAtas, COPY_PUT);
    }
    else if (curr->val.direction == DOWN)
    { /* DOWN = 4 */
	   putimage(curr->val.coorX, curr->val.coorY, tailBawah, COPY_PUT);
    }
}

void RenderingTembok()
{
    int x, y;
    x = 0;
    
    for (int i = 1; i <= 21; i++)
    {
        putimage(x, 0, mapEasy, COPY_PUT);
        x = x + 50;
    }
    
    x = 0;
    
    for (int i = 1; i <= 21; i++)
    {
        putimage(x, 650, mapEasy, COPY_PUT);
        x = x + 50;
    }
    
    y = 0;
    
    for (int i = 0; i <= 12; i++)
    {
        putimage(0, y, mapEasy, COPY_PUT);
        y = y + 50;
    }
    
    y = 0;
    
    for (int i = 0; i <= 12; i++)
    {
        putimage(1000, y, mapEasy, COPY_PUT);
        y = y + 50;
    }
}

void Renderingbg(int option)
{
	int x, y;
	x=50;
	for (int i = 1; i <= 19; i++)
    {
    	y=50;
    	for (int j = 1; j <= 12; j++)
    	{	
        	switch(option){
				case 1:
					{
						putimage(x, y, rumput_bg, COPY_PUT);
						break;
					}
				case 2:
					{
						putimage(x, y, rumput_bg, COPY_PUT);
						break;
					}
				case 3:
					{
						putimage(x, y, langit_bg, COPY_PUT);
						break;
					}
				case 4:
					{
						putimage(x, y, angkasa_bg, COPY_PUT);
						break;
					}
			}
        	y = y + 50;
    	}
        x = x + 50;
    }
	
}

void GetRandFood(Point coordObstacle[], int *randXapple, int *randYapple, int *randXmouse, int *randYmouse, int *randXPotion, int *randYPotion, LinkedList *l,char food){
	int randX=rand()% 18 + 1;
	int randY=rand()% 9 + 1;
	if(food == 'A'){
		*randXapple = randX;
		*randYapple = randY;
	}else if(food == 'P'){
		*randXPotion = randX;
		*randYPotion = randY;	
	}
	else{	
		*randXmouse = randX;
		*randYmouse = randY;
	}
	Node *curr = (Node *)malloc(sizeof(Node));

    if (curr == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
	
    curr = l->head->next;
    while (curr->next != NULL){
		if((curr->val.coorX == *randXapple*50 && curr->val.coorY == *randYapple*50)||
		(*randXapple*50 == *randXPotion*50 && *randYapple*50 == *randYPotion*50)||
		(*randXapple*50 == *randXmouse*50 && *randYapple*50 == *randYmouse*50)||
		(*randXmouse*50 == *randXmouse*50 && *randYmouse*50 == *randYPotion*50))
		{	
			GetRandFood(coordObstacle, &*randXapple,&*randYapple,&*randXmouse,&*randYmouse,&*randXPotion,&*randYPotion,l,food);
		}
		curr = curr->next;	
	}
	for(int i=0;i<100;i++){
		if(coordObstacle[i].coorX == *randXapple*50 && coordObstacle[i].coorY == *randYapple*50){
			GetRandFood(coordObstacle, &*randXapple,&*randYapple,&*randXmouse,&*randYmouse,&*randXPotion,&*randYPotion,l,'A');	
		}
	}
	for(int i=0;i<100;i++){
		if(coordObstacle[i].coorX == *randXmouse*50 && coordObstacle[i].coorY == *randYmouse*50){
			GetRandFood(coordObstacle, &*randXapple,&*randYapple,&*randXmouse,&*randYmouse,&*randXPotion,&*randYPotion,l,'M');	
		}
	}
	for(int i=0;i<100;i++){
		if(coordObstacle[i].coorX == *randXPotion*50 && coordObstacle[i].coorY == *randYPotion*50){
			GetRandFood(coordObstacle, &*randXapple,&*randYapple,&*randXmouse,&*randYmouse,&*randXPotion,&*randYPotion,l,'P');
		}
	}
	
}

void PutApple(int randXapple,int randYapple){
	putimage(randXapple*50,randYapple*50,apple,COPY_PUT);
}
void PutMouse(int randXmouse,int randYmouse){
	putimage(randXmouse*50,randYmouse*50,mouse,COPY_PUT);
}
void PutPotion(int randXPotion,int randYPotion){
	putimage(randXPotion*50,randYPotion*50,potion,COPY_PUT);
}
void GetHitBody(LinkedList *l, Point coordObstacle[])
{
	Node *kepala = (Node *)malloc(sizeof(kepala));
	Node *tail = (Node *)malloc(sizeof(tail));
	
    kepala = l->head;
    tail = l->head->next;
    
    while (tail->next != NULL)
	{
    	if(kepala->val.coorX == tail->val.coorX && kepala->val.coorY == tail->val.coorY)
    	{
    		if(kepala->val.direction==RIGHT)
    		{
    			readimagefile("sprite//snake//head_kanan.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
			}
			if(kepala->val.direction==LEFT)
			{
				readimagefile("sprite//snake//head_kiri.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
			}
			if(kepala->val.direction==DOWN)
			{
				readimagefile("sprite//snake//head_bawah.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
			}
    		if(kepala->val.direction==UP)
    		{
    			readimagefile("sprite//snake//head_atas.gif", kepala->val.coorX, kepala->val.coorY, kepala->val.coorX + SIZESPRITE, kepala->val.coorY + SIZESPRITE);
			}
    		mati = 1;
		}
    	tail = tail->next;
	}
	
			for(int i=0;i<100;i++)
			{
				if(coordObstacle[i].coorX==kepala->val.coorX && coordObstacle[i].coorY==kepala->val.coorY)
				{
					mati = 1;
				}
			}
}

void DeadSnake()
{
	for(int j=0;j<10;j++)
	{
		delay(200);
		swapbuffers();
		delay(200);
	}
	
	cleardevice();
	readimagefile("sprite//menu//gameover.gif", 0, 0, 1300, 700);
	swapbuffers();
	
	delay(5000);
	exit(0);

}

void RenderingBar(int potion)
{	
	int x=0;
	if(potion==1)
	{
		fillthebar=MAXBARPOTION;
	}
		for(int i=0;i<fillthebar;i++)
		{
			putimage(1075+x, 100, bargame, COPY_PUT);
			x+=5;
		}
}

void RenderingSkor(int skor[])
{
	int x = 0;
	for(int i=4;i>=0;i--){
		for(int j=0;j<=9;j++){
			if(skor[i] == j){
				putimage(1075+x,50,GambarSkor[j],COPY_PUT);	
			}	
		}
		
		x+=40;
	}	
}

void TambahSkor(int skor[], int tambahSkor){
	skor[0]= skor[0] + tambahSkor;
	for(int i=0;i<4;i++){
		if(skor[i] >= 10){
			skor[i] = 0;
			skor[i+1] = skor[i+1] + 1;
		}	
	}
}

void ProsesMakan(LinkedList *l, Point addPoint){
	if (l->head->val.direction == RIGHT)
    { /* Right = 1 */
        addPoint.coorX = -50;
        addPoint.coorY = 0;
    }
    else if (l->head->val.direction == LEFT)
    { /* LEFT = 2 */
        addPoint.coorX = 50;
        addPoint.coorY = 0;
    }
    else if (l->head->val.direction == UP)
    { /* UP = 3 */
        addPoint.coorX = 0;
        addPoint.coorY = 50;
    }
    else if (l->head->val.direction == DOWN)
    { /* DOWN = 4 */
        addPoint.coorX = 0;
        addPoint.coorY = -50;
    }
    AddLastNode(l, addPoint);
}

void Obstacle_Medium(Point coordObstacle[])
{
	int x = 0;
	int j = 0;
	
	putimage(50+x, 50, obstacle[4], COPY_PUT);
	coordObstacle[j].coorX = 50+x;
	coordObstacle[j].coorY = 50;
	j++;
	
	for(int i=0;i<17;i++)
	{
		putimage(100+x, 50, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 50;
		j++;
		x += 50;
	}
	putimage(100+x, 50, obstacle[2], COPY_PUT);
	coordObstacle[j].coorX = 100+x;
	coordObstacle[j].coorY = 50;
	j++;
	
	int y = 0;
	for(int i=0;i<10;i++)
	{
		putimage(100+x, 100+y, obstacle[7], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 100+y;
		j++;
		y += 50;
	}
	
	x = 0;
	putimage(50+x, 600, obstacle[4], COPY_PUT);
	coordObstacle[j].coorX = 50+x;
	coordObstacle[j].coorY = 600;
	j++;
	for(int i=0;i<17;i++)
	{
		putimage(100+x, 600, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 600;
		j++;
		x += 50;
	}
	putimage(100+x, 600, obstacle[2], COPY_PUT);
	coordObstacle[j].coorX = 100+x;
	coordObstacle[j].coorY = 600;
	j++;
	
	y = 0;
	for(int i=0;i<10;i++)
	{
		putimage(50, 100+y, obstacle[7], COPY_PUT);
		coordObstacle[j].coorX = 50;
		coordObstacle[j].coorY = 100+y;
		j++;
		y += 50;
	}
}

void Obstacle_Hard(Point coordObstacle[])
{
	int x = 0;
	int j=0;
	
	putimage(50+x, 250, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 50+x;
	coordObstacle[j].coorY = 250;
	j++;
	
	for(int i=0;i<6;i++)
	{
		putimage(100+x, 250, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 50+x;
		coordObstacle[j].coorY = 250;
		j++;
		x += 50;
	}
	putimage(100+x, 250	, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 100+x;
	coordObstacle[j].coorY = 250;
	
	j++;
	
	int y = 0;
	for(int i=0;i<4;i++)
	{
		putimage(100+x, 200+y, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 200+y;
		j++;
		y -= 50;
	}
	
	x = 0;
	putimage(650+x, 350, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 650+x;
	coordObstacle[j].coorY = 350;
	j++;
	for(int i=0;i<5;i++)
	{
		putimage(700+x, 350, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 700+x;
		coordObstacle[j].coorY = 350;
		j++;
		x += 50;
	}
	putimage(700+x, 350	, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 700+x;
	coordObstacle[j].coorY = 350;
	j++;
	y = 0;
	for(int i=0;i<5;i++)
	{
		putimage(650, 400+y, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 650;
		coordObstacle[j].coorY = 400+y;
		j++;
		y += 50;
	}	
}

void Obstacle_Expert(Point coordObstacle[])
{
	int x = 0;
	int j = 0;
	
	putimage(50+x, 50, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 50+x;
	coordObstacle[j].coorY = 50;
	j++;
	
	for(int i=0;i<17;i++)
	{
		putimage(100+x, 50, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 50;
		j++;
		x += 50;
	}
	putimage(100+x, 50, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 100+x;
	coordObstacle[j].coorY = 50;
	j++;
	
	int y = 0;
	for(int i=0;i<10;i++)
	{
		putimage(100+x, 100+y, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 100+y;
		j++;
		y += 50;
	}
	
	x = 0;
	putimage(50+x, 600, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 50+x;
	coordObstacle[j].coorY = 600;
	j++;
	for(int i=0;i<17;i++)
	{
		putimage(100+x, 600, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 100+x;
		coordObstacle[j].coorY = 600;
		j++;
		x += 50;
	}
	putimage(100+x, 600, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 100+x;
	coordObstacle[j].coorY = 600;
	j++;
	
	y = 0;
	for(int i=0;i<10;i++)
	{
		putimage(50, 100+y, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 50;
		coordObstacle[j].coorY = 100+y;
		j++;
		y += 50;
	}
	
	x = 0;
	putimage(300+x, 250, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 300+x;
	coordObstacle[j].coorY = 250;
	j++;
	putimage(300+x, 200, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 300+x;
	coordObstacle[j].coorY = 200;
	j++;
	for(int i=0;i<7;i++)
	{
		putimage(350+x, 250, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 350+x;
		coordObstacle[j].coorY = 250;
		j++;
		x+=50;
	}
	putimage(350+x, 250, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 350+x;
	coordObstacle[j].coorY = 250;
	j++;
	putimage(350+x, 200, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 350+x;
	coordObstacle[j].coorY = 200;
	j++;
	
	x = 0;
	putimage(300+x, 350, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 300+x;
	coordObstacle[j].coorY = 350;
	j++;
	putimage(300+x, 400, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 300+x;
	coordObstacle[j].coorY = 400;
	j++;
	for(int i=0;i<7;i++)
	{
		putimage(350+x, 350, obstacle[0], COPY_PUT);
		coordObstacle[j].coorX = 350+x;
		coordObstacle[j].coorY = 350;
		j++;
		x+=50;
	}
	putimage(350+x, 350, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 350+x;
	coordObstacle[j].coorY = 350;	
	j++;
	putimage(350+x, 400, obstacle[0], COPY_PUT);
	coordObstacle[j].coorX = 350+x;
	coordObstacle[j].coorY = 400;
}

void Help(){

	int delayShift = 4000;

	readimagefile("sprite//menu//help//help1.gif", 0, 0, 1300, 700);
	swapbuffers();
	delay(delayShift);
	readimagefile("sprite//menu//help//help2.gif", 0, 0, 1300, 700);
	swapbuffers();
	delay(delayShift);
	readimagefile("sprite//menu//help//help3.gif", 0, 0, 1300, 700);
	swapbuffers();
	delay(delayShift);
	readimagefile("sprite//menu//help//help4.gif", 0, 0, 1300, 700);
	swapbuffers();
	delay(delayShift);
	readimagefile("sprite//menu//help//help5.gif", 0, 0, 1300, 700);
	swapbuffers();
	delay(delayShift);
	main();
	
}

void Loading(){
	
	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	readimagefile("sprite//Loadingbar//bar1.gif", 280,550,1000,650);
	swapbuffers();
	delay(1500);
	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	readimagefile("sprite//Loadingbar//bar2.gif", 280,550,1000,650);
	swapbuffers();
	delay(1500);
	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	readimagefile("sprite//Loadingbar//bar3.gif", 280,550,1000,650);
	swapbuffers();
	delay(1500);
	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	readimagefile("sprite//Loadingbar//bar4.gif", 280,550,1000,650);
	swapbuffers();
	delay(1500);
	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	readimagefile("sprite//Loadingbar//bar5.gif", 280,550,1000,650);
	swapbuffers();
	delay(1000);
}

/* ============================================================================================================== */

void PLAY(int option)
{
	cleardevice();
	Loading();
	srand(time(NULL));
	int randXapple[2],randYapple[2],randXmouse,randYmouse,randXPotion,randYPotion;
	Point coordObstacle[100];
	
	SpriteHandler(option);
	
	LinkedList *l = newLinkedList();
    InitializationNode(l);
	  
    RenderingTembok(); 
	Controller(l);
	for(int i=0;i<2;i++){
		randXapple[i]=rand()% 18 + 1;
		randYapple[i]=rand()% 9 + 1;
	}
	
	randXmouse=rand()% 18 + 1;
	randYmouse=rand()% 9 + 1;
	randXPotion=rand()% 18 + 1;
	randYPotion=rand()% 9 + 1;
	
	switch(option)
	{	
		case 2 : 
		{
			Obstacle_Medium(coordObstacle);
			break;
		}
		case 3 :
		{
			Obstacle_Hard(coordObstacle);
			break;	
		}
		case 4 :
		{
			Obstacle_Expert(coordObstacle);
			break;
		}
	}
	
	for(int i=0;i<2;i++){
		GetRandFood(coordObstacle,&randXapple[i],&randYapple[i],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'A');
	}
	GetRandFood(coordObstacle,&randXapple[0],&randYapple[0],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'M');
	GetRandFood(coordObstacle,&randXapple[0],&randYapple[0],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'P');
	
	int randChanceTikus = 100,randChancePotion = 100;
	int delayMunculTikus = 3000;
	int delayMunculPotion = 3000;
	int makanApel = 0;
	int adaTikus = 0;
	int adaPotion = 0;
	int waktuTikus = 0;
	int waktuPotion = 0;
	int skor[6];
	for(int i=0;i<6;i++){
		skor[i] = 0;
	}
	for(int i=0;i<2;i++){
    	PutApple(randXapple[i],randYapple[i]);
	}
	Point addPoint;
	cleardevice();	
	while (mati != 1)
    {
    	cleardevice();
    	Renderingbg(option);
    	switch(option)
    	{	
    		case 2 : 
    		{
    			Obstacle_Medium(coordObstacle);
    			break;
			}
			case 3 :
			{
				Obstacle_Hard(coordObstacle);
				break;	
			}
			case 4 :
			{
				Obstacle_Expert(coordObstacle);
				break;
			}
		}
    	
    	
    	// KALAU MAKAN
    	// APEL
    	for(int i=0;i<2;i++){
    		if(randXapple[i]*50 == l->head->val.coorX && randYapple[i]*50 == l->head->val.coorY){
				TambahSkor(skor,1);
				GetRandFood(coordObstacle,&randXapple[i],&randYapple[i],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'A');
	    		ProsesMakan(l,addPoint);
			}	
		}
		
		// TIKUS
		if(randXmouse*50 == l->head->val.coorX && randYmouse*50 == l->head->val.coorY){
    		TambahSkor(skor,2);
			delayMunculTikus = 3000;
			waktuTikus = 0;
			adaTikus = 0;
    		GetRandFood(coordObstacle,&randXapple[0],&randYapple[0],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'M');
    		ProsesMakan(l,addPoint);
		}
		
		// POTION
		if(randXPotion*50 == l->head->val.coorX && randYPotion*50 == l->head->val.coorY){
    		delayMunculPotion = 3000;
			waktuPotion = 0;
			adaPotion = 0;
    		GetRandFood(coordObstacle,&randXapple[0],&randYapple[0],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'P');
    		RenderingBar(1);
		}
		
		// TUTUP KALAU MAKAN
		
		// Tampil Makanan
		// APEL
    	for(int i=0;i<2;i++){
			PutApple(randXapple[i],randYapple[i]);
		}
		
		// TIKUS
		if(delayMunculTikus <= 0){
			if(waktuTikus >= 0){
				randChanceTikus = rand()%10;	
				delayMunculTikus = 3000;
			}
			if(randChanceTikus < 5){
				PutMouse(randXmouse,randYmouse);
				adaTikus = 1;
				waktuTikus = 5000; // 5 detik atau lebih
			}
			else{
				waktuTikus = 5000; // 5 detik atau lebih
			}
		}
	 	if(adaTikus == 1){
			PutMouse(randXmouse,randYmouse);
		}
		
		// Potion
		if(delayMunculPotion <= 0){
			if(waktuPotion >= 0){
				randChancePotion = rand()%50;	
				delayMunculPotion = 3000;
			}
			if(randChancePotion < 5){
				PutPotion(randXPotion,randYPotion);
				adaPotion = 1;
				waktuPotion = 5000; // 5 detik atau lebih
			}
			else{
				waktuPotion = 5000; // 5 detik atau lebih
			}
		}
	 	if(adaPotion == 1){
			PutPotion(randXPotion,randYPotion);
		}
		// TUTUP Tampil Makanan
		
		// KONDISI WAKTU
		// TIKUS
		if(waktuTikus <= 0){
			GetRandFood(coordObstacle,&randXapple[0],&randYapple[0],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'M');
			adaTikus = 0;
		}else{
			if(adaTikus == 1){
				waktuTikus = waktuTikus - kecepatan ; 		
			}
		}
		if(adaTikus == 1){
			delayMunculTikus = 3000;
		}else{
			delayMunculTikus = delayMunculTikus - kecepatan;
		}
		
		// Potion
		if(waktuPotion <= 0){	
			GetRandFood(coordObstacle,&randXapple[0],&randYapple[0],&randXmouse,&randYmouse,&randXPotion,&randYPotion,l,'P');
			adaPotion = 0;
		}else{
			if(adaPotion == 1){
				waktuPotion = waktuPotion - kecepatan ; 	
			}
		}
		if(adaPotion == 1){
			delayMunculPotion = 3000;
		}else{
			delayMunculPotion = delayMunculPotion - kecepatan;
		}
		// TUTUP KONDISI WAKTU
		
		RenderingSkor(skor);
		RenderingBar(0);
		
		RenderingTembok(); 
		Controller(l);
		CollisionMaps(l);
		delay(kecepatan);
		GetHitBody(l,coordObstacle);
		swapbuffers();
		if(mati==1)
    	{
    		cleardevice();
    		
    		Renderingbg(option);
			RenderingTembok();
			RenderingBar(0);
			RenderingSkor(skor);
    		
			switch(option)
			{	
				case 2 : 
				{
					Obstacle_Medium(coordObstacle);
					break;
				}
				case 3 :
				{
					Obstacle_Hard(coordObstacle);
					break;	
				}
				case 4 :
				{
					Obstacle_Expert(coordObstacle);
					break;
				}
			}
	
			for(int i=0;i<2;i++)
			{
				PutApple(randXapple[i],randYapple[i]);
			}
			if (adaTikus == 1)
			{
				PutMouse(randXmouse,randYmouse);		
			}
			if (adaPotion == 1)
			{
				PutPotion(randXPotion,randYPotion);
			}
			
			DeadSnake();
			exit(0);
		}
	}
}

/* ============================================================================================================== */

