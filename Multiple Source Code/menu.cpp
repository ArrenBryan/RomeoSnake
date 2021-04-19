#include "menu.hpp"

void Menu__cursorControlMenu(const char ket[15])
{
	Button button;
	int x, y;
	int isEntered = 0;
	    
    if (((strcmp (ket, "MainMenu")) == 0) || ((strcmp (ket, "ClassicMenu")) == 0) || ((strcmp (ket, "ClassicScore")) == 0))
    {
	    x = 340;
	    y = 540;
	
	    Rendering__cursorMenu(x, y, "4Button");
	    swapbuffers();
	
	    while (isEntered == 0)
	    {
	        if (GetAsyncKeyState(VK_RIGHT))
			{
			    button = arrowright; 
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
			    button = arrowleft;
			}
			else if (GetAsyncKeyState(VK_UP)) 
			{
			    button = arrowup;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
			    button = arrowdown; 
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
			    button = enter; 
			}
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
			    button = esc; 
			}
			
	        switch (button)
	        {
		        case arrowright:		// Arrow Right Pressed
		        {
		            cleardevice();
		            
		            if ((strcmp (ket, "MainMenu")) == 0) Rendering__displayMenu("MainMenu");
		            if ((strcmp (ket, "ClassicMenu")) == 0) Rendering__displayMenu("ClassicMenu");
		            if ((strcmp (ket, "ClassicScore")) == 0) Rendering__displayMenu("ClassicMenu");
		            
		            x = x + 300;
					Menu__checkCursorButton(&x, &y, "4Button");
		            Rendering__cursorMenu(x, y, "4Button");
		            
		            swapbuffers();
		            break;
		        }
		        case arrowleft:			// Arrow Left Pressed
		        {
		            cleardevice();
		            
		            if ((strcmp (ket, "MainMenu")) == 0) Rendering__displayMenu("MainMenu");
		            if ((strcmp (ket, "ClassicMenu")) == 0) Rendering__displayMenu("ClassicMenu");
		            if ((strcmp (ket, "ClassicScore")) == 0) Rendering__displayMenu("ClassicMenu");
		            
		            x = x - 300;
					Menu__checkCursorButton(&x, &y, "4Button");
		            Rendering__cursorMenu(x, y, "4Button");
		            
		            swapbuffers();
		            break;
		        }
		        case arrowup:			// Arrow Up Pressed
		        {
		            cleardevice();
		            
		            if ((strcmp (ket, "MainMenu")) == 0) Rendering__displayMenu("MainMenu");
		            if ((strcmp (ket, "ClassicMenu")) == 0) Rendering__displayMenu("ClassicMenu");
		            if ((strcmp (ket, "ClassicScore")) == 0) Rendering__displayMenu("ClassicMenu");
		            
		            y = y - 80;
					Menu__checkCursorButton(&x, &y, "4Button");
		            Rendering__cursorMenu(x, y, "4Button");
		            
		            swapbuffers();
		            break;
		        }
		        case arrowdown:			// Arrow Down Pressed
		        {
		            cleardevice();
		            
		            if ((strcmp (ket, "MainMenu")) == 0) Rendering__displayMenu("MainMenu");
		            if ((strcmp (ket, "ClassicMenu")) == 0) Rendering__displayMenu("ClassicMenu");
		            if ((strcmp (ket, "ClassicScore")) == 0) Rendering__displayMenu("ClassicMenu");
		            
		            y = y + 80;
					Menu__checkCursorButton(&x, &y, "4Button");
		            Rendering__cursorMenu(x, y, "4Button");
		            
		            swapbuffers();
		            break;
		        }
		        case enter:				// Enter Button Pressed
		        {
		            isEntered = 1;
		            
					if ((strcmp (ket, "MainMenu")) == 0)
		            {
		            	Menu__checkEnterButton(x, y, "MainMenu");	
					}
					else if ((strcmp (ket, "ClassicMenu")) == 0)
					{
						Menu__checkEnterButton(x, y, "ClassicMenu");
					}
					else if ((strcmp (ket, "ClassicScore")) == 0)
					{
						Menu__checkEnterButton(x, y, "ClassicScore");
					}
				
		            break;
		        }
		        case esc:				// Esc Button Pressed
	        	{
	        		if ((strcmp (ket, "MainMenu")) == 0) break;
					else if ((strcmp (ket, "ClassicMenu")) == 0)
					{
						cleardevice();
						Rendering__displayMenu("ModeMenu");
						Menu__cursorControlMenu("ModeMenu");
					}
					else if ((strcmp (ket, "ClassicScore")) == 0)
					{
						cleardevice();
						Rendering__displayMenu("ModeMenu");
						Menu__cursorControlMenu("ModeMenuScore");
					}
		            break;	
				}
	        }
	    }
	}
	
	else if ((strcmp (ket, "PlayerMenu")) == 0)
	{
	    x = 200;
	    y = 520;
	
	    Rendering__cursorMenu(x, y, "3Button");
	    swapbuffers();
	   
	    while (isEntered == 0)
	    {
	        if (GetAsyncKeyState(VK_RIGHT))
			{
			    button = arrowright; 
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
			    button = arrowleft;
			}
			else if (GetAsyncKeyState(VK_UP)) 
			{
			    button = arrowup;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
			    button = arrowdown; 
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
			    button = enter; 
			}
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
			    button = esc; 
			}
			
	        switch (button)
	        {
		        case arrowright:		// Arrow Right Pressed
		        {
		            cleardevice();
		            
		            Rendering__displayMenu("PlayerMenu");
		            
		            if (y == 620) x = x + 150;
		            else if (y == 520 )x = x + 420;
					Menu__checkCursorButton(&x, &y, "3Button");
		            Rendering__cursorMenu(x, y, "3Button");
		            
		            swapbuffers();
		            break;
		        }
		        case arrowleft:			// Arrow Left Pressed
		        {
		            cleardevice();
		            
		            Rendering__displayMenu("PlayerMenu");
		            
		            if (y == 620) x = x - 150;
		            else if (y == 520) x = x - 420;
					Menu__checkCursorButton(&x, &y, "3Button");
					Rendering__cursorMenu(x, y, "3Button");
		            
					swapbuffers();
		            break;
		        }
				case arrowup:			// Arrow up Pressed
		        {
		            cleardevice();
		            
		            Rendering__displayMenu("PlayerMenu");
		            
		            x = x - 210;
		            y = y - 100;
					Menu__checkCursorButton(&x, &y, "3Button");
					Rendering__cursorMenu(x, y, "3Button");
		            
					swapbuffers();
		            break;
		        }
				case arrowdown:			// Arrow up Pressed
		        {
		            cleardevice();
		            
		            Rendering__displayMenu("PlayerMenu");
		            
		            if (x == 200){
		            	x = x + 210;
					}
					else if (x == 620){
						x = x - 210;
					}
					
		            y = y + 100;
					Menu__checkCursorButton(&x, &y, "3Button");
					Rendering__cursorMenu(x, y, "3Button");
		            
					swapbuffers();
		            break;
		        }		        
		        case enter:				// Enter Button Pressed	
		        {
		            isEntered = 1;
					Menu__checkEnterButton(x, y, "PlayerMenu");	
		            break;
		        }
		        case esc:				// Esc Button Pressed
		        {
					cleardevice();
					Rendering__displayMenu("MainMenu");
					Menu__cursorControlMenu("MainMenu");	
		            break;
				}
	        }
		}
	}
	else if (((strcmp (ket, "ModeMenu")) == 0) || ((strcmp (ket, "ModeMenuScore")) == 0))
	{
	    x = 200;
	    y = 560;
	
	    Rendering__cursorMenu(x, y, "2Button");
	    swapbuffers();
	   
	    while (isEntered == 0)
	    {
	        if (GetAsyncKeyState(VK_RIGHT))
			{
			    button = arrowright; 
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
			    button = arrowleft;
			}
			else if (GetAsyncKeyState(VK_RETURN))
			{
			    button = enter; 
			}
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
			    button = esc; 
			}
			
	        switch (button)
	        {
		        case arrowright:		// Arrow Right Pressed
		        {
		            cleardevice();
		
		            Rendering__displayMenu("ModeMenu");		            
		            x = x + 420;
					Menu__checkCursorButton(&x, &y, "2Button");
		            Rendering__cursorMenu(x, y, "2Button");
		            
		            swapbuffers();
		            break;
		        }
		        case arrowleft:			// Arrow Left Pressed
		        {
		            cleardevice();
		            
					Rendering__displayMenu("ModeMenu");
		            x = x - 420;
					Menu__checkCursorButton(&x, &y, "2Button");
					Rendering__cursorMenu(x, y, "2Button");
		            
					swapbuffers();
		            break;
		        }
		        case enter:				// Enter Button Pressed	
		        {
					isEntered = 1;
					
					if ((strcmp (ket, "ModeMenu")) == 0)
					{
						Menu__checkEnterButton(x, y, "ModeMenu");
					}
					
					else if ((strcmp (ket, "ModeMenuScore")) == 0)
					{
						Menu__checkEnterButton(x, y, "ModeMenuScore");
					}
					
		            break;
		        }
		        case esc:				// Esc Button Pressed
		        {
					if ((strcmp (ket, "ModeMenu")) == 0)
					{
						cleardevice();
						Rendering__displayMenu("PlayerMenu");
						Menu__cursorControlMenu("PlayerMenu");
					}
					if ((strcmp (ket, "ModeMenuScore")) == 0)
					{
						cleardevice();
						Rendering__displayMenu("MainMenu");
						Menu__cursorControlMenu("MainMenu");
					}
					
		            break;
				}
	        }
		}		
	}	
}

void Menu__checkCursorButton(int *x, int *y, const char ket[15])
{
	if ((strcmp (ket, "4Button")) == 0)
	{
		if (*y > 620) *y = 620;
	    if (*y < 540) *y = 540;
	    if (*x > 640) *x = 640;
	    if (*x < 340) *x = 340;
	}
	
	if ((strcmp (ket, "2Button")) == 0)
	{
		if (*x < 200) *x = 200;
		if (*x > 620) *x = 620;
	}
	
	if ((strcmp (ket, "3Button")) == 0)
	{   
        if ((*x == 200) && (*y < 520))
        {
            *x = 200;
            *y = 520;
        }
        
        else if ((*x == 620) && (*y < 520))
		{
        	*x = 620;
        	*y = 520;
		}

        else if (((*y == 520) && (*x < 200)) || ((*y == 620) && (*x < 410)))
        {
            *x = 200;
            *y = 520;
        }

        else if ((*x == 410) && (*y > 620))
        {
            *x = 410;
            *y = 620;
        }
        
        else if ((*x == 620) && (*y > 520))
        {
            *x = 410;
        }
        
        else if ((*y == 620) && (*x > 410))
        {
            *x = 620;
            *y = 520;
        }

        if (*x < 200) *x = 200;
        if (*y > 620) *y = 620;
        if (*x > 620) *x = 620;
        if (*y < 520) *y = 520;
	}
}

void Menu__checkEnterButton(int x, int y, const char ket[15])
{
	Sleep(200);
	if ((strcmp (ket, "MainMenu")) == 0)
	{
		if ((x == 340) && (y == 540))			// PlayGame Button
	    {
			cleardevice();
			Rendering__displayMenu("PlayerMenu");
			Menu__cursorControlMenu("PlayerMenu");
		}
		
	    else if ((x == 640) && (y == 540))		// Help Button
	    {
	        cleardevice();
			Rendering__displayMenu("HelpMenu");
	    }
	    
	    else if ((x == 340) && (y == 620))		// Score Button
	    {
	        Rendering__displayMenu("ModeMenu");
	        Menu__cursorControlMenu("ModeMenuScore");
	    }
	    
	    else if ((x == 640) && (y == 620))		// Exit Button
	    {
			exit(0);
	    }
	}
	
	else if ((strcmp (ket, "PlayerMenu")) == 0)
	{
		if ((x == 200) && (y == 520))			// SinglePlayer Button
		{
			cleardevice();
			Rendering__displayMenu("ModeMenu");
			Menu__cursorControlMenu("ModeMenu");
		}
		
		else if ((x == 620) && (y == 520))		// MultiPlayer Button (locked)
		{
			cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");					
		}
		
		else if ((x == 410) && (y == 620))		// Computer Snake Button
		{
			cleardevice();
			Game__computerSnake();				
		}
	}
	
	else if ((strcmp (ket, "ModeMenu")) == 0)
	{
		if ((x == 200) && (y == 560))			// Classic Mode Button
		{
			cleardevice();
			Rendering__displayMenu("ClassicMenu");
			Menu__cursorControlMenu("ClassicMenu");	
		}
		
		else if ((x == 620) && (y == 560))		// Arcade Mode Button (locked)
		{
			cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");
		}
	}
	
	else if ((strcmp (ket, "ClassicMenu")) == 0)
	{
		cleardevice();
	
		if ((x == 340) && (y == 540))			// Level Easy Button
	    {
			Game__classicNonObs();
		}
		
	    else if ((x == 640) && (y == 540))		// Level Medium Button
	    {
	        cleardevice();
			Rendering__displayMenu("MainMenu");	
			Menu__cursorControlMenu("MainMenu");						
	    }
	    
	    else if ((x == 340) && (y == 620))		// Level Hard Button
	    {
	        cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");					
	    }
	    
	    else if ((x == 640) && (y == 620))		// Level Expert Button
	    {
			cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");
	    }
	}
	
	else if ((strcmp (ket, "ModeMenuScore")) == 0)		// SCORING PURPOSE
	{
		if ((x == 200) && (y == 560))			// Classic Mode Button
		{
			cleardevice();
			Rendering__displayMenu("ClassicMenu");
			Menu__cursorControlMenu("ClassicScore");
		}
		
		else if ((x == 620) && (y == 560))		// Arcade Mode Button (locked)
		{
			cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");
		}
	}
	else if ((strcmp (ket, "ClassicScore")) == 0)	// SCORING PURPOSE
	{
		cleardevice();
		
		if ((x == 340) && (y == 540))			// Level Easy Button
	    {
			cleardevice();
			Rendering__displayMenu("EasyScore");
		}
		
	    else if ((x == 640) && (y == 540))		// Level Medium Button
	    {
			cleardevice();
			Rendering__displayMenu("MainMenu");	
			Menu__cursorControlMenu("MainMenu");						
	    }
	    
	    else if ((x == 340) && (y == 620))		// Level Hard Button
	    {
	        cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");					
	    }
	    
	    else if ((x == 640) && (y == 620))		// Level Expert Button
	    {
			cleardevice();
			Rendering__displayMenu("MainMenu");
			Menu__cursorControlMenu("MainMenu");
	    }
	}
}
