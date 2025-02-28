#include"Logger.h"

#include<spdlog/spdlog.h>
#include<spdlog/common.h>

std::shared_ptr<spdlog::logger> Logger::CoreLogger = nullptr;
std::shared_ptr<spdlog::logger> Logger::ClientLogger = nullptr;

void Logger::Init() {
        spdlog::set_pattern("[%T] %^[%l]%$ [%n]: %v ");

        CoreLogger = spdlog::stdout_color_mt("CoreLib");
        CoreLogger->set_level(spdlog::level::trace);

        ClientLogger = spdlog::stdout_color_mt("Client");
        ClientLogger->set_level(spdlog::level::trace);
}
