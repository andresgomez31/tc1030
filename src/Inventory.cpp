// Inventory.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "Inventory.hpp"
#include "Sale.hpp"
#include "SaleDevolution.hpp"
#include "Purchase.hpp"
#include "PurchaseDevolution.hpp"

Inventory::Inventory() {}

Inventory::Inventory(std::string csv_items_path, std::string csv_operations_path)
    : csv_items_path(csv_items_path), csv_operations_path(csv_operations_path) {
        load_items();
        load_operations();
    }

// Getters
std::map<std::string, Item> Inventory::get_items() const { return items; }
Item Inventory::get_item(std::string id) const {
    auto it = items.find(id);
    if (it != items.end()) {
        return it->second;
    }
    throw std::invalid_argument("Item ID not found: " + id);
}

std::vector<StockOperation*> Inventory::get_operations() const { return operations; }
std::string Inventory::get_csv_items_path() const { return csv_items_path; }
std::string Inventory::get_csv_operations_path() const { return csv_operations_path; }

// Setters
void Inventory::set_items(std::map<std::string, Item> items) { this -> items = items; }
void Inventory::set_operations(std::vector<StockOperation*> operations) { this -> operations = operations; }
void Inventory::set_csv_items_path(std::string filepath) { this -> csv_items_path = filepath; }
void Inventory::set_csv_operations_path(std::string filepath) { this -> csv_operations_path = filepath; }  

FileStatus Inventory::load_items() {
    std::map<std::string, Item> items;
    std::ifstream file(csv_items_path);
    std::string line;

    if (!file.is_open()) {
        return FileStatus::OPEN_ERROR;
    }

    std::getline(file, line);

    int line_number = 1;
    while (std::getline(file, line)) {
        line_number++;
        std::stringstream ss(line);
        std::string id, name, category, stock_str, price_str, cost_str;

        if (!std::getline(ss, id, ',')) continue;
        if (!std::getline(ss, name, ',')) continue;
        if (!std::getline(ss, category, ',')) continue;
        if (!std::getline(ss, stock_str, ',')) continue;
        if (!std::getline(ss, price_str, ',')) continue;
        if (!std::getline(ss, cost_str, ',')) continue;

        try {
            int stock = std::stoi(stock_str);
            float price = std::stof(price_str);
            float cost = std::stof(cost_str);

            Item item(id, name, category, stock, price, cost);
            items[item.get_id()] = item;
        } catch (const std::exception& e) {
            std::cerr << "Error in line " << line_number
                        << ": invalid conversion -> " << e.what() << "\n";
            continue;
        }
    }

    set_items(items);
    return FileStatus::OK;
}

FileStatus Inventory::load_operations() {
    std::vector<StockOperation*> ops;
    std::ifstream file(csv_operations_path);
    std::string line;

    if (!file.is_open()) return FileStatus::OPEN_ERROR;
    
    std::getline(file, line); // skip header
    int line_number = 1;

    while (std::getline(file, line)) {
        line_number++;
        std::stringstream ss(line);
        std::string type, id, quantity_str, date;

        if (!std::getline(ss, type, ',')) continue;
        if (!std::getline(ss, id, ',')) continue;
        if (!std::getline(ss, quantity_str, ',')) continue;
        if (!std::getline(ss, date, ',')) continue;

        try {
            int quantity = std::stoi(quantity_str);
            StockOperation* op;

            if (type == "Sale") {
                op = new Sale(id, quantity);
            }
            else if (type == "Sale Devolution") {
                op = new SaleDevolution(id, quantity);
            }
            else if (type == "Purchase") {
                op = new Purchase(id, quantity);
            }
            else if (type == "Purchase Devolution") {
                op = new PurchaseDevolution(id, quantity);
            }
            else {
                std::cerr << "Unknown type on line " << line_number << ": " << type << "\n";
                continue;
            }
            ops.push_back(op);

        } catch (const std::exception& e) {
            std::cerr << "Error in line " << line_number << ": " << e.what() << "\n";
            continue;
        }
    }
    set_operations(ops);
    return FileStatus::OK;
}

FileStatus Inventory::save_items() {
    std::ofstream file(csv_items_path);

    // CSV Header
    file << "id,name,category,stock,price,cost\n";

    for (const auto& pair : items) {
        const std::string& key = pair.first;
        const Item& value = pair.second;

        file << value.get_id() << ","
             << value.get_name() << ","
             << value.get_category() << ","
             << value.get_stock() << ","
             << value.get_price() << ","
             << value.get_cost() << "\n";
    }
    return FileStatus::OK;
}
FileStatus Inventory::save_operations() {
    std::ofstream file(csv_operations_path);

    file << "type,item_id,quantity,date\n";
    
    for (const auto& op : operations) {
        file << op->get_type() << ","
             << op->get_item_id() << ","
             << op->get_quantity() << ","
             << op->get_date() << "\n";
    }
    return FileStatus::OK;
}

FileStatus Inventory::add_item(Item item) {
    if (items.count(item.get_id()) > 0) return FileStatus::ALREADY_EXISTS;
    items[item.get_id()] = item;
    return FileStatus::OK;
}

FileStatus Inventory::remove_item(std::string id) {
    if (items.erase(id) == 0) return FileStatus::NOT_FOUND;
    return FileStatus::OK;
}

FileStatus Inventory::apply_operation(StockOperation* op, Item& item) {
    return op->apply(item);
}
void Inventory::show_inventory() {
    for (const auto& pair : items) {
        std::cout << pair.second << "\n";
    }
}


Inventory::~Inventory() {
    for (StockOperation* op : operations) {
        delete op;
    }
    operations.clear();
}
