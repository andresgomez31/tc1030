// Inventory.hpp

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
        Inventory(std::string csv_items_path, std::string csv_operations_path);

        std::map<std::string, Item> items;
        std::vector<StockOperation*> operations;
        std::string csv_items_path;
        std::string csv_operations_path;

    public:
        std::map<std::string, Item> get_items() const;
        Item get_item(std::string id) const;
        std::vector<StockOperation*> get_operations() const;
        std::string get_csv_items_path() const;
        std::string get_csv_operations_path() const;

        void set_items(std::map<std::string, Item>);
        void set_operations(std::vector<StockOperation*>);
        void set_csv_items_path(std::string filepath);
        void set_csv_operations_path(std::string filepath);

        FileStatus load_items();
        FileStatus load_operations();
        FileStatus save_items();
        FileStatus save_operations();
        FileStatus add_item(Item item);
        FileStatus remove_item(std::string id);
        FileStatus apply_operation(StockOperation* op, Item& item);
        void show_inventory();

        ~Inventory();
};