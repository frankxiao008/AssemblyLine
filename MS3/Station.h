// Assembly Line Project
// Station.h
// Saihong Xiao   140777178
// 2019/03/28
#ifndef SICT_STATION_H
#define SICT_STATION_H
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
	

	class Station {
		std::deque<CustomerOrder> orders;
		ItemSet* itemptr;
	public:
		Station();
		Station(const std::string& s);
		~Station();
		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os);
		Station(Station& s)= delete;
		Station(Station&& s) = delete;
		Station& operator=(Station& s)=delete;
		Station& operator=(Station&& s) = delete;
		bool stationempty();

	};
}
#endif // !SICT_STATION_H

