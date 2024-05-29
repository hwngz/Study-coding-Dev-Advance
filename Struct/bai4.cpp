#include<iostream>
#include<cmath>
using namespace std;
struct Diem
{
    double x,y;
};

struct TamGiac
{
    Diem a,b,c;
};
void Nhap(Diem &a);
void Xuat(Diem a);
double KhoangCachGiuaHaiDiem(Diem &a, Diem &b);
Diem DoixungO(Diem p);
Diem DoixungOx(Diem p);
Diem DoixungOy(Diem p);
int Phantu(Diem p);
//tamgiac
void NhapTamGiac(TamGiac &tg);
void XuatTamGiac(TamGiac tg);
double TinhChuVi(TamGiac tg);
double TinhDienTich(TamGiac tg);
int main()
{
    //**********************matphang********************************
    Diem a,b;
    Nhap(a);
    Nhap(b);
    Xuat(a);
    Xuat(b); 
    cout<<"Khoang cach giua hai diem: "<<KhoangCachGiuaHaiDiem(a,b)<<'\n';
    cout<<"Diem doi xung qua goc toa do: ";
    Xuat(DoixungO(a));
    cout<<"Diem doi xung qua truc 0x: ";
    Xuat(DoixungOx(a));
    cout<<"Diem doi xung qua truc Oy: ";
    Xuat(DoixungOy(a));

    int ktpt = Phantu(a); //dat bien de kiem tra diem co thuoc phan tu nao hay khong
    if(ktpt!=0)
        cout<<"Diem a thuoc phan tu thu: "<<Phantu(a)<<'\n';
    else
        cout << "Điem nam tren truc hoac tai goc toa đo.\n";
    
    //*****************tam giac*******************************
    TamGiac tamgiac;
    NhapTamGiac(tamgiac);
    cout<<"Toa do 3 diem cua tam giac";
    XuatTamGiac(tamgiac);
    cout<<"Chu vi tam giac: "<<TinhChuVi(tamgiac)<<'\n';
    cout<<"Dien tich tam giac: "<<TinhDienTich(tamgiac);
    return 0;
}

void Nhap(Diem &a)
{
    cin>>a.x>>a.y;
}
void Xuat(Diem a)
{
    cout<<'{'<<a.x<<","<<a.y<<'}'<<'\n';
}

double KhoangCachGiuaHaiDiem(Diem &a, Diem &b)
{
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt((dx*dx)+(dy*dy));
}

Diem DoixungO(Diem p){
    Diem O;
    O.x = -p.x;
    O.y = -p.y;
    return O;
}

Diem DoixungOx(Diem p){
    Diem dx;
    dx.x = p.x;
    dx.y = -p.y;
    return dx;
}
Diem DoixungOy(Diem p){
    Diem dy;
    dy.x = -p.x;
    dy.y = p.y;
    return dy;
}

int Phantu(Diem p){
    if (p.x > 0 && p.y > 0) {
        return 1; // Phần tư thứ nhất
    } else if (p.x < 0 && p.y > 0) {
        return 2; // Phần tư thứ hai
    } else if (p.x < 0 && p.y < 0) {
        return 3; // Phần tư thứ ba
    } else if (p.x > 0 && p.y < 0) {
        return 4; // Phần tư thứ tư
    } else {
        return 0; // Điểm nằm trên trục hoặc tại gốc tọa độ
    }
}

//************tam giac************************
void NhapTamGiac(TamGiac &tg){
    Nhap(tg.a);
    Nhap(tg.b);
    Nhap(tg.c);
}
void XuatTamGiac(TamGiac tg){
    Xuat(tg.a);
    Xuat(tg.b);
    Xuat(tg.c);
}

double TinhChuVi(TamGiac tg)
{
	double s,P,AB,AC,BC;
	AB = KhoangCachGiuaHaiDiem(tg.a,tg.b);
    P = AB + AC + BC;
    return P;
}
double TinhDienTich(TamGiac tg)
{
	double s,p,AB,AC,BC;			
	AB = KhoangCachGiuaHaiDiem(tg.a,tg.b);
	AC = KhoangCachGiuaHaiDiem(tg.a,tg.c);
	BC = KhoangCachGiuaHaiDiem(tg.b,tg.c);

	p=(AB +AC +BC)/2;

	s = sqrt(p*(p- AB)*(p-AC)*(p-BC));
	return s;
}