#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

// Function to count vowels in a line
void countVowels(const string& line, map<char, int>& vowelCount) {
    for (char ch : line) {
        ch = tolower(ch); // Convert to lowercase
        if (vowelCount.find(ch) != vowelCount.end()) {
            vowelCount[ch]++;
        }
    }
}

// Function to process the input file and generate report
bool processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName); // Open for reading
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file: " << inputFileName << endl;
        return false;
    }

    ofstream outputFile(outputFileName); // Open for writing
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file: " << outputFileName << endl;
        inputFile.close(); // Make sure to close input file
        return false;
    }

    string line;
    int lineCount = 0, wordCount = 0, charCount = 0, totalChars = 0;
    map<char, int> vowelCount = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};

    while (getline(inputFile, line)) {
        lineCount++;
        totalChars += line.length(); // Includes spaces

        stringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++;
            charCount += word.length(); // Excludes spaces
        }

        countVowels(line, vowelCount);
    }

    // Writing summary report
    outputFile << "----- File Analysis Report -----\n";
    outputFile << "Total Lines: " << lineCount << "\n";
    outputFile << "Total Words: " << wordCount << "\n";
    outputFile << "Characters (excluding spaces): " << charCount << "\n";
    outputFile << "Characters (including spaces): " << totalChars << "\n";
    outputFile << "Vowel Frequency:\n";
    for (auto it = vowelCount.begin(); it != vowelCount.end(); ++it) {
    outputFile << "  " << it->first << ": " << it->second << "\n";
}


    inputFile.close();
    outputFile.close();

    return true;
}

int main() {
    string inputFileName, outputFileName;

    cout << "Enter the name of the input text file: ";
    getline(cin, inputFileName);

    cout << "Enter the name of the output report file: ";
    getline(cin, outputFileName);

    if (processFile(inputFileName, outputFileName)) {
        cout << "Report successfully written to '" << outputFileName << "'\n";
    } else {
        cout << "Processing failed. Please check file names and try again.\n";
    }

    return 0;
}



