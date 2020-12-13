#include <iostream> 
using namespace std;
 

bool Dictionary::replace(KeyType key , Itemtype newItem){
  Itemtype item = Dictionary::get(key);
  if (item == -1) return false;
  Dictionary::remove(key);
  Dictionary::add(key,newItem);
  return true;
}

int countR(Itemtype item){

}

int main(){

}

