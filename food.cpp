#include "Food.h"
#include <string>
using namespace std;

#include <iomanip> // Formatting
#include <sstream> // For formatting

std::string formatDouble(double value) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2) << value;
    return out.str();
}


Food::Food(string _name, double _calories, double _carbs, double _proteins, double _fats){
    name = _name;
    calories = _calories;
    carbs = _carbs;
    proteins = _proteins;
    fats = _fats;
}

//Setters and getters
void Food::setGroup(string _group){
    group = _group;
    
}
string Food::getName(){
    return name;
};

double Food::getCalories(){
    return calories;
}; 
double Food::getCarbs(){
    return carbs;
}; 
double Food::getProteins(){
    return proteins;
};
double Food::getFats(){
    return fats;
};
double Food::getPortionSize(){
    return portionSize;
};
string Food::getGroup(){
    return group;
};    


//Methods
double Food::portion()
{
    // Dependiendo del grupo, calcula los gramos//
    return portionSize; // Placeholder return
}




std::string Food::showFood(){
    std::string message = getName() + " has:\n " + " " + formatDouble(getCalories())+" calories \n"+ " " +formatDouble(getProteins()) + " proteins\n" + " " +formatDouble(getCarbs()) + " carbs\n" + " " +formatDouble(getFats()) +" fats";
    return message; //Regresa la lista de la información nutricional ingresada del alimento
}

int Food::defineGroup() {
    carbs = getCarbs();
    fats = getFats();
    proteins = getProteins();

    double values[3]={carbs, fats, proteins};
    string groups[3]={"Carb", "Protein", "Fat"};

    string fgroup = "blablabla";
    double largest = values[0];

    for (int i = 0; i <= 3; ++i) {
        if (values[i] >= largest) {
            largest = values[i];
            fgroup=groups[i];
        };
    };
    Food::setGroup(fgroup);
    return 0;
}