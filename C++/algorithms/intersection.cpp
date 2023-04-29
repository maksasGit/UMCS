#include <math.h>
#include<bits/stdc++.h>

#define F_EPS 1e-4

using namespace std;

class Vector3{
public:
  float x,y,z;
  Vector3(){}
  Vector3(float _x, float _y, float _z){x=_x; y=_y; z=_z;}
  float len2(){return x*x + y*y + z*z;}
  float len(){return sqrt(len2());}
  void normalize(){float l=sqrt(x*x+y*y+z*z); x/=l; y/=l; z/=l;}
  float operator * (Vector3 arg){return x*arg.x + y*arg.y + z*arg.z;}
  Vector3 operator = (Vector3 src){x=src.x; y=src.y; z=src.z; return *this;}
  Vector3 operator + (Vector3 arg){Vector3 tmp(x+arg.x, y+arg.y, z+arg.z); return tmp;}
  Vector3 operator - (Vector3 arg){Vector3 tmp(x-arg.x, y-arg.y, z-arg.z); return tmp;}
  Vector3 operator * (float l){Vector3 tmp(x*l, y*l, z*l); return tmp;} //scalar multiply
};

/*
 * ray_st, ray_dir - start point and direction of the ray
 * sp_cen, sp_rad - center point and radius of the sphere
 * res1, res2 - intersection points (if there is less than 2 intersections - no changes)
 * return value - number of intersections
 */
int find_intersection(Vector3 ray_st, Vector3 ray_dir, Vector3 sp_cen, float sp_rad, Vector3 &res1, Vector3 &res2){
  Vector3 middle; //middle point between intersections
  Vector3 dist; //vector from center of sphere to ray start
  Vector3 dpos; //vector from ray_st to sp_cen
  float len2; //square of distance from center of sphere to ray
  ray_dir.normalize();
  sp_rad *= sp_rad;

  dpos = sp_cen - ray_st;
  middle = ray_st + ray_dir*(ray_dir*dpos);
  len2 = (middle - sp_cen).len2();

  if(len2 > sp_rad)return 0;
  if(fabs( len2 - sp_rad )<F_EPS){
    res1 = middle;
    return 1;
  }
  len2 = sqrt(sp_rad - len2);
  //now len2 is distance, not its square
  res1 = middle - ray_dir*len2;
  res2 = middle + ray_dir*len2;
  return 2;
}

int main(){
  Vector3 r1, r2;
  int num;
  num = find_intersection(Vector3(-1,0,0),Vector3(1,0 , 0 ), Vector3(0,0.5,0.5),1, r1, r2);
  cout << r1.x << ' ' << r1.y << ' ' << r1.y << ' ' << endl;
  cout << num << endl;
}
