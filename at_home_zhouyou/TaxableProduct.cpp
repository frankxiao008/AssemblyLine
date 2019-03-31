// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#include "TaxableProduct.h"

namespace sict {
	//three arguments constructor
	TaxableProduct::TaxableProduct(int num, double cost, char status)
		: Product(num, cost), taxStatus(status) {}

	//Return the price with tax
	double TaxableProduct::price() const {
		return taxStatus == 'H'? Product::price() * (1 + HST) : Product::price() * (1 + PST);
	}
	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		os << " " << (taxStatus == 'H' ? "HST" : "PST");
	}

	//Read a record from the file
	iProduct* readRecord(std::ifstream& file) {
		iProduct *product = nullptr;
		int num;
		double cost;
		char status;
		file >> num >> cost;
		status = file.get();
		if (status == ' ') {
			file >> status;
			if (status == 'H' || status == 'P') {
				TaxableProduct *tempProduct = new TaxableProduct(num, cost, status);
				product = tempProduct;
			}
		}else {
			Product *tempProduct = new Product(num, cost);
			product = tempProduct;
		}

		return product;
	}
}