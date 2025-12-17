#ifndef WINDSTORM_LOG_H
#define WINDSTORM_LOG_H

#include <string_view>

namespace windstorm::util {
    enum class Level {
        Info, Warn, Error
    };

    void set_quiet(bool quiet);

    void log(Level level, std::string_view msg);

    inline void info(std::string_view m) {
        log(Level::Info, m);
    }

    inline void warn(std::string_view m) {
        log(Level::Warn, m);
    }

    inline void error(std::string_view m) {
        log(Level::Error, m);
    }
}

#endif //WINDSTORM_LOG_H
