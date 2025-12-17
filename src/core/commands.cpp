#include "windstorm/commands.h"
#include "windstorm/version.h"
#include "windstorm/log.h"

#include <iostream>


namespace windstorm::core::cmd {
    int help() {
        std::cout << R"(windstorm - CLI prototype

usage:
    windstorm <command> [options]
    windstorm [--help] [--version] [--quiet]

commands:
    help      show this help
    version   print version
    status    print current status (not impl)

options:
    --help, -h      show help
    --version, -v   print version
    --quiet, -q     suppress non-error output
)";
        return 0;
    }

    int version() {
        std::cout << "windstorm " << core::version() << "\n";
        return 0;
    }

    int status() {
        util::info("status: (not impl)");
        return 0;
    }
}
