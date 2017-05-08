#define LeftDrive1 driveLeft1
#define LeftDrive2 driveLeft2
#define LeftDrive3 driveLeft3
#define RightDrive1 driveRight1
#define RightDrive2 driveRight2
#define RightDrive3 driveRight3
#define QuadLeft QuadLeft1
#define QuadRight QuadRight1



float velocityL;
float velocityR;
int holder=10;
int buffer=0;
int AutoSproket;
char  str[32];
int Ticks(int distance){     ///// Courtesy of Aditya
	return(int)(360*distance/holder);
}

task SpeedCalc()
{
	int tickinitL;
	int tickinitR;

	while(true){
		clearTimer(T1);
		tickinitL=SensorValue[QuadLeft];
		tickinitR=SensorValue[QuadRight];
		while (time1[T1]<100){
			wait1Msec(1);
		}
		velocityL=(abs((SensorValue[QuadLeft])-tickinitL))*20;
		velocityR=(abs((SensorValue[QuadRight])-tickinitR))*20;

	}
}

task LCD()
{
int lastLCDDisplayTime1;

	while(true)
	{

		if (nSysTime > lastLCDDisplayTime1+100) {
			clearLCDLine(0);                      // Clear line 1 (0) of the LCD
			clearLCDLine(1);                      // Clear line 2 (1) of the LCD
			displayLCDPos(0,0);                   // Set the cursor to line 0, position 0 (top line, far left)
			bLCDBacklight = true;
			displayNextLCDNumber(SensorValue[QuadArm]);
			displayLCDPos(1,0);                   // Set the cursor to line 0, position 0 (top line, far left)
			switch(AutoSproket)
	{
	case 0:
displayNextLCDString("progskills");

//#include "progskills.h";

		break;
	case 1:

displayNextLCDString("Autopid_switch");
//#include "Autopid1.h"

		break;
	case 2:

displayNextLCDString("Autopidcube");
//#include "Autopid1R.h"

		break;
	case 3:

displayNextLCDString("Autopidstar_star");
//#include "Autopid1RF.h"

		break;
	case 4:
displayNextLCDString("Autopidstarcube");
//#include "Autopid2.h"

		break;
	case 5:
displayNextLCDString("Autopidstarcube_mid");
//	#include "Autopidcube.h"

		break;
	case 6:
displayNextLCDString("AutopidstarcubeR");
//	#include "Autopidcube2.h"


		break;
	case 7:
displayNextLCDString("AutopidstarcubeR_mid,N");


		break;
	case 8:
displayNextLCDString("deploy");
		break;
		case 9:
 displayNextLCDString("nothing");
		break;


	}
			lastLCDDisplayTime1 = nSysTime;



		}
	}

}

	void Claw(int pos)
	{
		SensorValue(LeftClaw) = pos;
		SensorValue(RightClaw) = pos;
	}

	void LeftDrive(int Speed)
	{
		motor(LeftDrive1) = Speed;
		motor(LeftDrive2) = Speed;

	}
	void RightDrive(int Speed)
	{
		motor(RightDrive1) = Speed;
		motor(RightDrive2) = Speed;

	}
	void BrakeLeft()
	{
		LeftDrive(-10);
		while (velocityL>50){
		wait1Msec(3);
		}
		LeftDrive(0);
	}
	void BrakeRight()
	{
		RightDrive(-10);
		while (velocityR>50){
		wait1Msec(3);
		}
		RightDrive(0);
	}
	void BrakeLeftB()
	{
		LeftDrive(10);
		while (velocityL>50){
		wait1Msec(3);
		}
		LeftDrive(0);
	}
	void BrakeRightB()
	{
		RightDrive(10);
		while (velocityR>50){
		wait1Msec(3);
		}
		RightDrive(0);
	}
	void Forward(int Distance, int Speed)
	{
		SensorValue[QuadLeft]=0;
		SensorValue[QuadRight]=0;
		LeftDrive(Speed);
		RightDrive(Speed);

		int flagL = 1;
		int flagR = 1;

		while((flagL == 1) || (flagR == 1)){

			if((SensorValue[QuadLeft] <= ((Ticks(Distance))-buffer))&&(flagL==1)){}
			else{
				BrakeLeft();
				flagL=0;
			}

			if((SensorValue[QuadRight] <= ((Ticks(Distance))-buffer))&&(flagR==1)){}
			else{
				BrakeRight();
				flagR=0;
			}
		}

	}
	void Backward(int Distance, int Speed)
	{
		SensorValue[QuadLeft]=0;
		SensorValue[QuadRight]=0;
		LeftDrive(-Speed);
		RightDrive(-Speed);

		int flagL = 1;
		int flagR = 1;

		while((flagL == 1) || (flagR == 1)){

			if((abs(SensorValue[QuadLeft]) <= ((Ticks(Distance))-buffer))&&(flagL==1)){}
			else{
				BrakeLeftB();
				flagL=0;
			}

			if((abs(SensorValue[QuadRight]) <= ((Ticks(Distance))-buffer))&&(flagR==1)){}
			else{
				BrakeRightB();
				flagR=0;
			}
		}

	}
	void LeftTurn(int Distance, int Speed)
	{
		SensorValue[QuadLeft]=0;
		SensorValue[QuadRight]=0;
		LeftDrive(-Speed);
		RightDrive(Speed);

		int flagL = 1;
		int flagR = 1;

		while((flagL == 1) || (flagR == 1)){

			if((abs(SensorValue[QuadLeft]) <= ((Ticks(Distance))-buffer))&&(flagL==1)){}
			else{
				BrakeLeftB();
				flagL=0;
			}

			if((abs(SensorValue[QuadRight]) <= ((Ticks(Distance))-buffer))&&(flagR==1)){}
			else{
				BrakeRight();
				flagR=0;
			}
		}

	}
	void RightTurn(int Distance, int Speed)
	{
		SensorValue[QuadLeft]=0;
		SensorValue[QuadRight]=0;
		LeftDrive(Speed);
		RightDrive(-Speed);

		int flagL = 1;
		int flagR = 1;

		while((flagL == 1) || (flagR == 1)){

			if((abs(SensorValue[QuadLeft]) <= ((Ticks(Distance))-buffer))&&(flagL==1)){}
			else{
				BrakeLeft();
				flagL=0;
			}

			if((abs(SensorValue[QuadRight]) <= ((Ticks(Distance))-buffer))&&(flagR==1)){}
			else{
				BrakeRightB();
				flagR=0;
			}
		}

	}
