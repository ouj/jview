#ifndef STDDIR_H_
#define STDDIR_H_

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir
#define rmdir _rmdir
#else
#include <unistd.h>
#include <sys/stat.h>
inline int _mkdir(const char* path, mode_t mode = 0755) {
    return mkdir(path, mode);
}
#endif

#include <string>
inline std::string getFileName(const std::string &path) {
    size_t split = path.find_last_of("/\\");
    return path.substr(split+1);
}

inline std::string getFolderName(const std::string &path) {
    size_t split = path.find_last_of("/\\");
    return path.substr(0, split+1);
}

inline std::string getFileBaseName(const std::string &filename) {
    size_t split = filename.find_last_of(".");
    return filename.substr(0, split);
}

inline std::string getFileExtension(const std::string &filename) {
    size_t split = filename.find_last_of(".");
    return filename.substr(split+1);
}

#endif
