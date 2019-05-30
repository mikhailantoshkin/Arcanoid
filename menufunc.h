#ifndef MENUFUNC_H_INCLUDED
#define MENUFUNC_H_INCLUDED
#include <stdio.h>
#include <cstdio>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int exitwindow();
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int activebutton1(int *sellectedbutton)//Выбрана кнопка NEW GAME
{
int barX =400, barY = 100, mainbarwidth = 410, mainbarhigh = 600;// main menu bar size and pozition
int buttonhigh = 60, buttonwidth = 368, buttonX=barX+40, button1Y = 350, button2Y=460, button3Y=570; // buttons coordinates for sake of easy color change
    //buttons
setcolor(WHITE);
setbkcolor(RED);
settextstyle(0, 0, 8);
outtextxy(buttonX, button1Y, "NEW GAME");
setbkcolor(LIGHTGRAY);
settextstyle(0, 0, 8);
outtextxy(buttonX, button2Y, "CONTROLS");
outtextxy(buttonX+80, button3Y, "EXIT");
    //
    *sellectedbutton = 1;//переменная, чтобы знать какая кнопка сейчас выбрана
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
}
int activebutton2(int *sellectedbutton)//Выбрана кнопка CONTROLS
{
int barX =400, barY = 100, mainbarwidth = 410, mainbarhigh = 600;// main menu bar size and pozition
int buttonhigh = 60, buttonwidth = 368, buttonX=barX+40, button1Y = 350, button2Y=460, button3Y=570; // buttons coordinates for sake of easy color change
    //buttons
setcolor(WHITE);
setbkcolor(RED);
settextstyle(0, 0, 8);
outtextxy(buttonX, button2Y, "CONTROLS");
setbkcolor(LIGHTGRAY);
settextstyle(0, 0, 8);
outtextxy(buttonX, button1Y, "NEW GAME");
outtextxy(buttonX+80, button3Y, "EXIT");
    //
    *sellectedbutton = 2;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int activebutton3(int *sellectedbutton)//Выбрана кнопка EXIT
{

int barX =400, barY = 100, mainbarwidth = 410, mainbarhigh = 600;// main menu bar size and pozition
int buttonhigh = 60, buttonwidth = 368, buttonX=barX+40, button1Y = 350, button2Y=460, button3Y=570; // buttons coordinates for sake of easy color change

    //buttons
setcolor(WHITE);
setbkcolor(RED);
settextstyle(0, 0, 8);
outtextxy(buttonX+80, button3Y, "EXIT");
setbkcolor(LIGHTGRAY);
settextstyle(0, 0, 8);
outtextxy(buttonX, button2Y, "CONTROLS");
outtextxy(buttonX, button1Y, "NEW GAME");
    //
    *sellectedbutton = 3;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int buttonselection(int *sellectedbutton)//функция для анимации выбора кнопок в меню
{int menuselect=0, i;
for(i=0;;i++)  
{
    if(menuselect==32 ||menuselect== '\n') break; //если нажали пробел - сделан выбор
    menuselect = getch();
    if(*sellectedbutton == 1)//если была выбрана кнопка NEW GAME по нажаию стрелок выбираем другую и тд
    {
        switch(menuselect)
        {
            case 72:
                {
                    activebutton3(sellectedbutton);
                    break;
                }
            case 80:
                {
                   activebutton2(sellectedbutton);
                    break;
                }
            default: break;
        }
    }
    else {

 if(*sellectedbutton == 2)
    {
        switch(menuselect)
        {
            case 72:
                {
                    activebutton1(sellectedbutton);
                    break;
                }
            case 80:
                {
                   activebutton3(sellectedbutton);
                    break;
                }
            default: break;
        }
    }
    else{

  if(*sellectedbutton == 3)
    {
        switch(menuselect)
        {
            case 72:
                {
                    activebutton2(sellectedbutton);
                    break;
                }
            case 80:
                {
                   activebutton1(sellectedbutton);
                    break;
                }
            default: break;

        }
    }
}
}
}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int exitactivebutton1(int *sellectedbutton)//выбрана кнопка YES в меню выхода
{
int barX =340, barY = 155, mainbarwidth = 600, mainbarhigh = 410;// menu bar size and pozition
int buttonX1=barX+40, buttonX2=barX+mainbarwidth-120, buttonY = barY+mainbarhigh-120; // buttons coordinates for sake of easy color change
    //buttons
setcolor(WHITE);
setbkcolor(RED);
settextstyle(0, 0, 8);
outtextxy(buttonX1, buttonY, "YES");
setbkcolor(LIGHTGRAY);
settextstyle(0, 0, 8);
outtextxy(buttonX2, buttonY, "NO");
    //
    *sellectedbutton = 1;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int exitactivebutton2(int *sellectedbutton)//выбрана кнопка NO в меню выхода
{
int barX =340, barY = 155, mainbarwidth = 600, mainbarhigh = 410;// menu bar size and pozition
int buttonX1=barX+40, buttonX2=barX+mainbarwidth-120, buttonY = barY+mainbarhigh-120; // buttons coordinates for sake of easy color change
    //buttons
setcolor(WHITE);
setbkcolor(RED);
settextstyle(0, 0, 8);
outtextxy(buttonX2, buttonY, "NO");
setbkcolor(LIGHTGRAY);
settextstyle(0, 0, 8);
outtextxy(buttonX1, buttonY, "YES");
    //
    *sellectedbutton = 2;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int exitbuttonselection(int *sellectedbutton)//функция для анимации выбора кнопок в меню выхода, работает так же, как buttonselection
{
 int menuselect=0, i;
for(i=0;;i++)  
{
    if(menuselect==32 ||menuselect== '\n') break;
    menuselect = getch();
    //if(menuselect ==27) {*sellectedbutton = 2;return(0);}
    if(*sellectedbutton == 1)
    {
        switch(menuselect)
        {
            case 75:
                {
                    exitactivebutton2(sellectedbutton);
                    break;
                }
            case 77:
                {
                   exitactivebutton2(sellectedbutton);
                    break;
                }
            default: break;
        }
    }
    else {

 if(*sellectedbutton == 2)
    {
        switch(menuselect)
        {
            case 75:
                {
                    exitactivebutton1(sellectedbutton);
                    break;
                }
            case 77:
                {
                   exitactivebutton1(sellectedbutton);
                    break;
                }
            default: break;
        }
    }
}
}
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int exitwindow() //меню выхода из игры
{  setcolor(BLACK);
   setbkcolor(LIGHTBLUE);
   cleardevice();
    //bar setup
int barX =340, barY = 155, mainbarwidth = 600, mainbarhigh = 410, sellectedbutton;// main menu bar size and pozition
    //
    //bar
setfillstyle(1,BLACK);
bar(barX, barY, barX+mainbarwidth, barY+mainbarhigh);
    //
setcolor(WHITE);
setbkcolor(BLACK);
settextstyle(0, 0, 10);
outtextxy(barX+15, barY+15, "ARE YOU SHURE?");
exitactivebutton2(&sellectedbutton);
exitbuttonselection(&sellectedbutton);
switch(sellectedbutton)//проверяем какая кнопка была нажата
    {
        case 1: exit(0);
        case 2: return(0);
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
int controls()//отрисовка раздела CONTROLS
{
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
settextstyle(0, 0, 9);
outtextxy(440, 100, "CONTROLS");
settextstyle(0, 0, 2);
outtextxy(410, 197, "S - LUNCH BALL");
outtextxy(410, 250, "SPACE - STOP");
outtextxy(410, 303, "ARROWS - MOVE PLATFORM");
outtextxy(410, 356, "P - PAUSE ");
outtextxy(410, 412, "ESC - BACK TO MAIN MENU");
settextstyle(0, 0, 5);
setbkcolor(RED);
outtextxy(525, 650, "BACK");
while(1)
{
    menuselect= getch();//проверка на выход нажатия кнопки BACK
    if(menuselect== 32|| menuselect==27) return(0);
}

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif // MENUFUNC_H_INCLUDED
