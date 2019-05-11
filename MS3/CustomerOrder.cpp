// Assembly Line Project
// CustomerOrder.h
// Saihong Xiao   140777178
// 2019/03/15

#include <string>
#include <iomanip>
#include "Utilities.h"
#include "ItemSet.h"
#include"CustomerOrder.h"

namespace sict {

	size_t CustomerOrder::fieldwidth=0u;

	CustomerOrder::CustomerOrder() {
		Name = "No valid name";
		std::string Product = "No valid information";
		itemNumber = 0u;
	}

	CustomerOrder::CustomerOrder(const std::string& str) {
		try {
		size_t post = 0u;
		Utilities utilities;
		int count = 0;
		if (!str.empty()) {
		

				Name = utilities.extractToken(str, post);
				count++;
				if (fieldwidth < utilities.getFieldWidth())
					fieldwidth = utilities.getFieldWidth();
				if (post != std::string::npos) {
					Product = utilities.extractToken(str, post);
					count++;
				}
				std::vector<std::string> itemVector;
				while (post != std::string::npos && post < str.length() ) {
					std::string temp = utilities.extractToken(str, post);
					 itemVector.push_back(temp);
					 count++;
				}
			

			if (count < 3) {
				*this = CustomerOrder();
				throw "Not a valid order, no item required.";
			}
			else {
				itemNumber = itemVector.size();
				iteminfo = new itemiDetail[itemVector.size()];
				std::vector<std::string>::iterator i;
				int j = 0;
				for (i = itemVector.begin(); i != itemVector.end(); i++) {
					iteminfo[j].itemName = *i;
					iteminfo[j].SerialNumber = 0;
					iteminfo[j].fill = false;
					j++;
				}

			}
		
		}
		}
		catch (const std::string& msg) {
			std::cerr << msg << std::endl;
		}

	}

	CustomerOrder::~CustomerOrder() {
		delete[] iteminfo;
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (size_t i = 0; i < itemNumber; i++) {
			if (iteminfo[i].itemName == item.getName()) {
				if (item.getQuantity() < 1) {
					//iteminfo[i].SerialNumber = item.getSerialNumber();
					os << " Unable to fill " << this->Name << "[" << this->getNameProduct() << "]["
						<< iteminfo[i].itemName << "][" << iteminfo[i].SerialNumber << "]" << " out of stock" <<std::endl;
				}
				else if (iteminfo[i].fill) {
					//iteminfo[i].SerialNumber = item.getSerialNumber();
					os << " Unable to fill " << this->Name << "[" << this->getNameProduct() << "]["
						<< iteminfo[i].itemName << "][" << iteminfo[i].SerialNumber << "]" << " already filled" <<std::endl;
				}
				else {
					iteminfo[i].fill = true;
				
					iteminfo[i].SerialNumber = item.getSerialNumber();
					--item;
					os << " Filled " << this->Name << "[" << this->getNameProduct() << "]["
						<< iteminfo[i].itemName << "][" << iteminfo[i].SerialNumber << "]" << std::endl;

				}
			}


		}

	}
	bool CustomerOrder::isFilled() const {
		bool fill = true;
		for (size_t i = 0; i < itemNumber; i++) {
			if (!iteminfo[i].fill)
				fill = false;
		}
		return fill;
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const {
		bool itemfilled = true;
		for (size_t i = 0; i < itemNumber; i++)
			if (iteminfo[i].itemName == item && !iteminfo[i].fill)
				itemfilled = false;
		return itemfilled;
	}

	std::string CustomerOrder::getNameProduct() const {
		return  Name +" [" + Product + "]";
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {

		os << std::setw(CustomerOrder::fieldwidth)<< Name;
		os << "["<< Product << "]" <<std::endl;
		if (showDetail) {		
			for (size_t i = 0; i < itemNumber; i++) {
				std::string status = (iteminfo[i].fill) ? "Filled" : "MISSING";
				os << std::setw(CustomerOrder::fieldwidth) << " "
					<< "[" << iteminfo[i].SerialNumber << "] " << iteminfo[i].itemName
					<< " - " <<status << std::endl;				
			}
		}else {
			for (size_t i = 0; i < itemNumber; i++)
				os << std::setw(CustomerOrder::fieldwidth) << " " << iteminfo[i].itemName << std::endl;
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& order) {
		*this = std::move(order);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
		if (this != &src) {
			Name = src.Name;
			Product = src.Product;
			itemNumber = src.itemNumber;
			delete[] iteminfo;
			iteminfo = src.iteminfo;

			src.Name.clear();
			src.Product.clear();
			src.iteminfo = nullptr;
			src.itemNumber = 0;
		}
		return *this;
	}
}