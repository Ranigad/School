#ifndef FOOD_H
#define FOOD_H

#include <string>

/***************************************************************************
 * Food Class                                                              *
 *                                                                         *
 * Each instance of the class comprises of a food name, its type and a     *
 * sub type. Class methods are further explained in food.cpp               *
 ***************************************************************************/

class Food {
	private:
	std::string name;
	std::string typeFood;
	std::string subTypeFood;
	
	public:
	Food(std::string=" ", std::string=" ", std::string=" ");
	void setFood(std::string=" ", std::string=" ", std::string=" ");
	void showFood();
	std::string showName();
	std::string showTypeFood();
	std::string showSubTypeFood();
};

#endif


