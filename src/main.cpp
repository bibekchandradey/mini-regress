#include <iostream>
#include <CLI/CLI.hpp>

int main(int argc, char** argv) {
    CLI::App app{"Mini Regression Framework"};
    argv = app.ensure_utf8(argv);

    app.set_help_flag("--help", "Show this help message");

    CLI11_PARSE(app, argc, argv);

    std::cout << "regress: ok" << std::endl;
    return 0;
}
