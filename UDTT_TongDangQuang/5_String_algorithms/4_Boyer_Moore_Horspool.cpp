// Thuật toán Boyer Moore Horspool (BMH) được sử dụng để phát hiện xâu con P trong xâu T
// với thời gian thực hiện tốt hơn so với thuật toán vét cạn.
// Xem hướng dẫn cài đặt chi tiết trong file đề cương

// Thuật toán Boyer Moore Horspool (BMH) được sử dụng để phát hiện xâu con P trong xâu T
// với thời gian thực hiện tốt hơn so với thuật toán vét cạn.
// Xem hướng dẫn cài đặt chi tiết trong file đề cương

#include <bits/stdc++.h>
using namespace std;

int char_in_string(char c, char * p)
{
    int n = strlen(p);
    for (int i = 0; i < n; i++)
    {
        if(c == p[i])
            return i;
    }
    return -1;
}

int BMH(char * t, char * p)
{
    int v = strlen(p);
    int n = strlen(t);
    int i = v - 1;

    // trường hợp xâu t dài hơn xâu p
    if(v > n)
        return -1;

    while(i < n)
    {
        int k = v - 1; // đặt k là chỉ số để duyệt xâu p
        while(k >= 0 && t[i] == p[k])
        {
            i--;
            k--;
        }
        if (k < 0) 
            return i + 1;
        else
        {
            // kiểm tra xem ký tự t[i] có trong p hay không, nếu có trả về vị trí của ký tự đó
            int x = char_in_string(t[i], p);

            // nếu t[i] không nằm trong p thì chuyển i đến vị trí tiếp theo với khoảng cách bằng độ dài của p
            if(x < 0)
                i = i + v;
                
            // nếu t[i] nằm trong p thì dịch i lên v - x - 1 vị trí để tiếp tục duyệt
            else
                i = i + v - x - 1;
        }
    }
    return -1;
}


int main()
{
    char t[] = "hello world";
    char p[] = "world";

    int index = BMH(t, p);
    if(index != -1)
        cout << "p la xau con cua t, p xuat hien tai vi tri " << index << endl;
    else
        cout << "p khong la xau con cua t" << endl;
}



// Bài toán thay thế xâu con trong xâu cha bằng một xâu con khác
// #include <bits/stdc++.h>
// using namespace std;

// int char_in_string(char c, string p)
// {
//     int n = p.length();
//     for (int i = 0; i < n; i++)
//     {
//         if (c == p[i])
//             return i;
//     }
//     return -1;
// }

// int* A3(string p, string t, int & c)
// {
//     int n = p.length();
//     int v = t.length();
//     int * id = new int[n]; 
//     int i = v - 1;

//     if (v > n)
//         return id;
//     while (i < n)
//     {
//         int k = v - 1;
//         int j = i;
//         while (k >= 0 && p[j] == t[k])
//         {
//             j--;
//             k--;
//         }
//         if (k < 0)
//         {
//             id[c] = j + 1; 
//             c++; 
//             i += v; 
//         }
//         else
//         {
//             int x = char_in_string(p[i], t);
//             if (x < 0)
//                 i = i + v;
//             else
//                 i = i + (v - x - 1);
//         }
//     }
//     return id;
// }

// string A4(string p, string t, string w)
// {
//     int c = 0;
//     int * x = A3(p, t, c);

//     if (c == 0)
//         return p;

//     for (int i = c - 1; i >= 0; i--)
//         p.replace(x[i], t.length(), w);

//     return p;
// }

// string A5(string p, string t, string w) 
// {
//     string new_str = "";
//     int n = t.length();
//     int m = p.length();
//     for (int i = 0; i < m; i++) 
//     {
//         int j = 0;
//         while (j < n && p[i + j] == t[j]) 
//             j++;
//         if (j == n) 
//         {
//             new_str += w;
//             i += n - 1;
//         }
//         else
//             new_str += p[i];
//     }
//     return new_str;
// }


// int main()
// {
//     string p = "I am a child, child and child";
//     string t = "child";
//     string w = "children";

//     int c = 0;
//     int * x = A3(p, t, c);

//     if (c > 0)
//     {
//         cout << "Tu '" << t << "' xuat hien tai cac vi tri: ";
//         for (int i = 0; i < c; i++)
//             cout << x[i] << " ";
//         cout << endl;
//     }
//     else
//         cout << "'" << t << "' khong la xau con cua p" << endl;
//     cout << "--------------------------------------------" << endl;

//     string result = A4(p, t, w);
//     string result2 = A5(p, t, w);
//     cout << "Chuoi sau thi thay '" << t << "' bang '" << w << "' la: " << result2 << endl;
// }