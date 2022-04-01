/* Greedy Snake      version 1.1*/
/*       written by Xxxxic      */
/* 控制台刷新 吃以及移动的实现    */
/* 实现蛇的速度 以及得分的记录    */
/* 封装做得很差					*/	
/* 刷新的方式、符号的显示 丑炸了	*/

#include<iostream>
#include<windows.h>
#include"Head.h"
using namespace std;


int main()
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

	return 0;
}