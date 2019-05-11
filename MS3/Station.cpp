// Assembly Line Project
// Station.cpp
// Saihong Xiao   140777178
// 2019/03/28

#include "Station.h"

namespace sict {
	Station::Station():itemptr(nullptr){}

	Station::Station(const std::string& s) {
		itemptr = new ItemSet(s);
	}

	Station::~Station() { delete itemptr;  }

	void Station::display(std::ostream& os) const {
		if (itemptr)
			itemptr->display(os, false);
	}

	void Station::fill(std::ostream& os) {
		if (!orders.empty() ) {
			
			orders.back().fillItem(*itemptr, os);
		}

	}
	const std::string& Station::getName() const {
		return itemptr->getName();
	}
	bool Station::hasAnOrderToRelease() const {
		bool state=false;
		if (!orders.empty()) {
			if (orders.front().isItemFilled(itemptr->getName()) || itemptr->getQuantity() == 0)
				state = true;
		}
		else {
			state = false;
		}
		return state;
	}
	Station& Station::operator--() {
		--(*itemptr);
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		orders.push_back(std::move(order));
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool state;
		if (!orders.empty()) {
			ready = std::move(orders.front());
			orders.pop_front();
			if (hasAnOrderToRelease())
				state = true;
			else
				state = false;
		}
		else {

			state = false;
		}
		return state;
	}
	void Station::validate(std::ostream& os) {
		os << "getName(): " << itemptr->getName() << std::endl;
		os << "getSerialNumber(): " << itemptr->getSerialNumber() << std::endl;
		os << "getQuantity(): " << itemptr->getQuantity() << std::endl;
	}
	bool Station::stationempty() {
		if (!orders.empty())
			return false;
		else
			return true;
	}
}


