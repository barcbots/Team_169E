char    str[20];
char side[1];
float BatteryExp;
int AutoSelect;
int DiagStat;
int Diag_Motor=1;
int Diag_Motor_holder;
int Diag_Speed;
int Is_Diag_On=0;

const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int LCDstat=2;


void waitForRelease()
{
	while(vexRT[Btn6U]!= 0){}
	wait1Msec(5);
}
void waitForRelease1()
{
	while(vexRT[Btn6D]!= 0){}
	wait1Msec(5);
}
task Diagnostics(){
	//Diag_Motor=1;
	while(true){
		if(vexRT[Btn6U]){
			Diag_Motor=Diag_Motor+1;
			waitForRelease();

		}
		else if (vexRT[Btn6D]){
			Diag_Motor=Diag_Motor-1;
			waitForRelease1();
		}
		else{
			Diag_Motor=Diag_Motor;
		}


		if (abs(vexRT[Ch2]) >= 10) {
			if (vexRT[Ch2]>0){
				motor[Diag_Motor]=vexRT[Ch2];
				Diag_Speed=vexRT[Ch2];

			}
			else if (vexRT[Ch2] <= -10){
				motor[Diag_Motor]=vexRT[Ch2];
				Diag_Speed=vexRT[Ch2];
			}

		}
		else {
			motor[Diag_Motor] = 0;
			Diag_Speed=0;

		}

	}

}
task LCD()
{
	int lastLCDDisplayTime1;

	while(true)
	{
		AutoSelect= (SensorValue[AutoPot]/15/23);
		BatteryExp= SensorValue[in1]/280.00;

		if(SensorValue[AutoRight]==0){
			side='L';
		}
		else if(SensorValue[AutoRight]==1){
			side='R';
		}
		if(nLCDButtons == leftButton){
			LCDstat=1;
		}
		else if(nLCDButtons == centerButton){
			LCDstat=2;
		}
		else if(nLCDButtons == rightButton){
			LCDstat=3;
		}


		if (nSysTime > lastLCDDisplayTime1+100) {
			clearLCDLine(0);                      // Clear line 1 (0) of the LCD
			clearLCDLine(1);                      // Clear line 2 (1) of the LCD
			bLCDBacklight = true;
			switch(LCDStat){

			case 1:
				if (Is_Diag_On==1){
					stopTask(Diagnostics);
					startTask(usercontrol);
					Is_Diag_On=0;
				}
				sprintf( str, "Autonomous%i%c",AutoSelect,side );
				displayLCDString(0, 0, str);
				sprintf( str, "Lt%3.2f Rt%3.2f ",SmartMotorGetCurrent( port2 ),SmartMotorGetCurrent( port8 ) );
				displayLCDString(1, 0, str);


				break;

			case 2:
				if (Is_Diag_On==1){
					stopTask(Diagnostics);
					startTask(usercontrol);
					Is_Diag_On=0;
				}

				sprintf( str, "Lt%3i Crx. %3.2fV",  velocityL, nImmediateBatteryLevel/1000.0 );
				displayLCDString(0, 0, str);
				sprintf( str, "Rt%3i Exp. %3.2fV",  velocityR, BatteryExp );
				displayLCDString(1, 0, str);


				break;

			case 3:
				if (Is_Diag_On==0){
					stopTask(usercontrol);
					startTask(Diagnostics);
					Is_Diag_On=1;
				}

				sprintf( str, "	Diagnostics");
				displayLCDString(0, 0, str);
				sprintf( str, "Motor%i Speed %i",Diag_Motor, Diag_Speed );
				displayLCDString(1, 0, str);


				break;


			}

			lastLCDDisplayTime1 = nSysTime;

		}
	}

}
