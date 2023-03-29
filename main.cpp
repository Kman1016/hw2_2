#include "mbed.h"

// main() runs in its own thread in the OS
PwmOut PWM1(D6);
AnalogIn Ain(A0), AO(A1);
Thread t, t2;


void pwm_ramp() {
    while (true) {
        PWM1.period_ms(5);
        PWM1 = Ain*5;
        ThisThread::sleep_for(1ms);
        
    }
};

void AOIn() {
    while (true) {
        printf("%f\n", AO.read());
        ThisThread::sleep_for(1ms);
    }
};


int main()
{
    t.start(pwm_ramp);
    t2.start(AOIn);
    while (true) {
        
    }
}