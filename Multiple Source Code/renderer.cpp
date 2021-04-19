#include "renderer.hpp"

SpriteHandler *SpriteHandler__create(int gridSize)
{
	SpriteHandler *sh = (SpriteHandler *)malloc(sizeof(SpriteHandler));
	
	if (sh == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
    
	unsigned int tempSizing;
	tempSizing = imagesize(600, 600, 600 + gridSize, 600 + gridSize);
	
	/* Sprite Handler for Background Map */
	readimagefile("sprite//maps//rumput.gif",600,600,600 + gridSize, 600 + gridSize);
	sh->backgroundMap = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->backgroundMap);
	cleardevice();
	
	/* Sprite Handler for Wall Map */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//maps//tembok_easy.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->wallMap = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->wallMap);
	cleardevice();
	
	/* Sprite Handler for Apple */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//food//apple.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->apple = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->apple);
	cleardevice();
	
	/* Sprite Handler for Mouse */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//food//mouse.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->mouse = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->mouse);
	cleardevice();
	
	/* Sprite Handler for Potion */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//food//potion.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->potion = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->potion);
	cleardevice();
	
	/* Sprite Handler for Body Horizontal */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//body_horizontal.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->bodyHorizontal = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->bodyHorizontal);
	cleardevice();
	
	/* Sprite Handler for Body Vertical */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//body_vertical.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->bodyVertical = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->bodyVertical);
	cleardevice();
	
	/* Sprite Handler for Tail Kanan */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//tail_kanan.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->tailKanan = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->tailKanan);
	cleardevice();
	
	/* Sprite Handler for Tail Kiri */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//tail_kiri.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->tailKiri = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->tailKiri);
	cleardevice();
	
	/* Sprite Handler for Tail Atas */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//tail_atas.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->tailAtas = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->tailAtas);
	cleardevice();
	
	/* Sprite Handler for Tail Bawah */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//tail_bawah.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->tailBawah = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->tailBawah);
	cleardevice();
	
	/* Sprite Handler for Body Turn 1 */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//body_turn1.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->bodyTurn1 = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->bodyTurn1);
	cleardevice();
	
	/* Sprite Handler for Body Turn 2 */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//body_turn2.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->bodyTurn2 = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->bodyTurn2);
	cleardevice();
	
	/* Sprite Handler for Body Turn 3 */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//body_turn3.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->bodyTurn3 = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->bodyTurn3);
	cleardevice();
	
	/* Sprite Handler for Body Turn 1 */
	putimage(600, 600, sh->backgroundMap, COPY_PUT);
	readimagefile("sprite//snake//body_turn4.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->bodyTurn4 = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->bodyTurn4);
	cleardevice();
	
	/* Sprite Handler for 0 Numeric*/
	readimagefile("sprite//Angka//w0.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[0] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[0]);
	cleardevice();
	
	/* Sprite Handler for 1 Numeric*/
	readimagefile("sprite//Angka//w1.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[1] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[1]);
	cleardevice();
	
	/* Sprite Handler for 2 Numeric*/
	readimagefile("sprite//Angka//w2.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[2] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[2]);
	cleardevice();
	
	/* Sprite Handler for 3 Numeric*/
	readimagefile("sprite//Angka//w3.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[3] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[3]);
	cleardevice();
	
	/* Sprite Handler for 4 Numeric*/
	readimagefile("sprite//Angka//w4.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[4] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[4]);
	cleardevice();
	
	/* Sprite Handler for 5 Numeric*/
	readimagefile("sprite//Angka//w5.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[5] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[5]);
	cleardevice();
	
	/* Sprite Handler for 6 Numeric*/
	readimagefile("sprite//Angka//w6.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[6] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[6]);
	cleardevice();
	
	/* Sprite Handler for 7 Numeric*/
	readimagefile("sprite//Angka//w7.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[7] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[7]);
	cleardevice();
	
	/* Sprite Handler for 8 Numeric*/
	readimagefile("sprite//Angka//w8.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[8] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[8]);
	cleardevice();
	
	/* Sprite Handler for 9 Numeric*/
	readimagefile("sprite//Angka//w9.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
	sh->numericalScore[9] = malloc(tempSizing);
	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->numericalScore[9]);
	cleardevice();
	
	/* Sprite Handler for Player Name */
	sh->playerName = malloc(imagesize(1075, 200, 1275, 200 + 50));
		
//	/* Sprite Handler for Obstacle 1 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_normal.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[0] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[0]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 2 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_normal_bright.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[1] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[1]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 3 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkanan.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[2] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[2]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 4 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkanan_bright.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[3] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[3]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 5 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkiri.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[4] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[4]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 6 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_ujungkiri_bright.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[5] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[5]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 7 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_vertical.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[6] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[6]);
//	cleardevice();
//	
//	/* Sprite Handler for Obstacle 8 */
//	putimage(600, 600, sh->backgroundMap, COPY_PUT);
//	readimagefile("sprite//obstacle//pagar//obstacle_pagar_vertical_darkl.gif", 600 , 600, 600 + gridSize, 600 + gridSize);
//	sh->obstacle[7] = malloc(tempSizing);
//	getimage(600, 600, 600 + gridSize, 600 + gridSize, sh->obstacle[7]);
//	cleardevice();
	
	/* Sprite Handler for Bar Boost Gauge */
	setfillstyle(1, GREEN);
	bar(600 , 600, 600 + (gridSize/2/5), 600 + (gridSize/2/2));
	sh->barBoost = malloc(tempSizing);
	getimage(600, 600, 600 + (gridSize/2/5), 600 + (gridSize/2/2) + 20, sh->barBoost);
	cleardevice();
		
	return sh;
}

/* =============================================================================================== */

void Rendering__backgroundMap(SpriteHandler *sh)
{
	int x, y;
	
	x = 50;
	for (int i = 1; i <= 19; i++)
    {
    	y = 50;
    	for (int j = 1; j <= 12; j++)
    	{	
        	putimage(x, y, sh->backgroundMap, COPY_PUT);
        	y = y + 50;
    	}
        x = x + 50;
    }
}
void Rendering__wallMap(SpriteHandler *sh)
{
    int x, y;
    x = 0;
    
    for (int i = 1; i <= 21; i++)
    {
        putimage(x, 0, sh->wallMap, COPY_PUT);
        x = x + 50;
    }
    
    x = 0;
    
    for (int i = 1; i <= 21; i++)
    {
        putimage(x, 650, sh->wallMap, COPY_PUT);
        x = x + 50;
    }
    
    y = 0;
    
    for (int i = 0; i <= 12; i++)
    {
        putimage(0, y, sh->wallMap, COPY_PUT);
        y = y + 50;
    }
    
    y = 0;
    
    for (int i = 0; i <= 12; i++)
    {
        putimage(1000, y, sh->wallMap, COPY_PUT);
        y = y + 50;
    }
}

void Rendering__barBoost(void* barBoost, int *snakeBoostGauge, int isEating)
{
	int x = 0;
	if (isEating == 1)
	{
		*snakeBoostGauge = 40;
	}
	for(int i=0; i < *snakeBoostGauge; i++)
	{
		putimage(1075 + x, 120, barBoost, COPY_PUT);
		x += 5;
	}
}

void Rendering__food(SpriteHandler *sh, int x, int y, const char ket[15])
{
	if ((strcmp(ket, "Apple")) == 0)
	{
		putimage(x * 50, y * 50, sh->apple, COPY_PUT);
	}
	
	else if ((strcmp(ket, "Mouse")) == 0)
	{
		putimage(x * 50, y * 50, sh->mouse, COPY_PUT);
	}
	
	else if ((strcmp(ket, "Potion")) == 0)
	{
		putimage(x * 50, y * 50, sh->potion, COPY_PUT);
	}	
}

void Rendering__appleComputerSnake(SpriteHandler *sh, int x, int y)
{
	putimage(x * 50, y * 50, sh->apple, COPY_PUT);
}

void Rendering__displayScore(SpriteHandler *sh, int score[])
{
	int x = 0;
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (score[i] == j)
			{
				putimage(1070 + x, 50, sh->numericalScore[j], COPY_PUT);	
			}	
		}
		
		x += 40;
	}	
}

//void Rendering__obstacleMedium(SpriteHandler *sh, Point coordObstacle[])
//{
//	int x = 0;
//	int j = 0;
//	
//	putimage(50+x, 50, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 50+x;
//	coordObstacle[j].coorY = 50;
//	j++;
//	
//	for(int i=0;i<17;i++)
//	{
//		putimage(100+x, 50, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 50;
//		j++;
//		x += 50;
//	}
//	putimage(100+x, 50, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 100+x;
//	coordObstacle[j].coorY = 50;
//	j++;
//	
//	int y = 0;
//	for(int i=0;i<10;i++)
//	{
//		putimage(100+x, 100+y, sh->obstacle[7], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 100+y;
//		j++;
//		y += 50;
//	}
//	
//	x = 0;
//	putimage(50+x, 600, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 50+x;
//	coordObstacle[j].coorY = 600;
//	j++;
//	for(int i=0;i<17;i++)
//	{
//		putimage(100+x, 600, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 600;
//		j++;
//		x += 50;
//	}
//	putimage(100+x, 600, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 100+x;
//	coordObstacle[j].coorY = 600;
//	j++;
//	
//	y = 0;
//	for(int i=0;i<10;i++)
//	{
//		putimage(50, 100+y, sh->obstacle[7], COPY_PUT);
//		coordObstacle[j].coorX = 50;
//		coordObstacle[j].coorY = 100+y;
//		j++;
//		y += 50;
//	}
//}

//void Rendering__obstacleHard(SpriteHandler *sh, Point coordObstacle[])
//{
//	int x = 0;
//	int j=0;
//	
//	putimage(50+x, 250, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 50+x;
//	coordObstacle[j].coorY = 250;
//	j++;
//	
//	for(int i=0;i<6;i++)
//	{
//		putimage(100+x, 250, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 50+x;
//		coordObstacle[j].coorY = 250;
//		j++;
//		x += 50;
//	}
//	putimage(100+x, 250	, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 100+x;
//	coordObstacle[j].coorY = 250;
//	
//	j++;
//	
//	int y = 0;
//	for(int i=0;i<4;i++)
//	{
//		putimage(100+x, 200+y, sh->obstacle[7], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 200+y;
//		j++;
//		y -= 50;
//	}
//	
//	x = 0;
//	putimage(650+x, 350, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 650+x;
//	coordObstacle[j].coorY = 350;
//	j++;
//	for(int i=0;i<5;i++)
//	{
//		putimage(700+x, 350, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 700+x;
//		coordObstacle[j].coorY = 350;
//		j++;
//		x += 50;
//	}
//	putimage(700+x, 350	, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 700+x;
//	coordObstacle[j].coorY = 350;
//	j++;
//	y = 0;
//	for(int i=0;i<5;i++)
//	{
//		putimage(650, 400+y, sh->obstacle[7], COPY_PUT);
//		coordObstacle[j].coorX = 650+x;
//		coordObstacle[j].coorY = 400+y;
//		j++;
//		y += 50;
//	}	
//}
//
//void Rendering__obstacleExpert(SpriteHandler *sh, Point coordObstacle[])
//{
//	int x = 0;
//	int j = 0;
//	
//	putimage(50+x, 50, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 50+x;
//	coordObstacle[j].coorY = 50;
//	j++;
//	
//	for(int i=0;i<17;i++)
//	{
//		putimage(100+x, 50, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 50;
//		j++;
//		x += 50;
//	}
//	putimage(100+x, 50, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 100+x;
//	coordObstacle[j].coorY = 50;
//	j++;
//	
//	int y = 0;
//	for(int i=0;i<10;i++)
//	{
//		putimage(100+x, 100+y, sh->obstacle[7], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 100+y;
//		j++;
//		y += 50;
//	}
//	
//	x = 0;
//	putimage(50+x, 600, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 50+x;
//	coordObstacle[j].coorY = 600;
//	j++;
//	for(int i=0;i<17;i++)
//	{
//		putimage(100+x, 600, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 100+x;
//		coordObstacle[j].coorY = 600;
//		j++;
//		x += 50;
//	}
//	putimage(100+x, 600, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 100+x;
//	coordObstacle[j].coorY = 600;
//	j++;
//	
//	y = 0;
//	for(int i=0;i<10;i++)
//	{
//		putimage(50, 100+y, sh->obstacle[7], COPY_PUT);
//		coordObstacle[j].coorX = 50;
//		coordObstacle[j].coorY = 100+y;
//		j++;
//		y += 50;
//	}
//	
//	x = 0;
//	putimage(300+x, 250, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 300+x;
//	coordObstacle[j].coorY = 250;
//	j++;
//	putimage(300+x, 200, sh->obstacle[7], COPY_PUT);
//	coordObstacle[j].coorX = 300+x;
//	coordObstacle[j].coorY = 200;
//	j++;
//	for(int i=0;i<7;i++)
//	{
//		putimage(350+x, 250, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 350+x;
//		coordObstacle[j].coorY = 250;
//		j++;
//		x+=50;
//	}
//	putimage(350+x, 250, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 350+x;
//	coordObstacle[j].coorY = 250;
//	j++;
//	putimage(350+x, 200, sh->obstacle[7], COPY_PUT);
//	coordObstacle[j].coorX = 350+x;
//	coordObstacle[j].coorY = 200;
//	j++;
//	
//	x = 0;
//	putimage(300+x, 350, sh->obstacle[4], COPY_PUT);
//	coordObstacle[j].coorX = 300+x;
//	coordObstacle[j].coorY = 350;
//	j++;
//	putimage(300+x, 400, sh->obstacle[7], COPY_PUT);
//	coordObstacle[j].coorX = 300+x;
//	coordObstacle[j].coorY = 400;
//	j++;
//	for(int i=0;i<7;i++)
//	{
//		putimage(350+x, 350, sh->obstacle[0], COPY_PUT);
//		coordObstacle[j].coorX = 350+x;
//		coordObstacle[j].coorY = 350;
//		j++;
//		x+=50;
//	}
//	putimage(350+x, 350, sh->obstacle[2], COPY_PUT);
//	coordObstacle[j].coorX = 350+x;
//	coordObstacle[j].coorY = 350;	
//	j++;
//	
//	putimage(350+x, 400, sh->obstacle[7], COPY_PUT);
//	coordObstacle[j].coorX = 350+x;
//	coordObstacle[j].coorY = 400;
//}

/* =============================================================================================== */

void Rendering__snakeBody(LinkedList *l, SpriteHandler *sh)
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
    	if (((SnakeBody *) curr->value)->turn == noDirection && (((SnakeBody *) curr->value)->direction == right || ((SnakeBody *) curr->value)->direction == left))
    	{
			putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->bodyHorizontal, COPY_PUT);
		}
		else if (((SnakeBody *) curr->value)->turn == noDirection && (((SnakeBody *) curr->value)->direction == up || ((SnakeBody *) curr->value)->direction == down))
		{
			putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->bodyVertical, COPY_PUT);
		}
		
		if (((SnakeBody *) curr->value)->turn == right)
		{
			putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->bodyTurn1, COPY_PUT);
		}
		else if (((SnakeBody *) curr->value)->turn == left)
		{
			putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->bodyTurn2, COPY_PUT);
		}
		else if (((SnakeBody *) curr->value)->turn == up)
		{
			putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->bodyTurn3, COPY_PUT);
		}
		else if (((SnakeBody *) curr->value)->turn == down)
		{
			putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->bodyTurn4, COPY_PUT);
		}
		
		curr = curr->next;
	}
	
    /* 	Rendering Tail's Snake 	*/
    if (((SnakeBody *) curr->value)->direction == right)
    {
		putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->tailKanan, COPY_PUT);
    }
    else if (((SnakeBody *) curr->value)->direction == left)
    {
		putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->tailKiri, COPY_PUT);
    }
    else if (((SnakeBody *) curr->value)->direction == up)
    {
    	putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->tailAtas, COPY_PUT);
    }
    else if (((SnakeBody *) curr->value)->direction == down)
    {
	   putimage(((SnakeBody *) curr->value)->coord->coorX, ((SnakeBody *) curr->value)->coord->coorY, sh->tailBawah, COPY_PUT);
    }
}

/* =============================================================================================== */

void Rendering__cursorMenu(int x, int y, const char ket[15])
{
	if ((strcmp (ket, "4Button")) == 0)
	{
		readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 50, y - 50);	
	}
	else if (((strcmp (ket, "2Button")) == 0) || ((strcmp (ket, "3Button")) == 0))
	{
		readimagefile("sprite//menu//cursor_menu.gif", x, y, x - 70, y - 70);	
	}	
}

void Rendering__displayMenu(const char ket[15])
{
	if ((strcmp (ket, "MainMenu")) == 0)
	{
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	    readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	    readimagefile("sprite//menu//Start Game.gif", 400, 530, 200, 470);
	    readimagefile("sprite//menu//Score Button.gif", 400, 620, 200, 680);
	    readimagefile("sprite//menu//Help Button.gif", 700, 530, 500, 470);
	    readimagefile("sprite//menu//Quit Button.gif", 700, 620, 500, 680);
	}
	
    else if ((strcmp (ket, "PlayerMenu")) == 0)
    {
    	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	    readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	    readimagefile("sprite//menu//button_single_player.gif", 280, 500, -20, 420);
		readimagefile("sprite//menu//button_multi_player.gif", 700, 500, 400, 420);
		readimagefile("sprite//menu//button_computer_snake.gif", 490, 600, 190, 520);
		readimagefile("sprite//menu//esc.gif", 1200, 560, 1275, 610);
		readimagefile("sprite//menu//button_back.gif", 1200, 610, 1275, 685);
	}
	
	else if ((strcmp (ket, "ModeMenu")) == 0)
	{
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
	    readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
	    readimagefile("sprite//menu//button_arcade.gif", 700, 550, 400, 470);
		readimagefile("sprite//menu//button_classic.gif", 280, 550, -20, 470);
		readimagefile("sprite//menu//esc.gif", 1200, 560, 1275, 610);
		readimagefile("sprite//menu//button_back.gif", 1200, 610, 1275, 685);
	}
	
	else if ((strcmp (ket, "ClassicMenu")) == 0)
    {
    	readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
		readimagefile("sprite//menu//title select.gif"  , 350, 50, 950, 500);
		readimagefile("sprite//menu//button_easy.gif"   , 400, 530, 200, 470);
		readimagefile("sprite//menu//button_medium.gif" , 400, 620, 200, 680);
		readimagefile("sprite//menu//button_hard.gif"   , 700, 530, 500, 470);
		readimagefile("sprite//menu//button_expert.gif" , 700, 620, 500, 680);
		readimagefile("sprite//menu//esc.gif"           , 1200, 560, 1275, 610);
		readimagefile("sprite//menu//button_back.gif"   , 1200, 610, 1275, 685);
	}
	
	else if ((strcmp (ket, "LoadingScreen")) == 0)
	{
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
		readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
		readimagefile("sprite//loadingbar//bar1.gif", 280,550,1000,650);
		swapbuffers();
		
		delay(1500);
		
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
		readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
		readimagefile("sprite//loadingbar//bar2.gif", 280,550,1000,650);
		swapbuffers();
		
		delay(1500);
		
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
		readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
		readimagefile("sprite//loadingbar//bar3.gif", 280,550,1000,650);
		swapbuffers();
		
		delay(1500);
		
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
		readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
		readimagefile("sprite//loadingbar//bar4.gif", 280,550,1000,650);
		swapbuffers();
		
		delay(1500);
		
		readimagefile("sprite//menu//Title Screen 2.gif", 0, 0, 1300, 700);
		readimagefile("sprite//menu//Title.gif", 350, 50, 950, 500);
		readimagefile("sprite//loadingbar//bar5.gif", 280,550,1000,650);
		swapbuffers();
		
		delay(1000);
	}
	
	else if ((strcmp (ket, "HelpMenu")) == 0)
	{	
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
		
		Rendering__displayMenu("LoadingScreen");
		Rendering__displayMenu("MainMenu");
	    Menu__cursorControlMenu("MainMenu");
	}
	
	else if ((strcmp (ket, "EasyScore")) == 0)
	{
		swapbuffers();
		readimagefile("sprite//menu//Highscore.gif", 0, 0, 1300, 700);
		Rendering__easyHighscore(50);
		swapbuffers();
		do
		{
			
		} while (!GetAsyncKeyState(VK_ESCAPE));
		
		Rendering__displayMenu("LoadingScreen");
		Rendering__displayMenu("MainMenu");
	    Menu__cursorControlMenu("MainMenu");
	}
}

void Rendering__easyHighscore(int gridSize)
{
	FILE *fPointer;
	
	if ((fPointer = fopen("data/HighscoreData.txt","r")) == NULL) {
		perror ("Error opening file\n");
		exit(1);
	}
	
	DataHighscore *data = (DataHighscore*) malloc (5 * sizeof(int));
	int i, j, tempData, digitNumbers;
	int *dataNumbers;
	
	for (i = 0; i < 5; i++)
	{
		fscanf (fPointer, "%s %d", &data[i].playerName, &data[i].playerScore);
		for (j = 0; j < 5; j++)
		{
			switch (data[i].playerName[j])
			{
				case 'A' :
				{
					readimagefile("sprite//Huruf//A.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
					break;
				}
				
				case 'B' :
				{
					readimagefile("sprite//Huruf//B.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
					break;
				}
	        	case 'C' :
				{
					readimagefile("sprite//Huruf//C.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
					break;
				}
			    case 'D' :
			    {
			    	readimagefile("sprite//Huruf//D.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			    	break;
			    }
			    case 'E' :
			    {
			        readimagefile("sprite//Huruf//E.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'F' :
			    {
			        readimagefile("sprite//Huruf//F.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'G' :
			    {
			        readimagefile("sprite//Huruf//G.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'H' :
			    {
			        readimagefile("sprite//Huruf//H.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'I' :
			    {
			        readimagefile("sprite//Huruf//I.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'J' :
			    {
			        readimagefile("sprite//Huruf//J.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'K' :
			    {
			        readimagefile("sprite//Huruf//K.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'L' :
			    {
			        readimagefile("sprite//Huruf//L.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'M' :
			    {
			        readimagefile("sprite//Huruf//M.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'N' :
			    {
			        readimagefile("sprite//Huruf//N.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'O' :
			    {
			        readimagefile("sprite//Huruf//O.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'P' :
			    {
			        readimagefile("sprite//Huruf//P.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'Q' :
			    {
			        readimagefile("sprite//Huruf//Q.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }				
			    case 'R' :
			    {
			        readimagefile("sprite//Huruf//R.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'S' :
			    {
			        readimagefile("sprite//Huruf//S.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'T' :
			    {
			        readimagefile("sprite//Huruf//T.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'U' :
			    {
			        readimagefile("sprite//Huruf//U.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'V' :
			    {
			        readimagefile("sprite//Huruf//V.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'W' :
			    {
			        readimagefile("sprite//Huruf//W.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			    	break;
			    }
			    case 'X' :
			    {
			        readimagefile("sprite//Huruf//X.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'Y' :
			    {
			        readimagefile("sprite//Huruf//Y.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 'Z' :
			    {
			        readimagefile("sprite//Huruf//Z.gif", 350 + (j * gridSize) , 250 +(i * gridSize), 350 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			}
		}
		
		digitNumbers = getIntegerDigits(data[i].playerScore);
		dataNumbers = (int*) malloc (digitNumbers * sizeof(int));
		tempData = data[i].playerScore;
		
		for (j = digitNumbers; j > 0; j--)
		{
			dataNumbers[j] = tempData % 10;
			tempData = tempData / 10;
		}
		
		for (j = 5; j <= digitNumbers + 5; j++)
		{
			switch (dataNumbers[j - 5])
			{
				case 1 :
			    {
			        readimagefile("sprite//Angka//1.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 2 :
			    {
			        readimagefile("sprite//Angka//2.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 3 :
			    {
					readimagefile("sprite//Angka//3.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 4 :
			    {
			        readimagefile("sprite//Angka//4.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 5 :
			    {
			        readimagefile("sprite//Angka//5.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 6 :
			    {
			        readimagefile("sprite//Angka//6.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 7 :
			    {
			        readimagefile("sprite//Angka//7.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 8 :
			    {
			        readimagefile("sprite//Angka//8.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 9 :
			    {
			        readimagefile("sprite//Angka//9.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			    case 0 :
			    {
			        readimagefile("sprite//Angka//0.gif", 450 + (j * gridSize) , 250 +(i*gridSize), 450 + (j * gridSize) + gridSize, 250 + gridSize + (i * gridSize));
			        break;
			    }
			}
		}
	}
	
	fclose(fPointer);	
}

void Rendering__lastScore(SpriteHandler *sh, int score[])
{
	int x = 0;
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (score[i] == j)
			{
				putimage(550 + x, 540, sh->numericalScore[j], COPY_PUT);	
			}	
		}
		x += 40;
	}
}

void Rendering__gameOver()
{
	cleardevice();
	readimagefile("sprite//menu//gameover.gif", 0, 0, 1300, 700);
}

void Rendering__inputName()
{
	swapbuffers();
	readimagefile("sprite//menu//inputname.gif", 0, 0, 1300, 700);
	swapbuffers();
}

void Rendering__characterInput(char playerName[], int arrayLength, int gridSize)
{
	cleardevice();
	swapbuffers();
	Rendering__inputName();
	
	for (int i = 0; i < arrayLength; i++)
	{
		switch (playerName[i])
		{
			case 'A' : 
			{
				readimagefile("sprite//Huruf//A.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
				break;
			}
			
			case 'B' :
			{
				readimagefile("sprite//Huruf//B.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
				break;
			}
          	case 'C' :
			{
				readimagefile("sprite//Huruf//C.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
				break;
			}
		    case 'D' :
		    {
		    	readimagefile("sprite//Huruf//D.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		    	break;
		    }
		    case 'E' :
		    {
		        readimagefile("sprite//Huruf//E.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'F' :
		    {
		        readimagefile("sprite//Huruf//F.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'G' :
		    {
		        readimagefile("sprite//Huruf//G.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'H' :
		    {
		        readimagefile("sprite//Huruf//H.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'I' :
		    {
		        readimagefile("sprite//Huruf//I.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'J' :
		    {
		        readimagefile("sprite//Huruf//J.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'K' :
		    {
		        readimagefile("sprite//Huruf//K.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'L' :
		    {
		        readimagefile("sprite//Huruf//L.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'M' :
		    {
		        readimagefile("sprite//Huruf//M.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'N' :
		    {
		        readimagefile("sprite//Huruf//N.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'O' :
		    {
		        readimagefile("sprite//Huruf//O.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'P' :
		    {
		        readimagefile("sprite//Huruf//P.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'Q' :
		    {
		        readimagefile("sprite//Huruf//Q.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }				
		    case 'R' :
		    {
		        readimagefile("sprite//Huruf//R.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'S' :
		    {
		        readimagefile("sprite//Huruf//S.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'T' :
		    {
		        readimagefile("sprite//Huruf//T.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'U' :
		    {
		        readimagefile("sprite//Huruf//U.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'V' :
		    {
		        readimagefile("sprite//Huruf//V.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'W' :
		    {
		        readimagefile("sprite//Huruf//W.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		    	break;
		    }
		    case 'X' :
		    {
		        readimagefile("sprite//Huruf//X.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'Y' :
		    {
		        readimagefile("sprite//Huruf//Y.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case 'Z' :
		    {
		        readimagefile("sprite//Huruf//Z.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '1' :
		    {
		        readimagefile("sprite//Angka//1.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '2' :
		    {
		        readimagefile("sprite//Angka//2.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '3' :
		    {
		        readimagefile("sprite//Angka//3.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '4' :
		    {
		        readimagefile("sprite//Angka//4.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '5' :
		    {
		        readimagefile("sprite//Angka//5.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '6' :
		    {
		        readimagefile("sprite//Angka//6.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '7' :
		    {
		        readimagefile("sprite//Angka//7.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '8' :
		    {
		        readimagefile("sprite//Angka//8.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '9' :
		    {
		        readimagefile("sprite//Angka//9.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    case '0' :
		    {
		        readimagefile("sprite//Angka//0.gif", 550 + (i * gridSize) , 415, 550 + (i * gridSize) + gridSize, 415 + gridSize);
		        break;
		    }
		    default :
		    {
		        break;
		    }
		}
	}
	swapbuffers();
}	

void Rendering__playerName(char *playerName, int gridSize)
{
	int i = 0;
	
	while (playerName[i]!='\0')
	{
		switch (playerName[i])
		{
			case 'A' : 
			{
				readimagefile("sprite//Huruf//A.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
				break;
			}
			
			case 'B' :
			{
				readimagefile("sprite//Huruf//B.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
				break;
			}
          	case 'C' :
			{
				readimagefile("sprite//Huruf//C.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
				break;
			}
		    case 'D' :
		    {
		    	readimagefile("sprite//Huruf//D.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		    	break;
		    }
		    case 'E' :
		    {
		        readimagefile("sprite//Huruf//E.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'F' :
		    {
		        readimagefile("sprite//Huruf//F.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'G' :
		    {
		        readimagefile("sprite//Huruf//G.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'H' :
		    {
		        readimagefile("sprite//Huruf//H.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'I' :
		    {
		        readimagefile("sprite//Huruf//I.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'J' :
		    {
		        readimagefile("sprite//Huruf//J.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'K' :
		    {
		        readimagefile("sprite//Huruf//K.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'L' :
		    {
		        readimagefile("sprite//Huruf//L.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'M' :
		    {
		        readimagefile("sprite//Huruf//M.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'N' :
		    {
		        readimagefile("sprite//Huruf//N.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'O' :
		    {
		        readimagefile("sprite//Huruf//O.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'P' :
		    {
		        readimagefile("sprite//Huruf//P.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'Q' :
		    {
		        readimagefile("sprite//Huruf//Q.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }				
		    case 'R' :
		    {
		        readimagefile("sprite//Huruf//R.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'S' :
		    {
		        readimagefile("sprite//Huruf//S.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'T' :
		    {
		        readimagefile("sprite//Huruf//T.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'U' :
		    {
		        readimagefile("sprite//Huruf//U.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'V' :
		    {
		        readimagefile("sprite//Huruf//V.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'W' :
		    {
		        readimagefile("sprite//Huruf//W.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		    	break;
		    }
		    case 'X' :
		    {
		        readimagefile("sprite//Huruf//X.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'Y' :
		    {
		        readimagefile("sprite//Huruf//Y.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case 'Z' :
		    {
		        readimagefile("sprite//Huruf//Z.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '1' :
		    {
		        readimagefile("sprite//Angka//1.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '2' :
		    {
		        readimagefile("sprite//Angka//2.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '3' :
		    {
		        readimagefile("sprite//Angka//3.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '4' :
		    {
		        readimagefile("sprite//Angka//4.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '5' :
		    {
		        readimagefile("sprite//Angka//5.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '6' :
		    {
		        readimagefile("sprite//Angka//6.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '7' :
		    {
		        readimagefile("sprite//Angka//7.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '8' :
		    {
		        readimagefile("sprite//Angka//8.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '9' :
		    {
		        readimagefile("sprite//Angka//9.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    case '0' :
		    {
		        readimagefile("sprite//Angka//0.gif", 1075 + (i * gridSize) , 200, 1075 + (i * gridSize) + gridSize, 200 + gridSize);
		        break;
		    }
		    default :
		    {
		        break;
		    }
		}
		i++;
	}
}

void Rendering__boardGame()
{
	readimagefile("sprite//menu//board.gif", 1050, 150, 1300, 700);	
}
