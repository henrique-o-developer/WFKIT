#include <iostream>
#include <math.h>
#include <sstream>
#include <utility>
#include <vector>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

const string
    numberQ = R"([-]N[(.N)][f])",
    stringQ = R"("S")",
    charQ = R"('L')",
    variableQ = R"(:F:)"
;

struct Run;
struct Aditional;
struct StringAndInt;
struct variable;
struct generic;

struct pendent {
    int value;
    string type;
    string name;
    string action;
};

struct Op {
    Run (*r)(const generic a, const generic b, const Aditional &ad);
    int pri;
    string op;
    vector<string> a;
    vector<string> b;
};

struct Run {
    bool useA = true;
    bool useB = true;
    int aLe = -1;
    int bLe = -1;
    string ret;
};

struct Aditional {
    string& code;
    vector<variable>& all;
    vector<Op>& ops;
    int max;
    int min;
};

struct Operation {
    int min;
    int max;
    long long pri;
    bool exi;
    Op* obj;
    string ope;
};

struct StringAndInt {
    string s;
    int l;
};

struct variable {
    string type;
    string value;
    string name;
};

struct wfkit {
    vector<variable> all;
    vector<variable> scope;
    vector<pendent> pendent;
};

string replace(string s, string r, string R);
bool includeOnly(string s, string h) {
    bool ret = true;

    for (int i = 0; i < s.length(); i++) {
        bool ae = false;

        for (int j = 0; j < h.length(); j++) {
            if (s[i] == h[j]) ae = true;
        }

        if (!ae) ret = false;
    }

    return ret;
}

bool includeAny(string s, string h) {
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < h.length(); j++) {
            if (s[i] == h[j]) return true;
        }
    }

    return false;
}

bool include(string s, string h) {
    bool ret = false;

    for (int i = 0; i < s.length(); i++) {
        bool e = true;

        for (int j = 0; j < h.length(); j++) {
            if (s[i + j] != h[j]) e = false;
        }

        if (e) {
            ret = true;
        }
    }

    return ret;
}

string cts(char c) {
    stringstream ss;
    string s;

    ss << c;
    ss >> s;

    return s;
}

string catalog(string s) {
    if (s == "," || s == ";") return "mod";
    if (s == " " || s.empty()) return "null";
    if (s[s.length()-1] == ':' && s.length() > 2 && s[0] == ':') return "varType";
    if (includeOnly(s, "0123456789.-f")) return "number";
    if (includeOnly(s, "\"")) return "string";
    if (s == "int" || s == "string" || s == "float" || s == "bool" || s == "double") return "type";

    return s;
}

bool defaultCompare(string value, string you) {
    return value == you || value == catalog(you);
}

struct type {
    string name, value, type;
    bool (*compare)(string value, string you) = includeOnly;
};

struct generic {
    string res;
    bool suc;
};