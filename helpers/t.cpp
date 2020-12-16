#include <iostream>
#include <string>
#include <vector>

using namespace std;
void writeBackward(string s){ 
  if(s.empty()) return;
  else{ 
    cout << s.back() << endl; 
    writeBackward(s.substr(0,s.size()-1));
  }
}


void printB(int d, string soFar){
  if(d == 0) cout << soFar << endl;
  else{ 
    printB(d-1,soFar+"0");
    printB(d-1,soFar+"1");
  }
}

void printAllBinary(int numDigits){ 
  printB(numDigits,"");
}

vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
}

void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
}

void moveDisks(int n,string source,string destination, string spare){ 
  if(n == 1) cout << "move disk from " << source << " to " << destination << endl;
  else{
    moveDisks(n-1 , source , spare , destination);
    moveDisks(1 , source , destination ,spare );
    moveDisks(n-1 , spare , destination , source);
  }
}

int main(){
}

