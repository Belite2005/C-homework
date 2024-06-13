#include <iostream>
using namespace std;

namespace CustomNamespace {
    void printMessage() {
        cout << "Inside CustomNamespace" << endl;
    }
}

void printMessage() {
    cout << "Inside global scope" << endl;
}

int main() {
    printMessage();
    CustomNamespace::printMessage();
    
    return 0;
}

