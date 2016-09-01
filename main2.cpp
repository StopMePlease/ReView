#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <malloc.h>

using namespace std;

string BienKiTuDauThanhHoa(string s)
{
    string p = s;
    int len = p.length();

    if(p[0] != ' ')
    {
        if(p[0] >= 'a' && p[0] <= 'z')
        {
            p[0] -= 32;
        }
    }

    for(int i = 0; i < len; i++)
    {
        if(p[i] == ' ' && p[i + 1] != ' ')
        {
            if(p[i + 1] >= 'a' && p[i + 1] <= 'z')
            {
                p[i + 1] -= 32;
            }
        }
    }
    return p;
}

void XoaKyTu(string& s, int vitrixoa)
{
    int len = s.length();
    for(int i = vitrixoa + 1; i < len; i++)
    {
        s[i - 1] = s[i];
    }
    s[len - 1] = 0;
}

string XoaKhoangTrangThua(string s)
{
    string p = s;
    int len = p.length();

    for(int i = 0; i < len; i++)
    {
        if(p[i] == ' ' && p[i + 1] == ' ')
        {
            XoaKyTu(p, i);
            i--;
            len--;
        }
    }

    if(p[0] == ' ')
    {
        XoaKyTu(p, 0);
        len--;
    }

    if(p[len - 1] == ' ')
    {
        XoaKyTu(p, len - 1);
        len--;
    }
    return p;
}

int DemSoTu(string s)
{
    int dem;
    if(s[0] == ' ')
    {
        dem = 0;
    }
    else{
        dem = 1;
    }

    int len = s.length();

    for(int i = 0; i < len - 1; i++)
    {
        if(s[i] == ' ' && s[ i + 1] != ' ')
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    cout << "1. ham random\n";
    cout << "2. Xoa bo nho dem trong chuoi\n";
    cout << "3. Chuoi\n";
    cout << "4. Mang Rang Cua\n";

    int lc;
    cin >> lc;

    switch(lc)
    {
    case 1:
        {
            srand(time(0));
            int a = -20 + rand() % 51;
            cout << a;
            break;
        }
    case 2:
        {
            cout << " fflush(stdin); \n";
            cout << " while(getchar() != '\n'); \n";
            cout << " cin.get(); \n";
            break;
        }
    case 3:
        {
            cin.get();
            string s;
            getline(cin, s);

            s = BienKiTuDauThanhHoa(s);
            s = XoaKhoangTrangThua(s);
            XoaKyTu(s, 5);
            int dem = DemSoTu(s);

            cout << s << "\t" << dem;

            break;
        }
    case 4:
        {
            int dong = 5;
            int *cot = (int*)malloc(dong * sizeof(int));
            int **a = (int**)malloc(dong * sizeof(int));

            for(int i = 0; i < dong; i++)
            {
                cout << "Row " << i << " has ? column(s)\n";
                cin >> cot[i];
                a[i] = (int*)malloc(cot[i] * sizeof(int));
            }

            for(int i = 0; i < dong; i++)
            {
                for(int j = 0; j < cot[i]; j++)
                {
                    cout << "a[" << i << "][" << j << "]: ";
                    cin >> a[i][j];
                }
            }

            for(int i = 0; i < dong; i++)
            {
                for(int j = 0; j < cot[i]; j++)
                {
                    cout << "     " << a[i][j];
                }
                cout << endl;
            }

            for(int i = 0; i < dong; i++)
            {
                free(a[i]);
            }

            free(a);
            free(cot);
        }
    }

    return 0;
}
