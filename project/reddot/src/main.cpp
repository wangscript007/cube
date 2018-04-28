/******************************************************************************
Copyright (c) 2016. All Rights Reserved.

FileName: main.cpp
Version: 1.0
Date: 2016.1.13

History:
eric     2018.4.27   1.0     Create
******************************************************************************/
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <functional>
#include "project.h"
#include "dispatch_server.h"
#include "protocol.h"

using namespace std;

class Test
{
    ECO_VALUE_API(Test)
public:
    Test& set(IN const char* str);
    const char* get_str() const;
};

class Test::Impl
{
    ECO_IMPL_INIT(Test)
public:
    std::string data_;
public:
    void set_data(IN const char* str)
    {
        data_ = str;
    }
};

ECO_VALUE_IMPL(Test);
Test& Test::set(IN const char* str)
{
    m_impl->set_data(str);
    return *this;
}

const char* Test::get_str() const 
{
    cout << __FUNCTION__ << endl;
    return m_impl->data_.c_str();
}

void fun_default(IN eco::MessageMeta& msg)
{
    std::cout << __FUNCTION__  
        <<" session_id:" << msg.get_session_id()
        << " message_type:" << msg.get_type()
        << " data:" << msg.get_request_data()
        << std::endl;
}

void fun_eco(IN eco::MessageMeta& msg)
{
    std::cout << __FUNCTION__ 
        << " session_id:" << msg.get_session_id()
        << " message_type:" << msg.get_type()
        << " data:" << msg.get_request_data()
        << std::endl;
}

class MyClass
{
    ECO_SINGLETON_UNINIT(MyClass)
public:
    MyClass();
    ~MyClass();

    void test()
    {
        EcoCout << "hello world";
    }
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
ECO_SINGLETON_GET(MyClass)


int main(int argc, char **argv)
{
    cout << "hello reddot" << endl;
    
    GetMyClass().test();

    eco::DispatchServer<uint32_t, eco::MessageMeta> dispatch;
    dispatch.set_default(fun_default);
    dispatch.set_dispatch(10001, fun_eco);
    dispatch.run(1);

    for (int i = 0; i < 10; ++i)
    {
        eco::MessageMeta msg(i, 10001+i, "hello world");
        dispatch.post(msg);
    }


    getchar();
    return 0;
}
