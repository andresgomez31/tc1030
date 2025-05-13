// PurchaseDevolution.hpp

#pragma once
#include "StockOperation.hpp"

class PurchaseDevolution : public StockOperation {
    public:
        PurchaseDevolution(const std::string& item_id, int quantity);

        std::string get_type() const override;
        FileStatus apply(Item& item) const override;
};