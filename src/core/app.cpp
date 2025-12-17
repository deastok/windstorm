#include "windstorm/app.h"
#include "windstorm/commands.h"
#include "windstorm/log.h"

#include <string_view>
#include <string>


namespace windstorm::core {
    int run(int argc, char **argv) {
        for (int i = 1; i < argc; ++i) {
            std::string_view a = argv[i];
            if (a == "--quiet" || a == "-q") {
                util::set_quiet(true);
            }
        }

        if (argc < 2) {
            return cmd::help();
        }

        std::string_view command;
        for (int i = 1; i < argc; ++i) {
            std::string_view a = argv[i];
            if (!a.empty() && a[0] == '-') continue;
            command = a;
            break;
        }

        if (command.empty()) {
            for (int i = 1; i < argc; ++i) {
                std::string_view a = argv[i];
                if (a == "--help" || a == "-h") return cmd::help();
                if (a == "--version" || a == "-v") return cmd::version();
            }
            return cmd::help();
        }

        if (command == "help") return cmd::help();
        if (command == "version") return cmd::version();
        if (command == "status") return cmd::status();

        util::error(std::string("Unknown command: ") + std::string(command));
        return 2;
    }
}
