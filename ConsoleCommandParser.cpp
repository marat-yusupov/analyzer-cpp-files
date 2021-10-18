#include <string>
#include "ConsoleCommandParser.hpp"

ConsoleCommandParser::ConsoleCommandParser(std::string consoleCommand) { 
    if (consoleCommand.substr(0, consoleCommand.find(" ")).find("analyzer") != std::string::npos) {
        consoleCommand.erase(0, consoleCommand.substr(0, consoleCommand.find(" ")).length());
        
        int index = 0;
        while (consoleCommand[index] != '-') {
            if (consoleCommand[index] != ' ') {
                sourceDirectoryPath += consoleCommand[index];
            }
            
            index++;
        }
        index++;
        
        if (consoleCommand[index] == 'I')
            saveHeaderFilesPaths(consoleCommand, index);
    }
}


std::vector<std::string> ConsoleCommandParser::getHeadersDirectoryPaths() {
    return headersDirectoryPathsVect;
}


std::string ConsoleCommandParser::getSourcesDirectoryPath() { 
    return sourceDirectoryPath;
}

void ConsoleCommandParser::saveHeaderFilesPaths(std::string consoleCommand, int index) {
    while (index < consoleCommand.length()) {
        std::string headerFilesPath = "";
        while (consoleCommand[index] != '-' && index < consoleCommand.length()) {
            if (consoleCommand[index] != ' ' && consoleCommand[index] != 'I') {
                headerFilesPath += consoleCommand[index];
            }
            index++;
        }
        headersDirectoryPathsVect.push_back(headerFilesPath);
        index++;
    }
}
