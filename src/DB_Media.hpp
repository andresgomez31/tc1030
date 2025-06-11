// File: DB_Media.hpp

#pragma once

#include "DB_Service.hpp"

enum MEDIA_FIELDS {
    TYPE,
    ID,
    TITLE,
    DURATION,
    CATEGORY,
    SERIES_TITLE,
    CHAPTER,
    RATE_FROM,
    RATE_TO,
    RATE,
};

class DB_Media : public DB_Service {
    private:
        std::vector<Media*> data;
        std::unordered_map<std::string, Media*> index_by_id;

        void load_data() override;
        void create_indexes();

    public:
        DB_Media(std::string path);
        // Getters
        const std::vector<Media*>& get_media() const;
        std::vector<Media*> get_media(std::map<MEDIA_FIELDS, std::string> filters);

        // Setting rating on Media objects:
        void update_media(std::map<MEDIA_FIELDS, std::string> data, std::string& id);

        ~DB_Media();
};