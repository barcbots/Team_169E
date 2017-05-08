#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    Expander,       sensorNone)
#pragma config(Sensor, in8,    AutoPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  LEDleft,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  LEDright,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  Button,         sensorTouch)
#pragma config(Sensor, dgtl4,  LeftClaw,       sensorDigitalOut)
#pragma config(Sensor, dgtl6,  QuadArm,        sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  QuadRight,      sensorQuadEncoder)
#pragma config(Sensor, dgtl10, RightClaw,      sensorDigitalOut)
#pragma config(Sensor, dgtl11, QuadLeft,       sensorQuadEncoder)
#pragma config(Motor,  port2,           driveLY,       tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, dgtl11)
#pragma config(Motor,  port3,           driveLM,       tmotorVex393TurboSpeed_MC29, openLoop, reversed, encoderPort, dgtl11)
#pragma config(Motor,  port4,           armLIT,        tmotorVex393HighSpeed_MC29, openLoop, encoderPort, dgtl6)
#pragma config(Motor,  port5,           armLOT,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armROT,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port7,           armRIT,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           driveRM,       tmotorVex393TurboSpeed_MC29, openLoop, encoderPort, dgtl8)
#pragma config(Motor,  port9,           driveRY,       tmotorVex393TurboSpeed_MC29, openLoop, reversed, encoderPort, dgtl8)

	void LeftDrive(int Speed)
	{
		motor(driveLY) = Speed;
		motor(driveLM) = Speed;

	}
	void RightDrive(int Speed)
	{
		motor(driveRY) = Speed;
		motor(DriveRM) = Speed;

	}
	void Claw(int pos)
{
	SensorValue(LeftClaw) = pos;
	SensorValue(RightClaw) = pos;
}
int Motor_Speed=80;

task main()
{
	clearDebugStream();
 Claw(0);
	while(true){
			SensorValue[QuadRight]=0;
			RightDrive(Motor_Speed);
			LeftDrive(Motor_Speed);

			wait10Msec(50);
			SensorValue[QuadRight]=0;
			clearTimer(T1);
			wait10Msec(100);
		//	sprintf(str)
			writeDebugStreamLine("%3i   %5i", Motor_Speed,(abs(SensorValue[QuadRight])/12) );
			Motor_Speed=Motor_Speed+1 ;
		}



	}
