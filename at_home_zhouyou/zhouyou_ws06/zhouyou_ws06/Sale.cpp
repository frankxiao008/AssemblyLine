// *****************************
// Name: You Zhou
// ID : 125838177
// Mail : yzhou213@myseneca.ca
// Purpose : Workshop 6 OOP345
// *****************************
#include "Sale.h"
#include <iomanip>

using namespace std;

namespace sict {
	//one argument constructor that moves the record to an vector
	Sale::Sale(const char* filename) {
		ifstream fs(filename, ios::out);
		if (!fs) {
			cout << "The file cannot open" << filename << endl;
		}else {
			while (fs) {
				products.push_back(readRecord(fs));
			}
		}
	}

	//Print
	void Sale::display(ostream& os) const {
		double total = 0;
		os << "Product No      Cost Taxable" << endl;
		for (size_t i = 0; i < products.size() - 1; i++) {
			products[i]->display(os);
			total += products[i]->price();
			os << endl;
		}
		os << "     Total" << setw(10) << total << endl;
	}
}