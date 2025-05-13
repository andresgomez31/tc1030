#include "Inventory.hpp"

Inventory::Inventory() {}

Inventory::Inventory(std::map<std::string, Item> items, std::vector<StockOperation*> operations, 
    std::string csv_items_path, std::string csv_operations_path)
    : items(items), operations(operations), 
    csv_items_path(csv_items_path), csv_operations_path(csv_operations_path) {}

std::map<std::string, Item> Inventory::load_items() {

}
FileStatus Inventory::save_items() {

}
FileStatus Inventory::add_item() {

}
FileStatus Inventory::remove_item() {

}
FileStatus Inventory::apply_operation(StockOperation* op) {

}
void show_inventory();