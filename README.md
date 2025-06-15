# Data extraction from File  in C++

This C++ program reads a text file, analyzes its content, and writes a summary to another file. It counts lines, words, characters, and vowel frequencies.

## Features

- Line, word, and character count (with/without spaces)
- Vowel frequency (`a`, `e`, `i`, `o`, `u`)
- Uses `ifstream` and `ofstream` with error handling


## Handling File Opening and Error Checking

The program uses ifstream and ofstream for reading and writing files.
It checks whether files open successfully using .is_open() before processing.
If a file cannot be opened, it prints an error message and stops processing.


ifstream inputFile(inputFileName);
if (!inputFile.is_open()) {
    cerr << "Error: Could not open input file.\n";
    return false;
}


## Reading and Writing Operations

The program uses getline() to read each line.
It uses stringstream to break the line into words.
It writes the result to outputFile using << stream operator.


getline(inputFile, line);
stringstream ss(line);
outputFile << "Total Words: " << wordCount;


## File Closing

All files are closed explicitly using .close() to free resources and avoid corruption.

inputFile.close();
outputFile.close();


## Handling Large Files

The program reads the file line by line, not all at once.
This is memory-efficient and prevents crashing on large files.
Using stringstream and character-wise checks allows fine-grained processing without loading the full file.


## Robustness Against Errors

The program checks both file streams for open success.
It validates file names and uses cerr to report problems.
Logic separates counting words, characters, vowels for cleaner debugging.

