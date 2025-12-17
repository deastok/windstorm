#include <iostream>
#include <string_view>

#include "windstorm/version.h"

namespace {
constexpr std::string_view help_menu = R"(windstorm - CLI prototype

usage:
    windstorm [--help] [--version]

options:
    --help      show this help
    --version   print version
)";
}

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::string_view arg = argv[1];

        if (arg == "--help" || arg == "-h") {
            std::cout << help_menu;
            return 0;
        }

        if (arg == "--version" || arg == "-v") {
            std::cout << "windstorm " << windstorm::core::version() << "\n";
            return 0;
        }

        std::cerr << "Unknown argument: " << arg << "\n\n" << help_menu;
        return 2;
    }

    std::cout << "windstorm " << windstorm::core::version() << "\n";
    std::cout << "Run with --help for usage.\n";
    return 0;
}