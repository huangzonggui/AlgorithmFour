//��Ŀ���й������������߷������ݷ���
//������������4��5����������֪������ʼ����(x,y)�������ܹ����ص���ʼλ�õĲ��ظ������в�ͬ�߷���������

//���������
//��1��������������ʼλ�ã����кϷ����жϣ�
//��2��������ʼλ�ÿ�ʼ���������������������ѣ��ۼ�������
//��3������������

#include <stdio.h>
#include <stdlib.h>
int array[2][8]={{-1,-1,-2,-2,2,2,1,1},{-2,2,1,-1,1,-1,2,-2}};//��ʾ������8������
int chess[4][5];//��ʾ���̣�1����ʾ�Ѿ��ڽ����ʱ���߹���0����û��
int total=0;//ͳ���߷��ĸ���
int sx,sy;//(sx,sy)��ʾ������ʼ����

void find_way(int p1,int p2);//���ݵĹ���
void main()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for (j=0;j<5;j++)
		{
			chess[i][j]=0;
		}
	}
	printf("����������ʼ���꣺\n");
	scanf("%d",&sx);
	scanf("%d",&sy);
	printf("sx=%d,sy=%d\n",sx,sy);
	if ((sx<0)||(sx>=4)||(sy<0)||(sy>=5))
	{
		printf("ERROR\n");
	}else{
		chess[sx][sy]=1;
		find_way(sx,sy);//����ʼλ�ÿ�ʼ��̽
		printf("total=%d\n",total);
		getchar();
	}
	system("PAUSE");
}

void find_way(int p1,int p2){
	int i,pi,pj;
	//��8��������̽
	for(i=0;i<8;i++){
		pi=p1+array[0][i];
		pj=p2+array[1][i];
		if((sx==pi)&&(sy==pj)){
			total++;//�ҵ�һ���߷�����sx,sy����ʾ���
		}else if((pi>=0)&&(pi<4)&&(pj>=0)&&(pj<5)&&(chess[pi][pj]==0)){//������̽
			chess[pi][pj]=1;
			find_way(pi,pj);
			chess[pi][pj]=0;
		}
	}
}