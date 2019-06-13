#include<fstream.h>	//For iostream and file stream
#include<conio.h>	//For clrscr() function
#include<stdio.h>	//For get(char) function
#include<stdlib.h>  	//For exit(int) function
#include<string.h>	//For strcat(char*,char*) function

ifstream input("INPUT.TXT",ios::in);
ofstream inpout("INPUT.TXT",ios::out|ios::trunc);
ifstream keyI("KEY.TXT",ios::in);
int capk[30],lowk[30],tmp=0,i=0,j=0;
char k[101],files[1001];

void KeyGen();
void KeytoArr();
void Encrypt();
void Decrypt();

void main()
{
	again:
	clrscr();
	char str[2001],inp[201],ch[100];

	// Main Menu

	cout<<"################################################################################";
	cout<<"\n\n\t\t\t\t CIPHER_DECIPHER";
	cout<<"\n\t\t\t\t ~~~~~~~~~~~~~~~";
	cout<<"\n\t\t\t\t\t\t       Made by : Chirag Tamhane";
	cout<<"\n________________________________________________________________________________";
	cout<<"\n\t Encrypt your .TXT files using our RandomCipher(TM) Technology \n\t    for top of the line security and share it worry free!";
	cout<<"\n________________________________________________________________________________";
	cout<<"\n\n\t\t\tThanks for purchasing this product.\n\n      Please do consider checking out the \"Help\" section before proceeding! ";
	cout<<"\n\n\n\t\t  Choose an option : ";
	cout<<"\n\t\t\t(1) Encrypt the file\n\t\t\t(2) Decrypt the file\n\t\t\t(3) Help\n\t\t\t(4) Exit\n\t\t\t\t ";
	gets(ch);
	if(ch[0]=='3')
	{
		//HELP Section
		clrscr();
		cout<<"################################################################################";
		cout<<"\n\n\t\t\t\t     HELP";
		cout<<"\n\t\t\t\t    ~~~~~~";
		cout<<"\n\n\n    We ensure that your data stays encrypted to all until it reaches the \n    destination. The software has two key components known as the Input File \n    and Key.\n    INPUT FILE -> The .txt file you want to encrypt.\n    KEY -> The Encryption Key.";
		cout<<"\n\n\t\t\t    PRESS ANY KEY TO CONTINUE";
		getch();
		cout<<"\n\n    During Encryption, follow these steps (if using import function) :\n    (1)After ensuring that the file to be encrypted is in the BIN folder, \n       enter the exact name of the .txt file.";
		cout<<"\n    (2)A Random Key would be generated and saved as KEY.txt in the BIN folder.\n    (3)Now, the encrypted file would be stored as ENCPT.txt in the BIN folder.";
		cout<<"\n    (4)Voila! Your file has been encrypted. Share the ENCPT file + KEY to the \n     destination user where it would be decrypted by their client software.";
		cout<<"\n    If you're using the text function, just enter the text you want to encrypt.";
		cout<<"\n\n\t\t\t    PRESS ANY KEY TO CONTINUE";
		getch();
		cout<<"\n\n    During Decryption, ensure that the ENCPT file and KEY both are present \n    unadulterated in the BIN folder. Just enter \"Y\" to begin decryption followed    by exporting to OUTPUT.TXT";
		cout<<"\n\n\t\t      PRESS ANY KEY TO RETURN TO MAIN MENU";
		getch();
		goto again;
	}
	else
	if(ch[0]=='4')
	{
		keyI.close();
		exit(1);
		// Exit the program
	}
	else
	if(ch[0]=='1')
	{
		//ENCRYPTION
		fln:
		clrscr();
		char opt[101];
		cout<<"################################################################################";
		cout<<"\n\n\t\t\t\t     ENCRYPTION";
		cout<<"\n\t\t\t\t     ~~~~~~~~~~";
		cout<<"\n\n\t(1)Import from .txt file or (2)Enter the text or (3)Main Menu (1/2/3)\n\t\t\t\t\t";
		gets(opt);
		if(opt[0]=='2')
		{
			// Text Method
			cout<<"\n Enter the Text : ";
			gets(str);
			inpout<<str;
			inpout.close();
		}
		else
		if(opt[0]=='1')
		{
			// File Import Method
			cout<<"\n\n\tEnter the EXACT name of the .txt file that has to be encrypted :\n\t";
			gets(files);
			char ch;
			ifstream f;
			f.open(files,ios::in);
			if(!f)
			{
				strcat(files,".txt");
				f.open(files,ios::in);
				if(!f)
				{
					cout<<"\n\t\t\tFILE NOT FOUND!!!\n\tTry renaming your file to something else, preferably shorter!";
					getch();
					goto fln;
				}
			}
			while(!f.eof())
			{
				f.get(ch);
				inpout<<ch;
			}
			f.close();
			inpout.close();
		}
		else
			goto again;
		KeyGen();
		KeytoArr();
		Encrypt();
		cout<<"\n\n   Your File has been Encrypted and stored in the BIN folder as ENCPT.TXT !";
		remove("input.txt");
	}
	else
	if(ch[0]=='2')
	{
		//DECRYPTION
		clrscr();
		char opt[101];
		cout<<"################################################################################";
		cout<<"\n\n\t\t\t\t     DECRYPTION";
		cout<<"\n\t\t\t\t     ~~~~~~~~~~";
		cout<<"\n\n\tDo you want to decrypt your file or not? (Y/N) - ";
		gets(opt);
		if(opt[0]!='Y'&&opt[0]!='y')
			goto again;
		KeytoArr();
		Decrypt();
		cout<<"\n\n   Your File has been Decrypted and stored in the BIN folder as OUTPUT.TXT !";
	}
	else
	{
		cout<<"\n\t\t\t  Wrong Choice! Choose again..";
		getch();
		goto again;
	}
	getch();
	goto again;
}


void KeyGen()	//RandomCipher(TM) -> Function to randomly generate a KEY
{
	ofstream keyO("KEY.TXT",ios::out|ios::trunc);
	int Crnd=0,srnd=0;
	randomize();
	Crnd=random(470)+500;
	srnd=random(350)+100;
	int Ckey[26],skey[26],flag=0,Crand=0,srand=0;
	{
		for(i=0;i<27;i++)
		{
			Crand=random(26)+Crnd;
			srand=random(26)+srnd;
			for(j=0;j<i;j++)		//Counter-Repitition Measures
			{
				if(Ckey[j]==Crand)
					flag=1;
				while(Ckey[j]==Crand)
				{
					Crand=random(26)+Crnd;
				}
				if(skey[j]==srand)
					flag=1;
				while(skey[j]==srand)
				{
					srand=random(26)+srnd;
				}
				if(flag==1)
					j=0;
				flag=0;
			}
			Ckey[i]=Crand;
			skey[i]=srand;
		}

		keyO<<Crnd<<"|";			//Key printed on to the file
		for(i=1;i<27;i++)
		{
			keyO<<Ckey[i]<<",";
		}
		keyO<<"\n"<<srnd<<"|";
		for(i=1;i<27;i++)
		{
			keyO<<skey[i]<<",";
		}
	}
	keyO.close();
}

void KeytoArr()	//Key to Array
{
	keyI.seekg(0,ios::beg);
	keyI.getline(k,5,'|');
	for(i=0;i<26;i++)
	{
		keyI.getline(k,5,',');
		tmp=(100*(k[0]-48))+(10*(k[1]-48))+(k[2]-48);
		capk[i]=tmp;
	}
	keyI.getline(k,100,'|');
	for(i=0;i<26;i++)
	{
		keyI.getline(k,5,',');
		tmp=(100*(k[0]-48))+(10*(k[1]-48))+(k[2]-48);
		lowk[i]=tmp;
	}
}

void Encrypt()	//Function to Encrypt the text using the KEY
{
	ofstream encpt("ENCPT.TXT",ios::out|ios::trunc);
	{							//Encrypt and put into txt
		char ch;
		while(!input.eof())
		{
			input.get(ch);
			if(ch>96&&ch<123)
			{
				i=ch;
				i-=97;
				encpt<<"&"<<lowk[i];
			}
			else
			if(ch>64&&ch<91)
			{
				i=ch;
				i-=65;
				encpt<<capk[i];
			}
			else
			if(ch>='0'&&ch<='9')
				encpt<<"`"<<ch;
			else
			if(ch=='&')
				encpt<<"and";
			else
			if(ch=='`')
				encpt<<"tilda";
			else
				encpt<<ch;
		}
	}
	input.close();
	encpt.close();
}

void Decrypt()	//Function to decrypt the text using the KEY
{
	ifstream dcrpt("ENCPT.TXT",ios::in);  		
	ofstream opt("OUTPUT.TXT",ios::out|ios::trunc);
	dcrpt.seekg(0,ios::beg);
	int tmp=0;
	char ch,t;
	while(!dcrpt.eof())	//Decrypt and put into txt
	{
		dcrpt.get(ch);
		if(ch=='&')
		{
			dcrpt.getline(k,4,'&');
			tmp=(100*(k[0]-48))+(10*(k[1]-48))+(k[2]-48);
			for(i=0;i<26;i++)
			{
				if(tmp==lowk[i])
				{
					t=i+97;
					opt<<t;
					break;
				}
			}
		}
		else
		if(ch=='`')
		{
			dcrpt.get(t);
			opt<<t;
		}
		else
		if(ch>='0'&&ch<='9')
		{
			dcrpt.seekg(-1,ios::cur);
			dcrpt.getline(k,4,'&');
			tmp=(100*(k[0]-48))+(10*(k[1]-48))+(k[2]-48);
			for(i=0;i<26;i++)
			{
				if(tmp==capk[i])
				{
					t=i+65;
					opt<<t;
				}
			}
		}
		else
		if(ch=='a')
		{
			i=0;
			while(i<2)
			{
				dcrpt.get(t);
				i++;
			}
			opt<<"&";
		}
		else
		if(ch=='t')
		{
			i=0;
			while(i<4)
			{
				dcrpt.get(t);
				i++;
			}
			opt<<"`";
		}
		else
		if(ch=='�')
			break;
		else
			opt<<ch;
	}
	dcrpt.close();
	opt.close();
}