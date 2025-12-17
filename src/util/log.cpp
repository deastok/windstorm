#include "windstorm/log.h"

#include <iostream>

namespace windstorm::util {
    namespace {
        bool g_quiet = false;

        std::ostream &stream_for(Level level) {
            return (level == Level::Error) ? std::cerr : std::cout;
        }

        std::string_view prefix(Level level) {
            switch (level) {
                case Level::Info: return "[info] ";
                case Level::Warn: return "[warn] ";
                case Level::Error: return "[error] ";
            }
            return "";
        }
    }

    void set_quiet(bool quiet) {
        g_quiet = quiet;
    }

    void log(Level level, std::string_view msg) {
        if (g_quiet && level != Level::Error) return;
        stream_for(level) << prefix(level) << msg << "\n";
    }
}
