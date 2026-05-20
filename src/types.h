#pragma once

#include <filesystem>
#include <chrono>
#include <string>

enum class TestStatus {
    PASS,
    FAIL,
    TIMEOUT,
    ERROR
};

struct TestCase {
    std::string name;
    std::filesystem::path path;
    int timeout = 30;
};

struct TestResult {
    TestStatus status;
    std::chrono::milliseconds duration;
    std::string stdout_output;
    std::string stderr_output;
    int exit_code;
};
