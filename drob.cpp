#include <iostream>
#include <cstdlib>
#include <cstdint>

#define int int32_t

using namespace std;

class Drob{
 int cel, chisl,znam;
 int znak;

 int nod(int, int);
 void divZero();

public:
  Drob(); // конструктор дроби по-умолчанию
// Инициализирующий конструктор
  Drob(int,int,int);

// Приводит дробь к нормальному виду
  void simplify();

  int full() const;
  int sign() const;
// Устанавливаем значение
  void setVol(int, int,int);
// Печать дроби в формате простой дроби
   void print() const;
// Печать дроби в десятичном виде (n - количество знаков после запятой)
   void print( int n);

   Drob operator+(const Drob&);//done
   Drob operator+(const int);
   Drob* operator++(int);

   Drob operator-(const Drob&);
   Drob operator-(const int);
   Drob* operator--(int);

   Drob* operator!();

   Drob operator*(const Drob&);
   Drob operator*(const int);
   Drob operator/(const Drob&);
   Drob operator/(const int);

   bool operator>(const Drob&);
   bool operator>(const int);
   bool operator<(const Drob&);
   bool operator<(const int);

   bool operator==(const Drob&);
   bool operator==(const int);
   bool operator>=(const Drob&);
   bool operator>=(const int);
   bool operator<=(const Drob&);
   bool operator<=(const int);
};
// Конструктор "по-умолчанию"
Drob::Drob(){
  cel = chisl = 0;
  znam = 1;
};
// Инициализирующий конструктор (с параметрами )
// По количеству и типам параметров С++ различает какую из
// какую из имеющихся функций нужно применять
Drob::Drob(int c, int ch, int z){
     cel = c;
     chisl = ch;
     znam = z;
     simplify();
};

/*
================================================================================
*/


int Drob::nod(int a, int b){
     while (a && b)
         if (a >= b)
            a %= b;
         else
            b %= a;
     return a | b;
}

void Drob::divZero(){
  cout<<"division by zero occured"<<endl;
  exit(-1);
}

int Drob::full() const {
  if(cel==0){
    return chisl;
  } else {
    return cel*znam+cel/abs(cel)*chisl;
  }
}

int Drob::sign() const {
  if(full()>=0) return 1;
  else return -1;
}

void Drob::simplify(){
  if(znam==0){
    divZero();
  }
  if(znam<0){
    znam=-znam;
    chisl=-chisl;
  }

  int mult=full();
  if(mult>0){
    cel=mult/znam;
    chisl=mult%znam;
  } else if(mult==0){
    cel=0;
    chisl=0;
    znam=1;
  } else if(-znam<mult && mult<0){
    cel=0;
    chisl=mult;
  } else {
    cel=-((-mult)/znam);
    chisl=((-mult)%znam);
  }

  if(chisl!=0){
    int n=nod(abs(chisl), znam);
    chisl=chisl/n;
    znam=znam/n;
  }
}

/*
================================================================================
*/


// "Обычный" print()
void Drob::print() const {
  if(znam==1){
    cout<<cel+chisl;
  } else{
    if(cel!=0){
    cout<<cel;
    }
    if(chisl!=0){
      cout<<'('<<chisl<<'/'<<znam<<')';
    }
    if(cel==chisl && chisl==0) cout<<'0';
  }
  cout<<endl;
   //cout<<cel<<'('<<chisl<<'/'<<znam<<')';
};

// print() "с парамером" - n означает сколько знаков
// после запятой нужно напечатать.
void Drob::print( int n){
   int c = cel * znam + chisl;
   int b = znam;
  for(int i = 0; i < n + 1; i++){
   int pr = c / b;
   cout<<pr;
   if (i == 0)
    cout<<'.';
   int next = c % b;
   next *= 10;
   while(next < b){
     next *= 10;
     i++;
     if (next >= b || i>=n) break;
     cout<<'0';
   }
  c = next;
 }
  cout<<endl;
};

/*
================================================================================
*/


Drob Drob::operator+(const Drob& a){
  Drob tmp;
  tmp.cel=0;
  tmp.znam=znam*a.znam;
  tmp.chisl = full()*a.znam + a.full()*znam;
  tmp.simplify();
  return tmp;
};

Drob Drob::operator+(const int a){
  Drob add(a,0,1);
  Drob temp;
  temp=*this+add;
  return temp;
};

Drob operator+(int a, Drob b){
  return b+a;
}

Drob* Drob::operator++(int){
   *this=*this+1;
   return this;
};


/*
================================================================================
*/



Drob Drob::operator-(const Drob& a){
  Drob tmp;
  tmp.cel=0;
  tmp.znam=znam*a.znam;
  tmp.chisl = full()*a.znam - a.full()*znam;
  tmp.simplify();
  return tmp;
};

Drob Drob::operator-(const int a){
  return *this-Drob(a,0,1);
};

Drob* Drob::operator--(int){
   *this=*this-1;
   return this;
};

Drob operator-(int a, Drob b){
  return Drob(a,0,1)-b;
}

/*
================================================================================
*/

Drob* Drob::operator!(){
 int temp=znam;
 znam=full();
 chisl=temp;
 cel=0;
 simplify();
 return this;
}

/*
================================================================================
*/

Drob Drob::operator*(const Drob& a){
  Drob temp;
  temp.znam=znam*a.znam;
  temp.chisl=full()*a.full();
  temp.simplify();
  return temp;
};

Drob Drob::operator*(const int a){
  Drob temp;
  temp.chisl=full()*a;
  temp.simplify();
  return temp;
};

Drob operator*(int a, Drob b){
  return b*a;
}

Drob Drob::operator/(const Drob& a){
  Drob temp;
  temp.znam=znam*a.full();
  temp.chisl=full()*a.znam;
  temp.simplify();
  return temp;
};

Drob Drob::operator/(const int a){
  Drob temp(cel,chisl,znam);
  temp.znam=znam*a;
  temp.simplify();
  return temp;
};

Drob operator/(int a, Drob b){
  return Drob(a,0,1)/b;
}

/*
================================================================================
*/

bool Drob::operator>(const Drob& a){
  return full()*a.znam>a.full()*znam;
};

bool Drob::operator>(const int a){
  return full()>a*znam;
};

bool  operator>(int a, Drob b){
  return b>a;
}

bool Drob::operator<(const Drob& a){
  return full()*a.znam>a.full()*znam;
};

bool Drob::operator<(const int a){
  return full()<a*znam;
};

bool operator<(int a, Drob b){
  return b<a;
}

/*
================================================================================
*/

bool Drob::operator==(const Drob& a){
  return full()*a.znam==a.full()*znam;
};

bool Drob::operator==(const int a){
  return full()==a*znam;
};

bool operator==(int a, Drob b){
  return b==a;
}

bool Drob::operator>=(const Drob& a){
  return full()*a.znam>=a.full()*znam;
};

bool Drob::operator>=(const int a){
  return full()>=a*znam;
};

bool operator>=(int a, Drob b){
  return b>=a;
}

bool Drob::operator<=(const Drob& a){
  return full()*a.znam<=a.full()*znam;
};

bool Drob::operator<=(const int a){
  return full()<=a*znam;
};

bool operator<=(int a, Drob b){
  return b<=a;
}
