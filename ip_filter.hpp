#pragma once

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str, char d);
void print_ip(auto ip);
void print_pool(auto ip_pool);
void sort(auto *ip_pool);
std::vector<std::tuple<int, int, int, int>> filter(auto ip_pool, int key);
std::vector<std::tuple<int, int, int, int>> filter(auto ip_pool, int key1, int key2);
std::vector<std::tuple<int, int, int, int>> filter_any(auto ip_pool, int key);
int cimus();