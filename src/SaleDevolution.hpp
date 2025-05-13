// SaleDevolution.hpp

#pragma once
#include "StockOperation.hpp"

class SaleDevolution : public StockOperation {
    public:
        SaleDevolution(const std::string& item_id, int quantity);

        std::string get_type() const override;
        FileStatus apply(Item& item) const override;
};