#ifndef __MovingAnimal_H__
#define __MovingAnimal_H__

#include <random>
#include "Direction.h"

class MovingAnimal : public Animal{
	std::mt19937_64 randGenerator;
	std::uniform_int_distribution<int> distribution;
	
private:
	Direction randDirection(){
		return (Direction)distribution(randGenerator);
	}
	
public:
	
	MovingAnimal(std::string path) : Animal(path), randGenerator((unsigned long)this), distribution(0,3){}
	
	virtual void userFunction(){
		move(randDirection());
	}
};

#endif /* __MovingAnimal_H__ */

