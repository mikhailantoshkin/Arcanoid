
int activebutton1(int *sellectedbutton)
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
outtextxy(buttonX-20, button2Y, "HIGHSCORE");
outtextxy(buttonX+80, button3Y, "EXIT");
    //
    *sellectedbutton = 1;

}
int activebutton2(int *sellectedbutton)
{
int barX =400, barY = 100, mainbarwidth = 410, mainbarhigh = 600;// main menu bar size and pozition
int buttonhigh = 60, buttonwidth = 368, buttonX=barX+40, button1Y = 350, button2Y=460, button3Y=570; // buttons coordinates for sake of easy color change
    //buttons
setcolor(WHITE);
setbkcolor(RED);
settextstyle(0, 0, 8);
outtextxy(buttonX-20, button2Y, "HIGHSCORE");
setbkcolor(LIGHTGRAY);
settextstyle(0, 0, 8);
outtextxy(buttonX, button1Y, "NEW GAME");
outtextxy(buttonX+80, button3Y, "EXIT");
    //
    *sellectedbutton = 2;

}
int activebutton3(int *sellectedbutton)
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
outtextxy(buttonX-20, button2Y, "HIGHSCORE");
outtextxy(buttonX, button1Y, "NEW GAME");
    //
    *sellectedbutton = 3;

}

int buttonselection(int *sellectedbutton)
{int menuselect=0, i;


for(i=0;;i++)  //sycle for menu animation and button chosing
{
    if(menuselect==32 ||menuselect== '/n') break;
    menuselect = getch();
    if(*sellectedbutton == 1)
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

int exitactivebutton1(int *sellectedbutton)
{

int barX =340, barY = 155, mainbarwidth = 600, mainbarhigh = 410;// main menu bar size and pozition
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

int exitactivebutton2(int *sellectedbutton)
{

int barX =340, barY = 155, mainbarwidth = 600, mainbarhigh = 410;// main menu bar size and pozition
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

int exitbuttonselection(int *sellectedbutton)
{
 int menuselect=0, i;


for(i=0;;i++)  //sycle for menu animation and button chosing
{
    if(menuselect==32 ||menuselect== '/n') break;
    menuselect = getch();
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
int exitwindow()
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
switch(sellectedbutton)
    {
        case 1: exit(0);
        case 2: break;
    }
}
