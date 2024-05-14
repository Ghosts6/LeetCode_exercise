#include <iostream>

class ParkingSystem {
private:
    int bigSlots;
    int mediumSlots;
    int smallSlots;
public:
    ParkingSystem(int big, int medium, int small) {
        bigSlots = big;
        mediumSlots = medium;
        smallSlots = small;
    }
    bool addCar(int carType) {
        switch(carType) {
            case 1:
                if (bigSlots > 0) {
                    bigSlots--;
                    return true;
                }
                break;
            case 2:
                if (mediumSlots > 0) {
                    mediumSlots--;
                    return true;
                }
                break;
            case 3:
                if (smallSlots > 0) {
                    smallSlots--;
                    return true;
                }
                break;
        }
        return false;
    }
};
// test case
int main() {
    ParkingSystem parking(1, 1, 0);
    std::cout << "Adding car of type 1: " << (parking.addCar(1) ? "Success" : "Failed") << std::endl;
    std::cout << "Adding car of type 2: " << (parking.addCar(2) ? "Success" : "Failed") << std::endl;
    std::cout << "Adding car of type 3: " << (parking.addCar(3) ? "Success" : "Failed") << std::endl; 
    return 0;
}
