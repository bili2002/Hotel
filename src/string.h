#pragma once

#include <iostream>
#include <algorithm>

#include "vector.h"

std::istream& operator>>(std::istream& in, MyVector<char>& str);
std::ostream& operator<<(std::ostream& out, const MyVector<char>& str);

MyVector<char> toString(int n);
int toInt(MyVector<char> str);
