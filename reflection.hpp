#pragma once

#define TO_STRING(s) # s

#include <set>
#include <map>
#include <typeinfo>
#include <string>

class Reflection
{
protected:
  std::map<std::string, const std::type_info*> typemap;
  std::map<std::string, int*> intmap;
  std::map<std::string, long*> longmap;
  std::map<std::string, float*> floatmap;
  std::map<std::string, double*> doublemap;
  std::map<std::string, bool*> boolmap;
  std::map<std::string, std::string*> stringmap;

  std::string fieldNamePrefix;
  bool fieldNameCaseSensitive;

public:
  Reflection();

  // preparation methods for reflection
  void mapParametersAll();
  void mapParameter(std::string name, int& value);
  void mapParameter(std::string name, long& value);
  void mapParameter(std::string name, float& value);
  void mapParameter(std::string name, double& value);
  void mapParameter(std::string name, bool& value);
  void mapParameter(std::string name, std::string& value);

  // reflection accessor
  std::string getParameter(std::string name);
  void setParameter(std::string name, std::string value);
  std::set<std::string> getDeclaredFields();

  void debugFields();
};
