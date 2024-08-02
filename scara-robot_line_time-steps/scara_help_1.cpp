// scara_help_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdio>
using namespace std;


///////////////////////////////////////////////////////////////////////
string** create2D(int colm,int row)
{
    string** array2d = new string * [row];
    for (int i = 0; i < row; i++)
        array2d[i] = new string[colm];
    return array2d;
}
///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////   export methods   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void fullFile(string** dyn, string name, int row, int colm)
{
    ofstream File(name);
    if (File.is_open())
    {
        //cout << "file is created \n";

        for (int i = 0; i < row+1; i++)
        {
            for (int c = 0; c < colm; c++)
            {
                File << dyn[c][i] << ";";
            }
             File<<endl;
        }
        File.close();
    }
    else { cout << "unable to open the file "; }
}
////////////////////////////////////////////////////////////////////////
void delete2d(string** dyn,int row)
{
    for (int i = 0; i < row; i++)
        delete[] dyn[i];
    delete[] dyn;
}
///////////////////////////////////////////////////////////////////////
double length(int x1, int y1, int x2, int y2) {
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
////////////////////////////////////////////////////////////////////////
int main()
{
    double x, y, t, ax, ay, q1, q2;
    double x1=200, y1=120, x2=203, y2=130;
    int l1 = 228, l2 = 144;
    double T = 4*4;  //16 micro second
    int v = 100;// 100 m/s
    string **data;

    int l = 1;
    double r1 = sqrt(x1 * x1 + y1 * y1);
    double r2 = sqrt(x2 * x2 + y2 * y2);
    double pi = 3.141592;
    int c= (length(x1,y1,x2,y2)*1000000) / (T * v); 
    cout << c; cout << endl;
    data = create2D(c+1, 9);
    ay = (y2-y1)/((T*c)/1000000);
    cout << ay; cout << endl;
    ax = ((x2 - x1) / ((T * c) / 1000000));
    cout << ax; cout << endl;
    double c1, c2, c3, n1, n2, n3, s1=0, s2=0, sp1=0, sp2=0,tq1,tq2,sb1,sb2,sn1=0,sn2=0;
    
     if ( r1 >= 90 && r1 <= 366 && r2 >= 90 && r2 <= 366) {
         
         for (int i = 0; i < c; i++) {

             

             t = (T * i)/1000000;
             y = y1 + (ay * t);
             x = x1 + (ax * t);
             tq1 = t;
             tq2 = t;
             sb1 = sn1;
             sb2 = sn2;
              c1 = ((x * x) + (y * y) - (l1 * l1) - (l2 * l2));
              c2 = (2 * l1 * l2);
             cout << c1; cout << endl;
             cout << c2; cout << endl;
              s2 = acos(c1 / c2);
              s2 = s2 * (180 / pi);
             cout << "s2 = "; cout << s2; cout << endl;
             if (x == 0) {
                 c3 = 3.14259;
             }
             else {
                  n1 = y / x;
                 c3 = atan(n1);
                 cout << "n1 = "; cout << n1; cout << endl;
             }

              n2 = (l2 * sin(s2));
              n3 = sqrt((x * x) + (y * y));
             cout << "n2 = "; cout << n2; cout << endl;
             cout << "n3 = "; cout << n3; cout << endl;

              s1 = c3 - asin(n2 / n3);
              s1 = s1 * (180 / pi);
             cout << "s1 = "; cout << s1; cout << endl;
             if (l == 1) {
                 sp1 = s1;
                 sp2 = s2;
                 l++;
             }

                 data[0][i+1] = to_string(t*1000000);
                 cout << data[0][i+1]; cout << "( " << 0 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";

                 data[1][i+1] = to_string(x);
                 cout << data[1][i+1] << "( " << 1 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";

                 data[2][i + 1] = to_string(y);
                 cout << data[2][i + 1] << "( " << 2 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";

                 data[3][i + 1] = to_string(s1);
                 cout << data[3][i + 1] << "( " << 3 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";

                 data[4][i + 1] = to_string(s2) ;
                 cout << data[4][i + 1] << "( " << 4 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";
                 sn1 = int(abs((s1 - sp1) * (160 / 18)));
                 data[5][i + 1] = to_string(sn1);
                 cout << data[5][i + 1] << "( " << 5 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";

                 data[6][i + 1] = to_string(((sn1-sb1) == 0 ? 0 : t *1000000));
                 cout << data[6][i + 1] << "( " << 6 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";
                 sn2 = int(abs((s2 - sp2) * (160 / 18)));
                 data[7][i + 1] = to_string(sn2);
                 cout << data[7][i + 1] << "( " << 7 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";
               
                 data[8][i + 1] = to_string(((sn2 - sb2) == 0 ? 0 : t *1000000 ));
                 cout << data[8][i + 1] << "( " << 8 << ",,," << i << " )";          // to print all data from the array
                 cout << "\t\t";
             }
             cout << endl;
         }



    /*for (int i = 1; i < c; i++) {
        for (int c = 0; c < 5; c++) {
             data[0][c]= 5;
            cout << data[1][c] << "( " << i << ",,," << c << " )";          // to print all data from the array
            cout << "\t\t";
        }
        cout << endl;
    }
    cout << "\n\n\n";
    */
                /*
                double steps1 = (1600 / pi) * 10 * s1;  int  abs_1 = abs(steps1);
                double steps2 = (1600 / pi) * 8 * s2;   int  abs_2 = abs(steps2);
                double steps3 = 1600 * z;               long abs_3 = abs(steps3);
                double stepso = (3200 / 360) * o;       int  abs_o = abs(stepso);

                Serial.println((String)" steps1 = " + steps1 + "  ,  " + abs_1);
                Serial.println((String)" steps2 = " + steps2 + "  ,  " + abs_2);
                Serial.println((String)" steps3 = " + steps3 + "  ,  " + abs_3);
                Serial.println((String)" stepso = " + stepso + "  ,  " + abs_o);


                if (abs_1 <= 24000 && abs_2 <= 19200 && abs_3 <= 292000 && abs_o <= 6400) {
                    long cs[4];
                    for (int i = 0; i < 4; i++)
                        cs[1] = steps1 - steppers[1].stepPosition;
                    cs[2] = steps2 - steppers[2].stepPosition;
                    cs[3] = steps3 - steppers[3].stepPosition;
                    cs[0] = stepso - steppers[0].stepPosition;

                    Serial.println((String)" cs1 = " + cs[1]);
                    Serial.println((String)" cs2 = " + cs[2]);
                    Serial.println((String)" cs3 = " + cs[3]);
                    Serial.println((String)" cso = " + cs[0]);
                    */
         fullFile(data,"data3.csv", c, 9);
         delete2d(data, 9);

    cout << "Hello World!\n";
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
