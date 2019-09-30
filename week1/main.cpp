#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

unordered_map<string, int> map;
set<string> stop_words;

void readStopWords( string filename ){
    fstream fs;
    fs.open(filename,ios::in);
    if( !fs.is_open() ) {
        cout << "Error opening file";
        exit(1);
    }
    char buffer[256];
    fs.getline(buffer,256,'\n');
    stringstream ss(buffer);
    string stop_word;
    while( getline(ss,stop_word,',') ){
        stop_words.insert(stop_word);
    }
}

vector<string> split(string s){

}

void readFile( string& filename ){
    fstream fs;
    fs.open(filename,ios::in);
    if( !fs.is_open() ) {
        cout << "Error opening file";
        exit(1);
    }
    char buffer[256];
    while( !fs.eof() ){
        fs.getline(buffer,256,'\n');
        vector<string> lists = split(buffer);
    }

    fs.close();
}
int main(int argc, char** argv) {
    if( argc < 2 ){
        cout<<"please input file name"<<endl;
        exit(1);
    }
    string DIR = "../";

    readStopWords(DIR.append("stop_words.txt"));
    readFile(DIR.append(argv[1]));

    return 0;
}