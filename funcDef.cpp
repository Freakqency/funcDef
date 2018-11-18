#include <regex>
#include <string>
#include <iostream>
using namespace std;

unsigned int func(const char* strFunctionName, const char* strSourceCode )
{
    int funcIndex;
    string n(strFunctionName);
    string pat = R"(\s*\([\w, ]*\)\s*\{)";
    pat.insert(0, n);
    regex r(pat);
    regex rx(R"(\\n)");
    string s(strSourceCode);
    for (std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), r); i != std::sregex_iterator(); ++i)
        funcIndex = i->position();
    if (funcIndex == 0)
        return 0;
    else {
        std::ptrdiff_t const countNewline(std::distance(std::sregex_iterator(s.begin(), s.begin() + funcIndex, rx), std::sregex_iterator()));
        return countNewline + 1;
    }
}

int main()
{
    char strFunctionName[] = "func2";
    char strSourceCode[] = "int func1(){ return 0; }\\n int func2(){ return 1; }\\n"
                           "int main(int argc, char*argv[]){ return func2(); }\\n";
    int c = func(strFunctionName, strSourceCode);
    cout << c;
}
