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

int main(int args,char **argv)
{ 
    serialize_book_vector_demo(atoi(argv[1])); 
}












































