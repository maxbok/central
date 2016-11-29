#ifndef GPIO_H
#define GPIO_H

#include <string>
using namespace std;
/* GPIO
 * Purpose: Each object instantiated from this class will control a GPIO pin
 * The GPIO pin number must be passed to the overloaded class constructor
 */

class GPIO {
public:
    GPIO();  // create a GPIO object that controls GPIO4 (default)
    GPIO(string x); // create a GPIO object that controls GPIOx, where x is passed to this constructor
    int export_gpio(); // exports GPIO
    int unexport_gpio(); // unexport GPIO
    int setdir_gpio(string dir); // Set GPIO Direction
    int setval_gpio(string val); // Set GPIO Value (putput pins)
    int getval_gpio(string& val); // Get GPIO Value (input/ output pins)
    string get_gpio_num(); // return the GPIO number associated with the instance of an object
private:
    string gpio_num; // GPIO number associated with the instance of an object
};

#endif

