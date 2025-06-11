#pragma once

#include "src/DB_Media.hpp"

void show_all_media(DB& db);
void review_media(DB& db);
void show_media(DB& db, std::map<MEDIA_FIELDS, std::string> filters);
void free_memory(DB& db);
void menu(DB& db);