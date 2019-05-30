#include <graphics.h>
#include <dos.h>
#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <menufunc.h>
#include <BRICK.h>
int game();
int set_default();
int draw_ballplayer();
int draw_ball();
int draw_player();
int gamestart();
int ballhit();
int endgame();
int nextlvl();
void del_check();
void draw_bricks1();
void draw_bricks2();
void draw_bricks3();
brick array1[30][30];
long  lives = 3, result;
int number_of_bricks;
int destroy;
int gamewindow;
int  score =0;
int level = 0;
int playerposX = 590, playersizeX = 100, playersizeY = 5, playerscale = 1, playerspeed = 0, radX=5, radY=5,ballX=640, ballY=709; //ball and palyer setup
int ballSX=0, ballSY=0; // ball speed
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                            // MAIN MENU
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main()
{
char menuselect;//для ввода с клавиатуры
int okno;
int sellectedbutton;//принемает значения от 1 до 3, определяет какая кнопка меню была выбрана
int i;
    //window setup
okno = initwindow(1280,720);
while(1){ //goto  replacer
setcolor(BLACK);
setbkcolor(LIGHTBLUE);
cleardevice();
    //
    //bar setup
int barX =400, barY = 100, mainbarwidth = 410, mainbarhigh = 600;// main menu bar size and pozition
    //
    //main manu bar
setfillstyle(1,BLACK);
bar(barX, barY, barX+mainbarwidth, barY+mainbarhigh);
    //
    //game title
setcolor(WHITE);
setbkcolor(BLACK);
settextstyle(0, 0, 10);
outtextxy(440, 100, "ARCANOID");
    //
    //buttons
sellectedbutton = 1;
activebutton1(&sellectedbutton);//по-умолчания выбрана кнопка NEW GAME
buttonselection(&sellectedbutton);//анимируем выбор кнопки
    switch(sellectedbutton)//проверяем какая кнопка была нажата
    {
        case 1: {closegraph(okno);game();break;}
        case 2: {controls(); break;}
        case 3:
            {
                exitwindow();
                break;
            }
    }continue;

return(0);
}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                            // SCREENSET
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
char live[] = "LIVE", arrow;
int gameinterface()//функция отрисовки игрового поля
{
    int gamezoneX1 = 199, gamezoneX2=1080, gamezoneY1=0, gamezoneY2=720;
    gamewindow = initwindow(1280,720);
    cleardevice();
    setbkcolor(BLACK);
    setcolor(WHITE);
    cleardevice();
    rectangle(0,0,1279,720);
    rectangle(gamezoneX1,gamezoneY1,gamezoneX2,gamezoneY2);
    settextstyle(1, 0, 3);
    outtextxy(10, 10, live);
    outtextxy(10, 30, "3");
    outtextxy(1115, 10, "SCORE");
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int game() //игра до запуска мяча
{
 gameinterface();
 switch(level)//выбор уровня
 {
     case 0:{draw_bricks1();break;}
     case 1:{draw_bricks2();break;}
     case 2:{draw_bricks3();break;}
 }
 draw_ballplayer();
    while(1)//перемещаем игрока
    {
    arrow=getch();
    switch(arrow)
        {
        case 's':{gamestart();break;}
        case 77: {playerspeed=2;break;}
        case 75: {playerspeed=-2;break;}
        case ' ': {playerspeed=0;break;}
        case 'p': {getch();break;}
        case 27: {closegraph(gamewindow);set_default();main();break;}
        }

      draw_ballplayer();
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int gamestart() //когда маяч запущен
{
    static char show_lives[]={0};//счет
    char c;
    ballSX=-1;//задаем направление мяча
    ballSY=-1;
    while(1)
    {
        while(!kbhit())//пока не нажата любая кнопка мяч и платформа двигаются без изменений
        {
            if(playerposX==1080-(playersizeX*playerscale)) playerspeed=0;//если платформа ударилась в стену
            if(playerposX==200) playerspeed=0;
            if(ballX==1075||ballX==205) ballSX*=-1;//если мяч ударился в стену
            del_check();//проверка столкновения с блоком
            if(ballY==11||ballY==710) {ballhit();}//отражение от потолка или платформы
            if(ballY==715)//если мяч промахнулся мимо платформы
                {
                    setcolor(WHITE);
                    outtextxy(10, 30, show_lives);
                    lives-=1;
                    if(lives==-1) endgame();
                    sprintf(show_lives , "%d", lives);
                    settextstyle(1, 0, 3);
                    outtextxy(10, 30, show_lives);
                    setfillstyle(1, BLACK);
                    bar(playerposX-5, 680,playerposX+playersizeX, 720);
                    bar(ballX-5,ballY-5,ballX+5,ballY+5);
                    playerposX = 590;
                    playerspeed = 0;
                    ballX=640;
                    ballY=709;
                    ballSX=0;
                    ballSY=0;
                    return(0);
                }

            delay(6);
            draw_player();
            delay(2);
            draw_ball();
        }
        c=getch();//проверям что за кнопка была нажата и меняем направление платформы
        switch(c)
        {
            case 77:{playerspeed=2;break;}
            case 75:{playerspeed=-2;break;}
            case ' ':{playerspeed=0;break;}
            case 'p': {getch();break;}
            case 27: {closegraph(gamewindow);set_default();main();break;}

        }
    }

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                    //BALL AND PLAYER
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int draw_ballplayer()//отрисовка платформы с прикрепленным мячом
{
  while(1)
  {
  if(playerposX==1080-(playersizeX*playerscale)) return(0); //остановка если ударились в стену
  if(playerposX==200) return(0);
  if(kbhit()) return(0); //остановка, если нажата кнопка
  delay(10);
  setfillstyle(1,BLACK);
  bar(playerposX-5, 720-(playersizeY*playerscale),playerposX, 720);
  bar(playerposX+(playersizeX*playerscale), 720-(playersizeY*playerscale),playerposX+(playersizeX*playerscale)+5, 720);
  if(playerspeed!=0) bar(ballX-5,ballY-5,ballX+5,ballY+5);
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
int draw_player()//отрисовка платформы
{

    setfillstyle(1,BLACK);
    bar(playerposX, 720-(playersizeY*playerscale),playerposX+(playersizeX*playerscale), 720);
    setfillstyle(1,LIGHTGREEN);
    playerposX+=playerspeed;
    bar(playerposX, 720-(playersizeY*playerscale),playerposX+(playersizeX*playerscale), 720);

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int draw_ball()//отрисовка мяча
{

    setfillstyle(1,BLACK);
    bar(ballX-5,ballY-5,ballX+5,ballY+5);
    setfillstyle(1,WHITE);
    ballX+=ballSX;
    ballY+=ballSY;
    fillellipse(ballX, ballY, radX, radY);
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int ballhit()//проверка удара в платформу
{
            if(ballY==11)ballSY*=-1;
            if(ballX>=playerposX&&ballX<=(playerposX+playersizeX))
               {//если удар пришедся в часть платформы, которая была ближе к мячу - он отразится в ту же сторону, откуда прилетел
                  if(ballX>=playerposX&&ballX<=(playerposX+playersizeX/2)) {ballSY*=-1; if(ballSX==1)ballSX*=-1;}
                  if(ballX>=(playerposX+playersizeX/2)&&ballX<=(playerposX+playersizeX)) {ballSY*=-1;if(ballSX==-1) ballSX*=-1;
               }
                return(0);
                }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
                                                                //SUPPORT FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
void draw_bricks1()//уровень 1
 {
    level=1;
	int i,j,x=200,y=120,width=44,height=25,color=1,shap=1;
	for(i=0;i<5;i++,y+=26,x=200)
		for(j=0;j<19;j++,x+=46)
		 {
			if(color==15)
				color=1;
				array1[i][j].init(x,y,width,height,color++);
				array1[i][j].paint();

		 }
	number_of_bricks=i*j;
 }

 void draw_bricks2()//уровень 2
 {
    level=2;
	int i,j,x=270,y=120,width=44,height=25,color=2,shap=1;
	for(i=0;i<3;i++,y+=26,x=270)
		for(j=0;j<16;j++,x+=46)
		 {
			if(color==15)
				color=1;
				array1[i][j].init(x,y,width,height,color++);
				array1[i][j].paint();

		 }
	number_of_bricks=i*j;
 }

 void draw_bricks3()//уровень 3
 {
    level=3;
	int i,j,x=200,y=120,width=44,height=25,color=5,shap=1;
	for(i=0;i<6;i++,y+=26,x=200)
		for(j=0;j<19;j++,x+=46)
		 {
			if(color==15)
				color=1;
				array1[i][j].init(x,y,width,height,color++);
				array1[i][j].paint();

		 }
	number_of_bricks=i*j;
 }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
 void del_check()//проверка на столкновение с блоком
 {
int check;
	static char show_result[]={0};
	int j, i;
	for(i=0;i<10;i++)
		for(j=0;j<30;j++)
		 {
			check=array1[i][j].is_in(ballX,ballY);//проверяем столкновение для каждого блока
			if(check)
			 {
				if(check==1)
					ballSY=1;//удар в блок снизу
				if(check==2)
					ballSY=-1;//удар в блок сверху
				if(check==3||check==4)//удар в блок сбоку
					ballSX*=-1;
				array1[i][j].hide();//убираем блок
				outtextxy(1140, 40, show_result);//увеличиваем счет
				result+=1;

				sprintf(show_result , "%d", result);
				setcolor(WHITE);
				outtextxy(1140, 40, show_result);
				setcolor(BLACK);
				if(++destroy==number_of_bricks)//все блоки были учнитожены - след уровень
					nextlvl();
			 }
		 }
 }
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int set_default()//переменные по-умолчанию
{
 result =0;
 level=0;
 lives = 3;
 playerposX = 590;
 playersizeX = 100;
 playersizeY = 5;
 playerscale = 1;
 playerspeed = 0;
 radX=5;
 radY=5;
 ballX=640;
 ballY=709;
 ballSX=0;
 ballSY=0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int nextlvl()//выбор след уровня
{
    switch(level)
    {
        case 0: {level+=1;game();break;}
        case 1: {level+=1;game();break;}
        case 2: {level+=1;game();break;}
        case 3: {endgame(); break;}
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int endgame()//конец игры
{
    char show_result[]={0};
    int barX =340, barY = 155, mainbarwidth = 600, mainbarhigh = 410;
    setfillstyle(1,LIGHTGRAY);
    bar(barX, barY, barX+mainbarwidth, barY+mainbarhigh);
    settextstyle(0, 0, 10);
    setbkcolor(LIGHTGRAY);
    setcolor(WHITE);
    outtextxy(barX+100, barY+15, "GAME OVER");
    settextstyle(0, 0, 2);
    outtextxy(barX+30, barY+150, "Your score:");
    sprintf(show_result , "%d", result);
    setcolor(RED);
    outtextxy(barX+450, barY+150, show_result);
    setcolor(WHITE);
    outtextxy(barX+200, barY+200, "PRESS ANY KEY");
    outtextxy(barX+180, barY+253, "TO RETURN IN MAIN MENU");
    getch();
    set_default();
    closegraph(gamewindow);
    main();
}
