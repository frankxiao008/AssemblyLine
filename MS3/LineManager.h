// Assembly Line Project
// LinManager.h
// Saihong Xiao   140777178
// 2019/03/28

#ifndef SICT_LM_H
#define SICT_LM_H

#include <iostream>
#include <vector>
#include <deque>
#include "Station.h"
//#include "CustomerOrder.h"

namespace sict {
	class LineManager {
		
		std::deque<sict::CustomerOrder> Orderstobefill;
		std::deque<sict::CustomerOrder> Completed;
		std::deque<sict::CustomerOrder> InCompleted;
		size_t Start;
		size_t Last;
		std::vector<Station*> sta;  
		std::vector<size_t> NextStation;

	public:
		LineManager();
		LineManager(std::vector<Station*>& s, std::vector<size_t>& nextstation, 
			std::vector<CustomerOrder>& orders, size_t firststation, std::ostream& os);
		void display( std::ostream& os )const;
		bool run(std::ostream& os);

	};

}

#endif // !SICT_LM_H
