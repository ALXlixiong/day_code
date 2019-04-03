/*
 * string
 * 
 */ 
#include<iostream>
using namespace std;
#include<string>
//int main()
//{
//  string s1 = "hello world";
//  cout<<s1<<endl;
//  s1.resize(3);
//  cout<<s1<<endl;
//  s1 += '0';
//  cout<<s1<<endl; 
//
//  //find 
//  size_t pos = s1.find('o');
//  cout<<"pos = "<<pos<<endl;
//  pos = s1.find("ld");
//  cout<<"pos = "<<pos<<endl;
//  cout<<string::npos<<endl;
//  pos = -1;
//  cout<<string::npos<<endl;
//  return 0;
//}
#include<algorithm>
#include<cstring>
#include<string>
int main()
{
  char *str1 = "hello world";
  char *str2 ="wrld";
  auto it = search(str1,str1+strlen(str1),str2,str2+strlen(str2));
  if(it != str1+strlen(str1))
    cout<<*it<<endl;
  else 
    cout<<"no find"<<endl;
  return 0;
}
