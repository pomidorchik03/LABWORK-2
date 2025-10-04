#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_ip(auto ip)
{
    std::cout << std::get<0>(*ip) << ".";
    std::cout << std::get<1>(*ip) << ".";
    std::cout << std::get<2>(*ip) << ".";
    std::cout << std::get<3>(*ip);
    std::cout << "\n";
}

void print_pool(auto ip_pool)
{
    for (std::vector<std::tuple<int, int, int, int>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        print_ip(ip);
    }
    std::cout << "\n";
}

void sort(auto *ip_pool)
{
    unsigned long long i = 1;
    unsigned long long j = 2;
    while (i < (*ip_pool).size())
    {
        if ((*ip_pool)[i - 1] > (*ip_pool)[i])
        {
            i = j;
            j++;
        }
        else
        {
            auto elem = (*ip_pool)[i];
            (*ip_pool)[i] = (*ip_pool)[i - 1];
            (*ip_pool)[i - 1] = elem;
            i--;
            if (i == 0)
            {
                i = j;
                j++;
            }
        }
    }
}

std::vector<std::tuple<int, int, int, int>> filter(auto ip_pool, int key)
{
    std::vector<std::tuple<int, int, int, int>> result = {};
    auto filter{[key](std::vector<std::tuple<int, int, int, int>>::const_iterator ip){ return std::get<0>(*ip) == key; }};
    for (std::vector<std::tuple<int, int, int, int>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if (filter(ip))
        {
            result.push_back(*ip);
        }
    }
    return result;
}

std::vector<std::tuple<int, int, int, int>> filter(auto ip_pool, int key1, int key2)
{
    std::vector<std::tuple<int, int, int, int>> result = {};
    auto filter_two{[key1, key2](std::vector<std::tuple<int, int, int, int>>::const_iterator ip){ return std::get<0>(*ip) == key1 && std::get<1>(*ip) == key2; }};
    for (std::vector<std::tuple<int, int, int, int>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if (filter_two(ip))
        {
            result.push_back(*ip);
        }
    }
    return result;
}

std::vector<std::tuple<int, int, int, int>> filter_any(auto ip_pool, int key)
{
    std::vector<std::tuple<int, int, int, int>> result = {};
    auto filter_any{[key](std::vector<std::tuple<int, int, int, int>>::const_iterator ip){ return std::get<0>(*ip) == key || std::get<1>(*ip) == key || std::get<2>(*ip) == key || std::get<3>(*ip) == key; }};
    for (std::vector<std::tuple<int, int, int, int>>::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if (filter_any(ip))
        {
            result.push_back(*ip);
        }
    }
    return result;
}

int cimus()
{
    try
    {
        std::vector<std::tuple<int, int, int, int>> ip_pool;
        auto byte_by_index{[](std::vector<std::string> v, int index)
                           { return std::stoi(split(v.at(0), '.')[index]); }};

        for (std::string line; std::getline(std::cin, line);)
        {
            std::vector<std::string> v = split(line, '\t');
            std::tuple<int, int, int, int> temp = {byte_by_index(v, 0), byte_by_index(v, 1), byte_by_index(v, 2), byte_by_index(v, 3)};
            ip_pool.push_back(temp);
        }

        // TODO reverse lexicographically sort
        sort(&ip_pool);

        print_pool(ip_pool);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        filter(ip_pool, 1);

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

        filter(ip_pool, 46, 70);

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        filter_any(ip_pool, 46);

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
