#include<iostream>
#include<iomanip>
#include<sstream>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;

//=========================================================STRUCT NGAY / THANG / NAM======================================================
struct Ngay_Thang_Nam
{
	int ngay;
	int thang;
	int nam;
};
//=========================================================================================================================================

//=======================================================STRUCT KHOAN THU NHAP=============================================================
struct Thu{
	Ngay_Thang_Nam ntn;
	long int tienThu;
	string khoanThu;
	string ghiChu;
	int check;
};
//=========================================================================================================================================
 
//=======================================================STRUCT KHOAN CHI TIEU=============================================================
struct Chi{
	Ngay_Thang_Nam ntn;
	long int tienChi;
	string khoanChi;
	string ghiChu;
	int check;
};
//=========================================================================================================================================

//=======================================================STRUCT THONG TIN KHACH HANG=======================================================
struct Thong_Tin{
	string hoTen;
	int tuoi;
	string queQuan;
	string SDT;
	string CMT;
};

int check = 0; // Dung de kiem tra xem nguoi dung da nhap thong tin cac nhan hay chua.
//=========================================================================================================================================

//=============================================================STRUCT QUAN LY==============================================================
struct Quan_Ly{
	Chi C[100];
	Thu T[100];
	Thong_Tin TT;
};
//=======================================================================================================================================

//====================================================CHECK SO NGUYEN====================================================================
int checkSoNguyen(string k, string h)
{
	string x;
	int kt;
	do
	{
		kt = 1;
		cout<<k;
		fflush(stdin);
		getline(cin,x);
		
		for(int i=0; i<x.length(); i++)
		{
			if((int)x[i]<48||(int)x[i]>57)
			{
				kt = 0;
				break;
			}
		}
		
		if(kt==0||x=="\0")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<h<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(kt==0||x=="\0");
	
	int v = atoi(x.c_str());
	
	return v;
}

int checkSoNguyen_1(string k, string h)
{
	string x;
	int kt;
	do
	{
		kt = 1;
		cout<<k;
		fflush(stdin);
		getline(cin,x);
		
		for(int i=0; i<x.length(); i++)
		{
			if((int)x[i]<48||(int)x[i]>57)
			{
				kt = 0;
				break;
			}
		}
		
		if(kt==0||x=="\0")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<h<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			return -1;
		}
	}while(kt==0||x=="\0");
	
	int v = atoi(x.c_str());
	
	return v;
}

string checkSoNguyen_2(string k, string h)
{
	string x;
	int kt;
	do
	{
		kt = 1;
		cout<<k;
		fflush(stdin);
		getline(cin,x);
		
		for(int i=0; i<x.length(); i++)
		{
			if((int)x[i]<48||(int)x[i]>57)
			{
				kt = 0;
				break;
			}
		}
		
		if(kt==0||x=="\0")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<h<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(kt==0||x=="\0");
	
	return x;
}

string checkChuoi(string k, string h)
{
	string x;
	int kt;
	do
	{
		kt = 1;
		
		cout<<k;
		fflush(stdin);
		getline(cin,x);
		
		for(int i=0; i<x.length(); i++)
		{
			if((int)x[i]<65||((int)x[i]>90&&(int)x[i]<97)||(int)x[i]>122)
			{
				kt = 0;
				break;
			}
		}
		
		if(kt==0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<h<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(kt==0||x=="\0");
	
	return x;
}
//==========================================================================================================================================

//====================================================TINH SO NGAY CO TRONG 1 THANG BAT KY==================================================
int so_ngay_trong_thang(int nam, int thang)
{
	if(thang==4||thang==6||thang==9||thang==11)
	{
		return 30;
	}
	else if(thang==2)
	{
		if(nam%4==0&&nam%100!=0)
		{
			return 29;
		}
		if(nam%400==0) 
		{
			return 29; 
		}
		return 28;
	}
	
	return 31;
} 
//=========================================================================================================================================

//======================================================NHAP NGAY / THANG / NAM============================================================
void nhap_ngay(Ngay_Thang_Nam &k)
{
	cout<<endl;
	do
	{
		k.nam= checkSoNguyen("Nhap Nam: ", "ERROR: Nhap Nam Khong Hop Le. Vui Long Nhap Lai");
		if(k.nam<1980||k.nam>2025)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Vui Long Nhap Lai Nam(DK: 1980<=Nam<=2025)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(k.nam<1980||k.nam>2025);
	
	do
	{
		k.thang = checkSoNguyen("Nhap Thang: ", "ERROR: Nhap Thang Khong Hop Le. Vui Long Nhap Lai");
		if(k.thang<1||k.thang>12)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Vui Long Nhap Lai Thang(DK: 1<=Thang<=12)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(k.thang<1||k.thang>12);
	
	int soNgay;
	do
	{
		k.ngay = checkSoNguyen("Nhap Ngay: ", "ERROR: Nhap Ngay Khong Hop Le. Vui Long Nhap Lai");
		soNgay = so_ngay_trong_thang(k.nam, k.thang);
		if(k.ngay<1||k.ngay>soNgay)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Vui Long Nhap Lai Ngay(DK: 1<=Ngay<="<<soNgay<<")"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(k.ngay<1||k.ngay>soNgay);
}
//=================================================================================================================================

//===================================NHAP THONG TIN KHOAN CHI - LY QUYEN ANH=======================================================
void Them_Khoan_Chi_Tieu(Chi &C)
{
	string k; // Tao bien k de luu so tien so tien
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTHEM KHOAN CHI TIEU";
	cout<<"\n-------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	cout<<"Nhap Ten Khoan Chi: ";
	fflush(stdin);
	getline(cin,C.khoanChi);
	if(C.khoanChi.length()>=25) // Neu ten khoan chi co so ki tu lon hon hoac bang 25 thi ta se cat no di.
	{
		C.khoanChi.erase(25); // Ham erase dung de cat chuoi.
	}
	
	do
	{
		k = checkSoNguyen_2("Nhap So Tien Da Chi: ", "ERROR: So Tien Ban Nhap Khong Hop Le. Vui Long Nhap Lai");
		if(k.length()>9) // Neu so luong ki tu cua k ma lon hon 9 ki tu thi ta se phai nhap lai.
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: So Tien Ban Nhap Khong Duoc Vuot Qua 1000000000. Vui Long Nhap Lai"<<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(k.length()>9);
	
	C.tienChi = atoi(k.c_str());// Ham atoi() dung de chuyen 1 bien kieu CHAR thanh 1 bien kieu INT
								// c_str() dung de chuyen 1 chuoi thanh 1 mang ki tu.
	
	cout<<"Nhap Ngay/Thang/Nam: ";
	nhap_ngay(C.ntn);
	
	cout<<"Ghi Chu(Toi Da 50 Ky Tu - Neu Co): ";
	fflush(stdin);
	getline(cin,C.ghiChu);
	
	if(C.ghiChu.length()>=50) // Neu ghi chu co so ki tu lon hon hoac bang 50 thi ta se cat bo de cho tron 50 ki tu.
	{
		C.ghiChu.erase(50); // Ham erase dung de cat chuoi.
	}
	
	C.check=0;// DANH CHO PHAN XOA
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"Da Them Khoan Chi Tieu Nay Vao Danh Sach"<<endl;  // Thong bao cho nguoi dung biet la DA THEM THANH CONG KHOAN CHI VAO MANG.
	cout<<"----------------------------------------\n"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
//=========================================================================================================================================

//==========================================================NHAP THONG TIN KHOAN THU=======================================================
void Them_Khoan_Thu_Nhap(Thu &T)
{
	string k;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTHEM KHOAN THU NHAP";
	cout<<"\n-------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	cout<<"Nhap Ten Khoan Thu: ";
	fflush(stdin);
	getline(cin,T.khoanThu);
	if(T.khoanThu.length()>=25)
	{
		T.khoanThu.erase(25);
	}
	
	do
	{
		k = checkSoNguyen_2("Nhap So Tien Da Thu: ", "ERROR: So Tien Ban Nhap Khong Hop Le");
		if(k.length()>9)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: So Tien Ban Nhap Khong Duoc Vuot Qua 1000000000. Vui Long Nhap Lai"<<endl; 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(k.length()>9);
	
	T.tienThu = atoi(k.c_str());
	
	cout<<"Nhap Ngay/Thang/Nam: ";
	nhap_ngay(T.ntn);
	cout<<"Ghi Chu(Toi Da 50 Ky Tu - Neu Co): ";
	fflush(stdin);
	getline(cin,T.ghiChu);
	
	if(T.ghiChu.length()>=50)
	{
		T.ghiChu.erase(50);
	}
	
	T.check=0;// DANH CHO PHAN XOA
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"Da Them Khoan Thu Nhap Nay Vao Danh Sach"<<endl;
	cout<<"----------------------------------------\n"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
//=========================================================================================================================================

//===========================================================HAM TAO NGAY/THANG/NAM THANH 1 CHUOI============================
string Ham_Tao_Chuoi_NgayThangNam(int ngay, int thang, int nam)
{
	string tam;
	stringstream s1;	s1 << ngay;		string v1 = s1.str();	tam = v1 + "/";
	stringstream s2;	s2 << thang;	string v2 = s2.str();	tam = tam + v2 + "/";
	stringstream s3;	s3 << nam;		string v3 = s3.str();	tam = tam + v3;
	return tam;
}
//===========================================================XUAT THONG TIN KHOAN CHI======================================================
void Xuat_Cac_Khoan_Chi(Chi C, int STT)
{
	string tam = Ham_Tao_Chuoi_NgayThangNam(C.ntn.ngay, C.ntn.thang, C.ntn.nam);

	cout<<"|  "<<setw(6)<<left<<STT<<"|  "<<setw(25)<<left<<C.khoanChi<<"|  "<<setw(25)<<left<<C.tienChi<<"|  "<<setw(20)<<left<<tam<<"|  "<<setw(50)<<left<<C.ghiChu<<"|  "<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
}
//=========================================================================================================================================

//======================================THONG KE CAC KHOAN CHI TRONG 12 THANG - LY QUYEN ANH===============================================
void Thong_Ke_Cac_Khoan_Chi_Trong_12_Thang(Quan_Ly QL, int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<setw(55)<<" "<<"THONG KE CAC KHOAN CHI TRONG 12 THANG";
	cout<<endl<<setw(55)<<" "<<"-------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	long int tongTien = 0;
	for(int i=1; i<=12; i++) // Tuong trung cho 12 thang
	{
		int kt = 0; // Dung de kiem tra xem thang nay co ton tai khoan chi nao khong
		long long tongTien = 0;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		cout<<"|"<<setw(67)<<left<<" "<<"THANG "<<setw(67)<<left<<i<<"|"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Chi"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		for(int j=0; j<n; j++) // Cho bien j chay tu dau mang chi den cuoi mang chi
		{
			if(QL.C[j].ntn.thang == i) // Neu 1 khoan chi nao co thang nhap vao ma bang voi thang i thi ta se goi ham con Xuat_Cac_Khoan_Chi();
			{
				kt++;		Xuat_Cac_Khoan_Chi(QL.C[j],kt);			tongTien = tongTien + QL.C[j].tienChi;
			}
		}
		
		if(kt==0) // Neu kt==0 thi chung to thang i khong ton tai khoan chi nen ta se in ra man hinh cau "KHONG CO KHOAN CHI"
		{
			cout<<"|                                                             KHONG CO KHOAN CHI                                                             |"<<endl;
			cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		}
		else
		{
			stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
			cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA CHI"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
			cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
		}
		cout<<endl;
	}
}
//=========================================================================================================================================

//===========================================================XUAT THONG TIN KHOAN THU======================================================
void Xuat_Cac_Khoan_Thu(Thu T, int STT)
{
	string tam = Ham_Tao_Chuoi_NgayThangNam(T.ntn.ngay, T.ntn.thang, T.ntn.nam);
	
	cout<<"|  "<<setw(6)<<left<<STT<<"|  "<<setw(25)<<left<<T.khoanThu<<"|  "<<setw(25)<<left<<T.tienThu<<"|  "<<setw(20)<<left<<tam<<"|  "<<setw(50)<<left<<T.ghiChu<<"|  "<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
}
//=========================================================================================================================================

//=================================THONG KE CAC KHOAN THU TRONG 12 THANG - NGUYEN ANH THANG================================================
void Thong_Ke_Cac_Khoan_Thu_Trong_12_Thang(Quan_Ly QL, int m)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<setw(55)<<" "<<"THONG KE CAC KHOAN THU TRONG 12 THANG";
	cout<<endl<<setw(55)<<" "<<"-------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	for(int i=1; i<=12; i++)
	{
		int kt = 0;
		long long tongTien = 0;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		cout<<"|"<<setw(67)<<left<<" "<<"THANG "<<setw(67)<<left<<i<<"|"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Thu"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		for(int j=0; j<m; j++)
		{
			if(QL.T[j].ntn.thang == i)
			{
				kt++;   	Xuat_Cac_Khoan_Thu(QL.T[j],kt);	    	tongTien = tongTien + QL.T[j].tienThu;
			}
		}
		
		if(kt==0)
		{
			cout<<"|                                                             KHONG CO KHOAN THU                                                             |"<<endl;
			cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		}
		else
		{
			stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
			cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA THU"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
			cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
		}
		cout<<endl;
	}
}
//=========================================================================================================================================

//====================================THONG KE CAC KHOAN CHI THEO THANG - LY QUYEN ANH=====================================================
void Thong_Ke_Cac_Khoan_Chi(Quan_Ly QL, int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTHONG KE CAC KHOAN CHI THEO THANG"<<endl;
	cout<<"---------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	int thangZ, namZ; //thangZ dung de luu thang ma ta can thong ke, namZ dung de luu nam ma ta can thong ke.
	
	do
	{
		// Goi ham checkSoNguyen() de nhap nam can thong ke vao luu vao bien namZ
		namZ = checkSoNguyen("Nhap Nam Can Thong Ke: ","ERROR: Nam Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
		
		if(namZ<1980||namZ>2025) // Kiem tra xem namZ co nam trong khoang tu 2000->2025 hay ko?
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Nhap Lai Nam(DK: 1980<=Nam<=2025)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(namZ<1980||namZ>2025); // DK de yeu cau nguoi dung nhap lai nam.
	
	do
	{
		// Goi ham checkSoNguyen() de nhap thang can thong ke vao luu vao bien thangZ
		thangZ = checkSoNguyen("Nhap Thang Can Thong Ke: ","ERROR: Thang Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
		
		if(thangZ>12||thangZ<1) // Kiem tra xem thangZ co nam trong khoang tu 1->12 hay ko?
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Nhap Lai Thang(DK: 1<=Thang<=12)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
		
	}while(thangZ>12||thangZ<1); // DK de yeu cau nguoi dung nhap lai thang.
	
	int kt = 0; //Dung de kiem tra xem thang ma ta muon thong ke co ton tai khoan chi hay khong.
	long long tongTien = 0;
	
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(53)<<left<<" "<<"THONG KE CAC KHOAN CHI TRONG THANG "<<setw(52)<<left<<thangZ<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Chi"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<n; i++) // Cho vong for chay tu dau mang chi den cuoi mang chi
	{
		if(QL.C[i].ntn.thang==thangZ&&QL.C[i].ntn.nam==namZ) // Neu tim thay bat ky khoan chi nao do ma co thang, nam them vao ma bang voi thangZ, namZ thi ta se goi ham Xuat_Cac_Khoan_Chi();
		{
			kt++;
			Xuat_Cac_Khoan_Chi(QL.C[i],kt); // Goi ham de xuat thong tin khoan chi nay ra man hinh.
			tongTien = tongTien + QL.C[i].tienChi;
		}
	}
	
	if(kt==0) // Neu kt==0 thi co nghia trong mang chi khong ton tai khoan chi co thang nhap vao va nam nhap vao bang voi thangZ va namZ => Ta se in ra man hinh "KHONG CO KHOAN CHI".
	{
		cout<<"|                                                             KHONG CO KHOAN CHI                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Thang "<<thangZ<<"/"<<namZ<<" Khong Co Khoan Chi"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA CHI"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
	}
	cout<<endl;
}
//========================================================================================================================================

//=======================================THONG KE CAC KHOAN THU THEO THANG - NGUYEN ANH THANG==============================================
void Thong_Ke_Cac_Khoan_Thu(Quan_Ly QL, int m)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTHONG KE CAC KHOAN THU THEO THANG"<<endl;
	cout<<"---------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	
	int thangZ, namZ;
	
	do
	{
		namZ = checkSoNguyen("Nhap Nam Can Thong Ke: ","ERROR: Nam Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
		if(namZ<1980||namZ>2025)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Nhap Lai Nam(DK: 1980<=Nam<=2025)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(namZ<1980||namZ>2025);
	
	do
	{
		thangZ = checkSoNguyen("Nhap Thang Can Thong Ke: ","ERROR: Thang Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
		if(thangZ>12||thangZ<1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Nhap Lai Thang(DK: 1<=Thang<=12)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(thangZ>12||thangZ<1);
	
	int kt = 0;
	long long tongTien = 0;
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(53)<<left<<" "<<"THONG KE CAC KHOAN THU TRONG THANG "<<setw(52)<<left<<thangZ<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<m; i++)
	{
		if(QL.T[i].ntn.thang==thangZ&&QL.T[i].ntn.nam==namZ)
		{
			kt++;
			Xuat_Cac_Khoan_Thu(QL.T[i], kt);
			tongTien = tongTien + QL.T[i].tienThu;
		}
	}
	
	if(kt==0)
	{
		cout<<"|                                                             KHONG CO KHOAN THU                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Thang "<<thangZ<<"/"<<namZ<<" Khong Co Khoan Thu"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA THU"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
	}
	cout<<endl;
}
//===================================================================================================================================

//====================================NHAP THONG TIN CA NHAN KHACH HANG - NGUYEN ANH THANG============================================
void nhap_thong_tin_ca_nhan(Quan_Ly &QL)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<"NHAP VA CHINH SUA THONG TIN NGUOI DUNG"<<endl;
	cout<<"--------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	QL.TT.hoTen = checkChuoi("Nhap Ho Ten(Ghi Lien Khong Dau): ", "ERROR: Ho Ten Khong Duoc Chua Cac Ki Tu Dac Biet");
	if(QL.TT.hoTen.length()>30)
	{
		QL.TT.hoTen.erase(30);
	}
	
	do
	{
		QL.TT.tuoi = checkSoNguyen("Nhap Tuoi: ", "ERROR: So Tuoi Ban Nhap Khong Hop Le. Vui Long Nhap Lai Tuoi");
		if(QL.TT.tuoi<1||QL.TT.tuoi>99)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Vui Long Nhap Lai Tuoi (DK: 1<=Tuoi<=99)"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(QL.TT.tuoi<1||QL.TT.tuoi>99);
	
	
	do
	{
		cout<<"Nhap Que Quan: ";
		fflush(stdin);
		getline(cin,QL.TT.queQuan);
		if(QL.TT.queQuan=="\0")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: Que Quan Khong Hop Le. Vui Long Nhap Lai"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(QL.TT.queQuan=="\0");
	if(QL.TT.queQuan.length()>30)
	{
		QL.TT.queQuan.erase(30);
	}
	
	string v;
	do
	{
		v = checkSoNguyen_2("Nhap SDT: ", "ERROR: SDT Khong Hop Le. Vui Long Nhap Lai SDT");
		if(v.length()<8||v.length()>11)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: SDT Khong Hop Le. Vui Long Nhap Lai"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
	}while(v.length()<8||v.length()>13);
	QL.TT.SDT = v;
	 
	string v1;
	do
	{
		v1 = checkSoNguyen_2("Nhap CCCD: ", "ERROR: CCCD Khong Hop Le. Vui Long Nhap Lai CCCD");
		if(v1.length()==12||v1.length()==9)
		{
			break;
		}
		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
			cout<<"ERROR: CCCD Khong Hop Le. Vui Long Nhap Lai"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			
	}while(true);
	QL.TT.CMT = v1;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nDA LUU THONG TIN NGUOI DUNG"<<endl;
	cout<<"---------------------------\n"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	check = 1;
}
//=========================================================================================================================================

//=================================XUAT THONG TIN CAC NHAN KHACH HANG - LY QUYEN ANH=======================================================
void xuat_thong_tin_ca_nhan(Quan_Ly QL)
{
	if(check == 0) // Neu check==0 co nghia la nguoi dung chua nhap thong tin ca nhan nen ta in ra man hinh cau" Ban chua khoi tao thong tin ca nhan".
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Ban Chua Khoi Tao Thong Tin Ca Nhan"<<endl;
		cout<<"-----------------------------------"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else // Neu ma check!=0 thi ta in ra thong tin nguoi dung ra man hinh.
	{
		cout<<"\n\n\t\t\t\t\t\t                 THONG TIN NGUOI DUNG                "<<endl;
		cout<<"\t\t\t\t\t\t*--------------------*--------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|"<<setw(20)<<left<<"  HO TEN"<<"|  "<<setw(30)<<left<<QL.TT.hoTen<<"|"<<endl;
		cout<<"\t\t\t\t\t\t*--------------------*--------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|"<<setw(20)<<left<<"  TUOI"<<"|  "<<setw(30)<<left<<QL.TT.tuoi<<"|"<<endl;
		cout<<"\t\t\t\t\t\t*--------------------*--------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|"<<setw(20)<<left<<"  QUE QUAN"<<"|  "<<setw(30)<<left<<QL.TT.queQuan<<"|"<<endl;
		cout<<"\t\t\t\t\t\t*--------------------*--------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|"<<setw(20)<<left<<"  SDT"<<"|  "<<setw(30)<<left<<QL.TT.SDT<<"|"<<endl;
		cout<<"\t\t\t\t\t\t*--------------------*--------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|"<<setw(20)<<left<<"  CMT"<<"|  "<<setw(30)<<left<<QL.TT.CMT<<"|"<<endl;
		cout<<"\t\t\t\t\t\t*--------------------*--------------------------------*"<<endl<<endl;
	}
	
}
//=========================================================================================================================================

//=====================================================TIM KIEM CAC KHOAN THU THEO NGAY====================================================
void Thong_Ke_Cac_Khoan_Thu_Theo_Ngay(Quan_Ly QL, int m)
{
	int kt = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTIM KIEM CAC KHOAN THU THEO NGAY"<<endl;
	cout<<"--------------------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	long long tongTien = 0;
	Ngay_Thang_Nam ntnTam;
	nhap_ngay(ntnTam);
	string tam = Ham_Tao_Chuoi_NgayThangNam(ntnTam.ngay, ntnTam.thang, ntnTam.nam);
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN THU TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<m; i++)
	{
		if(QL.T[i].ntn.ngay==ntnTam.ngay&&QL.T[i].ntn.thang==ntnTam.thang&&QL.T[i].ntn.nam==ntnTam.nam)
		{
			kt++;
			Xuat_Cac_Khoan_Thu(QL.T[i],kt);
			tongTien = tongTien + QL.T[i].tienThu;
		}
	}
	if(kt==0)
	{
		cout<<"|                                                                KHONG CO KHOAN THU                                                          |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Ngay "<<tam<<" Khong Co Khoan Thu"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA THU"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
	}
	cout<<endl;
}
//=========================================================================================================================================

//=================================TIM KIEM CAC KHOAN CHI THEO NGAY - LY QUYEN ANH==========================================================
void Thong_Ke_Cac_Khoan_Chi_Theo_Ngay(Quan_Ly QL, int n)
{
	int kt = 0; // Dung de kiem tra xem ngay  ma ta can thong keco ton tai khoan chi hay ko?
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTIM KIEM CAC KHOAN CHI THEO NGAY"<<endl;
	cout<<"--------------------------------";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	long long tongTien = 0;
	Ngay_Thang_Nam ntnTam; // tao bien ntnTam de luu ngay/thang/nam can thong ke cac khoan chi
	nhap_ngay(ntnTam); // Goi ham nhap_ngay de nhap ngay/thang/nam
	
	string tam = Ham_Tao_Chuoi_NgayThangNam(ntnTam.ngay, ntnTam.thang, ntnTam.nam);
	
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN CHI TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan CHI"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<n; i++) // Cho vong for chay tu dau mang chi den cuoi mang chi
	{
		// Neu ta tim thay 1 khoan chi nao do co ngay/thang/nam them vao == voi ngay/thang/nam ma ta can thong ke thi ta goi ham Xuat_Cac_Khoan_Chi();
		if(QL.C[i].ntn.ngay==ntnTam.ngay&&QL.C[i].ntn.thang==ntnTam.thang&&QL.C[i].ntn.nam==ntnTam.nam)
		{
			kt++;
			Xuat_Cac_Khoan_Chi(QL.C[i],kt); // Goi ham Xuat_Cac_Khoan_Chi() De In Khoan chi ra man hinh.
			tongTien = tongTien + QL.C[i].tienChi;
		}
	}
	
	if(kt==0) // Neu kt==0 thi ta se in ra man hinh cau " KHONG CO KHOAN CHI".
	{
		cout<<"|                                                                KHONG CO KHOAN CHI                                                          |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Ngay "<<tam<<" Khong Co Khoan Chi"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA CHI"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
	}
	cout<<endl;
}
//=========================================================================================================================================

//=========================TIM KIEM NGAY THU NHIEU NHAT - NGUYEN ANH THANG==================================================
int tinh_tong_so_tien_thu_theo_ngay(Quan_Ly QL, int v, int m)
{
	int tong = 0;
	for(int i=v; i<m; i++)
	{
		if((QL.T[i].ntn.ngay==QL.T[v].ntn.ngay)&&(QL.T[i].ntn.thang==QL.T[v].ntn.thang)&&(QL.T[i].ntn.nam==QL.T[v].ntn.nam))
		{
			tong = tong + QL.T[i].tienThu;
		}
	}
	if(tong==0)
	{
		return -1;
	}
	return tong;
}

void Tim_Kiem_Ngay_Thu_Nhieu_Nhat(Quan_Ly QL, int m)
{
	int max = -1;
	cout<<"\n*---------------------------------------------------*"<<endl;
	cout<<"|                "<<"NGAY THU NHIEU NHAT"<<"                |"<<endl;
	cout<<"*--------*----------------------*-------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(20)<<left<<"Ngay/Thang/Nam"<<"|  "<<setw(17)<<left<<"Tong Tien"<<"|"<<endl;
	cout<<"*--------*----------------------*-------------------*"<<endl;
	
	for(int i=0; i<m; i++)
	{
		int tong = tinh_tong_so_tien_thu_theo_ngay(QL,i,m);
		if(tong>max)
		{
			max = tong;
		}
	}
	if(max==-1)
	{
		cout<<"|           "<<"KHONG CO NGAY THU NHIEU NHAT"<<"            |"<<endl;
		cout<<"*---------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Khong Co Ngay Thu Nhieu Nhat"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		int dem=1;
		for(int i=0; i<m; i++)
		{
			int tong = tinh_tong_so_tien_thu_theo_ngay(QL,i,m);
			if(tong==max)
			{
				string tam = Ham_Tao_Chuoi_NgayThangNam(QL.T[i].ntn.ngay,QL.T[i].ntn.thang,QL.T[i].ntn.nam);
				
				cout<<"|  "<<setw(6)<<left<<dem<<"|  "<<setw(20)<<left<<tam<<"|  "<<setw(17)<<left<<tong<<"|"<<endl;
				cout<<"*--------*----------------------*-------------------*"<<endl;
				
				dem++;
			}
		}
	}
	cout<<endl; 
}
//========================================================================================================================================

//=========================================TIM KIEM NGAY CHI NHIEU NHAT================================================
int tinh_tong_so_tien_chi_theo_ngay(Quan_Ly QL, int v, int m)
{
	int tong = 0;
	for(int i=v; i<m; i++)
	{
		if((QL.C[i].ntn.ngay==QL.C[v].ntn.ngay)&&(QL.C[i].ntn.thang==QL.C[v].ntn.thang)&&(QL.C[i].ntn.nam==QL.C[v].ntn.nam))
		{
			tong = tong + QL.C[i].tienChi;
		}
	}
	if(tong==0)
	{
		return -1;
	}
	return tong;
}

void Tim_Kiem_Ngay_Chi_Nhieu_Nhat(Quan_Ly QL, int n)
{
	int max = -1;
	cout<<"\n*---------------------------------------------------*"<<endl;
	cout<<"|                "<<"NGAY CHI NHIEU NHAT"<<"                |"<<endl;
	cout<<"*--------*----------------------*-------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(20)<<left<<"Ngay/Thang/Nam"<<"|  "<<setw(17)<<left<<"Tong Tien"<<"|"<<endl;
	cout<<"*--------*----------------------*-------------------*"<<endl;
	
	for(int i=0; i<n; i++)
	{
		int tong = tinh_tong_so_tien_chi_theo_ngay(QL,i,n);
		if(tong>max)
		{
			max = tong;
		}
	}
	if(max==-1)
	{
		cout<<"|           "<<"KHONG CO NGAY CHI NHIEU NHAT"<<"            |"<<endl;
		cout<<"*---------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Khong Co Ngay Chi Nhieu Nhat"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		int dem=1;
		for(int i=0; i<n; i++)
		{
			int tong = tinh_tong_so_tien_chi_theo_ngay(QL,i,n);
			if(tong==max)
			{
				string tam = Ham_Tao_Chuoi_NgayThangNam(QL.C[i].ntn.ngay,QL.C[i].ntn.thang,QL.C[i].ntn.nam);
				
				cout<<"|  "<<setw(6)<<left<<dem<<"|  "<<setw(20)<<left<<tam<<"|  "<<setw(17)<<left<<tong<<"|"<<endl;
				cout<<"*--------*----------------------*-------------------*"<<endl;
				
				dem++;
			}
		}
	}
	cout<<endl; 
}
//===========================================================================================================================

//===========================================DOC FILE - NGUYEN ANH THANG==================================================================
void Doc_File(Quan_Ly &QL, int &n, int &m)
{
	ifstream fileIn;
	
	fileIn.open("./Danh_Sach_Chi_Tieu.txt",ios_base::in);
	
	if(fileIn.fail()==true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: File 'Danh_Sach_Chi_Tieu.txt' Khong Ton Tai"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		string k;
		int h;
		
		while(fileIn.eof()!=true)
		{
			//LUU KHOAN CHI
			getline(fileIn,k,',');
			QL.C[n].khoanChi = k;
			
			//LUU SO TIEN
			fileIn>>h;
			
			//BO QUA DAU ','
			QL.C[n].tienChi = h;
			getline(fileIn,k,',');
			
			//LUU NGAY
			getline(fileIn,k,'/');
			h=atoi(k.c_str());
			QL.C[n].ntn.ngay = h;
			
			//LUU THANG
			getline(fileIn,k,'/');
			h=atoi(k.c_str());
			QL.C[n].ntn.thang = h;
			
			//LUU NAM
			getline(fileIn,k,',');
			h=atoi(k.c_str());
			QL.C[n].ntn.nam = h;
			
			//LUU GHI CHU
			getline(fileIn,k,'\n');
			QL.C[n].ghiChu = k;
			
			QL.C[n].check = 0;
			n++;
		}
		
		fileIn.close();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<"\nDa Doc File 'Danh_Sach_Chi_Tieu.txt' Thanh Cong"<<endl;
		cout<<"-----------------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	
	//-------------------------------------------------------------------------------------------------------------------
	
	fileIn.open("./Danh_Sach_Thu_Nhap.txt",ios_base::in);
	
	if(fileIn.fail()==true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: File 'Danh_Sach_Thu_Nhap.txt' Khong Ton Tai"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		string k;
		int h;
		
		while(fileIn.eof()!=true)
		{
			//LUU KHOAN THU NHAP
			getline(fileIn,k,',');
			QL.T[m].khoanThu = k;
			
			//LUU SO TIEN 
			fileIn>>h;
			QL.T[m].tienThu = h;
			
			//BO QUA DAU ','
			getline(fileIn,k,',');
			
			//LUU NGAY
			getline(fileIn,k,'/');
			QL.T[m].ntn.ngay = atoi(k.c_str());
			
			//LUU THANG
			getline(fileIn,k,'/');
			QL.T[m].ntn.thang = atoi(k.c_str());
			
			//LUU NAM
			getline(fileIn,k,',');
			QL.T[m].ntn.nam = atoi(k.c_str());
			
			//LUU GHI CHU
			getline(fileIn,k,'\n');
			QL.T[m].ghiChu = k;
			
			QL.T[m].check = 0;
			m++;
		}
		
		fileIn.close();
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<"\nDa Doc File 'Danh_Sach_Thu_Nhap.txt' Thanh Cong\n"<<endl;
		cout<<"-----------------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
}
//===========================================================================================================================

//==========================================GHI FILE - NGUYEN ANH THANG===============================================================
void Ghi_File(Quan_Ly QL, int n, int m)
{
	ofstream fileOut;
	
	fileOut.open("./danh_sach_chi.txt",ios_base::out);

	for(int i=0; i<n; i++)
	{
		fileOut<<QL.C[i].khoanChi<<","<<QL.C[i].tienChi<<","<<QL.C[i].ntn.ngay<<"/"<<QL.C[i].ntn.thang<<"/"<<QL.C[i].ntn.nam<<","<<QL.C[i].ghiChu<<endl;
	}
	
	fileOut.close();

	fileOut.open("./danh_sach_thu.txt",ios_base::out);
	for(int i=0; i<m; i++)
	{
		fileOut<<QL.T[i].khoanThu<<","<<QL.T[i].tienThu<<","<<QL.T[i].ntn.ngay<<"/"<<QL.T[i].ntn.thang<<"/"<<QL.T[i].ntn.nam<<","<<QL.T[i].ghiChu<<endl;
	}
	
	fileOut.close();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nDANG GHI FILE ..."<<endl;
	cout<<"\nGHI FILE THANH CONG"<<endl;
	cout<<"-------------------\n"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
//===========================================================================================================================

//==============================CHINH SUA THONG TIN KHOAN CHI TIEU - NGUYEN ANH THANG====================================================
void Chinh_Sua_Thong_Tin_Khoan_Chi_Tieu(Quan_Ly &QL, int n)
{
	Thong_Ke_Cac_Khoan_Chi_Trong_12_Thang(QL,n);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<"CHINH SUA THONG TIN KHOAN CHI THEO NGAY"<<endl;
	cout<<"---------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	Chi *C[n];
	int dem=0;
	Ngay_Thang_Nam ntnTam;
	nhap_ngay(ntnTam);
	string tam = Ham_Tao_Chuoi_NgayThangNam(ntnTam.ngay, ntnTam.thang, ntnTam.nam);
	
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN CHI TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan CHI"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<n; i++)
	{
		if(QL.C[i].ntn.ngay==ntnTam.ngay&&QL.C[i].ntn.thang==ntnTam.thang&&QL.C[i].ntn.nam==ntnTam.nam)
		{
			C[dem] = &QL.C[i];
			Xuat_Cac_Khoan_Chi(QL.C[i],dem+1);
			dem++;
		}
	}
	
	if(dem==0)
	{
		cout<<"|                                                             KHONG CO KHOAN CHI                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Ngay "<<ntnTam.ngay<<"/"<<ntnTam.thang<<"/"<<ntnTam.nam<<" Khong Co Khoan Chi Nao De Ban Chinh Sua"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		int STT;
		do
		{
			STT = checkSoNguyen("Nhap STT Khoan Chi Can Chinh Sua: ","ERROR: STT Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
			if(STT<1||STT>dem)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				cout<<"ERROR: Nhap Lai STT(DK: 1<=STT<="<<dem<<")"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}while(STT<1||STT>dem);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<"\nMoi Ban Chinh Sua Thong Tin Khoan Chi Nay: "<<endl;
		cout<<"------------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		
		cout<<"Nhap Ten Khoan Chi: ";
		fflush(stdin);
		getline(cin,C[STT-1]->khoanChi);
		if(C[STT-1]->khoanChi.length()>=25)
		{
			C[STT-1]->khoanChi.erase(25);
		}
		
		string k;
		do
		{
			k = checkSoNguyen_2("Nhap So Tien Da Chi: ", "ERROR: So Tien Ban Nhap Khong Hop Le");
			if(k.length()>9)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				cout<<"ERROR: So Tien Ban Nhap Khong Duoc Vuot Qua 1000000000. Vui Long Nhap Lai"<<endl; 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}while(k.length()>9);
		
		C[STT-1]->tienChi = atoi(k.c_str());
		
		cout<<"Nhap Ngay/Thang/Nam: ";
		nhap_ngay(C[STT-1]->ntn);
		cout<<"Ghi Chu(Neu Co): ";
		fflush(stdin);
		getline(cin,C[STT-1]->ghiChu);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<endl<<"CHINH SUA THONG TIN KHOAN CHI THANH CONG"<<endl;
		cout<<"---------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
}
//===========================================================================================================================

//=====================================CHINH SUA THONG TIN KHOAN THU NHAP====================================================
void Chinh_Sua_Thong_Tin_Khoan_Thu_Nhap(Quan_Ly &QL, int m)
{
	Thong_Ke_Cac_Khoan_Thu_Trong_12_Thang(QL,m);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<"CHINH SUA THONG TIN KHOAN THU THEO NGAY"<<endl;
	cout<<"---------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	Thu *T[m];
	int dem=0;
	Ngay_Thang_Nam ntnTam;
	nhap_ngay(ntnTam);
	string tam = Ham_Tao_Chuoi_NgayThangNam(ntnTam.ngay, ntnTam.thang, ntnTam.nam);
	
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN THU TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Thu"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<m; i++)
	{
		if(QL.T[i].ntn.ngay==ntnTam.ngay&&QL.T[i].ntn.thang==ntnTam.thang&&QL.T[i].ntn.nam==ntnTam.nam)
		{
			T[dem] = &QL.T[i];
			Xuat_Cac_Khoan_Thu(QL.T[i],dem+1);
			dem++;
		}
	}
	
	if(dem==0)
	{	
		cout<<"|                                                             KHONG CO KHOAN THU                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Ngay "<<ntnTam.ngay<<"/"<<ntnTam.thang<<"/"<<ntnTam.nam<<" Khong Co Khoan Thu Nao De Ban Chinh Sua"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		int STT;
		do
		{
			STT = checkSoNguyen("Nhap STT Khoan Thu Can Chinh Sua: ","ERROR: STT Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
			if(STT<1||STT>dem)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				cout<<"ERROR: Nhap Lai STT(DK: 1<=STT<="<<dem<<")"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}while(STT<1||STT>dem);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<"\nMoi Ban Chinh Sua Thong Tin Khoan Thu Nay: "<<endl;
		cout<<"------------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		
		cout<<"Nhap Ten Khoan Thu: ";
		fflush(stdin);
		getline(cin,T[STT-1]->khoanThu);
		if(T[STT-1]->khoanThu.length()>=25)
		{
			T[STT-1]->khoanThu.erase(25);
		}
		
		string k;
		do
		{
			k = checkSoNguyen_2("Nhap So Tien Da Thu: ", "ERROR: So Tien Ban Nhap Khong Hop Le");
			if(k.length()>9)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				cout<<"ERROR: So Tien Ban Nhap Khong Duoc Vuot Qua 1000000000. Vui Long Nhap Lai"<<endl; 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}while(k.length()>9);
		T[STT-1]->tienThu = atoi(k.c_str());
		
		cout<<"Nhap Ngay/Thang/Nam: ";
		nhap_ngay(T[STT-1]->ntn);
		cout<<"Ghi Chu(Neu Co): ";
		fflush(stdin);
		getline(cin,T[STT-1]->ghiChu);
		
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<endl<<"CHINH SUA THONG TIN KHOAN THU THANH CONG"<<endl;
		cout<<"---------------------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
}
//=======================================================================================================================================

//==============================XOA MOT KHOAN CHI TRONG 1 NGAY BAT KI - NGUYEN ANH THANG=================================================
void Xoa_Mot_Khoan_Chi_Trong_Mot_Ngay_Bat_Ki(Quan_Ly &QL,int &n)
{
	Thong_Ke_Cac_Khoan_Chi_Trong_12_Thang(QL,n);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<"XOA MOT KHOAN CHI TRONG MOT NGAY BAT KY"<<endl;
	cout<<"---------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	Chi *C[n];
	int dem=0;
	long long tongTien = 0; 
	Ngay_Thang_Nam ntnTam;
	nhap_ngay(ntnTam);
	string tam = Ham_Tao_Chuoi_NgayThangNam(ntnTam.ngay, ntnTam.thang, ntnTam.nam);
	
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN CHI TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Chi"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<n; i++)
	{
		if(QL.C[i].ntn.ngay==ntnTam.ngay&&QL.C[i].ntn.thang==ntnTam.thang&&QL.C[i].ntn.nam==ntnTam.nam)
		{
			C[dem] = &QL.C[i];
			Xuat_Cac_Khoan_Chi(QL.C[i],dem+1);
			tongTien = tongTien + QL.C[i].tienChi; 
			dem++;
		}
	}
	
	if(dem==0)
	{
		cout<<"|                                                             KHONG CO KHOAN CHI                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: NGAY "<<tam<<" KHONG CO KHOAN CHI"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA CHI"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*\n"<<endl;

		int STT;
		do
		{
			STT = checkSoNguyen("Nhap STT Khoan Chi Can Xoa: ","ERROR: STT Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
			if(STT<1||STT>dem)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				cout<<"ERROR: Nhap STT(DK: 1<=STT<="<<dem<<")"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}while(STT<1||STT>dem);
		C[STT-1]->check = 1;
		
		//TIM VI TRI PT CAN XOA TRONG MANG CAC KHOAN CHI
		int viTri;
		for(int i=0; i<n; i++)
		{
			if(QL.C[i].check == 1)
			{
				viTri = i;
				break;
			}
		}
		
		//XOA PT O VI TRI CAN XOA
		for(int i=viTri; i<n-1; i++)
		{
			QL.C[i] = QL.C[i+1];
		}
		n--; 
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<endl<<"DA XOA KHOAN CHI THANH CONG"<<endl;
		cout<<"---------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		
		dem = 0;
		tongTien = 0; 
		cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN CHI TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Chi"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		for(int i=0; i<n; i++)
		{
			if(QL.C[i].ntn.ngay==ntnTam.ngay&&QL.C[i].ntn.thang==ntnTam.thang&&QL.C[i].ntn.nam==ntnTam.nam)
			{
				Xuat_Cac_Khoan_Chi(QL.C[i],dem+1);
				tongTien = tongTien + QL.C[i].tienChi; 
				dem++;
			}
		}
		
		if(dem == 0)
		{
			cout<<"|                                                             KHONG CO KHOAN CHI                                                             |"<<endl;
			cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		}
		else
		{
			stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
			cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA CHI"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
			cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
		} 
	}
	cout<<endl;
}
//========================================================================================================================================

//==============================XOA MOT KHOAN THU TRONG 1 NGAY BAT KI - NGUYEN ANH THANG=================================================
void Xoa_Mot_Khoan_Thu_Trong_Mot_Ngay_Bat_Ki(Quan_Ly &QL,int &m)
{
	Thong_Ke_Cac_Khoan_Thu_Trong_12_Thang(QL,m);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<endl<<"XOA MOT KHOAN THU TRONG MOT NGAY BAT KY"<<endl;
	cout<<"---------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	Thu *T[m];
	int dem=0;
	long long tongTien = 0; 
	Ngay_Thang_Nam ntnTam;
	nhap_ngay(ntnTam);
	string tam = Ham_Tao_Chuoi_NgayThangNam(ntnTam.ngay, ntnTam.thang, ntnTam.nam);
	
	cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN THU TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Thu"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<m; i++)
	{
		if(QL.T[i].ntn.ngay==ntnTam.ngay&&QL.T[i].ntn.thang==ntnTam.thang&&QL.T[i].ntn.nam==ntnTam.nam)
		{
			T[dem] = &QL.T[i];
			Xuat_Cac_Khoan_Thu(QL.T[i],dem+1);
			tongTien = tongTien + QL.T[i].tienThu; 
			dem++;
		}
	}
	
	if(dem==0)
	{
		cout<<"|                                                             KHONG CO KHOAN THU                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: NGAY "<<tam<<" KHONG CO KHOAN THU"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA THU"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*\n"<<endl;

		int STT;
		do
		{
			STT = checkSoNguyen("Nhap STT Khoan Thu Can Xoa: ","ERROR: STT Ban Vua Nhap Khong Hop Le. Vui Long Nhap Lai");
			if(STT<1||STT>dem)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
				cout<<"ERROR: Nhap STT(DK: 1<=STT<="<<dem<<")"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			}
		}while(STT<1||STT>dem);
		T[STT-1]->check = 1;
		
		//TIM VI TRI PT CAN XOA TRONG MANG CAC KHOAN THU
		int viTri;
		for(int i=0; i<m; i++)
		{
			if(QL.T[i].check == 1)
			{
				viTri = i;
				break;
			}
		}
		
		//XOA PT O VI TRI CAN XOA
		for(int i=viTri; i<m-1; i++)
		{
			QL.T[i] = QL.T[i+1];
		}
		m--; 
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<endl<<"\nDA XOA KHOAN THU THANH CONG"<<endl;
		cout<<"---------------------------"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		
		dem = 0;
		long long tongTien = 0; 
		cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		cout<<"|"<<setw(57)<<left<<""<<"CAC KHOAN THU TRONG NGAY "<<setw(57)<<left<<tam<<" |"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Thu"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
		cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
		for(int i=0; i<m; i++)
		{
			if(QL.T[i].ntn.ngay==ntnTam.ngay&&QL.T[i].ntn.thang==ntnTam.thang&&QL.T[i].ntn.nam==ntnTam.nam)
			{
				Xuat_Cac_Khoan_Thu(QL.T[i],dem+1);
				tongTien = tongTien + QL.T[i].tienThu;
				dem++;
			}
		}
		
		if(dem == 0)
		{
			cout<<"|                                                             KHONG CO KHOAN THU                                                             |"<<endl;
			cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		}
		else
		{
			stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
			cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA THU"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
			cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
		} 
	}
}
//========================================================================================================================================

//=======================================XOA TAT CA CAC KHOAN CHI - LY QUYEN ANH===============================================================
void Xoa_Tat_Ca_Cac_Khoan_Chi(int &n)
{
	if(n==0) // Neu n == 0 thi ta se in ra man hinh cau "Yeu Cau Nay Khong Duoc Thuc Hien Vi Mang Luu Tru Cac Khoan Thu Dang Trong"
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<"ERROR: Yeu Cau Nay Khong Duoc Thuc Hien Vi Mang Luu Tru Cac Khoan Chi Dang Trong\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		n = 0; // Dinh dang lai so luong phan tu cua mang chi. n=0
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<"\n\nDA XOA TAT CA CAC KHOAN CHI"<<endl;
		cout<<"---------------------------\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
}
//========================================================================================================================================

//==================================XOA TAT CA CAC KHOAN THU - LY QUYEN ANH===============================================================
void Xoa_Tat_Ca_Cac_Khoan_Thu(int &m)
{
	if(m==0) // Neu n == 0 thi ta se in ra man hinh cau "Yeu Cau Nay Khong Duoc Thuc Hien Vi Mang Luu Tru Cac Khoan Chi Dang Trong"
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<endl<<"ERROR: Yeu Cau Nay Khong Duoc Thuc Hien Vi Mang Luu Tru Cac Khoan Thu Dang Trong\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		return;
	}
	else
	{
		m = 0; // Dinh dang lai so luong phan tu cua mang thu. m=0
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
		cout<<"\nDA XOA TAT CA CAC KHOAN THU"<<endl;
		cout<<"---------------------------\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
}
//========================================================================================================================================

//=====================================CHUYEN DOI CHUOI VE DANG CHUAN=====================================================================
string Chuyen_Doi_Chuoi_Ve_Dang_Chuan(string k)
{
	//Chuyen chuoi k ve chuoi chua tat ca cac ki tu la chu thuong 
	for(int i=0;i<k.length();i++)
	{
	    if(k[i]>=65&&k[i]<=90)
	    {
	  	    k[i] = k[i]+32;
	  	}
    }
    
    //Xoa tat ca cac khoang trang dau chuoi
    while(k.length()>0)
	{
		if(k[0]==32)
		{
		  	k.erase(0,1);
		}
		else
		{
		  	break;
		}
   }
   //xoa tat ca cac khoang trang cuoi chuoi
   while(k.length()>0)
   {
        if(k[k.length()-1]==32)
        {
      	    k.erase(k.length()-1);
	    }
	    else
	    {
	  	    break;
	    }
	}
	
	return k;
}
//========================================================================================================================================

//=====================================TIM KIEM KHOAN CHI THEO TEN KHOAN CHI - NGUYEN ANH THANG===========================================
void Tim_Kiem_Khoan_Chi_Theo_Ten_Khoan_Chi(Quan_Ly QL,int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\nTHONG KE KHOAN CHI THEO TEN KHOAN CHI";
	cout<<"\n-------------------------------------"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	string k;
	int kt = 0;
	long long tongTien = 0;
	cout<<"Nhap Ten Khan Chi Can Tim Kiem: ";
	fflush(stdin);
	getline(cin,k);
	
	k = Chuyen_Doi_Chuoi_Ve_Dang_Chuan(k);
    
    cout<<"\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(61)<<left<<" "<<"THONG KE CAC KHOAN CHI"<<setw(57)<<left<<" "<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Chi"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Chi"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<n; i++) // Cho vong for chay tu dau mang chi den cuoi mang chi
	{
		string tam = Chuyen_Doi_Chuoi_Ve_Dang_Chuan(QL.C[i].khoanChi);
		if(tam.find(k) != -1) // Neu tim thay bat ky khoan chi nao do ma co thang, nam them vao ma bang voi thangZ, namZ thi ta se goi ham Xuat_Cac_Khoan_Chi();
		{
			kt++;
			Xuat_Cac_Khoan_Chi(QL.C[i],kt); // Goi ham de xuat thong tin khoan chi nay ra man hinh.
			tongTien = tongTien + QL.C[i].tienChi;
		}
	}
	
	if(kt==0) // Neu kt==0 thi co nghia trong mang chi khong ton tai khoan chi co thang nhap vao va nam nhap vao bang voi thangZ va namZ => Ta se in ra man hinh "KHONG CO KHOAN CHI".
	{
		cout<<"|                                                             KHONG CO KHOAN CHI                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Khong Tim Thay Khoan Chi"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA CHI"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
	}
	cout<<endl;
   	
}
//========================================================================================================================================

//=====================================TIM KIEM KHOAN CHI THEO TEN KHOAN CHI - NGUYEN ANH THANG=====================================
void Tim_Kiem_Khoan_Thu_Theo_Ten_Khoan_Thu(Quan_Ly QL,int m)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	cout<<"\n\nTHONG KE KHOAN THU THEO TEN KHOAN THU";
	cout<<"\n-------------------------------------\n"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	
	string k;
	int kt = 0;
	long long tongTien = 0;
	cout<<"Nhap Ten Khoan Thu Can Tim Kiem: ";
	fflush(stdin);
	getline(cin,k);
	
	k = Chuyen_Doi_Chuoi_Ve_Dang_Chuan(k);
    
    cout<<"\n\n*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
	cout<<"|"<<setw(61)<<left<<" "<<"THONG KE CAC KHOAN THU"<<setw(57)<<left<<" "<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	cout<<"|  "<<setw(6)<<left<<"STT"<<"|  "<<setw(25)<<left<<"Khoan Thu"<<"|  "<<setw(25)<<left<<"Gia Tien"<<"|  "<<setw(20)<<left<<"Ngay Thu"<<"|  "<<setw(50)<<left<<"Ghi Chu"<<"|"<<endl;
	cout<<"*--------*---------------------------*---------------------------*----------------------*----------------------------------------------------*"<<endl;
	for(int i=0; i<m; i++)
	{
		string tam = Chuyen_Doi_Chuoi_Ve_Dang_Chuan(QL.T[i].khoanThu);
		if(tam.find(k) != -1)
		{
			kt++;
			Xuat_Cac_Khoan_Thu(QL.T[i],kt);
			tongTien = tongTien + QL.T[i].tienThu;
		}
	}
	
	if(kt==0)
	{
		cout<<"|                                                             KHONG CO KHOAN THU                                                             |"<<endl;
		cout<<"*--------------------------------------------------------------------------------------------------------------------------------------------*"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
		cout<<"\nERROR: Khong Tim Thay Khoan Thu"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	}
	else
	{
		stringstream s1;	s1 << tongTien;		string v1 = s1.str();	string tam = v1 + " VND";
		cout<<"|"<<setw(22)<<left<<" "<<"TONG SO TIEN DA THU"<<setw(23)<<left<<" "<<"|"<<setw(31)<<left<<" "<<" "<<setw(43)<<left<<tam<<"|"<<endl;
		cout<<"*----------------------------------------------------------------*---------------------------------------------------------------------------*"<<endl;
	}
	cout<<endl;
   	
}
//========================================================================================================================================

//================================================MENU DUNG DE QUAN LY CHUONG TRINH=======================================================
void Menu(Quan_Ly &QL)
{
	int luaChon1;
	int n = 0, m = 0;
	while(true)
	{
		system("cls");
		cout<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
		cout<<"\t\t\t\t\t\t                   QUAN LY THU/CHI                "<<endl;
		cout<<"\t\t\t\t\t\t*=====*==========================================*"<<endl;
		cout<<"\t\t\t\t\t\t|  1  |  THEM KHOAN CHI TIEU                     |"<<endl; // LY QUYEN ANH
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  2  |  THEM KHOAN THU NHAP                     |"<<endl; // NGUYEN ANH THANG
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  3  |  CAC THONG KE VA CHINH SUA CUA KHOAN CHI |"<<endl; 
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  4  |  CAC THONG KE VA CHINH SUA CUA KHOAN THU |"<<endl; 
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  5  |  NHAP VA CHINH SUA THONG TIN CA NHAN     |"<<endl; // NGUYEN ANH THANG
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  6  |  XEM THONG TIN CA NHAN                   |"<<endl; // LY QUYEN ANH
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  7  |  DOC FILE                                |"<<endl; // NGUYEN ANH THANG
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  8  |  GHI FILE                                |"<<endl; // NGUYEN ANH THANG
		cout<<"\t\t\t\t\t\t*-----*------------------------------------------*"<<endl;
		cout<<"\t\t\t\t\t\t|  0  |  THOAT                                   |"<<endl;	
		cout<<"\t\t\t\t\t\t*=====*==========================================*"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		
		luaChon1 = checkSoNguyen_1("Moi Ban Lua Chon: ", "ERROR: Lua Chon Khong Hop Le. Vui Long Kiem Tra Lai"); 
		
		switch(luaChon1)
		{
			case -1:
				{
					system("pause");
				}break;
			case 0:
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
					cout<<"\nXIN CHAO BAN"<<endl;
					cout<<"------------";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					return;
				}
			case 1:
				{
					Them_Khoan_Chi_Tieu(QL.C[n]);
					n++;
					system("pause");
				}break;
			case 2:
				{
					Them_Khoan_Thu_Nhap(QL.T[m]);
					m++;
					system("pause");
				}break;
			case 3:
				{
					int luaChon2;
					while(true)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
						system("cls");
						cout<<endl;
						cout<<"\t\t\t\t\t\t        CAC THONG KE VA CHINH SUA KHOAN CHI          "<<endl;
						cout<<"\t\t\t\t\t\t*=====*=============================================*"<<endl;
						cout<<"\t\t\t\t\t\t|  1  |  THONG KE CAC KHOAN CHI THEO THANG          |"<<endl; // LY QUYEN ANH
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
						cout<<"\t\t\t\t\t\t|  2  |  THONG KE CAC KHOAN CHI TRONG 12 THANG      |"<<endl; // NGUYEN ANH THANG
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
						cout<<"\t\t\t\t\t\t|  3  |  THONG KE CAC KHOAN CHI THEO NGAY           |"<<endl; // LY QUYEN ANH
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl; 
						cout<<"\t\t\t\t\t\t|  4  |  TIM KIEM KHOAN CHI THEO TEN KHOAN CHI      |"<<endl; // NGUYEN ANH THANG
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl; 
						cout<<"\t\t\t\t\t\t|  5  |  TIM KIEM NGAY CHI NHIEU NHAT               |"<<endl; // NGUYEN ANH THANG
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl; 
						cout<<"\t\t\t\t\t\t|  6  |  CHINH SUA THONG TIN KHOAN CHI              |"<<endl; // NGUYEN ANH THANG 
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
						cout<<"\t\t\t\t\t\t|  7  |  XOA MOT KHOAN CHI TRONG MOT NGAY BAT KI    |"<<endl; // NGUYEN ANH THANG
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
						cout<<"\t\t\t\t\t\t|  8  |  XOA TAT CA CAC KHOAN CHI                   |"<<endl; // LY QUYEN ANH 
						cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
						cout<<"\t\t\t\t\t\t|  0  |  TRO LAI                                    |"<<endl;
						cout<<"\t\t\t\t\t\t*=====*=============================================*"<<endl<<endl;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						
						luaChon2 = checkSoNguyen_1("Moi Ban Luu Chon: ", "ERROR: Lua Chon Khong Hop Le. Vui Long Kiem Tra Lai");
						
						if(luaChon2==0)
						{
							break;
						}
						switch(luaChon2)
						{
							case -1:
							{
								system("pause");
							}break;
							case 1:
							{
								Thong_Ke_Cac_Khoan_Chi(QL,n);
								system("pause");
							}break;
							case 2:
							{
								Thong_Ke_Cac_Khoan_Chi_Trong_12_Thang(QL,n);
								system("pause");
							}break;
							case 3:
							{
								Thong_Ke_Cac_Khoan_Chi_Theo_Ngay(QL,n);
								system("pause");
							}break;
							case 4:
							{
								Tim_Kiem_Khoan_Chi_Theo_Ten_Khoan_Chi(QL,n);
								system("pause");
							}break;
							case 5:
							{
								Tim_Kiem_Ngay_Chi_Nhieu_Nhat(QL,n);
								system("pause");
							}break;
							case 6:
							{
								Chinh_Sua_Thong_Tin_Khoan_Chi_Tieu(QL,n);
								system("pause");
							}break;
							case 7:
							{
								Xoa_Mot_Khoan_Chi_Trong_Mot_Ngay_Bat_Ki(QL,n);
								system("pause");
							}break;
							case 8:
							{
								Xoa_Tat_Ca_Cac_Khoan_Chi(n);
								system("pause");
							}break;
							default:
							{
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
								cout<<"ERROR: Lua Chon Khong Hop Le [0->7]"<<endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
								system("pause");
							}
						}
					}
				}break;
			
			case 4:{
				int luaChon3;
				while(true)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
					system("cls");
					cout<<endl;
					cout<<"\t\t\t\t\t\t        CAC THONG KE VA CHINH SUA KHOAN THU          "<<endl;
					cout<<"\t\t\t\t\t\t*=====*=============================================*"<<endl;
					cout<<"\t\t\t\t\t\t|  1  |  THONG KE CAC KHOAN THU THEO THANG          |"<<endl; // NGUYEN ANH THANG
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
					cout<<"\t\t\t\t\t\t|  2  |  THONG KE CAC KHOAN THU TRONG 12 THANG      |"<<endl; // LY QUYEN ANH
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
					cout<<"\t\t\t\t\t\t|  3  |  THONG KE CAC KHOAN THU THEO NGAY           |"<<endl; // LY QUYEN ANH
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl; 
					cout<<"\t\t\t\t\t\t|  4  |  TIM KIEM KHOAN THU THEO TEN KHOAN THU      |"<<endl; 
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl; 
					cout<<"\t\t\t\t\t\t|  5  |  TIM KIEM NGAY THU NHIEU NHAT               |"<<endl; // NGUYEN ANH THANG
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl; 
					cout<<"\t\t\t\t\t\t|  6  |  CHINH SUA THONG TIN KHOAN THU              |"<<endl; // NGUYEN ANH THANG
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
					cout<<"\t\t\t\t\t\t|  7  |  XOA MOT KHOAN THU TRONG MOT NGAY BAT KI    |"<<endl; // NGUYEN ANH THANG
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
					cout<<"\t\t\t\t\t\t|  8  |  XOA TAT CA CAC KHOAN THU                   |"<<endl; // LY QUYEN ANH
					cout<<"\t\t\t\t\t\t*-----*---------------------------------------------*"<<endl;
					cout<<"\t\t\t\t\t\t|  0  |  TRO LAI                                    |"<<endl;
					cout<<"\t\t\t\t\t\t*=====*=============================================*"<<endl<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					
					luaChon3 = checkSoNguyen_1("Moi Ban Luu Chon: ", "ERROR: Lua Chon Khong Hop Le. Vui Long Lua Chon Lai"); 
		
					if(luaChon3==0)
					{
						break;
					}
					switch(luaChon3)
					{
						case -1:
						{
							system("pause");
						}break;
						case 1:
						{
							Thong_Ke_Cac_Khoan_Thu(QL,m);
							system("pause");
						}break;
						case 2:
						{
							Thong_Ke_Cac_Khoan_Thu_Trong_12_Thang(QL,m);
							system("pause");
						}break;
						case 3:
						{
							Thong_Ke_Cac_Khoan_Thu_Theo_Ngay(QL,m);
							system("pause");
						}break;
						case 4:
						{
							Tim_Kiem_Khoan_Thu_Theo_Ten_Khoan_Thu(QL,m);
							system("pause");
						}break;
						case 5:
						{
							Tim_Kiem_Ngay_Thu_Nhieu_Nhat(QL,m);
							system("pause");
						}break;
						case 6:
						{
							Chinh_Sua_Thong_Tin_Khoan_Thu_Nhap(QL,m);
							system("pause");
						}break;
						case 7:
						{
							Xoa_Mot_Khoan_Thu_Trong_Mot_Ngay_Bat_Ki(QL,m);
							system("pause");
						}break;
						case 8:
						{
							Xoa_Tat_Ca_Cac_Khoan_Thu(m);
							system("pause");
						}break;
						default:
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
							cout<<"ERROR: Lua Chon Khong Hop Le [0->7]"<<endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
							system("pause");
						}
					}
				}
			}break;
			
			case 5:
				{
					nhap_thong_tin_ca_nhan(QL);
					system("pause");
				}break;
			case 6:
				{
					xuat_thong_tin_ca_nhan(QL);
					system("pause");
				}break;
			case 7:
				{
					Doc_File(QL,n,m);
 					system("pause");
 				}break;
			case 8:
				{
					Ghi_File(QL,n,m);
 					system("pause");
				}break;
			default:
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
					cout<<"ERROR: Lua Chon Khong Hop Le. Vui Long Kiem Tra Lai"<<endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					system("pause");
				}
		}
	} 
}
//=====================================================================================================================================

//================================================HAM MAIN()===========================================================================
int main()
{
	Quan_Ly QL;
	Menu(QL);
}
