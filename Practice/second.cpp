#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class car{
private:
  int speed;
  static int count;

public:
  car():speed(0){
    count++;
  }
  void setSpeed(int s){
    speed=s;
  }

  int getSpeed() const{
    return speed;
  }

};
int car::count=0;


class Student{
private:
  std::string name;
  int grade;


public:
  Student(){
    name ="Student";
    grade=0;
  }

  Student(const std::string& n, int g){
    name=n;
    grade=g;
  }

  auto printInfo() const{
    std::cout<< name<<" "<<grade<<std::endl;
  }
};



void elimDups(std::vector<std::string>& words){
  std::sort(words.begin(), words.end());
  auto unique = std::unique(words.begin(), words.end());
  words.erase(unique, words.end()); 
}

void biggies(std::vector<std::string>& words, size_t sz){

  elimDups(words);

  std::stable_sort(words.begin(), words.end(),
    [](const std::string& a, std::string& b){return a.size()< b.size();});
  
  auto wc = std::find_if(words.begin(), words.end(), 
    [sz](const std::string& s){return s.size() >= sz;}
  );
  
  auto count = words.end() - wc;

  std::for_each(wc, words.end(),
    [](const std::string& s){std::cout<<s<<"";});
  
}

std::vector<int> nums = {4,8,15,16,23,42};

int count = std::count_if (nums.begin(), nums.end(),
  [](int& a) {return a%2 ==0;});















int main(){

  car niggacar;
  niggacar.setSpeed(70);
  std::cout<<niggacar.getSpeed()<<std::endl;

  Student nigga("Hebane", 95);
  nigga.printInfo();

}