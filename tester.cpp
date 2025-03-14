#include <iostream>
#include <string_view>
#include <string.h>
#include <forward_list>
#include <string>
#include <chrono>
#include <unordered_map>
#include <fstream>
#include <bit>
#include <codecvt>
#include <unicode/utypes.h>
#include <unicode/ustring.h>
#include <vector>
#include <list>
#include <mach/mach.h>
#include <memory>
#include <any>
#include <variant>


union node{
    struct vals{
        int prev;
        int current;
    }vals;
    node* ptr;
};


size_t getMemoryUsage() {
    task_basic_info_data_t taskInfo;
    mach_msg_type_number_t infoCount = TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&taskInfo, &infoCount) == KERN_SUCCESS) {
        return taskInfo.resident_size; // RAM usage in bytes
    }
    return 0;
}


void task(){
    //Custom data structure of my own design
    int size = 1000000;
    int iterations = 3;
    int divisors[] = {15, 3, 2};
    std::cout << "hello" << std::endl;
    std::vector<node> node_vec;
    node_vec.push_back({.vals = {-1, 0}});
    for(int i = 1; i < size; i++){
        node_vec.push_back({.vals = {i - 1, i}});
    }
    int prev;
    for(int i = 0; i < iterations; i++){
        prev = node_vec.begin()->vals.prev;
        for(auto it = node_vec.begin(); it != node_vec.end();){
            if(it->vals.prev + it->vals.current < 2000000){
                if((it->vals.prev + it->vals.current) % divisors[i] == 0){
                    auto current = it;
                    auto next = ++it;
                    if(next->vals.prev + next->vals.current < 2000){
                        current->ptr = &(*next);
                    }
                    else{
                        (--it)->ptr = (++it)->ptr;
                    }
                }
                else{
                    it->vals.prev = prev;
                    prev = it->vals.current;
                    ++it;
                }
            }
            else{
                it = node_vec.begin() + (it->ptr - &node_vec[0]);
            }
        }
    }
}


void task2(){
    //vector
    int size = 1000000;
    int iterations = 3;
    int divisors[] = {15, 3, 2};
    std::cout << "hello" << std::endl;
    std::vector<int> vec;
    for(int i = 0; i < size; i++){
        vec.push_back(i);
    }
    for(int i = 0; i < iterations; i++){
        for(auto it = ++vec.begin(); it != vec.end();){
            auto prev = --it;
            auto current = ++it;
            if((*prev + *current) % divisors[i] == 0){
                vec.erase(it);
            }
            else{
                ++it;
            }
            
        }
    }
}


void task3(){
    //list
    int size = 1000000;
    int iterations = 3;
    int divisors[] = {15, 3, 2};
    std::cout << "hello" << std::endl;
    std::list<int> list;
    for(int i = 0; i < size; i++){
        list.push_back(i);
    }
    for(int i = 0; i < iterations; i++){
        for(auto it = ++list.begin(); it != list.end();){
            auto prev = --it;
            auto current = ++it;
            if((*prev + *current) % divisors[i] == 0){
                ++it;
                list.erase(current);
            }
            else{
                ++it;
            }
            
        }
    }
}


int main(int argc, const char * argv[]) {
    size_t RamUsage1 = getMemoryUsage();
    auto start = std::chrono::high_resolution_clock::now();
    task();
    //task2();
    //task3();
    auto end = std::chrono::high_resolution_clock::now();
    size_t RamUsage2 = getMemoryUsage();
    std::cout << "time: " << std::chrono::duration<double>(end - start).count() << " s" << std::endl;
    std::cout << "RAM usage: " << RamUsage2 - RamUsage1 << std::endl;
}
