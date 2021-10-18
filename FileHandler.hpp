#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class FileHandler {
public:
    FileHandler(std::map<std::string, std::string> sourceFiles, std::map<std::string, std::string> headerFiles);
    std::vector<std::string> getFilesTree();
    std::map<std::string, int> getFileInclusions();
    void findCountOfInclusions();
private:
    std::vector<std::string> files;
    std::vector<std::string> filesTree;
    std::map<std::string, int> fileInclusions;
    void findDependencies(std::ifstream &file, std::map<std::string, std::string> &headerFiles);
    int countOfDots = 0;
};
