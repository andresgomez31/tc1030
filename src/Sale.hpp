// Sale.hpp

#pragma once
#include "StockOperation.hpp"

class Sale : public StockOperation {
    public:
        Sale(const std::string& item_id, int quantity);

        std::string get_type() const override;
        FileStatus apply(Item& item) const override;
};