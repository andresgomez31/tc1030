// StockOperation.hpp

#pragma once
#include <string>
#include "FileStatus.hpp"
#include "Item.hpp"

class StockOperation {
    private:
        std::string item_id;
        int quantity;
        std::string date;

    protected:
        StockOperation();
        StockOperation(std::string item_id, int quantity);
        
    public:
        // Getters
        std::string get_item_id() const;
        int get_quantity() const;
        std::string get_date() const;
        virtual std::string get_type() const = 0;

        // Setters
        void set_date();

        // Apply operations
        virtual FileStatus apply(Item& item) const = 0;
        // Destructor
        virtual ~StockOperation() = default;
};