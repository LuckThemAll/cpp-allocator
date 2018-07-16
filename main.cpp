#define PICOBENCH_IMPLEMENT_WITH_MAIN
#include "picobench/picobench.hpp"
#include <vector>
#include "allocator.cpp"

static void push_back(picobench::state &s)
{
    std::vector<int> v;
    for (auto _ : s)
    {
        v.push_back(rand());
    }
}
PICOBENCH(push_back);

static void push_back_fixed(picobench::state &s)
{
    std::vector<int,art::allocator<int> > v;
    for (auto _ : s)
    {
        v.push_back(rand());
    }
}
PICOBENCH(push_back_fixed);

static void reserve_big(picobench::state &s)
{
    std::vector<int> v;
    for (auto _ : s)
    {
        v.reserve(10000000);
    }
}
PICOBENCH(reserve_big);

static void reserve_fixed(picobench::state &s)
{
    std::vector<int,art::allocator<int> > v;
    for (auto _ : s)
    {
        v.reserve(10000000);
    }
}
PICOBENCH(reserve_fixed);

static void clear(picobench::state &s)
{
    std::vector<int> v;
    for (auto _ : s)
    {
        v.insert(v.begin(),10000,1);
        v.clear();
    }
}
PICOBENCH(clear);

static void clear_fixed(picobench::state &s)
{
    std::vector<int,art::allocator<int> > v;
    for (auto _ : s)
    {
        v.insert(v.begin(),10000,1);
        v.clear();
    }
}
PICOBENCH(clear_fixed);

static void erase(picobench::state &s)
{
    std::vector<int> v;
    for (auto _ : s)
    {
        v.insert(v.begin(),100,1);
        for (auto it = v.begin(); it < v.end(); ++it){
            v.erase(it);
        }
    }
}

PICOBENCH(erase);

static void erase_fixed(picobench::state &s)
{
    std::vector<int,art::allocator<int> > v;
    for (auto _ : s)
    {
        v.insert(v.begin(),100,1);
        for (auto it = v.begin(); it < v.end(); ++it){
            v.erase(it);
        }
    }
}
PICOBENCH(erase_fixed);