// https://leetcode.com/problems/design-parking-system/

class ParkingSystem
{
public:
    int *mapping;
    ParkingSystem(int big, int medium, int small)
    {
        mapping = new int[3];
        mapping[0] = big;
        mapping[1] = medium;
        mapping[2] = small;
    }

    bool addCar(int carType)
    {
        if (mapping[carType - 1] == 0)
            return false;
        mapping[carType - 1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */