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

void view(int x){
		printf("\n_______________________________________\n");
		printf("         Data Pasien ke-%d \n",x+1);
		printf("_______________________________________\n");
		printf("\nId_Pasien         	: %d",dt[x].pas.id_pasien);
	    printf("\nNama Pasien             : %s",dt[x].pas.nama);
	    printf("\nJenis Penyakit       	: %s",dt[x].pas.jenis_penyakit);
	    printf("\nJenis Kamar		: %s",dt[x].jenis_kamar);
		printf("\nNomor Kamar		: %d",dt[x].no_kamar);
	    printf("\ntanggal masuk		: %d-%d-%d\n",dt[x].tgl.tanggal,dt[x].tgl.bulan,dt[x].tgl.tahun);
}

int jumpsearch_idpasien(dat dt[], int size, int cari){
	int i;
	int mulai =0;
	int end = sqrt (size);
	
	while (dt[end].pas.id_pasien <= cari && end < size)
	{
		mulai=end;
		end += sqrt(size);
	}
	for(i=mulai; i<end; i++){
		if(dt[i].pas.id_pasien==cari){
			return i;
		}
	}
	return -1;
}

int jumpsearch_namapasien(dat dt[],int size, char cari_nama[]){ 
    int i;
	int target =0;
	int mulai = 0;
	int end = sqrt(size);
	
	while (strcmp(dt[target].pas.nama,cari_nama)!=0 && target <= size)
	{
		target++;
	}
	while (strcmp(dt[mulai].pas.nama,cari_nama) != 0 && target>mulai) //loncat
	{
		mulai += end;
	}
	
	mulai = mulai - end; // mundur 
	
	for(i=mulai; i<=target; i++){
		
		if (strcmp(cari_nama,dt[i].pas.nama)==0)
		{
			return i;
		}
	}
	return -1;
}

int jumpsearch_nokamar(dat dt[],int size,int cari){ //tidak bisa
	int i;
	int mulai=0;
	int end = sqrt(size);
	
	while(dt[end].no_kamar <= cari && end < size)
	{
		mulai=end;
		end += sqrt(size);
	}
	for(i=mulai; i<end; i++){
		if(dt[i].no_kamar == cari){
			return i;
		}
		return -1;
	}
}

int main(){
		
	int i,j,menu,search,sort,n=0,gap,temp,ubah;



	void pilihan_menu(){
		system("color F4");
		printf("\n ==================================================================");
		printf("\n \t\t\t\     PROGRAM APLIKASI");
		printf("\n\t\t\t PENDATAAN RUMAH SAKIT");
		printf("\n ==================================================================");
		printf("\n\n\t\t\t1. Input Data Pasien");
		printf("\n\t\t\t2. View Data Pasien");
		printf("\n\t\t\t3. Update Data Pasien");
		printf("\n\t\t\t4. Search Data Pasien");
		printf("\n\t\t\t5. Sort Data Pasien");
		printf("\n\t\t\t6. Keluar Aplikasi");
		printf("\n\nPilih Menu : "); scanf("%d",&menu);
		system("cls");
	}
	void pilihan_search(){
		printf("\n ================================================");
		printf("\n\t\tSEARCH DATA PASIEN\n");
		printf("\n ================================================\n");
		printf("\t1. Pencarian Berdasarkan ID Pasien \n");
    	printf("\t2. Pencarian Berdasarkan Nama Pasien \n");
    	printf("\t3. Pencarian Berdasarkan Nomor Kamar \n");
    	printf("\t4. Kembali ke Menu Utama");
		printf("\nPilih Menu : "); scanf("%d",&search);
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
		else if(menu==2)
		{
       		printf("----------------------------------------\n");
			printf("           VIEW DATA PASIEN	\n");
			printf("----------------------------------------\n");
            	if(n==0){
					printf("\n Input Data Pasien Terlebih Dahulu!!!");
				}else{
					for(i=0;i<n;i++){
						view(i);
				}
			}
			getch();
			system("cls");
		}
		else if(menu==3){
		}
		else if(menu==4){
			do{
				system("cls");
				pilihan_search();
				if(search==1){
        			int cari_id;
					system("cls");
					printf("========================================\n");
        			printf("		SEARCH DATA PASIEN				\n");
        			printf("	   *Berdasarkan ID Pasien*			\n");
        			printf("========================================\n");
					printf(" Masukkan ID Pasien Yang di cari : "); fflush(stdin); scanf("%d",& cari_id);
			
					int y;
					y=jumpsearch_idpasien(dt,n,cari_id);
					
					if(y==-1){
						printf("\n ID PASIEN TIDAK DITEMUKAN!!\n");
					}else{
						view(y);
					}
					getch();
					system("cls");
				}
				else if(search==2){
					char cari_nama[20];
					
					system("cls");
					printf("\n\t\t SEARCH DATA PASIEN(nama_pasien)\n");
					printf(" Masukan nama_pasien yang dicari : "); fflush(stdin); scanf("%s", &cari_nama);
					
					int y;
					
					y=jumpsearch_namapasien(dt,n,cari_nama);
					if(y == -1){
						printf("NAMA PASIEN TIDAK DITEMUKAN\n");
					}
					else
					{
						printf("Data Ketemu");
						view(y);
					}
					getch();
					system("cls");
				}
				else if(search==3){
					int cari_no;
					
					system("cls");
					printf("=======================================\n");
        			printf("		SEARCH DATA PASIEN			   \n");
        			printf("	   *Berdasarkan No Kamar*	       \n");
        			printf("=======================================\n");
					printf(" Masukan No Kamar Yang di Cari : "); fflush(stdin); scanf("%d", &cari_no);
					
					int y;
					y=jumpsearch_nokamar(dt,n,cari_no);
					
					if(y == -1){
						printf("NO KAMAR TIDAK DITEMUKAN!!\n");
					}
					else
					{
						view(y);
					}
					getch();
					system("cls");
				}
			}while(search!=4);
		}
			}while(menu!=0);
			 printf("Inputan Salah");
}

