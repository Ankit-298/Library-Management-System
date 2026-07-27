#include "Utility.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>

namespace Utility {

    bool isValidDate(const std::string& date) {
        if (date.length() != 10) return false;
        if (date[4] != '-' || date[7] != '-') return false;
        for (int i = 0; i < 10; ++i) {
            if (i == 4 || i == 7) continue;
            if (!isdigit(date[i])) return false;
        }
        
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));
        
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) return false;
        } else if (month == 2) {
            bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
            if (isLeap && day > 29) return false;
            if (!isLeap && day > 28) return false;
        }
        return true;
    }

    bool isLeapYear(int y) {
        return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
    }

    int dateToDays(int y, int m, int d) {
        int days = d;
        int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < m; ++i) {
            days += mdays[i];
            if (i == 2 && isLeapYear(y)) {
                days++;
            }
        }
        days += 365 * y + (y / 4) - (y / 100) + (y / 400);
        return days;
    }

    int dateDifferenceInDays(const std::string& date1, const std::string& date2) {
        int y1 = std::stoi(date1.substr(0, 4));
        int m1 = std::stoi(date1.substr(5, 2));
        int d1 = std::stoi(date1.substr(8, 2));
        
        int y2 = std::stoi(date2.substr(0, 4));
        int m2 = std::stoi(date2.substr(5, 2));
        int d2 = std::stoi(date2.substr(8, 2));
        
        return dateToDays(y2, m2, d2) - dateToDays(y1, m1, d1);
    }

    int getValidInt() {
        int num;
        while (true) {
            std::string input;
            std::getline(std::cin, input);
            input = trim(input);
            if (input.empty()) continue;
            try {
                size_t pos;
                num = std::stoi(input, &pos);
                if (pos == input.length()) {
                    return num;
                }
            } catch (...) {
            }
            std::cout << "Invalid input. Please enter a valid integer: ";
        }
    }

    int getValidID() {
        while (true) {
            int id = getValidInt();
            if (id > 0) return id;
            std::cout << "ID must be a positive integer. Please enter again: ";
        }
    }

    int getValidYear() {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int currentYear = now->tm_year + 1900;

        while (true) {
            int year = getValidInt();
            if (year > 0 && year <= currentYear) {
                return year;
            }
            std::cout << "Invalid year. Please enter a valid year up to " << currentYear << ": ";
        }
    }

    std::string getValidString() {
        std::string str;
        while (true) {
            std::getline(std::cin, str);
            str = trim(str);
            if (str.empty()) {
                std::cout << "Input cannot be empty. Please enter a valid string: ";
                continue;
            }
            if (str.find('|') != std::string::npos) {
                std::cout << "Character '|' is reserved and cannot be used. Please enter again: ";
                continue;
            }
            return str;
        }
    }

    bool isValidPhone(const std::string& phone) {
        if (phone.empty()) return false;
        for (char c : phone) {
            if (!isdigit(c) && c != '+' && c != '-' && c != ' ' && c != '(' && c != ')') {
                return false;
            }
        }
        return true;
    }

    bool isValidEmail(const std::string& email) {
        if (email.empty()) return false;
        auto atPos = email.find('@');
        auto dotPos = email.rfind('.');
        if (atPos == std::string::npos || dotPos == std::string::npos) return false;
        if (atPos == 0 || dotPos == email.length() - 1 || atPos > dotPos) return false;
        return true;
    }

    std::string trim(const std::string& str) {
        auto start = str.find_first_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        auto end = str.find_last_not_of(" \t\n\r");
        return str.substr(start, end - start + 1);
    }
    
    std::vector<std::string> split(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
}
