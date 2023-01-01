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

void invoke_func_argv_demo(int x,int y)
{
    util ul;
    ul.invoke_func_argv(x,y);
}

void multi_thread_demo(int x,int y,int z,string str)
{
    util ul;
    ul.multi_thread(x,y,z,str);
}

void print_random_demo(int len)
{
    util ul;
    ul.print_random(len);
}

void t_array_demo(uint32_t min,uint32_t max,int len)
{
    util ul;
    ul.t_array_demo(min,max,len);
}

void quick_sort_demo(int len)
{
    util ul;
    ul.quick_sort_asc_uint32(len);
}

int main(int args,char **argv)
{ 
    // t_array_demo(0,UINT32_MAX,atoi(argv[1]));
    quick_sort_demo(atoi(argv[1]));
}












































