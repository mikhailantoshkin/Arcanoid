#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <stdio.h>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <string>
int drawplayer();
int playerballmoveR();
int playerballmoveL();
int playermoveR();
int playermoveL();
int ballmoveupleft();
int ballmovedownleft();
int ballmovedownright();
int ballmoveupright();
int  score =0, lives = 3;
int playerposX = 590, playersizeX = 100, playersizeY = 10, playerscale = 1, playerspeed = 0, radX=5, radY=5,ballX=640, ballY=705;
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                            // SCREENSET
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
char live[] = "LIVE X 3", playerscore[]="0000", arrow;
int gameinterface()
{
    int gamezoneX1 = 199, gamezoneX2=1080, gamezoneY1=0, gamezoneY2=720;
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
    cleardevice();
    rectangle(0,0,1279,720);
    rectangle(gamezoneX1,gamezoneY1,gamezoneX2,gamezoneY2);
    settextstyle(1, 0, 3);
    outtextxy(10, 10, live);
    outtextxy(1115, 10, "SCORE");
    outtextxy(1140, 40, playerscore);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int controls()
{
    int gamezoneX1 = 199, gamezoneX2=1080, gamezoneY1=0, gamezoneY2=720;
    int gamewindow;
    gamewindow = initwindow(1280,720);
    setbkcolor(BLACK);
    setcolor(WHITE);
    cleardevice();
    rectangle(0,0,1279,720);
    rectangle(gamezoneX1,gamezoneY1,gamezoneX2,gamezoneY2);
    settextstyle(0, 0, 4);
    outtextxy(250, 250, "SPACEBAR - LUNCH BALL");
    outtextxy(250, 303, "ARROWS - MOVE PLATFORM ");
    outtextxy(250, 456, "PRESS ANY KEY TO CONTINUE");
    getch();
    return(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int game()
{

 controls();
 gameinterface();
 draw_ballplayer();
    while(1)
    {
    arrow=getch();
    switch(arrow)
        {
        case 's':{break;}
        case 77: {playerspeed=5;break;}
        case 75: {playerspeed=-5;break;}
        case ' ': {playerspeed=;break;}
        }
      draw_ballplayer();
    }
//system("pause");
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                           // PLAYER
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int draw_ballplayer()
{
  while(1)
  {
  if(playerposX==1080-(playersizeX*playerscale)) return(0);
  if(playerposX==200) return(0);
  if(kbhit()) return(0);
  setfillstyle(1,BLACK);
  bar(playerposX, 720-(playersizeY*playerscale)-10,playerposX+(playersizeX*playerscale), 720);
  setfillstyle(1,LIGHTGREEN);
  playerposX+=playerspeed;
  ballX+=playerspeed;
  bar(playerposX, 720-(playersizeY*playerscale),playerposX+(playersizeX*playerscale), 720);
  setfillstyle(1,WHITE);
  fillellipse(ballX, ballY, radX, radY);
  }


}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int draw_player()
{
        if(playerposX==1080-(playersizeX*playerscale)) return(0);
        if(playerposX==200) return(0);
        if(kbhit()) return(0);
        setfillstyle(1,BLACK);
        bar(playerposX, 720-(playersizeY*playerscale),playerposX+(playersizeX*playerscale), 720);
        setfillstyle(1,LIGHTGREEN);
        playerposX+=playerspeed;
        bar(playerposX, 720-(playersizeY*playerscale),playerposX+(playersizeX*playerscale), 720);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                                       // BALL
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//

int ballmoveupright()
{
    while(1)
    {
    delay(4);
    setfillstyle(1,BLACK);
    bar(ballX-5,ballY-5,ballX+5,ballY+5);
    setfillstyle(1,WHITE);
    ballX+=1;
    ballY-=1;
    fillellipse(ballX, ballY, radX, radY);
    if(ballX==1075) break;
    if(ballY==10) break;
    }
    if(ballX==1075) ballmoveupleft();
    if(ballY==10) ballmovedownright();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int ballmoveupleft()
{
    while(1)
    {
    delay(4);
    setfillstyle(1,BLACK);
    bar(ballX-5,ballY-5,ballX+5,ballY+5);
    setfillstyle(1,WHITE);
    ballX-=1;
    ballY-=1;
    fillellipse(ballX, ballY, radX, radY);
    if(ballX==205) break;
    if(ballY==10) break;
    }
    if(ballX==205) ballmoveupright();
    if(ballY==10) ballmovedownleft();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int ballmovedownleft()
{
    while(1)
    {
    delay(4);
    setfillstyle(1,BLACK);
    bar(ballX-5,ballY-5,ballX+5,ballY+5);
    setfillstyle(1,WHITE);
    ballX-=1;
    ballY+=1;
    fillellipse(ballX, ballY, radX, radY);
    if(ballY==705&&ballX>=playerposX&&ballX<=(playerposX+playersizeX)) break;
    else
    {
        if(ballY==715) break;
    }
    if(ballX==205) break;
    }
    if(ballY==715)
        {
            setfillstyle(1,BLACK);
            bar(200,680,1080,720);
            ballX=640, ballY=705;
            playerposX = 590;
            lives-=1;
            return(0);

        }
    if(ballY==705&&ballX>=playerposX&&ballX<=(playerposX+playersizeX)) ballmoveupleft();
    if(ballX==205) ballmovedownright();
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int ballmovedownright()
{
    while(1)
    {
    delay(4);
    setfillstyle(1,BLACK);
    bar(ballX-5,ballY-5,ballX+5,ballY+5);
    setfillstyle(1,WHITE);
    ballX+=1;
    ballY+=1;
    fillellipse(ballX, ballY, radX, radY);
    if(ballY==705&&ballX>=playerposX&&ballX<=(playerposX+playersizeX)) break;
    else
    {
        if(ballY==715) break;
    }
    if(ballX==1075) break;
    }
    if(ballY==715)
        {
            setfillstyle(1,BLACK);
            bar(200,680,1080,720);
            ballX=640, ballY=705;
            playerposX = 590;
            lives-=1;
            return(0);

        }
    if(ballY==705&&ballX>=playerposX&&ballX<=(playerposX+playersizeX)) ballmoveupright();
    if(ballX==1075) ballmovedownleft();
}



#endif // GAME_H_INCLUDED
