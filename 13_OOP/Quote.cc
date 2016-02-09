#include <string>

class Quote {
public:
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;
};

class Bulk_quote : public Quote {
public:
	double net_price(std::size_t) const override;
};
