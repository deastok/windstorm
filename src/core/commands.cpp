#include "windstorm/commands.h"
#include "windstorm/version.h"

#include <iostream>

namespace windstorm::core::cmd {
    int help() {
        std::cout << R"(windstorm - CLI prototype

usage:
    windstorm <command>
    windstorm [--help] [--version]

commands:
    help      show this help
    version   print version
    status    print current status (not impl)

options:
    --help, -h      show help
    --version, -v   print version
)";
        return 0;
    }

    int version() {
        std::cout << "windstorm " << windstorm::core::version() << "\n";
        return 0;
    }

    int status() {
        std::cout << "status: (not impl)\n";
        return 0;
    }
}
