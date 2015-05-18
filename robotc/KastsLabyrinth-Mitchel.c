#pragma config(Sensor, S2,     LeftColor,      sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S1,     RightColor,     sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S3,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S4,     Touch,          sensorEV3_Touch)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)

#define RIGHT 3
#define LEFT 4
#define UP 1
#define DOWN 2

struct road
{
	bool used;
	int cityAX, cityAY, cityBX, cityBY;
	int distance;
};

struct square
{
	road up, down, right, left;

	int x, y;
};

struct directions
{
	bool left;
	bool right;
	bool up;
	bool down;

	int locationx, locationy;

	directions* next;

	bool used;
};

struct lastCity
{
	lastCity * forward;
	lastCity * backward;
	int x;
	int y;

	bool used;
};

void FollowDirections();
void randomDestination();

//directions directionList[50];
lastCity from[5][7];
bool include[5][7];
int distanceArray[5][7];
square board[5][7];
int directionArray[50];
int up, down, left, right;
bool red[5][7];
bool moves[4];
bool visited[5][7];
int curX, curY;
int finX, finY;
int directionCounter;
int lastDirection;


void Sandstor()
{
  //        125 = Tempo
  //          5 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   22); wait1Msec( 240);  // Note(E, Duration(Eighth))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   22); wait1Msec( 240);  // Note(E, Duration(Eighth))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   22); wait1Msec( 240);  // Note(A, Duration(Eighth))
  PlayTone(  783,   11); wait1Msec( 120);  // Note(G, Duration(16th))
  PlayTone(  783,   11); wait1Msec( 120);  // Note(G, Duration(16th))
  PlayTone(  783,   11); wait1Msec( 120);  // Note(G, Duration(16th))
  PlayTone(  783,   11); wait1Msec( 120);  // Note(G, Duration(16th))
  PlayTone(  783,   11); wait1Msec( 120);  // Note(G, Duration(16th))
  PlayTone(  783,   11); wait1Msec( 120);  // Note(G, Duration(16th))
  PlayTone(  783,   22); wait1Msec( 240);  // Note(G, Duration(Eighth))
  PlayTone(  587,   11); wait1Msec( 120);  // Note(D, Duration(16th))
  PlayTone(  587,   11); wait1Msec( 120);  // Note(D, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   22); wait1Msec( 240);  // Note(E, Duration(Eighth))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   22); wait1Msec( 240);  // Note(E, Duration(Eighth))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 120);  // Note(A, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   22); wait1Msec( 240);  // Note(E, Duration(Eighth))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   11); wait1Msec( 120);  // Note(E, Duration(16th))
  PlayTone(  659,   22); wait1Msec( 240);  // Note(E, Duration(Eighth))
  return;
}

void CloseEnc()
{
  //        125 = Tempo
  //          6 = Default octave
  //     Eighth = Default note length
  //        10% = Break between notes
  //
  PlayTone( 1175,   86); wait1Msec( 960);  // Note(G, Duration(Quarter))
  PlayTone( 1320,   86); wait1Msec( 960);  // Note(A, Duration(Quarter))
  PlayTone( 1047,   86); wait1Msec( 960);  // Note(F, Duration(Quarter))
  PlayTone(  698,   86); wait1Msec( 960);  // Note(F5, Duration(Quarter))
  PlayTone(  784,  173); wait1Msec(1920);  // Note(C, Duration(Half))
  //PlayTone(    0,  346); wait1Msec(3840);  // Note(Rest, Duration(Whole))
  return;
}

void TheGreat()
{
  //        120 = Tempo
  //          5 = Default octave
  //    Quarter = Default note length
  //        10% = Break between notes
  //
  PlayTone(  698,   11); wait1Msec( 125);  // Note(F, Duration(16th))
  wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  932,   23); wait1Msec( 250);  // Note(A#, Duration(Eighth))
   wait1Msec( 500);  // Note(Rest)
   wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  698,   11); wait1Msec( 125);  // Note(F, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  880,   34); wait1Msec( 375);  // Note(D6, Duration(Eighth .))
  PlayTone(  784,   11); wait1Msec( 125);  // Note(C6, Duration(16th))
  PlayTone(  932,   11); wait1Msec( 125);  // Note(A#, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  783,   45); wait1Msec( 500);  // Note(G)
   wait1Msec(1000);  // Note(Rest, Duration(Half))
  wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  784,   11); wait1Msec( 125);  // Note(C6, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  784,   23); wait1Msec( 250);  // Note(C6, Duration(Eighth))
   wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  932,   11); wait1Msec( 125);  // Note(A#, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  880,   34); wait1Msec( 375);  // Note(A, Duration(Eighth .))
  PlayTone(  932,   11); wait1Msec( 125);  // Note(A#, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 125);  // Note(A, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  783,   23); wait1Msec( 250);  // Note(G, Duration(Eighth))
  PlayTone(  698,   11); wait1Msec( 125);  // Note(F, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  587,   23); wait1Msec( 250);  // Note(D, Duration(Eighth))
   wait1Msec( 500);  // Note(Rest)
   wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  587,   11); wait1Msec( 125);  // Note(D, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  622,   23); wait1Msec( 250);  // Note(D#, Duration(Eighth))
  PlayTone(  659,   23); wait1Msec( 250);  // Note(E, Duration(Eighth))
  PlayTone(  698,   11); wait1Msec( 125);  // Note(F, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  932,   23); wait1Msec( 250);  // Note(A#, Duration(Eighth))
   wait1Msec( 500);  // Note(Rest)
   wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  698,   11); wait1Msec( 125);  // Note(F, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  880,   34); wait1Msec( 375);  // Note(D6, Duration(Eighth .))
  PlayTone(  784,   11); wait1Msec( 125);  // Note(C6, Duration(16th))
  PlayTone(  932,   11); wait1Msec( 125);  // Note(A#, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  783,   23); wait1Msec( 250);  // Note(G, Duration(Eighth))
   wait1Msec(1000);  // Note(Rest, Duration(Half))
   wait1Msec( 500);  // Note(Rest)
  PlayTone(  784,   11); wait1Msec( 125);  // Note(C6, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  784,   23); wait1Msec( 250);  // Note(C6, Duration(Eighth))
   wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  932,   11); wait1Msec( 125);  // Note(A#, Duration(16th))
  wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  880,   11); wait1Msec( 125);  // Note(A, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  698,   23); wait1Msec( 250);  // Note(F, Duration(Eighth))
   wait1Msec( 250);  // Note(Rest, Duration(Eighth))
  PlayTone(  784,   11); wait1Msec( 125);  // Note(C6, Duration(16th))
   wait1Msec( 125);  // Note(Rest, Duration(16th))
  PlayTone(  932,   45); wait1Msec( 500);  // Note(A#)
  return;
}



void resetDirections()
{
	for (int i = 0; i < 50; i++)
	{
		directionArray[i] = 99;
	}
}

void removeDownRoad()
{
	displayTextLine(5,"road from %d,%d to %d, %d no longer exists!", curX, curY, curX-1, curY);
	sleep(1000);
	board[curX][curY].down.cityBX = curX;
	board[curX][curY].down.cityBY = curY;
	board[curX][curY].down.distance = 99999;

	board[curX+1][curY].up.cityBX = curX + 1;
	board[curX+1][curY].up.cityBY = curY;
	board[curX+1][curY].up.distance = 99999;
}

void removeLeftRoad()
{
	board[curX][curY].left.cityBX = curX;
	board[curX][curY].left.cityBY = curY;
	board[curX][curY].left.distance = 99999;

	board[curX][curY-1].right.cityBX = curX;
	board[curX][curY-1].right.cityBY = curY - 1;
	board[curX][curY-1].right.distance = 99999;
}

void removeUpRoad()
{
	board[curX][curY].up.cityBX = curX;
	board[curX][curY].up.cityBY = curY;
	board[curX][curY].up.distance = 99999;

	board[curX-1][curY].down.cityBX = curX;
	board[curX-1][curY].down.cityBY = curY-1;
	board[curX-1][curY].down.distance = 99999;
}

void removeRightRoad()
{
	displayTextLine(7, "%d,%d", board[curX][curY].right.cityBX, board[curX][curY].right.cityBY);
	sleep(2000);
	board[curX][curY].right.cityBX = curX;
	board[curX][curY].right.cityBY = curY;
	board[curX][curY].right.distance = 99999;
	displayTextLine(5, "%d,%d road right now leads", curX, curY);
	displayTextLine(6," to %d,%d, curX, curY", 	board[curX][curY].right.cityBX, 	board[curX][curY].right.cityBY);

	board[curX][curY+1].left.cityBX = curX;
	board[curX][curY+1].left.cityBY = curY+1;
	board[curX][curY+1].left.distance = 99999;
}


void TurnRight()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	int CurGyro = SensorValue[Gyro] + 84;
	setMotorSpeed(LeftTire, 25);
	setMotorSpeed(RightTire, -25);
	while(SensorValue[Gyro] < CurGyro)
	{
	}
	setMotorSpeed(LeftTire, 0);
	setMotorSpeed(RightTire, 0);
	sleep(100);
}

void TurnLeft()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	int CurGyro = SensorValue[Gyro] - 84;
	setMotorSpeed(LeftTire, -25);
	setMotorSpeed(RightTire, 25);
	while(SensorValue[Gyro] > CurGyro)
	{
	}
	setMotorSpeed(LeftTire, 0);
	setMotorSpeed(RightTire, 0);
	sleep(100);
}

void FaceUp()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	if (lastDirection == DOWN)
	{
		TurnRight();
		TurnRight();
	}
	else if (lastDirection == RIGHT)
	{
		TurnLeft();
	}
	else if (lastDirection == LEFT)
	{
		TurnRight();
	}

	lastDirection = UP;
}

void FaceDown()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	if (lastDirection == UP)
	{
		TurnRight();
		TurnRight();
	}
	else if (lastDirection == LEFT)
	{
		TurnLeft();
	}
	else if (lastDirection == RIGHT)
	{
		TurnRight();
	}

	lastDirection = DOWN;
}

void FaceRight()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	if (lastDirection == UP)
	{
		TurnRight();

	}
	else if (lastDirection == DOWN)
	{
		TurnLeft();
	}
	else if (lastDirection == LEFT)
	{
		TurnRight();
		TurnRight();
	}

	lastDirection = RIGHT;
}

void FaceLeft()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	if (lastDirection == DOWN)
	{
		TurnRight();

	}
	else if (lastDirection == UP)
	{
		TurnLeft();
	}
	else if (lastDirection == RIGHT)
	{
		TurnRight();
		TurnRight();
	}

	lastDirection = LEFT;
}

void GoBack()
{
	setMotorSpeed(LeftTire, 0);
	setMotorSpeed(RightTire, 0);
	setMotorSyncEncoder(LeftTire,RightTire,0,200,-30);
	while(getMotorRunning(LeftTire))
	{

	}
	sleep(100);
}

bool DriveIn()
{
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
	setMotorSyncEncoder(LeftTire,RightTire,0,700,40);
	while(getMotorRunning(LeftTire))
	{
		if(getTouchValue(Touch) == 1)
		{
			GoBack();
			return false;
		}

		if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] > 2)
		{
			setMotorSpeed(RightTire, 0);
			setMotorSpeed(LeftTire, 0);
			setMotorSpeed(RightTire, 20);
			setMotorSpeed(LeftTire, -4);
			while(SensorValue[RightColor] > 10)
			{

			}
			setMotorSpeed(LeftTire, 0);
			setMotorSpeed(RightTire, 0);
		}
		else if(SensorValue[LeftColor] > 2 && SensorValue[RightColor] < 2)
		{
			setMotorSpeed(RightTire, 0);
			setMotorSpeed(LeftTire, 0);
			setMotorSpeed(LeftTire, 20);
			setMotorSpeed(RightTire, -4);
			while(SensorValue[LeftColor] > 2)
			{

			}
			setMotorSpeed(LeftTire, 0);
			setMotorSpeed(RightTire, 0);
		}
		else if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] < 2)
		{
			setMotorSpeed(RightTire, 0);
			setMotorSpeed(LeftTire, 0);
		}

	}
	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);
	setMotorSyncEncoder(LeftTire,RightTire,0,450,40);
	while(getMotorRunning(LeftTire))
	{
	}
	return true;
}










//reset function for arrays



void boardReset()
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			include[x][y] = false;
			distanceArray[x][y] = 99;
			from[x][y].x = -1;
			from[x][y].y = -1;
		}
	}
}


void Dijkstras(int x, int y, int fX, int fY)
{

	directions * KING = NULL;
	bool done = false;
	int lowest, newIncludex, newIncludey, oldIncludex, oldIncludey;
	int directionCounter;
	boardReset();
	distanceArray[x][y] = 0;
	include[x][y] = true;
	oldIncludex = x;
	oldIncludey = y;
	if (x == fX && y == fY)
	{
		return;
	}


	while (!done)
	{
		//cout << oldIncludex << " " << oldIncludey << endl;
		int test1 = board[oldIncludex][oldIncludey].up.cityBX;
		int test2 = board[oldIncludex][oldIncludey].up.cityBY;
		int test3 = board[oldIncludex][oldIncludey].down.cityBX;
		int test4 = board[oldIncludex][oldIncludey].down.cityBY;
		int test5 = board[oldIncludex][oldIncludey].left.cityBX;
		int test6 = board[oldIncludex][oldIncludey].left.cityBY;
		int test7 = board[oldIncludex][oldIncludey].right.cityBX;
		int test8 = board[oldIncludex][oldIncludey].right.cityBY;
		//cout << test1 << " " << test2 << " " << test3 << " " << test4 << " " << test5 << " " << test6 << " " << test7 << " " << test8 << endl;
		if (board[oldIncludex][oldIncludey].up.distance + distanceArray[oldIncludex][oldIncludey]
			< distanceArray[board[oldIncludex][oldIncludey].up.cityBX][board[oldIncludex][oldIncludey].up.cityBY])
		{
			distanceArray[board[oldIncludex][oldIncludey].up.cityBX][board[oldIncludex][oldIncludey].up.cityBY] = (board[oldIncludex][oldIncludey].up.distance + distanceArray[oldIncludex][oldIncludey]);

			from[board[oldIncludex][oldIncludey].up.cityBX][board[oldIncludex][oldIncludey].up.cityBY].x = oldIncludex;

			from[board[oldIncludex][oldIncludey].up.cityBX][board[oldIncludex][oldIncludey].up.cityBY].y = oldIncludey;
		}

		test1 = board[oldIncludex][oldIncludey].down.cityBX;
		test2 = board[oldIncludex][oldIncludey].down.cityBY;
		if (board[oldIncludex][oldIncludey].down.distance + distanceArray[oldIncludex][oldIncludey]
			< distanceArray[board[oldIncludex][oldIncludey].down.cityBX][board[oldIncludex][oldIncludey].down.cityBY])
		{
			distanceArray[board[oldIncludex][oldIncludey].down.cityBX][board[oldIncludex][oldIncludey].down.cityBY] = (board[oldIncludex][oldIncludey].down.distance + distanceArray[oldIncludex][oldIncludey]);

			from[board[oldIncludex][oldIncludey].down.cityBX][board[oldIncludex][oldIncludey].down.cityBY].x = oldIncludex;

			from[board[oldIncludex][oldIncludey].down.cityBX][board[oldIncludex][oldIncludey].down.cityBY].y = oldIncludey;
		}

		test1 = board[oldIncludex][oldIncludey].left.cityBX;
		test2 = board[oldIncludex][oldIncludey].left.cityBY;
		if (board[oldIncludex][oldIncludey].left.distance + distanceArray[oldIncludex][oldIncludey]
			< distanceArray[board[oldIncludex][oldIncludey].left.cityBX][board[oldIncludex][oldIncludey].left.cityBY])
		{
			distanceArray[board[oldIncludex][oldIncludey].left.cityBX][board[oldIncludex][oldIncludey].left.cityBY] = (board[oldIncludex][oldIncludey].left.distance + distanceArray[oldIncludex][oldIncludey]);

			from[board[oldIncludex][oldIncludey].left.cityBX][board[oldIncludex][oldIncludey].left.cityBY].x = oldIncludex;

			from[board[oldIncludex][oldIncludey].left.cityBX][board[oldIncludex][oldIncludey].left.cityBY].y = oldIncludey;
		}

		test1 = board[oldIncludex][oldIncludey].right.cityBX;
		test2 = board[oldIncludex][oldIncludey].right.cityBY;
		if (board[oldIncludex][oldIncludey].right.distance + distanceArray[oldIncludex][oldIncludey]
			< distanceArray[board[oldIncludex][oldIncludey].right.cityBX][board[oldIncludex][oldIncludey].right.cityBY])
		{
			distanceArray[board[oldIncludex][oldIncludey].right.cityBX][board[oldIncludex][oldIncludey].right.cityBY] = (board[oldIncludex][oldIncludey].right.distance + distanceArray[oldIncludex][oldIncludey]);

			from[board[oldIncludex][oldIncludey].right.cityBX][board[oldIncludex][oldIncludey].right.cityBY].x = oldIncludex;

			from[board[oldIncludex][oldIncludey].right.cityBX][board[oldIncludex][oldIncludey].right.cityBY].y = oldIncludey;
		}

		lowest = 99;
		newIncludex = 99;
		newIncludey = 99;
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 7; y++)
			{
				if (include[x][y] == false)
				{
					if (lowest > distanceArray[x][y])
					{
						lowest = distanceArray[x][y];
						newIncludex = x;
						newIncludey = y;
						//cout << newIncludex << endl;
						//cout << newIncludey << endl;

					}
				}
			}
		}

		if (lowest == 99)
		{
			//This means we couldn't add anything else aka the square we're trying to get to
			//isn't reachable... will put "55" into the array to signify this is a bad square.
			done = true;
			directionCounter = 0;
		  resetDirections();
			directionArray[directionCounter] = 55;
			return;
		}

		include[newIncludex][newIncludey] = true;
		//cout << "new include: " << newIncludex << "," << newIncludey << endl;
		oldIncludex = newIncludex;
		oldIncludey = newIncludey;

		if (newIncludex == fX && newIncludey == fY)
		{
			done = true;
			directionCounter = 0;
			while (from[newIncludex][newIncludey].x != -1)
			{
				if (newIncludey - from[newIncludex][newIncludey].y == 0)
				{
					if (newIncludex - from[newIncludex][newIncludey].x > 0)
					{
						//down
						directionArray[directionCounter] = DOWN;
					}
					else
						//up
						directionArray[directionCounter] = UP;
				}
				else if (newIncludey - from[newIncludex][newIncludey].y > 0)
				{
					//right
					directionArray[directionCounter] = RIGHT;
				}
				else
				{
					//left
					directionArray[directionCounter] = LEFT;
				}
				directionCounter++;
				int temp1, temp2;
				temp1 = from[newIncludex][newIncludey].x;
				temp2 = from[newIncludex][newIncludey].y;
				newIncludex = temp1;
				newIncludey = temp2;
			}
		}
	}


}

void checkForRed()
{
	if(SensorValue[LeftColor] == 5 && SensorValue[RightColor] == 5)
	{
		Sandstor();
		sleep(1000);
		finX = 0;
		finY = 0;
		resetDirections();
		Dijkstras(curX, curY, finX, finY);
		FollowDirections();
	}
}

void FollowDirections()
{
	directionCounter = 49;
	displayBigTextLine(1, "%d, %d, %d, %d, ", curX, curY, finX, finY);
	//cout << rand1 << "," << rand2 << " " << rand3 << "," << rand4 << endl;
	while (directionCounter >= 0)
	{
		displayBigTextLine(1, "%d, %d, %d, %d, ", curX, curY, finX, finY);
		if (directionArray[directionCounter] == DOWN)
		{
			//cout << " right ";
			displayBigTextLine (3, "Down");
			sleep(1000);
			//determine what was the last
			FaceDown();
			if (!DriveIn())
			{
				//right, so y+1 didn't work.
				//removeRoad(curX, curY, curX, curY+1);
				displayBigTextLine (3, "Oops");
				sleep(1000);
				removeDownRoad();
				//directionCounter = 0;
				resetDirections();
				Dijkstras(curX, curY, finX, finY);
				FollowDirections();
			}
			else
			{
				curX++;
				visited[curX][curY] = true;
				checkForRed();
			}
		}
		else if (directionArray[directionCounter] == UP)
		{
			//cout << " left ";
			displayBigTextLine(3, "Up");
			sleep(1000);
			FaceUp();
			if (!DriveIn())
			{
				//removeRoad(curX, curY, curX, curY-1)
				removeUpRoad();
				resetDirections();
				Dijkstras(curX, curY, finX, finY);
				FollowDirections();
			}
			else
			{

				curX--;
				visited[curX][curY] = true;
				checkForRed();

			}
		}
		else if (directionArray[directionCounter] == LEFT)
		{
			//cout << " up ";
			displayBigTextLine(3, "left");
			sleep(1000);
			FaceLeft();
			if (!DriveIn())
			{
				//removeRoad(curX, curY, curX-1, curY);
				removeLeftRoad();
				resetDirections();
				Dijkstras(curX, curY, finX, finY);
				FollowDirections();
				directionCounter = 0;
			}
			else
			{

				curY--;
				visited[curX][curY] = true;
				checkForRed();
			}
		}
		else if (directionArray[directionCounter] == RIGHT)
		{
			//cout << " down ";
			displayBigTextLine(3, "right To %d,%d", curX, curY+1);
			sleep(1000);
			FaceRight();
			if (!DriveIn())
			{
				//removeRoad(curX, curY, curX + 1, curY);
				removeRightRoad();
				resetDirections();
				Dijkstras(curX, curY, finX, finY);
				directionCounter = 0;
				FollowDirections();
				return;
			}
			else
			{

				curY++;
				visited[curX][curY] = true;
				checkForRed();
			}
		}

		else if (directionArray[directionCounter] == 55)
		{
			visited[finX][finY] = true;
		}
		else
		{
			//nothing
		}
		directionCounter--;
	}
	if ((curX == 0) && (curY == 0))
	{

	}
	else
	{
		randomDestination();
	}
}

void randomDestination()
{
	//CloseEnc();
	int rand1, rand2;

	bool done;
	done = true;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (visited[i][j] == false)
			{
				done = false;
			}
		}
	}
	if (!done)
	{
		rand1 = random(4);
		rand2 = random(6);
		while(visited[rand1][rand2])
		{
			rand1 = random(4);
			rand2 = random(6);
		}

		finX = rand1;
		finY = rand2;
		resetDirections();
		Dijkstras(curX, curY, finX, finY);
		FollowDirections();
	}
	else
	{
		resetDirections();
		Dijkstras(curx, curY, 0, 0)
		{
			FollowDirections();
		}
	}
}

task main()
{
	//TheGreat();
	int rand1, rand2, rand3, rand4;
	up = 0;
	down = 180;
	left = -90;
	right = 90;
	curX = 0;
	curY = 0;
	boardReset();
	sleep (3000);
	lastDirection = UP;
	visited[0][0] = true;
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			board[x][y].x = x;
			board[x][y].y = y;
			red[x][y] = false;
			visited[x][y] = false;

			board[x][y].up.cityAX = x;
			board[x][y].up.cityAY = y;
			board[x][y].up.cityBX = x;
			board[x][y].up.cityBY = y;
			board[x][y].up.distance = 1;

			board[x][y].down.cityAX = x;
			board[x][y].down.cityAY = y;
			board[x][y].down.cityBX = x;
			board[x][y].down.cityBY = y;
			board[x][y].down.distance = 1;

			board[x][y].left.cityAX = x;
			board[x][y].left.cityAY = y;
			board[x][y].left.cityBX = x;
			board[x][y].left.cityBY = y;
			board[x][y].left.distance = 1;

			board[x][y].right.cityAX = x;
			board[x][y].right.cityAY = y;
			board[x][y].right.cityBX = x;
			board[x][y].right.cityBY = y;
			board[x][y].right.distance = 1;
		}
	}

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 7; y++)
		{
			for (int i = 0; i < 4; i++)
			{
				moves[i] = true;
			}

			if (x == 0) //top
			{
				moves[0] = false;
			}
			else if (x == 4) //bottom
			{
				moves[1] = false;
			}
			if (y == 0) //left
			{
				moves[2] = false;
			}
			else if (y == 6) //right
			{
				moves[3] = false;
			}


			if (moves[0] == false)
			{
				//on the top
				if (moves[2] == false)
				{
					//top left


					board[x][y].down.cityBX = x + 1;
					board[x][y].down.cityBY = y;


					board[x][y].right.cityBX = x;
					board[x][y].right.cityBY = y + 1;
				}

				else if (moves[3] == false)
				{
					//top right
					board[x][y].down.cityBX = x + 1;
					board[x][y].down.cityBY = y;

					board[x][y].left.cityBX = x;
					board[x][y].left.cityBY = y - 1;
				}

				else
				{
					board[x][y].down.cityBX = x+1;
					board[x][y].down.cityBY = y;


					board[x][y].right.cityBX = x;
					board[x][y].right.cityBY = y + 1;

					board[x][y].left.cityBX = x;
					board[x][y].left.cityBY = y - 1;
				}
			}
			else if (moves[1] == false)
			{
				//bottom
				if (moves[2] == false)
				{
					//left
					board[x][y].right.cityBX = x;
					board[x][y].right.cityBY = y+1;

					board[x][y].up.cityBX = x-1;
					board[x][y].up.cityBY = y;
				}

				else if (moves[3] == false)
				{
					//right
					board[x][y].left.cityBX = x;
					board[x][y].left.cityBY = y-1;

					board[x][y].up.cityBX = x - 1;
					board[x][y].up.cityBY = y;
				}

				else
				{
					board[x][y].left.cityBX = x;
					board[x][y].left.cityBY = y-1;

					board[x][y].up.cityBX = x - 1;
					board[x][y].up.cityBY = y;

					board[x][y].right.cityBX = x;
					board[x][y].right.cityBY = y+1;
				}
			}

			else
			{
				if (moves[2] == false)
				{
					// left
					board[x][y].up.cityBX = x-1;
					board[x][y].up.cityBY = y;

					board[x][y].down.cityBX = x+1;
					board[x][y].down.cityBY = y;

					board[x][y].right.cityBX = x;
					board[x][y].right.cityBY = y + 1;

				}

				else if (moves[3] == false)
				{
					//right
					board[x][y].left.cityBX = x;
					board[x][y].left.cityBY = y-1;

					board[x][y].up.cityBX = x-1;
					board[x][y].up.cityBY = y;

					board[x][y].down.cityBX = x+1;
					board[x][y].down.cityBY = y;
				}

				else
				{
					board[x][y].left.cityBX = x;
					board[x][y].left.cityBY = y-1;

					board[x][y].up.cityBX = x-1;
					board[x][y].up.cityBY = y;

					board[x][y].right.cityBX = x;
					board[x][y].right.cityBY = y + 1;

					board[x][y].down.cityBX = x+1;
					board[x][y].down.cityBY = y;
				}
			}
		}
	}

	//phew, finally done creating the board and all the links.
	//now onto the Dijkstras!
	boardReset();
	rand1 = random(4);
	rand2 = random(6);
	rand3 = random(4);
	rand4 = random(6);

	resetGyro(Gyro);
	//displayTextLine(1, "%d, %d, %d, %d, ", rand1, rand2, rand3, rand4);
	sleep(1000);
	for (int i = 0; i < 50; i++)
	{
		directionArray[i] = 0;
	}
	finX = 2;
	finY = 4;
	Dijkstras(curX, curY, finX, finY);
	FollowDirections();

	CloseEnc();


};
