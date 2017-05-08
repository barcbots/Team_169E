
void Autonomous1r(){

pidBackward(90,110);
Claw(1);
defence=1;
ArmUp();
pidBackward(30,40);
pidRightSide(-25,50);
wait10Msec(500);
defence=0;
wait10Msec(90);
pidBackward(10,10);
Claw(1);

wait10Msec(20);
pidBackward(15,25);
wait10Msec(20);
pidForward(12,20);
Claw(0);
wait10Msec(10);
ArmUp();
wait10Msec(80);
pidBackward(30,70);
wait10Msec(50);
pidBackward(10,20);
pidRightSide(15,20);
pidForward(70,110);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);
wait10Msec(110);



pidLeftSide(20,25);
pidForward(70,110);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);
/*
RunArm(-20);
pidBackward(120,150);
SensorValue[QuadArm]=0;
wait10Msec(30);
//Claw(1);
pidRightSide(-25,50);
pidBackward(10,10);
Claw(1);

wait10Msec(20);
pidBackward(15,25);
wait10Msec(20);
pidForward(12,20);
Claw(0);
wait10Msec(10);
ArmUp();
wait10Msec(80);
pidBackward(30,70);
wait10Msec(50);
pidBackward(10,20);
pidRightSide(15,20);
pidForward(70,110);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);
wait10Msec(110);



pidLeftSide(20,25);
pidForward(70,110);
Claw(0);
wait10Msec(10);
pidBackward(24,25);
ArmUp();
pidBackward(40,60);
*/
}
