// Purchase.hpp

#pragma once
#include "StockOperation.hpp"

class Purchase : public StockOperation {
    public:
        Purchase(const std::string& item_id, int quantity);

        std::string get_type() const override;
        FileStatus apply(Item& item) const override;
};