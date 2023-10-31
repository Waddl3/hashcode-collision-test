# Hash Map Implementation for Text File

This program generates a polynomial hash code for words in a text file and counts the number of collisions (where different words result in the same hash code) using a C++ implementation.

## Purpose

The purpose of this code is to demonstrate a basic implementation of a hash map using a polynomial hashing technique to map words to their corresponding hash codes. It aims to show how collisions can occur when different words generate the same hash code.

## Implementation Details

### Hash Function
The code implements a simple polynomial hashing technique in the `HashCode` class. The `operator()` function calculates the hash code for a given string, and the hash collisions are tracked using an `unordered_map`.

### Lowercasing Function
The `lowerCase()` function converts input strings to lowercase to ensure uniform hashing.

### Reading Text File
The program reads a text file (`usdeclarPC.txt`) containing text and processes the words to generate hash codes for each word. It then checks for collisions by comparing hash codes of different words.

## Usage

### Compilation
Compile the code using a C++ compiler (e.g., g++):

```bash
g++ -o hash_map hash_map.cpp
```

### Execution
Run the compiled program and pass the text file as a command-line argument:

```bash
./hash_map C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt
```

Replace `C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt` with the path to the text file you want to analyze.

## Contributors

- Author: Jesus Rodriguez-Luna

## Notes

The code may produce collisions depending on the choice of hash function and the characteristics of the input text file. Higher collision counts could indicate inefficiencies in the chosen hash function.
