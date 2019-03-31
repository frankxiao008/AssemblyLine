// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#include "Product.h"
#include <iomanip>

namespace sict {
	//two argument constructor that receives and stores the product number and price
	Product::Product(int num, double cost) : p_num(num > 0 ? num : 0), p_cost(cost >= 0 ? cost : 0) {}

	//Return the price
	double Product::price() const { return p_cost; }

	//Print
	void Product::display(std::ostream& os)const {
		os << std::right << std::fixed << std::setw(10) << p_num;
		os << std::right << std::fixed << std::setw(10) << std::setprecision(2) << Product::price();
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}
}