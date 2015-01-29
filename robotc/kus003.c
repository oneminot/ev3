#pragma config(Sensor, S1,     ColorSensor,    sensorEV3_Color)
#pragma config(Sensor, S3,     LightSensor,    sensorLightActive)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int iStopLightSensor = 35;
int iStopColorSensor = 15;
task main()
{
	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);
	while(true)
	{
		displayBigTextLine(4, "welcome, kus");
		short lightSensorValue;
		lightSensorValue = SensorValue(LightSensor);
		displayBigTextLine(6, "%d", lightSensorValue);
		float colorSensorValue;
		colorSensorValue = getColorReflected(ColorSensor);
		displayBigTextLine(8, "%d", colorSensorValue);
		if(getColorReflected(ColorSensor) > iStopColorSensor && SensorValue(LightSensor) > iStopLightSensor)
		{
			setMotorSyncEncoder(LeftTire, RightTire, 0, 60, 50);
		}
		else if(getColorReflected(ColorSensor) < iStopColorSensor)
		{
			moveMotorTarget(LeftTire, 80, 40);
			while (getMotorMoving(LeftTire))
			{
				if (SensorValue(ColorSensor) < iStopColorSensor)
				{
					break;
				}
			}
		}
		else if(SensorValue(LightSensor) < iStopLightSensor)
		{
			moveMotorTarget(LeftTire, 80, 40);
			while (getMotorMoving(LeftTire))
			{
				if (SensorValue(ColorSensor) < iStopLightSensor)
				{
					break;
				}
			}
		}
	}

};