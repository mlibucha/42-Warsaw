#pragma once

#include <list>
#include <string>

namespace Utils {
std::list<std::string> SplitStringToString(const std::string &stack,
                                           const char delimitor);
std::list<int> SplitStringToInt(const std::string &stack,
                                           const char delimitor);

} // namespace Utils
