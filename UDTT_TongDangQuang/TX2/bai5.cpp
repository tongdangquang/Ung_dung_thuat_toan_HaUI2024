#include <bits/stdc++.h>
using namespace std;

struct PC
{
	string brand;
	char config[100];
	long price;
};

int char_in_string (char c, char * p)
{
    int n = strlen(p);
    for (int i = 0; i < n; i++)
    {
        if (c == p[i])
            return i;
    }
    return -1;
}

int F1(char * t, char * p)
{
    int v = strlen(p), n = strlen(t), i = v - 1;

    if(v > n)
        return -1;

    while(i < n)
    {
        int k = v - 1;
        while(k >= 0 && t[i] == p[k])
        {
            i--;
            k--;
        }
        if (k < 0) 
            return i + 1;
        else
        {
            int x = char_in_string(t[i], p);
            if(x < 0)
                i = i + v;
            else
                i = i + v - x - 1;
        }
    }
    return -1;
}

void F2 (char * s, int * z)
{
    int n = strlen(s);
    int left = 0, right = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > right)
        {
            left = right = i;
            while(right < n && s[right - left] == s[right])
                right++; 
            z[i] = right - left; 
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

void F3(PC * d, int n)
{
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if(F1(d[i].config, "RAM 16GB") != -1)
            r++;
    }

    if(r > 0)
    {
        cout << "So may tinh co RAM 16GB la: " << r << endl;
        cout << "--------------------------------------------" << endl;
        cout << "DANH SACH MAY TINH CO RAM 16GB: " << endl;
        cout << left << setw(10) << "BRAND" << left << setw(50) << "CONFIGURATION" << left << setw(15) << "PRICE" << endl;
         for (int i = 0; i < n; i++)
            if(F1(d[i].config, "RAM 16GB") != -1)
                cout << left << setw(10) << d[i].brand << left << setw(50) << d[i].config << left << setw(15) << d[i].price << endl;
    }
    else
        cout << "Khong co may tinh nao co RAM 16GB" << endl;
}

int Z_apply(char * t, char * p)
{
    int p_size = strlen(p);
    int t_size = strlen(t);
    char s[p_size + t_size + 2];
    strcpy(s, p);
    strcat(s, "$");
    strcat(s, t);
    int n = strlen(s);

    int * z = new int [n]();

    F2(s, z);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if(z[i] == p_size)
            cnt++;
    }
    return cnt;
}

void F4(PC* d, int n)
{
    int s = 0;
    PC * t = new PC[n];
    char p[] = "SSD";
    for (int i = 0; i < n; i++)
    {
        if(Z_apply(d[i].config, p) != 0)
        {
            t[s] = d[i];
            s++;
        }
    }

    if(s > 0)
    {
        cout << "So luong may tinh su dung o cung SSD la: " << s << endl;
        cout << "--------------------------------------------" << endl;

        cout << "DANH SACH MAY TINH SU DUNG O CUNG SSD: " << endl;
        cout << left << setw(10) << "BRAND" << left << setw(50) << "CONFIGURATION" << left << setw(15) << "PRICE" << endl;
        for (int i = 0; i < s; i++)
            cout << left << setw(10) << t[i].brand << left << setw(50) << t[i].config << left << setw(15) << t[i].price << endl;
    }
    else
        cout << "Khong co may tinh nao su dung o cung SSD" << endl;
}


int main ()
{
	int n = 5;
	PC * d = new PC [n]{
		{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
		{"LG", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 1TB", 20000000},
		{"DELL", "CPU 2.5GHz upto 3.5GHz-RAM 24GB-SSD 256GB", 18000000},
		{"ASUS", "CPU 2.5GHz upto 3.5GHz-RAM 32GB-SSD 512GB", 25000000},
		{"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 2TB", 16000000},
	};
    
    cout << "--------------------------------------------" << endl;
	F3(d, n);
    cout << "--------------------------------------------" << endl;
    F4(d, n);
}