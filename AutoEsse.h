
char    strA[20];
int defence=0;

task AutoReliz()
{
	while (true){
		if(SensorValue[QuadArm]>78){
			Claw(1);
			if (defence!=1){
			if (SensorValue[QuadArm]>90){
				RunArm(0);
				wait10Msec(5);
				ArmDown();
			}
	}
		}

	}
}
void ArmDef(int time){
	defence=1;
	PIDTUNE(5,0.05,0);
	pidRequestedValue=90;
	wait10Msec(time);
	defence=0;
}
int LightFlag=0;
task LightDebug(){
	while (true){
		if(LightFlag==1){
		motor[port10]=127;
		wait10Msec(10);
		LightFlag=0;
		}
		else if(LightFlag==0){
		motor[port10]=0;
		}
	}
}
void LightUp(){
	LightFlag=1;


}
#include "Autonomous/Autonomous1.h"
#include "Autonomous/Autonomous2.h"
#include "Autonomous/Autonomous3.h"
#include "Autonomous/Autonomous4.h"
#include "Autonomous/Autonomous5.h"
#include "Autonomous/Autonomous6.h"
#include "Autonomous/Autonomous7.h"
#include "Autonomous/Autonomous8.h"
#include "Autonomous/Autonomous9.h"
#include "Autonomous/Autonomous10.h"
#include "Autonomous/Autonomous1r.h"
#include "Autonomous/Autonomous2r.h"
#include "Autonomous/Autonomous3r.h"
#include "Autonomous/Autonomous4r.h"
#include "Autonomous/Autonomous5r.h"
#include "Autonomous/Autonomous6r.h"
#include "Autonomous/Autonomous7r.h"
#include "Autonomous/Autonomous8r.h"
#include "Autonomous/Autonomous9r.h"
#include "Autonomous/Autonomous10r.h"

void RunAuto(int Selected){
	if(SensorValue[AutoRight]==0){
	switch(Selected)
	{
	case 1:
		Autonomous1();
		sprintf( strA, "Autonomous1");
		break;
	case 2:
		Autonomous2();
		sprintf( strA, "Autonomous2");
		break;
	case 3:
		Autonomous3();
		sprintf( strA, "Autonomous3");
		break;
	case 4:
		Autonomous4();
		sprintf( strA, "Autonomous4");
		break;
	case 5:
		Autonomous5();
		sprintf( strA, "Autonomous5");
		break;
	case 6:
		Autonomous6();
		sprintf( strA, "Autonomous6");
		break;
	case 7:
		Autonomous7();
		sprintf(strA, "Autonomous7");
		break;
	case 8:
		Autonomous8();
		sprintf( strA, "Autonomous8");
		break;
	case 9:
		Autonomous9();
		sprintf( strA, "Autonomous9");
		break;
	case 10:
		Autonomous10();
		sprintf( strA, "Autonomous10");
		break;
	}
}
else if(SensorValue[AutoRight]==1){
		switch(Selected)
	{
	case 1:
		Autonomous1r();
		sprintf( strA, "Autonomous1r");
		break;
	case 2:
		Autonomous2r();
		sprintf( strA, "Autonomous2r");
		break;
	case 3:
		Autonomous3r();
		sprintf( strA, "Autonomous3r");
		break;
	case 4:
		Autonomous4r();
		sprintf( strA, "Autonomous4r");
		break;
	case 5:
		Autonomous5r();
		sprintf( strA, "Autonomous5r");
		break;
	case 6:
		Autonomous6r();
		sprintf( strA, "Autonomous6r");
		break;
	case 7:
		Autonomous7r();
		sprintf(strA, "Autonomous7r");
		break;
	case 8:
		Autonomous8r();
		sprintf( strA, "Autonomous8r");
		break;
	case 9:
		Autonomous9r();
		sprintf( strA, "Autonomous9r");
		break;
	case 10:
		Autonomous10r();
		sprintf( strA, "Autonomous10r");
		break;
	}

}
}
