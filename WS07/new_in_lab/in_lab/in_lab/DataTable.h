


#ifndef SICT_DATATABLE_H
#define SICT_DATATABLE_H
#include <utility>  
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
		DataTable(std::ifstream& file) {
			
			if (file.good()) {
			
					T x, y;
					fs >> x >> y;
					std::pair<T, T> temp = std::make_pair(x, y);
					dot.push_back(temp);
				}
			}
		file.close();

		
		}

		T mean()const {
			T ysum = 0.0;
			for (int i=0; i< dot.size(); i++)
			{
				ysum += (*i).second;
			}
			

			T ymaen = ysum / dot.size();
			return ymean;
		}

		T sigma() const {
			T ymean = mean();
			T value;
			
			for (int i=0; i< dot.size(); i++) {
				value += ((*i).second - mean)* (i->second - mean);
			}
			value = sqrt(value / (dot.size() - 1));
			return value;
		}

		void displayData(std::ostream& os)const { 
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			for(int i=0; i <= dot.size(); i++ )
			{
				os << std::setprecision(ND) << std::setw(FW) << std::get<0>(dot[i]);
				os << std::setw(FW) << std::get<1>(dot[i]) << std::endl;

			}
			
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
