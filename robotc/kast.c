#pragma config(Sensor, S1,     UltrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Arm,           tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          LeftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          RightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int MaxFrontDistance = 250;
int Max = 255;
int intSensorWait = 2000;
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
	sleep(intSensorWait);
	motor[Arm] = 0;
	ResetAllMotorEncoders();
	displayTextLine(10, "Let's face front!");
	setMotorTarget(Arm, 105, 15);
	setLEDColor(ledGreen);
	while(getMotorRunning(Arm))
	{
		//do nothing
		sleep(intSensorWait);
		setLEDColor(ledOrange);
	}
	setLEDColor(ledGreenFlash);
}

void TurnSensorLeft()
{
	motor[Arm] = -50;
	sleep(intSensorWait);
	motor[Arm] = 0;
	ResetAllMotorEncoders();
}

void TurnSensorRight()
{
	motor[Arm] = 50;
	sleep(intSensorWait);
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

void MoveForwardALot()
{
	if(intFrontDistance > MaxFrontDistance)
	{
		sleep(intLongWait);
		ResetAllMotorEncoders();
		setMotorSyncEncoder(LeftMotor, RightMotor, 0, 720, 50);
		MoveForwardALot();
	}
}

void MoveLeft()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	motor[RightMotor] =  30;
	motor[LeftMotor] = -30;
	sleep(intShortWait);
	motor[LeftMotor] = 0;
	motor[RightMotor] = 0;
}

void MoveRight()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	motor[LeftMotor] =  30;
	motor[RightMotor] = -30;
	sleep(intShortWait);
	motor[LeftMotor] = 0;
	motor[RightMotor] = 0;
}

void MoveForward()
{
	sleep(intLongWait);
	ResetAllMotorEncoders();
	setMotorSyncEncoder(LeftMotor, RightMotor, 0, 180, 50);
	MoveForwardALot();
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

bool isLeftTurnPossible()
{
	if(intRightDistance <= MinDistance || intLeftDistance > MaxDistance)
	{
		return true;
	}
	else { return false; }
}

bool isRightTurnPossible()
{
	if(intLeftDistance <= MinDistance || intRightDistance > MaxDistance)
	{
		return true;
	}
	else { return false; }
}

bool isMoveForwardPossible()
{
	if(intFrontDistance >= MinDistance && intLeftDistance >= MinDistance && intRightDistance >= MinDistance)
	{
		return true;
	}
	else { return false; }
}

task main()
{
	ResetSensorLocation();
	while(true)
	{
		ResetAllMotorEncoders();
		setLEDColor(ledGreenPulse);
		GetDistances();
		if (intFrontDistance <= MinDistance)
		{
			MoveBack();
		}
		else if (isMoveForwardPossible())
		{
			MoveForward();
		}
		else if (isRightTurnPossible())
		{
			MoveRight();
		}
		else if (isLeftTurnPossible())
		{
			MoveLeft();
		}
	}
}
