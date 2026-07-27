#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

namespace Utility {
    // Date validation (YYYY-MM-DD format check)
    bool isValidDate(const std::string& date);

    // Date difference (in days) (Format: YYYY-MM-DD)
    int dateDifferenceInDays(const std::string& date1, const std::string& date2);

    // Input validation (integers)
    int getValidInt();

    // Input validation (positive integers for IDs)
    int getValidID();

    // Input validation (valid year)
    int getValidYear();

    // Input validation (non-empty strings)
    std::string getValidString();

    // Phone validation (basic digit check)
    bool isValidPhone(const std::string& phone);

    // Email validation (basic @ and . check)
    bool isValidEmail(const std::string& email);

    // String trimming
    std::string trim(const std::string& str);
    
    // Split string
    std::vector<std::string> split(const std::string& str, char delimiter);
}

#endif // UTILITY_H
