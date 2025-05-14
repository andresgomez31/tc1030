#include "Item.hpp"
#include <iostream>

Item::Item() : id(""), name(""), category(""), stock(0), price(0.0f), cost(0.0f) {}

Item::Item(std::string id, std::string name, std::string category, int stock, float price, float cost)
    : id(id), name(name), category(category), stock(stock), price(price), cost(cost) {}

// Getters
std::string Item::get_id() const { return id; }
std::string Item::get_name() const { return name; }
std::string Item::get_category() const { return category; }
int Item::get_stock() const { return stock; }
float Item::get_price() const { return price; }
float Item::get_cost() const { return cost; }

// Setters
void Item::set_id(std::string id) { this -> id = id; }
void Item::set_name(std::string name) { this -> name = name; }
void Item::set_category(std::string category) { this -> category = category; }
void Item::set_stock(int stock) { this -> stock = stock; }
void Item::set_price(float price) { this -> price = price; }
void Item::set_cost(float cost) { this -> cost = cost; }

// Operator overloads
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "ID: " << item.get_id() << "\n"
       << "Name: " << item.get_name() << "\n"
       << "Category: " << item.get_category() << "\n"
       << "Stock: " << item.get_stock() << "\n"
       << "Price: $" << item.get_price() << "\n"
       << "Cost: $" << item.get_cost() << "\n";
    return os;
}
