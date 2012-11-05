#include <iostream>
#include <string>
#include <set>

#include "testmodel.hpp"

using std::cout;
using std::endl;
using std::set;
using std::string;

int main() {
  TestModel t;

  cout << "--- default values ---" << endl;
  t.debugFields();
  cout << endl;

  // field access with ordinary accessor
  cout << "--- field access with ordinary accessor ---" << endl;
  t.setTestInt(12);
  t.setTestLong(238794398789432);
  t.setTestFloat(0.58);
  t.setTestDouble(101.33091);
  t.setTestBool(false);
  t.setTestString("ABC");
  cout << "_testInt = " << t.getTestInt() << endl;
  cout << "_testLong = " << t.getTestLong() << endl;
  cout << "_testFloat = " << t.getTestFloat() << endl;
  cout << "_testDoule = " << t.getTestDouble() << endl;
  cout << "_testBool = " << t.getTestBool() << endl;
  cout << "_testString = " << t.getTestString() << endl;
  cout << endl;

  // field access with reflection
  cout << "--- field access with reflection ---" << endl;
  t.setParameter("_testInt", "20");
  t.setParameter("_testLong", "184583792502390");
  t.setParameter("_testFloat", "5.73");
  t.setParameter("_testDouble", "-0.717495");
  t.setParameter("_testBool", "true");
  t.setParameter("_testString", "DEF");
  cout << "_testInt = " << t.getParameter("_testInt") << endl;
  cout << "_testLong = " << t.getParameter("_testLong") << endl;
  cout << "_testFloat = " << t.getParameter("_testFloat") << endl;
  cout << "_testDoule = " << t.getParameter("_testDouble") << endl;
  cout << "_testBool = " << t.getParameter("_testBool") << endl;
  cout << "_testString = " << t.getParameter("_testString") << endl;
  cout << endl;

  // get all field names with reflection
  cout << "--- get all field names with reflection ---" << endl;
  set<string> declaredFields = t.getDeclaredFields();
  for (set<string>::iterator it = declaredFields.begin();
       it != declaredFields.end();
       ++it)
    cout << *it << endl;
  cout << endl;

  cout << "--- debug all fields with reflection ---" << endl;
  t.debugFields();
  cout << endl;
}
