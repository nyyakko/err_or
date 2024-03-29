#include <gtest/gtest.h>

#include <err_or/ErrorOr.hpp>
#include <err_or/types/TraceError.hpp>

using namespace error;

TEST(compile_time, convert_to_string_implicitly)
{
    (void)[] () -> ErrorOr<std::string> {
        return "69420";
    };
}

TEST(compile_time, convert_to_pair_implicitly)
{
    (void)[] () -> ErrorOr<std::pair<int, std::string>> {
        return {{ 69, "420" }};
    };
}

TEST(compile_time, non_default_error_type)
{
    (void)[] () -> ErrorOr<void, TraceError> {
        return make_error<TraceError>("error");
    };
}

