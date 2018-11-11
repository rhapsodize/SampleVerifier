#include <iostream>
#include <fstream>
#include "json.hpp"
#include <string>
//using std::vector;
using namespace std;


int main(int argc, char** argv) {

std::ifstream file1,file2;
file1.open(argv[1]);
nlohmann::json jsonObject1;
if(file1.is_open()){
file1 >> jsonObject1;
}
//cout<<jsonObject1<<endl;
file2.open(argv[2]);
nlohmann::json jsonObject2;
if(file2.is_open()){
file2 >> jsonObject2;
}

std::vector<string> storeStr;

nlohmann::json result;
int global_counter = 0;
int countstr = 0;
for (auto itr = jsonObject1.begin(), itr2 = jsonObject2.begin();itr2!= jsonObject2.end(); ++itr,++itr2){
countstr ++;
storeStr.push_back(itr.key());


if(itr.key()=="metadata"){
nlohmann::json meta;
nlohmann::json tmp;
tmp["arraySize"]=itr.value()["arraySize"];
tmp["file"]=argv[1];
tmp["numSamples"]=itr.value()["numSamples"];

result["sample1"]["metadata"]=tmp;
//continue;
//}
//for (auto itr2 = jsonObject2.begin();itr2!= jsonObject2.end(); ++itr2){

if(itr2.key()=="metadata"){
nlohmann::json meta;
nlohmann::json tmp;
tmp["arraySize"]=itr2.value()["arraySize"];
tmp["file"]=argv[2];
tmp["numSamples"]=itr2.value()["numSamples"];

result["sample2"]["metadata"]=tmp;
continue;
}
}
int miscount=0;
for(int i = 0; i<itr.value().size();i++){
if(itr.value()[i]!=itr2.value()[i]){
//miscount++;
nlohmann::json element;
element.push_back(itr.value()[i]);
element.push_back(itr2.value()[i]);
result[storeStr.at(countstr-1)]["Mismatches"][to_string(miscount)]=element;
miscount++;
}
}
if(miscount!=0){
global_counter++;
result[storeStr.at(countstr-1)]["sample1"] = itr.value();
result[storeStr.at(countstr-1)]["sample2"] = itr2.value();
}
result["metadata"]["samplesWithConflictingResults"]=countstr;
//cout<<miscount<<endl;
}
//}



//std::ofstream o("AlmostSampleExample.json");
//o << std::setw(4)<< result << std::endl;

cout<<result<<endl;

return 0;
}




































/*
std::ifstream file;
file.open(filename);
nlohmann::json jsonObject;
if(file.is_open()){
file >> jsonObject;
}
std::out<<jsonObject;
nlohmann::json outputObj;



for(auto itr=jsonObject.begin();iter!=jsonObject.end();++iter){


}


for (auto arrayItr = jsonObject["iter.key()"].begin();
     arrayItr!=jsonObject["iter.key()"].end);
     ++arrayIter){
for (auto arrayItr = jsonObject["iter.key()"].begin();
     arrayItr!=jsonObject["iter.key()"].end);
     ++arrayIter){



}
}


OutputObj["iter.key()"]["Mismatches"]["1"][];
OutputObj["iter.key()"]["Mismatches"]["2"][];

*/

