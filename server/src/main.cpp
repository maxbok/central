#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "GPIO.h"

using namespace std;

void sig_handler(int sig);

bool ctrl_c_pressed = false;

int main() {
    struct sigaction sig_struct;
    sig_struct.sa_handler = sig_handler;
    sig_struct.sa_flags = 0;
    sigemptyset(&sig_struct.sa_mask);

    if (sigaction(SIGINT, &sig_struct, NULL) == -1) {
        cout << "Problem with sigaction" << endl;
        exit(1);
    }

    GPIO *gpio18 = new GPIO("18");

    gpio18->export_gpio();

    cout << "GPIO pin exported" << endl;

    gpio18->setdir_gpio("out");

    cout << "Set GPIO pin direction" << endl;

    while(1) {
        cout << "Set GPIO value to 1" << endl;
        gpio18->setval_gpio("1");
        usleep(500000);
        cout << "Set GPIO value to 0" << endl;
        gpio18->setval_gpio("0");
        usleep(500000);

        if(ctrl_c_pressed) {
            cout << "Ctrl^C Pressed" << endl;
            cout << "unexporting pins" << endl;
            gpio18->unexport_gpio();
            cout << "deallocating GPIO Objects" << endl;
            delete gpio18;
            gpio18 = 0;
            break;

        }
    }

    cout << "Exiting..." << endl;
    return 0;
}

void sig_handler(int sig) {
    cout << "nCtrl^C pressed in sig handlern" << endl;
    ctrl_c_pressed = true;
}

