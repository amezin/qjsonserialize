#include "common.h"

#include <string>

int stdwstring_deserialize(int, char *[])
{
    static const std::wstring expected(L"Hello, World!");
    std::wstring s;
    QJsonValue json(QString::fromStdWString(expected));
    VERIFY(qjsonserialize::deserialize(json, s));
    VERIFY(s == expected);
    return 0;
}