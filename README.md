# Inverted Search

## Project Brief
Developed an inverted index search engine in C for fast keyword search across multiple text files using hash tables and linked lists. Implemented database create/update and save/load operations with a menu-driven CLI and efficient file I/O. Improved reliability through input validation and robust error handling.

A C implementation of an inverted index data structure for efficient text search across multiple files.

## Overview
This project implements an inverted search mechanism that creates an index of words and their locations across multiple text files. It allows for fast searching and retrieval of information similar to search engines.

## Features
- Create inverted index database from multiple text files
- Fast keyword search across indexed files using hash tables
- Display the complete database
- Save database to file for persistence
- Load database from file
- Update database with new files
- Hash table implementation for efficient storage and retrieval
- Menu-driven command-line interface
- Input validation and robust error handling

## Project Structure
All source files are in the root directory with modular organization:
- `main.c` - Main program and menu interface
- `create_database.c` - Database creation logic
- `hash.c` - Hash table implementation
- `file_validation.c` - Input file validation
- `read_datafile.c` - File reading operations
- `search.c` - Search functionality
- `display.c` - Database display operations
- `save.c` - Save database to file
- `load_database.c` - Load database from file
- `update.c` - Update database with new files
- `word_list.c` - Word list management
- `inverted_Search.h` - Header file with all declarations

## How to Build
```bash
make
```

## How to Run
```bash
./inverted.exe file1 file2 [more files...]
```

## Operations
1. **Create Database** - Build inverted index from input files
2. **Display Database** - Show the complete index
3. **Search** - Find a word in the database
4. **Save Database** - Save index to a file
5. **Update Database** - Add new files to existing index
6. **Load Database** - Load previously saved index

## Technologies Used
- **Embedded C** - Advanced C & Data Structure
- Hash tables
- Linked lists
- File operations
- Dynamic memory allocation
- Command-line arguments
- Makefiles

## Data Structure
The program uses:
- Hash table for efficient word lookup
- Linked lists for storing file information
- Word nodes containing word frequency and file locations

## Key Challenges & Learnings
✓ Faced repeated database creation causing unnecessary wordcount increments
✓ Needed a fast, memory-efficient system to handle thousands of words across multiple files with persistence
✓ Fixed redundant creation by adding an is_created flag to prevent duplicate operations
✓ Learned efficient data structure design for search optimization

## GitHub Repository
https://github.com/Khusboo-REC/project-4

## Example Usage
```bash
# Create index from files
./inverted.exe file1.txt file2.txt

# Then use menu to:
# 1. Create database
# 2. Search for words
# 3. Save/Load database
```
