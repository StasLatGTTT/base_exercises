#include "drob.cpp"

int main(){ // конструктор "по-умолчанию"
  int l,m,n;
  Drob c;

  cout<<"Enter drob a: ";
  cin>>l>>m>>n;
  Drob a(l,m,n);

  cout<<"Enter drob b: ";
  cin>>l>>m>>n;
  Drob b(l,m,n);

  cout<<"enter number n: ";
  cin>>n;

  cout<<"a=";
  a.print();

  cout<<"b=";
  b.print();

  cout<<"n="<<n<<endl;

/*
================================================================================
*/

  c=a+b;
  cout<<"a+b=";
  c.print();

  c=a+n;
  cout<<"a+n=";
  c.print();

  c=n+a;
  cout<<"n+a=";
  c.print();

/*
================================================================================
*/

  c=a-b;
  cout<<"a-b=";
  c.print();

  c=a-n;
  cout<<"a-n=";
  c.print();

  c=n-a;
  cout<<"n-a=";
  c.print();

/*
================================================================================
*/

  c=a*b;
  cout<<"a*b=";
  c.print();

  c=a*n;
  cout<<"a*n=";
  c.print();

  c=n*a;
  cout<<"n*a=";
  c.print();

  c=a/b;
  cout<<"a/b=";
  c.print();

  c=a/n;
  cout<<"a/n=";
  c.print();

  c=n/a;
  cout<<"n/a=";
  c.print();

/*
================================================================================
*/

  int x;

  x=a>b;
  cout<<"a>b - "<<x<<endl;
  x=a<b;
  cout<<"a<b - "<<x<<endl;
  x=n>a;
  cout<<"n>a - "<<x<<endl;
  x=b<n;
  cout<<"b<n - "<<x<<endl;

  x=a==b;
  cout<<"a==b - "<<x<<endl;
  x=n==b;
  cout<<"n==b - "<<x<<endl;
  x=a==n;
  cout<<"a==n - "<<x<<endl;

  x=a>=b;
  cout<<"a<=b - "<<x<<endl;
  x=a<=b;
  cout<<"a>=b - "<<x<<endl;
  x=n<=b;
  cout<<"n<=b - "<<x<<endl;
  x=a>=n;
  cout<<"a>=n - "<<x<<endl;

 return 0;
}
