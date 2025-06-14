// File: menu.hpp

#pragma once

#include "src/DB.hpp"

void print_options();
void print_all_media(DB& db, bool details = false);
void print_all_with_min_rate(DB& db, float& rate, bool details = false);
void print_all_of_genre(DB& db, std::string& genre, bool details = false);
void rate_media(DB& db);
void menu(std::string path, bool details = false);