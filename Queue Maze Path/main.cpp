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

//�������� ť�� �����س��ٰ� ���� ������ ������� ���ư��� ���ο� ��� Ž������->�ݺ�

int main()
{
	//stack<Vector> History;
	queue<Vector> HistoryB;
	int Count = 0;


	Vector PathPosition(1, 2);
	int Value = -1;

	//History.push(PlayerPosition);
	MAP[PathPosition.Y][PathPosition.X] = Value;

	while (true)
	{
		//���� ����
		if (PathPosition.X == 1 && PathPosition.Y == 8)
		{
			for (int Y = 0; Y < 10; ++Y)
			{
				for (int X = 0; X < 10; ++X)
				{
					cout << MAP[Y][X] << "      ";
				}
				cout << endl;
			}
			break;
		}

		//�����ʿ� ���� �ֳ�?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == 0)
		{
			++Count;
		}
		//�Ʒ��ʿ� ���� �ֳ�?
		if (MAP[PathPosition.Y + 1][PathPosition.X] == 0)
		{
			++Count;
		}
		//���� ���� �ֳ�?
		if (MAP[PathPosition.Y][PathPosition.X - 1] == 0)
		{
			++Count;
		}
		//���� ���� �ֳ�?
		if (MAP[PathPosition.Y - 1][PathPosition.X] == 0)
		{
			++Count;
		}



		if (Count > 1)
		{
			HistoryB.push(PathPosition);
		}


		//�����ʿ� ���� �ֳ�?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == 0)
		{
			MAP[PathPosition.Y][PathPosition.X + 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.X++;
		}
		//�Ʒ��ʿ� ���� �ֳ�?
		else if (MAP[PathPosition.Y + 1][PathPosition.X] == 0)
		{
			MAP[PathPosition.Y + 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.Y++;

		}
		//���� ���� �ֳ�?
		else if (MAP[PathPosition.Y][PathPosition.X - 1] == 0)
		{
			MAP[PathPosition.Y][PathPosition.X - 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.X--;
		}
		//���� ���� �ֳ�?
		else if (MAP[PathPosition.Y - 1][PathPosition.X] == 0)
		{
			MAP[PathPosition.Y - 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.Y--;
		}
		else
		{

			//���ư��� ������ Ż�� �Ұ�
			if (HistoryB.empty())
			{
				cout << "No Escape!!" << endl;
				break;
			}

			//���ο� ���� ������ ������� ���ư���
			PathPosition.X = HistoryB.front().X;
			PathPosition.Y = HistoryB.front().Y;
			HistoryB.pop();

		}

		//ī��Ʈ �ʱ�ȭ
		Count = 0;



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


	//Ż�� ������ �Դ��� �ǵ��ư��鼭 ������� Ž��

	stack<Vector> PathStack;
	int PathValue = MAP[PathPosition.Y][PathPosition.X];

	PathStack.push(PathPosition);

	while (MAP[PathPosition.Y][PathPosition.X] != -1)
	{

		++PathValue;

		//�����ʿ� ���� �ֳ�?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == PathValue)
		{

			PathPosition.X++;
			PathStack.push(PathPosition);
		}
		//�Ʒ��ʿ� ���� �ֳ�?
		else if (MAP[PathPosition.Y + 1][PathPosition.X] == PathValue)
		{

			PathPosition.Y++;
			PathStack.push(PathPosition);

		}
		//���� ���� �ֳ�?
		else if (MAP[PathPosition.Y][PathPosition.X - 1] == PathValue)
		{

			PathPosition.X--;
			PathStack.push(PathPosition);
		}
		//���� ���� �ֳ�?
		else if (MAP[PathPosition.Y - 1][PathPosition.X] == PathValue)
		{

			PathPosition.Y--;
			PathStack.push(PathPosition);
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



