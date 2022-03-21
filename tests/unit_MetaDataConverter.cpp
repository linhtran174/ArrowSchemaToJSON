#include <MetadataConverter.cpp>
#include <iostream>
#include <arrow/api.h>

using namespace std;
using namespace arrow;

int main(){
    MetadataConverter converter;
    // string testJson = R"({
    //     "name": "linh tran",
    //     "age": "27"
    // })";

    shared_ptr<KeyValueMetadata> testKvMeta(new KeyValueMetadata());
    testKvMeta->Append("Name", "Linh");
    testKvMeta->Append("key1", "value1");
    testKvMeta->Append("key2", "value2");
    cout << "Arrow KeyValueMetadata ToString: " << testKvMeta->ToString() << "\n" << endl;


    string JSONstring = converter.serialize(testKvMeta);
    cout << "Serialized JSON string: " << JSONstring << endl;

    shared_ptr<KeyValueMetadata> convertedKvMeta = converter.parse(JSONstring);

    bool ok = testKvMeta->Equals(*convertedKvMeta);
    // shared_ptr<KeyValueMetadata> kvMeta = md.parse(testJson);

    if(ok){
        cout << "Test passed!" << endl;
        return 0;
    }
    else{
        cout << "Test failed!" << endl;
        return 1;
    }
}