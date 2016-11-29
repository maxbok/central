#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GPIO.h"

using namespace std;

GPIO::GPIO() {
    this->gpio_num = "18"; //GPIO18 is default
}

GPIO::GPIO(string gnum) {
    this->gpio_num = gnum;  //Instatiate GPIO object for GPIO pin number "gnum"
}

int GPIO::export_gpio() {
    string export_str = "/sys/class/gpio/export";
    ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    if (exportgpio < 0){
        cout << " OPERATION FAILED: Unable to export GPIO"<< this->gpio_num <<" ."<< endl;
        return -1;
    }

    exportgpio << this->gpio_num ; //write GPIO number to export
    exportgpio.close(); //close export file
    return 0;
}

int GPIO::unexport_gpio() {
    string unexport_str = "/sys/class/gpio/unexport";
    ofstream unexportgpio(unexport_str.c_str()); //Open unexport file
    if (unexportgpio < 0){
        cout << " OPERATION FAILED: Unable to unexport GPIO"<< this->gpio_num <<" ."<< endl;
        return -1;
    }

    unexportgpio << this->gpio_num ; //write GPIO number to unexport
    unexportgpio.close(); //close unexport file
    return 0;
}

int GPIO::setdir_gpio(string dir) {
    string setdir_str ="/sys/class/gpio/gpio" + this->gpio_num + "/direction";
    ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
        if (setdirgpio < 0){
            cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpio_num <<" ."<< endl;
            return -1;
        }

        setdirgpio << dir; //write direction to direction file
        setdirgpio.close(); // close direction file
        return 0;
}

int GPIO::setval_gpio(string val) {
    string setval_str = "/sys/class/gpio/gpio" + this->gpio_num + "/value";
    ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
        if (setvalgpio < 0){
            cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpio_num <<" ."<< endl;
            return -1;
        }

        setvalgpio << val ;//write value to value file
        setvalgpio.close();// close value file
        return 0;
}

int GPIO::getval_gpio(string& val) {
    string getval_str = "/sys/class/gpio/gpio" + this->gpio_num + "/value";
    ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    if (getvalgpio < 0){
        cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpio_num <<" ."<< endl;
        return -1;
            }

    getvalgpio >> val ;  //read gpio value

    if(val != "0")
        val = "1";
    else
        val = "0";

    getvalgpio.close(); //close the value file
    return 0;
}

string GPIO::get_gpio_num() {
    return this->gpio_num;
}

