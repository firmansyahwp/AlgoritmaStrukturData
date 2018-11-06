// TUGAS BESAR ALGORITMA DAN STRUKTUR DATA 
// SEMESTER GANJIL 2017
// TEKNIK INFORMATIKA
// INSTITUT TEKNOLOGI SUMATERA
// KELAS RB
				


#include <stdio.h>								// untuk pembacaan bahasa c
#include <stdlib.h>								// untuk menggunakan pointer
#include <time.h>								// untuk menggunakan fungsi random
#include <windows.h>								// untuk menggunakan waktu dan menghapus layar
#include <conio.h>								// untuk memberhentikan program sejenak

#define boolean unsigned char							// untuk membuat fungsi pengecekan dengan boolean
#define true 1
#define false 0

#define Nil NULL

typedef char infotype;
typedef struct tElmtList *address;
typedef struct tElmtList{
    infotype info;
    address next;
}ElmtList;

typedef struct{
    address First;
}List;

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First

boolean IsEmpty(List L) {							// untuk mengecek isi list kosong atau tidak
    return (First(L)==Nil);						
}

void CreateEmpty(List *L) {							// untuk membuat list kosong
    First(*L)=Nil;
}

address Allocation(infotype X) {						// untuk memesan memori yang ditambahkan ke list
    address NodeBaru;

    NodeBaru=(address)malloc(sizeof(ElmtList));
    Info(NodeBaru)=X;
    Next(NodeBaru)=Nil;

    return NodeBaru;
}

void InsertVFirst(List *L, char x) {
    address P;

    P=Allocation(x);
    if(P!=Nil){
        Next(P)=First(*L);
        First(*L)=P;
    }
    
}


char symbolacak() {								// untuk membuat symbol berupa char sebanyak 6 tipe
    char symbol; 
    char n;
    
	n = rand() % 6;
    symbol = 'a' + n;
    if(symbol=='a'){
    	symbol='*';
	} else if(symbol=='b'){
		symbol='/';
	} else if(symbol=='c'){
		symbol='-';
	} else if(symbol=='d'){
		symbol='+';
	} else if(symbol=='e'){
		symbol='$';
	} else if(symbol=='f'){
		symbol='%';
	}
	
    return symbol;
}

int JumlahSkor (List L) {							// untuk menghitung isi total isi list 
	int sum = 0;
	address P;

	P = First(L);
	while (P != Nil ) {
		sum += Info(P);
		P = Next(P);
	}
	return (sum);
}

int main () {
	
	int pilihanmenu,i,a,j;
	int n=1;
    int b1[100], b2;
	char symbol;
    List Lskor;
    boolean test = true;
	
	Menu :
	
	printf ("=================||===================================||=====================\n");
	printf ("=================|| Wellcome To Brains Challenge Game ||=====================\n");
	printf ("=================||===================================||=====================\n\n");
	printf ("1. Play Game\n");
	printf ("2. Game Instructions\n");
	printf ("0. Quit Game\n\n");
	printf ("Choose your answer : ");	
	scanf ("%d",&pilihanmenu);
	
	if (pilihanmenu==0) {
		system("CLS");
		printf ("\n\n----------------------------- See You! -------------------------------\n\n");
	} else if (pilihanmenu==1) {
		printf ("\nLet's Play'!\nPrepare Yourself!\n\nLoading...............");
		sleep(3);
		system("CLS");
	
	CreateEmpty(&Lskor);
	
	do {
		
		j=0;
		
		printf ("===========================================================================\n");
		printf ("============================ BRAINS CHALLENGE =============================\n");
		printf ("===========================================================================\n\n");
		
		printf ("Scene %d : \n\n",n);
		srand(time(Nil));						// digunakan untuk selalu mengacak symbol yang muncul saat dipanggil
	    for(i=15;i!=0;i--)
	    {
	        symbol = symbolacak();
	        
	        if (symbol=='*') {						// menghitung jumlah bintang yang muncul dengan bantuan variabel j
				j++;
			}
			b1[n]=j;						// menyalin data dari variabel j ke array b1
	        printf("%c",symbol);
	    }
	    printf ("\n\n------------------ Remember amaount of '*' for this scene -----------------\n\n ");	 
		sleep(5);
    	system("CLS");
	    
		if (n >= 3) {
	    	
			b2=n-2;
	    	
			printf ("===========================================================================\n");
			printf ("============================ BRAINS CHALLENGE =============================\n");
			printf ("===========================================================================\n\n");
		    
		    printf ("How many '*' for scene %d : ", b2);
		    scanf ("%d",&a);
		    if (a==b1[b2]) {						// membuat perbandingan jawaban dengan jumlah bintang yang telah dihitung
		    	printf ("  TRUE!\n");
		    	InsertVFirst(&Lskor, 1);				// jawaban akan diberi nilai 1 dan dimasukan ke dalam list
				printf ("\n");
		    	printf ("\nNext ->");
		    	getch();
		    	system("CLS");
		    	
			} else {
				printf ("  FALSE!\n");
				test = false;
			}    
		    
		}
		   
		n++;
	
	} while (test == true);							// melakukan perulangan terus jika jawaban benar
	
	
	// menampilkan jumlah scene yang berhasil dijawab 
	
	printf ("\n------------------------------ GAME ENDS ----------------------------------\n\n");
    printf ("\nYou Can Answer : %d Scene", JumlahSkor(Lskor));
	printf ("\n\n");
    getch(); 

	} else if (pilihanmenu==2) {
		
		system ("CLS");
		
		printf ("\n------------------------ GAME INSTRUCTIONS ----------------------------\n\n\n");
  		printf("1. The player is asked to remember the number of '*'\n   that appear in a scene\n\n");
  		printf("2. At the beginning of the game will be given 3 scenes\n   each containing 15 symbols\n\n");
  		printf("3. Each Scene will be given 5 seconds to calculate\n   the number of '*' that appears\n\n" );
  		printf("4. After starting with 3 scenes, the next player is asked\n   the number of symbol '*' that appears in the first scene\n\n" );
  		printf("5. If the answer is correct, it will show the next scene, \n   and given the number of symbol '*' in the second,\n   and subsequent scenes, if it is wrong then the game ends\n\n");
		printf("\n\n Press Any Key To Back To Menu"); 
		
		getch();
		system("CLS");
		goto Menu;
		
	} else {
		system("CLS");
		goto Menu;
	}

	return 0;
}
