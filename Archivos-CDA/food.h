#include <iostream>
using namespace std;

class Food {
private:
    std::string name;
    double calories;
    double carbs;
    double proteins;
    double fats;
    double portionSize;
    std::string group; // what group does the food belongs to

public:
    // Constructor
    Food(const std::string& name, double weight, double height, double calories, const std::string& state, const std::array<double, 3>& split);

    // Methods
    void portionGrams();
    void group();
    void showValues();
};