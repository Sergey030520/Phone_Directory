#include <iostream>
#include <string>
#include <map>
#include <vector>

 void addPhoneDirectory( std::map<std::string, std::string>& copy_phoneDir ,
                         const std::string& phone, const std::string name){
    copy_phoneDir.insert(std::make_pair(phone, name));
}
void showPhone_in_directory(std::map<std::string, std::string>& copy_phoneDir, std::string& phone){
    auto request = copy_phoneDir.find(phone);
    std::cout << request->first << " " << request->second << std::endl;
}
void showName_in_directory(std::map<std::string, std::string>& copy_phoneDir, std::string& name){
    for(auto it = copy_phoneDir.begin();it != copy_phoneDir.end(); ++it){
        if (it->second == name) std::cout << it->first << " ";
    }
};
void initialMapData(std::map<std::string, std::string>& phone_directory){
    phone_directory.insert(std::make_pair<std::string, std::string> ("50-20-30", "Alexey"));
    phone_directory.insert(std::make_pair<std::string, std::string> ("40-30-20", "Alena"));
    phone_directory.insert(std::make_pair<std::string, std::string> ("60-25-30", "Viktoria"));
    phone_directory.insert(std::make_pair<std::string, std::string> ("55-40-35", "Pasha"));
    phone_directory.insert(std::make_pair<std::string, std::string> ("56-41-35", "Pasha"));
}

int main() {
    std::map<std::string, std::string> phone_directory;
    initialMapData(phone_directory);
    std::string userRequest;
    std::vector<std::string> date_req;
    std::cout << "Input the operation you want to perform: ";
    std::getline(std::cin, userRequest);
    date_req.push_back(userRequest.substr(0,8));
    if (userRequest.length() > 8) date_req.push_back(userRequest.substr(8,userRequest.length()- 8));
    if (date_req.size() > 1) addPhoneDirectory(phone_directory, date_req[0], date_req[1]);
    else if(!date_req.empty()){
        if (date_req[0][2] == '-') showPhone_in_directory(phone_directory, date_req[0]);
        else showName_in_directory(phone_directory, date_req[0]);
    };
}
