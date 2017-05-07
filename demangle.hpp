#pragma once
#include <string>
#include <typeindex>

namespace ext {

std::string demangle(const std::string& name);
std::string demangle(const std::type_info& type);
std::string demangle(const std::type_index& idx);

}
