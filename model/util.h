#pragma once
#ifndef __util_h__
#define __util_h__
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream> 
#include <mysql/mysql.h>
#include <random>
#include <sstream>
#include <string.h>
#include <thread>
#include <unistd.h>
#include <uuid/uuid.h>
#include <vector>
#include <jsoncpp/json/json.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>  
#include <cppconn/resultset_metadata.h>

#include "model/book.h"

using namespace std;

class util
{
public:
    void time_demo();
    string get_time();
    string get_uuid();
    void print_time();
    void print_uuid();
    void test_uuid();
    void fill_book_vector(vector<book> &vec, int len);
    void print_book_vector(vector<book> &vec);
    void book_vector(int len);
    void serialize_book_vector(int len);
    void log_file_msg(const string &filename,const string &msg);
    void deserialize_json_string_to_vector(const string &filename);
    static int sum(int x,int y);
    static int prod(int x,int y);
    int pass_func_as_argu(int x,int y,int(*func)(int,int));
    void invoke_func_argv(int x,int y);
    void multi_thread(int x,int y,int z,string str);
    
    template<typename T>
    T get_random(T min,T max);

    // template<typename T>
    void print_random(int len);

    template<typename T>
    void fill_t_array(T *arr,T min,T max,int len);

    template<typename T>
    void print_t_array(T *arr,int len);

    template<typename T>
    void t_array_gen_print(T min,T max,int len);

    void t_array_demo(uint32_t min,uint32_t max,int len);

    template<typename T>
    void swap(T *left,T *right);

    template<typename T>
    int partition_t_array_asc(T *arr,int low,int high);

    template<typename T>
    void quick_sort_asc(T *arr,int low,int high);

    void quick_sort_asc_uint32(int len);

    template<typename T>
    void bubble_sort_asc(T *arr,int len);

    void bubble_sort_asc_uint64(int len); 
    
    void mysql_retrieve_data(); 
};
#endif