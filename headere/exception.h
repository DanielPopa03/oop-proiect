#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
#include <fstream>
#include <exception>


class EnterException : public std::exception {
public:
    const char* what() const noexcept {
        return "\n YOU MUST ENTER A VALID NUMBER!! \n";
    }
};

class DeleteException : public std::exception {
public:
    const char* what() const noexcept {
        return "\n YOU CANNOT DELETE!! \n";
    }
};

#endif
