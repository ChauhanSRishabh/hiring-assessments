#include <iostream>
#include <string>
#include <sstream>
using namespace std;


// Calculate total minutes between 2 given times in 12 hr format

int StringChallenge(string str) {
  
  // code goes here
  string time1, time2, hr1, hr2, min1, min2;
  int hyphen = str.find('-');
  bool col = false;

  for(int i=0; i<str.length(); i++)
  {
    if(i>=hyphen)
    {
      col = false;
      for(; i<str.length(); i++)
      {
        if(str[i] == ':')
        {
          col = true;
          continue;
        }
        if(str[i] == 'a' || str[i] == 'p')
        {
          time2.push_back(str[i]);
          time2.push_back(str[i+1]);
        }
        if(col && isdigit(str[i]))
        {
          min2.push_back(str[i]);
        }
        else if(isdigit(str[i]))
        {
          hr2.push_back(str[i]);
        }
      }
    }
    else
    {
      if(str[i] == ':')
      {
        col = true;
        continue;
      }
      if(str[i] == 'a' || str[i] == 'p')
      {
        time1.push_back(str[i]);
        time1.push_back(str[i+1]);
      }
      if(col && isdigit(str[i]))
      {
        min1.push_back(str[i]);
      }
      else if(isdigit(str[i]))
      {
        hr1.push_back(str[i]);
      }
    }
  }

  int hr = 0;
  if(stoi(hr1) == stoi(hr2) && time1 == time2 &&  stoi(min1) > stoi(min2))
  {
    hr = 24 - (stoi(hr1) - stoi(hr2));
  }
  else if(stoi(hr1) > stoi(hr2) && time1 == time2 &&  stoi(min1) < stoi(min2))
  {
    hr = 24 - (stoi(hr1) - stoi(hr2));
  }
  else if(time1 == time2 || (hr2 == "12" && hr1 != "12"))
  {
    hr = stoi(hr2) - stoi(hr1);
  }
  else
  {
    hr = (12 - stoi(hr1) + stoi(hr2));
  }
  int time;
  if(min1 != "00")
  {
    time = (hr*60 - stoi(min1)) + stoi(min2);
  }
  else
  {
    time = (hr*60 + stoi(min1)) + stoi(min2);
  }
  return time;

}

int main(void) { 
   
  // keep this function call here
  cout << StringChallenge("1:23am-1:08am");
  return 0;
    
}
