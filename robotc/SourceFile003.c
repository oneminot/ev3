#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
task main()
{
	//motor[LeftTire]=100;
	//motor[RightTire]=100;
	//sleep(1000);
	//motor[LeftTire]=-100;
	//motor[RightTire]=-100;
	//sleep(1000);
	//motor[LeftTire]=0;
	//motor[RightTire]=0;
	//sleep(1000);
	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);
	motor[LeftTire]=100;
	motor[RightTire]=100;
	sleep(2000);
	motor[LeftTire]=0;
	motor[RightTire]=0;

	int DistL = getMotorEncoder(LeftTire);
	int DistR = getMotorEncoder(RightTire);

	displayBigTextLine(4,"LeftTire %d",DistL);
	displayBigTextLine(10,"RightTire %d",DistR);

	sleep(5000);
}
