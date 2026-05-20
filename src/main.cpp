#include <iostream>
#include <CLI/CLI.hpp>
#include "TestDiscovery.h"

int main(int argc, char** argv) {
    CLI::App app{"Mini Regression Framework"};
    argv = app.ensure_utf8(argv);

    std::string testDir;
    app.add_option("test-dir", testDir, "Directory to search for tests")->required();

    app.set_help_flag("--help", "Show this help message");
    CLI11_PARSE(app, argc, argv);

    auto tests = discoverTests(testDir);

    for (auto& tc : tests) {
        std::cout << tc.name << "  " << tc.path << "\n";
    }

    return 0;
}
