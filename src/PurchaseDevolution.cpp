#include "PurchaseDevolution.hpp"

PurchaseDevolution::PurchaseDevolution(const std::string& item_id, const int quantity) 
    : StockOperation(item_id, quantity) {}

std::string PurchaseDevolution::get_type() const { return "Purchase Devolution"; }
FileStatus PurchaseDevolution::apply(Item& item) const {
    int result = item.get_stock() - get_quantity();
    if (result > 0) {
        item.set_stock(result);
        return FileStatus::OK;
    }
    else {
        return FileStatus::INSUFFICIENT_STOCK;
    }
}
