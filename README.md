# CineMate - Movie Recommendation System

**Team Name:** CodeFlix  
**Team Members:**  
- **Rishi Oswal**  
- **Sonia Nanvani**  
- **Gargi Salukhe**  
- **Prerana Patil**  

**Language:** C++ (C++17)  
**Application Type:** Console-based Application  

---

## 🎬 Project Overview & Objectives

**CineMate** is an object-oriented C++ console application designed to help users discover, filter, and receive personalized movie recommendations. The system manages diverse film categories through a robust Object-Oriented Architecture, supporting filtering by genre, minimum rating, and release year.

### Core Objectives
1. Implement a clean, interactive, menu-driven C++ application.
2. Demonstrate core Object-Oriented Programming (OOP) principles: **Encapsulation**, **Inheritance**, **Polymorphism**, and **Abstraction**.
3. Provide multi-criteria movie discovery with AND logic filtering.
4. Ensure total system stability through comprehensive input validation and duplicate prevention.

---

## 🚀 Main Features

1. **Add Custom Movies**: Add new movies dynamically with title, genre, rating (0.0–10.0), release year (1888–2026), and category-specific attributes.
2. **Display All Movies**: View complete details of all loaded sample movies and user-added movies using polymorphic formatting.
3. **Search by Genre**: Case-insensitive substring and keyword search (e.g., Action, Comedy, Sci-Fi, Drama).
4. **Filter by Minimum Rating**: Retrieve movies meeting or exceeding a specified rating threshold ($Rating \ge \text{threshold}$).
5. **Search by Release Year**: Search for movies by exact release year or within a specific year range.
6. **Smart Recommendation Engine**: Filter movies using combined genre, rating, and year range criteria ($AND$ logic).
7. **Duplicate Prevention**: Rejects duplicate movie entries based on normalized title and release year.
8. **Fault-Tolerant Input**: Protects against non-numeric entries, empty strings, out-of-range inputs, and unexpected input buffer states.

---

## 🧱 OOP Architecture & Principles

CineMate is built upon the four pillars of Object-Oriented Programming:

```
                  +-------------------+
                  |       Movie       |  <--- Base Class (Encapsulation & Polymorphism)
                  +-------------------+
                    ^               ^
                    |               |
       +------------+               +------------+
       |                                         |
+--------------+                          +--------------+
| ActionMovie  |                          | ComedyMovie  |  <--- Derived Classes (Inheritance)
+--------------+                          +--------------+

                                 |
                                 v  (Composition: std::vector<std::unique_ptr<Movie>>)
                          +--------------+
                          | MovieSystem  |  <--- System Facade (Abstraction)
                          +--------------+
```

### 1. Encapsulation
- **Implementation**: The base class [`Movie`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/Movie.h) encapsulates movie attributes (`title`, `genre`, `rating`, `releaseYear`) as `private` data members.
- **Validation**: Direct access is restricted. Mutation is only permitted via validated public setters (`setTitle`, `setGenre`, `setRating`, `setReleaseYear`).
- **Data Integrity**: Setter methods validate numeric bounds (e.g., rating must be $0.0 \le r \le 10.0$, release year $1888 \le y \le 2026$) and reject empty/whitespace strings.

### 2. Inheritance
- **Implementation**: Specialized classes [`ActionMovie`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/ActionMovie.h) and [`ComedyMovie`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/ComedyMovie.h) publicly inherit from [`Movie`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/Movie.h).
- **Code Reuse & Extension**: Derived classes reuse base initialization and getters while introducing category-specific fields:
  - `ActionMovie`: adds `actionSubgenre` (e.g., Superhero, Sci-Fi Action).
  - `ComedyMovie`: adds `humorStyle` (e.g., Slapstick, Satire, Rom-Com).
- **Extensibility**: Additional genre classes (e.g., `HorrorMovie`, `SciFiMovie`) can easily inherit from `Movie` without modifying existing system code.

### 3. Polymorphism
- **Implementation**: The base class defines a virtual method `virtual void displayDetails() const` and a virtual destructor `virtual ~Movie() = default`.
- **Runtime Binding**: Derived classes override `displayDetails()` to print custom, category-tailored formats.
- **Memory Safety**: `MovieSystem` stores movies using smart pointers (`std::vector<std::unique_ptr<Movie>>`). Calling `displayDetails()` on a base `Movie*` pointer dynamically invokes the correct derived override at runtime without object slicing.

### 4. Abstraction
- **Implementation**: [`MovieSystem`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/MovieSystem.h) presents a high-level, simplified interface for client applications (`main.cpp`).
- **Information Hiding**: Internal collection storage (`std::vector`), duplicate checking algorithms, string normalization routines, and pointer management are hidden behind clean public methods: `addMovie()`, `searchByGenre()`, `filterByRating()`, and `getRecommendations()`.

---

## 🛠️ Class Descriptions & Relationships

| Class Name | Header File | Implementation File | Role & Key Responsibilities |
| :--- | :--- | :--- | :--- |
| `Movie` | [`Movie.h`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/Movie.h) | [`Movie.cpp`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/Movie.cpp) | Base class representing common movie attributes, setters with input validation, and virtual `displayDetails()`. |
| `ActionMovie` | [`ActionMovie.h`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/ActionMovie.h) | [`ActionMovie.cpp`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/ActionMovie.cpp) | Derived class for Action movies. Adds `actionSubgenre` and overrides `displayDetails()`. |
| `ComedyMovie` | [`ComedyMovie.h`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/ComedyMovie.h) | [`ComedyMovie.cpp`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/ComedyMovie.cpp) | Derived class for Comedy movies. Adds `humorStyle` and overrides `displayDetails()`. |
| `MovieSystem` | [`MovieSystem.h`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/MovieSystem.h) | [`MovieSystem.cpp`](file:///c:/Users/prera/Downloads/Prerana_Documents/CineMate/src/MovieSystem.cpp) | System facade managing `std::vector<std::unique_ptr<Movie>>`, sample data population, duplicate checking, and search/recommendation logic. |

---

## 💻 Compilation & Execution Instructions

### Prerequisites
- C++17 compatible compiler (`g++` 7.0+, `clang++`, or MSVC 2017+).

### Windows (g++)
Open PowerShell or Command Prompt in the project root directory:

```powershell
# Compile the project with all warnings enabled
g++ -std=c++17 -Wall -Wextra -pedantic src/Movie.cpp src/ActionMovie.cpp src/ComedyMovie.cpp src/MovieSystem.cpp src/main.cpp -o CineMate.exe

# Run CineMate
.\CineMate.exe
```

### Linux / macOS (g++ or clang++)
```bash
# Compile
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -o CineMate

# Run
./CineMate
```

---

## 🎮 Menu Usage & Sample Interaction

```text
========================================================
               CINEMATE MOVIE SYSTEM                    
                Developed by CodeFlix                   
 Team Members: Rishi Oswal, Sonia Nanvani,              
               Gargi Salukhe, Prerana Patil             
========================================================

------------------ MAIN MENU ------------------
 1. Add Movie
 2. Display All Movies
 3. Search Movies by Genre
 4. Find Movies Above a Rating (>= threshold)
 5. Search Movies by Release Year
 6. Get Movie Recommendations (AND Logic)
 7. Exit
-----------------------------------------------
 Enter option (1-7): 6

--- GET MOVIE RECOMMENDATIONS ---
 Information: Filtering criteria are combined using AND logic.
 A movie must satisfy ALL chosen conditions to be recommended.

 Enter Preferred Genre (or press ENTER to ignore genre filter): Action
 Enter Minimum Rating Threshold (0.0 to 10.0, default 0.0): 8.5
 Do you wish to filter by Release Year Range? (1 = Yes, 2 = No): 2

==================================================
 RECOMMENDATIONS (Genre: "Action", Rating >= 8.5)
==================================================
 Matching Count: 2 movie(s)

--- Result #1 -------------------------------------------
 Type:         Action Movie
 Title:        The Dark Knight
 Genre:        Action
 Rating:       9.0 / 10.0
 Release Year: 2008
 Subgenre:     Superhero / Crime
 Category:     [ACTION EXTREME]

--- Result #2 -------------------------------------------
 Type:         Action Movie
 Title:        Inception
 Genre:        Action
 Rating:       8.8 / 10.0
 Release Year: 2010
 Subgenre:     Sci-Fi Action
 Category:     [ACTION EXTREME]
==================================================
```

---

## 🔒 Input Validation Rules & Known Limitations

### Validation Rules
1. **Rating**: Must be a floating-point value in the range $[0.0, 10.0]$.
2. **Release Year**: Must be an integer in the range $[1888, 2026]$.
3. **Strings**: Titles and genres must contain non-whitespace text.
4. **Duplicate Policy**: Movies are identified as duplicate if their normalized title (case-insensitive) and release year match an existing entry.
5. **Stream Recovery**: Invalid non-numeric input (e.g., letters when a number is requested) triggers stream clearing and reprompting without crashing.

### Limitations & Future Enhancements
- Movie storage is maintained in-memory during application runtime. Persistent database or JSON file storage can be added as a future module.
- Additional specialized subclasses (e.g., `HorrorMovie`, `DocumentaryMovie`) can be created following the established inheritance model.
