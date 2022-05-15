#include "string.h"

std::istream& operator>>(std::istream& in, MyVector<char>& str) {
    char temp = ' ';

    while (isspace(temp) && in.good()) {
        in.get(temp);
    };

    while (!isspace(temp) && in.good()) {
        str.push_back(temp);
        in.get(temp);
    };

    return in;
}

std::ostream& operator<<(std::ostream& out, const MyVector<char>& str) {
    for (auto ch : str) {
        out<<ch;
    }

    return out;
}

MyVector<char> toString(int n) {
    MyVector<char> temp;

    while (n) {
        temp.push_back(n%10 - '0');
        n /= 10;
    }

    std::reverse(temp.begin(), temp.end());
    return temp;
}

int toInt(MyVector<char> str) {
    int n = 0;
    int pow10 = 1;

    while (!str.empty()) {
        n = (str.pop_back() - '0') * pow10;
        pow10 *= 10;
    }

    return n;
}
