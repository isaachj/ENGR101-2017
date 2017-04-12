#include <stdio.h>
#include <time.h>
#include "E101.h"

// reads 3 values from the sensor with a gap between readings
int readValues(){
	init();
	int adc_reading;
	adc_reading = read_analog(0);
	printf("%d\n", adc_reading);
	sleep1(1, 0);
	adc_reading = read_analog(2);
	printf("%d\n", adc_reading);
	sleep1(1, 0);
	adc_reading = read_analog(4);
	printf("%d\n", adc_reading);
	sleep1(1, 0);
	return 0;
}

//reads the max value from the sensor
int readMax(){
	init();
	int adc_max;
	int adc_reading;	
	for(int i = 0; i < 10; i++){
		adc_reading = read_analog(0);
		if(adc_reading > adc_max){
			adc_max = adc_reading;
		}
		sleep1(0, 50000);
	}
	printf("%d\n", adc_max);
	return 0;
}

// reads the max and min values from the sensor
int readMaxAndMin(){
	init();
	int adc_reading;
	int adc_max = 0;
	int adc_min = 1024;	
	for(int i = 0; i < 50; i++){
		adc_reading = read_analog(0);
		if(adc_reading > adc_max){
			adc_max = adc_reading;
		}else if(adc_reading < adc_min){
			adc_min = adc_reading;
		}
		sleep1(0, 50000);
	}
	printf("Max: %d\n", adc_max);
	printf("Min: %d\n", adc_min);
	return 0;
}

// reads the average value from the sensor
int readAverage(){
	init();
	int adc_reading = 0;
	for(int i = 0; i < 5; i++){
		adc_reading = adc_reading + read_analog(0);
		adc_reading = adc_reading / 5;
		sleep1(0, 50000);	
	}
	printf("%d\n", adc_reading);
	return 0;
}

// reads the max, min, average and half-range values from the sensor
int readHalfRange(){
	init();
	int adc_reading = 0;
	int adc_avg = 0;
	int adc_max = 0;
	int adc_min = 1024;
	for(int i = 0; i < 5; i++){
		adc_reading = read_analog(0);
		adc_avg = adc_avg + adc_reading;  
		if(adc_reading > adc_max){
			adc_max = adc_reading;
		}else if(adc_reading < adc_min){
			adc_min = adc_reading;
		}
		adc_avg = adc_avg / 5;
		sleep1(0, 50000);	
	}
	int half_range = (adc_max - adc_min) / 2;
	printf("Max: %d\n", adc_max);
	printf("Min: %d\n", adc_min);
	printf("Average Adc Reading: %d\n", adc_avg);
	printf("Half range: %d\n", half_range);
	return 0;
}
