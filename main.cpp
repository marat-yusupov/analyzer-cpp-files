#include <iostream>
#include <string>
#include "ConsoleCommandParser.hpp"
#include "PathsHandler.hpp"
#include "FileHandler.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string consoleCommand;
    
    cout << "command: \n" << endl;
    cout << "analyzer <source path> [options]" << endl;
    cout << "[options] : -I <path> - for .hpp files \n" << endl;
    cout << "input console command: \n" << endl;

// example: analyzer /Users/maratyusupov/MatrixTask -I /Users/maratyusupov/test

    getline(cin, consoleCommand);
    ConsoleCommandParser commandParser(consoleCommand);
    PathsHandler pathHandler(commandParser.getSourcesDirectoryPath(), commandParser.getHeadersDirectoryPaths());
    FileHandler fileHandler(pathHandler.getSourceFiles(), pathHandler.getHeaderFiles());
    
    cout << endl;
    
    for (int i = 0; i < fileHandler.getFilesTree().size(); i++) {
        cout << fileHandler.getFilesTree()[i] << endl;
    }
    
    cout << endl;
    
    fileHandler.findCountOfInclusions();
    for (auto elem : fileHandler.getFileInclusions()) {
        cout << elem.first << " " << elem.second << endl;
    }
    
    return 0;
}
