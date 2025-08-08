// File: menu.cpp

#include "menu.hpp"
#include <sstream>
#include <iostream>

void print_options() {
    std::stringstream output;

    output  << "1) Mostrar todo el catalogo con calificaciones." << "\n"
            << "2) Calificar un video." << "\n"
            << "3) Mostrar peliculas o capitulos con una calificacion minima determinada." << "\n"
            << "4) Mostrar peliculas o capitulos de un cierto genero." << "\n"
            << "9) Salir." << "\n";

    std::cout << output.str();
}

void print_all_media(DB& db, bool details) {
    std::stringstream result;
    for (const auto& pair : db.id_indexes) {
        if (details) {
            result << pair.second->to_string() << "\n";
        }
        else {
            result << pair.first << "\n";
        }
    }
    std::cout << result.str();
}

void print_all_with_min_rate(DB& db, float& rate, bool details) {
    std::vector<std::string> media_ids;
    std::stringstream result;
    for (const auto& pair : db.rate_indexes) {
        if (pair.second >= rate) {
            media_ids.push_back(pair.first);
        }
    }
    for (const std::string& media_id : media_ids) {
        if (details) {    
            result << db.id_indexes[media_id]->to_string() << "\n";
        }
        else {
            result << media_id << "\n";
        }
    }
    std::cout << result.str();
}

void print_all_of_genre(DB& db, std::string& genre, bool details) {
    std::stringstream result;
    for (const auto& media : db.genre_indexes[genre]) {
        if (details) {
            result << media->to_string() << "\n";
        }
        else {
            result << media->get_id() << "\n";
        }
    }
    std::cout << result.str();
}

void rate_media(DB& db) {
    std::string id;
    bool media_found = false;
    do {
        std::cout << "Enter the ID of the media to review: ";
        std::getline(std::cin, id);
        auto it = db.id_indexes.find(id);
        if (it == db.id_indexes.end()) {
            std::cout << "Media with ID '" << id << "' not found. Please try again." << std::endl;
        }
        else {
            media_found = true;
        }
    } while (!media_found);

    int review;

    do {
        std::cout << "Enter your review (0-5): ";
        std::string input;
        std::getline(std::cin, input);
        try {
            review = std::stoi(input);
        } catch (...) {
            review = -1;
        }
        if (review < 0 || review > 5) {
            std::cout << "Invalid review. Please enter a number between 0 and 5." << std::endl;
        }
    } while (review < 0 || review > 5);

    auto it = db.rates.find(id);
    if (it == db.rates.end()) {
        std::vector<float> rates; 
        rates.push_back(review);
        db.rates.insert({ id, rates });
        db.id_indexes[id]->set_rate(std::to_string(review));
        db.rate_indexes[id] = review; // Initialize the rate index
    }
    else {
        db.rates[id].push_back(review);
        float avg;
        for (float& _ : db.rates[id]) avg += _;
        avg /= db.rates[id].size();
        db.id_indexes[id]->set_rate(std::to_string(avg));
        db.rate_indexes[id] = avg; // Update the rate index
        std::cout << "New average rating for media with ID '" << id << "' is: " << avg << std::endl;
    }
}

void menu(std::string path, bool details) {
    DB db(path);
    int option;
    float rate;
    std::string genre;

    do {
        std::cout << "Select an option: " << std::endl;
        print_options();
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                print_all_media(db, details);
                break;
            case 2:
                rate_media(db);
                break;
            case 3:
                std::cout << "Enter minimum rating: ";
                std::cin >> rate;
                std::cin.ignore();
                print_all_with_min_rate(db, rate, details);
                break;
            case 4:
                std::cout << "Enter genre: ";
                std::getline(std::cin, genre);
                print_all_of_genre(db, genre, details);
                break;
            default:
                if (option != 9) {
                    std::cout << "Invalid option. Please try again." << std::endl;
                }
        }
    } while (option != 9);
}