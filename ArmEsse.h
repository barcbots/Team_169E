void ArmUp(){

	PIDTUNE(2.2,0.3,1.8);

	pidRequestedValue=95;
}
void ArmMid(){
	PIDTUNE(3.5,0.05,0.08);
	//	pidholder=50;
	pidRequestedValue=50;
}

void ArmDown(){
	PIDTUNE(4,0.05,0.7);
	//	pidholder=0;
	pidRequestedValue=-8;
}
int HoldEngage=0;
int Hold_Predict=10;
float Hold_Speed=0;
int HoldPosition;
float HoldTune=0.001;
int Hold_last=0;
int Hold_init=0;

task ArmHold1()
{
while (true){
	while(HoldEngage==1){
		if (Hold_init==0){
	Hold_Speed=Hold_Predict;
	HoldPosition=SensorValue[QuadArm];
	Hold_init=1;
	Hold_last=SensorValue[QuadArm];
}

	if((SensorValue[QuadArm]-HoldPosition)>10){
		Hold_Speed=Hold_Speed-1*HoldTune;
	}
	else if((SensorValue[QuadArm]-HoldPosition)<-10){
		Hold_Speed=Hold_Speed+1*HoldTune;
	}

	RunArm(Hold_Speed);

	}
	wait1Msec( 25 );
}
}
