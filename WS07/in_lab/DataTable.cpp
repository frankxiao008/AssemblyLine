
#include <fstream>
#include "DataTable.h"

namespace sict {
	
	DataTable::DataTable(const char* file) {
		
		std::ifstream fs(file, std::ifstream::in);
		if (!fs) {
			std::cout << "Fail to open the file" << std::endl;
		}
		else {
			while (fs) {
				T fisrt, T second;
				fs >> first >> second;
				std::make_pair(first, second);
			}
		}

		while (ifs.good()) {
			std::cout << c;
			c = ifs.get();
		}
	}
	void DataTable::displayData(std::ostream& os)const {

	}
	void DataTable::displayStatistics(std::ostream& os)const {

	}
}