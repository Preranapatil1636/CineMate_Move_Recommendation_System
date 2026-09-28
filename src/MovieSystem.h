#ifndef MOVIE_SYSTEM_H
#define MOVIE_SYSTEM_H

#include <vector>
#include <memory>
#include <string>
#include "Movie.h"
#include "ActionMovie.h"
#include "ComedyMovie.h"

/**
 * @class MovieSystem
 * @brief Manages the collection of polymorphic Movie objects.
 * 
 * Demonstrates Abstraction by providing a high-level API for adding,
 * searching, filtering, and recommending movies while encapsulating
 * the underlying std::vector<std::unique_ptr<Movie>> container.
 */
class MovieSystem {
private:
    std::vector<std::unique_ptr<Movie>> movies;

public:
    // Constructor & Destructor
    MovieSystem() = default;
    ~MovieSystem() = default;

    // Prevent copy operations due to unique_ptr storage
    MovieSystem(const MovieSystem&) = delete;
    MovieSystem& operator=(const MovieSystem&) = delete;

    // Allow move operations
    MovieSystem(MovieSystem&&) = default;
    MovieSystem& operator=(MovieSystem&&) = default;

    // Core Functional API
    bool addMovie(std::unique_ptr<Movie> movie);
    void loadSampleMovies();
    
    // Query & Display Methods
    void displayAllMovies() const;
    void displayMovieList(const std::vector<const Movie*>& list, const std::string& sectionTitle) const;

    // Filtering & Recommendation Methods
    std::vector<const Movie*> searchByGenre(const std::string& genre) const;
    std::vector<const Movie*> filterByRating(double minRating) const;
    std::vector<const Movie*> searchByExactYear(int year) const;
    std::vector<const Movie*> searchByYearRange(int startYear, int endYear) const;
    std::vector<const Movie*> getRecommendations(const std::string& genre, double minRating, 
                                                 int startYear = 1888, int endYear = 2026) const;

    // Utility Methods
    bool isDuplicate(const std::string& title, int releaseYear) const;
    size_t getMovieCount() const;
};

#endif // MOVIE_SYSTEM_H
