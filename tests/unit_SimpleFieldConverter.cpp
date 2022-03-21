#include <SimpleFieldConverter.cpp>
#include <SimpleDataTypeConverter.cpp>
#include <iostream>
#include <arrow/api.h>

using namespace std;
using namespace arrow;

int main(){
    SimpleFieldConverter converter;
    // string testJson = R"({
    //     "name": "linh tran",
    //     "age": "27"
    // })";

    shared_ptr<Field> nameField = field("name", utf8(), 
        key_value_metadata({{"description", "Full name of the person"}})
    );
    shared_ptr<Field> addressField = field("address", utf8());
    shared_ptr<Field> ageField = field("age", int8());
    shared_ptr<Field> bodyFatField = field("bodyFat", float64());
    shared_ptr<Field> birthDayField = field("birthDay", date64());
    shared_ptr<Field> isCrazyField = field("isCrazy", boolean());

    string nameFieldString = converter.serialize(nameField);
    string ageFieldString = converter.serialize(ageField);
    string bodyFatFieldString = converter.serialize(bodyFatField);

    cout << "JSON string for name field: " << nameFieldString << endl;

    bool ok;
    if(ok){
        cout << "Test passed!" << endl;
        return 0;
    }
    else{
        cout << "Test failed!" << endl;
        return 1;
    }
}
