#include "model/util.h"

void util::multi_thread(int x,int y,int z,string str)
{
    thread t1([](int xx,int yy,int zz,string sstr)
    {
        util ul;
        for(int i=0;i<xx;i++)
        {
            cout<<i+1<<","<<ul.get_uuid()<<","<<ul.get_time()<<endl;
            sleep(1);
        }

        for(int i=0;i<yy;i++)
        {
            cout<<i+1<<","<<ul.get_uuid()<<","<<ul.get_time()<<endl;
            sleep(1);
        }

        for(int i=0;i<zz;i++)
        {
            cout<<i+1<<","<<ul.get_uuid()<<endl;
            sleep(1);
        }
        cout<<"The string is "<<endl<<sstr<<endl;
    },x,y,z,str);
    t1.join();
    cout<<get_time()<<",finished in "<<__FUNCTION__<<","<<__LINE__<<endl;
}

void util::invoke_func_argv(int x,int y)
{
    cout<<"The sum of "<<x<<" and "<<y<<" is "<<pass_func_as_argu(x,y,&sum)<<endl;
    cout<<"The prod of "<<x<<" and "<<y<<" is "<<pass_func_as_argu(x,y,&prod)<<endl;
    cout<<get_time()<<",finished in "<<__FUNCTION__<<","<<__LINE__<<endl;
}

int util::sum(int x, int y)
{
    return x + y;
}
int util::prod(int x, int y)
{
    return x * y;
}

int util::pass_func_as_argu(int x, int y, int (*func)(int, int))
{
    return func(x, y);
}

void util::deserialize_json_string_to_vector(const string &filename)
{
    fstream rfile(filename, ios::in);
    if (!rfile.is_open())
    {
        cout << "Open " << filename << " failed!" << endl;
    }

    stringstream ss;
    ss << rfile.rdbuf();
    string jsonvalue = ss.str();
    ss.str(std::string());
    Json::Reader jsonreader;
    Json::Value jsonroot;
    if (!jsonreader.parse(jsonvalue, jsonroot))
    {
        cout << "Parsed from json string value failed!" << endl;
        return;
    }

    vector<book> vec;
    Json::Value::iterator itr = jsonroot.begin();
    while (itr != jsonroot.end())
    {
        book bk;
        bk.idx = (*itr)["idx"].asUInt64();
        bk.id = (*itr)["id"].asUInt64();
        bk.abstract = (*itr)["abstract"].asString();
        bk.author = (*itr)["author"].asString();
        bk.comment = (*itr)["comment"].asString();
        bk.content = (*itr)["content"].asString();
        bk.isbn = (*itr)["isbn"].asString();
        bk.summary = (*itr)["summary"].asString();
        bk.title = (*itr)["title"].asString();
        bk.topic = (*itr)["topic"].asString();
        vec.push_back(bk);
        itr++;
    }
    print_book_vector(std::ref(vec));
    cout << get_time() << ",finished in " << __FUNCTION__ << "," << __LINE__ << endl;
}

void util::log_file_msg(const string &filename, const string &msg)
{
    fstream logfile(filename, ios::app);
    if (!logfile.is_open())
    {
        cout << "Create or open " << filename << " failed!" << endl;
        return;
    }

    logfile << msg;
    if (!logfile.good())
    {
        cout << "Write into " << filename << " failed!" << endl;
        return;
    }
    cout << get_time() << ",write into " << filename << " successfully!" << endl
         << endl;
}

void util::serialize_book_vector(int len)
{
    vector<book> vec;
    fill_book_vector(std::ref(vec), len);
    Json::Value root;
    vector<book>::iterator itr = vec.begin();
    while (itr != vec.end())
    {
        Json::Value subjson;
        subjson["idx"] = itr->idx;
        subjson["id"] = itr->id;
        subjson["abstract"] = itr->abstract;
        subjson["author"] = itr->author;
        subjson["comment"] = itr->comment;
        subjson["content"] = itr->content;
        subjson["isbn"] = itr->isbn;
        subjson["summary"] = itr->summary;
        subjson["title"] = itr->title;
        subjson["topic"] = itr->topic;
        root.append(subjson);
        itr++;
    }
    Json::StyledWriter writer;
    string jsonvalue = writer.write(std::ref(root));
    string logfilename = get_time().append(".txt");
    log_file_msg(logfilename, jsonvalue);
    // cout << jsonvalue << endl;
    cout << get_time() << ",finished in " << __FUNCTION__ << "," << __LINE__ << endl;
}

void util::book_vector(int len)
{
    vector<book> vec;
    fill_book_vector(std::ref(vec), len);
    print_book_vector(std::ref(vec));
    cout << get_time() << ", finished in " << __FUNCTION__ << "," << __LINE__ << endl;
}

void util::print_book_vector(vector<book> &vec)
{
    vector<book>::iterator itr = vec.begin();
    while (itr != vec.end())
    {
        cout << fixed << itr->idx << "," << itr->id << "," << itr->abstract << "," << itr->author << "," << itr->comment << ","
             << itr->content << "," << itr->isbn << "," << itr->summary << "," << itr->title << "," << itr->topic << endl;
        itr++;
    }
}

void util::fill_book_vector(vector<book> &vec, int len)
{
    for (int i = 0; i < len; i++)
    {
        book bk;
        bk.idx = static_cast<uint64_t>(i);
        bk.id = static_cast<uint64_t>(i * i * i * i * i);
        bk.abstract.assign(get_uuid());
        bk.author.assign(get_uuid());
        bk.comment.assign(get_uuid());
        bk.content.assign(get_uuid());
        bk.isbn.assign(get_uuid());
        bk.summary.assign(get_uuid());
        bk.title.assign(get_uuid());
        bk.topic.assign(get_uuid());
        vec.push_back(bk);
    }
}

void util::test_uuid()
{
    chrono::time_point<chrono::high_resolution_clock> starttime, endtime;
    char *uuidvalue = (char *)malloc(40);
    for (int i = 0; i < 1000; i++)
    {
        starttime = chrono::high_resolution_clock::now();
        for (int j = 0; j < 1000000; j++)
        {
            uuid_t newuuid;
            uuid_generate(newuuid);
            uuid_unparse(newuuid, uuidvalue);
        }
        endtime = chrono::high_resolution_clock::now();
        cout << i + 1 << ",time cost :"
             << chrono::duration_cast<chrono::seconds>(endtime - starttime).count() << " seconds,"
             << chrono::duration_cast<chrono::milliseconds>(endtime - starttime).count() << " mills,"
             << chrono::duration_cast<chrono::microseconds>(endtime - starttime).count() << " micros,"
             << chrono::duration_cast<chrono::nanoseconds>(endtime - starttime).count() << " nanos!" << endl;
    }
    cout << get_time() << ",finished in " << __FUNCTION__ << "," << __LINE__ << endl;
}

void util::print_uuid()
{
    uint64_t num = 0;
    while (1)
    {
        cout << ++num << "," << get_uuid() << "," << get_time() << endl;
        usleep(100000);
    }
}

string util::get_uuid()
{
    uuid_t newuuid;
    uuid_generate(newuuid);
    char *uuidvalue = (char *)malloc(40);
    uuid_unparse(newuuid, uuidvalue);
    string uuidStr(uuidvalue);
    free(uuidvalue);
    uuidvalue = nullptr;
    return uuidStr;
}

void util::time_demo()
{
    static uint64_t num=0;
    chrono::time_point<chrono::high_resolution_clock> now = chrono::high_resolution_clock::now();
    // cout << "nanos " << chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()).count()
    //      << ",micros " << chrono::duration_cast<chrono::microseconds>(now.time_since_epoch()).count()
    //      << ",mills " << chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count()
    //      << ",seconds " << chrono::duration_cast<chrono::seconds>(now.time_since_epoch()).count() << endl;
    chrono::milliseconds mills = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch());
    chrono::seconds seconds = chrono::duration_cast<chrono::seconds>(now.time_since_epoch());
    uint64_t millsValue = mills.count() - seconds.count() * 1000;
    time_t rawTime = chrono::high_resolution_clock::to_time_t(now);
    struct tm tmInfo = *std::localtime(&rawTime);
    stringstream ss;
    ss << std::put_time(&tmInfo, "%Y%m%d%H%M%S") << std::setfill('0') << std::setw(3) << millsValue;
    string dtvalue = ss.str();
    ss = stringstream(std::string());
    cout<<++num<<","<< dtvalue << endl;
}

string util::get_time()
{
    chrono::time_point<chrono::high_resolution_clock> now = chrono::high_resolution_clock::now();
    chrono::milliseconds mills = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch());
    chrono::seconds seconds = chrono::duration_cast<chrono::seconds>(now.time_since_epoch());
    uint64_t millsValue = mills.count() - seconds.count() * 1000;
    time_t rawTime = chrono::high_resolution_clock::to_time_t(now);
    struct tm tmInfo = *std::localtime(&rawTime);
    stringstream ss;
    ss << std::put_time(&tmInfo, "%Y%m%d%H%M%S") << std::setfill('0') << std::setw(3) << millsValue;
    string dtvalue = ss.str();
    ss = stringstream(std::string());
    return dtvalue;
}

void util::print_time()
{
    while (1)
    {
        time_demo();
        usleep(100000);
    }
}