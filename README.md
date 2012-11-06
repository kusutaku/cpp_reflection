Reflection for GNU C++
======================


What's This?
------------

This is super lightweight Reflection functionarity for GNU C++.  
You don't have to install any libraries, to generate dictionaries, to use templates, and so on.  
All you have to do is to inherit the Reflection class.  
This enables C++ user Model class to accept name based field accessors like ordinary reflection.  
  
    // reflection accessor  
    std::string getParameter(std::string name);  
    void setParameter(std::string name, std::string value);  
    std::set<std::string> getDeclaredFields();  
  
  
Necessary Packages
------------------
  
*  gcc  
*  boost  
  
  
How To Use
----------
  
All you have to do to use it is only 2 things as follows.  
   
1) include reflection.hpp and inherit Reflection class from your Model class (refer to testmodel.hpp)  
    
    // example
    #include "reflection.hpp"  
    class TestModel : public Reflection {  
      ...  
    };  
   
2) override mapParameter method, write mapping of all properties in it,  
   and call it from constructor (refer to testmodel.cpp)  
  
    // example
    void TestModel::mapParameters() {  
      mapParameter(TO_STRING(_foo), _foo);  
      mapParameter(TO_STRING(_bar), _bar);  
    }  
    
    TestModel::TestModel()  
    {  
      mapParameters();  
    }  
  
  
Example Code
------------
  
You can try an example by following command after necessary packages.  
  
    make  
    ./reflectiontest  
  
  
Download
--------

You can download latest version from https://github.com/kusutaku/cpp_reflection
  
  

License
-------
* Copyright 2012, Takuya Kusumoto ([@github](https://github.com/kusutaku/cpp_reflection "cpp_reflection")).
