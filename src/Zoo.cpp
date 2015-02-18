#include "Zoo.h"

Zoo::Zoo(std::string fileName){
	if (!texture_.loadFromFile(fileName)){
		throw std::runtime_error("file not found");
	}
	setTexture(texture_);
	setOrigin(0.f,0.f);	
}

