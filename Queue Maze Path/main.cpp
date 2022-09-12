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

//갈림길을 큐에 저장해놨다가 길이 막히면 갈림길로 돌아가서 새로운 길로 탐색시작->반복

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
		//종료 조건
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

		//오른쪽에 길이 있냐?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == 0)
		{
			++Count;
		}
		//아래쪽에 길이 있냐?
		if (MAP[PathPosition.Y + 1][PathPosition.X] == 0)
		{
			++Count;
		}
		//왼쪽 길이 있냐?
		if (MAP[PathPosition.Y][PathPosition.X - 1] == 0)
		{
			++Count;
		}
		//위쪽 길이 있냐?
		if (MAP[PathPosition.Y - 1][PathPosition.X] == 0)
		{
			++Count;
		}



		if (Count > 1)
		{
			HistoryB.push(PathPosition);
		}


		//오른쪽에 길이 있냐?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == 0)
		{
			MAP[PathPosition.Y][PathPosition.X + 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.X++;
		}
		//아래쪽에 길이 있냐?
		else if (MAP[PathPosition.Y + 1][PathPosition.X] == 0)
		{
			MAP[PathPosition.Y + 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.Y++;

		}
		//왼쪽 길이 있냐?
		else if (MAP[PathPosition.Y][PathPosition.X - 1] == 0)
		{
			MAP[PathPosition.Y][PathPosition.X - 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.X--;
		}
		//위쪽 길이 있냐?
		else if (MAP[PathPosition.Y - 1][PathPosition.X] == 0)
		{
			MAP[PathPosition.Y - 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			PathPosition.Y--;
		}
		else
		{

			//돌아가길 없으면 탈출 불가
			if (HistoryB.empty())
			{
				cout << "No Escape!!" << endl;
				break;
			}

			//새로운 길이 없으면 갈림길로 돌아가라
			PathPosition.X = HistoryB.front().X;
			PathPosition.Y = HistoryB.front().Y;
			HistoryB.pop();

		}

		//카운트 초기화
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


	//탈출 했으면 왔던길 되돌아가면서 최적경로 탐색

	stack<Vector> PathStack;
	int PathValue = MAP[PathPosition.Y][PathPosition.X];

	PathStack.push(PathPosition);

	while (MAP[PathPosition.Y][PathPosition.X] != -1)
	{

		++PathValue;

		//오른쪽에 길이 있냐?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == PathValue)
		{

			PathPosition.X++;
			PathStack.push(PathPosition);
		}
		//아래쪽에 길이 있냐?
		else if (MAP[PathPosition.Y + 1][PathPosition.X] == PathValue)
		{

			PathPosition.Y++;
			PathStack.push(PathPosition);

		}
		//왼쪽 길이 있냐?
		else if (MAP[PathPosition.Y][PathPosition.X - 1] == PathValue)
		{

			PathPosition.X--;
			PathStack.push(PathPosition);
		}
		//위쪽 길이 있냐?
		else if (MAP[PathPosition.Y - 1][PathPosition.X] == PathValue)
		{

			PathPosition.Y--;
			PathStack.push(PathPosition);
		}

	}

	cout << "Maze 최적 경로" << endl;
	while (!PathStack.empty())
	{
		cout << PathStack.top().X << "," << PathStack.top().Y << endl;
		PathStack.pop();

	}


	return 0;
}



