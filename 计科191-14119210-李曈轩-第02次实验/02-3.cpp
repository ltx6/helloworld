#include <iostream> 
using namespace std;
int count = 0;
int chess[8][8]={0};

int notDanger( int row, int col )
{
	int i,k;
	// �ж��з���
	for( i=0; i < 8; i++ )
	{
		if( chess[i][col]==1 )
		{
			return 0;
		}
	}
	// �ж���Խ��� 
	for( i=row, k=col; i>=0 && k>=0; i--, k-- )
	{
		if(chess[i][k]==1  )
		{
			return 0;
		}
	}
	// �ж��ҶԽ��� 
	for( i=row, k=col; i>=0 && k<8; i--, k++ )
	{
		if(chess[i][k]==1  )
		{
			return 0;
		}
	}
	return 1;
}

void Print()          //��ӡ��� 
{
	int row,col;
	printf("�� %d ��\n", count+1);
		for( row=0; row < 8; row++ )
		{
			for( col=0; col< 8; col++ )
			{
				if(chess[row][col]==1)        //�ʺ��á�0����ʾ
				{
					printf("0 ");
				}
				else
				{
					printf("# ");
				}
			}
			printf("\n");
		}
		printf("\n");
}

void EightQueen( int row )
{
	int col;
	if( row>7 )                       //�����������ж��ҵ����ûʺ��λ�����ӡ
	{
		Print();                       //��ӡ�˻ʺ�Ľ� 
		count++;
		return ;
		
	}

	for( col=0; col < 8; col++ )        //���ݣ��ݹ�
	{
		if( notDanger( row, col ) )    // �ж��Ƿ�Σ��
		{
			chess[row][col]=1;
			EightQueen(row+1);
			
			chess[row][col]=0;           //���㣬�������ʱ����������
		}
	}
}

int main()
{
	EightQueen(0);        
	printf("�ܹ��� %d �ֽ������!\n\n", count);
	return 0;
}
