#include "simple_logger.h"

#include <iostream>

SimpleLogger::SimpleLogger(const std::string& log_file_path)
    : _log_file_path(log_file_path), _ofs(log_file_path) {
    if (!_ofs) {
        std::cerr << "Error: trying to place log file in nonexistent directory, "
                  << "please create the required directory" << std::endl;
        std::cerr << "log file path: " << log_file_path << std::endl;
    }
    _ofs << std::boolalpha;
}
