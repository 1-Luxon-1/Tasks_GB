#include "parsetext.h"
#include "qalgorithms.h"
ParseText::ParseText(QString textStr)
{
    str=textStr;
}

QString ParseText::parse()
{
    str = str.toUpper();
    if(str=="RUB")
    {
        return QString::fromUtf8("\u20BD");
    }
    if(str=="EURO")
    {
        return QString::fromUtf8("\u20AC");
    }
    if(str=="AUTHORSHIP")
    {
        return QString::fromUtf8("\u00A9");
    }
    if(str=="PERMILL")
    {
        return QString::fromUtf8("\u2030");
    }
    else
    {
        return "NotInTheDatabase";
    }
}

