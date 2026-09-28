#include "Movie.h"

Movie::Movie()
    : title("Untitled"), genre("General"), rating(0.0), releaseYear(2000) {}

Movie::Movie(const std::string& title, const std::string& genre, double rating, int releaseYear) {
    if (!setTitle(title)) {
        this->title = "Untitled";
    }
    if (!setGenre(genre)) {
        this->genre = "General";
    }
    if (!setRating(rating)) {
        this->rating = 0.0;
    }
    if (!setReleaseYear(releaseYear)) {
        this->releaseYear = 2000;
    }
}

std::string Movie::getTitle() const {
    return title;
}

std::string Movie::getGenre() const {
    return genre;
}

double Movie::getRating() const {
    return rating;
}

int Movie::getReleaseYear() const {
    return releaseYear;
}

std::string Movie::getMovieType() const {
    return "Standard Movie";
}

bool Movie::setTitle(const std::string& t) {
    std::string trimmed = trim(t);
    if (trimmed.empty()) {
        return false;
    }
    title = trimmed;
    return true;
}

bool Movie::setGenre(const std::string& g) {
    std::string trimmed = trim(g);
    if (trimmed.empty()) {
        return false;
    }
    genre = trimmed;
    return true;
}

bool Movie::setRating(double r) {
    if (isValidRating(r)) {
        rating = r;
        return true;
    }
    return false;
}

bool Movie::setReleaseYear(int y) {
    if (isValidReleaseYear(y)) {
        releaseYear = y;
        return true;
    }
    return false;
}

void Movie::displayDetails() const {
    std::cout << "----------------------------------------\n";
    std::cout << " Type:         " << getMovieType() << "\n";
    std::cout << " Title:        " << title << "\n";
    std::cout << " Genre:        " << genre << "\n";
    std::cout << " Rating:       " << std::fixed << std::setprecision(1) << rating << " / 10.0\n";
    std::cout << " Release Year: " << releaseYear << "\n";
}

std::string Movie::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

std::string Movie::toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

bool Movie::isValidRating(double r) {
    return (r >= 0.0 && r <= 10.0);
}

bool Movie::isValidReleaseYear(int y) {
    // Cinema started around 1888; current upper bound set to 2026.
    return (y >= 1888 && y <= 2026);
}
