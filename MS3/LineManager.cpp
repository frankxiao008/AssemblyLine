// Assembly Line Project
// LinManager.cpp
// Saihong Xiao   140777178
// 2019/03/28
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "LineManager.h"
#include "AssemblyLine.h"
#include "CustomerOrder.h"


namespace sict {

	LineManager::LineManager() {
		//size_t Last = 0;

	}

	LineManager::LineManager(std::vector<Station*>& s, std::vector<size_t>& nextstation,
		std::vector<CustomerOrder>& orders, size_t first, std::ostream & os)
	{
		for (size_t i = 0; i < orders.size(); i++) {
			Orderstobefill.push_front(std::move(orders[i]));
		}
		sta = std::move(s);
		NextStation = nextstation;
		Start = first;
		Last = std::find(nextstation.begin(), nextstation.end(), 5) - nextstation.begin();


	}

	void LineManager::display(std::ostream& os)const {
		os << "COMPLETED ORDERS" << '\n';
		for (auto& i : Completed)
			i.display(os, true);
		os << "INCOMPLETED ORDERS" << '\n';
		for (auto& i : InCompleted)

			i.display(os, true);
	}

	bool LineManager::run(std::ostream& os) {


		
		CustomerOrder ready;
		if (!Orderstobefill.empty()) {
			*sta[Start] += std::move(Orderstobefill.back());
			Orderstobefill.pop_back();
		}
			for_each(sta.begin(), sta.end(), [&](auto& station) { station->fill(os); });

			for (size_t i = 0; i < sta.size(); i++) {
				if (sta[i]->hasAnOrderToRelease()) {
					if (i != Last) {
						//sta[i]->fill(os);

						sta[i]->pop(ready);
						os << "-- > " << ready.getNameProduct()
							<< " moved from " + sta[i]->getName() << " to " << sta[NextStation[i]]->getName() << std::endl;
						*sta[NextStation[i]] += std::move(ready);

					}
					else {

						//sta[i]->fill(os);
						sta[i]->pop(ready);
						if (ready.isFilled()) {
							os << "-- > " << ready.getNameProduct()
								<< " moved from " + sta[i]->getName() << " to " << " Completed Set " << std::endl;
							Completed.push_back(std::move(ready));
						}
						else {
							os << "-- > " << ready.getNameProduct()
								<< " moved from " + sta[i]->getName() << " to " << " Incomplete Set " << std::endl;
							InCompleted.push_back(std::move(ready));
						}

					}
				}
			}



		bool flag = true;
			for (size_t i = 0; i < sta.size(); i++) {

			if (!sta[i]->stationempty())
				flag = false;

			}
			return flag;

	}
}