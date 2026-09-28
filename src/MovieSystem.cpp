#include "MovieSystem.h"
#include <iostream>
#include <iomanip>

bool MovieSystem::addMovie(std::unique_ptr<Movie> movie) {
    if (!movie) {
        return false;
    }

    // Duplicate check based on Title (case-insensitive) and Release Year
    if (isDuplicate(movie->getTitle(), movie->getReleaseYear())) {
        std::cout << "\n [ERROR] Duplicate movie detected! A movie titled \"" 
                  << movie->getTitle() << "\" released in " 
                  << movie->getReleaseYear() << " already exists in the system.\n";
        return false;
    }

    movies.push_back(std::move(movie));
    return true;
}

void MovieSystem::loadSampleMovies() {
    // Populate realistic sample dataset with diverse genres, ratings, and years
    addMovie(std::make_unique<ActionMovie>("The Dark Knight", 9.0, 2008, "Superhero / Crime"));
    addMovie(std::make_unique<ActionMovie>("Inception", 8.8, 2010, "Sci-Fi Action"));
    addMovie(std::make_unique<ActionMovie>("Avengers: Endgame", 8.4, 2019, "Superhero"));
    addMovie(std::make_unique<ActionMovie>("Mad Max: Fury Road", 8.1, 2015, "Post-Apocalyptic Action"));

    addMovie(std::make_unique<ComedyMovie>("Superbad", 7.6, 2007, "Slapstick / Teen"));
    addMovie(std::make_unique<ComedyMovie>("The Hangover", 7.7, 2009, "Buddy Comedy"));
    addMovie(std::make_unique<ComedyMovie>("Paddington 2", 7.8, 2017, "Family Comedy"));

    addMovie(std::make_unique<Movie>("Interstellar", "Sci-Fi", 8.7, 2014));
    addMovie(std::make_unique<Movie>("Parasite", "Drama", 8.5, 2019));
    addMovie(std::make_unique<Movie>("Spirited Away", "Animation", 8.6, 2001));
    addMovie(std::make_unique<Movie>("Pulp Fiction", "Crime", 8.9, 1994));
    addMovie(std::make_unique<Movie>("The Shawshank Redemption", "Drama", 9.3, 1994));
}

void MovieSystem::displayAllMovies() const {
    if (movies.empty()) {
        std::cout << "\n [INFO] No movies currently available in the system.\n";
        return;
    }

    std::cout << "\n==================================================\n";
    std::cout << "               ALL AVAILABLE MOVIES               \n";
    std::cout << "==================================================\n";
    std::cout << " Total Count: " << movies.size() << " movie(s)\n";

    for (size_t i = 0; i < movies.size(); ++i) {
        std::cout << "\n--- Movie #" << (i + 1) << " ---";
        movies[i]->displayDetails();
    }
    std::cout << "==================================================\n";
}

void MovieSystem::displayMovieList(const std::vector<const Movie*>& list, const std::string& sectionTitle) const {
    std::cout << "\n==================================================\n";
    std::cout << " " << sectionTitle << "\n";
    std::cout << "==================================================\n";

    if (list.empty()) {
        std::cout << " [INFO] No movies match the requested criteria.\n";
        std::cout << "==================================================\n";
        return;
    }

    std::cout << " Matching Count: " << list.size() << " movie(s)\n";
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << "\n--- Result #" << (i + 1) << " ---";
        list[i]->displayDetails();
    }
    std::cout << "==================================================\n";
}

std::vector<const Movie*> MovieSystem::searchByGenre(const std::string& genre) const {
    std::vector<const Movie*> results;
    std::string searchGenreLower = Movie::toLower(Movie::trim(genre));

    for (const auto& m : movies) {
        std::string movieGenreLower = Movie::toLower(m->getGenre());
        if (movieGenreLower.find(searchGenreLower) != std::string::npos) {
            results.push_back(m.get());
        }
    }
    return results;
}

std::vector<const Movie*> MovieSystem::filterByRating(double minRating) const {
    std::vector<const Movie*> results;
    for (const auto& m : movies) {
        // Rating comparison rule: Rating >= minRating (inclusive threshold)
        if (m->getRating() >= minRating) {
            results.push_back(m.get());
        }
    }
    return results;
}

std::vector<const Movie*> MovieSystem::searchByExactYear(int year) const {
    std::vector<const Movie*> results;
    for (const auto& m : movies) {
        if (m->getReleaseYear() == year) {
            results.push_back(m.get());
        }
    }
    return results;
}

std::vector<const Movie*> MovieSystem::searchByYearRange(int startYear, int endYear) const {
    std::vector<const Movie*> results;
    if (startYear > endYear) {
        std::swap(startYear, endYear);
    }
    for (const auto& m : movies) {
        if (m->getReleaseYear() >= startYear && m->getReleaseYear() <= endYear) {
            results.push_back(m.get());
        }
    }
    return results;
}

std::vector<const Movie*> MovieSystem::getRecommendations(const std::string& genre, double minRating,
                                                           int startYear, int endYear) const {
    std::vector<const Movie*> results;
    std::string searchGenreLower = Movie::toLower(Movie::trim(genre));
    if (startYear > endYear) {
        std::swap(startYear, endYear);
    }

    for (const auto& m : movies) {
        std::string movieGenreLower = Movie::toLower(m->getGenre());
        bool matchGenre = searchGenreLower.empty() || (movieGenreLower.find(searchGenreLower) != std::string::npos);
        bool matchRating = (m->getRating() >= minRating); // Rule: Rating >= minRating
        bool matchYear = (m->getReleaseYear() >= startYear && m->getReleaseYear() <= endYear);

        // Multi-criteria filter uses AND logic
        if (matchGenre && matchRating && matchYear) {
            results.push_back(m.get());
        }
    }
    return results;
}

bool MovieSystem::isDuplicate(const std::string& title, int releaseYear) const {
    std::string newTitleLower = Movie::toLower(Movie::trim(title));
    for (const auto& m : movies) {
        std::string existingTitleLower = Movie::toLower(m->getTitle());
        if (existingTitleLower == newTitleLower && m->getReleaseYear() == releaseYear) {
            return true;
        }
    }
    return false;
}

size_t MovieSystem::getMovieCount() const {
    return movies.size();
}
