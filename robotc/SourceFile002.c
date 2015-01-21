#pragma config(Sensor, S1,     ColorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     UltrasonicSensor, sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          Arm,           tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	setMotorSyncEncoder(LeftTire, RightTire, 0, 360, 50);
	while (getMotorRunning(LeftTire))
	{
		playTone(180, 1000);

	}
}
