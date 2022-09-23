#include <iostream>
double betsy(int);
double pam(int);

void estimate(int lines, double (*pf)(int) );

int main()
{
  using namespace std;
  int code;
  cout << "How many lines of codes do you need?";
  cin >> code;
  cout << "Here's Besty's estimate :\n";
  estimate(code, betsy);
  cout << "Here's Pam's estimate:\n ";
  estimate(code, pam);
  return 0;
}

double betsy(int lns)
{
  
}
  
