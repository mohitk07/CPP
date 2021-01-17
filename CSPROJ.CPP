
#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
class voter_status
{
public:
int namecode;
int voting_status;
};

class candidate_status
{
public:
int namecode;
int numVotes;
};

class Candidate
{
	public:
	int tcode,namecode;
	char name[20];
	char age[20];
	char party[20];
	char symbol[20];
	char summary[50];
	char revenue[20];
	char area[10];
	void list_of_candidate_names();
	 voter_status* init_voter_status(int &);
	 candidate_status* init_candidate_status(int &);
	void candidate_sort();
	void modify_candidate_record(int);
	int name_candidate_found(int);
	void display_candidate_record(int);
	int  last_candidate_code(int &);
	int  candidate_recordno(int,Candidate &);
	void  delete_candidate_record(int);
	void getdata()
	{
{
Candidate cr;
int tcode, valid ;
char ch;
int num_candidates;
do
{
clrscr() ;
gotoxy(71,2) ;
cout <<"<0>=Exit" ;
gotoxy(27,3) ;
cout <<" ADD NAME TO THE CANDIDATE LIST" ;
gotoxy(26,4) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
gotoxy(5,6) ;
cout <<"Name Code : ";
gotoxy(5,8) ;
cout <<"Name : " ;
gotoxy(5,10) ;
cout <<"Party Name : " ;
gotoxy(5,12) ;
cout <<"Party Sign : " ;
do
{
valid = 1 ;
gotoxy(1,8) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER NAME TO ADD IN THE CANDIDATE LIST" ;
gotoxy(5,8) ;
cout <<"Name : " ;
gets(cr.name) ;
strupr(cr.name) ;
if (cr.name[0] == '0')
return ;
if ((strlen(cr.name) < 1) || (strlen(cr.name) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A.....Z" ;
getch() ;
}
}while (!valid) ;
do
{
valid = 1 ;
gotoxy(1,10) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,25) ;
cout <<"ENTER PARTY NAME TO ADD IN THE LIST" ;
gotoxy(5,10) ;
cout <<"Party Name : " ;
gets(cr.party) ;
strupr(cr.party);
if (cr.party[0] == '0')
return ;
if ((strlen(cr.party) < 1) || (strlen(cr.party) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A.....Z" ;
getch() ;
}
} while (!valid) ;
do
{
valid = 1 ;
gotoxy(1,12) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;

gotoxy(5,25) ;
cout <<"ENTER PARTY SIGN TO ADD IN THE MENU" ;
gotoxy(5,12) ;
cout <<"Party Sign : " ;
gets(cr.symbol) ;
strupr(cr.symbol);
if (cr.symbol[0] == '0')
return ;
if ((strlen(cr.symbol) < 1) ||(strlen(cr.symbol) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A.....Z" ;
getch() ;
}
} while (!valid) ;
do
{
valid = 1;
gotoxy(1,16) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;

gotoxy(5,25) ;
cout <<"ENTER REVENUE OF THE CANDIDATE" ;
gotoxy(5,16) ;
cout <<"Revenue : " ;
gets(cr.revenue) ;
strupr(cr.revenue);
if (cr.revenue[0] == '0')
return ;
if ((strlen(cr.revenue) < 1) ||(strlen(cr.revenue) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A.....Z" ;
getch() ;
}
} while (!valid) ;
do
{
valid = 1;
gotoxy(1,18) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;

gotoxy(5,25) ;
cout <<"ENTER AGE OF THE CANDIDATE" ;
gotoxy(5,18) ;
cout <<"Age : " ;
gets(cr.age) ;
strupr(cr.age);
if (cr.age[0] == '0')
return ;
if ((strlen(cr.age) < 1) ||(strlen(cr.age) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A.....Z" ;
getch() ;
}
} while (!valid) ;
do
{
valid = 1;
gotoxy(1,20) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;

gotoxy(5,25) ;
cout <<"ENTER AREA OF THE CANDIDATE" ;
gotoxy(5,20) ;
cout <<"Area : " ;
gets(cr.area) ;
strupr(cr.area);
if (cr.area[0] == '0')
return ;
if ((strlen(cr.area) < 1) ||(strlen(cr.area) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A.....Z" ;
getch() ;
}
} while (!valid) ;
do
{
gotoxy(1,15) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,28) ;
cout <<"Do you want to save this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'Y')
{
fstream file ;
file.open("CLASS1.DAT", ios::out | ios::app | ios::binary) ;
file.write((char *)&cr, sizeof(Candidate)) ;
file.close() ;
tcode++ ;
}
do
{
gotoxy(1,17) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,30) ;
cout <<"Do you want to add more records (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
} while (ch != 'N' && ch != 'Y') ;

} while (ch == 'Y') ;
}
}
void dispdata()
{
clrscr() ;

Candidate cr;
fstream file ;
file.open("CLASS1.DAT", ios::in|ios::binary) ;
file.seekg(0) ;
int row = 6 , found = 0 , pageno = 1 ;
gotoxy(30,2) ;
cout <<"LIST OF NAMES OF CANDIDATES" ;
gotoxy(29,3) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
gotoxy(3,4) ;
cout <<"NAME CODE NAME PARTY NAME PARTY SIGN REVENUE AGE AREA";
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
while (file.read((char *)&cr, sizeof(Candidate)))
{
delay(20) ;
found = 1 ;
gotoxy(5,row) ;
cout <<cr.tcode ;
gotoxy(14,row) ;
cout	<<cr.name ;
gotoxy(31,row) ;
cout	<<cr.party ;
gotoxy(45,row) ;
cout	<<cr.symbol ;
gotoxy(58,row) ;
cout <<cr.revenue ;
gotoxy(69,row) ;
cout <<cr.age ;
gotoxy(75,row) ;
cout <<cr.area ;
if ( row == 22 )
{
row = 5 ;
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
pageno++ ;
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getche() ;
clrscr() ;
gotoxy(3,4) ;
cout << "NAME CODE NAME PARTY NAME PARTY SIGN REVENUE AGE AREA" ;
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
}
else
row++ ;
}
if ( !found )
{
gotoxy(5,10) ;
cout <<"\7Records not found " ;
}
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
gotoxy(1,20) ;
cout <<"Press any key to continue..." ;
getche() ;
file.close () ;
}
void moddata()
{
clrscr() ;
char t_code[5], ch ;
int tcode ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to see the list" ;
gotoxy(5,3) ;
cout <<"Enter Name Code of the item to be Modify : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
{
list_of_candidate_names() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to Exit" ;
gotoxy(5,24) ;
cout <<"Enter Name Code of the item to be modify : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
return ;
}
clrscr() ;
if (!name_candidate_found(tcode))
{
gotoxy(5,5) ;
cout <<"\7Record not found" ;
getch() ;
return ;
}
display_candidate_record(tcode) ;
do
{
gotoxy(5,8) ;
cout <<"Do you want to Modify this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'N')
return ;
modify_candidate_record(tcode) ;
}
void deldata()
{
clrscr() ;
char t_code[5], ch ;
int tcode ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to see the list" ;
gotoxy(5,3) ;
cout <<"Enter Name Code of the item to be deleted : " ;
gets(t_code) ;
tcode = atoi(t_code) ;

if (tcode == 0)
{
list_of_candidate_names() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"Press 0 to EXIT" ;
gotoxy(5,24) ;
cout <<"Enter Name Code of the item to be deleted : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
return ;
}
clrscr() ;
if (!name_candidate_found(tcode))
{
gotoxy(5,5) ;
cout <<"\7Record not found" ;
getch() ;
return ;
}
display_candidate_record(tcode) ;
do
{
gotoxy(1,8) ; clreol() ;
gotoxy(5,8) ;
cout <<"Do you want to delete this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'N')
return ;
delete_candidate_record(tcode) ;
gotoxy(5,15) ;
cout <<"\7Record Deleted" ;
getch() ;
}
};


void Candidate :: candidate_sort(void)
{
int i=0,j ;
Candidate *arr, temp ;
fstream file ;
file.open("CLASS1.DAT", ios::in|ios::binary) ;

while (file.read((char *) &temp, sizeof(Candidate)))
i++ ;

file.clear();

arr = (Candidate*) new Candidate[i];

int size ;
size = i ;

file.seekg(0,ios::beg) ;

for( i = 0; i < size; i++)
file.read((char*)&arr[i],sizeof(Candidate));

file.close() ;

for (i=1; i<size; i++)
{
for (j=0; j<size-i; j++)
{
if (arr[j].namecode > arr[j+1].namecode)
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

file.open("CLASS1.DAT", ios::out|ios::binary) ;

for (i=0; i<size; i++)
file.write((char *) &arr[i], sizeof(Candidate));
delete[] arr;

file.close() ;
}
void Candidate :: modify_candidate_record(int tcode)
{
Candidate cr;
int recno ;
int revenue;
recno = candidate_recordno(tcode,cr) ;
int valid, t_code ;
char ch,t_namecode[5] ;
gotoxy(71,2) ;
cout <<"<0>=Exit" ;
gotoxy(5,12) ;
cout <<"Name Code : " ;
gotoxy(5,14) ;
cout <<" Name : " ;
gotoxy(5,16) ;
cout <<" Party Name : " ;
gotoxy(5,18) ;
cout <<"Party Sign: " ;
do
{
gotoxy(20,12) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,12) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER NAME CODE TO ADD IN THE MENU" ;
gotoxy(5,12) ;
cout <<"Name Code : " ;
gets(t_namecode) ;
cr.namecode = atoi(t_namecode) ;
if (cr.namecode == 0)
return ;
if (name_candidate_found(cr.namecode) && cr.namecode != tcode)
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 CODE ALREADY GIVEN" ;
getch() ;
}
}
do
{
gotoxy(20,14) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,14) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER NAME TO ADD IN THE MENU" ;
gotoxy(5,14) ;
cout <<" Name : " ;
gets(cr.name) ;
strupr(cr.name) ;
if (cr.name[0] == '0')
return ;
if ((strlen(cr.name) < 1) || (strlen(cr.name) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = 1..50" ;
getch() ;
}
}
do
{
gotoxy(20,16) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,16) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER PARTY NAME TO ADD IN THE MENU" ;
gotoxy(5,16) ;
cout <<"Party Name : " ;
gets(cr.party) ;
strupr(cr.party);
if (cr.party[0] == '0')
return ;
if ((strlen(cr.party) < 1) || (strlen(cr.party) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = 1..50" ;
getch() ;
}
}
do
{
gotoxy(20,18) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,18) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER PARTY SIGN TO ADD IN THE MENU" ;
gotoxy(5,18) ;
cout <<"Party Sign : " ;
gets(cr.symbol) ;
strupr(cr.symbol);


if (cr.symbol[0] == '0')
return ;
if ((strlen(cr.symbol) < 1) || (strlen(cr.symbol) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = " <<cr.symbol <<"..50" ;
getch() ;
}
}
do
{
gotoxy(20,20) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,20) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER THE SUMMARY OF THE CANDIDATE" ;
gotoxy(5,20) ;
cout <<"Summary declared: " ;
gets(cr.summary) ;
strupr(cr.summary);


if (cr.summary[0] == '0')
return ;
if ((strlen(cr.summary) < 1) || (strlen(cr.summary) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = " <<cr.summary <<"..50" ;
getch() ;
}
}
do
{
gotoxy(1,21) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,21) ;
cout <<"Do you want to save this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'N')
return ;
getch() ;
fstream file ;
file.open("CLASS1.DAT", ios::out | ios::ate|ios::binary) ;
int location ;
location = (recno-1) * sizeof(cr) ;
file.seekp(location) ;
file.write((char *) &cr, sizeof(Candidate)) ;
file.close() ;
candidate_sort() ;
clrscr() ;
gotoxy(5,15) ;
cout <<"\7Record Modified" ;
getch() ;
}
int Candidate :: name_candidate_found(int tcode)
{
Candidate cr;
fstream file ;
file.open("CLASS1.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
int found=0 ;
while (file.read((char *)&cr, sizeof(Candidate)))
{
if (cr.namecode == tcode)
{
found++ ;
break ;
}
}
file.close() ;
return found ;
}

void Candidate :: display_candidate_record(int tcode)
{
Candidate cr;
fstream file ;
file.open("CLASS.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
while (file.read((char *)&cr, sizeof(Candidate)))
{
if (cr.namecode == tcode)
{
gotoxy(5,3) ;
cout <<"Name Code : "<<cr.namecode ;
gotoxy(5,4) ;
cout <<"Name : "<<cr.name ;
gotoxy(5,5) ;
cout <<"Party Name : "<<cr.party ;
gotoxy(5,6) ;
cout <<"Party Sign : "<<cr.symbol ;
gotoxy(5,7) ;
cout <<"Revenue : "<<cr.revenue ;
gotoxy(5,8) ;
cout <<"Age : "<<cr.age ;
gotoxy(5,9) ;
cout <<"Area : "<<cr.area ;
break ;
}
}
file.close() ;
}


int Candidate :: last_candidate_code(int &num_candidates)
{
Candidate cr;
fstream file ;
num_candidates = 0;
file.open("CLASS1.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
int t=0 ;
while (file.read((char *) &cr, sizeof(Candidate)))
{
t = cr.namecode ;
num_candidates++;
}
file.close() ;
return t ;
}

int Candidate :: candidate_recordno(int tcode,Candidate &cr)
{
Candidate temp;
fstream file ;
file.open("CLASS.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
int found=0 ;
while (file.read((char *) &temp, sizeof(Candidate)))
{
found++ ;
if (temp.namecode == tcode)
{
cr = temp;
break ;
}
}
file.close() ;
return found ;
}



void Candidate :: delete_candidate_record(int tcode)
{
Candidate cr;
fstream file ;
file.open("CLASS1.DAT", ios::in|ios::binary) ;
fstream temp ;
temp.open("temp.dat", ios::out|ios::binary) ;
file.seekg(0,ios::beg) ;
while ( !file.eof() )
{
file.read((char *)&cr, sizeof(Candidate)) ;
if ( file.eof() )
break ;
if ( cr.namecode != tcode )
temp.write((char *)&cr, sizeof(Candidate)) ;
}
file.close() ;
temp.close() ;
file.open("CLASS1.DAT", ios::out|ios::binary) ;
temp.open("temp.dat", ios::in|ios::binary) ;
temp.seekg(0,ios::beg) ;
while ( !temp.eof() )
{
temp.read((char *)&cr, sizeof(Candidate)) ;
if ( temp.eof() )
break ;
file.write((char *) &cr, sizeof(Candidate)) ;
}
file.close() ;
temp.close() ;
}
void Candidate :: list_of_candidate_names(void)
{
clrscr() ;

Candidate cr;
fstream file ;
file.open("CLASS1.DAT", ios::in|ios::binary) ;
file.seekg(0) ;
int row = 6 , found = 0 , pageno = 1 ;
gotoxy(30,2) ;
cout <<"LIST OF NAMES OF CANDIDATES" ;
gotoxy(29,3) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
gotoxy(3,4) ;
cout <<"NAME CODE NAME PARTY NAME PARTY SIGN REVENUE AGE AREA";
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
while (file.read((char *)&cr, sizeof(Candidate)))
{
delay(20) ;
found = 1 ;
gotoxy(5,row) ;
cout <<cr.namecode ;
gotoxy(14,row) ;
cout	<<cr.name ;
gotoxy(31,row) ;
cout	<<cr.party ;
gotoxy(45,row) ;
cout	<<cr.symbol;
gotoxy(58,row) ;
cout <<cr.revenue ;
gotoxy(69,row) ;
cout <<cr.age ;
gotoxy(75,row) ;
cout <<cr.area ;
if ( row == 22 )
{
row = 5 ;
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
pageno++ ;
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getche() ;
clrscr() ;
gotoxy(3,4) ;
cout << "NAME CODE NAME PARTY NAME PARTY SIGN REVENUE AGE AREA" ;
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
}
else
row++ ;
}
if ( !found )
{
gotoxy(5,10) ;
cout <<"\7Records not found " ;
}
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
gotoxy(1,20) ;
cout <<"Press any key to continue..." ;
getche() ;
file.close () ;
}
class voter
{
	public:
	int vcode;
	int namecode;
	char name[20];
	char gender[10];
	char age[10];
	int last_voter_code(int&) ;
	void list_of_voters_names(void) ;
	void delete_voter_record(int) ;
	void modify_voter_record(int) ;
	void display_voter_record(int) ;
	int name_voter_found(int) ;
	voter_status* init_voter_status(int &);
	candidate_status* init_candidate_status(int &);
	void voting(void) ;
	int voter_recordno(int, voter&) ;
	void voter_sort(void) ;
int string_is_number(char* s)
{
int size = strlen(s);
for(int i = 0; i < size; i++)
if (!(s[i] >= '0' && s[i] <= '9'))
return 0;
return 1;
}
void dispv()
{
clrscr() ;
voter vr;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
file.seekg(0) ;
int row = 6 , found = 0 , pageno = 1 ;
gotoxy(30,2) ;
cout <<"LIST OF NAMES OF VOTERS" ;
gotoxy(29,3) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
gotoxy(3,4) ;
cout <<"NAME CODE NAME AGE GENDER" ;
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
while (file.read((char *)&vr, sizeof(voter)))
{
delay(20) ;
found = 1 ;
gotoxy(5,row) ;
cout <<vr.namecode ;
gotoxy(14,row) ;
cout	<<vr.name ;
gotoxy(37,row) ;
cout	<<vr.age;
gotoxy(51,row) ;
cout	<<vr.gender; ;
if ( row == 22 )
{
row = 5 ;
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
pageno++ ;
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getche() ;
clrscr() ;
gotoxy(3,4) ;
cout << "NAME CODE NAME AGE GENDER " ;
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
}
else
row++ ;
}
if ( !found )
{
gotoxy(5,10) ;
cout <<"\7Records not found " ;
}
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
gotoxy(1,20) ;
cout <<"Press any key to continue..." ;
getche() ;
file.close () ;
}

void getv()
{
voter vr;
int vcode, valid ;
char ch;
int num_voters;
vcode = last_voter_code(num_voters) ;
vcode++ ;
do
{
clrscr() ;
gotoxy(71,2) ;
cout <<"<0>=Exit" ;
gotoxy(23,3) ;
cout <<" ADD NAME TO THE VOTER LIST" ;
gotoxy(23,4) ;
cout <<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
gotoxy(5,6) ;
cout <<"Name Code : " <<vcode ;
gotoxy(5,8) ;
cout <<"Name: " ;
gotoxy(5,10) ;
cout <<"Age: " ;
gotoxy(5,12) ;
cout <<"Gender: " ;
do
{
valid = 1 ;
gotoxy(1,8) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER NAME OF THE VOTER TO ADD IN THE LIST" ;
gotoxy(5,8) ;
cout <<" Name : " ;
gets(vr.name) ;
strupr(vr.name) ;
if (vr.name[0] == '0')
return ;
if ((strlen(vr.name) < 1) || (strlen(vr.name) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = A...Z" ;
getch() ;
}
} while (!valid) ;
do
{
valid = 1 ;
gotoxy(1,10) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER AGE OF VOTER TO ADD IN THE LIST" ;
gotoxy(5,10) ;
cout <<"Age : " ;
gets(vr.age) ;
strupr(vr.age);
if (vr.age[0] == '0')
return ;
if ((strlen(vr.age) < 1) || (strlen(vr.age) > 3 ) || (!string_is_number(vr.age)))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = 18...100" ;
getch() ;
}
if (atoi(vr.age) < 18)
{
valid = 0;
gotoxy(3,24);
cout <<"\7 Voter's age is less than 18";
getch();
}

} while (!valid) ;
do
{
valid = 1 ;
gotoxy(1,12) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER GENDER OF VOTER TO ADD IN THE MENU" ;
gotoxy(5,12) ;
cout <<"GENDER : " ;
gets(vr.gender) ;
strupr(vr.gender);
if (vr.gender[0] == '0')
return ;
if ((strlen(vr.gender) < 1) ||(strlen(vr.gender) > 1)
|| (strcmp(vr.gender,"M") && strcmp(vr.gender,"F")))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = M/F" ;
getch() ;
}
} while (!valid) ;
do
{
gotoxy(1,15) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,15) ;
cout <<"Do you want to save this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'Y')
{
vr.namecode = vcode ;
fstream file ;
file.open("CLASS2.DAT", ios::out | ios::app |ios::binary) ;
file.write((char *)&vr, sizeof(voter)) ;
file.close() ;
vcode++ ;
}
do
{
gotoxy(1,17) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,17) ;
cout <<"Do you want to add more records (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
} while (ch == 'Y') ;
}

void delv()
{
clrscr() ;
char t_code[5], ch ;
int tcode ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to see the list" ;
gotoxy(5,3) ;
cout <<"Enter Name Code of the item to be deleted : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
{
list_of_voters_names() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to Exit" ;
gotoxy(5,24) ;
cout <<"Enter Name Code of the item to be deleted : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
return ;
}
clrscr() ;
if (!name_voter_found(tcode))
{
gotoxy(5,5) ;
cout <<"\7Record not found" ;
getch() ;
return ;
}
display_voter_record(tcode) ;
do
{
gotoxy(1,8) ; clreol() ;
gotoxy(5,8) ;
cout <<"Do you want to delete this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'N')
return ;
delete_voter_record(tcode) ;
gotoxy(5,15) ;
cout <<"\7Record Deleted" ;
getch() ;
}

void modv()
{
clrscr() ;
char t_code[5], ch ;
int tcode ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to see the list" ;
gotoxy(5,3) ;
cout <<"Enter Name Code of the item to be Modify : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
{
list_of_voters_names() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"Press <ENTER> to Exit" ;
gotoxy(5,24) ;
cout <<"Enter Name Code of the item to be modify : " ;
gets(t_code) ;
tcode = atoi(t_code) ;
if (tcode == 0)
return ;
}
clrscr() ;
if (!name_voter_found(tcode))
{
gotoxy(5,5) ;
cout <<"\7Record not found" ;
getch() ;
return ;
}
display_voter_record(tcode) ;
do
{
gotoxy(5,8) ;
cout <<"Do you want to Modify this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'N')
return ;
modify_voter_record(tcode) ;
}
};
void voter :: voter_sort(void)
{
int i=0,j ;
voter *arr, temp ;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
}

int voter :: last_voter_code(int &num_voters)
{
voter vr;
fstream file ;
num_voters = 0;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
int t=0 ;
while (file.read((char *)&vr,sizeof(voter)))
{
t = vr.namecode ;
num_voters++;
}
file.close() ;
return t ;
}

void voter :: display_voter_record(int vcode)
{
voter vr;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
while (file.read((char *)&vr, sizeof(voter)))
{
if (vr.namecode == vcode)
{
gotoxy(5,3) ;
cout <<"Name Code : "<<vr.namecode ;
gotoxy(5,4) ;
cout <<"Name : "<<vr.name ;
gotoxy(5,5) ;
cout <<"Age : "<<vr.age ;
gotoxy(5,6) ;
cout <<"Gender : "<<vr.gender ;
break ;
}
}
file.close() ;
}
int voter :: name_voter_found(int tcode)
{
voter vr;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
int found=0 ;
while (file.read((char *)&vr, sizeof(voter)))
{
if (vr.vcode == tcode)
{
found++ ;
break ;
}
}
file.close() ;
return found ;
}

int voter :: voter_recordno(int tcode, voter &vr)
{
voter temp;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
file.seekg(0,ios::beg) ;
int found=0 ;
while (file.read((char *)&temp, sizeof(voter)))
{
found++ ;
if (temp.vcode == tcode)
{
vr = temp;
break ;
}
}
file.close() ;
return found ;
}

void voter :: delete_voter_record(int tcode)
{
voter vr;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
fstream temp ;
temp.open("temp.dat", ios::out|ios::binary) ;
file.seekg(0,ios::beg) ;
while ( !file.eof() )
{
file.read((char *)&vr, sizeof(voter)) ;
if ( file.eof() )
break ;
if ( vr.vcode != tcode )
temp.write((char *)&vr, sizeof(voter)) ;
}
file.close() ;
temp.close() ;
file.open("CLASS2.DAT", ios::out|ios::binary) ;
temp.open("temp.dat", ios::in|ios::binary) ;
temp.seekg(0,ios::beg) ;
while ( !temp.eof() )
{
temp.read((char *)&vr, sizeof(voter)) ;
if ( temp.eof() )
break ;
file.write((char *)&vr, sizeof(voter)) ;
}
file.close() ;
temp.close() ;
}

void voter :: modify_voter_record(int tcode)
{
voter vr;
int recno ;
recno = voter_recordno(tcode,vr) ;

if (recno == 0)
return;
int valid, t_code ;
char ch,t_namecode[5] ;
gotoxy(71,2) ;
cout <<"<0>=Exit" ;
gotoxy(5,12) ;
cout <<"Name Code : " ;
gotoxy(5,14) ;
cout <<" Name : " ;
gotoxy(5,16) ;
cout <<" Age : " ;
gotoxy(5,18) ;
cout <<"Gender: " ;
do
{
gotoxy(20,12) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,12) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER NAME CODE TO ADD IN THE MENU" ;
gotoxy(5,12) ;
cout <<"Name Code : " ;
gets(t_namecode) ;
vr.namecode = atoi(t_namecode) ;
if (vr.namecode == 0)
return ;
if (name_voter_found(vr.namecode) && vr.namecode != tcode)
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 CODE ALREADY GIVEN" ;
getch() ;
}
}
do
{
gotoxy(20,14) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,14) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER NAME TO ADD IN THE MENU" ;
gotoxy(5,14) ;
cout <<" Name : " ;
gets(vr.name) ;
strupr(vr.name) ;
if (vr.name[0] == '0')
return ;
if ((strlen(vr.name) < 1) || (strlen(vr.name) > 50))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = 1..50" ;
getch() ;
}
}
do
{
gotoxy(20,16) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,16) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER AGE OF VOTER TO ADD IN THE MENU" ;
gotoxy(5,16) ;
cout <<"Age : " ;
gets(vr.age) ;
strupr(vr.age);
if (vr.age[0] == '0')
return ;
if ((strlen(vr.age) < 1) || (strlen(vr.age) > 10) || !string_is_number(vr.age))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = 1..10" ;
getch() ;
}
}
do
{
gotoxy(20,18) ; clreol() ;
cout <<"Change (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
valid = 0 ;
while (ch == 'Y' && !valid)
{
valid = 1 ;
gotoxy(1,18) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(3,25) ;
cout <<"ENTER GENDER OF VOTER TO ADD IN THE MENU" ;
gotoxy(5,18) ;
cout <<"Gender : " ;
gets(vr.gender) ;
strupr(vr.gender);
if (vr.gender[0] == '0')
return ;
if ((strlen(vr.gender) < 1) || (strlen(vr.gender) > 10))
{
valid = 0 ;
gotoxy(3,24) ;
cout <<"\7 Range = " <<vr.gender <<"..10" ;
getch() ;
}
}
do
{
gotoxy(1,21) ; clreol() ;
gotoxy(1,24) ; clreol() ;
gotoxy(1,25) ; clreol() ;
gotoxy(5,21) ;
cout <<"Do you want to save this record (y/n) : " ;
ch = getche() ;
ch = toupper(ch) ;
if (ch == '0')
return ;
} while (ch != 'N' && ch != 'Y') ;
if (ch == 'N')
return ;

getch() ;
fstream file ;
file.open("CLASS2.DAT", ios::out | ios::ate|ios::binary) ;
int location ;
location = (recno-1) * sizeof(vr) ;
cout << " Location is " << location;
file.seekp(location) ;
file.write((char *) &vr, sizeof(voter)) ;
file.close() ;
voter_sort() ;
clrscr() ;
gotoxy(5,15) ;
cout <<"\7Record Modified" ;
getch() ;
}
void voter :: list_of_voters_names(void)
{
clrscr() ;
voter vr;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
file.seekg(0) ;
int row = 6 , found = 0 , pageno = 1 ;
gotoxy(30,2) ;
cout <<"LIST OF NAMES OF VOTERS" ;
gotoxy(29,3) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
gotoxy(3,4) ;
cout <<"NAME CODE NAME AGE GENDER" ;
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
while (file.read((char *)&vr, sizeof(voter)))
{
delay(20) ;
found = 1 ;
gotoxy(5,row) ;
cout <<vr.namecode ;
gotoxy(14,row) ;
cout	<<vr.name ;
gotoxy(37,row) ;
cout	<<vr.age;
gotoxy(51,row) ;
cout	<<vr.gender; ;
if ( row == 22 )
{
row = 5 ;
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
pageno++ ;
gotoxy(1,25) ;
cout <<"Press any key to continue..." ;
getche() ;
clrscr() ;
gotoxy(3,4) ;
cout << "NAME CODE NAME AGE GENDER " ;
gotoxy(2,5) ;
cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
}
else
row++ ;
}
if ( !found )
{
gotoxy(5,10) ;
cout <<"\7Records not found " ;
}
gotoxy(66,1) ;
cout <<"Page no. : " <<pageno ;
gotoxy(66,2) ;
cout <<"===============" ;
gotoxy(1,20) ;
cout <<"Press any key to continue..." ;
getche() ;
file.close () ;
}
voter_status* voter::init_voter_status(int &num)
{
voter_status *vs = NULL;
num = 0;
last_voter_code(num);
if (num != 0)
{
vs = new voter_status[num];
voter vr;
fstream file ;
file.open("CLASS2.DAT", ios::in|ios::binary) ;
for(int i = 0; i < num; i++)
{
file.read((char *)&vr, sizeof(voter));
vs[i].namecode = vr.namecode;
vs[i].voting_status = 0;
}
file.close();
}
return vs;
}
candidate_status* voter::init_candidate_status(int &num)
{
candidate_status *cs = NULL;;
num = 0;
Candidate cr;
cr.last_candidate_code(num);
if (num != 0)
{
cs = new candidate_status[num];
Candidate cr;
fstream file;
file.open("CLASS1.DAT",ios::in|ios::binary);
for(int i = 0; i < num; i++)
{
file.read((char *)&cr, sizeof(Candidate));
cs[i].namecode = cr.namecode;
cs[i].numVotes = 0;
}
file.close();
}
return cs;

}

void voter::voting()
{

clrscr() ;

char ch,name[50];
int n ,num_voters = 0, num_candidates = 0;
int vtr_rec;
voter_status* vs = init_voter_status(num_voters);
candidate_status* cs = init_candidate_status(num_candidates);
int valid=0;
if (num_voters == 0)
{
gotoxy(3,6);
cout << "There are NO VOTERS";
ch = getche();
delete[] vs;
delete[] cs;
return;
}
if (num_candidates == 0)
{
gotoxy(3,6);
cout << "There are NO CANDIDATES";
ch = getche();
delete[] vs;
delete[] cs;
return;
}

while(1)
{
clrscr();
gotoxy(30,2);
cout <<"VOTING HAS STARTED";
gotoxy(29,3);
cout <<"~~~~~~~~~~~~~~~~~~~~~~";

{
int i;
for(i = 0; i < num_voters; i++)
{
if (vs[i].voting_status == 0) break;
}
if (i == num_voters)
{
gotoxy(3,4);
cout<<"All VOTES have been casted";
getche();
break;
}

}

gotoxy(3,24) ;
clreol();
cout <<"To End the voting Enter <STOP>.\n";
gotoxy(3,25);
clreol();
cout <<"Once voting is stopped it cann't resume. You will have to start a fresh" ;

gotoxy(6,3);
clreol();
cout <<"Enter the voter code <To view listof voters press <ENTER>- ";
gets(name);
if (strcmp(name,"STOP") == 0)
{
gotoxy(6,5);
clreol();
cout <<"Do you want to STOP the voting and start counting votes (y/n) - ";
ch = getche();
ch = toupper(ch);
while(!(ch == 'Y' || ch == 'N'))
{
gotoxy(70,5);
clreol();
ch = getche();
ch = toupper(ch);
}
if (ch == 'N')
{
gotoxy(6,5);
clreol();
continue;
}
else break;
}

n = string_is_number(name);
gotoxy(6,5);
clreol();

if (n == 0)
{
cout << "Incorrect voter code, enter only digits, try again ";
getche();
continue;
}

n = atoi(name);
if (n == 0)
{
list_of_voters_names();
continue;
}


for(vtr_rec = 0; vtr_rec < num_voters; vtr_rec++)
{
if (vs[vtr_rec].namecode == n)
{
if (vs[vtr_rec].voting_status == 1)
{
cout << "Voter with voter code "<< n <<" has alread voted";
}
getche();
break;
}
}
if ( vtr_rec == num_voters)
{
cout << "Voter code "<< n << " not found in Voter list";
getche();
continue;
}
if (vs[vtr_rec].voting_status == 1)
{
cout << "Voter code "<<n<< " has already voted, can't vote again";
getche();
continue;
}

while(1)
{
clrscr();

gotoxy(3,24) ;
clreol();
cout<<"To cast invalid vote press <y>";

gotoxy(3,3);
cout <<"Voter with voter code " << vs[vtr_rec].namecode<<" is voting";
gotoxy(3,4);
cout<<"Enter the candidate code <To view list of candidate press <ENTER>-" ;

char can_code[50];
gets(can_code);

if (can_code[0] == 'Y' || can_code[0] == 'y')
{
vs[vtr_rec].voting_status = 1;
clrscr();
cout<<"Voter ";
gotoxy(3,7);
display_voter_record(vs[vtr_rec].namecode);
gotoxy(3,8);
cout <<"has casted a invalid vote";
getche();
break;
}


int can = string_is_number(can_code);

gotoxy(3,6);
if (can == 0)
{
cout << "Incorrect candidate code, enter only digits, try again ";
getche();
continue;
}

can = atoi(can_code);
if (can == 0)
{
Candidate cr;
cr.list_of_candidate_names();
getche();
continue;
}
int can_rec;
for(can_rec=0; can_rec<num_candidates; can_rec++)
{
if (cs[can_rec].namecode == can)
break;
}
if (can_rec == num_candidates)
{
cout <<"Candidate code "<<can<<" not found in Candidate List";
getche();
continue;
}
cs[can_rec].numVotes++;
vs[vtr_rec].voting_status = 1;
clrscr();
gotoxy(3,6);

voter vr;
voter_recordno(vs[vtr_rec].namecode, vr) ;

cout<<"Voter " << vr.name<< " has voted for Candidate ";

Candidate cr;
cr.candidate_recordno(cs[can_rec].namecode,cr);

cout << cr.name;

gotoxy(35,20);
cout<<"VOTE CASTED";
getche();
valid=1;
break;
}
}


if (valid)
{
clrscr();
gotoxy(20,9);
cout<<"VOTING RESULTS";
int tie =0;
int winner=0;
int max = 0;
int i;
for(i = 0; i < num_candidates; i++)
{
if (cs[i].numVotes > max)
{
max = cs[i].numVotes;
}
else if (cs[i].numVotes == max && max > 0)
tie = 1;
}

gotoxy(20,12);
if (tie) cout<<"Voting has resulted in tie, joint winners are";
else cout <<"WINNER is ";
gotoxy(20,13);
for(i = 0; i < num_candidates; i++)
{
if (cs[i].numVotes == max)
{

Candidate cr;
cr.candidate_recordno(cs[i].namecode,cr);
if (winner)
cout<<", ";
cout << "\n\n\t\t\t"<<cr.name<<endl;
gotoxy(25,25);
cout<<"THE SUMMARY FOLLOWS";
delay(500);
gotoxy(25,27);
delay(500);
cout << "PARTY NAME -->"<<cr.party<<endl;
gotoxy(25,29);
delay(500);
cout << "PARTY SIGN -->"<<cr.symbol<<endl;
gotoxy(25,31);
delay(500);
cout << "REVENUE -->"<<cr.revenue<<endl;
gotoxy(25,33);
delay(500);
cout << "AGE -->"<<cr.age<<endl;
gotoxy(25,35);
delay(500);
cout << "AREA -->"<<cr.area;
winner++;
}
}

}
ch = getche();
delete[] vs;
delete[] cs;
}


int main()
{
	Candidate c;
	voter v;
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t WELCOME TO NEXTGEN VOTING";
	getch();
	label4:
	clrscr();
	cout<<"\n\n\n\n\n\n\n\t\t\t\t TYPE OF USER";
	cout<<"\n\n\n\n\n\t\t\t    1.Administrator";
	cout<<"\n\t\t\t    2.Voter";
	getch();
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			char ch;
			int r=0;
			char pass[20];
			for(;;)
			{
				clrscr();
				gotoxy(16,10);
				cout<<"Enter the password  :";
				r=0;
				for(int i=0;;i++)
				{
					ch=getch();
					if(ch==13)
					{
						pass[r]='\0';
						break;
					}
					if(ch==8)
					{
						if(i>0)
						{
							cout<<ch<<" "<<ch;
							i-=2;r--;
						}
						else
							i--;
					}
					else
					{
						cout<<"#";
						pass[r]=ch;
						r++;
					}
				}
				if(strcmp("dps",pass)==0)
				{
					label1:
					clrscr();
					gotoxy(30,2);
					cout<<"  ADMINISTRATOR";
					cout<<"\n\n\n\n\tMENU\n\n";
					cout<<"\n 1.Candidate \n";
					cout<<"\n 2.Voter \n";
					cout<<"\n 0.EXIT";
					getch();
					int choice1;
					cin>>choice1;
					switch(choice1)
					{
						case 1:
						{
							label2:
							clrscr();
							gotoxy(30,2);
							cout<<"  ADMINISTRATOR - CANDIDATE";
							cout<<"\n\n\n\n\tMENU\n\n";
							cout<<"\n 1.Display Candidate list\n";
							cout<<"\n 2.Add Candidate \n";
							cout<<"\n 3.Delete Candidate\n";
							cout<<"\n 4.Modify Candidate Record";
							getch();
							int ans;
							cin>>ans;
							switch(ans)
							{
								case 1:
								{
									c.dispdata();
									goto label2;
									break;

								 }
								 case 2:
								 {
									c.getdata();
									goto label2;
									break;

								 }
								 case 3:
								 {
									c.deldata();
									goto label2;
									break;

								 }
								 case 4:
								 {
									c.moddata();
									goto label2;
									break;

								 }
								 case 0:
								 exit(1);
								 break;
							}
							goto label1;
							break;
						}
						case 2:
						{
							label3:
							clrscr();
							gotoxy(30,2);
							cout<<"  ADMINISTRATOR - VOTER";
							cout<<"\n\n\n\n\tMENU\n";
							cout<<"\n 1.See Voter list \n";
							cout<<"\n 2.Delete Voter\n";
							cout<<"\n 0.EXIT";
							getch();
							int ans;
							cin>>ans;
							switch(ans)
							{
								case 1:
								{
									v.dispv();
									goto label3;
									break;
								}
								case 2:
								{
									v.delv();
									goto label3;
									break;
								}
								case 0:
								{
								exit(0);
								}
							}
							break;
						}

					}
					goto label1;
					break;
				}
				else
				{
				cout<<"\n\n\t\t\a!! INVALID PASSWORD !!";
				delay(300);
				cout<<"\n\n\t\t--> TRY AGAIN";
				getch();
				}
			}
			break;
		}
		case 2:
		{
			label5:
			clrscr();
			gotoxy(30,2);
			cout<<"  VOTER";
			cout<<"\n\n\n\n\tMENU\n\n";
			cout<<"\n 1.New Voter\n";
			cout<<"\n 2.Registered Voter\n";
			cout<<"\n 3.Check your voting status\n";
			cout<<"\n 4.See Candidate list\n";
			cout<<"\n 5.CAST YOUR VOTE\n";
			cout<<"\n 6.EXIT";
			getch();
			int choice2;
			cin>>choice2;
			switch(choice2)
			{
				case 1:
				{
					clrscr();
					gotoxy(30,2);
					cout<<"  VOTER - NEW VOTER";
					cout<<"\n\n\n\n\tMENU\n\n";
					cout<<"\n 1.Register as a new voter\n";
					v.getv();
					getch();
					goto label5;
					break;
				  }
				  case 2:
				  {
					clrscr();
					gotoxy(30,2);
					cout<<"  VOTER - EXISTING VOTER";
					cout<<"\n\n\n\n\tMENU\n\n";
					cout<<"\n 1.Modify Your Record \n";						{
					v.modv();
					getch();
					goto label5;
					break;
				  }
				  case 3:
				  {
					clrscr();
					gotoxy(30,2);
					cout<<"  VOTER - CHECK STATUS";
					int t;
					v.init_voter_status(t);
					getch();
					goto label5;
					break;
				  }
				  case 4:
				  {
					clrscr();
					gotoxy(30,2);
					cout<<"  VOTER - CANDIDATE LIST";
					c.dispdata();
					getch();
					goto label5;
					break;
				  }
				  case 5:
				  {
					clrscr();
					gotoxy(30,2);
					cout<<"  VOTER - CAST YOUR VOTE";
					v.voting();
					getch();
					goto label5;
					break;
				   }
				   case 6:
				  {
				  }
			}
			goto label4;
			break;
		}
	}
}
}