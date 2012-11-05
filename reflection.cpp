#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>    
#include <algorithm>
#include <iostream>

#include "reflection.hpp"

using std::find;
using std::string;
using std::cout;
using std::endl;
using std::pair;
using std::set;
using std::type_info;
using boost::lexical_cast;
using boost::format;
using boost::algorithm::to_lower;

Reflection::Reflection() :
fieldNamePrefix(""),
fieldNameCaseSensitive(false)
{
}

void Reflection::mapParameter(string name, int& value) {
  if (!fieldNameCaseSensitive) to_lower(name);
  typemap[name] = &typeid(value);
  intmap[name] = &value;
}
void Reflection::mapParameter(string name, long& value) {
  if (!fieldNameCaseSensitive) to_lower(name);
  typemap[name] = &typeid(value);
  longmap[name] = &value;
}
void Reflection::mapParameter(string name, float& value) {
  if (!fieldNameCaseSensitive) to_lower(name);
  typemap[name] = &typeid(value);
  floatmap[name] = &value;
}
void Reflection::mapParameter(string name, double& value) {
  if (!fieldNameCaseSensitive) to_lower(name);
  typemap[name] = &typeid(value);
  doublemap[name] = &value;
}
void Reflection::mapParameter(string name, bool& value) {
  if (!fieldNameCaseSensitive) to_lower(name);
  typemap[name] = &typeid(value);
  boolmap[name] = &value;
}
void Reflection::mapParameter(string name, string& value) {
  if (!fieldNameCaseSensitive) to_lower(name);
  typemap[name] = &typeid(value);
  stringmap[name] = &value;
}

void Reflection::setParameter(string name, string value) {
  name = fieldNamePrefix + name;
  if (!fieldNameCaseSensitive) to_lower(name);

  if (typemap.find(name) != typemap.end()) {
    if (*typemap[name] == typeid(int))
      *intmap[name] = lexical_cast<int>(value);
    else if (*typemap[name] == typeid(long))
      *longmap[name] = lexical_cast<long>(value);
    else if (*typemap[name] == typeid(float))
      *floatmap[name] = lexical_cast<float>(value);
    else if (*typemap[name] == typeid(double))
      *doublemap[name] = lexical_cast<double>(value);
    else if (*typemap[name] == typeid(bool)) {
      to_lower(value);
      if (value.substr(0, 1) == "t")
        *boolmap[name] = true;
      else if (value.substr(0, 1) == "f")
        *boolmap[name] = false;
      else
        *boolmap[name] = lexical_cast<bool>(value);
    }
    else if (*typemap[name] == typeid(string))
      *stringmap[name] = value;
  }
  else
    cout << "unknown property: " << name << endl;
}

string Reflection::
getParameter(string name)
{
  name = fieldNamePrefix + name;
  if (!fieldNameCaseSensitive) to_lower(name);

  if (typemap.find(name) == typemap.end())
    return "";
  else if (*typemap[name] == typeid(int))
    return lexical_cast<string>(*intmap[name]);
  else if (*typemap[name] == typeid(long))
    return lexical_cast<string>(*longmap[name]);
  else if (*typemap[name] == typeid(float))
    return (format("%g") % *floatmap[name]).str();
    // if you need full digit, use following instead
    //return lexical_cast<string>(*floatmap[name]);
  else if (*typemap[name] == typeid(double))
    return (format("%g") % *doublemap[name]).str();
    // if you need full digit, use following instead
    //return lexical_cast<string>(*doublemap[name]);
  else if (*typemap[name] == typeid(bool))
    return *boolmap[name] ? "true" : "false";
  else if (*typemap[name] == typeid(string))
    return *stringmap[name];
  else
    return "";
}

set<string> Reflection::getDeclaredFields() {
  set<string> fields;
  pair<string, const type_info*> p;
  BOOST_FOREACH(p, typemap) {
    fields.insert(p.first);
  }
  return fields;
}

void Reflection::debugFields() {
  pair<string, const type_info*> p;
  BOOST_FOREACH(p, typemap) {
    cout << p.first << " = " << getParameter(p.first) << endl;
  }
}
