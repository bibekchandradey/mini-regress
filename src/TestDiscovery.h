#pragma once
#include <vector>
#include <filesystem>

struct TestCase {
    std::string name;
    std::filesystem::path path;
    int timeout = 30;
};

std::vector<TestCase> discoverTests(const std::filesystem::path& directory);
