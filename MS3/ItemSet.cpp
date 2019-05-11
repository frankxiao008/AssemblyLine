// Assembly Line Project
// ItemSet.cpp
// Saihong Xiao   140777178
// 2019/03/08

#include <iostream>
#include <iomanip>
#include <string>
#include "itemSet.h"
#include "Utilities.h"

namespace sict {
	size_t ItemSet::fieldwidth = 0u;
	ItemSet::ItemSet(const std::string& str) {
		size_t post=0u;
		Utilities utilities;
		if (!str.empty()) {

			Name = utilities.extractToken(str, post);

			if (fieldwidth < Name.length())
					fieldwidth = Name.length();
		

		
			std::string temp = utilities.extractToken(str, post);
			SerialNumber = std::stoi(temp);

	
			temp= utilities.extractToken(str, post);
			Quantity = std::stoi(temp);


			description= utilities.extractToken(str, post);
		}
	}

	ItemSet::ItemSet(): Name(), SerialNumber(0), Quantity(0), description(){
	}


	const std::string& ItemSet::getName() const {
		return Name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return SerialNumber;
	}

	const unsigned int ItemSet::getQuantity() const {
		return Quantity;
	}

	ItemSet& ItemSet::operator--() {
		if (Quantity >0) {
			Quantity--;
			SerialNumber++;
		}
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		
			os.setf(std::ios::left);
			os <<std::setw(fieldwidth)<<std::setfill(' ') << Name;
			os << " [" << std::setfill('0') << std::setw(5) <<std::right<< SerialNumber << "] " <<std::setfill(' ');
			if (full) {
				os << "Quantity " <<std::setfill(' ')<< std::setw(3)<<std::left << Quantity;
				os << " Description: " << description << std::endl;

			}
		
	}

}