#include "windstorm/app.h"
#include "windstorm/commands.h"

#include <iostream>
#include <string_view>


namespace windstorm::core {
    int run(int argc, char **argv) {
        if (argc < 2) {
            return cmd::help();
        }

        std::string_view a1 = argv[1];

        if (a1 == "--help" || a1 == "-h") return cmd::help();
        if (a1 == "--version" || a1 == "-v") return cmd::version();

        if (a1 == "help") return cmd::help();
        if (a1 == "version") return cmd::version();
        if (a1 == "status") return cmd::status();

        std::cerr << "Unknown command: " << a1 << "\n\n";
        return cmd::help() == 0 ? 2 : 2;
    }
}
