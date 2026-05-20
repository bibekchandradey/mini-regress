#include "TestDiscovery.h"
#include <algorithm>

std::vector<TestCase> discoverTests(const std::filesystem::path& dir) {
    std::vector<TestCase> tests;

    for (auto& entry : std::filesystem::recursive_directory_iterator(dir)) {
        if (!entry.is_regular_file()) continue;

        // skip hidden files
        if (entry.path().filename().string().starts_with('.')) continue;

        // check execute permission
        auto perms = entry.status().permissions();
        bool isExec = (perms & std::filesystem::perms::owner_exec) != std::filesystem::perms::none;
        if (!isExec) continue;

        TestCase tc;
        tc.name = entry.path().stem().string();
        tc.path = entry.path();
        tc.timeout = 30;
        tests.push_back(tc);
    }

    // sort alphabetically by name
    std::sort(tests.begin(), tests.end(), [](const TestCase& a, const TestCase& b) {
        return a.name < b.name;
    });

    return tests;
}
