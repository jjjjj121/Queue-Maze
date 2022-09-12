#include <iostream>
#include <stack>
#include <conio.h>
#include <queue>

using namespace std;

//Right, Down, Left, Up
int MAP[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

class Vector
{
public:
	int X;
	int Y;


public:
	Vector()
	{
		X = 0;
		Y = 0;
	}
	Vector(int NewX, int NewY)
	{
		X = NewX;
		Y = NewY;
	}
	~Vector() {}

};

//�߰� Queue�� �̿��� ���Ž�� ���
//Ž���ؼ� �� ������ �������� �׳� �ѹ��� �� ������ -> ���������� �߰��� ���� ������ ��� ť�� �߰��ؼ� ������ �װ�Ž���Ϸ���.

int main()
{
	//stack<Vector> History;
	queue<Vector> Que;

	Vector PathPosition(1, 2);
	Vector SearchPosition(0,0);
	Vector EndPosition(1, 8);
	int Value = -1;

	bool Running = true;

	//History.push(PlayerPosition);
	Que.push(PathPosition);

	MAP[PathPosition.Y][PathPosition.X] = Value;
	
	while (Running)
	{

		//�����ʿ� ���� �ֳ�?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == 0 && Running == true)
		{

			MAP[PathPosition.Y][PathPosition.X + 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X + 1;
			SearchPosition.Y = PathPosition.Y;

			Que.push(SearchPosition);

			//���� ����
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}

		}
		//�Ʒ��ʿ� ���� �ֳ�?
		if (MAP[PathPosition.Y + 1][PathPosition.X] == 0 && Running == true)
		{
			MAP[PathPosition.Y + 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X;
			SearchPosition.Y = PathPosition.Y + 1;

			Que.push(SearchPosition);

			//���� ����
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}
		}
		//���� ���� �ֳ�?
		if (MAP[PathPosition.Y][PathPosition.X - 1] == 0 && Running == true)
		{
			MAP[PathPosition.Y][PathPosition.X - 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X - 1;
			SearchPosition.Y = PathPosition.Y;

			Que.push(SearchPosition);

			//���� ����
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}
		}
		//���� ���� �ֳ�?
		if (MAP[PathPosition.Y - 1][PathPosition.X] == 0 && Running == true)
		{
			MAP[PathPosition.Y - 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X;
			SearchPosition.Y = PathPosition.Y - 1;

			Que.push(SearchPosition);

			//���� ����
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}


		}

		//Queue�� Ž���� ���� �����ϸ�(���� �Ȱ������� ������)
		if (Que.empty() == false)
		{
			Que.pop();
			//MAP[PathPosition.Y][PathPosition.X] = VISITED;

			PathPosition.X = Que.front().X;
			PathPosition.Y = Que.front().Y;
			
		}
		//�ƴϸ� �������ǿ��� �ȸ°�, �ٰ��ôµ� �����Ƿ�, Ż�ⱸ ����.
		else
		{
			cout << "No Escape!!" << endl;
			break;
		}


		for (int Y = 0; Y < 10; ++Y)
		{
			for (int X = 0; X < 10; ++X)
			{
				cout << MAP[Y][X] << "     ";
			}
			cout << endl;
		}

		_getch();

	}



	cout << SearchPosition.X << SearchPosition.Y << endl;

	//Ż�� ������ �Դ��� �ǵ��ư��鼭 ������� Ž��

	stack<Vector> PathStack;
	
	int PathValue = MAP[SearchPosition.Y][SearchPosition.X];

	PathStack.push(SearchPosition);

	while (MAP[SearchPosition.Y][SearchPosition.X] != -1)
	{

		++PathValue;

		//�����ʿ� ���� �ֳ�?
		if (MAP[SearchPosition.Y][SearchPosition.X + 1] == PathValue)
		{
		
			SearchPosition.X++;
			PathStack.push(SearchPosition);
		}
		//�Ʒ��ʿ� ���� �ֳ�?
		else if (MAP[SearchPosition.Y + 1][SearchPosition.X] == PathValue)
		{
			
			SearchPosition.Y++;
			PathStack.push(SearchPosition);

		}
		//���� ���� �ֳ�?
		else if (MAP[SearchPosition.Y][SearchPosition.X - 1] == PathValue)
		{
			
			SearchPosition.X--;
			PathStack.push(SearchPosition);
		}
		//���� ���� �ֳ�?
		else if (MAP[SearchPosition.Y - 1][SearchPosition.X] == PathValue)
		{
			
			SearchPosition.Y--;
			PathStack.push(SearchPosition);
		}

	}

	cout << "Maze ���� ���" << endl;
	while (!PathStack.empty())
	{
		cout << PathStack.top().X << "," << PathStack.top().Y << endl;
		PathStack.pop();




	}






	return 0;
}
