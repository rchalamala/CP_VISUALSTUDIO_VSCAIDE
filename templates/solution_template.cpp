#include "../cpplib/general/base.hpp"
#include "../cpplib/general/io.hpp"
#include "../cpplib/general/debug.hpp"
using namespace std;
// Powered by caide (code generator, tester, and library code inliner)

//#define INTERACTIVE
//#define CODE_JAM
//#define LIGHT_OJ

class Solution
{
	void output_case(std::ostream& out)
	{
		static std::int32_t _test_case = 0;
		out << "Case #";
		#ifdef CODE_JAM
		out << "#";
		#endif
		out << ++_test_case << ": ";
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		#if defined(CODE_JAM) || defined(LIGHT_OJ)
		output_case(out);
		#endif

	}
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}
