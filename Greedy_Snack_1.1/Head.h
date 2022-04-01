#pragma once
#include<deque>
#include<ctime>
#define H 22		//Height
#define W 22		//Width

class Board
{
public:
	char bg[H][W];
	Board();			//初始化background bg
	void Prt();			//输出当前全局状态
	void food();		//随机生成food
	void clear();		//清除蛇上一个状态 即在deque——snake中已经出队了但是覆盖了背景的元素
	void Speed_control();//控制蛇的速度以及等级
protected:
	int x1, y1;			//food的坐标 （x是竖着的）
	int gamespeed = 1000;			//蛇的速度
	static int count;
};

class Snake :public Board
{
public:
	typedef struct Node{
		int x, y;
		const char Body = '*';		
		const char Head = '@';		
		Node():x(0),y(0){}
		Node(int _x,int _y):x(_x),y(_y){}
	}Node;

	Snake();
	std::deque<Snake::Node> snake;	
	void Node_Cover();				//覆盖bg	
	bool judge_die();				
	bool judge_eat();				
	void move();		
protected:
	int direction;					//储存方向
};

void Game_Start();				//conformity