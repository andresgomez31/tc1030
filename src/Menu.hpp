#pragma once
#include <string>
#include "Item.hpp"
#include "Sale.hpp"
#include "SaleDevolution.hpp"
#include "Purchase.hpp"
#include "PurchaseDevolution.hpp"
#include "Inventory.hpp"

class Menu {
    private:
        Menu();
        Menu(Inventory inventory);
        Inventory inventory;
    public:
        void Main_menu();
}