// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#ifndef _SICT_IPRODUCT_H
#define _SICT_IPRODUCT_H
#include <iostream>
#include <fstream>

namespace sict {
	//Define a abstract class
	class iProduct {
	public:
		//virtual function price and display
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};
	//Global function
	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	//Read a record from the file
	iProduct* readRecord(std::ifstream& file);
}

#endif