


#ifndef SICT_DATATABLE_H
#defineSICT_DATATABLE_H

#include <numeric>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
extern int FW; // field width
extern int ND; // precision for numbers

namespace sict {
	template<typename T>
	class DataTable {
		std::vector < std::pair<T, T> > dot;
	
	public:
		DataTable(const char* file) {
			std::ifstream fs(file, std::ifstream::in);
			if (!fs) {
				std::cout << "Fail to open the file" << std::endl;
			}
			else {
				while (fs) {
					T fisrt,  second;
					fs >> first >> second;
					std::pair<T, T> temp = std::make_pair(first, second);
					dot.push_back(std::move(temp));
				}
			}

		
		}

		T mean() {
			T ysum = 0.0;
			for (auto i = dot.begin(), i != dot.end(); i++) {
				ysum += *i.second;
			}
			T ymaen = ysum / dot.size();
			return ymean;
		}

		T sigma() {
			T ymean = mean();
			T value;
			for (auto i = dot.begin(), i != dot.end(); i++) {
				value += (*i.second - mean)* (*i.second - mean);
			}
			value = sqrt(value / (dot.size() - 1));
			return value;
		}

		void displayData(std::ostream& os)const { 
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os <<std::setprecision(ND) << std::setw(FW) <<first <<setw(FW) << std::endl;
			
		}
		void displayStatistics(std::ostream& os)const {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << std::setprecision(ND);
			os << std::setw(FW) << "y mean" << std::setw(FW) << mean() << std::endl;
			os << std::setw(FW) << "y sigma" << std::setw(FW) << sigma() << std::endl;

				


		}
	};
}

#endif
