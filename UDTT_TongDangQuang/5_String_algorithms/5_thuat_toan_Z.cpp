// Thuật toán này được sử dụng để đếm số lần xuất hiện cũng như xác định
// các vị trí xuất hiện của một xâu con P trong một xâu T.
// s = "dang$tongdangquangdang"
#include <bits/stdc++.h>
using namespace std;

void Z_algorithm (char * s, int * z)
{
    int n = strlen(s);
    int left = 0, right = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > right)
        {
            left = right = i;
            // trường hợp tìm thấy ký tự khớp với tiền tố s
            while(right < n && s[right - left] == s[right])
                right++; // tăng right để tạo ra vị trí của xâu con 
            z[i] = right - left; // z[i] = right - left là số ký tự xâu cha khớp với xâu con 
            right--; // trừ right đi 1 để đảm bảo đúng vị trí index (ví dụ như chuỗi có 20 kí tự nhưng index cuối cùng là 19) và trả lại 1 lần lặp thừa của vòng while bên trên
        }

        // trường hợp tìm được xâu con trước đó thì các vị trí còn lại trong khoảng [left, right] của z bằng 0
        else if (z[i - left] < right - i + 1)
            z[i] = z[i - left]; // gán các z[i] = 0 (ngoài z[left] ra)
            
        // trường hợp khác
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

int Z_apply (char * t, char * p)
{
    // tạo xâu mới s
    int p_size = strlen(p);
    int t_size = strlen(t);
    char s[p_size + t_size + 2];
    strcpy(s, p); // Sao chép nội dung của p vào s
    strcat(s, "$"); // Thêm ký tự phân tách $ vào sau p
    strcat(s, t); // Thêm chuỗi t vào sau $
    int n = strlen(s);
    int * z = new int [n]();

    Z_algorithm(s, z);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if(z[i] == p_size)
            cnt++;
    }
    return cnt;
}

int main()
{
    char t[] = "tongdangquangdang";
    char p[] = "dang";
    int result = Z_apply(t, p);
    cout << "Result: " << result << endl;
}


// void Z_algorithm (string s, int * z)
// {
//     int n = s.length();
//     int left = 0, right = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if (i > right)
//         {
//             left = right = i;
//             // trường hợp tìm thấy ký tự khớp với tiền tố s
//             while(right < n && s[right - left] == s[right])
//                 right++; // tăng right để tạo ra vị trí của xâu con 
//             z[i] = right - left; // z[i] = right - left là số ký tự xâu cha khớp với xâu con 
//             right--; // trừ right đi 1 để đảm bảo đúng vị trí index (ví dụ như chuỗi có 20 kí tự nhưng index cuối cùng là 19) và trả lại 1 lần lặp thừa của vòng while bên trên
//         }

//         // trường hợp tìm được xâu con trước đó thì các vị trí còn lại trong khoảng [left, right] của z bằng 0
//         else if (z[i - left] < right - i + 1)
//             z[i] = z[i - left]; // gán các z[i] = 0 (ngoài z[left] ra)
            
//         // trường hợp khác
//         else
//         {
//             left = i;
//             while(right < n && s[right - left] == s[right])
//                 right++;
//             z[i] = right - left;
//             right--;
//         }
//     }
// }

// int Z_apply (string t, string p)
// {
//     // tạo xâu mới s
//     int p_size = p.length();
//     int t_size = p.length();
//     string s = p + "$" + t;
//     int n = s.length();
//     int * z = new int [n]();

//     Z_algorithm(s, z);
//     int cnt = 0;
//     for (int i = 1; i < n; i++)
//     {
//         if(z[i] == p_size)
//             cnt++;
//     }
//     return cnt;
// }

// int main()
// {
//     string t = "tongdangquangdan";
//     string p = "dangv";
//     int result = Z_apply(t, p);
//     cout << "Result: " << result << endl;
// }
