#include <cxxabi.h>
#include <memory>

#include "demangle.hpp"

namespace ext {

std::string demangle(const std::string& name)
    {
    int status = -4;
    std::unique_ptr<char,decltype(free)*> result_buf( abi::__cxa_demangle( name.c_str(), NULL, NULL, &status ), free );
    switch ( status )
        {
        case 0:
            return result_buf.get();
        case -1:
            return "A memory allocation failiure occurred.";
        case -2:
            return std::string( name ) + " is not a valid name under the C++ ABI mangling rules.";
        case -3:
            return "One of the arguments is invalid.";
        default:
            return "unknown error";
        }
    }

std::string demangle(const std::type_info& type)
    {
    return demangle(type.name());
    }

std::string demangle(const std::type_index& idx)
    {
    return demangle(idx.name());
    }

} // ns ext
