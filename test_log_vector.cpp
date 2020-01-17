#include <iostream>
#include <string>
#include <vector>

#include "simple_logger.h"

const std::string kLogFilepath = "vector_test.log";

int main() {
    std::vector<int> int_vector{1, 1, 2, 3, 5, 8, 13};
    
    SimpleLogger logger(kLogFilepath);
    logger.Log("Log only: ", int_vector);
    logger.LogAndPrint(std::cout, "Log and print: ", int_vector);
    
    return 0;
}
    
