// Assembly Line Project
// CustomerOrder.h
// Saihong Xiao   140777178
// 2019/03/08
#pragma once
#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDRE_H
#include<string>
#include <vector>
#include <iostream>
#include "ItemSet.h"

namespace sict {
	class CustomerOrder {
		std::string Name = "";
		std::string Product = "";	
		struct itemiDetail {
			std::string itemName;
			unsigned int SerialNumber;
			bool fill= false;
		} * iteminfo = nullptr ;
		size_t itemNumber;
		static size_t fieldwidth;

	
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail= false) const;	
		CustomerOrder(CustomerOrder&& order);
		CustomerOrder& operator=(CustomerOrder&& src);
		CustomerOrder(CustomerOrder& order)= delete;
		CustomerOrder& operator=(CustomerOrder& src) = delete;
	};

}




#endif