#pragma once

#include <string>
#include <utility>
#include <vector>

#include <queue>

using User = std::pair<std::string, std::string> ;

std::string matchmake(std::queue<User> q, User user);