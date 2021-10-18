#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class PathsHandler {
public:
    PathsHandler(std::string sourcesDirectoryPath, std::vector<std::string> headersDirectoryPath);
    
    std::map<std::string, std::string> getSourceFiles();
    std::map<std::string, std::string> getHeaderFiles();
    
private:
    std::string sourcePath;
    
    std::map<std::string, std::string> sourceFiles;
    std::map<std::string, std::string> headerFiles;
//    std::vector<std::string> sourceFiles;
//    std::vector<std::string> headerFiles;
    
    void saveFilePaths(std::string extension, std::string directoryPath, std::map<std::string, std::string> &filesMap);
};
