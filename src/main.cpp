#include <iostream>
#include <string>
#include <limits>
#include <memory>
#include <sstream>
#include "MovieSystem.h"
#include "ActionMovie.h"
#include "ComedyMovie.h"

// Input Validation Helpers
static std::string getStringInput(const std::string& prompt, bool allowEmpty = false) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::string trimmed = Movie::trim(input);
        if (!trimmed.empty() || allowEmpty) {
            return trimmed;
        }
        std::cout << " [ERROR] Input cannot be blank or whitespace only. Please try again.\n";
    }
}

static int getIntInput(const std::string& prompt, int minVal, int maxVal) {
    int val;
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> val && !(ss >> line) && val >= minVal && val <= maxVal) {
            return val;
        }
        std::cout << " [ERROR] Invalid numeric input! Please enter an integer between " 
                  << minVal << " and " << maxVal << ".\n";
    }
}

static double getDoubleInput(const std::string& prompt, double minVal, double maxVal) {
    double val;
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> val && !(ss >> line) && val >= minVal && val <= maxVal) {
            return val;
        }
        std::cout << " [ERROR] Invalid rating! Please enter a number between " 
                  << std::fixed << std::setprecision(1) << minVal 
                  << " and " << maxVal << ".\n";
    }
}

static void printHeader() {
    std::cout << "\n========================================================\n";
    std::cout << "               CINEMATE MOVIE SYSTEM                    \n";
    std::cout << "                Developed by CodeFlix                   \n";
    std::cout << " Team Members: Rishi Oswal, Sonia Nanvani,              \n";
    std::cout << "               Gargi Salukhe, Prerana Patil             \n";
    std::cout << "========================================================\n";
}

static void printMenu() {
    std::cout << "\n------------------ MAIN MENU ------------------\n";
    std::cout << " 1. Add Movie\n";
    std::cout << " 2. Display All Movies\n";
    std::cout << " 3. Search Movies by Genre\n";
    std::cout << " 4. Find Movies Above a Rating (>= threshold)\n";
    std::cout << " 5. Search Movies by Release Year\n";
    std::cout << " 6. Get Movie Recommendations (AND Logic)\n";
    std::cout << " 7. Exit\n";
    std::cout << "-----------------------------------------------\n";
}

static void handleAddMovie(MovieSystem& system) {
    std::cout << "\n--- ADD A NEW MOVIE ---\n";
    std::cout << " Select Movie Category:\n";
    std::cout << " 1. Action Movie (Specialized)\n";
    std::cout << " 2. Comedy Movie (Specialized)\n";
    std::cout << " 3. Standard Movie (Other Genres: Sci-Fi, Drama, Horror, etc.)\n";
    int categoryChoice = getIntInput(" Enter choice (1-3): ", 1, 3);

    std::string title = getStringInput(" Enter Movie Title: ");
    int year = getIntInput(" Enter Release Year (1888-2026): ", 1888, 2026);

    // Check for duplicate before prompting for remaining details
    if (system.isDuplicate(title, year)) {
        std::cout << "\n [ERROR] Duplicate movie detected! A movie titled \"" 
                  << title << "\" released in " << year << " already exists.\n";
        return;
    }

    double rating = getDoubleInput(" Enter Rating (0.0 to 10.0): ", 0.0, 10.0);

    if (categoryChoice == 1) {
        std::string subgenre = getStringInput(" Enter Action Subgenre (e.g. Superhero, Sci-Fi Action, Spy): ");
        auto actionMovie = std::make_unique<ActionMovie>(title, rating, year, subgenre);
        if (system.addMovie(std::move(actionMovie))) {
            std::cout << "\n [SUCCESS] Action movie \"" << title << "\" added successfully!\n";
        }
    } else if (categoryChoice == 2) {
        std::string style = getStringInput(" Enter Humor Style (e.g. Slapstick, Satire, Dark Comedy, Rom-Com): ");
        auto comedyMovie = std::make_unique<ComedyMovie>(title, rating, year, style);
        if (system.addMovie(std::move(comedyMovie))) {
            std::cout << "\n [SUCCESS] Comedy movie \"" << title << "\" added successfully!\n";
        }
    } else {
        std::string genre = getStringInput(" Enter Genre (e.g. Drama, Sci-Fi, Thriller, Romance, Horror): ");
        auto movie = std::make_unique<Movie>(title, genre, rating, year);
        if (system.addMovie(std::move(movie))) {
            std::cout << "\n [SUCCESS] Standard movie \"" << title << "\" added successfully!\n";
        }
    }
}

static void handleSearchByGenre(const MovieSystem& system) {
    std::cout << "\n--- SEARCH MOVIES BY GENRE ---\n";
    std::string genre = getStringInput(" Enter Genre to search (e.g., Action, Comedy, Sci-Fi, Drama): ");
    auto results = system.searchByGenre(genre);
    system.displayMovieList(results, "SEARCH RESULTS FOR GENRE: \"" + genre + "\"");
}

static void handleFilterByRating(const MovieSystem& system) {
    std::cout << "\n--- FIND MOVIES ABOVE RATING ---\n";
    std::cout << " Note: Results match movies with Rating >= your specified minimum threshold.\n";
    double minRating = getDoubleInput(" Enter Minimum Rating Threshold (0.0 - 10.0): ", 0.0, 10.0);
    auto results = system.filterByRating(minRating);
    
    std::ostringstream label;
    label << "MOVIES WITH RATING >= " << std::fixed << std::setprecision(1) << minRating;
    system.displayMovieList(results, label.str());
}

static void handleSearchByYear(const MovieSystem& system) {
    std::cout << "\n--- SEARCH MOVIES BY RELEASE YEAR ---\n";
    std::cout << " 1. Search by Exact Year\n";
    std::cout << " 2. Search by Year Range\n";
    int choice = getIntInput(" Enter choice (1-2): ", 1, 2);

    if (choice == 1) {
        int year = getIntInput(" Enter Exact Release Year (1888-2026): ", 1888, 2026);
        auto results = system.searchByExactYear(year);
        system.displayMovieList(results, "MOVIES RELEASED IN YEAR " + std::to_string(year));
    } else {
        int startYear = getIntInput(" Enter Start Year (1888-2026): ", 1888, 2026);
        int endYear = getIntInput(" Enter End Year (1888-2026): ", 1888, 2026);
        auto results = system.searchByYearRange(startYear, endYear);
        system.displayMovieList(results, "MOVIES RELEASED BETWEEN " + std::to_string(startYear) + " AND " + std::to_string(endYear));
    }
}

static void handleRecommendations(const MovieSystem& system) {
    std::cout << "\n--- GET MOVIE RECOMMENDATIONS ---\n";
    std::cout << " Information: Filtering criteria are combined using AND logic.\n";
    std::cout << " A movie must satisfy ALL chosen conditions to be recommended.\n\n";

    std::string genre = getStringInput(" Enter Preferred Genre (or press ENTER to ignore genre filter): ", true);
    double minRating = getDoubleInput(" Enter Minimum Rating Threshold (0.0 to 10.0, default 0.0): ", 0.0, 10.0);
    
    std::cout << " Do you wish to filter by Release Year Range? (1 = Yes, 2 = No): ";
    int filterYearChoice = getIntInput("", 1, 2);
    int startYear = 1888;
    int endYear = 2026;

    if (filterYearChoice == 1) {
        startYear = getIntInput(" Enter Start Year (1888-2026): ", 1888, 2026);
        endYear = getIntInput(" Enter End Year (1888-2026): ", 1888, 2026);
    }

    auto results = system.getRecommendations(genre, minRating, startYear, endYear);

    std::ostringstream sectionTitle;
    sectionTitle << "RECOMMENDATIONS (";
    if (!genre.empty()) {
        sectionTitle << "Genre: \"" << genre << "\", ";
    } else {
        sectionTitle << "Any Genre, ";
    }
    sectionTitle << "Rating >= " << std::fixed << std::setprecision(1) << minRating;
    if (filterYearChoice == 1) {
        sectionTitle << ", Years: " << startYear << "-" << endYear;
    }
    sectionTitle << ")";

    system.displayMovieList(results, sectionTitle.str());
}

int main() {
    MovieSystem system;
    
    // Load pre-populated sample movie dataset
    system.loadSampleMovies();

    printHeader();
    std::cout << " [INFO] Loaded " << system.getMovieCount() << " sample movies into the system.\n";

    bool running = true;
    while (running) {
        printMenu();
        int choice = getIntInput(" Enter option (1-7): ", 1, 7);

        switch (choice) {
            case 1:
                handleAddMovie(system);
                break;
            case 2:
                system.displayAllMovies();
                break;
            case 3:
                handleSearchByGenre(system);
                break;
            case 4:
                handleFilterByRating(system);
                break;
            case 5:
                handleSearchByYear(system);
                break;
            case 6:
                handleRecommendations(system);
                break;
            case 7:
                running = false;
                std::cout << "\n========================================================\n";
                std::cout << " Thank you for using CineMate! Goodbye from CodeFlix.  \n";
                std::cout << "========================================================\n\n";
                break;
            default:
                std::cout << " [ERROR] Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
