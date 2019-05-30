
class brick
 {
	int x,y; //координаты левого верхнего угла блока
	int width, height;//размеры блока
	int bg;//цвет блока
	int enable;
	int shape;
	int destroy;
	public:
		void init(int,int,int,int,int,int,int);
		void init_destroy();
		void undo_destroy();
		void paint();
		int  is_in(int,int);
		void hide();
 };

void brick::init(int _x,int _y,int w,int h,int _bg,int _shape=0,int _destroy=0)  //инициализация
 {
	x=_x;
	y=_y;
	width=w;
	height=h;
	bg=_bg;
	enable=1;
	shape=_shape;
	destroy=_destroy;
 }

void brick::paint()//отрисовка
 {
	if(shape)
		setfillstyle(10,bg);
	else
		setfillstyle(1,bg);
	bar(x, y, x+width-1, y+height-1);
	setcolor(WHITE);
	line(x, y, x+width-1, y);
	line(x, y, x, y+height-1);
	line(x, y+height-1, x+width-1, y+height-1);
	line(x+width-1, y+height-1, x+width-1, y);
	if(shape)
	 {
		setfillstyle(1,RED);
		fillellipse(x+width/2,y+height/2,10,10);
		setcolor(BLACK);
		circle(x+width/2-5,y+height/2-3,1);
		circle(x+width/2+5,y+height/2-3,1);
		circle(x+width/2,y+height/2+1,1);
		pieslice(x+width/2,y+height/2+5,180,360,3);
	 }
	setcolor(BLACK);
 }

int brick::is_in(int x1, int y1)//проверка столкновения
 {
	if(x1>=x-5&&x1<=x+width+5&&y1<=y+height+5&&y1>=y-5&&destroy&&enable)
		return 5;
	if(x1>=x-5&&x1<=x+width+5&&y1<=y+height+5&&y1>=y+height&&enable)//удар снизу
		return 1;
	else if(x1>=x-5&&x1<=x+width+5&&y1<=y+5&&y1>=y&&enable)//удар сверху
		return 2;
	else if(x1<=x+width+5&&x1>=x+width&&y1>=y-5&&y1<=y+height+5&&enable)//удар справа
		return 3;
	else if(x1>=x-5&&x1<=x&&y1>=y-5&&y1<=y+height+5&&enable)//удар слева
		return 4;
	return 0;
 }

void brick::hide()//убираем блок
 {
	setfillstyle(1,BLACK);
	bar(x, y, x+width-1, y+height-1);
	setcolor(BLACK);
	line(x, y, x+width-1, y);
	line(x, y, x, y+height-1);
	line(x, y+height-1, x+width-1, y+height-1);
	line(x+width-1, y+height-1, x+width-1, y);
	setfillstyle(1,WHITE);
	enable=0;
 }

void brick::init_destroy()
 {
	destroy=1;
 }

void brick::undo_destroy()
 {
	destroy=0;
 }



