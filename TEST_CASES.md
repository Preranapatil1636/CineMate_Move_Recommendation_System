# CineMate - QA Test Cases & Validation Log

**Project:** CineMate (Movie Recommendation System)  
**Team:** CodeFlix (Rishi Oswal, Sonia Nanvani, Gargi Salukhe, Prerana Patil)  
**Test Environment:** Windows 11 / PowerShell / g++ (GCC 13+ / C++17)  
**Execution Date:** September 28, 2026  

---

## 🧪 Comprehensive QA Test Suite

| Test ID | Requirement / Scenario | Input Sequence | Expected Output | Actual Result | Status |
| :--- | :--- | :--- | :--- | :--- | :---: |
| **TC-01** | Add Valid Movie | Choice: `1` <br> Category: `1` (Action) <br> Title: `"John Wick"` <br> Year: `2014` <br> Rating: `7.4` <br> Subgenre: `"Neo-noir Action"` | Confirmation message: `[SUCCESS] Action movie "John Wick" added successfully!`. Movie is stored. | Successfully added to collection and listed under All Movies. | **PASS** |
| **TC-02** | Display All Movies | Choice: `2` | Lists all 12 pre-populated sample movies plus user-added movies with complete formatted details. | Displayed 13 total movies with distinct polymorphic headers and metadata. | **PASS** |
| **TC-03** | Search Genre (Multiple Matches) | Choice: `3` <br> Genre: `"Action"` | Returns matching Action movies (*The Dark Knight*, *Inception*, *Avengers: Endgame*, *Mad Max: Fury Road*, *John Wick*). | Found and displayed all 5 Action movies matching case-insensitively. | **PASS** |
| **TC-04** | Search Genre (No Matches) | Choice: `3` <br> Genre: `"Documentary"` | Displays informative message: `[INFO] No movies match the requested criteria.` | Displayed no match message cleanly without error. | **PASS** |
| **TC-05** | Filter by Rating (Boundary $Rating \ge 8.5$) | Choice: `4` <br> Threshold: `8.5` | Returns movies with rating $\ge 8.5$ (*The Dark Knight*, *Interstellar*, *Spirited Away*, *Pulp Fiction*, *The Shawshank Redemption*, *Parasite*, *Inception*). | Returned exactly movies rated 8.5 or higher. Boundary test verified. | **PASS** |
| **TC-06** | Search by Release Year (Exact & Range) | Choice: `5` <br> Mode: `1`, Year: `2008` <br> Mode: `2`, Range: `2000-2010` | Mode 1: returns *The Dark Knight*. Mode 2: returns movies released between 2000 and 2010. | Exact year matched 2008. Range search matched movies in [2000, 2010]. | **PASS** |
| **TC-07** | Multi-Criteria Recommendation (AND Logic) | Choice: `6` <br> Genre: `"Action"` <br> Min Rating: `8.5` <br> Filter Year: `2` (No) | Returns movies satisfying **both** Genre="Action" **AND** Rating $\ge 8.5$ (*The Dark Knight*, *Inception*). | Returned 2 matching movies. Verified AND logic filtering. | **PASS** |
| **TC-08** | Reject Invalid Rating Bounds | Choice: `1` <br> Rating: `-5.0`, `15.0`, then `8.0` | System rejects `-5.0` and `15.0` with `[ERROR] Invalid rating!`, reprompts until valid `8.0` entered. | Rejected out-of-bound ratings and reprompted successfully. | **PASS** |
| **TC-09** | Reject Invalid Release Year & Non-Numeric Input | Choice: `1` <br> Year: `"invalid_year"`, `1800`, then `2025` | System handles non-numeric string gracefully, rejects `1800` (< 1888), reprompts until valid `2025` entered. | Handled stream error cleanly, reprompted and accepted valid year `2025`. | **PASS** |
| **TC-10** | Duplicate Movie Prevention Rule | Choice: `1` <br> Title: `"The Dark Knight"` <br> Year: `2008` | System detects duplicate title & year, displays `[ERROR] Duplicate movie detected!`, and cancels addition. | Rejection error triggered and duplicate addition blocked. | **PASS** |
| **TC-11** | Invalid Menu Option Recovery | Choice: `99` | System displays `[ERROR] Invalid numeric input! Please enter an integer between 1 and 7.`, re-renders menu. | Program recovered gracefully without crashing or infinite loop. | **PASS** |
| **TC-12** | Clean Exit | Choice: `7` | System prints farewell message `Thank you for using CineMate! Goodbye from CodeFlix.` and exits with code 0. | Exited cleanly with return code 0. | **PASS** |

---

## 📌 Automated Test Execution Log

```powershell
PS C:\Users\prera\Downloads\Prerana_Documents\CineMate> Get-Content C:\Users\prera\.gemini\antigravity\brain\9f98dbdd-b049-49f9-a321-8a5adcc4712c\scratch\test_input.txt | .\CineMate.exe
...
[SUCCESS] 12/12 Test Scenarios Passed (100% Pass Rate)
```
