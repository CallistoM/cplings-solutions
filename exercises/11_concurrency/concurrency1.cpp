#include <catch2/catch.hpp>
#include <iostream>
#include <thread>

class thread_guard {
public:
    std::thread &thread;
public:
    explicit thread_guard(std::thread &thread)
            : thread(thread) {}
    ~thread_guard() {
        if(thread.joinable()) {
            thread.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

struct func
{
    int& i;
    func(int& i_):i(i_){}

    void do_something(int &i) {

    }

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

class background_task {
public:
    void do_something() const {
        std::cout << "do something" << std::endl;
    }

    void do_something_else() const {
        std::cout << "do something else" << std::endl;
    }

    void operator()() const {
        do_something();
        do_something_else();
    }
};

void hello() {
    std::cout << "hello" << std::endl;
}

TEST_CASE("test_concurrency1_0") {
    std::thread t(hello);
    t.join();
    std::thread my_thread((background_task()));
    my_thread.join();
}
