#include <bits/stdc++.h>
using namespace std;

void Sort(string * d, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(d[i].length() < d[j].length())
                swap(d[i], d[j]);
        }
    }
}

string G(string * d, int n, int k, int & x)
{
    Sort (d, n);
    string p = "";
    for (int i = 0; i < n; i++)
    {
        if(p.length() + d[i].length() <= k)
        {
            p += d[i];
            x++;
        }
        if(p.length() == k)
            break;
    }
    return (p.length() == k) ? p : "";
}

int char_in_string(char c, string p)
{
    int n = p.length();
    for (int i = 0; i < n; i++)
    {
        if(c == p[i])
            return i;
    }
    return -1;
}

bool BMH(string t, string p)
{
    int v = p.length();
    int n = t.length();
    int i = v - 1;
    if (v > n)
        return false;
    while(i < n)
    {
        int k = v - 1;
        while (k >= 0 && t[i] == p[k])
        {
            i--;
            k--;
        }
        if (k < 0)
            return true;
        else
        {
            int x = char_in_string(t[i], p);
            if(x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
    return false;
}

void BMH_apply(string * d, int n, string x)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if(BMH(d[i], x))
            c++;
    }
    if(c > 0)
    {
        cout << "Tu " << x << " xuat hien trong " << c << " xau cua danh sach" << endl;        
        cout << "DANH SACH XAU CO XUAT HIEN TU \'" << x << "\':" << endl;
        for (int i = 0; i < n; i++)
        {
            if(BMH(d[i], x))
                cout << d[i] << endl;
        }
    }
    else
        cout << "Tu " << x << " khong xuat hien trong xau nao danh sach" << endl;
}


void Z(string s, int * z)
{
    int n = s.length();
    int left = 0, right = 0;
    for (int i = 1; i < n; i++)
    {
        if( i > right)
        {
            left = right = i;
            while (right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        }
        else if (z[i - left] < right - i + 1)
            z[i] = z[i - left];
        else
        {
            left = i;
            while(right < n && s[right - left] == s[right])
                right++;
            z[i] = right - left;
            right--;
        }
    }
}

void Z_apply(string * d, int n, string p)
{
    string * dd_str = new string [n];
    int * dd_count = new int [n]();
    int x = 0;

    for (int i = 1; i < n; i++)
    {
        string s = p + "$" + d[i];
        int len_s = s.length();
        int * z = new int [len_s]();
    
        Z(s, z);
        int c = 0;
        for (int j = 1; j < len_s; j++)
        {
            if(z[j] == p.length())
                c++;
        }
        if(c > 0)
        {
            dd_str[x] = d[i];
            dd_count[x] = c;
            x++;
        }
    }

    if (x > 0)
    {
        cout << "XAU \'" << p << "\' LA XAU CON CUA CAC XAU:" << endl;
        cout << left << setw(50) << "CHUOI" << left << setw(20) << "SO LAN XUAT HIEN CHUOI \'" << p << "\'" << endl;
        for (int i = 0; i < x; i++)
            cout << left << setw(50) << dd_str[i] << left << setw(20) << dd_count[i] << endl;
    }
    else
        cout << "Khong co xau nao trong danh sach co \'" << p << "\' la xau con" << endl;
}

int main()
{
    int n = 5;
    string * d = new string [n]{
        "child", 
        "Hello world",
        "My child name is Ana child",
        "He is a child",
        "Thank you very much"
    };
    
    int x = 0;
    string result = G(d, n, 32, x);
    if(result != "")
    {
        cout << "Can it nhat " << x << " xau tu danh sach" << endl;
        cout << "Ket qua xau p: " << result << endl;
    }
    else
        cout << "Khong the tao xau thoa man" << endl;
    cout << "----------------------------------------------------" << endl;

    BMH_apply(d, n, "child");
    cout << "----------------------------------------------------" << endl;

    Z_apply(d, n, d[0]);
}
