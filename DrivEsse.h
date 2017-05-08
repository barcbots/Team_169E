#include "LinearArray.h"
static float pidRequestedValueL;
static float pidRequestedValueR;


float velocityL;
float velocityR;
float velocityA;
int errorL;
int errorR;
int holder=10;


int Ticks(int distance){     ///// Courtesy of Aditya
	return(int)(360*distance/holder);
}

int Lineariz(int motorValue){     ///// Courtesy of Aditya
	return(int)(motorValue);
}

int pidTicks(float distance){     ///// Courtesy of Aditya
	return(int)(360*distance/10.65);
}

int pidAngles(float angles){     ///// Courtesy of Aditya
	return(int)(angles*3.94);
}

int Arc_Speed_H;
int Arc_Speed_L;
int Arc_Distance_H;
int Arc_Distance_L;
const float drive_width=14;
void pidArc(float radius, float end_angle, float max_speed ){
	Arc_Distance_H = pow((radius+drive_width),2)*PI/4;
	Arc_Distance_L = pow(radius,2)*PI/4;
	Arc_Speed_H = max_speed;
	Arc_Speed_L = max_speed*(Arc_Speed_L/Arc_Speed_H);

}
int smooth_turn_motor;
void SmoothTurn(int Target, float factor_int, float factor_end, int max){
	if ((abs(SensorValue[QuadLeft]))<(abs(Target*factor_int))){
		smooth_turn_motor=10+((abs(Target*factor_int)-10)/(1+100*pow(2.718,-(abs(SensorValue[QuadLeft])))));
	}
}

task SpeedCalc()
{
	int tickinitL;
	int tickinitR;
	int tickinitA;
  datalogClear();
	while(true){

		clearTimer(T1);
		tickinitL=(SensorValue[QuadLeft]);
		tickinitR=(SensorValue[QuadRight]);
		tickinitA=(SensorValue[QuadArm]);
		while (time10[T1]<50){
			wait1Msec(1);
		}
		velocityL=((abs((SensorValue[QuadLeft])-tickinitL))/9);
		velocityR=((abs((SensorValue[QuadRight])-tickinitR))/9);
		velocityA=(abs((SensorValue[QuadArm])-tickinitA)*2);
	//	errorL= abs((abs(pidRequestedValueL)-(abs(SensorValue[QuadLeft]/3))));
	//	errorR= abs((abs(pidRequestedValueR)-(abs(SensorValue[QuadRight]/3))));
    datalogDataGroupStart();
		datalogAddValue(0, velocityL);
    datalogAddValue(1, velocityR);
    datalogDataGroupEnd();
	}
}
