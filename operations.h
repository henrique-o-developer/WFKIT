#include "lib.h"

Run igual(const vector<StringAndInt> &a, const vector<StringAndInt> &b, const Aditional &ad) {}

Run funcao(const vector<StringAndInt> &a, const vector<StringAndInt> &b, const Aditional &ad) {
    Run ret;

    if (a[0].s == "end-of") {
        vector<pendent> r;

        for (const auto &item: ad.pendent) {
            if (item.name != b[0].s) {
                r.push_back(item);
                continue;
            }

            cout << "v: " << item.value << ";\n";
        }
    } else {
        ret.pendent = ad.pendent;

        pendent v;

        v.value = ad.s.substr(ad.max, ad.s.length()).find(';');
        v.type = "function";
        v.name = a[0].s;
        v.action = "pass";

        ret.pendent.push_back(v);
    }

    return ret;
}

Run classe(const vector<StringAndInt> &a, const vector<StringAndInt> &b, const Aditional &ad) {}

Run globalVar(const vector<StringAndInt> &a, const vector<StringAndInt> &b, const Aditional &ad) {}

Run scopeVar(const vector<StringAndInt> &a, const vector<StringAndInt> &b, const Aditional &ad) {}

vector<Op> getBaseOperations() {
    vector<Op> ops;

    ops.push_back({funcao, 50, "function"});

    return ops;
}