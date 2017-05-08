if (vexRT[Btn5U] == 1) {

			if(SensorValue[QuadArm]<95){
				RunArm(127);
			}
			else{
				RunArm(0);
			}
			armstate=0;
			downstate=0;

		}
		else if (vexRT[Btn5D] == 1) {

			if(SensorValue[QuadArm]>0){
				RunArm(-127);
			}
			else{
				RunArm(0);
			}
			armstate=0;
			downstate=1;

		}

		else{

			if(armstate==0){
				if ((SensorValue[QuadArm])>10){
					if(downstate==0){
						RunArm(14);
				//	HoldEngage=1;
					}
					else {
						RunArm(0);
					}
				}
				else{
					if(SensorValue[Button]!=1){
						RunArm(-20);
					}
					else if (SensorValue[Button]==1){
						SensorValue[QuadArm]=0;
					}
				}
			}
			else if (armstate==1)
			{
				armstate=1;
			}
		}
