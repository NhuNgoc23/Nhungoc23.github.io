//Dung cau truc mang 1 chieu thao tac tren day so nguyen cai dat cac tac vu da hoc

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define		sptmax  40
//===================================0
void 	NhapDS 	(int a[], int n);
void 	NhapDS1 (int a[], int n);
void 	XuatDS 	(int a[], int n);
void 	Them1PTu (int a[], int *n, int vt, int x);
void 	Xoa1PTu  (int a[], int *n, int vt, int *x);
//===================================
int		BinarySearch (int a[], int n, int x); // tim kiem nhi phan
int		LinearSearch (int a[], int n, int x); // tim kiem tuyen tinh
//===================================
void 	CopyArr (int a[], int b[], int n);
void 	HoanVi (int *x, int *y);
//===================================
void 	InterchangeSort (int a[], int n); // sap xep doi cho truc tiep
void 	SelectionSort (int a[], int n); // sap xep chon truc tiep
void 	InsertionSort (int a[], int n); // sap xep chen truc tiep
void 	BubbleSort (int a[], int n); // sap xep noi bot
void 	QuickSort (int a[], int l, int r);// sap xep phan hach
//..............
//===================================
int main()
{
   //clrscr();		//Xoa MH
   system("cls");	//Hoa MH
   int 	a[sptmax], b[sptmax], n, x, vt, chon, kq, l, r;
   char ch;
   do
   {
      	system("cls");	//Hoa MH
      	printf("\n\tCAC GIAI THUAT TIM KIEM VA SAP XEP ");
		printf("\n\t1.  Nhap Danh Sach Tu Ban Phim ");
      	printf("\n\t2.  Nhap Danh Sach Ngau Nhien ");
      	printf("\n\t3.  Xuat Danh Sach ");
      	printf("\n\t4.  Them 1 Phan Tu Vao Danh Sach ");
      	printf("\n\t5.  Xoa 1 Phan Tu Ra Khoi Danh Sach ");
      	printf("\n\t6.	Tim Kiem Bang  Phuong Phap Nhi Phan ");
      	printf("\n\t7.	Tim Kiem Bang  Phuong Phap Tuyen Tinh ");
      	printf("\n\t8.	Sap Xep Bang  Phuong Phap Doi Cho Truc Tiep ");
      	printf("\n\t9.	Sap Xep Bang  Phuong Phap Chon Truc Tiep  ");
      	printf("\n\t10.	Sap Xep Bang  Phuong Phap Chen Truc Tiep  ");
      	printf("\n\t11.	Sap Xep Bang  Phuong Phap Bang Noi Bot ");
      	printf("\n\t12.	Sap Xep Bang  Phuong Phap Phan Hach ");
      	printf("\n\t..... !");
      	printf("\n\t0.  Thoat Khoi Chuong Trinh !!!");
      	printf("\n\tBan Chon Chuc Nang Nao ? :");
      	scanf ("%d", &chon);
      	switch (chon)
      	{
	  		case 1:
	  		{
				printf("\n\tNhap Danh Sach Tu Ban Phim ");
				printf("\n\tNhap So Phan Tu: ");
				scanf("%d", &n);
				NhapDS (a, n);
				break;  
			}
			case 2:
	  		{
				printf("\n\tNhap Danh Sach Ngau Nhien ");
				printf("\n\tNhap So Phan Tu : ");
				scanf("%d", &n);
				NhapDS1 (a, n);
				getch();
				break;  
			}
			case 3:
	  		{
				printf("\n\tXuat Danh Sach ");
				XuatDS (a, n);
				getch();
				break;  
			}
			case 4:
	  		{
				printf("\n\tThem 1 Phan Tu Vao Danh Sach");
				printf("\n\t Danh Sach Truoc Khi Them ");
				XuatDS(a, n);
				getch();
				printf("\n\tNhap Vi Tri Them [1 -> %d] : ", n + 1);
				scanf("%d", &vt);
				vt = vt - 1;
				while ((vt < 1) || (vt > n))
				{
					printf("\tNhap Lai Vi Tri Them [1 -> %d] : ", n + 1);
					scanf("%d", &vt);
					vt = vt - 1;
				}
				printf("\n\tNhap Noi Dung Can Them : ");
				scanf("%d", &x);
				Them1PTu (a, &n, vt, x);
				printf("\n\t Danh Sach Sau Khi Them ");
				XuatDS(a, n);
				getch();
				break;  
			}
			case 5:
	  		{
				printf("\n\tXoa 1 Phan Tu Trong Danh Sach");
				printf("\n\t Danh Sach Truoc Khi Xoa ");
				XuatDS(a, n);
				getch();
				printf("\n\tNhap Vi Tri Xoa [1 -> %d] : ", n);
				scanf("%d", &vt);
				vt = vt - 1;
				while ((vt < 1) || (vt >= n))
				{
					printf("\tNhap Lai Vi Tri Xoa [1 -> %d] : ", n);
					scanf("%d", &vt);
					vt = vt - 1;
				}
				Xoa1PTu (a, &n, vt, &x);
				printf("\n\t Danh Sach Sau Khi Xoa ");
				XuatDS(a, n);
				getch();
				break;  
			}
			case 6:
			{
				printf("\n\tTim Kiem Bang Phuong Phap Tuyen Tinh ");
				printf("\n\t Danh Sach Hien Tai ");
				XuatDS(a, n);
				getch();
				printf("\n\tNhap Noi Dung Can Tim : ");
				scanf("%d", &x);
				kq = LinearSearch (a, n, x);
				if (kq != -1)
					printf("\n\tTim Thay Phan Tu Co Noi Dung %d Trong Danh Sach Tai Vi Tri %d !", x, kq + 1);
				else
					printf("\n\tKhong Tim Thay Phan Tu Co Noi Dung %d Trong Danh Sach !", x);
				getch();
				break;  
			}
			case 7:
			{
				printf("\n\tTim Kiem Bang Phuong Phap Nhi Phan !");
				CopyArr (a, b, n);		
				InterchangeSort (b, n);		
				printf("\n\t Danh Sach Hien Tai ");
				XuatDS(b, n);
				getch();
				printf("\n\tNhap Noi Dung Can Tim : ");
				scanf("%d", &x);
				kq = BinarySearch (b, n, x);
				if (kq != -1)
					printf("\n\tTim Thay Phan Tu Co Noi Dung %d Trong Danh Sach Tai Vi Tri %d !", x, kq + 1);
				else
					printf("\n\tKhong Tim Thay Phan Tu Co Noi Dung %d Trong Danh Sach !", x);
				getch();
				break;  
			}
			case 8:
	  		{
				printf("\n\tSap Xep Bang Phuong Phap Doi Cho Truc Tiep ");
				CopyArr (a, b, n);		
				printf("\n\t Danh Sach Truoc Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				InterchangeSort (b, n);		
				printf("\n\t Danh Sach Sau Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				break;  
			}
			case 9:
	  		{
				printf("\n\tSap Xep Bang  Phuong Phap Chon Truc Tiep ");
				CopyArr (a, b, n);		
				printf("\n\t Danh Sach Truoc Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				SelectionSort (a, n);		
				printf("\n\t Danh Sach Sau Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				break;  
			}
			case 10:
	  		{
				printf("\n\tSap Xep Bang Phuong Phap Chen ");
				CopyArr (a, b, n);		
				printf("\n\t Danh Sach Truoc Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				InsertionSort ( a,  n);		
				printf("\n\t Danh Sach Sau Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				break;  
			}
			case 11:
	  		{
				printf("\n\tSap Xep Bang  Phuong Phap Chen Noi Bot ");
				CopyArr (a, b, n);		
				printf("\n\t Danh Sach Truoc Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				BubbleSort ( a, n);		
				printf("\n\t Danh Sach Sau Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				break;  
			}
			case 12:
	  		{
				printf("\n\tSap Xep Bang  Phuong Phap Phan Hach ");
				CopyArr (a, b, n);		
				printf("\n\t Danh Sach Truoc Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				QuickSort ( a,  l,  r);	
				printf("\n\t Danh Sach Sau Khi Sap Xep ");
				XuatDS(b, n);
				getch();
				break;  
			}
			
	  	}//KT Switch
	  
   }while (chon > 0);
   getch();		//Dung MH
   return 1;
}
//===================================
//===================================
void 	NhapDS (int a[], int n)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("\tNhap Noi Dung PT8u Thu %d :  ", i + 1);
		scanf("%6d", &a[i]);
	}
}
//===================================
void 	NhapDS1 (int a[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100 + 10;
		//rand() % GTToiDa So can random
	printf("\n\tNhap Thanh Cong !");
}

//===================================
void 	XuatDS (int a[], int n)
{	
	printf("\n\t");
	for (int i = 0; i < n; i++)
		printf("%8d", a[i]);
}
//===================================
/*
B1.  Kiem Tra DS Day (n > sptmax)
	-  Dung : mang day, Dung
	-  Nguoc lai, goi B2
B2.  Kiem tra tinh HLe cua vt them 
	neu (vt < 1 hoac > n + 1)
	-  Dung => vt them khong hop le , Dung	
	-  Nguoc lai (Vt them HLe), goi B3
B3.  Doi cac PTu tu cuoi den vt them len 1 vt
B4.  Gan PTu tai vt them = x (a[vt] = x)
	 Tang SPTu len 1 DV (n = n + 1)
*/
void 	Them1PTu (int a[], int *n, int vt, int x)
{
	if(*n >= sptmax)		//B1
		printf("\n\tDS Day ! Khong Them Dc !");
	else
		if ((vt < 0) || (vt > *n))	//B2
			printf("\n\tVi Tri Them Khong HLe !");
		else
		{
			//==  B3.  Doi .....
			for (int i = *n; i > vt; i--)
				a[i] = a[i - 1];		//Doi
			//=== KThuc B3 ====
			a[vt] = x;
			*n = *n + 1;
		}
}


//===================================
/*
B1.  Kiem Tra DS Rong (n < 1)
	-  Dung : Rong, Dung
	-  Nguoc lai, goi B2
B2.  Kiem tra tinh HLe cua vt xoa
	neu (vt < 1 hoac > n)
	-  Dung => vt them khong hop le , Dung	
	-  Nguoc lai (Vt them HLe), goi B3
B3.  Gan X = NDung PTu Xoa (X = A[VT])
B4.  Doi cac PTu tu vtxoa + 1 den cuoi xuong 1 vt
B5.  Gan PTu tai vt them = x (a[vt] = x)
	 Giam SPTu Xuong 1 DV (n = n - 1)
*/
void 	Xoa1PTu (int a[], int *n, int vt, int *x)
{
	if(*n < 1)		//B1
		printf("\n\tDS Rong ! Khong Xoa Dc !");
	else
		if ((vt < 0) || (vt >= *n))	//B2
			printf("\n\tVi Tri Xoa Khong HLe !");
		else
		{
			*x = a[vt];		//B3
			//==  B4.  Doi .....
			for (int i = vt + 1; i < *n; i++)
				a[i - 1] = a[i];		//Doi
			//=== KThuc B3 ====
			*n = *n - 1;
		}
}
//===================================
//Copy mang
void 	CopyArr (int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
//===================================
int		BinarySearch (int a[], int n, int x)
{
	int left = 0, right = n - 1;
	int mid;
	do
	{
		mid  = (int) (left + right)/ 2;
		if(a[mid] == x)
			return mid;		//Tim Thay
		if (a[mid] > x)		//Tim Ben Day Con Trai
			right = mid - 1;		//Xac dinh Right moi
		else			//Tim Ben Day Con Phai
			left = mid + 1;			//Xac dinh Left moi
	}while (left <= right);
	return -1;		//Khong Tim Thay
}
//===================================
int		LinearSearch (int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if(a[i] == x)
			return i;	//Tim Thay
	return -1;		//Khong Tim Thay 
}
//===================================
int		LinearSearch1 (int a[], int n, int x)
{
	int i = 0;
	while ((a[i] != x) && (i < n))
		i++;
	if(i < n)
		return i;	//Tim Thay
	return -1;		//Khong Tim Thay 
}
//===================================
int		LinearSearch2 (int a[], int n, int x)
{
	int i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	if(i < n)
		return i;	//Tim Thay
	return -1;		//Khong Tim Thay 
}
//===================================
//=====CAC GT SAP XEP================
void 	HoanVi (int *x, int *y)
{
	int tam;
	tam = *x;
	*x = *y;
	*y = tam;
}
//PP Doi Cho Truc Tiep
void 	InterchangeSort (int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		if (a[i] > a[j])	//HoanVi
			HoanVi (&a[i], &a[j]);
}
//===================================
void 	InterchangeSort_CTiet (int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{	printf("\n\t==== Khi I = %d ====", i);
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])	//HoanVi
			
				HoanVi (&a[i], &a[j]);
				
			XuatDS (a, n);
			printf("\t=== J = %d  =====", j);
		}
			
		getch();
	}
}

//===================================
void 	SelectionSort (int a[], int n)
{
	int min;
	for ( int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if ( a[j] < a[min] )
				min = j;
			HoanVi (&a[min], &a[i]);
	}
}
//========================================
void 	InsertionSort (int a[], int n)
{
	int pos, i;
	int x;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		pos = i - 1;
		while (( pos >= 0) && (a[pos] > x))
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;	
	}
}
//======================================
void 	BubbleSort (int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				HoanVi (&a[j], &a[j - 1]);
			
}
//======================================
void 	QuickSort (int a[], int l, int r)
{
	int i, j;
	int x;
	x = a[(l + r) / 2];
	do
	{
	i = l;
	j = r;
	while (a[i] < x) j++;
	while (a[i] > x) j--;
	if (i <= j)
	{
		HoanVi (&a[i], &a[j]);
		i++;
		j--;
	}
	}
	while ( i < j);
	if (l < j)
	QuickSort (a, i, r);
}

