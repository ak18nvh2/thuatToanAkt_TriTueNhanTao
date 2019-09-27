//
//  main.cpp
//  akt
//
//  Created by hieuuu on 9/27/19.
//  Copyright © 2019 hieuuu. All rights reserved.
//

#include <iostream>
using namespace std;
bool check[50000000];// dung de kiem tra xem trangThai thu i da xuat hien hay chua, neu xuat hien roi thi la true, chua xuat hien thi la i.
int chiSo=2;// la chuoiTrangThaiTuDauDenDich.size()

struct trangThai
{
    int a[3][3];// luu trang thai bat ki cua tro choi
    int g,h,f;// g la so lan di chuyen khoang trang, h la so vi tri con sai so voi dich, f la g+h
};

trangThai chuoiTrangThaiTuDauDenDich[50000000];
int soSanhMang(int a[3][3], int b[3][3])// tim so vi tri khac nhau cua 2 mang
{
    int dem=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(a[i][j]!=b[i][j])
                dem++;
    return dem;
}
void xuatMang(int a[3][3])// xuat mang ra man hinh
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
}
void ganMang(int a[3][3], int b[3][3])// gan mang a thanh mang b
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            a[i][j]=b[i][j];
}

int timTrangThaiCon1(trangThai x, trangThai &con)//tim trang thai con voi phan tu thu [i+1][j], neu co the di chuyen khoang trang tu vi tri [i][j] den vi tri [i+1][j] va trang thai nay chua tung xuat hien thi trang thai nay dc coi la trang thai con cua trang thai x
{
    
    trangThai moi;
    int luu_i,luu_j;
    
    ganMang(moi.a,x.a);
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(moi.a[i][j]==0)
            {
                luu_i=i;
                luu_j=j;
            }
        }
    
    if(luu_i+1 < 3)
    {
        swap(moi.a[luu_i+1][luu_j],moi.a[luu_i][luu_j]);
        moi.g=x.g+1;
        moi.h=soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[0].a);
        moi.f=moi.g+moi.h;
        for(int i=1; i<chiSo; i++)
            if(soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[i].a)==0)
                return 0;
        con=moi;
        return 1;
    }
    else
        return 0;
    
}

int timTrangThaiCon2(trangThai x, trangThai &con)// tuong tu ham timTrangThaiCon2 nhung chuyen tu [i+1][j] thanh [i-1][j]
{
    
    trangThai moi;
    int luu_i,luu_j;
    
    ganMang(moi.a,x.a);
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(moi.a[i][j]==0)
            {
                luu_i=i;
                luu_j=j;
            }
        }
    
    if(luu_i-1>-1)
    {
        swap(moi.a[luu_i-1][luu_j],moi.a[luu_i][luu_j]);
        moi.g=x.g+1;
        moi.h=soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[0].a);
        moi.f=moi.g+moi.h;
        for(int i=1; i<chiSo; i++)
            if(soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[i].a)==0)
            {
                return 0;
            }
        con=moi;
        return 1;
    }
    else
        return 0;
    
}

int timTrangThaiCon3(trangThai x, trangThai &con)//[i][j+1]
{
    
    trangThai moi;
    int luu_i,luu_j;
    ganMang(moi.a,x.a);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(moi.a[i][j]==0)
            {
                luu_i=i;
                luu_j=j;
            }
        }
    
    if(luu_j+1<3)
    {
        swap(moi.a[luu_i][luu_j+1],moi.a[luu_i][luu_j]);
        moi.g=x.g+1;
        moi.h=soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[0].a);
        moi.f=moi.g+moi.h;
        for(int i=1; i<chiSo; i++)
            if(soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[i].a)==0)
            {
                return 0;
            }
        con=moi;
        return 1;
    }
    else
        return 0;
    
}

int timTrangThaiCon4(trangThai x, trangThai &con)//[i][j-1]
{
    
    trangThai moi;
    int luu_i,luu_j;
    
    ganMang(moi.a,x.a);
    
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(moi.a[i][j]==0)
            {
                luu_i=i;
                luu_j=j;
            }
        }
    
    if(luu_j-1>-1)
    {
        swap(moi.a[luu_i][luu_j-1],moi.a[luu_i][luu_j]);
        
        moi.g=x.g+1;
        moi.h=soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[0].a);
        moi.f=moi.g+moi.h;
        for(int i=1; i<chiSo; i++)
            if(soSanhMang(moi.a,chuoiTrangThaiTuDauDenDich[i].a)==0)
            {
                return 0;
            }
        con=moi;
        return 1;
    }
    else
        return 0;
    
}

void showTrangThai(trangThai x)// in ra trang thai hien tai dang xet
{
    
    cout<<"Lan di thu : "<<x.g<<endl;
    cout<<"Con sai "<<x.h<<" vi tri"<<endl;
    cout<<"Trang thai la: "<<endl;
    
    xuatMang(x.a);
    
}
int main()
{
   
    int banDau[3][3] = // trang thai dau
    {
        { 2, 8, 3 }, //row 1
        { 1, 6, 4 }, //row 2
        { 7, 0, 5 } //row 3
    };
    int dich[3][3] = // trang thai dich
    {
        { 1, 2, 3 }, //row 1
        { 8, 0, 4 }, //row 2
        { 7, 6, 5 } //row 3
    };
    // gan chuoiTrangThaiTuDauDenDich[1] la trang thai ban dau
    ganMang( chuoiTrangThaiTuDauDenDich[1].a,banDau);
    chuoiTrangThaiTuDauDenDich[1].g=0;
    chuoiTrangThaiTuDauDenDich[1].h=5;
    chuoiTrangThaiTuDauDenDich[1].f=chuoiTrangThaiTuDauDenDich[1].g+chuoiTrangThaiTuDauDenDich[1].h;
    //chuoiTrangThaiTuDauDenDich[0] la trang thai dich
    ganMang( chuoiTrangThaiTuDauDenDich[0].a,dich);
    
    int demTru=1;// so luong trangThai chua xet trong mang ChuoiTrangThaiTuDauDenDich
    int lanXet=0;// lan xet cac trang thai
    
    while(demTru>0)// neu khong con traiThai nao de xet nua thi dung
    {
        int giaTriMinF=9999;
        int vitriMinF;
        for(int i=1; i<chiSo; i++)// tim vi tri trạng thái co f nho nhat de kiem tra, neu la trangThai dich thi dung, k phải trang thái đích thì tìm các trạng thái con của nó
        {
            if(chuoiTrangThaiTuDauDenDich[i].f<giaTriMinF && check[i]==false)// chỉ xét những trạng thái chưa kiểm tra
            {
                vitriMinF=i;
                giaTriMinF=chuoiTrangThaiTuDauDenDich[i].f;
            }
        }
        check[vitriMinF]=true;// đã kiểm tra rồi thì không xét lại nữa
        demTru--;
        cout<<"Day la lan xet thu "<< ++lanXet<<endl;
        showTrangThai(chuoiTrangThaiTuDauDenDich[vitriMinF]);
        if(soSanhMang(chuoiTrangThaiTuDauDenDich[vitriMinF].a,dich)==0)// la dich thi dung, in ra dich
        {
            xuatMang(chuoiTrangThaiTuDauDenDich[vitriMinF].a);
            break;
        }
        else
        {
            trangThai moi;// tim trang thai con
            int ktr=timTrangThaiCon1(chuoiTrangThaiTuDauDenDich[vitriMinF],moi);
            if(ktr==1)// [i+1][j]
               {
                   chuoiTrangThaiTuDauDenDich[chiSo++]=moi;
                   demTru++;
               }
            
            ktr=timTrangThaiCon3(chuoiTrangThaiTuDauDenDich[vitriMinF],moi);
            if(ktr==1)//[x][j+1]
            {
                chuoiTrangThaiTuDauDenDich[chiSo++]=moi;
                demTru++;
            }
            
            ktr=timTrangThaiCon2(chuoiTrangThaiTuDauDenDich[vitriMinF],moi);
            if(ktr==1)//[x-1][j]
            {
                chuoiTrangThaiTuDauDenDich[chiSo++]=moi;
                demTru++;
            }
            ktr=timTrangThaiCon4(chuoiTrangThaiTuDauDenDich[vitriMinF],moi);
            if(ktr==1)//[x][j-1]
            {
                chuoiTrangThaiTuDauDenDich[chiSo++]=moi;
                demTru++;
            }
        }
        
    }
    
    return 0;
}

/*
 int banDau[3][3] = // trang thai dau
 {
 { 1, 2, 3 }, //row 1
 { 7, 5, 6 }, //row 2
 { 0, 4, 8 } //row 3
 };
 int dich[3][3] = // trang thai dich
 {
 { 3, 2, 1 }, //row 1
 { 5, 4, 6 }, //row 2
 { 0, 7, 8 } //row 3
 };
 -----------------
 bai sgk
 int banDau[3][3] = // trang thai dau
 {
 { 2, 8, 3 }, //row 1
 { 1, 6, 4 }, //row 2
 { 7, 0, 5 } //row 3
 };
 int dich[3][3] = // trang thai dich
 {
 { 1, 2, 3 }, //row 1
 { 8, 0, 4 }, //row 2
 { 7, 6, 5 } //row 3
 };
 */
