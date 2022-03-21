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
    cout << "JSON string for name field: " << nameFieldString << endl;
    shared_ptr<Field> reconstructedNameField = converter.parse(nameFieldString);
    bool nameFieldOk = nameField->Equals(reconstructedNameField, true);
    cout << "Name field OK: " << nameFieldOk << "\n" << endl;

    string ageFieldString = converter.serialize(ageField);
    cout << "JSON string for age field: " << ageFieldString << endl;
    shared_ptr<Field> reconstructedAgeField = converter.parse(ageFieldString);
    bool ageFieldOk = ageField->Equals(reconstructedAgeField, true);
    cout << "Age field OK: " << ageFieldOk << "\n" << endl;

    string bodyFatFieldString = converter.serialize(bodyFatField);
    cout << "JSON string for bodyFat field: " << bodyFatFieldString << endl;
    shared_ptr<Field> reconstructedBodyFatField = converter.parse(bodyFatFieldString);
    bool bodyFatFieldOk = bodyFatField->Equals(reconstructedBodyFatField, true);
    cout << "BodyFat field OK: " << bodyFatFieldOk << "\n" << endl;

    string birthDayFieldString = converter.serialize(birthDayField);
    cout << "JSON string for age field: " << birthDayFieldString << endl;
    shared_ptr<Field> reconstructedBirthDayField = converter.parse(birthDayFieldString);
    bool birthDayFieldOk = birthDayField->Equals(reconstructedBirthDayField, true);
    cout << "BirthDay field OK: " << birthDayFieldOk << "\n" << endl;

    string isCrazyFieldString = converter.serialize(isCrazyField);
    cout << "JSON string for isCrazy field: " << isCrazyFieldString << endl;
    shared_ptr<Field> reconstructedIsCrazyField = converter.parse(isCrazyFieldString);
    bool isCrazyFieldOk = isCrazyField->Equals(reconstructedIsCrazyField, true);
    cout << "isCrazy field OK: " << isCrazyFieldOk << "\n" << endl;


    bool ok = nameFieldOk && ageFieldOk && bodyFatFieldOk && birthDayFieldOk && isCrazyFieldOk;
    if(ok){
        cout << "Test passed!" << endl;
        return 0;
    }
    else{
        cout << "Test failed!" << endl;
        return 1;
    }
}
