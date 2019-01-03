/*!
 * @author: yanguohang
 * @date: 2018/11/16
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<stdlib.h>
#include <sstream>
using namespace std;
//rename
string getImageName(string timeStr)
{
     string frontName = timeStr.substr(0,10);
     string lastName=timeStr.substr(10,6);
     string imageName=frontName+"."+lastName;
     return imageName;
}
int main(int argc, char** argv) {
   ifstream fin(argv[1]);
    string imgDir(argv[2]);
    string line;
    map<int, string> mapCameraImage;//number time
    int noCount= 0;
    while (std::getline(fin, line)) {
    //上海车
        std::string noStr = line.substr(0, line.find(' '));
        std::string timeStr = line.substr(line.find(' ') + 1);
        int noInt=atoi(noStr.c_str())+1;
        string imageName=getImageName(timeStr);
        mapCameraImage.insert(pair<int,string>(noInt,imageName));
        //日本车
        /*
        noCount++;
        std::string timeStr = line;
            string imageName=getImageName(timeStr);
        mapCameraImage.insert(pair<int,string>(noCount,imageName));
        */
   }
    int fail_count=0;
   map<int, string>::iterator iter;
    iter = mapCameraImage.begin();

    while(iter != mapCameraImage.end()) {
      //  cout << iter->first << " : " << iter->second << endl;
        int noInt=iter->first ;
        string newName=iter->second;
        string oldName;
        //string dir="/home/sensetime/code/RenameCameraPictur/image/";
        string dir=imgDir;
        stringstream ss;
        ss<<noInt;
        ss>>oldName;
        oldName=dir+oldName+".png";
        newName=dir+newName+".png";

         if (!rename(oldName.c_str(), newName.c_str()))
	{
		//std::cout << "rename success "<< std::endl;
	}
	else
	{
		std::cout << "rename error "<< std::endl;
		fail_count++;
	}
       // cout<<newName<<"\n";
        iter++;
    }
    cout<<"rename end!"<<endl;
    cout<<"fail number"<<" "<<fail_count<<endl;
    return 0;
}
