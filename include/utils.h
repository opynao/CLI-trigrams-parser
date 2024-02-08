#pragma once
#include <iostream>

#define LOGF std::cerr << __FUNCTION__ << " = " << __LINE__ << std::endl
#define PR(x) std::cout << #x << " = " << x << std::endl
