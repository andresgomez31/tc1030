// StockOperation.cpp

#include "StockOperation.hpp"

StockOperation::StockOperation() : item_id(""), quantity(0), date("") {}

StockOperation::StockOperation(std::string item_id, int quantity) : item_id(item_id), quantity(quantity) {}

// Getters 
std::string StockOperation::get_item_id() const { return item_id; }
int StockOperation::get_quantity() const { return quantity; }
std::string StockOperation::get_date() const { return date; }