#pragma once
#ifndef __util_h__
#define __util_h__
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string.h>
#include <thread>
#include <unistd.h>
#include <uuid/uuid.h>
#include <vector>
#include <jsoncpp/json/json.h>
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
};
#endif