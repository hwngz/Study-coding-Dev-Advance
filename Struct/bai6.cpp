#include <iostream>
#include <algorithm>

using namespace std;

struct PhanSo{
	int tu, mau;
};

void nhapPhanSo(PhanSo &p);
void xuatPhanSo(PhanSo p);
void nhapArr(PhanSo *arr, int &size);
void xuatArr(PhanSo *arr, int size);
void rutGon(PhanSo &p);
bool soSanh(PhanSo a, PhanSo b);
int main() {
	int n=0;
    PhanSo *ps = new PhanSo[1000];
    nhapArr(ps, n);
    cout<<"Mang phan so: ";
    xuatArr(ps,n);
    for(int i=0; i<n; i++)
    {
        rutGon(ps[i]);
    }

    int dema=0, demd=0;
    for(int i=0; i<n; i++)
    {
        if(ps[i].tu * ps[i].mau < 0)
        {
            dema++;
        }else if(ps[i].tu * ps[i].mau > 0)
        {
            demd++;
        }
    }
    cout<<"\nMang phan so sau khi rut gon: ";xuatArr(ps,n);
    PhanSo ddd;
    ddd.tu=0;
    ddd.mau=1;
    for(int i=0; i<n; i++)
    {
        if(ps[i].tu * ps[i].mau > 0)
        {
            ddd=ps[i];
            break;
        }
    }

    PhanSo mx=ps[0], mi=ps[0];
    for(int i=1; i<n; i++)
    {
        if(soSanh(ps[i], mx))
            mx=ps[i];
        if(soSanh(mi, ps[i]))
            mi=ps[i];
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j < n; j++)
        {
            if(soSanh(ps[i], ps[j]))
                swap(ps[i],ps[j]);
        }
    }
    cout<<"\nMang theo thu tu tang dan: ";
    xuatArr(ps,n);

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j < n; j++)
        {
            if(soSanh(ps[j], ps[i]))
                swap(ps[i],ps[j]);
        }
    }
    cout<<"\nMang theo thu tu tang dan: ";
    xuatArr(ps,n);


    cout<<"\nSo luong phan so am la: "<<dema;
    cout<<"\nSo luong phan so duong la: "<<demd;
    cout<<"\nSo duong dau tien la: ";xuatPhanSo(ddd);
    cout<<"\nPhan so lon nhat la: ";
    xuatPhanSo(mx);
    cout<<"\nPhan so nho nhat la: ";
    xuatPhanSo(mi);
    
    delete[] ps;
	return 0;
}

void nhapPhanSo(PhanSo &p)
{
    cin>>p.tu>>p.mau;
}
void xuatPhanSo(PhanSo p)
{
    cout << p.tu << "/" << p.mau<<' ';
}

void nhapArr(PhanSo *arr, int &size)
{
    while(cin>>arr[size].tu>>arr[size].mau)
    {
        size++;
    }
}
void xuatArr(PhanSo *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        xuatPhanSo(arr[i]);
    }
}

void rutGon(PhanSo &p){
	int x = __gcd(p.tu, p.mau);
	p.tu /= x;
	p.mau /= x;
    
    if(p.tu * p.mau < 0)
    {
        if(p.mau < 0)
        {
            p.tu=-abs(p.tu);
            p.mau=abs(p.mau);
        }
    }
    else
    {
        p.tu=abs(p.tu);
        p.mau=abs(p.mau);
    }
}

bool soSanh(PhanSo a, PhanSo b)
{
    return a.tu*b.mau > b.tu*a.mau;
}