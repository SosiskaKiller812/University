#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <string_view>

struct StringHash{
    using is_transparent = void;

    size_t operator()(const std::string &s) const;
    size_t operator()(std::string_view sv) const;
    size_t operator()(const char *s) const;
};

int getDistance(std::unordered_map<std::string, int, StringHash, std::equal_to<>> &map);
void addCity(std::unordered_map<std::string, int, StringHash, std::equal_to<>> &map);