#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct STACK{
	string matkul[100];
	int sks[100];
	char bobot[100];
	int total[100];
	int atas;
};
STACK tumpuk;

int main(){
	int pilStack,i,newSks,newTotal,pilMakul;
	char newBobot;
	string newMatkul;
	tumpuk.atas=-1;
	do{
		system("cls");
		cout<<"=================================="<<endl;
		cout<<"|  Program Input Data Mahasiswa  |"<<endl;
		cout<<"=================================="<<endl;
		cout<<"| 1. Matakuliah Baru             |"<<endl;
		cout<<"| 2. Data Matakuliah             |"<<endl;
		cout<<"| 3. Update Matakuliah           |"<<endl;
		cout<<"| 4. Hapus Matakuliah            |"<<endl;
		cout<<"| 5. Keluar                      |"<<endl;
		cout<<"=================================="<<endl;
		cout<<"Masukan Pilihan : ";cin>>pilStack;
		switch(toupper(pilStack)){
			case 1 : system("cls");{
				if(tumpuk.atas==100-1){
					cout<<"Data Penuh";
					getch();
				}else{
					cout<<"Nama matakuliah \t: ";cin>>newMatkul;
					cout<<"SKS\t\t\t: ";cin>>newSks;
					cout<<"Bobot (A/B/C/D/E) : ";cin>>newBobot;
					switch(newBobot){
						case 'a': 
						case 'A': 
							newTotal = newSks*4;
							newBobot='A';
							break;
						case 'b': 
						case 'B': 
							newTotal = newSks*3;
							newBobot='B';
							break;
						case 'c': 
						case 'C': 
							newTotal = newSks*2;
							newBobot='C';
							break;
						case 'd': 
						case 'D': 
							newTotal = newSks*1;
							newBobot='D';
							break;
						case 'e': 
						case 'E': 
							newTotal = newSks*0;
							newBobot='E';
							break;
						default :
							break;
					}
					tumpuk.atas++;
					
					tumpuk.matkul[tumpuk.atas]=newMatkul;
					tumpuk.sks[tumpuk.atas]=newSks;
					tumpuk.bobot[tumpuk.atas]=newBobot;
					tumpuk.total[tumpuk.atas]=newTotal;
					cout<<"Matakuliah telah diMasukan....";
					getch();
				}
				break;
			}
			case 2 : system("cls");{
				if(tumpuk.atas==-1){
					cout<<"Tumpukan kosong!";
				}else{
					cout<<"Matakuliah yang diambil :\n\n";
					cout<<"==========================================================================\n";
					cout<<"| Matakuliah\t\t | \tSKS\t | Bobot\t | Total\t |\n";
					cout<<"==========================================================================\n";
					for(i=0;i<=tumpuk.atas;i++){
						cout<<"| "<<tumpuk.matkul[i]<<"\t\t | \t"<<tumpuk.sks[i]<<"\t | "<<tumpuk.bobot[i]<<"\t\t | \t"<<tumpuk.total[i]<<"\t |\n";
					}
					cout<<"==========================================================================\nTekan 'Enter' untuk kembali....";
				}
				getch();
				break;
			}
			case 3 :system("cls");{
				if(tumpuk.atas==-1){
					cout<<"Tumpukan kosong!";
					getch();
				}else{
					cout<<"Matakuliah yang diambil :\n\n";
					cout<<"==================================================================================\n";
					cout<<"| No.\t| Matakuliah\t\t | \tSKS\t | Bobot\t | Total\t |\n";
					cout<<"==================================================================================\n";
					for(i=0;i<=tumpuk.atas;i++){
						cout<<"| "<<(i+1)<<"\t| "<<tumpuk.matkul[i]<<"\t\t | \t"<<tumpuk.sks[i]<<"\t | "<<tumpuk.bobot[i]<<"\t\t | \t"<<tumpuk.total[i]<<"\t |\n";
					}
					cout<<"==================================================================================\n";
					cout<<"Masukan Nomor Matakuliah ('0' untuk kembali) : ";cin>>pilMakul;
					if(pilMakul==0){
						break;
					}else{
						system("cls");
						if(tumpuk.matkul[pilMakul-1]!=""){
							char save;
							cout<<"Nama matakuliah : "<<tumpuk.matkul[pilMakul-1]<<endl;
							cout<<"SKS : ";cin>>newSks;
							cout<<"Bobot (A/B/C/D/E) : ";cin>>newBobot;
							switch(newBobot){
								case 'a': 
								case 'A': 
									newTotal = newSks*4;
									newBobot='A';
									break;
								case 'b': 
								case 'B': 
									newTotal = newSks*3;
									newBobot='B';
									break;
								case 'c': 
								case 'C': 
									newTotal = newSks*2;
									newBobot='C';
									break;
								case 'd': 
								case 'D': 
									newTotal = newSks*1;
									newBobot='D';
									break;
								case 'e': 
								case 'E': 
									newTotal = newSks*0;
									newBobot='E';
									break;
								default :
									break;
							}
							cout<<"Simpan data baru ? (Y/n) : ";cin>>save;
							if(save=='Y'||save=='y'){
								system("cls");
								tumpuk.sks[pilMakul-1]=newSks;
								tumpuk.bobot[pilMakul-1]=newBobot;
								tumpuk.total[pilMakul-1]=newTotal;
								cout<<"Matakuliah telah diUpdate....";
								getch();	
							}else{
								break;
							}
						}else{
							cout<<"Data tidak ditemukan...";
							getch();
						}
					}
				}
				break;
			}
			case 4 : system("cls");{
				if(tumpuk.atas==-1){
					cout<<"Matakuliah kosong!";
					getch();
				}else{
					cout<<"Matakuliah yang dihapus = "<<tumpuk.matkul[tumpuk.atas];
					tumpuk.atas--;
					getch();
				}
				break;
			}
			case 5 :{
				return 0;
				break;
			}
			default : system("cls");{
				cout<<"Pilihan tidak ditemukan!";
				getch();
				break;
			}
		}
	}while(pilStack!=5);
}
