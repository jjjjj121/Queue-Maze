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

//추가 Queue를 이용한 경로탐색 방법
//탐색해서 길 있으면 무작위로 그냥 한번씩 다 가보기 -> 가본곳에서 추가로 길이 있으면 계속 큐에 추가해서 언젠가 그곳탐색하러감.

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

		//오른쪽에 길이 있냐?
		if (MAP[PathPosition.Y][PathPosition.X + 1] == 0 && Running == true)
		{

			MAP[PathPosition.Y][PathPosition.X + 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X + 1;
			SearchPosition.Y = PathPosition.Y;

			Que.push(SearchPosition);

			//종료 조건
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}

		}
		//아래쪽에 길이 있냐?
		if (MAP[PathPosition.Y + 1][PathPosition.X] == 0 && Running == true)
		{
			MAP[PathPosition.Y + 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X;
			SearchPosition.Y = PathPosition.Y + 1;

			Que.push(SearchPosition);

			//종료 조건
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}
		}
		//왼쪽 길이 있냐?
		if (MAP[PathPosition.Y][PathPosition.X - 1] == 0 && Running == true)
		{
			MAP[PathPosition.Y][PathPosition.X - 1] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X - 1;
			SearchPosition.Y = PathPosition.Y;

			Que.push(SearchPosition);

			//종료 조건
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}
		}
		//위쪽 길이 있냐?
		if (MAP[PathPosition.Y - 1][PathPosition.X] == 0 && Running == true)
		{
			MAP[PathPosition.Y - 1][PathPosition.X] = MAP[PathPosition.Y][PathPosition.X] - 1;
			SearchPosition.X = PathPosition.X;
			SearchPosition.Y = PathPosition.Y - 1;

			Que.push(SearchPosition);

			//종료 조건
			if (SearchPosition.X == EndPosition.X && SearchPosition.Y == EndPosition.Y)
			{
				Running = false;
			}


		}

		//Queue에 탐색할 길이 존재하면(아직 안가본곳이 존재함)
		if (Que.empty() == false)
		{
			Que.pop();
			//MAP[PathPosition.Y][PathPosition.X] = VISITED;

			PathPosition.X = Que.front().X;
			PathPosition.Y = Que.front().Y;
			
		}
		//아니면 종료조건에도 안맞고, 다가봤는데 없으므로, 탈출구 없음.
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

	//탈출 했으면 왔던길 되돌아가면서 최적경로 탐색

	stack<Vector> PathStack;
	
	int PathValue = MAP[SearchPosition.Y][SearchPosition.X];

	PathStack.push(SearchPosition);

	while (MAP[SearchPosition.Y][SearchPosition.X] != -1)
	{

		++PathValue;

		//오른쪽에 길이 있냐?
		if (MAP[SearchPosition.Y][SearchPosition.X + 1] == PathValue)
		{
		
			SearchPosition.X++;
			PathStack.push(SearchPosition);
		}
		//아래쪽에 길이 있냐?
		else if (MAP[SearchPosition.Y + 1][SearchPosition.X] == PathValue)
		{
			
			SearchPosition.Y++;
			PathStack.push(SearchPosition);

		}
		//왼쪽 길이 있냐?
		else if (MAP[SearchPosition.Y][SearchPosition.X - 1] == PathValue)
		{
			
			SearchPosition.X--;
			PathStack.push(SearchPosition);
		}
		//위쪽 길이 있냐?
		else if (MAP[SearchPosition.Y - 1][SearchPosition.X] == PathValue)
		{
			
			SearchPosition.Y--;
			PathStack.push(SearchPosition);
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
