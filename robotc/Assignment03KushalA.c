#pragma config(Sensor, S1,     UltrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Arm,           tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          LeftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int MaxDistance = 21;
int MinDistance = 10;
bool boolTurnedRight = false;
bool boolTurnedLeft = false;
bool boolTurnedFront = true;
int intLeftDistance = 0;
int intRightDistance = 0;
int intFrontDistance = 0;
int intLongWait = 0;
int intShortWait = 200;

void ResetAllMotorEncoders()
{
	resetMotorEncoder(Arm);
	resetMotorEncoder(LeftMotor);
	resetMotorEncoder(RightMotor);
}

void ResetSensorLocation()
{
	motor[Arm] = -50;
	sleep(1000);
	motor[Arm] = 0;
	ResetAllMotorEncoders();
	displayBigTextLine(10, "Let's face front!");
	setMotorTarget(Arm, 105, 15);
	while(getMotorRunning(Arm))
	{
		//do nothing
		setLEDColor(ledOrangePulse);

	}
}

void TurnSensorLeft()
{
	motor[Arm] = -50;
	sleep(1000);
	motor[Arm] = 0;
	ResetAllMotorEncoders();
}

void TurnSensorRight()
{
	motor[Arm] = 50;
	sleep(1000);
	motor[Arm] = 0;
	ResetAllMotorEncoders();
}

void TurnSensorFront()
{
	ResetSensorLocation();
}

void GetLeftDistance()
{
	TurnSensorLeft();
	intLeftDistance = getUSDistance(UltrasonicSensor);
}

void GetRightDistance()
{
	TurnSensorRight();
	intRightDistance = getUSDistance(UltrasonicSensor);
}

void GetFrontDistance()
{
	TurnSensorFront();
	intFrontDistance = getUSDistance(UltrasonicSensor);
}

void MoveLeft()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	motor[RightMotor] =  30;
	motor[LeftMotor] = -10;
	sleep(intShortWait);
	motor[LeftMotor] = 0;
	motor[RightMotor] = 0;
}

void MoveRight()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	motor[LeftMotor] =  30;
	motor[RightMotor] = -10;
	sleep(intShortWait);
	motor[LeftMotor] = 0;
	motor[RightMotor] = 0;
}

void MoveForward()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	if(intFrontDistance > 200 && intLeftDistance < MaxDistance)
	{
		setMotorSyncEncoder(LeftMotor, RightMotor, 0, 720, 50);
	}
	else
	{
		setMotorSyncEncoder(LeftMotor, RightMotor, 0, 180, 50);
	}
}

void MoveBack()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	setMotorSyncEncoder(LeftMotor, RightMotor, 0, 60, -20);
}

void GetDistances()
{
	GetLeftDistance();
	sleep(intShortWait);
	displayBigTextLine(2, "%d", intLeftDistance);
	sleep(intShortWait);
	GetRightDistance();
	sleep(intShortWait);
	displayBigTextLine(4, "%d", intRightDistance);
	sleep(intShortWait);

	GetFrontDistance();
	sleep(intShortWait);
	displayBigTextLine(6, "%d", intFrontDistance);
	sleep(intShortWait);
	sleep(intShortWait);
}

task main()
{
	displayString(1, "hello");
	ResetSensorLocation();
	while(true)
	{
		ResetAllMotorEncoders();
		setLEDColor(ledGreenPulse);
		GetDistances();
		if(intLeftDistance <= MaxDistance && intLeftDistance >= MinDistance && intFrontDistance >= MaxDistance)
		{
			MoveForward();
		}
		else if (intFrontDistance < MinDistance)
		{
			MoveBack();
		}
		else if (intLeftDistance <= MinDistance || intFrontDistance <= MaxDistance)
		{
			MoveRight();
		}
		else if (intRightDistance <= MinDistance || intLeftDistance >= MaxDistance)
		{
			MoveLeft();
		}
	}
}
