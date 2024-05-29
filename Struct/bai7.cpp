#include<iostream>
#include<cmath>
using namespace std;
struct Diem
{
    double x,y;
};
void Nhap(Diem &a);
void Xuat(Diem a);
void NhapArr(Diem arr[], int size);
void XuatArr(Diem arr[], int size);
double tinhKhoangCach(Diem diem);
Diem timDiemGanGocToaDoNhat(Diem arr[], int size);
int main()
{
    int size, dem = 0, dem2=0;
    cin>>size;
    Diem *arr= new Diem[size];
    NhapArr(arr,size);
    cout<<"Mang diem: ";
    XuatArr(arr,size);

    Diem a;
    a.x=arr[0].x;
    a.y=arr[0].y;

    Diem mi;
    mi.x=arr[0].x;
    mi.y=arr[0].y;
    for(int i=0; i<size; i++)
    {
        if(arr[i].x > 0)
        {
            dem++;
        }

        if(a.x==arr[i].x && arr[i].y==a.y)
        {
            dem2++;
        }

        if(a.x < arr[i].x)
        {
            a.x=arr[i].x;
            a.y=arr[i].y;
        }

        if(mi.x > arr[i].x)
        {
            mi.x=arr[i].x;
            mi.y=arr[i].y;
        }
    }
    cout<<"\nSo diem co hoanh do duong: "<<dem;
    cout<<"\nSo diem trung voi cac diem khac: "<<dem2;
    cout<<"\nDiem co hoanh do lon nhat la: ";Xuat(a);
    cout<<"\nDiem co hoanh do nho nhat la: ";Xuat(mi);

    Diem diemGanNhat = timDiemGanGocToaDoNhat(arr, size);
    cout << "\nDiem gan goc toa do nhat: ";Xuat(diemGanNhat);

}
void Nhap(Diem &a)
{
    cin>>a.x>>a.y;
}
void Xuat(Diem a)
{
    cout<<'{'<<a.x<<","<<a.y<<'}';
}
void NhapArr(Diem arr[], int size)
{
    
    for (int i = 0;i <size ; ++i)
    {
        Nhap(arr[i]);
    }
}
void XuatArr(Diem arr[], int size)
{
    for (int i = 0;i <size ; ++i)
    {
        Xuat(arr[i]);
    }
}

double tinhKhoangCach(Diem diem) {
  return sqrt(diem.x * diem.x + diem.y * diem.y);
}

Diem timDiemGanGocToaDoNhat(Diem arr[], int size) {
  Diem diemGanNhat = arr[0];
  double khoangCachMin = tinhKhoangCach(diemGanNhat);

  for (int i = 1; i < size; i++) {
    double khoangCach = tinhKhoangCach(arr[i]);
    if (khoangCach < khoangCachMin) {
      khoangCachMin = khoangCach;
      diemGanNhat = arr[i];
    }
  }

  return diemGanNhat;
}