#define BOOST_TEST_MODULE test

#include "ip_filter.hpp"
#include <vector>
#include <tuple>
#include <boost/test/unit_test.hpp>
#include <iostream>

BOOST_AUTO_TEST_SUITE(test)

BOOST_AUTO_TEST_CASE(sample_test_sort)
{
    std::vector<std::tuple<int, int, int, int>> first_sample = {std::make_tuple(10, 10, 10, 10),
                                                                std::make_tuple(10, 10, 10, 9),
                                                                std::make_tuple(10, 10, 10, 11)};

    std::vector<std::tuple<int, int, int, int>> first_answer = {std::make_tuple(10, 10, 10, 11),
                                                                std::make_tuple(10, 10, 10, 10),
                                                                std::make_tuple(10, 10, 10, 9)};
    bool flag = true;
    sort(&first_sample);
    for (unsigned long long i = 0; i < first_sample.size(); i++)
    {
        if (first_sample[i] != first_answer[i])
        {
            flag = false;
        }
    }
    BOOST_CHECK(flag);
}

BOOST_AUTO_TEST_CASE(sample_test_ip_filter)
{
    std::vector<std::tuple<int, int, int, int>> second_sample = {std::make_tuple(113, 162, 145, 156),
                                                                std::make_tuple(157, 39, 22, 224),
                                                                std::make_tuple(79, 180, 73, 190),
                                                                std::make_tuple(179, 210, 145, 4),
                                                                std::make_tuple(219, 102, 120, 135),
                                                                std::make_tuple(67, 232, 81, 208),
                                                                std::make_tuple(85, 254, 10, 197),
                                                                std::make_tuple(23, 240, 215, 189),
                                                                std::make_tuple(1, 29, 168, 152),
                                                                std::make_tuple(185, 69, 186, 168),
                                                                std::make_tuple(110, 152, 103, 161),
                                                                std::make_tuple(185, 182, 81, 131),
                                                                std::make_tuple(68, 45, 152, 8),
                                                                std::make_tuple(114, 221, 179, 117),
                                                                std::make_tuple(185, 89, 100, 249),
                                                                std::make_tuple(46, 70, 113, 73),
                                                                std::make_tuple(188, 68, 0, 38),
                                                                std::make_tuple(119, 42, 115, 97),
                                                                std::make_tuple(194, 106, 108, 214),
                                                                std::make_tuple(24, 210, 239, 177),
                                                                std::make_tuple(166, 88, 193, 116),
                                                                std::make_tuple(62, 205, 202, 214),
                                                                std::make_tuple(188, 166, 87, 191),
                                                                std::make_tuple(103, 62, 147, 2),
                                                                std::make_tuple(95, 181, 177, 197),
                                                                std::make_tuple(95, 181, 177, 197),
                                                                std::make_tuple(149, 107, 0, 27),
                                                                std::make_tuple(182, 186, 69, 18),
                                                                std::make_tuple(73, 21, 168, 251),
                                                                std::make_tuple(113, 190, 198, 73)};

    std::vector<std::tuple<int, int, int, int>> second_answer = {std::make_tuple(1, 29, 168, 152),
                                                                std::make_tuple(185, 69, 186, 168),
                                                                std::make_tuple(73, 21, 168, 251)};

    bool flag = true;
    second_sample = filter_any(second_sample, 168);
    for (unsigned long long i = 0; i < second_sample.size(); i++)
    {
        if (second_sample[i] != second_answer[i])
        {
            flag = false;
        }
    }
    BOOST_CHECK(flag);
}

BOOST_AUTO_TEST_CASE(invalid_test)
{
    std::vector<std::tuple<int, int, int, int>> third_sample = {std::make_tuple(91, 15, 15, 33),
                                                                std::make_tuple(188, 72, 96, 184),
                                                                std::make_tuple(50, 254, 198, 161),
                                                                std::make_tuple(98, 219, 109, 151),
                                                                std::make_tuple(123, 133, 114, 213),
                                                                std::make_tuple(89, 177, 68, 136),
                                                                std::make_tuple(89, 177, 68, 136),
                                                                std::make_tuple(65, 208, 151, 112),
                                                                std::make_tuple(183, 198, 27, 25),
                                                                std::make_tuple(187, 189, 75, 118),
                                                                std::make_tuple(188, 212, 33, 157),
                                                                std::make_tuple(94, 240, 192, 2),
                                                                std::make_tuple(69, 160, 110, 157),
                                                                std::make_tuple(81, 198, 169, 232),
                                                                std::make_tuple(185, 89, 100, 47),
                                                                std::make_tuple(46, 182, 19, 219),
                                                                std::make_tuple(183, 88, 197, 193),
                                                                std::make_tuple(49, 74, 228, 23),
                                                                std::make_tuple(124, 224, 214, 76),
                                                                std::make_tuple(107, 185, 11, 105),
                                                                std::make_tuple(41, 235, 16, 95),
                                                                std::make_tuple(68, 37, 186, 197),
                                                                std::make_tuple(188, 72, 127, 199),
                                                                std::make_tuple(173, 171, 247, 113),
                                                                std::make_tuple(173, 171, 247, 113),
                                                                std::make_tuple(49, 35, 12, 51)};

    std::vector<std::tuple<int, int, int, int>> third_answer = {std::make_tuple(188, 72, 96, 184), std::make_tuple(188, 212, 33, 157)};

    bool flag = true;
    third_answer = filter(third_sample, 188);
    for (unsigned long long i = 0; i < third_sample.size(); i++)
    {
        if (third_sample[i] != third_answer[i])
        {
            flag = false;
        }
    }
    BOOST_CHECK(flag);
    
}

BOOST_AUTO_TEST_SUITE_END()