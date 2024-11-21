#include <iostream>

#include "plan.h"
#include "meal.h" //BORRE EL CPP DE MEAL
using namespace std;
#include <string>


Plan::Plan(double planCalories, std::array<double, 3> _split, int _numberOfMeals)
{
    split = _split;
    numberOfMeals = _numberOfMeals;// Sets the number of meals per day, example 5
    meals.resize(numberOfMeals);
}

void Plan::setMacros() { //this comes from the split (in fact, i could've called the split macros)
    
    double total = planCalories;
    double carbPercentage = split[0];
    double proteinPercentage = split[1];
    double fatPercentage = split[2];

    int _fats = (total*fatPercentage)/100;
    int _carbs = (total*carbPercentage)/100;
    int _proteins =(total*proteinPercentage)/100;

    //These are the portions of each macro
    int proteins = _proteins;
    int carbs = _carbs;
    int fats = _fats;
    std::cout<<"Macros portions set succesfully to "<<carbs<<endl;
    // Changes the ammount of proteins
}

int Plan::getCarbs()
{
    return carbs;
}

int Plan::getProteins()
{
    return proteins;
}

int Plan::getFats()
{
    return fats;
}

std::vector<Meal> Plan::setMeals(){ //Distributes the macros found before into the number of meals
    std::vector<Meal> meals;
    int numberOfMeals = numberOfMeals;
    int carbs = getCarbs();
    int proteins = getProteins();
    int fats = getFats();

    int baseCarbs = carbs / numberOfMeals;
    int baseProteins = proteins / numberOfMeals;
    int baseFats = fats / numberOfMeals;

    int extraCarbs = carbs % numberOfMeals;
    int extraProteins = proteins % numberOfMeals;
    int extraFats = fats % numberOfMeals;

    for (int i = 0; i < numberOfMeals; ++i){
        
        int mealCarbs = baseCarbs + (i < extraCarbs ? 1 : 0);
        int mealProteins = baseProteins + (i < extraProteins ? 1 : 0);
        int mealFats = baseFats + (i < extraFats ? 1 : 0);
        meals.emplace_back(mealCarbs, mealProteins, mealFats); //THIS CREATES several objects type MEAL that recieve the INT of the mealCarbs (the portions, then the meal has to be constructed)
    }
    std::cout<<"Meals set correctly "<<endl;
    
    return meals;
}


std::vector<Meal> Plan::getMeals(){
    return meals;
}

void Plan::showPlan(){ //no sale imprimir un vector de meals, recomiendo ir a meal y escribir una funcion de displayMeal
    for (int i = 0; i < meals.size(); ++i) {
    std::cout << meals[i].displayMeal()<<std::endl;
    };
}
