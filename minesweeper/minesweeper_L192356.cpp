#include<iostream>
#include<Windows.h>
#include<cstring>
#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include<fstream>
using namespace std;
                   //login functions
bool accountchecker(char a[] , char b[])            //This is a genral function made in order to compare two arrays in login function
{
    bool equal = false;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == b[i])
        {

            if (a[i + 1] == '\0' && b[i + 1] == '\0')
            {
                return true;
            }
        }
        else
        {
            equal = false;
            break;
        }
    }
    return false;
}
void registered(char F_NAME[100],char CNIC[20],char L_NAME[100],int age,char gender) //This function is used to write the data of each user in a registered file
{
		ofstream datafile;
	datafile.open("registered.txt", ios::app);
	if(!datafile.is_open())
	{
		cout<<"Something went bad while opening file";
	}
	else
	{
	datafile<<F_NAME<<setw(20)<<L_NAME<<setw(20)<<CNIC<<setw(20)<<age<<setw(20)<<gender<<endl;
    }
    if(!datafile)
    {
    	cout<<"Some bad happens while writing into file"<<endl;
	}
   
	datafile.close();
}
void analysis_write(int age)   //this function saves and writes of ages of users in order to do analysis with respect to their ages
{
	ofstream analysis_write;
	analysis_write.open("analysis.txt", ios::app);
	if (!analysis_write.is_open())
	{
		cout << "Something went bad while opening file";
	}
	else
	{
		analysis_write<<endl << age;
	}
	if (!analysis_write)
	{
		cout << "Some bad happens while writing into file" << endl;
	}

	analysis_write.close();
}
void analysis_read()//THIS FUNCTION BASICALLY READ NUMBER OF PERCENTAGES,NO OF USERS(WITH RESPECT TO AGE ) ,AND TOTAL USERS THAT PLAY GAME
{
	int child_no = 0;
	int young_no = 0;
	int old_no = 0;
	int age;
	char gender;
	ifstream analysis_read;
	analysis_read.open("analysis.txt");
	if (analysis_read.is_open())
	{
		while (!analysis_read.eof())
		{
			analysis_read >> age;
			//cout<<endl << age << endl;
			if (age < 18)
			{
				child_no++;
			}
			else if (age >= 18 && age <= 60)
			{
				young_no++;
			}
			else if (age > 60)
			{
				old_no++;
			}
		}
	}
	else
	{
		cout << "Something bad happens while opening file" << endl;;
	}
	int total = child_no + young_no + old_no;
	double child_ratio = static_cast<double>((child_no * 100) / total);
	double young_ratio = static_cast<double>((young_no * 100) / total);
	double old_ratio = static_cast<double>((old_no * 100) / total);
	cout << "                                     LATEST ANALYSIS                                     " << endl;
	cout << " NUMBER OF CHILDREN PLAYING THIS GAME ARE  EQUAL TO       " << child_no << endl;
	cout << "PERCENTAGE OF CHILDREN PLAYING THIS GAME IS EQUAL TO      " << child_ratio << endl;
	cout << " NUMBER OF youngsters PLAYING THIS GAME ARE  EQUAL TO     " << young_no << endl;
	cout << "PERCENTAGE OF YOUNG PEOPLE PLAYING THIS GAME IS EQUAL TO  " << young_ratio << endl;
	cout << " NUMBER OF oLD PERSONS PLAYING THIS GAME ARE  EQUAL TO    " << old_no << endl;
	cout << "PERCENTAGE OF old PEOPLE PLAYING THIS GAME IS EQUAL TO    " << old_ratio << endl;
	cout << "WOW" << "THIS GAME HAS GROWING USER AND THEY TOTAL ARE       " << total << endl;


}

void login(char history[100])       //this function basically take user history_name and store user F_name in it and also for login function 
{
	int starter;
	cout << "ENTER 1 TO Creat new account."<<endl << "ENTER 2 IF YOU Already have account login."<<endl<<endl;
	do
	{
    
    cin >> starter; 
	if(starter==1 ||starter==2)         //it will take input untill above two chices are not entered
	{
		break;
	}
	else
	{
		cout<<"Invalid number  enter again"<<endl;
	}
	}while(starter!=1 || starter !=2);
    if (starter == 2)
    {
        cout << "Enter FIRST NAME " << endl;
        char F_NAME[100];
        char L_NAME[100];
        cin.ignore();
        cin.getline(F_NAME, 100);
        cout << "Enter LAST NAME" << endl;
        cin.getline(L_NAME,100);
        cout << "Enter CNIC" << endl;
        char CNIC[20];
        cin.getline(CNIC,100);
        char checkerarray[100];   //array to check f_name
        char checkerarray0[100]; //array to check last name
        char checkerarray1[20]; //array to check cnic
        bool found = false;
        while (found == false)
        {
            ifstream account;
			account.open("data.txt");
			if(account.is_open())
			{
				            while (!account.eof())
            {
                account.getline(checkerarray, 100);
                account.getline(checkerarray0,100);
                account.getline(checkerarray1, 100);
                if (accountchecker(F_NAME, checkerarray) && accountchecker(L_NAME, checkerarray0))
                {
                    if (accountchecker(CNIC, checkerarray1))
                    {
						strcpy_s(history,strlen(F_NAME)+1,F_NAME);
                        cout << "Login successfull PRESS ENTER FOR FURTHER PROCESSING"<<endl;
                        found = true;
                        break;
                    }
                }
            }
			}
			else
			{
				cout<<"SOME BAD HAPPENS WHILE READING FROM FILE"<<endl;
			}

            account.close();
            if (found == false)                 //again take input if cnic or name is incorrect
            {
                cout << "Invalid username or cnic , Enter again"<<endl;
                cout << "Enter FIRST NAME " << endl;
                cin.getline(F_NAME, 100);
                cout << "Enter LAST NAME" << endl;
                cin.getline(L_NAME,100);  
                cout << "Enter CNIC" << endl;
                cin.getline(CNIC, 20);               
            }
        }
        
    }
    if (starter == 1)
    {
        ofstream datafile("data.txt", ios::app);
        bool samename = true; //represents that username already exists
        cin.ignore();
        while (samename == true) 
        {
            cout << "Enter FIRST NAME" << endl;
            char F_NAME[100];
            char L_NAME[100];
            cin.getline(F_NAME, 100);
             cout << "Enter LAST NAME" << endl;
             cin.getline(L_NAME, 100);
             cout << "Enter CNIC" << endl;
            char CNIC[20];
            cin.getline(CNIC, 20);
            char checkerarray[100];
            char checkerarray0[100];
            char checkerarray1[20];
            ifstream account;
			account.open("data.txt");
			if(account.is_open())
			{
				            while (!account.eof())
            {
                account.getline(checkerarray, 100);
                account.getline(checkerarray0, 100);
                account.getline(checkerarray1, 20);
                if (accountchecker(F_NAME, checkerarray) && accountchecker(L_NAME, checkerarray0))
                {
                    samename = true;
                    break;
                }
                else
				{
                    samename = false;
				}
            }
			}
			else
			{
				cout<<"some bad happens while reading into file"<<endl;
			}
            if (samename == false)
            {
                datafile <<F_NAME<< endl;
                datafile<<L_NAME<<endl;
                datafile << CNIC << endl;
                char gender;
                cout<<"ENTER your gender M OR F"<<endl;
                cin>>gender;
                int age;
                cout<<"ENTER YOUR AGE"<<endl;
                cin>>age;
                cout << "Account created"<<endl;
				strcpy_s(history,strlen(F_NAME)+1,F_NAME);
                registered(F_NAME,CNIC,L_NAME,age,gender);            //to store proper data of each user in registerd file
	            analysis_write(age); //to store age in order to do analysis with respect to age
            }
            else
            {
                cout << "Usename alredy Exist: Enter again" << endl;
            }
        }
    }
}
                           //history saave
void history(char historyfile[100],int level,int score,char game_status[100])        //to save history of any person level,score,win or loose
{
	char level1[100]="beginner";
	char level2[100]="semipro";
	char level3[100]="professional";
	ofstream history_write;
	history_write.open(historyfile, ios::app);
	if(!history_write.is_open())
	{
		cout<<"Something went bad while opening file";
	}
	else
	{
		if(level==1)
		history_write<<level1<<setw(20)<<score<<setw(20)<<game_status<<endl;
		if(level==2)
		history_write<<level2<<setw(20)<<score<<setw(20)<<game_status<<endl;
		if(level==3)
			history_write<<level3<<setw(20)<<score<<setw(20)<<game_status<<endl;
		
    }
    if(!history_write)
    {
    	cout<<"Some bad happens while writing into file"<<endl;
	}
   
	history_write.close();
}
                  //graphical functions
void gotoxy(int x, int y)
	//This function is used in going at any position by giving coordinate x ,y value
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}   
void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B,int FR, int FG, int FB)      //x1,x2 shows width and y1,y2 are use for hight in order to create ellipse and R,G,B AND FR,FG,FB are for internal and boundry colours values respectively
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush =  ::CreateSolidBrush(RGB(FR, FG, FB));  //Fill color is black
	SelectObject(device_context,brush);
	Ellipse(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
		

}
void myLine(int x1, int y1, int x2, int y2,int r,int g,int b) //use three 3 integers in r,g,b if you want colored lines. //also x1,y1 are itial points and x2,y2 are final points
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(r,g,b)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}
void myRect(int x1, int y1, int x2, int y2, int R, int G, int B) //x1 represents the left boundrey distance x2 right,y1 above and y2 down
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
    HPEN pen =CreatePen(PS_SOLID,2,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(192,192,192)); //Fill color is passed as parameter to the function!!!
	
	SelectObject(device_context,brush);
	
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
                     //Beginner level functions
void numberdrawer(char n,int x1,int x2,int y1,int y2) //this function is used to  draw numbers in beginner level
{
	if(n=='1')                                //draw 1
	{
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
	}
	if(n=='2')                              //draw 2
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);

	}
	if(n=='3')                        //draw3
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
	}
	if(n=='4')                        //draw 4
	{
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
	}
	if(n=='5')                        //draw 5
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
	}
	if(n=='6')                    //draw 6
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
	}
	if(n=='7')                  //draw 7
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);

	}
	if(n=='8')               //draw 8
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
	}
	if(n=='0')            //draw 0
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
	}
	if(n=='*')          //to make bomb
	{
		myEllipse(x1+10,y1+10,x2-10,y2-10,0,0,0,0,0,0);

	}
}
void initializing(char arr[10][10],char show[10][10])        //initializes one array with '0' chracter and other with '-' chracter in beginner level
{
for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i][j]='0';
		}
	}
for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			show[i][j]='-';
		}
     }
}
void bombplace(char arr[10][10])         //to put bombs in beginner level
{
	srand(time(0));
		int i;
		int j;
		int count=0;
		while(count<10)
		{
			i=rand()%10;            //rand to put random bombs
			j=rand()%10;
			arr[i][j]='*';
			count++;
		}
}
void assingningnumbers(char bomb[10][10])           //to assign number to blocks that surrond bombs
{
  		for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (bomb[i][j] != '*')
			{
				char count = '0';            //in order to count bombs
				if (i > 0 && i < 9 && j > 0 && j < 9)            //excluding boundrey lines
				{
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 0 && j == 0)   //top left corner
				{
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 0 && j != 0 && j != 9)         //top line
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
				 bomb[i][j] = count;
				}
				else if (i == 0 && j == 9)         //top right corner
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (j == 0 && i != 9 && i != 0)         // left side excluding corners
				{
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 9 && j == 0)                      //bottom left corner
				{
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 9 && j != 0 && j != 9)            //bottom line excluding corners
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 9 && j == 9) //bottom right corner
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (j == 9 && i != 9 && i != 0)      //right side excluding corners
				{
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
			}

		}
	}
}
void highlighterbox(int x1,int x2,int y1,int y2) //to make highligher to show that user can see his current position
{
	myLine(x1,y1,x2-30,y2,0,255,255);
	myLine(x1,y1,x2,y2-30,0,255,255);
	myLine(x1+30,y1,x2,y2,0,255,255);
	myLine(x1,y1+30,x2,y2,0,255,255);
}
void highlighterbox2(int x1,int x2,int y1,int y2) //in order to neutralize the foot blocks made by above highlighter box
{
	myLine(x1,y1,x2-30,y2,0,0,255);
	myLine(x1,y1,x2,y2-30,0,0,255);
	myLine(x1+30,y1,x2,y2,0,0,255);
	myLine(x1,y1+30,x2,y2,0,0,255);
}
void opengridonbomb(char arr[][10]) //if games looses it will open grid
{
	int x=100,y=100, x1=130,y1=130;
	for(int i=0;i<10;i++)
	{
		x=100,x1=130;
		for(int j=0;j<10;j++)
		{
			numberdrawer(arr[i][j],x,x1,y,y1);
			x=x+30;
			x1=x1+30;
		}
		y1=y1+30;
		y=y+30;
	}
}
int checkwinner(char show[][10],int bombs) //check no of bombs and if those cells that are open except bombs it will tell us that win 
{
	int count=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(show[i][j]=='-')
				count++;
		}
	}
		if(count==bombs)
			return 1;
		else 
			return 0;
}
void drawblocks()                                //this is basically used to print a graphical grid using rectangle graphics
{
		int x1=100,y1=100,x2=130,y2=130;
		for(int i=0;i<10;i++)
	{
		x1=100,x2=130;
		for(int j=0;j<10;j++)
		{
	myRect(x1,y1,x2,y2,0,0,255);

	x1=x1+30,
	x2=x2+30;
		}
		cout<<endl;
		y1=y1+30;
		y2=y2+30;
	}
}
void savebomb(char bomb[][10],char name[50])               //if user wants it will save the bomb array 
{
		
	ofstream bomb_write;
	int lenght = strlen(name);
	name[lenght] = 'b';                                    //bom is written after file name to store array having bombs
	name[lenght + 1] = 'o';
	name[lenght + 2] = 'm';
	name[lenght + 3] = '\0';
  bomb_write.open(name);
	if(bomb_write.is_open())
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				bomb_write<<bomb[i][j];
			}
		}


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	bomb_write.close();
}
void saveshow(char show[][10],char name[50])                 //this function will store show array
{
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'h';                  //after taking name write show at end in order to distinguish fro bom save grid
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'w';
	name[lenght + 4] = '\0';
	ofstream show_write;
    show_write.open(name);


	if(show_write.is_open())
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
					show_write<<show[i][j];
			}
		}


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	show_write.close();	
}
void savescore(int score,char name[50])                 //this will save the score of file if user wants to save game
{
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'c';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'r';
	name[lenght + 4] = '\0';
	ofstream score_write;
  score_write.open(name);


	if(score_write.is_open())
	{

			score_write<<score;


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	score_write.close();	
}
void loadbomb1(char bomb[][10],char name[50])                //this function will basically load the save bomb array
{
		ifstream bomb_read;
		int lenght = strlen(name);
	name[lenght] = 'b';                              ////this  is use to write for distuinguishing and open bomb array stored and read it
	name[lenght + 1] = 'o';
	name[lenght + 2] = 'm';
	name[lenght + 3] = '\0';
	bomb_read.open(name);


	if(bomb_read.is_open())
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
					bomb_read>>bomb[i][j];
			}
		}
	}

	bomb_read.close();

}
void loadshow(char show[][10],char name[50])                 //This function will basically load the show array
{
	ifstream show_read;
	int lenght = strlen(name);
	name[lenght] = 's';                                          //this  is use to write for distuinguishing and open show array stored and read it
	name[lenght + 1] = 'h';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'w';
	name[lenght + 4] = '\0';
	show_read.open(name);
	if(show_read.is_open())
	{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
					show_read>>show[i][j];
			}
		}
	}
	show_read.close();
}
int loadscore1(int score,char name[50])                      //this function will load the score from file and return the read score
{
	ifstream score_read;
	int score_l=0;
	int lenght = strlen(name);
	name[lenght] = 's';                                         //this  is use to write for distuinguishing and open score array stored and read it
	name[lenght + 1] = 'c';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'r';
	name[lenght + 4] = '\0';
	score_read.open(name);
	if(score_read.is_open())
	{
       score_read>>score_l;
	   score=score_l;
	}
	else
	{
		cout<<"something went wrong"<<endl;
	}
	score_read.close();
	return score_l;
}
                 //semi pro
void numberdrawer2(char n,int x1,int x2,int y1,int y2)           //in order to draw numbers in semi pro grid
{
	if(n=='1')                                                 //in order to draw1
	{
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
	}
	if(n=='2')                                                      //in order to draw 2
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);

	}
	if(n=='3')                              //in order to draw 3
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
	}
	if(n=='4')                          //in order to draw 4
	{
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
	}
	if(n=='5')                           //in order to draw 5
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
	}
	if(n=='6')            //in order to draw 6
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
	}
	if(n=='7')             //in order to draw 7
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);

	}
	if(n=='8')                //in order to draw 8
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
	}
	if(n=='0')                     //in order to draw 0
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
	}
	if(n=='*')              //in order to draw bomb
	{
		myEllipse(x1+10,y1+10,x2-10,y2-10,0,0,0,0,0,0);

	}
}
void initializing2(char arr[15][15],char show[15][15])               //this function basically initializes two char array
{
for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			arr[i][j]='0';
		}
	}
for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			show[i][j]='-';
		}
     }
}
void bombplace2(char arr[15][15])     //in order to place bombs in one grid
{
	srand(time(0));
		int i;
		int j;
		int count=0;
		while(count<15)
		{
			i=rand()%15;             // in order to  put random bombs in a array
			j=rand()%15;
			arr[i][j]='*';
			count++;
		}
}
void assingningnumbers2(char bomb[15][15])       //in order to assingn  numbers to block that have bombs arround them
{
  		for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (bomb[i][j] != '*')
			{
				char count = '0';
				if (i > 0 && i < 14 && j > 0 && j < 14)       //in order    to count bombs excluding boundrey lines
				{
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 0 && j == 0)               //top left corner
				{
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 0 && j != 0 && j != 14)         //top line excluding corners
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
				 bomb[i][j] = count;
				}
				else if (i == 0 && j == 14)       //top right corner
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (j == 0 && i != 14 && i != 0)       //left line excluding corners
				{
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 14 && j == 0)          //bottom left corner
				{
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 14 && j != 0 && j != 14)    //bottom line excluding corners
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 14 && j == 14)         //bottom right corner
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (j == 14 && i != 14 && i != 0)     //right side excluding corners
				{
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
			}

		}
	}
}
void highlighterbox12(int x1,int x2,int y1,int y2)   //in order to make a highlighter box
{
	myLine(x1,y1,x2-30,y2,0,255,255);
	myLine(x1,y1,x2,y2-30,0,255,255);
	myLine(x1+30,y1,x2,y2,0,255,255);
	myLine(x1,y1+30,x2,y2,0,255,255);
}
void highlighterbox22(int x1,int x2,int y1,int y2)  // in order to make a box that neutrializes the foot box made by highlighter box
{
	myLine(x1,y1,x2-30,y2,0,0,255);
	myLine(x1,y1,x2,y2-30,0,0,255);
	myLine(x1+30,y1,x2,y2,0,0,255);
	myLine(x1,y1+30,x2,y2,0,0,255);
}
void opengridonbomb2(char arr[][15]) //in order to open grid if a bomb is opened
{
	int x=100,y=100, x1=130,y1=130;
	for(int i=0;i<15;i++)
	{
		x=100,x1=130;
		for(int j=0;j<15;j++)
		{
			numberdrawer2(arr[i][j],x,x1,y,y1);
			x=x+30;
			x1=x1+30;
		}
		y1=y1+30;
		y=y+30;
	}
}
int checkwinner2(char show[][15],int bombs)    //in order to check that if all cells are open except bombs
{
	int count=0;
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			if(show[i][j]=='-')
				count++;
		}
	}
		if(count==bombs) //if cell that remained unopen are equal to bombs
			return 1;
		else 
			return 0;
}
void drawblocks2()              //in order to draw graphical grid in semi pro level
{
		int x1=100,y1=100,x2=130,y2=130;
		for(int i=0;i<15;i++)
	{
		x1=100,x2=130;
		for(int j=0;j<15;j++)
		{
	myRect(x1,y1,x2,y2,0,0,255);

	x1=x1+30,
	x2=x2+30;
		}
		cout<<endl;
		y1=y1+30;
		y2=y2+30;
	}
}
void savebomb2(char bomb[][15],char name[50]) //in order to save bombs in  char bomb array in a file
{
		
	ofstream bomb_write;
	int lenght = strlen(name);
	name[lenght] = 'b';                //it will write bom2 at end of file name for purpose of distiguishing only
	name[lenght + 1] = 'o';
	name[lenght + 2] = 'm';
	name[lenght + 3] = '2';
	name[lenght + 4] = '\0';
  bomb_write.open(name);
	if(bomb_write.is_open())
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<15;j++)
			{
				bomb_write<<bomb[i][j];
			}
		}


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	bomb_write.close();
}
void saveshow2(char show[][15],char name[50])           //in order to save a char array other then show array
{
	int lenght = strlen(name);
	name[lenght] = 's';                                 //this is write for distuinguishing from other store array
	name[lenght + 1] = 'h';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'w';
	name[lenght + 4] = '2';
	name[lenght + 5] = '\0';
	ofstream show_write;
    show_write.open(name);


	if(show_write.is_open())
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<15;j++)
			{
					show_write<<show[i][j];
			}
		}


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	show_write.close();	
}
void savescore2(int &score,char name[50])           //this will save score array
{
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'c';          //this is write for distungishing purpose only
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'r';
	name[lenght + 4]=  '2';
	name[lenght + 5] = '\0';
	ofstream score_write;
  score_write.open(name);
	if(score_write.is_open())
	{

					score_write<<score;
	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	score_write.close();	
}
void loadbomb2(char bomb[][15],char name[50])            //this is use to load arrray of bombs
{
		ifstream bomb_read;
		int lenght = strlen(name);
	name[lenght] = 'b';                            //this  is use to write for distuinguishing and open bomb array stored and read it
	name[lenght + 1] = 'o';
	name[lenght + 2] = 'm';
	name[lenght + 3]= '2' ;
	name[lenght + 4] = '\0';
	bomb_read.open(name);


	if(bomb_read.is_open())
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<15;j++)
			{
					bomb_read>>bomb[i][j];
			}
		}
	}

	bomb_read.close();

}
void loadshow2(char show[][15],char name[50])            //this is used to load show array
{
	ifstream show_read;
	int lenght = strlen(name);
	name[lenght] = 's';                                                //this  is use to write for distuinguishing and open show array stored and read
	name[lenght + 1] = 'h';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'w';
	name[lenght + 4]=  '2';
	name[lenght + 5] = '\0';
	show_read.open(name);
	if(show_read.is_open())
	{
		for(int i=0;i<15;i++)
		{
			for(int j=0;j<15;j++)
			{
					show_read>>show[i][j];
			}
		}
	}
	show_read.close();
}
int loadscore2(int score,char name[50])
{
	ifstream score_read;
	int score_l=0;
	int lenght = strlen(name);
	name[lenght] = 's';                                                 //this  is use to write for distuinguishing and open score array stored and read
	name[lenght + 1] = 'c';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'r';
	name[lenght + 4]=  '2';
	name[lenght + 5] = '\0';
	score_read.open(name);
	if(score_read.is_open())
	{
       score_read>>score_l;
	   score=score_l;
	}
	else
	{
		cout<<"something went wrong"<<endl;
	}
	score_read.close();
	return score_l;
}
             //Professional level
void numberdrawer3(char n,int x1,int x2,int y1,int y2)              //this is used to draw numbers in professional level
{
	if(n=='1')                                                //this is used to draw 1
	{
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
	}
	if(n=='2')                                                 //this is used to draw 2
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);

	}
	if(n=='3')                                             //this is used to draw 3
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
	}
	if(n=='4')                                      //this is used to draw 4
	{
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
	}
	if(n=='5')                                 //this is used to draw 5
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
	}
	if(n=='6')                              //this is used to draw 6
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
	}
	if(n=='7')                         //this is used to draw 7
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-10,0,0,255);

	}
	if(n=='8')                       //this is used to draw 8
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+10,y1+15,x2-10,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
	}
	if(n=='0')                   //this is used to draw 0
	{
		myLine(x1+10,y1+10,x2-10,y2-20,0,0,255);
		myLine(x1+10,y1+10,x2-20,y2-15,0,0,255);
		myLine(x1+20,y1+15,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+20,x2-10,y2-10,0,0,255);
		myLine(x1+10,y1+15,x2-20,y2-10,0,0,255);
		myLine(x1+20,y1+10,x2-10,y2-15,0,0,255);
	}
	if(n=='*')                //this is used to draw bombs
	{
		myEllipse(x1+10,y1+10,x2-10,y2-10,0,0,0,0,0,0);

	}
}
void initializing3(char arr[20][20],char show[20][20])               //initializes one array with '0' chracter and other with '-' chracter in professional level
{
for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			arr[i][j]='0';
		}
	}
for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			show[i][j]='-';
		}
     }
}
void bombplace3(char arr[20][20])                     //this is used to place random bombs
{
	srand(time(0));
		int i;
		int j;
		int count=0;
		while(count<20)
		{
			i=rand()%20;
			j=rand()%20;
			arr[i][j]='*';
			count++;
		}
}
void assingningnumbers3(char bomb[20][20])    //this is used to assingn numbers to blocks that surrond bombs in professional and semi professional level
{
  		for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (bomb[i][j] != '*')
			{
				char count = '0';
				if (i > 0 && i < 19 && j > 0 && j < 19)
				{
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 0 && j == 0)
				{
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 0 && j != 0 && j != 19)
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
				 bomb[i][j] = count;
				}
				else if (i == 0 && j == 19)
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (j == 0 && i != 19 && i != 0)
				{
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i + 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 19 && j == 0)
				{
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 19 && j != 0 && j != 19)
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i][j + 1] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j + 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (i == 19 && j == 19)
				{
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
				else if (j == 19 && i != 19 && i != 0)
				{
					if (bomb[i - 1][j] == '*')
						count++;
					if (bomb[i + 1][j] == '*')
						count++;
					if (bomb[i][j - 1] == '*')
						count++;
					if (bomb[i - 1][j - 1] == '*')
						count++;
					if (bomb[i + 1][j - 1] == '*')
						count++;
					bomb[i][j] = count;
				}
			}

		}
	}
}
void highlighterbox13(int x1,int x2,int y1,int y2) //this is used to make highlighter box in professional level
{
	myLine(x1,y1,x2-30,y2,0,255,255);
	myLine(x1,y1,x2,y2-30,0,255,255);
	myLine(x1+30,y1,x2,y2,0,255,255);
	myLine(x1,y1+30,x2,y2,0,255,255);
}
void highlighterbox23(int x1,int x2,int y1,int y2)        //this is used to neutralize the footbox created by highlighter box
{
	myLine(x1,y1,x2-30,y2,0,0,255);
	myLine(x1,y1,x2,y2-30,0,0,255);
	myLine(x1+30,y1,x2,y2,0,0,255);
	myLine(x1,y1+30,x2,y2,0,0,255);
}
void opengridonbomb3(char arr[][20])     //this is used to open grid if a bomb is open
{
	int x=100,y=100, x1=130,y1=130;
	for(int i=0;i<20;i++)
	{
		x=100,x1=130;
		for(int j=0;j<20;j++)
		{
			numberdrawer3(arr[i][j],x,x1,y,y1);
			x=x+30;
			x1=x1+30;
		}
		y1=y1+30;
		y=y+30;
	}
}
int checkwinner3(char show[][20],int bomb) //to check if all cells are opened except bombs
{
	int count=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(show[i][j]=='-')
				count++;
		}
	}
		if(count==bomb)
			return 1;
		else 
			return 0;
}
void drawblocks3()                       //to draw blocks in professional level
{
		int x1=100,y1=100,x2=130,y2=130;
		for(int i=0;i<20;i++)
	{
		x1=100,x2=130;
		for(int j=0;j<20;j++)
		{
	myRect(x1,y1,x2,y2,0,0,255);

	x1=x1+30,
	x2=x2+30;
		}
		cout<<endl;
		y1=y1+30;
		y2=y2+30;
	}
}
void savebomb3(char bomb[][20],char name[50]) //this is used to save bomb array
{	
	ofstream bomb_write;
	int lenght = strlen(name);
	name[lenght] = 'b';
	name[lenght + 1] = 'o';
	name[lenght + 2] = 'm';
	name[lenght + 3] = '3';
	name[lenght + 4] = '\0';
  bomb_write.open(name);
	if(bomb_write.is_open())
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
				bomb_write<<bomb[i][j];
			}
		}


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	bomb_write.close();
}
void saveshow3(char show[][20],char name[50]) //this is used to store show array
{
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'h';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'w';
	name[lenght + 4] = '3';
	name[lenght + 5] = '\0';
	ofstream show_write;
    show_write.open(name);
	if(show_write.is_open())
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
					show_write<<show[i][j];
			}
		}


	}
	else
	{
		cout<<"some bad happens"<<endl;
	}
	show_write.close();	
}
void savescore3(int score,char name[50])      //this is used to store score array
{
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'c';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'r';
	name[lenght + 4]=  '3';
	name[lenght + 5] = '\0';
	ofstream score_write;
  score_write.open(name);


	if(score_write.is_open())
	{

					score_write<<score;
	}

	else
	{
		cout<<"some bad happens"<<endl;
	}
	score_write.close();	
}
void loadbomb3(char bomb[][20],char name[50]) //this is is used to load bomb array
{
		ifstream bomb_read;
		int lenght = strlen(name);
	name[lenght] = 'b';
	name[lenght + 1] = 'o';
	name[lenght + 2] = 'm';
	name[lenght + 3]= '3' ;
	name[lenght + 4] = '\0';
	bomb_read.open(name);


	if(bomb_read.is_open())
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
					bomb_read>>bomb[i][j];
			}
		}
	}

	bomb_read.close();

}
void loadshow3(char show[][20],char name[50])     //this is used to load show array
{
	ifstream show_read;
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'h';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'w';
	name[lenght + 4]=  '3';
	name[lenght + 5] = '\0';
	show_read.open(name);
	if(show_read.is_open())
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<20;j++)
			{
					show_read>>show[i][j];
			}
		}
	}
	show_read.close();
}
int loadscore3(int score,char name[50])     //this is used to load score array
{
	ifstream score_read;
	int score_l=0;
	int lenght = strlen(name);
	name[lenght] = 's';
	name[lenght + 1] = 'c';
	name[lenght + 2] = 'o';
	name[lenght + 3] = 'r';
	name[lenght + 4]=  '3';
	name[lenght + 5] = '\0';
	score_read.open(name);
	if(score_read.is_open())
	{
       score_read>>score_l;
	   score=score_l;
	}
	else
	{
		cout<<"something went wrong"<<endl;
	}
	score_read.close();
	return score_l;
}
int main()
{ 
	cout<<"WElocome to MINESWEEPER"<<endl;
	char history_file[100]; //this is used to store persons history and it is its history file is its first name
	login(history_file);
	cin.ignore();
	analysis_read();
	cout<<"Remember your history is saved in your first name file"<<endl;
	cout<<"Use arrow keys for moving up down left and right and o to open cell and e to exit(program ask you to reconfirm if n is enter it exit) and s to save game and other choices are given below"<<endl;
	char again_play;
	int level;
		do
	{
	do
	{
		cout<<"PRESS 1 FOR Beginner level"<<endl;
	    cout<<"PRESS 2 FOR SEMI PRO Level"<<endl;
		cout<<"PRESS 3 for professional level"<<endl;
	cin>>level;
	if(level==1 || level==2 || level==3)
	{
		break;
	}
	if(level!=1 || level!=2 || level!=3)
	{
		cout<<"invalid number"<<"   ENTER AGAIN"<<endl;
	}
	}
	while(level!= 1 || level!= 2 ||level!=3);
	system("CLS");
	gotoxy(0,0); 
	cout<<"SWITCH To FULL SCREEN FOR BETTER EXPERIANCE"<<endl;
	int gametype;

	if(level==1)
	{
	int score=0;
	char show[10][10];
	char bomb[10][10];
	int x1=100,y1=100,x2=130,y2=130;         //set position for highlighter also and where to start making grid
	do
	{
		cout<<"PRESS 1 FOR NEW GAME"<<endl;
	    cout<<"PRESS 2 FOR LOAD GAME"<<endl;
	cin>>gametype;
	if(gametype==1 || gametype==2)
	{
		break;
	}
	if(gametype!=1 || gametype!=2)
	{
		cout<<"invalid number"<<"   ENTER AGAIN"<<endl;
	}
	}
	while(gametype!= 1 || gametype!= 2);
	system("CLS");
	if(gametype==1)
	{
	initializing(bomb,show);
	bombplace(bomb);
	assingningnumbers(bomb);
	drawblocks();
	}
	else if(gametype==2)
	{
		char load[50];
       cout<<"Enter your game name"<<endl;
	   cin>>load;
	   char load1[50];
		char load2[50];
		cin.ignore();
		strcpy_s(load1,strlen(load)+1,load);
		strcpy_s(load2,strlen(load)+1,load);
		loadbomb1(bomb,load);
		loadshow(show,load1);
		score=loadscore1(score,load2);
		drawblocks();
		for(int i=0;i<10;i++)
		{
			x1=100,x2=130;
			for(int j=0;j<10;j++)
			{
		    if(show[i][j]=='l')            //'l' is here that cells already open and numbers are drawn in respective blocks
		    {
			numberdrawer(bomb[i][j],x1,x2,y1,y2);
		    }
			x1=x1+30,
	        x2=x2+30;
			}
			y1=y1+30;
		    y2=y2+30;
	}
	}
	int flag=0;        //to brek loop below first while loop
	int i=0;
	int j=0;
	 x1=100,y1=100,x2=130,y2=130; 
		while (flag == 0)
		{
			highlighterbox(x1,x2,y1,y2); //highlighter box
			char c = _getch(); //get char without pressing enter
			
	if (c == 'M')
			{
				if (x2 < 400)		//for right
				{
					x1 = x1 + 30;
					x2 = x2 + 30;
					highlighterbox2(x1-30,x2-30,y1,y2);
					j++;
				}
			}
			else	if (c == 'K')
			{
				if (x1 != 100)		//for left
				{
					x1 = x1 - 30;
					x2 = x2 - 30;
					highlighterbox2(x1+30,x2+30,y1,y2);
					j--;
				}
			}
			else if(c=='s')           //save game
			{
				char name[50];
				gotoxy(0,0);
				cout<<"Enter the name of file in which data to be saved"<<endl;
				cin>>name;
				char name1[50];
				char name2[50];
				strcpy_s(name1,strlen(name)+1,name);
				strcpy_s(name2,strlen(name)+1,name);
				savebomb(bomb,name);
				saveshow(show,name1);
				savescore(score,name2);
				flag=1;
			}
			else if (c == 'H')
			{
				if (y1 != 100)		//for up
				{
					y1 = y1 - 30;
					y2 = y2 - 30;
					highlighterbox2(x1,x2,y1+30,y2+30);
					i--;
				}
			}
			else if (c == 'P')
			{
				if (y2 < 400)		//for down
				{
					y1 = y1 + 30;
					y2 = y2 + 30;
					highlighterbox2(x1,x2,y1-30,y2-30);
					i++;
				}
			}
			else if(c=='e') //exit code but again asked if sure
			{
				gotoxy(0,0);
				cout<<"exit"<<endl;
				Sleep(0);
				flag=1;
			}
				else if(c=='o') //to open box
				{
					if(show[i][j]=='-')

					{
						if(bomb[i][j]!='*')
						{
						numberdrawer(bomb[i][j],x1,x2,y1,y2); //number draw if not a bomb 
						show[i][j]='l';
						score=score+5;
						}
						else if(bomb[i][j]=='*') //if bomb it will open it
						{
							opengridonbomb(bomb);
							show[i][j]=='l';
							gotoxy(0,0);
							cout<<"you loose score is"<<score;
							char game_status[100]="LOOSE";
							history(history_file,level,score,game_status);

							flag=1;
						}
					}
			}
					int l=0;
					l=checkwinner(show,10);
						if(l==1)
						{
							gotoxy(0,0);
							cout<<"you win and your score is"<<score;
							char game_status[100]="Win";
							history(history_file,level,score,game_status);
							flag=1;
						}
			}
		}
			if(level==2)
	{
	int score=0;
	char show[15][15];
	char bomb[15][15];
	int x1=100,y1=100,x2=130,y2=130;
	do
	{
		cout<<"PRESS 1 FOR NEW GAME"<<endl;
	    cout<<"PRESS 2 FOR LOAD GAME"<<endl;
	cin>>gametype;
	if(gametype==1 || gametype==2)
	{
		break;
	}
	if(gametype!=1 || gametype!=2)
	{
		cout<<"invalid number"<<"   ENTER AGAIN"<<endl;
	}
	}
	while(gametype!= 1 || gametype!= 2);
	system("CLS");
	if(gametype==1)
	{
	initializing2(bomb,show);
	bombplace2(bomb);
	assingningnumbers2(bomb);
	drawblocks2();
	}
	else if(gametype==2)
	{
		char load[50];
       cout<<"Enter your game name"<<endl;
	   cin>>load;
	   char load1[50];
		char load2[50];
		cin.ignore();
		strcpy_s(load1,strlen(load)+1,load);
		strcpy_s(load2,strlen(load)+1,load);
		loadbomb2(bomb,load);
		loadshow2(show,load1);
		score=loadscore2(score,load2);
		drawblocks2();
		for(int i=0;i<15;i++)
		{
			x1=100,x2=130;
			for(int j=0;j<15;j++)
			{
		    if(show[i][j]=='l') // l are blocks where cells are opened and  numbers are drawn in them
		    {
			numberdrawer2(bomb[i][j],x1,x2,y1,y2);
		    }
			x1=x1+30,
	        x2=x2+30;
			}
			y1=y1+30;
		    y2=y2+30;
	}
	}
	int flag=0;
	int i=0;
	int j=0;
	 x1=100,y1=100,x2=130,y2=130;
		while (flag == 0)
		{
			highlighterbox12(x1,x2,y1,y2);
			char c = _getch();
			
	if (c == 'M')
			{
				if (x2 < 550)		//for right
				{
					x1 = x1 + 30;
					x2 = x2 + 30;
					highlighterbox22(x1-30,x2-30,y1,y2);
					j++;
				}
			}
			else	if (c == 'K')
			{
				if (x1 != 100)		//for left
				{
					x1 = x1 - 30;
					x2 = x2 - 30;
					highlighterbox22(x1+30,x2+30,y1,y2);
					j--;
				}
			}
			else if(c=='s')           //to save game
			{
				char name[50];
				gotoxy(0,0);
				cout<<"Enter the name of file in which data to be saved"<<endl;
				cin>>name;
				char name1[100];
				char name2[100];
				strcpy_s(name1,strlen(name)+1,name);
				strcpy_s(name2,strlen(name)+1,name);
				savebomb2(bomb,name);
				saveshow2(show,name1);
				savescore2(score,name2);
				flag=1;
			}
			else if (c == 'H')
			{
				if (y1 != 100)		//for up
				{
					y1 = y1 - 30;
					y2 = y2 - 30;
					highlighterbox22(x1,x2,y1+30,y2+30);
					i--;
				}
			}
			else if (c == 'P')
			{
				if (y2 < 550)		//for down
				{
					y1 = y1 + 30;
					y2 = y2 + 30;
					highlighterbox22(x1,x2,y1-30,y2-30);
					i++;
				}
			}
			else if(c=='e') //to exit game
			{
				gotoxy(0,0);
				cout<<"exit"<<endl;
				again_play='n';
				break;
				//flag=1;
			}
				else if(c=='o') //o to open blocks
				{
					if(show[i][j]=='-')

					{
						if(bomb[i][j]!='*')
						{
						numberdrawer2(bomb[i][j],x1,x2,y1,y2);
						show[i][j]='l';
						score=score+5;
						}
						else if(bomb[i][j]=='*')
						{
							opengridonbomb2(bomb);
							show[i][j]=='l';
							gotoxy(0,0);
							cout<<"you loose score is "<<score;
							char game_status[100]="LOOSE";
							history(history_file,level,score,game_status);
							flag=1;
						}
					}
			}
					int l=0;
					l=checkwinner2(show,10);
						if(l==1)
						{
							gotoxy(0,0);
							cout<<"you win and your score is"<<score;
							char game_status[100]="Win";
							history(history_file,level,score,game_status);
							flag=1;
						}
			}
		}
		if(level==3)
	{
	int score=0;
	char show[20][20];
	char bomb[20][20];
	int x1=100,y1=100,x2=130,y2=130;
	do
	{
		cout<<"PRESS 1 FOR NEW GAME"<<endl;
	    cout<<"PRESS 2 FOR LOAD GAME"<<endl;
	cin>>gametype;
	if(gametype==1 || gametype==2)
	{
		break;
	}
	if(gametype!=1 || gametype!=2)
	{
		cout<<"invalid number"<<"   ENTER AGAIN"<<endl;
	}
	}
	while(gametype!= 1 || gametype!= 2);
	system("CLS");
	if(gametype==1)
	{
	initializing3(bomb,show);
	bombplace3(bomb);
	assingningnumbers3(bomb);
	drawblocks3();
	}
	else if(gametype==2)
	{
		char load[50];
       cout<<"Enter your game name"<<endl;
	   cin>>load;
	   char load1[50];
		char load2[50];
		cin.ignore();
		strcpy_s(load1,strlen(load)+1,load);
		strcpy_s(load2,strlen(load)+1,load);
		loadbomb3(bomb,load);
		loadshow3(show,load1);
		score=loadscore3(score,load2);
		drawblocks3();
		for(int i=0;i<20;i++)
		{
			x1=100,x2=130;
			for(int j=0;j<20;j++)
			{
		    if(show[i][j]=='l')  //l are blocks where cells are opened and  numbers are drawn in them
		    {
			numberdrawer3(bomb[i][j],x1,x2,y1,y2);
		    }
			x1=x1+30,
	        x2=x2+30;
			}
			y1=y1+30;
		    y2=y2+30;
	}
	}
	int flag=0;
	int i=0;
	int j=0;
	 x1=100,y1=100,x2=130,y2=130;
		while (flag == 0)
		{
			highlighterbox13(x1,x2,y1,y2);
			char c = _getch();
			
	if (c == 'M')
			{
				if (x2 < 700)		//for right
				{
					x1 = x1 + 30;
					x2 = x2 + 30;
					highlighterbox23(x1-30,x2-30,y1,y2);
					j++;
				}
			}
			else	if (c == 'K')
			{
				if (x1 != 100)		//for left
				{
					x1 = x1 - 30;
					x2 = x2 - 30;
					highlighterbox23(x1+30,x2+30,y1,y2);
					j--;
				}
			}
			else if(c=='s') //save game
			{
				char name[50];
				gotoxy(0,0);
				cout<<"Enter the name of file in which data to be saved"<<endl;
				cin>>name;
				char name1[100];
				char name2[100];
				strcpy_s(name1,strlen(name)+1,name);
				strcpy_s(name2,strlen(name)+1,name);
				savebomb3(bomb,name);
				saveshow3(show,name1);
				savescore3(score,name2);
				flag=1;
			}
			else if (c == 'H')
			{
				if (y1 != 100)		//for up
				{
					y1 = y1 - 30;
					y2 = y2 - 30;
					highlighterbox23(x1,x2,y1+30,y2+30);
					i--;
				}
			}
			else if (c == 'P')
			{
				if (y2 < 700)		//for down
				{
					y1 = y1 + 30;
					y2 = y2 + 30;
					highlighterbox23(x1,x2,y1-30,y2-30);
					i++;
				}
			}
			else if(c=='e') //e to exit game
			{
				gotoxy(0,0);
				cout<<"exit"<<endl;
				Sleep(0);
				flag=1;
			}
				else if(c=='o') //o to open cells
				{
					if(show[i][j]=='-')

					{
						if(bomb[i][j]!='*')
						{
						numberdrawer3(bomb[i][j],x1,x2,y1,y2);
						show[i][j]='l';
						score=score+5;
						}
						else if(bomb[i][j]=='*')
						{
							opengridonbomb3(bomb);
							show[i][j]=='l';
							gotoxy(0,0);
							cout<<"you loose score is "<<score;
							char game_status[100]="LOOSE";
							history(history_file,level,score,game_status);

							flag=1;
						}
					}
			}
					int l=0;
					l=checkwinner3(show,20);
						if(l==1)
						{
							gotoxy(0,0);
							cout<<"you win and your score is"<<score;
							char game_status[100]="Win";
							history(history_file,level,score,game_status);
							flag=1;
						}
			}
		}
			do
	{
		cout<<"PRESS y FOR playing GAME again"<<endl;
	    cout<<"PRESS n FOR not playing  agin GAME and if you really want to exit"<<endl;
	cin>>again_play;
	if(again_play=='n' || again_play=='y')
	{
		break;
	}
	if(again_play!='n' || again_play!='y' )
	{
		cout<<"invalid character"<<"   ENTER AGAIN"<<endl;
	}
	}
	while(again_play!= 'n'  || again_play!= 'y');
		}
		while(again_play!='n' && again_play=='y');
		system ("CLS");
	
if(again_play!='n')
{
	Sleep(300000000);
}
else
{
	Sleep(0);
}
return 0;
}
