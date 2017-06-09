#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>

#define all(c) c.begin(), c.end()

using namespace std;

template<typename T> void reverse(T begin, T end) { 
      // We should at first decrement 'end' 
      // But only for non-empty range 
      if(begin != end) 
      { 
           end--; 
           if(begin != end) { 
                while(true) { 
                     swap(*begin, *end); 
                     begin++; 
                     if(begin == end) { 
                          break; 
                     } 
                     end--; 
                     if(begin == end) { 
                          break; 
                     } 
                } 
           } 
      } 
 } 

void printVector(const vector<int>& v) {
	for(int i = 0; i < v.size(); i++)
	 		cout << v[i] << " ";
}


void printMatrix(vector<vector<int>>& v) {
	v[2][1] = -2;

	for(int i = 0; i < v.size(); i++){
	 	for(int j = 0; j < v[0].size(); j++)
	 		cout << v[i][j] << " ";
	 	cout << endl;
	}
}

int main()
{
	map<string, int> teste;

	teste["Bumbum"] = 10;

	cout << teste["Bumbum"] << endl;

	return 0;
}