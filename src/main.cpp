#include <iostream>
#include "register.hpp"

int main() {
    // ---- ACC TEST ----
    {
        ACC acc;
        Binary data = {1,0,1,0,1,0,1,0};

        acc.setControl(true, false);  // load on
        acc.LOAD(data);
        acc.setControl(false, true);  // output on

        std::cout << "[ACC READ] ";
        for (bool bit : acc.READ()) std::cout << bit;
        std::cout << "\n";

        acc.CLEAR();
        std::cout << "[ACC CLEAR] ";
        for (bool bit : acc.READ()) std::cout << bit;
        std::cout << "\n";
    }

    // ---- GR TEST ----
    {
        GR gr;
        Binary data = {0,1,0,1,0,1,0,1};

        gr.setControl(true, false);
        gr.LOAD(data);
        gr.setControl(false, true);

        std::cout << "[GR READ] ";
        for (bool bit : gr.READ()) std::cout << bit;
        std::cout << "\n";

        gr.CLEAR();
        std::cout << "[GR CLEAR] ";
        for (bool bit : gr.READ()) std::cout << bit;
        std::cout << "\n";
    }

    // ---- FR TEST ----
    {
        FR fr;
        Flags f = {true, false, true, false}; // C, Z, N, V

        fr.setControl(true);
        fr.LOAD(f);

        auto out = fr.READ();
        std::cout << "[FR READ] "
                  << "C:" << out.C << " "
                  << "Z:" << out.Z << " "
                  << "N:" << out.N << " "
                  << "V:" << out.V << "\n";

        fr.CLEAR();
        out = fr.READ();
        std::cout << "[FR CLEAR] "
                  << "C:" << out.C << " "
                  << "Z:" << out.Z << " "
                  << "N:" << out.N << " "
                  << "V:" << out.V << "\n";
    }

    return 0;
}
