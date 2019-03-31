// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#ifndef _SICT_TAXABLEPRODUCT_H
#define _SICT_TAXABLEPRODUCT_H
#include "Product.h"

namespace sict {
	const double HST = 0.13;
	const double PST = 0.08;
	class TaxableProduct : public Product {
		char taxStatus;
	public:
		TaxableProduct(int num, double cost, char status);
		double price() const;
		void display(std::ostream& os) const;
	};
	iProduct* readRecord(std::ifstream& file);
}

#endif