#include "lib.h"

Run igual(const generic a, const generic b, const Aditional &ad) {}

Run funcao(const generic a, const generic b, const Aditional &ad) {
    Run ret;

    if (a.res == "end-of") {
        vector<pendent> r;

        for (const auto &item: ad.pendent) {
            if (item.name != b.res) {
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
        v.name = a.res;
        v.action = "pass";

        ret.pendent.push_back(v);
    }

    return ret;
}

Run classe(const generic a, const generic b, const Aditional &ad) {}

Run globalVar(const generic a, const generic b, const Aditional &ad) {}

Run scopeVar(const generic a, const generic b, const Aditional &ad) {}

Run mais(const generic a, const generic b, const Aditional &ad) {

}

vector<Op> getBaseOperations() {
    vector<Op> ops;

    ops.push_back({mais, 1, "+", {numberQ, stringQ}, {numberQ, stringQ, charQ}});

    return ops;
}