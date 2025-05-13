#pragma once
#include <string>
#include <map>
#include <vector>
#include "FileStatus.hpp"
#include "StockOperation.hpp"
#include "Item.hpp"

class Inventory {
    private:
        Inventory();
        Inventory(std::map<std::string, Item> items, std::vector<StockOperation*> operations, 
            std::string csv_items_path, std::string csv_operations_path);

        std::map<std::string, Item> items;
        std::vector<StockOperation*> operations;
        std::string csv_items_path;
        std::string csv_operations_path;

    public:
    std::map<std::string, Item> load_items();
    FileStatus save_items();
    FileStatus add_item();
    FileStatus remove_item();
    FileStatus apply_operation(StockOperation* op);
    void show_inventory();
};