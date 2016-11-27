#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Starting Central server…" << endl;

    while(1) {
        usleep(500000);
        cout << "loop" << endl;
    }

    cout << "Ending Central server…" << endl;
    return 0;
}

