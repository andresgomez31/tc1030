// StockOperation.cpp

#include "StockOperation.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>

StockOperation::StockOperation() : item_id(""), quantity(0), date("") {}

StockOperation::StockOperation(std::string item_id, int quantity) : item_id(item_id), quantity(quantity) {
    set_date();
}

// Getters 
std::string StockOperation::get_item_id() const { return item_id; }
int StockOperation::get_quantity() const { return quantity; }
std::string StockOperation::get_date() const { return date; }

// Setters
void StockOperation::set_date() {
    std::time_t now = std::time(nullptr);
    std::tm* tm_ptr = std::localtime(&now);

    std::ostringstream oss;
    oss << std::put_time(tm_ptr, "%Y-%m-%dT%H:%M:%S");
    this -> date = oss.str();
}