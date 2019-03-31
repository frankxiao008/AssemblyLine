// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#ifndef _SICT_SALE_H
#define _SICT_SALE_H
#include <vector>
#include "Product.h"
#include "TaxableProduct.h"

namespace sict {
	class Sale {
		std::vector <sict::iProduct* > products;
	public:
		//one argument constructor that moves the record to an vector
		Sale(const char* filename);
		void display(std::ostream& os) const;
	};
}

#endif