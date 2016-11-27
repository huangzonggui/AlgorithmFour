//题目：中国象棋中马的走法（回溯法）
//问题描述：在4×5的棋盘上已知马的起始坐标(x,y)，求马能够返回到起始位置的不重复的所有不同走法的总数。

//问题分析：
//（1）、读入马的起始位置，进行合法性判断；
//（2）、从起始位置开始搜索，搜索方法采用深搜，累计总数；
//（3）、输出结果。

#include <stdio.h>
#include <stdlib.h>
int array[2][8]={{-1,-1,-2,-2,2,2,1,1},{-2,2,1,-1,1,-1,2,-2}};//表示马跳的8个方向：(-1,-2),(-1,2),(-2,1),(-2,-1),(2,1),(2,-1),(1,2),(1,-2)
// 其中1,-1,2,-2表示向哪个方向移动多少个位置

int chess[4][5];//表示棋盘，1：表示已经在较早的时候走过，0：则没有
int total=0;//统计走法的个数
int sx,sy;//(sx,sy)表示马的起始坐标

void find_way(int p1,int p2);//回溯的过程
void main(){
	int i,j;
	for(i=0;i<4;i++)	{
		for (j=0;j<5;j++)		{
			chess[i][j]=0;
		}
	}
	printf("输入马的起始坐标：\n");
	scanf("%d",&sx);
	scanf("%d",&sy);
	printf("sx=%d,sy=%d\n",sx,sy);
	if ((sx<0)||(sx>=4)||(sy<0)||(sy>=5)){
		printf("ERROR\n");
	}else{
		chess[sx][sy]=1;
		find_way(sx,sy);//从起始位置开始试探
		printf("total=%d\n",total);
	}
	system("PAUSE");
}

void find_way(int p1,int p2){
	int i,pi,pj;
	//向8个方向试探
	for(i=0;i<8;i++){
		pi=p1+array[0][i];//横坐标移动|i|个单位，方向看正负号
		pj=p2+array[1][i];//纵坐标移动|j|个单位，方向看正负号

		if((sx==pi)&&(sy==pj)){
			total++;//找到一种走法回到原来的位置，（sx,sy）表示起点
		}else if((pi>=0)&&(pi<4)&&(pj>=0)&&(pj<5)&&(chess[pi][pj]==0)){//如果坐标合法而且不回头（chess[pi][pj]=1表示这一种走法的脚印），继续试探
			//走到标志为1
			chess[pi][pj]=1;
			find_way(pi,pj);
			//回溯后
			chess[pi][pj]=0;
		}
	}
}