#include <iostream>
#include <arrow/api.h>
#include <CompositeFieldConverter.hpp>

using namespace std;
using namespace arrow;

int main(){
    CompositeFieldConverter converter;

    shared_ptr<Field> childField1 = field("childField1", int32());
    shared_ptr<Field> listField1 = field("listOfInt32", list(childField1));
    shared_ptr<Field> listField2 = field("listField2", list(listField1));
    shared_ptr<Field> listField3 = field("listField3", list(listField2));

    string JSONString = converter.serialize(listField3);
    cout << JSONString << endl;

    cout << listField3->type()->num_fields() << endl;

}
