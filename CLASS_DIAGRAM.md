# CineMate - Class Diagram

The following Mermaid diagram accurately illustrates the class architecture, inheritance hierarchy, encapsulation members, methods, and composition relationships within **CineMate**.

```mermaid
classDiagram
    class Movie {
        -string title
        -string genre
        -double rating
        -int releaseYear
        +Movie()
        +Movie(string title, string genre, double rating, int releaseYear)
        +virtual ~Movie()
        +getTitle() string
        +getGenre() string
        +getRating() double
        +getReleaseYear() int
        +virtual getMovieType() string
        +setTitle(string t) bool
        +setGenre(string g) bool
        +setRating(double r) bool
        +setReleaseYear(int y) bool
        +virtual displayDetails() void
        +static trim(string str)$ string
        +static toLower(string str)$ string
        +static isValidRating(double r)$ bool
        +static isValidReleaseYear(int y)$ bool
    }

    class ActionMovie {
        -string actionSubgenre
        +ActionMovie()
        +ActionMovie(string title, double rating, int releaseYear, string subgenre)
        +getActionSubgenre() string
        +setActionSubgenre(string subgenre) bool
        +getMovieType() string
        +displayDetails() void
    }

    class ComedyMovie {
        -string humorStyle
        +ComedyMovie()
        +ComedyMovie(string title, double rating, int releaseYear, string style)
        +getHumorStyle() string
        +setHumorStyle(string style) bool
        +getMovieType() string
        +displayDetails() void
    }

    class MovieSystem {
        -vector~unique_ptr~Movie~~ movies
        +MovieSystem()
        +~MovieSystem()
        +addMovie(unique_ptr~Movie~ movie) bool
        +loadSampleMovies() void
        +displayAllMovies() void
        +displayMovieList(vector list, string title) void
        +searchByGenre(string genre) vector
        +filterByRating(double minRating) vector
        +searchByExactYear(int year) vector
        +searchByYearRange(int startYear, int endYear) vector
        +getRecommendations(string genre, double minRating, int startYear, int endYear) vector
        +isDuplicate(string title, int releaseYear) bool
        +getMovieCount() size_t
    }

    Movie <|-- ActionMovie : Inheritance
    Movie <|-- ComedyMovie : Inheritance
    MovieSystem "1" *-- "0..*" Movie : Manages std::vector~unique_ptr~Movie~~
```

---

## Relationship Explanations
1. **Inheritance (`<|--`)**: `ActionMovie` and `ComedyMovie` derive publicly from the `Movie` base class, inheriting common properties while adding specialized genre attributes.
2. **Composition (`*--`)**: `MovieSystem` owns and manages multiple polymorphic `Movie` instances using `std::vector<std::unique_ptr<Movie>>`.
3. **Polymorphism**: `MovieSystem` interacts with `Movie` objects through base class pointers, dynamically resolving virtual method calls to `displayDetails()`.
