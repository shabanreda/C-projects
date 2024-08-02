// dynamic array with files.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdio>
using namespace std;
 int n;
 int Find_n(string name)
 {
     int x = 0;
     string y;
     ifstream eFile(name);
     if (eFile.is_open())
     {

         do {
             ++x;
             getline(eFile, y, '\n');
             // cout << eFile.eof();
         } while (!eFile.eof());

         // cout << endl << x << endl;
     }
     else { cout << "unable to open the file "; }
     return x;
 }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int findN(string name)
{
    string x;
    ifstream reading(name);
    if (reading.is_open()) {
        getline(reading, x, ';');
        getline(reading, x, ';');
        reading.close();
    }
    else {
        cout << "unable to open file" << endl;
    }
   // cout << x << endl;   
    return stoi(x);
}
/////////////////////////////////////////////////////////////////////////
int size_string(string name) {
    int x = 0;
    for (int i = 0; i < 100; i++) {
        if (name[i] != '\0')
            x = i + 1;
        else { break; }
    }
    return x;
}
string take_name(string name,int n) {
    string  namep;
    int x = 1, y;
   // getline(cin, name);
    y = size_string(name);
    for (int i = 1; i < y; i++) {
        if (name[i] == ' ')
            x++;
    }
    if (x != n)
    {
        while ((x != n)) {
            cout << "wrong!......complete your name to the " << n << "th name \n";
            cout << name + " ";
            getline(cin, namep);
            name = name + " " + namep;
            y = size_string(name);
            x = 1;
            for (int i = 1; i < y; i++) {
                if (name[i] == ' ')
                    x++;
                if (x == n)break;
            }
        }
    }
    return name;
}
char sizing_char(char c) {
    switch (c) {
    case  'a': c = 'A'; break;
    case  'b': c = 'B'; break;
    case  'c': c = 'C'; break;
    case  'd': c = 'D'; break;
    case  'e': c = 'E'; break;
    case  'f': c = 'F'; break;
    case  'g': c = 'G'; break;
    case  'h': c = 'H'; break;
    case  'i': c = 'I'; break;
    case  'j': c = 'J'; break;
    case  'k': c = 'K'; break;
    case  'l': c = 'L'; break;
    case  'm': c = 'M'; break;
    case  'n': c = 'N'; break;
    case  'o': c = 'O'; break;
    case  'p': c = 'P'; break;
    case  'q': c = 'Q'; break;
    case  'r': c = 'R'; break;
    case  's': c = 'S'; break;
    case  't': c = 'T'; break;
    case  'u': c = 'U'; break;
    case  'y': c = 'Y'; break;
    case  'z': c = 'Z'; break;
    }
    return c;
}
string capital_char(string name) {
    name[0] = sizing_char(name[0]);
    int y;
    char x = 's';
    y = size_string(name);
    for (int i = 1; i < y; i++) {
        if (name[i] == ' ') {
            name[i + 1] = sizing_char(name[i + 1]);
        }
    }
    return name;
}
string take_cap_name(string name, int n) {
   // cout << "please enter your name to the " << n << "th name \n";
    name = take_name(name,n);
    name = capital_char(name);
    return name;
}
////////////////////////////////////////////////////////////////////////
bool is_ID_there(string** ddata, string x)
{
    string y;
    bool z = true;
    for (int i = 2; i < (n + 2); i++) {
        y = ddata[i][0].substr(1, ddata[i][0].length() - 1);
        if (x == y)
            z = false;
    }
    if (z == false) cout << "false\n\n\n";
    else cout << "true\n\n\n";
    return z;
}
/////////////////////////////////////////////////////////////////////////////////////   export methods   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fullFile(string** dyn, string name, int colm)
{
    ofstream File(name);
    if (File.is_open())
    {
        //cout << "file is created ";

        for (int i = 0; i < (n + 2); i++)
        {
            for (int c = 0; c < colm; c++)
            {
                File << dyn[i][c] << ";";
            }
            //  File<<endl;
        }
        File.close();
    }
    else { cout << "unable to open the file "; }
}
////////////////////////////////////////////////////////////////////////
void addToFile(string** dyn, string name, int colm)
{
    int row = n + 1;
    ofstream File(name, ios::app);
    if (File.is_open())
    {
        //cout << "file is created ";
        string x = "" + (dyn[row][0]);
        File << x;
        for (int c = 1; c < colm; c++)
        {
            File << dyn[row][c] << ";";
        }
        File.close();
    }
    else { cout << "unable to open the file "; }
}
////////////////////////////////////////////////////////////////////////
void enterDataTo(string** dataDy, string id, int c1)
{
    cout << " enter the following data\n\n";
    string x;
    cout << "  1-code  :  " << id << endl;
    dataDy[(n + 1)][0] = "\n" + id;
    cin.ignore();
    for (int i = 1; i < c1; i++) {
        cout << "  " << (i + 1) << "-" << dataDy[1][i] << "  :  ";
      getline(cin, dataDy[(n + 1)][i]);
    }
 // dataDy[(n + 1)][1]= take_cap_name(dataDy[(n + 1)][1],2);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fullArr(string** dyn, string name, int colm)
{
    ifstream reading(name);
    if (reading.is_open()) {
        for (int i = 0; i < (n + 2); i++) {
            for (int c = 0; c < colm; c++) {
                getline(reading, dyn[i][c], ';');
               /* cout << dyn[i][c] << "( " << i << ",,," << c << " )";          // to print all data from the array
                cout << "\t\t";*/
            }
           // cout << endl;
        }
        //cout << "\n\n\n";
        reading.close();
    }
    else
    {
        cout << "unable to open file" << endl;
    }
    dyn[0][1] = to_string(n);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printArr(string** dyn, int colm)
{
    for (int i = 0; i < (n + 2); i++) {
        for (int c = 0; c < colm; c++) {

            cout << dyn[i][c] << "( " << i << ",,," << c << " )";          // to print all data from the array
            cout << "\t\t";
        }
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////
/* void Create2dyArrN(string ** dyn, int row, int colm)
{
    dyn = new string* [row];
    for (int i = 0; i < row; i++)
        dyn[i] = new string[colm];
}*/
///////////////////////////////////////////////////////////////////////
void delete2d(string** dyn)
{
    int row = n + 2;
    for (int i = 0; i < row; i++)
        delete[] dyn[i];
    delete[] dyn;
}
///////////////////////////////////////////////////////////////////////
string** create2D( int colm)
{
    int row = n + 2;
    string** array2d = new string * [row];
    for (int i = 0; i < row; i++)
        array2d[i] = new string[colm];
    return array2d;
}
///////////////////////////////////////////////////////////////////////
void pdata(string** ddata, string x)
{
    string y;
    for (int i = 2; i < (n + 2); i++) {
        y = ddata[i][0].substr(1, ddata[i][0].length() - 1);
        if (x == y) {
            x = "5";
            cout << "     Id   :  " << y << endl;
            cout << "    Name  :  " << ddata[i][1] << endl;
            cout << "    Age   :  " << ddata[i][2] << endl;
            cout << "   Gender :  " << ddata[i][3] << endl << endl;
        }
    }
    if (x != "5")
    {
        cout << "the id is not found !" << endl << endl;
    }
}

////////////////////////////////////////////////////////////  function to print student grades  by entering the student id ....
void pgrade(string** dgrade, string x, int n)
{
    string y;
    for (int i = 2; i < (n + 2); i++) {
        y = dgrade[i][0].substr(1, dgrade[i][0].length() - 1);
        if (x == y) {
            x = "5";
            cout << "       Id        : " << y << endl;
            cout << "  maths grade    : " << dgrade[i][1] << endl;
            cout << "  Physics grade  : " << dgrade[i][2] << endl;
            cout << "  Drawing grade  : " << dgrade[i][3] << endl;
            cout << "  Computer grade : " << dgrade[i][4] << endl;
            cout << "  Chemistry grade: " << dgrade[i][5] << endl << endl;
        }
    }
    if (x != "5")
    {
        cout << "the id is not found !" << endl;
    }
}
//////////////////////////////////////////////////////////////
void pGBA(string** dGBA, string x, int n)
{
    if (x != "" && x != "0") {
        string y;
        for (int i = 0; i < (n + 2); i++) {
            y = dGBA[i][0].substr(1, dGBA[i][0].length() - 1);
            if (x == y) {
                x = "5";
                cout << "       Id        : " << y << endl;
                cout << "    maths     GBA grade : " << dGBA[i][1] << endl;
                cout << "    Physics   GBA grade : " << dGBA[i][2] << endl;
                cout << "    Drawing   GBA grad  : " << dGBA[i][3] << endl;
                cout << "    Computer  GBA grade : " << dGBA[i][4] << endl;
                cout << "    Chemistry GBA grade : " << dGBA[i][5] << endl << endl;
            }
        }
    }
    if (x != "5")
    {
        cout << "the id is not found !" << endl << endl;
    }
}
/////////////////////////////////////////////////////////////////////// function to normlize student grades by entering the student id ....
void normlize(string **norm,string x, int n,int colm)
{
    int row= n+2 ,i = 0;
    string y;
    for (i = 2; i < row; i++) {
        y = norm[i][0].substr(1, norm[i][0].length() - 1);
        if (x == y) {
            x = "5";
            cout << endl << i << endl;
            double sum = 0;
            for (int c = 1; c < colm; c++)
            {
                sum += stod(norm[i][c]);
            }
            double avg = sum / (colm-1);
            double diviation = 0;
            double standv = 0;
            for (int c = 1; c < colm; c++)
            {
                diviation += pow(stod(norm[i][c]) - avg, 2);
            }
            standv = sqrt(diviation / (colm-1));
            cout << " mean = " << avg << endl << " standard diviation  = " << standv << endl;
            for (int c = 1; c < colm; c++) {
                cout << "normlization for  " << norm[1][c] << "  grade  =  " << (stod(norm[i][c]) - avg) / standv << endl;
            }
            break;
        }

    }
    if (x != "5")
    {
        cout << "the id is not found !" << endl << endl;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////// function to replace grades with GBA grades
string GRDtoGBA(string x)
{
    float y;
    if (x != "") {
        y = stof(x);
        string arr1[20] = { "A","B+","B","C+","C","D+","D","F","F" ,"F" ,"F" ,"F" ,"F" ,"F" ,"F" ,"F" };
        if (y < 90){
         if (y < 85){
          if (y < 80){
           if (y < 75){
            if (y < 70){
             if (y < 65){
              if (y < 60) { x = arr1[7]; }
              else { x = arr1[6]; }}
             else { x = arr1[5]; }}
            else { x = arr1[4]; }}
           else { x = arr1[3]; }}
          else { x = arr1[2]; }}
         else { x = arr1[1]; }}
        else { x = arr1[0]; }
        ////////////////////////////////////////
        // anather way
      /*              int i = 0;
          int v = 90;
          while (v > 1)
          {if (y<v && y>(v - 5))
            {x = arr1[i];}
            i++; v -= 5; }
          if(y>=90){
            x = arr1[0];
          }*/
    }
    else { x = "F"; }
    return x;
}
//////////////////////////////////////////////////////////////////////////  create csv file include GBA grades
void createGBA(string** grade, string x, int n, int colm)
{
    ofstream GBAgrade("GBAgrade.csv");
    int row = n + 2;
    if (GBAgrade.is_open())
    {
        //cout << "file is created ";
        for (int i = 0; i < colm; i++)
        {
            GBAgrade << grade[0][i] << ";";
        }
        for (int i = 0; i < colm; i++)
        {
            GBAgrade << grade[1][i] << ";";
        }
        for (int i = 2; i < row; i++)
        {
            GBAgrade << grade[i][0] << ";";
            for (int c = 1; c < colm; c++)
            {
                GBAgrade << GRDtoGBA(grade[i][c]) << ";";
            }
        }
        GBAgrade.close();
    }
    else { cout << "unable to open the file "; }
}
////////////////////////////////////////////////////////////////////////
void edite_data(string** ddata, string** dgrade, string id, int n, int c1)
{
        cout << "\n\n";
        string y,x,w,q="",t;
        for (int i = 2; i < (n + 2); i++) {
            y = ddata[i][0].substr(1, ddata[i][0].length() - 1);
            if (id == y) {
                x = "5";
                cin >> w;
                if (w == "id" || w == "ID")
                {
                    cout << "    New Id   :  "; cin >> q ; cout << endl;
                    ddata[i][0] = "\n" + q;
                    dgrade[i][0] = ddata[i][0];
                }
                else if (w == "name" || w == "NAME")
                {
                    cout << "   New Name  :  ";getline(cin,q); cout << endl;
                    q = take_cap_name(q, 2);
                    ddata[i][1] = q;
                }
                else if (w == "age" || w == "AGE")
                {
                    cout << "   New Age   :  "; cin >> ddata[i][2]; cout << endl;
                }
                else if (w == "gender" || w == "GENDER")
                {
                    cout << "   New Gender :  "; cin >> ddata[i][3]; cout << endl << endl;
                }
                else if (w == "grades" || w == "GRADES")
                {
                    cout << "\n\n ** new grades **   :-\n\n ";
                    cout << "      maths    : "; cin >> dgrade[i][1]; cout << endl;
                    cout << "     Physics   : "; cin >> dgrade[i][2]; cout << endl;
                    cout << "     Drawing   : "; cin >> dgrade[i][3]; cout << endl;
                    cout << "     Computer  : "; cin >> dgrade[i][4]; cout << endl;
                    cout << "     Chemistry : "; cin >> dgrade[i][5]; cout << endl<<endl;
                }
            }
        }
        if (x != "5")
        {
            cout << "the id is not found !" << endl << endl;
        }
    }
////////////////////////////////////////////////////////////////////////
void enter_arr(string** arr, int n, int c) {
    for (int i = 0; i < n + 2; i++) {
        for (int C = 0; C < c + 2; C++)
            cin >> arr[i][C];
    }
}
////////////////////////////////////////////////////////////////////////
void full_arr1_to_arr2(string** arr1, string** arr2,int n,int c) {
    for (int i = 0; i < n + 2; i++) {
        for (int C = 0; C < c ; C++)
            arr2[i][C] = arr1[i][C];
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////
int arange_menu() {
    string n;
    int x;
    do{
    cout << "  arange to ID                      (   ID    )\n";
    cout << "  arange to name                    (  name   )\n";
    cout << " arange to age                      (   age   )\n";
    cout << " arange to gender (famile first)                   (  gender )\n";
    cin >> n;
    if (n == "id" || n == "ID") { x = 0; break;}
    else if (n == "name" || n == "NAME") { x = 1; break; }
    else if (n == "age" || n == "AGE") { x = 2; break; }
    else if (n == "gender" || n == "GENDER") { x = 3; break;}
    else { cout << "\n wrong.... please enter correct selection ! \n\n"; }
    }while (true);
    return x;
}
/////////////////////////////////////////////////////////////////
void arange(string** dyn, int n, int c)
{
    string** arr;
    arr = create2D(c);
    string min;
    int x=0, y;
    full_arr1_to_arr2(dyn, arr, n, c);
    y=arange_menu();
    for (int i = 2; i < n + 2; i++) {
        min = dyn[2][y];
        for (int j = 2; j < n + 2; j++) {
            if (min >= dyn[j][y]) {
                min = dyn[j][y];
                x = j;
            }
        }
        for (int C = 0; C < c; C++) {
            arr[i][C] = dyn[x][C];
            cout << arr[i][C] << "( " << i << " , " << C << " )";
        }
            dyn[x][y] = "zzzzzzzzzzzzzzzzzzzz";
    }
    full_arr1_to_arr2(arr, dyn,n,c);

}

//////////////////////////////////////////////////////////////
void main_menu()
{
    cout << "==========================================================================================\n";
    cout << "\t 1-to import student data enter                         ( A )\n\n";
    cout << "\t 2-to import student grade enter                        ( B )\n\n";
    cout << "\t 3-to export student data & grade enter                 ( C )\n\n";
    cout << "\t 3-to edite student data & grade enter                  ( D )\n\n";
    cout << "\t 5-to modify student data enter                         ( E )\n\n";
    cout << "\t 2-to arange students in specific selection             ( g )\n\n";
    cout << "\t 5-for statistics of each course enter                  ( S )\n\n";
    cout << "----------------------------------------------------------------------------\n";
}
/////////////////////////////////////////////////////////////////////
void secondary_menu()
{
    cout << "---------------------------------------------------------------------\n";
    cout << "  to return to the main minu enter                  (    r    )\n";
    cout << "  to  enter new ID enter                            (    N    )\n";
    cout << "  to close the program enter                        (    F    )\n";
    cout << "----------------------------------------------------------------------------\n";
}
/////////////////////////////////////////////////////////////////////
void edite_menu()
{
    cout << "-----------------------------------------------------------------------------\n";
    cout << "\t 1-to edite student     iD       enter             (iD)\n\n";
    cout << "\t 2-to edite student     name     enter             (name)\n\n";
    cout << "\t 3-to edite student     age      enter             (age)\n\n";
    cout << "\t 4-to edite student    gender    enter             (gender)\n\n";
    cout << "\t 5-to edite student    grades    enter             (grades)\n\n";
    cout << "------------------------------------------------------------------------------\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int  c1 = 4, c2 = 6;    //  c1 => no. coloms in data file ,,,,,,,c2 => no. coloms in grade file ,,,,,,,n => number of students
    string id="123", str, ** dataDy, **gradeDy, **GBAdy;
    char z;
    n = findN("studentsData.csv");
    dataDy = create2D(c1);
    gradeDy = create2D(c2);
    GBAdy = create2D(c2);
    fullArr(dataDy, "studentsData.csv", c1);
    fullArr(gradeDy, "studentsGrade.csv", c2);
    createGBA(gradeDy, "studentsGrade.csv", n,c2);
    fullArr(GBAdy, "GBAgrade.csv", c2);
    char f, c{}, b;
    c = 'o';
    /////////////////////////////// active commonds/////////////////////
    do {
        if (c != 'F'&&c != 'f')
        {
            //system("CLs");
            cout << "please enter the Student Id : \n\n\n\n";
            cin >> id;
            do {
                cout << "pleas enter one function from the main minu\n\n ";
                main_menu();
                cin >> f;
                    if (f == 'A'|| f == 'a')

                {
                    pdata(dataDy, id);
                    secondary_menu();
                    cin >> c;
                    if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                        break;
                    }
                }

                    else if (f == 'B'|| f == 'b')
                    {
                        pgrade(gradeDy, id,n);
                        secondary_menu();
                        cin >> c;
                        if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                            break;
                        }
                    }
                    
                    else if (f == 'C' || f == 'c')
                        {
                            do {
                                z = is_ID_there(dataDy, id);
                                if (z)
                                {
                                    delete2d(dataDy);
                                    delete2d(gradeDy);
                                    delete2d(GBAdy);
                                    n += 1;
                                    dataDy = create2D(c1);       //cout<<dataDy[0][1]<<endl;
                                    gradeDy = create2D(c2);
                                    GBAdy = create2D(c2);
                                    fullArr(dataDy, "studentsData.csv",c1);
                                    fullArr(gradeDy, "studentsGrade.csv", c2);

                                    enterDataTo(dataDy, id, c1);     // printArr(dataDy,n,c1);
                                    enterDataTo(gradeDy, id, c2);
                                    dataDy[n][1] = take_cap_name(dataDy[n][1], 2);
                                    createGBA(gradeDy, "studentsGrade.csv", n, c2);
                                    fullArr(GBAdy, "GBAgrade.csv", c2);
                                    fullFile(dataDy, "studentsData.csv", c1);                //addToFile(dataDy,"studentsData.csv",n,c1);
                                    fullFile(gradeDy, "studentsGrade.csv", c2);
                                    fullFile(GBAdy, "GBAgrade.csv", c2);
                                    secondary_menu();
                                    cin >> c;
                                    cout << "\n\n\n";
                                    if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                                        break;
                                    }
                                }

                                else {
                                    cout << " sorry this id is writen before\n\n";
                                }
                                //cout << "  to reenter new student enter                      ( S )\n";
                                secondary_menu();
                                cin >> c;
                                cout << "\n\n\n";
                                if (c == 'N' || c == 'n' || c == 'F' || c == 'f' || c == 'r' || c == 'R') {
                                    break;
                                }

                            } while (true);
                        }
                        
                    else  if (f == 'D' || f == 'd')
                            {
                                do {
                                    z = is_ID_there(dataDy, id);
                                    if (z != true)
                                    {
                                        pdata(dataDy, id);
                                        pgrade(gradeDy, id, n);
                                        edite_menu();
                                        edite_data(dataDy, gradeDy, id, n, c1);
                                        createGBA(gradeDy, "studentsGrade.csv", n, c2);
                                        fullArr(GBAdy, "GBAgrade.csv", c2);
                                        fullFile(dataDy, "studentsData.csv", c1);                //addToFile(dataDy,"studentsData.csv",n,c1);
                                        fullFile(gradeDy, "studentsGrade.csv", c2);
                                        fullFile(GBAdy, "GBAgrade.csv", c2);
                                        secondary_menu();
                                        cin >> c;
                                        cout << "\n\n\n";
                                        if (c == 'N' || c == 'n' || c == 'F' || c == 'f' || c == 'r' || c == 'R') {
                                            break;
                                        }
                                    }
                                    else {
                                        cout << "the id is not found !" << endl << endl;
                                        c = 'N';
                                        break;
                                    }
                                } while (true);
                            }
                            
                    else if (f == 'E' || f == 'e')
                                {
                                    cout << "  to normlize grades of the student enter         ( N )\n";
                                    cout << "  to print GBA grades of  the student enter       ( G )\n";
                                    char M;
                                    cin >> M;
                                    if (M == 'N'|| M == 'n')
                                    {
                                        normlize(gradeDy, id, n, c2);
                                    }
                                    if (M == 'G'|| M == 'g')
                                    {
                                        pGBA(GBAdy, id, n);
                                    }
                                    secondary_menu();
                                    cin >> c;

                                    if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                                        break;
                                    }
                                }
                                
                    else if (f == 'S' || f == 's')
                                    {
                                        cout << "    sorry no feature to do now \n";
                                        secondary_menu();
                                        cin >> c;
                                        if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                                            break;
                                        }
                                    }
                                    
                    else if (f == 'g' || f == 'G')
                                        {
                                            //string** arr;
                                           // arr= create2D(n, c1);
                                           // enter_arr(arr, n, c1);
                                            arange(dataDy, n, c1);
                                            printArr(dataDy, c1);
                                            secondary_menu();
                                            cin >> c;
                                            if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                                                break;
                                            }
                                        }
                                        else {
                                            cout << "****    you entered unknown function !    ****\n\n";
                                            secondary_menu();
                                            cin >> c;
                                            if (c == 'N' || c == 'n' || c == 'F' || c == 'f') {
                                                break;
                                            }
                                        }
                if (c == 'N' || c == 'n' || c == 'F' || c == 'f')
                    break;
            } while (true);
        }
        else {
            break;
        }
    } while (true);
    delete2d(dataDy);
    delete2d(gradeDy);
    delete2d(GBAdy);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
