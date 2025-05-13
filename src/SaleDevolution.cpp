#include "SaleDevolution.hpp"

SaleDevolution::SaleDevolution(const std::string& item_id, int quantity)
    : StockOperation(item_id, quantity) {}

std::string get_type() { return "Purchase"; }

FileStatus SaleDevolution::apply(Item& item) const {
    item.set_stock(item.get_stock() + get_quantity());
    return FileStatus::OK;
}
