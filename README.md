# README: Multimedia Catalog Management System

This project implements a basic system to manage a catalog of movies and TV series episodes, allowing users to view, filter, and rate multimedia content. It is designed following object-oriented programming principles, using inheritance and polymorphism to structure different media types.

## 1. Project Structure

The project is organized into several `.cpp` (implementation) and `.hpp` (header) files to promote modularity and code clarity.

```
.
├── data/
│   └── media.csv       (or videos.txt, see 'Additional Notes')
├── main.cpp
├── menu.cpp
├── menu.hpp
└── src/
    ├── Chapter.cpp
    ├── Chapter.hpp
    ├── DB.cpp
    ├── DB.hpp
    ├── functions.cpp
    ├── functions.hpp
    ├── Media.cpp
    ├── Media.hpp
    ├── Movie.cpp
    └── Movie.hpp
```

**File Descriptions:**

- **main.cpp:** Main entry point. Initializes the database (DB) and launches the main menu interface.
- **menu.hpp / menu.cpp:** Contains logic for user interaction and the main menu.
  - `print_options()`: Shows available options.
  - `print_all_media()`: Prints the entire catalog.
  - `print_all_with_min_rate()`: Filters and shows content with a minimum rating.
  - `print_all_of_genre()`: Filters and shows content by genre.
  - `rate_media()`: Allows users to rate a video.
  - `menu()`: Main function managing the menu loop and navigation.
- **src/Media.hpp / src/Media.cpp:**
  - `Media`: Abstract base class. Defines common properties (ID, title, duration, genre, rating) and behaviors (`to_string()`, `to_csv()`) for all media items, ensuring polymorphism.
- **src/Movie.hpp / src/Movie.cpp:**
  - `Movie`: Concrete class inheriting from Media. Represents a movie and overrides `to_string()` and `to_csv()` for movie-specific representation.
- **src/Chapter.hpp / src/Chapter.cpp:**
  - `Chapter`: Concrete class inheriting from Media. Represents a series episode, adding attributes like series title and episode number. Also overrides `to_string()` and `to_csv()`.
- **src/DB.hpp / src/DB.cpp:**
  - `DB`: Acts as the in-memory database manager. Loads data from a CSV file and maintains several data structures (`unordered_map`) to index content by ID, genre, and rating for efficient searching and filtering. Manages memory for dynamically created Media objects.
- **src/functions.hpp / src/functions.cpp:** Contains general utility functions not directly belonging to a specific class, such as:
  - `read_csv()`: Reads lines from a CSV file.
  - `instance_media()`: Dynamically creates a Movie or Chapter instance from a CSV line, based on media type.
  - `create_id_indexes()`, `create_genre_indexes()`, `create_rate_indexes()`: Functions to build DB's internal indexes.

## 2. System Features

This program offers a console interface to interact with a multimedia catalog.

**Object-Oriented Design Principles:**
- **Inheritance:** `Movie` and `Chapter` classes inherit from the base `Media` class, sharing common attributes and behaviors.
- **Polymorphism:** Media pointers store both `Movie` and `Chapter` objects uniformly. Virtual methods like `to_string()` and `to_csv()` ensure type-specific behavior at runtime.

**Menu Functionalities:**
The program presents a cyclic menu with the following options:

1. **Show entire catalog with ratings:**  
   Prints all loaded movies and episodes. Output includes ID, title, duration, genre, and for episodes, series title and episode number. Shows average rating or "NR" (Not Rated) if unrated.

2. **Rate a video:**  
   Prompts for the video ID and an integer rating (0-5). Input is validated. The new rating is averaged with previous ratings.

3. **Show movies or episodes with a minimum rating:**  
   Prompts for a minimum rating (decimals allowed). Lists videos with an average rating greater than or equal to the input. Unrated videos ("NR") are not shown.  
   *Note: The current implementation does not include a submenu to filter by type (movie/episode/both), and shows all matching media.*

4. **Show movies or episodes of a certain genre:**  
   Prompts for the desired genre. Lists videos classified under that genre.  
   *Note: Like the previous option, no submenu for type selection is implemented.*

5. **Exit:**  
   Ends the program.

## 3. How to Compile and Run

**Prerequisites:**  
A C++ compiler (GCC, Clang, or MSVC) supporting C++17.

### 3.1. Linux / macOS (G++ or Clang)

1. Navigate to the project root:
   ```sh
   cd /path/to/project
   ```
2. Create the data directory and CSV file:
   ```sh
   mkdir data
   touch data/media.csv
   ```
   Populate `data/media.csv` (or `data/videos.txt` if you adjust `main.cpp`) with your media data.

3. Compile:
   ```sh
   g++ -std=c++17 -Isrc/ main.cpp menu.cpp src/*.cpp -o media_catalog
   ```

4. Run:
   ```sh
   ./media_catalog
   ```

### 3.2. Windows (MinGW/MSYS2 G++)

- Follow similar steps as Linux/macOS.
- Compile with:
  ```sh
  g++ -std=c++17 -Isrc/ main.cpp menu.cpp src/*.cpp -o media_catalog.exe
  ```
- Run with:
  ```sh
  .\media_catalog.exe
  ```

### 3.3. Windows (MSVC / Visual Studio IDE)

1. Open Visual Studio and create a new "Console Application (C++)" project.
2. Add all `.cpp` and `.hpp` files (including those in `src/`) to the project.
3. In project properties, add `$(ProjectDir)src;` to "Additional Include Directories".
4. Set the C++ language standard to C++17 or later.
5. Create the `data` folder at the same level as your `.vcxproj` and place your `media.csv` (or `videos.txt`) inside.
6. Build and run the project.
