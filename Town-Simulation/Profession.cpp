#include "Profession.h"

Profession::Profession(const std::string& type){
    this->type = type;
}

const std::string& Profession::get_type() const{
    return type;
}
