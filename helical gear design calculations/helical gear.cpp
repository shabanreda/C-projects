// helical gear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
#define _USE_MATH_DEFINES
void fullArr(string** dyn, string name, int stNum, int colm)
{
    ifstream reading(name);
    if (reading.is_open()) {
        for (int i = 0; i < (stNum + 1); i++) {
            for (int c = 0; c < colm; c++) {
                getline(reading, dyn[i][c], ',');
                cout << dyn[i][c] << "( " << i << ",,," << c << " )";          // to print all data from the array
                cout << "\t\t";
            }
            cout << endl;
        }
        cout << "\n\n\n";
        reading.close();
    }
    else
    {
        cout << "unable to open file" << endl;
    }
    // dyn[0][1] = to_string(stNum);
}

///////////////////////////////////////////////////////////////////////
void delete2d(string** dyn, int n)
{
    int row = n;
    for (int i = 0; i < row; i++)
        delete[] dyn[i];
    delete[] dyn;
}
///////////////////////////////////////////////////////////////////////
string** create2D(int n, int colm)
{
    int row = n + 2;
    string** array2d = new string * [row];
    for (int i = 0; i < row; i++)
        array2d[i] = new string[colm];
    return array2d;
}

int main()
{
    double alf = 20, alft,gama = 0, m = 0, mn = 0, b = 0, u = 0, Dp = 0, Dg = 0, Dpm = 0, Dgm = 0, Zp, Zg, Zfp, Zfg, DLTp = 0, DLTg = 0, L = 0, P = 0, Tp = 0, w = 0, V = 0, Pt = 0, Frp, Frg, Fap, Fag, Pd = 0, Pen = 0, Pw = 0, Kyp = 0, Kyg = 0, Ks = 0, Kv = 0,Kl, Sp, Sg, Syp, Sup, Syg, Sug, Senp, Seng, BHN=0, Kd, K = 0.111, e, ep, er, Ep, Eg, Kw, Kn, MS;
    string** module, ** segma, ** epr, ** KW;
    gama = 30 * (( 3.14159) / 180);
    alf = 20 * ((3.14159) / 180);
    module = create2D(50, 1);
    segma = create2D(7, 3);
    epr = create2D(17, 2);
    KW = create2D(12, 4);
    fullArr(module, "modules .csv", 50, 1);
    fullArr(segma, "segma .csv", 7, 3);
    fullArr(epr, "permissible error.csv", 17, 2);
    fullArr(KW, "load stress  factor (Kw) .csv", 12, 4);
    cout << "\n please enter the following data  : \n\n\n";
    cout << "        power  (KW)  =  "; cin >> P; cout << endl;
    cout << "  anglur speed (rpm) =  "; cin >> w; cout << endl;
    do {
        cout << "    reduction ratio  =  "; cin >> u; cout << endl;
        if (u > 10 || u < 0)
        {
            cout << "\n wrong : The reduction ratio is over design it shloud be 4>u>0: \n\n";
            cout << " please enter a new u  \n\n";
        }
        else
            break;
    } while (true);
    do {
        string c;

        do {
            cout << "        module  (mm/tooth)  =  "; cin >> mn; cout << endl;
            string y, x = "4";
            double r;
            r = stod(module[0][0]);
            if (mn == r)
            {
                break;
            }
            else {
                for (int i = 1; i < 51; i++) {
                    y = module[i][0].substr(1, module[i][0].length() - 1);
                    r = stod(y);
                    if (mn == r) {
                        x = "5";
                    }
                }
                if (x == "5")
                    break;
                else {
                    cout << "\n this module is not found  !" << endl << endl;
                    for (int i = 1; i < 51; i++) {
                        y = module[i][0].substr(1, module[i][0].length() - 1);
                        r = stod(y);
                        if (mn < r) {
                            cout << "\n the nearst values to your module is  ( " << module[i][0].substr(1, module[i][0].length() - 1) << "  ,  " << module[i - 1][0].substr(1, module[i - 1][0].length() - 1) << " )\n";
                            cout << " please enter a new module  \n\n";
                            break;
                        }
                    }
                }
            }
        } while (true);
        m = mn / cos(gama);
        cout << "\n  m = " << m << "\n\n";
        do {
            cout << "\n     the maximum of pinion diameter is  =  "<< (50 * 120*1000) / (w*2*3.14159)<<" mm \n\n";
            cout << "\n    pinion diameter  =  "; cin >> Dp; cout << endl << endl;
            
            Dg = u * Dp;
            V = (w * Dp * 2 * 3.14159) / (60 * 2 * 1000);
            float exm = fmod(Dp, m);
            exm = double(int(exm * 1000)) / 1000;
            
            if (V > 50)
                cout << "  wrong : The Velocity of pinion = " << V << " (m/s)  \n It is over design , it shloud be V<20  m/s \n to help...decrease the pinion diameter\n\n";
            else if ((exm / m) != 0.0)
            {

                cout << "  wrong : The number of teeth = " << Dp / m << " (mm) and exm = " << exm << " \n It is over design , it shloud be integer number ....change the pinion diameter   \n";
                cout << "\n the nearst values to your pinion diameter is  ( " << ((Dp / m) - (exm / m)) * m << "  ,  " << ((Dp / m) - (exm / m) + 1) * m << " )\n";
            }
            else
                break;
        } while (true);

        //L = sqrt(pow(Dp / 2, 2) + pow(Dg / 2, 2));
        Zp = Dp / m;
        Zg = Zp * u;
        cout << " please try to enter the tooth width b (mm)   \n\n but rememper that b shloud be between : \n  " << (m * 12.5) << " mm  to " << (m * 20) << " mm  --> for single gear \n\n";
        do {
            cout << "        tooth width b (mm)    =  "; cin >> b; cout << endl;
            if (b < m * 12.5 || b > m * 20)
            {
                cout << "\n wrong : The tooth width is not in rang: \n\n";
                cout << " please enter a new b  \n\n";
            }
            else
                break;
        } while (true);

        alft = atan(tan(alf)/cos(gama));
        Tp = ((P * 60E3) / (w * 6.28318));
        Pt = (Tp* 2E3) / ( Dp );
        Fap = Pt * tan(alft) ;
        Frp = Pt *  tan(gama);

       // Zfp = Zp / cos(DLTp);
        //Zfg = Zp / cos(DLTg);
        Kyp = 0.54 - (3 / Zp);
       // Kyg = 0.48 - (2.85 / Zfg);
        Ks = 1.5;
        if (V < 10)
            Kv = 6 / (6 + V);
        else if (V < 20)
            Kv = 15 / (15 + V);
        else if (V > 20)
            Kv = 5.5 / (5.5 + sqrt(V));
        Kyp = 0.54 - (3 / Zp);
        Kl = 1.25;
        Sp = (Pt * Ks * Kl) / (b * m * Kv * Kyp);
      //  cout << "DLTp = " << DLTp << " (rad) " << endl;
        //cout << "DLTg = " << DLTg << " (rad) " << endl;
        cout << "alfn = " << alf << " (rad) " << endl;
        cout << "alft = " << alft << " (rad) " << endl;
        cout << "gama = " << gama << " (rad) " << endl;
        cout << " Dp  = " << Dp << " (mm) " << endl;
        cout << " Dg  = " << Dg << " (mm) " << endl;
       // cout << " Dpm = " << Dpm << " (mm) " << endl;
        //cout << " Dgm = " << Dgm << " (mm) " << endl;
        cout << "  Pt = " << Pt << " (N) " << endl;
        cout << " Frp = " << Frp << " (N) " << endl;
        cout << " Fap = " << Fap << " (N) " << endl;
        cout << " Kyp = " << Kyp << endl;
        cout << "  Ks = " << Ks << endl;
        cout << "  Kv = " << Kv << endl;
        cout << "  Kl = " << Kl << endl;
        cout << "   V = " << V << " (m/s) " << endl;
        //cout << " b/L = " << b / L << endl;
        cout << "\n\n segma pinion = " << Sp << " (MPa) " << endl;
        do {
            string y, x = "4";
            double r;
            r = stod(segma[0][1]);
            if ((Sp * 1.5) < r)
            {
                Syp = r;
                Sup = stod(segma[0][0]);
                BHN = stod(segma[0][2]);
                if (BHN >= 150 && BHN < 200)
                    BHN = 150;
                else if (BHN >= 200 && BHN < 250)
                    BHN = 200;
                else if (BHN == 250)
                    BHN = 250;
                cout << "\n the nearst values to your segma yield is  ( " << Syp << "  MPa\n ";
                cout << "\n and segma ultimate is  ( " << Sup << "  MPa\n ";
                break;
            }
            else {
                for (int i = 1; i < 8; i++) {
                    y = segma[i][1];
                    r = stod(y);
                    cout << " r =  " << r << endl;
                    if ((Sp * 1.5) < r) {
                        Syp = r;
                        Sup = stod(segma[i][0]);
                        BHN = stod(segma[i][2]);
                        cout << "\n the nearst values to your segma yield is  ( " << Syp << "  MPa\n ";
                        cout << "\n and segma ultimate is  ( " << Sup << "  MPa\n ";
                        break;
                    }
                }
                if (BHN >= 150 && BHN < 200)
                    BHN = 150;
                else if (BHN >= 200 && BHN < 250)
                    BHN = 200;
                else if (BHN == 250)
                    BHN = 250;
                if ((Sp * 1.5) > r) {
                    cout << "\n this segma yield ( " << Sp * 1.5 << " ) is not found  !" << endl << endl;
                    cout << " please  improve your data again \n\n";
                    c = "6";
                    break;
                }
                break;
            }
        } while (true);

        if (c != "6")
        {


            double r, rma, rmi, ema, emi;

            for (int i = 1; i < 18; i++) {
                r = stod(epr[i][0].substr(1, epr[i][0].length() - 1));
                if (V < r)
                    ep = stod(epr[i][1].substr(1, epr[i][1].length() - 1));
                else {};
                if (V > r)
                {
                }
                else {
                    rma = r;
                    rmi = stod(epr[i - 1][0].substr(1, epr[i - 1][0].length() - 1));
                    ema = stod(epr[i][1]);
                    emi = stod(epr[i - 1][1]);
                    ep = ema - (((rma - V) / (rma - rmi)) * (ema - emi));
                    cout << "\n ep = " << ep << " Mm \n\n";
                    break;
                }
            }
            if (ep > 50)
            {
                ep = 50;
            }
            K = 0.111;
            Ep = 210;  // GPa....steel
            Eg = 210;  // GPa....steel
            Kd = (K * ep) / ((1 / Ep) + (1 / Eg));
            cout << "\n Kd = " << Kd << " N/mm \n\n";

            Pd = (((Kd * b*pow(cos(gama),2)) + Pt)*cos(gama)) / (1 + (0.15 / V) * sqrt((Kd * b*pow(cos(gama),2)) + Pt));
            cout << "  Pd =" << Pd << "N \n\n";

            Pen = Sup * b * m * Kyp * 0.5;
            cout << "\n this  endurence force  (Pen) " << Pen << "  N  " << endl << endl;
            MS = (Pen - Pd) / Pd;
            if (P <= 10 && MS < 0.25)
                cout << "  wrong : The Margin of safety = " << MS * 100 << " (m/s)  \n It is over design , it shloud be MS > 25 %  m/s  \n\n";
            else if (P <= 20 && MS < 0.35)
                cout << "  wrong : The Margin of safety = " << MS * 100 << " (m/s)  \n It is over design , it shloud be MS > 35 %  m/s  \n\n";
            else if (P > 10 && MS < 0.50)
                cout << "  wrong : The Margin of safety = " << MS * 100 << "  %  \n It is over design , it shloud be MS > 50 %  m/s  \n\n";

            cout << "   The Margin of safety = " << MS * 100 << " %   \n \n";

            string  y, x = "4";
            double R, r1;
            for (int i = 1; i < 13; i++) {
                y = KW[i][0].substr(1, KW[i][0].length() - 1);
                R = stod(y);
                r1 = stod(KW[i][1]);
                if (BHN == R && BHN == r1) {
                    Kw = stod(KW[i][3]);

                }
            }

            Kn = (2 * u) / (1 + u);
            Pw = Kw * Kn * b * Dp/pow(cos(gama),2);
            cout << "\n this wear forcee  (Pw) = " << Pw << " N  " << endl << endl;

            if (Pw < Pd)
                cout << "\n Wrong : Pw < Pd  !" << endl << endl;

            cout << "# to exit click          ---> ( F ) \n\n";
            cout << "# to return the process  ---> ( R ) \n\n";
            cin >> c;
            if (c == "f" || c == "F")
                break;

        }
    } while (true);

    delete2d(module, 51);
    delete2d(segma, 8);
    delete2d(epr, 18);
    delete2d(KW, 13);







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
