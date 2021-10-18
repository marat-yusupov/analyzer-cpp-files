#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include "FileHandler.hpp"

using namespace std;

FileHandler::FileHandler(std::map<std::string, std::string> sourceFiles, std::map<std::string, std::string> headerFiles) { 
    for (auto elem : sourceFiles) {
        countOfDots = 0;
        ifstream file(elem.second);
        
        if (!file.is_open()) {
            cout << "Cannot open file" << endl;
            return;
        }
        
        filesTree.push_back(elem.first);
        files.push_back(elem.first);
        findDependencies(file, headerFiles);
    }
}

void FileHandler::findDependencies(std::ifstream &file, std::map<std::string, std::string> &headerFiles) {
    std::string stringOfFile;

    countOfDots += 2;
    std::string dots = "";
    
    for (int i = 0; i < countOfDots; i++) {
        dots += '.';
    }
    
    while (getline(file, stringOfFile)) {
        if (stringOfFile[0] != '/') {
            if (stringOfFile.substr(0, stringOfFile.find(" ")).find("#include") != std::string::npos) {
                std::string fileName = stringOfFile.erase(0, stringOfFile.substr(0, stringOfFile.find("\"")).length());

                stringstream stream(fileName);
                string nameWithoutQuotes;
                map <string, string> :: iterator it;
    
                while(stream >> std::quoted(nameWithoutQuotes)) {
                    it = headerFiles.find(nameWithoutQuotes);
                    if (!it->second.empty()) {
                        filesTree.push_back(dots + nameWithoutQuotes);
                        ifstream dependencyFile(it->second);
                        findDependencies(dependencyFile, headerFiles);
                    } else {
                        filesTree.push_back(dots + nameWithoutQuotes + " (!)");
                    }
                    files.push_back(nameWithoutQuotes);
                }
            }
        } else continue;
    }
}

void FileHandler::findCountOfInclusions() {
    for (int i = 0; i < files.size(); i++) {
        fileInclusions[files[i]]++;
    }
}

std::vector<string> FileHandler::getFilesTree() {
    return filesTree;
}

std::map<std::string, int> FileHandler::getFileInclusions() { 
    return fileInclusions;
}




