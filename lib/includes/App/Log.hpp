#pragma once
#include <spdlog/spdlog.h>
// Third-party library, required for log output
// GitHub: https://github.com/gabime/spdlog
namespace Log {
// Determining whether the NDEBUG preprocessor exists
// If not defined, we do not use a function from a third-party library
// There is no output of logs if the project is set to Release
#ifdef NDEBUG

#define LOG_INFO(...)	
#define LOG_ERROR(...)	
#define LOG_WARN(...)	
#define LOG_CRITICAL(...)	

#else

#define LOG_INFO(...)	spdlog::info(__VA_ARGS__)
#define LOG_ERROR(...)	spdlog::error(__VA_ARGS__)
#define LOG_WARN(...)	spdlog::warn(__VA_ARGS__)
#define LOG_CRITICAL(...)	spdlog::critical(__VA_ARGS__)

#endif // NDEBUG
}