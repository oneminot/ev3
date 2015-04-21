#pragma config(Sensor, S1,     LeftColorSensor, sensorEV3_Color)
#pragma config(Sensor, S2,     RightColorSensor, sensorEV3_Color)
#pragma config(Sensor, S3,     GyroSensor,     sensorEV3_Gyro)
#pragma config(Sensor, S4,     TouchSensor,    sensorEV3_Touch)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int KSoundVolume = 5;

int KForwardSpeed = 20;
int KTurnSpeed = 20;

int KDebugTimeout = 5000;

const int KTrayLength = 7;
const int KTrayWidth = 5;

int VisitedSquare[KTrayLength][KTrayWidth];
int Wall[KTrayLength][KTrayWidth];

void InitializeVisitedSquareTray(int InitialValue)
{
	for (int i = 0; i < KTrayLength; i++)
	{
		for (int j = 0; j < KTrayWidth; j++)
		{
			VisitedSquare[i][j] = InitialValue;
		}
	}
}

void InitializeWallTray(int InitialValue)
{
	for (int i = 0; i < KTrayLength; i++)
	{
		for (int j = 0; j < KTrayWidth; j++)
		{
			Wall[i][j] = InitialValue;
		}
	}
}

void PrintStats()
{

}

bool ShouldGoLeft()
{
	if(SensorValue(LeftColorSensor) > 12 && SensorValue(RightColorSensor) <= 5){return true;} else {return false;}
}

bool ShouldGoRight()
{
	if(SensorValue(LeftColorSensor) <= 12 && SensorValue(RightColorSensor) > 5){return true;} else {return false;}
}

task main()
{
	setSoundVolume(KSoundVolume);
	InitializeVisitedSquareTray(0);
	InitializeWallTray(0);

	while(true)
	{
		PrintStats();
		while(ShouldGoLeft())
		{
			displayBigTextLine(10, "go left");
			motor[LeftTire] = -KTurnSpeed;
			motor[RightTire] = KTurnSpeed;
		}
		while(ShouldGoRight())
		{
			displayBigTextLine(10, "go right");
			motor[LeftTire] = KTurnSpeed;
			motor[RightTire] = -KTurnSpeed;
		}
		while(!ShouldGoRight() && !ShouldGoLeft())
		{
			displayBigTextLine(10, "go straight");
			motor[LeftTire] = KForwardSpeed;
			motor[RightTire] = KForwardSpeed;
		}
	}
}
