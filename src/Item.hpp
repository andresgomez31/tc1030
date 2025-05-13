// Item.hpp

#pragma once
#include <string>

class Item {
    private:
        std::string id;
        std::string name;
        std::string category;
        int stock;
        float price;
        float cost;

    public:
        Item();
        Item(std::string id, std::string name, std::string category,
            int stock, float price, float cost);

        // Getters
        std::string get_id() const;
        std::string get_name() const;
        std::string get_category() const;
        int get_stock() const;
        float get_price() const;
        float get_cost() const;

        // Setters (ommiting stock for integrity)
        void set_id(std::string id);
        void set_name(std::string name);
        void set_category(std::string category);
        void set_stock(int stock);
        void set_price(float price);
        void set_cost(float cost);
};