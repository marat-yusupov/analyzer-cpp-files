#include <stdio.h>
#include <string>
#include <vector>

class ConsoleCommandParser {
public:
    ConsoleCommandParser(std::string consoleCommand);
    
    std::string getSourcesDirectoryPath();
    std::vector<std::string> getHeadersDirectoryPaths();
    
private:
    std::vector<std::string> headersDirectoryPathsVect;
    std::string sourceDirectoryPath;

    void saveHeaderFilesPaths(std::string consoleCommand, int index);
};
