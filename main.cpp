#include "operations.h"

void formatHelp(string& c, bool& mult, bool& mf, bool& mfa, bool& need, string& mulul, string& res, bool& suc) {
    if (c == "[" || c == "]") need = !need;

    if (c == "(") mult = true;

    if (c == ")") {
        if (mf) {
            if (!mfa) {
                cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\n";
                suc = false;
            }
        }

        res += mulul;
        mult = false;
        mulul = "";
        mf = false;
        mfa = true;
    }
}

generic format(string s, string f, vector<type> v) {
    generic ret = {"", true};
    int k = 0;
    bool need = true;
    bool mult = false;
    bool mf = false;
    bool mfa = true;
    string mulul;
    bool any = false;

    for (int i = 0; i < s.length(); ++i) {
        if (!ret.suc) break;

        string a;
        string m = cts(s[i]);
        type b;

        if (s[i-1] == '\\') {
            s = s.substr(0, i-1) + s.substr(i, s.length());
            cout << "s: " + s + ";\n";
            m = R"(\)" + m;
            i--;

            cout << "i: " << i << ";\n";
        }

        for (int i2 = k; i2 < f.length(); ++i2) {
            string c = cts(f[i2]);

            formatHelp(c, mult, mf, mfa, need, mulul, ret.res, ret.suc);
            if (includeOnly(c, "([])")) {
                k++;
                continue;
            }

            a = c;

            b = {c, c, "s"};
            for (const auto &item: v) {
                if (item.name == a) b = item;
            }

            break;
        }

        cout << "b: " << b.value << ", " << b.name << ", " << b.compare(m, b.value) << ", " << m << ";\n";

        if (b.compare(m, b.value)) {
            if (!mult) ret.res += cts(s[i]);
            else {
                cout << "S\n";
                mulul += cts(s[i]);
                mfa = false;
            }

            any = true;

            if (b.type == "s" && !mult) k++;
        } else {
            if (!any && need) {
                ret.suc = false;
            }

            if (mult && !any) {
                cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA: " << b.name << "\n;";
                mf = true;
            }

            k++;
            i--;
            any = false;
        }
    }

    if (mult && f[k+1] != ')') ret.suc = false;

    cout << "res: " << ret.res << ";\n";

    for (int i2 = k+1; i2 < f.length(); ++i2) {
        string c = cts(f[i2]);

        formatHelp(c, mult, mf, mfa, need, mulul, ret.res, ret.suc);

        cout << "need: " << need << ", i: " << i2 << ", c: " << c << ";\n";
        if (need && c != "]") {
            ret.suc = false;
            break;
        }
    }

    return ret;
}

string parsemain(string code, vector<variable> all) {

}

bool compareString(string me, string value) {
    if (me == "\"") return false;

    return true;
}

int main(int argc, char** argv) {
    bool runDef = false;

    if (runDef) {
        if (argc >= 2) {
            ifstream ifs(argv[1]);
            string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));

            parsemain(content, {});
        } else {
            vector<variable> vars;

            while (true) {
                string cmd;

                cout << "command: ";

                getline(cin, cmd);

                if (cmd == "->stop") break;

                //wfkit wkit = parsemain(cmd, vars);

                //vars = wkit.all;
            }
        }
    }

    vector<type> v;

    v.push_back({"N", "0123456789", "m", includeAny});
    v.push_back({"L", "", "m", compareString});

    //cout << "g: " << format(R"(-12345f)", R"([-]N[(.N)][f])", v).suc << ";\n";
    cout << "g: " << format(R"("aab\"")", R"("L")", v).suc << ";\n";

    return 0;
}

