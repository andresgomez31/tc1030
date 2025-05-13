#include "Sale.hpp"

Sale::Sale(const std::string& item_id, const int quantity) 
    : StockOperation(item_id, quantity) {}

std::string Sale::get_type() const { return "Purchase Devolution"; }
FileStatus Sale::apply(Item& item) const {
    int result = item.get_stock() - get_quantity();
    if (result > 0) {
        item.set_stock(result);
        return FileStatus::OK;
    }
    else {
        return FileStatus::INSUFFICIENT_STOCK;
    }
}
