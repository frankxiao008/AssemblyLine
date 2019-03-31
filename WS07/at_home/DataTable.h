// Workshop 7 - STL Algorithms
// DataTable.h
// write by Saihong Xiao  140777178
// updated by Chris Szalwinski 
// 2019/03/19


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

			while (file.good()) {

				T x, y;
				file >> x >> y;
				std::pair<T, T> temp = std::make_pair(x, y);
				dot.push_back(temp);
			}
			file.close();
		}
		


	

		T mean() const {
			T ysum = 0.0;
			for (const auto& i: dot)
			{
				ysum += i.second;
			}
			

			T ymean = ysum / dot.size();
			return ymean;
		}

		T sigma() const {
			T ymean = mean();
			T value(0.0);
			
			for (const auto& i: dot ) {
				value += (i.second - ymean)* (i.second - ymean);
			}
			value = sqrt(value / (dot.size() - 1));
			return value;
		}
	T median()const {
			std::vector<T> y = { };
			for (const auto& i : dot)
				y.push_back(i.second);
			sort(y.begin(), y.end());
			return y[y.size() / 2];
		}

	
		T slope() const {
			T xsum = std::accumulate(dot.begin(), dot.end(), static_cast<T>(0), [](auto& init, auto& p) {return init + p.first; });
			T ysum = std::accumulate(dot.begin(), dot.end(), static_cast<T>(0), [](auto& init, auto& p) {return init + p.second; });
			T xy_inner = std::inner_product(dot.begin(), dot.end(), dot.begin(), static_cast<T>(0),
							std::plus<T>(), [](auto&a, auto&b) { return a.first * b.second; });

			T xSuqareSum = std::accumulate(dot.begin(), dot.end(), static_cast<T>(0), 
				[](auto& init, auto&p) {return init + p.first * p.first; });


			T numerator = dot.size()* xy_inner - xsum * ysum;
			T denominator = dot.size() * xSuqareSum - xsum * xsum;

			T s = numerator / denominator;
			
			return s;
		}
	
		T y_intercept() const {
			T ysum = std::accumulate(dot.begin(), dot.end(), static_cast<T>(0), [](auto& init, auto& p) {return init + p.second; });
			T xsum = std::accumulate(dot.begin(), dot.end(), static_cast<T>(0), [](auto& init, auto& p) {return init + p.first; });

			T intercept = (ysum - slope()*xsum) / dot.size();
			return intercept;

		}
		
		void displayData(std::ostream& os)const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			for (const auto& i : dot) {

				os <<fixed<< std::setprecision(ND) << std::setw(FW) << i.first;
				os << std::setw(FW) << i.second << std::endl;

			}
			
			
		}

	
		void displayStatistics(std::ostream& os)const {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << std::setprecision(ND);
			os << std::setw(FW)<<std::left << "y mean" <<" = "<< std::setw(FW) << mean() << std::endl;
			os << std::setw(FW) << "y sigma" << " = " << std::setw(FW) << sigma() << std::endl;
			os << std::setw(FW) << std::left << "y median" << " = " << std::setw(FW) << median() << std::endl;
			os << std::setw(FW) << "slope" << " = " << std::setw(FW) << slope() << std::endl;
			os << std::setw(FW) << "intercept" << " = " << std::setw(FW) << y_intercept() << std::endl;

		}

	    
	};//end of the class
}

#endif
