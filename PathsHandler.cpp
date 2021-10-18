#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "PathsHandler.hpp"

namespace FileSystem = std::__fs::filesystem;

PathsHandler::PathsHandler(std::string sourcesDirectoryPath, std::vector<std::string> headerPaths) {
    if (!sourcesDirectoryPath.empty()) {
        saveFilePaths(".cpp", sourcesDirectoryPath, sourceFiles);
    }
    
    if (!headerPaths.empty()) {
        for (int i = 0; i < headerPaths.size(); i++) {
            saveFilePaths(".hpp", headerPaths[i], headerFiles);
        }
    }
}

void PathsHandler::saveFilePaths(std::string extension, std::string directoryPath, std::map<std::string, std::string> &filesMap) {
    for (const auto& p : FileSystem::recursive_directory_iterator(directoryPath)){
        if (!FileSystem::is_regular_file(p.status())) {
            std::string name(p.path().filename());
            saveFilePaths(extension, (directoryPath + '/' + name), filesMap);
            continue;
        }

        std::string name(p.path().filename());

        bool match = !name.compare(name.size() - extension.size(), extension.size(), extension);
        if (!match)
            continue;
        std::string path = directoryPath + '/' + name;
        filesMap.insert(make_pair(name, path));
    }
}

std::map<std::string, std::string> PathsHandler::getHeaderFiles() {
    return headerFiles;
}


std::map<std::string, std::string> PathsHandler::getSourceFiles() { 
    return sourceFiles;
}




