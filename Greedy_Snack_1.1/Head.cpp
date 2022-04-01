#include"Head.h"
#include<iostream>
#include<conio.h>


int Snake::count = 0;
Board::Board()	//最后别忘设置food
{
	for (int i = 1; i < H - 1; i++)
		for (int j = 1; j < W - 1; j++)
			bg[i][j] = ' ';
	for (int i = 0; i < W; i++)
		bg[0][i] = bg[H - 1][i] = '#';
	for (int i = 1; i < H - 1; i++)
		bg[i][0] = bg[i][W - 1] = '#';
	food();
}
void Board::Prt()
{
	//先清除屏幕 再打印
	system("cls");
	std::cout << std::endl;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			std::cout << bg[i][j] << ' ';
		std::cout << std::endl;
	}
	std::cout << "        当前的蛇的等级: " << (1000 - gamespeed) / 100 + 1 << std::endl;
	std::cout << "        你已吃了 " << Snake::count << " 个食物" << std::endl;
}
void Board::Speed_control()
{
	if (gamespeed <= 0) gamespeed = 100;
	gamespeed = 1000 - (count / 5) * 100;
}
void Board::food()
{
	srand(time(0));
	do {
		x1 = rand() % (H - 2) + 1;	//1 ~ H-2
		y1 = rand() % (W - 2) + 1;
	} while (bg[x1][y1] != ' ');	//不覆盖🐍与边框
	bg[x1][y1] = '$';				//food
}
void Board::clear()
{
	for (int i = 1; i < H - 1; i++)
		for (int j = 1; j < W - 1; j++)
			bg[i][j] = ' ';
	bg[x1][y1] = '$';
}
Snake::Snake()
{
	snake.push_front(Node(1, 1));
	snake.push_front(Node(1, 2));
	snake.push_front(Node(1, 3));	
	snake.push_front(Node(1, 4));
	direction = 77;					//向右
}
bool Snake::judge_die()		//先走再判断
{
	//注意deque.front()或[]返回的为常引用类型 不可修改
	//先cover再judge 排除是吃到了的情况
	int x_head = snake.front().x;
	int y_head = snake.front().y;
	if ((x_head == 0 || x_head == H - 1 || y_head == 0 || y_head == W - 1 || bg[x_head][y_head] == '*') && !judge_eat())
		return 1;
	else return 0;
}
bool Snake::judge_eat()
{
	return (snake[0].x == x1 && snake[0].y == y1);
}
void Snake::Node_Cover()
{
	//队列中储存的Node实际上是蛇的坐标 然后要让蛇的坐标覆盖原始背景版再打印
	bg[snake[0].x][snake[0].y] = snake[0].Head;
	for(int i=1;i<snake.size();i++)
		bg[snake[i].x][snake[i].y] = snake[i].Body;
}
void Snake::move()
{
	clock_t time_start, time_over;
	time_start = clock();		//记录当前的时间
	while ((time_over = (clock() - time_start <= gamespeed)) && !_kbhit());		//_kbhit()在ctime库 来检查有无输入 无输入返回0
	//卡gamespeed 等时间从0到gamespeed（毫秒） 再执行下面
	//实现刷新：https://blog.csdn.net/wangxun20081008/article/details/115594058
	//什么时候变不变direction：方向没有变时temp=direction  还有方向转了一百八十度时
	if (time_over) {
		char c1 = _getch();
		char temp = _getch();
		int op[4] = { 72,75,80,77 };	//up left down right
		for (int i = 0; i < 4; i++)
			if ((int)temp == op[i] && direction != op[(i + 2) % 4])
			{
				direction = (int)temp; break;
			}
	}
	int x_head = snake.front().x;
	int y_head = snake.front().y;
	switch (direction)
	{
	case 72: snake.push_front(Node(x_head - 1, y_head));  	break;	//up
	case 80: snake.push_front(Node(x_head + 1, y_head));    break;	//down
	case 75: snake.push_front(Node(x_head, y_head - 1));    break;	//left
	case 77: snake.push_front(Node(x_head, y_head + 1));    break;	//right
	}
	if (judge_die())
		return ;
	if (judge_eat())	//吃了-刷新 没吃-去尾
	{
		food(); 
		count++;
	}
	else
		snake.pop_back();
	//吃了后 先加尾再移动？ 先加在尾部的话可能会覆盖 该处实现没问题
	//先移动再加尾 这样子无法判断原来的尾巴的位置 不行
	//记得刷新吃
	//if (judge_eat())
	//{
	//	int x_back = snake.back().x;
	//	int y_back = snake.back().y;
	//	switch (direction)
	//	{
	//	case 72: snake.push_back(Node(x_back + 1, y_back));	 break;	//up
	//	case 80: snake.push_back(Node(x_back - 1, y_back));	 break;	//down
	//	case 75: snake.push_back(Node(x_back, y_back + 1));	 break;	//left
	//	case 77: snake.push_back(Node(x_back, y_back - 1));	 break;	//right
	//	}
	//	food();
	//}
}
void Game_Start()
{
	Snake s;
	while (1)
	{
		s.Speed_control();
		s.move();
		if (s.judge_die())
			break;
		s.clear();
		s.Node_Cover();
		s.Prt();
	}
	std::cout << "Game Over!" << std::endl;

	return ;
}
