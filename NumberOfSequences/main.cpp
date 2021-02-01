#define CAIDE_STDIN 1
#define CAIDE_STDOUT 1
#include <fstream>
#include <iostream>

#ifdef CAIDE_IN_PATTERN
#if __cplusplus < 201703L
#define CAIDE_STDIN
#undef CAIDE_IN_PATTERN
#else

#include <filesystem>
#include <regex>
#include <stdexcept>

std::string getLatest() {
    using namespace std::filesystem;

    std::string f;
    file_time_type t;

    std::regex regex(CAIDE_IN_PATTERN);

    for (const auto& p : directory_iterator(".")) {
        if (!p.is_regular_file())
            continue;
        auto fileName = p.path().filename().string();
        if (!std::regex_match(fileName, regex))
            continue;
        auto curTime = p.last_write_time();
        if (f.empty() || t < curTime) {
            f = fileName;
            t = curTime;
        }
    }

    if (f.empty())
        throw std::runtime_error("Input file not found");
    return f;
}
#endif
#endif

void solve(std::istream& in, std::ostream& out);
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#ifdef LOCAL
	std::cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
#endif

#if defined(CAIDE_STDIN)
    std::istream& in = std::cin;
#elif defined(CAIDE_IN_PATTERN)
    std::ifstream in(getLatest());
#else
    std::ifstream in(CAIDE_IN_FILE);
#endif

#ifdef CAIDE_STDOUT
    std::ostream& out = std::cout;
#else
    std::ofstream out(CAIDE_OUT_FILE);
#endif
    solve(in, out);
    return 0;
}

