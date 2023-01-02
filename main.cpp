#include "model/util.h"

void print_time_demo()
{
    util ul;
    ul.print_time();
}

void print_uuid_demo()
{
    util ul;
    ul.print_uuid();
}

void test_uuid_demo()
{
    util ul;
    ul.test_uuid();
}

void book_vector_demo(int len)
{
    util ul;
    ul.book_vector(len);
}

void serialize_book_vector_demo(int len)
{
    util ul;
    ul.serialize_book_vector(len);
}

void deserialize_json_string_to_vector_demo(const string &filename)
{
    util ul;
    ul.deserialize_json_string_to_vector(std::ref(filename));
}

void invoke_func_argv_demo(int x, int y)
{
    util ul;
    ul.invoke_func_argv(x, y);
}

void multi_thread_demo(int x, int y, int z, string str)
{
    util ul;
    ul.multi_thread(x, y, z, str);
}

void print_random_demo(int len)
{
    util ul;
    ul.print_random(len);
}

void t_array_demo(uint32_t min, uint32_t max, int len)
{
    util ul;
    ul.t_array_demo(min, max, len);
}

void quick_sort_demo(int len)
{
    util ul;
    ul.quick_sort_asc_uint32(len);
}

void bubble_sort_asc_demo(int len)
{
    util ul;
    ul.bubble_sort_asc_uint64(len); 
}

int sum(int x,int y)
{
    return x+y;
}

int prod(int x,int y)
{
    return x*y;
}

int pass_func(int x,int y,int(*func)(int,int))
{
    return func(x,y);
}

void pass_func_demo(int x,int y)
{
    cout<<"The sum of "<<x<<" and "<<y<<" is "<<pass_func(x,y,&sum)<<endl;
    cout<<"The prod of "<<x<<" and "<<y<<" is "<<pass_func(x,y,&prod)<<endl;
}

//g++ -g -std=c++2a -I. *.cpp ./model/*.cpp -o h1 -luuid -lpthread -lmysqlcppconn -ljsoncpp
int main(int args,char **argv)
{  
    serialize_book_vector_demo(100000);
}

