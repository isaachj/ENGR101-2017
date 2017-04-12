#include <stdio.h>
#include <time.h>
#include "E101.h"

// runs the motor for 5 seconds then stops
int main() {
        init();
        set_motor(1, 100);        
        sleep1(5, 0);    
        stop(1);
        return 0; }

// turns the robot to the left
int turn_left(int duration){
init();
    set_motor(1, 100); //right wheel    
    set_motor(2, -100);    //left wheel
    sleep1(duration, 0);    
    stop(1);
    stop(2);
    return 0; }

// theoretically changes the motors speed based on the sensor readings
int main(){
    init();
    int time = 1;
    while(time < 20){
        double speed = read_analog(0)/700;    
        speed =254*speed;
        printf("%f", speed);    
        set_motor(1, speed);
        sleep1(0, 500000);
        time++; }
    set_motor(1, 0);}
