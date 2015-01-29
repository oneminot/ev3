#pragma config(Sensor, S1,     ColorSensor,    sensorEV3_Color)
#pragma config(Sensor, S3,     LightSensor,    sensorLightActive)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int iStopLightSensor = 35;
int iStopColorSensor = 15;
int iRotateAngle = 1;
int iRotateSpeed = 25;
task main()
{
	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);
	while(true)
	{
		resetMotorEncoder(LeftTire);
		resetMotorEncoder(RightTire);
		displayBigTextLine(4, "welcome, kus");
		short lightSensorValue;
		lightSensorValue = SensorValue(LightSensor);
		displayBigTextLine(6, "%d", lightSensorValue);
		float colorSensorValue;
		colorSensorValue = getColorReflected(ColorSensor);
		displayBigTextLine(8, "%d", colorSensorValue);
		if(getColorReflected(ColorSensor) >= iStopColorSensor && SensorValue(LightSensor) >= iStopLightSensor)
		{
			sleep(2000);
			setMotorSyncEncoder(LeftTire, RightTire, 0, 360, 30);
			//motor[LeftTire] = iRotateSpeed * 2;
			//motor[RightTire] = iRotateSpeed * 2;
			while (getMotorMoving(LeftTire) || getMotorMoving(RightTire))
			{
				if (SensorValue(ColorSensor) < iStopColorSensor || SensorValue(LightSensor) < iStopLightSensor)
				{
					// My right sensor found white stop moving
					motor[LeftTire] = 0;
					motor[RightTire] = 0;
					break;
				}
			}
		}
		if(getColorReflected(ColorSensor) < iStopColorSensor)
		{
			setMotorTarget(LeftTire, iRotateAngle, iRotateSpeed);
			while (getMotorMoving(LeftTire))
			{
				if (SensorValue(ColorSensor) > iStopColorSensor)
				{
					// My right sensor found white stop moving
					sleep(2000);
					motor[LeftTire] = 0;
					break;
				}
			}
		}
		if(SensorValue(LightSensor) < iStopLightSensor)
		{
			setMotorTarget(RightTire, iRotateAngle, iRotateSpeed);
			while (getMotorMoving(RightTire))
			{
				if (SensorValue(LightSensor) > iStopLightSensor)
				{
					sleep(2000);
					motor[RightTire] = 0;
					break;
				}
			}
		}
	}
};
