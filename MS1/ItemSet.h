// Assembly Line Project
// ItemSet.h
// Saihong Xiao   140777178
// 2019/03/08

#ifndef SICT_ITEM_H
#define SICT_ITEM_H

namespace sict {

	class ItemSet {
		std::string Name="";
		unsigned int SerialNumber{0u};
		unsigned int Quantity{0u};
		std::string description;
		static size_t fieldwidth;
	public:
		ItemSet();
		ItemSet(const std::string& str);
		const std::string& getName() const;
		const unsigned int getSerialNumber()const;
		const unsigned int getQuantity()const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};

}
#endif
