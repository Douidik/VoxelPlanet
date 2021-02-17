#ifndef VOXENG_LOGGING_HPP
#define VOXENG_LOGGING_HPP

#include <fmt/core.h>
#include <fmt/color.h>

namespace VoxelEngine
{

constexpr fmt::text_style LOG_INFO_STYLE = fg(fmt::color::white);
constexpr fmt::text_style LOG_DEBUG_STYLE = fg(fmt::color::lime_green);
constexpr fmt::text_style LOG_WARN_STYLE = fg(fmt::color::orange_red);
constexpr fmt::text_style LOG_ERROR_STYLE = fg(fmt::color::red) | fmt::emphasis::bold;

template <typename... Args>
void LogPrint(fmt::text_style style, std::string_view message, Args &&...args)
{
    fmt::memory_buffer formatted = fmt::format(style, message, args...) + '\n';
    fmt::print(formatted.data());
}

} // namespace VoxelEngine

#define VOXENG_INFO_LOG(...) ::VoxelEngine::LogPrint(::VoxelEngine::LOG_INFO_STYLE, __VA_ARGS__)
#define VOXENG_DEBUG_LOG(...) ::VoxelEngine::LogPrint(::VoxelEngine::LOG_DEBUG_STYLE, __VA_ARGS__)
#define VOXENG_WARN_LOG(...) ::VoxelEngine::LogPrint(::VoxelEngine::LOG_WARN_STYLE, __VA_ARGS__)
#define VOXENG_ERROR_LOG(...) ::VoxelEngine::LogPrint(::VoxelEngine::LOG_ERROR_STYLE, __VA_ARGS__)

#endif
