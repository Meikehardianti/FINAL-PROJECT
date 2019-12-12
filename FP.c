#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

struct tanggal{
	int tanggal;
	int bulan;
	int tahun;
};

struct pasien{
	int id_pasien;
	char nama[100];
	char jenis_penyakit[100];
};

struct data{
	char jenis_kamar[100];
	int no_kamar;
	struct tanggal tgl;
	struct pasien pas;
};
typedef struct data dat;
dat dt[100];

void input();
void view ();


void input(int x){
    printf("Masukkan Id_Pasien	    	    : ",x+1);fflush(stdin); scanf("%d",&dt[x].pas.id_pasien);
    printf("Masukkan Nama Pasien                : ",x+1);fflush(stdin); gets(dt[x].pas.nama);
    printf("Masukkan Jenis Penyakit		    : ",x+1);fflush(stdin); gets(dt[x].pas.jenis_penyakit);
    printf("Masukkan Jenis Kamar		    : ",x+1);fflush(stdin); gets(dt[x].jenis_kamar);
	printf("Masukkan Nomor Kamar		    : ",x+1);fflush(stdin); scanf("%d",&dt[x].no_kamar);
    printf("Masukkan Tanggal Masuk(1-31)        : ",x+1);fflush(stdin); scanf("%d",&dt[x].tgl.tanggal);
    printf("Masukkan Bulan Masuk		    : ",x+1);fflush(stdin); scanf("%d",&dt[x].tgl.bulan);
    printf("Masukkan tahun masuk		    : ",x+1);fflush(stdin); scanf("%d",&dt[x].tgl.tahun);
}
int main(){
		
	int i,j,menu,search,sort,n=0,gap,temp,ubah;



	void pilihan_menu(){
		printf("======================================================\n");
		printf("\tPROGRAM APLIKASI PENDATAAN RUMAH SAKIT \n");
		printf("======================================================\n");
		printf("\n1. Input Data Pasien");
		printf("\n2. View Data Pasien");
		printf("\n3. Update Data Pasien");
		printf("\n4. Search Data Pasien");
		printf("\n5. Sort Data Pasien");
		printf("\n6. Keluar Aplikasi");
		printf("\n\nPilih Menu : "); scanf("%d",&menu);
		system("cls");
	}	
	do{
		system("cls");
		pilihan_menu();
		if(menu==1){
			printf("----------------------------------------\n");
			printf("           INPUT DATA PASIEN	\n");
			printf("----------------------------------------\n");
			input(n);
            n++;
            system("cls");
		}
			}while(menu!=0);
			 printf("Inputan Salah");
		}

