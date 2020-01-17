/*
 * SimpleLogger: an extremely simple C++ logging class. Does not have logging levels.
 *
 * Sample usage:
 *   SimpleLogger logger("my_log.txt");
 *   logger.Log("Input vector: ", input_vector);
 *   logger.LogAndPrint(std::cout, "Result: ", RunAlgorithm(input_vector));
 *
 * Notes:
 *  - At logger construction, log file is created if doesn't exist, and cleared if it does exist
 *  - Log and LogAndPrint support variable number of arguments
 *  - Stream insertion operator (<<) must be defined for all types given to Log/LogAndPrint
 *  - Stream insertion operator for std::vector is included in simple_logger.h
 */

#pragma once

#include <fstream>
#include <ostream>
#include <string>
#include <vector>

namespace {

// Stream insertion for std::vector (so Logger can write vectors automatically)
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

// Specialization for vector of strings
inline std::ostream& operator<<(std::ostream& os, const std::vector<std::string>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << "\"" << v[i] << "\"";
        if (i + 1 < v.size()) os << ", ";
    }
    os << "]";
    return os;
}

}  // namespace

class SimpleLogger {
  public:
    // Creates log file if it does not exist, clears log file if it already exists
    SimpleLogger(const std::string& log_file_path);

    // Only log
    template <typename T>
    void Log(T t);

    template <typename T, typename... Args>
    void Log(T t, Args... args);

    // Log and print
    template <typename T>
    void LogAndPrint(std::ostream& os, T t);
    
    template <typename T, typename... Args>
    void LogAndPrint(std::ostream& os, T t, Args... args);

  private:
    std::string _log_file_path;
    std::ofstream _ofs;
};

template <typename T>
void SimpleLogger::Log(T t) {
    _ofs << t << std::endl;
}

template <typename T, typename... Args>
void SimpleLogger::Log(T t, Args... args) {
    _ofs << t;
    Log(args...);
}

template <typename T>
void SimpleLogger::LogAndPrint(std::ostream& os, T t) {
    _ofs << t << std::endl;
    os << t << std::endl;
}

template <typename T, typename... Args>
void SimpleLogger::LogAndPrint(std::ostream& os, T t, Args... args) {
    _ofs << t;
    os << t;
    LogAndPrint(os, args...);
}
