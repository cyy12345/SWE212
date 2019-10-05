#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;
set<string> stop_words;

void readStopWords( string filename ){
    fstream fs;
    fs.open(filename,ios::in);
    if( !fs.is_open() ) {
        cout << "Error opening file1";
        exit(1);
    }
    string str;
    getline(fs,str);
    stringstream ss(str);
    string stop_word;
    while( getline(ss,stop_word,',') ){
        stop_words.insert(stop_word);
    }
    stop_words.insert("s");
}

void count(string s){
    stringstream ss(s);
    string str;
    while( ss>>str ){
        if( stop_words.find(str) != stop_words.end() ){
            continue;
        }
        if( map.find(str) != map.end() ) {
            map[str]++;
        }else{
            map[str]=1;
        }
    }
}

void readFile( string filename ){
    fstream fs;
    fs.open(filename,ios::in);
    if( !fs.is_open() ) {
        cout << "Error opening file";
        exit(1);
    }
    string line;
    while( getline(fs,line) ){
        for( int i=0; i<line.size();++i){
            if(ispunct(line[i])){
                line[i] = ' ';
            }else{
                line[i] = tolower(line[i]);
            }
        }
        count(line);

    }

    fs.close();
}
void sortAndOutput(){
    vector<pair<string,int>> v;
    for( auto it = map.begin(); it != map.end(); ++it ){
        v.emplace_back(*it);
    }
    sort(v.begin(),v.end(),[](pair<string,int> a, pair<string,int> b){ return a.second > b.second;});
    for( int i=0; i< 25; ++i){
        cout<< v[i].first << "  -  " << v[i].second << endl;
    }
}
int main(int argc, char** argv) {
    if( argc < 2 ){
        cout<<"please input file name"<<endl;
        exit(1);
    }
    string DIR = "../";
    readStopWords(DIR+"stop_words.txt");

    readFile(DIR+argv[1]);
    sortAndOutput();

    return 0;
}