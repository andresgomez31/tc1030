#include "menu.hpp"
#include <iostream>

void show_all_media(DB& db) {
    std::vector<Media*> media = db.media.get_media();

    for (const Media* m : media) {
        std::cout << m->to_string() << std::endl;
    }
}

void review_media(DB& db) {
    std::string id;
    std::vector<Media*> found;
    do {
        std::cout << "Enter the ID of the media to review: ";
        std::getline(std::cin, id);
        found = db.media.get_media({{MEDIA_FIELDS::BY_ID, id}});
        if (found.empty()) {
            std::cout << "Media with ID '" << id << "' not found. Please try again." << std::endl;
        }
    } while (found.empty());

    int review = -1;
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

    db.reviews.append_review(id, review);

    std::cout << "Review submitted successfully for media ID " << id << "." << std::endl;
}

void show_media(DB& db, std::map<MEDIA_FIELDS, std::string> filters) {
    std::vector<Media*> media = db.media.get_media(filters);

    if (media.empty()) {
        std::cout << "No media found matching the specified criteria." << std::endl;
        return;
    }

    for (const Media* m : media) {
        std::cout << m->to_string() << std::endl;
    }
}

void free_memory(DB& db) {
    delete &db;
    std::cout << "Memory freed successfully." << std::endl;
}

void menu(DB& db) {
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Mostrar todo el catalogo con calificaciones.\n";
        std::cout << "2. Calificar un video\n";
        std::cout << "3. Mostrar peliculas o capitulos con una calificacion minima determinada\n";
        std::cout << "4. Mostrar peliculas o capitulos de un cierto genero.\n";
        std::cout << "9. Salir\n";
        std::cout << "Seleccione una opcion: ";

        std::string input;
        std::getline(std::cin, input);

        if (input == "1") {
            show_all_media(db);
        } else if (input == "2") {
            review_media(db);
        } else if (input == "3") {
            std::cout << "Ingrese la calificacion minima (0-5): ";
            std::string min_rating_str;
            std::getline(std::cin, min_rating_str);
            int min_rating = 0;
            try {
                min_rating = std::stoi(min_rating_str);
            } catch (...) {
                min_rating = 0;
            }
            std::map<MEDIA_FIELDS, std::string> filters;
            filters[MEDIA_FIELDS::RATE_FROM] = std::to_string(min_rating);
            show_media(db, filters);
        } else if (input == "4") {
            std::cout << "Ingrese el genero: ";
            std::string genre;
            std::getline(std::cin, genre);
            std::map<MEDIA_FIELDS, std::string> filters;
            filters[MEDIA_FIELDS::CATEGORY] = genre;
            show_media(db, filters);
        } else if (input == "9") {
            free_memory(db);
            std::cout << "Saliendo del programa.\n";
            break;
        } else {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }
}