/* Greedy Snake      version 1.1*/
/*       written by Xxxxic      */
/* ����̨ˢ�� ���Լ��ƶ���ʵ��    */
/* ʵ���ߵ��ٶ� �Լ��÷ֵļ�¼    */
/* ��װ���úܲ�					*/	
/* ˢ�µķ�ʽ�����ŵ���ʾ ��ը��	*/

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