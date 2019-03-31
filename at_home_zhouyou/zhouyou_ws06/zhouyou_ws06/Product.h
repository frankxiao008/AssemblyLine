// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#ifndef _SICT_PRODUCT_H
#define _SICT_PRODUCT_H
#include "iProduct.h"

namespace sict {
	class Product : public iProduct {
		int p_num;
		double p_cost;
	public:
		//two argument constructor that receives and stores the product number and price
		Product(int num, double cost);
		double price() const;
		void display(std::ostream& os) const;
	};
}

#endif