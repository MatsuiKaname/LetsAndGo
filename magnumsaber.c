#include<stdio.h>
#include<stdlib.h>

#include<wiringPi.h>

int MOTOR_PIN[] = {12,13};

int main(int argc, char *argv[]){
	if(argc<3){
	printf("Usage:%s Motor_Number ON(1)/OFF(0)\n",argv[0]);
	return -1;
	}

	int motor_num = atoi(argv[1]);
	int on_off = atoi(argv[2]);

	if(motor_num > 1){
	printf("Error:Motor_Number must be specified from 0 to 1.\n");
	return -1;
	}

	if(!(on_off == 0 || on_off == 1)){
	printf("Error: ON/OFF must be specified to 0 or 1.\n");
	return -1;
	}
	if(wiringPiSetup() == -1){
	printf("Error: setup failed.\n");
	return -1;
	}

	pinMode(MOTOR_PIN[motor_num],OUTPUT);
	digitalWrite(MOTOR_PIN[0],0);
	digitalWrite(MOTOR_PIN[1],0);

	digitalWrite(MOTOR_PIN[motor_num],on_off);

	return 0;

}
