#pragma config(Sensor, S2,     LeftColor,      sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S1,     RightColor,     sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S3,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S4,     Touch,          sensorEV3_Touch)
#pragma config(Motor,  motorB,          LeftTire,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RightTire,     tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
const int kushal_length = 7;
const int kushal_width = 5;
const int kushal_initial_length = 0;
const int kushal_initial_width = 0;
const int kushal_initial_kushal_directionion = 0;
bool is_kushal_tile_white[kushal_length][kushal_width];
bool win;
bool spaces = false;
void DriveIn();
int int_sleep_timer = 100;
void kushal_stop()
{
	displayCenteredTextLine(7, "%s", "kushal_stop");
	setMotorSpeed(RightTire, 0);
	setMotorSpeed(LeftTire, 0);
}
void kushal_turn(int kushal_right_tire_speed, int kushal_left_tire_speed)
{
	displayCenteredTextLine(7, "%s", "kushal turn");
	setMotorSpeed(RightTire, kushal_right_tire_speed);
	setMotorSpeed(LeftTire, kushal_left_tire_speed);
}
void kushal_reset_motor_encoders()
{
	displayCenteredTextLine(7, "%s", "kushal reset motor encoders");
	resetMotorEncoder(LeftTire);
	resetMotorEncoder(RightTire);
}
void set_spaces_true_if_we_are_in_white()
{
	displayCenteredTextLine(7, "%s", "all spaces");
	for(int x = 0; x < kushal_length; x++)
	{
		for(int y = 0; y < kushal_width; y++)
		{
			if(is_kushal_tile_white[x][y] == false)
			{
				spaces = false;
				x = kushal_length;
				break;
			}
			else
			{
				spaces = true;
			}
		}
	}
}
void GoBack()
{
	displayCenteredTextLine(7, "%s", "go back");
	setMotorSyncEncoder(LeftTire, RightTire, 0, 250, -30);
	while(getMotorRunning(LeftTire)){}
	sleep(int_sleep_timer);
}
void GoBackFull()
{
	displayCenteredTextLine(7, "%s", "go back full");
	kushal_stop();
	setMotorSyncEncoder(LeftTire, RightTire, 0, 700, -30);
	while(getMotorRunning(LeftTire))
	{
		if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] > 2)
		{
			kushal_stop();
			setMotorSpeed(RightTire, -10);
			while(SensorValue[RightColor] > 2){}
			kushal_stop();
		}
		else if(SensorValue[LeftColor] > 2 && SensorValue[RightColor] < 2)
		{
			kushal_stop();
			setMotorSpeed(LeftTire, -10);
			while(SensorValue[LeftColor] > 2){}
			kushal_stop();
		}
		else if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] < 2)
		{
			kushal_stop();
		}
	}
	sleep(int_sleep_timer);
	GoBack();
}
bool should_i_keep_going()
{
	displayCenteredTextLine(7, "%s", "should i keep going");
	kushal_reset_motor_encoders();
	setMotorSyncEncoder(LeftTire, RightTire, 0, 100, 30);
	while(getMotorRunning(LeftTire)){}
	sleep(int_sleep_timer);
	if(SensorValue[LeftColor] == 5 && SensorValue[RightColor] == 5)
	{
		GoBackFull();
		DriveIn();
		// i won
		GoBackFull();
		win = true;
		return false;
	}
	else {return true;}
}
void DriveIn()
{
	displayCenteredTextLine(7, "%s", "drive in");
	kushal_stop();
	setMotorSyncEncoder(LeftTire, RightTire, 0, 700, 40);
	while(getMotorRunning(LeftTire))
	{
		if(getTouchValue(Touch) == 1)
		{
			GoBack();
		}
		if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] > 2)
		{
			kushal_stop();
			kushal_turn(20, -4);
			while(SensorValue[RightColor] > 2){}
			kushal_stop();
		}
		else if(SensorValue[LeftColor] > 2 && SensorValue[RightColor] < 2)
		{
			kushal_stop();
			kushal_turn(-4, 20);
			while(SensorValue[LeftColor] > 2){}
			kushal_stop();
		}
		else if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] < 2)
		{
			kushal_stop();
		}
	}
	kushal_reset_motor_encoders();
	setMotorSyncEncoder(LeftTire, RightTire, 0, 450, 40);
	while(getMotorRunning(LeftTire)){}
}
bool GoToLine(int r, int c)
{
	displayCenteredTextLine(7, "%s", "go to line");
	set_spaces_true_if_we_are_in_white();
	bool temp = true;
	if(win == true || spaces == true)
	{
		return false;
	}
	if(is_kushal_tile_white[r][c]== true)
	{
		if(r + 1 < kushal_length)
		{
			if(is_kushal_tile_white[r + 1][c]== false)
			{
				if(GoToLine(r + 1,c))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else if(r - 1 > -1)
		{
			if(is_kushal_tile_white[r - 1][c]== false)
			{
				if(GoToLine(r - 1,c))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else if(c + 1 < kushal_width)
		{
			if(is_kushal_tile_white[r][c + 1]== false)
			{
				if(GoToLine(r,c + 1))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else if(c - 1 > -1)
		{
			if(is_kushal_tile_white[r][c - 1]== false)
			{
				if(GoToLine(r, c - 1))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		kushal_stop();
		setMotorSyncEncoder(LeftTire,RightTire,0,1000,30);
		while(getMotorRunning(LeftTire))
		{
			if(getTouchValue(Touch) == 1)
			{
				GoBack();
				return false;
			}
			if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] > 2)
			{
				kushal_stop();
				kushal_turn(20, -4);
				while(SensorValue[RightColor] > 2){}
				kushal_stop();
				temp = should_i_keep_going();
				if(temp == true)
				{
					is_kushal_tile_white[r][c] = true;
					GoBack();
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(SensorValue[LeftColor] > 2 && SensorValue[RightColor] < 2)
			{
				kushal_stop();
				kushal_turn(-4, 20);
				while(SensorValue[LeftColor] > 2){}
				kushal_stop();
				temp = should_i_keep_going();
				if(temp == true)
				{
					is_kushal_tile_white[r][c] = true;
					GoBack();
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(SensorValue[LeftColor] < 2 && SensorValue[RightColor] < 2)
			{
				kushal_stop();
				temp = should_i_keep_going();
				if(temp == true)
				{
					is_kushal_tile_white[r][c] = true;
					GoBack();
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}
void TurnRight()
{
	displayCenteredTextLine(7, "%s", "turn right");
	kushal_stop();
	int CurGyro = SensorValue[Gyro] + 84;
	kushal_turn(-25, 25);
	while(SensorValue[Gyro] < CurGyro){}
	kushal_stop();
	sleep(int_sleep_timer);
}
void TurnLeft()
{
	displayCenteredTextLine(7, "%s", "turn left");
	kushal_stop();
	int CurGyro = SensorValue[Gyro] - 84;
	kushal_turn(25, -25);
	while(SensorValue[Gyro] > CurGyro){}
	kushal_stop();
	sleep(int_sleep_timer);
}
void checkLeft(int r, int c,int kushal_direction,bool &goLeft)
{
	displayCenteredTextLine(7, "%s", "check left");
	if(kushal_direction <1)
	{
		kushal_direction = 4;
	}
	if(kushal_direction == 1)
	{
		r = r + 1;
	}
	else if(kushal_direction == 2)
	{
		c = c + 1;
	}
	else if(kushal_direction == 3)
	{
		r = r - 1;
	}
	else
	{
		c = c - 1;
	}
	if((kushal_direction == 1 && r > 6) || (kushal_direction == 2 && c > 4) || (kushal_direction == 3 && r < 0) || (kushal_direction == 4 && c < 0))
	{
		goLeft = false;
	}
	if(goLeft)
	{
		TurnLeft();
		if(!(GoToLine(r, c)))
		{
			goLeft = false;
		}
		else
		{
			goLeft = true;
		}
		TurnRight();
	}
}
void checkRight(int r, int c,int kushal_direction, bool &goRight)
{
	displayCenteredTextLine(7, "%s", "check right");
	if(kushal_direction > 4)
	{
		kushal_direction = 1;
	}
	if(kushal_direction == 1)
	{
		r = r + 1;
	}
	else if(kushal_direction == 2)
	{
		c = c + 1;
	}
	else if(kushal_direction == 3)
	{
		r = r - 1;
	}
	else
	{
		c = c - 1;
	}
	if((kushal_direction == 1 && r > 6) || (kushal_direction == 2 && c > 4) || (kushal_direction == 3 && r < 0) || (kushal_direction == 4 && c < 0))
	{
		goRight = false;
	}
	if(goRight)
	{
		TurnRight();
		if(!GoToLine(r, c))
		{
			goRight = false;
		}
		else
		{
			goRight = true;
		}
		TurnLeft();
	}
}
void checkFront(int r, int c,int kushal_direction, bool &goStraight)
{
	displayCenteredTextLine(7, "%s", "check front");
	if(kushal_direction == 1)
	{
		r = r + 1;
	}
	else if(kushal_direction == 2)
	{
		c = c + 1;
	}
	else if(kushal_direction == 3)
	{
		r = r - 1;
	}
	else
	{
		c = c - 1;
	}
	if((kushal_direction == 1 && r > 6) || (kushal_direction == 2 && c > 4) || (kushal_direction == 3 && r < 0) || (kushal_direction == 4 && c < 0))
	{
		goStraight = false;
	}
	if(goStraight)
	{
		if(!GoToLine(r, c))
		{
			goStraight = false;
		}
		else
		{
			goStraight = true;
		}
	}
}
void Maze(int r, int c, int kushal_direction)
{
	displayCenteredTextLine(7, "%s", "maze");
	set_spaces_true_if_we_are_in_white();
	int kushal_temporary_row,kushal_temporary_column,tempdir;
	bool goLeft = true;
	bool goRight = true;
	bool goStraight = true;
	displayCenteredBigTextLine(1, "Row%d", r);
	displayCenteredBigTextLine(3, "Column %d", c);
	displayCenteredBigTextLine(5, "Direction %d", kushal_direction);
	if(kushal_direction > 4)
	{
		kushal_direction = 1;
	}
	if(kushal_direction <1)
	{
		kushal_direction = 4;
	}
	checkLeft(r,c,kushal_direction-1,goLeft);
	checkFront(r,c,kushal_direction,goStraight);
	checkRight(r,c,kushal_direction+1,goRight);
	if(win == true || spaces == true)
	{
		goLeft = false;
		goRight = false;
		goStraight = false;
	}
	kushal_temporary_row = r;
	kushal_temporary_column = c;
	if(goLeft)
	{
		tempdir = kushal_direction;
		kushal_direction = kushal_direction - 1;
		if(kushal_direction <1)
		{
			kushal_direction = 4;
		}
		if(kushal_direction == 1)
		{
			kushal_temporary_row = r + 1;
		}
		else if(kushal_direction == 2)
		{
			kushal_temporary_column = c + 1;
		}
		else if(kushal_direction == 3)
		{
			kushal_temporary_row = r - 1;
		}
		else
		{
			kushal_temporary_column = c - 1;
		}
		sleep(int_sleep_timer);
		TurnLeft();
		DriveIn();
		Maze(kushal_temporary_row , kushal_temporary_column , kushal_direction);
		GoBackFull();
		TurnRight();
		kushal_direction = tempdir;
		set_spaces_true_if_we_are_in_white();
		if(win == true|| spaces == true)
		{
			goLeft = false;
			goRight = false;
			goStraight = false;
		}
	}
	if(goStraight)
	{
		if(kushal_direction == 1)
		{
			kushal_temporary_row = r + 1;
		}
		else if(kushal_direction == 2)
		{
			kushal_temporary_column = c + 1;
		}
		else if(kushal_direction == 3)
		{
			kushal_temporary_row = r - 1;
		}
		else
		{
			kushal_temporary_column = c - 1;
		}
		sleep(int_sleep_timer);
		DriveIn();
		Maze(kushal_temporary_row , kushal_temporary_column , kushal_direction);
		GoBackFull();
		set_spaces_true_if_we_are_in_white();
		if(win == true || spaces == true)
		{
			goLeft = false;
			goRight = false;
			goStraight = false;
		}
	}
	if(goRight)
	{
		tempdir = kushal_direction;
		kushal_direction = kushal_direction + 1;
		if(kushal_direction > 4)
		{
			kushal_direction = 1;
		}
		if(kushal_direction == 1)
		{
			kushal_temporary_row = r + 1;
		}
		else if(kushal_direction == 2)
		{
			kushal_temporary_column = c + 1;
		}
		else if(kushal_direction == 3)
		{
			kushal_temporary_row = r - 1;
		}
		else
		{
			kushal_temporary_column = c - 1;
		}
		sleep(int_sleep_timer);
		TurnRight();
		DriveIn();
		Maze(kushal_temporary_row,kushal_temporary_column,kushal_direction);
		GoBackFull();
		TurnLeft();
		kushal_direction = tempdir;
		set_spaces_true_if_we_are_in_white();
		if(win == true|| spaces == true)
		{
			goLeft = false;
			goRight = false;
			goStraight = false;
		}
	}
	if(!goLeft  && !goRight && !goStraight)
	{
		set_spaces_true_if_we_are_in_white();
	}
}
task main()
{
	displayCenteredTextLine(7, "%s", "main");
	resetGyro(Gyro);
	is_kushal_tile_white[kushal_initial_length][kushal_initial_width] = true;
	Maze(kushal_initial_length, kushal_initial_width, kushal_initial_kushal_directionion);
}