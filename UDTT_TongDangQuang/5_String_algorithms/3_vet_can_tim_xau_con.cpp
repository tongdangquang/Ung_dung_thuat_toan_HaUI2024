// BÀI TOÁN: Tìm xâu con 
// - Cho 2 xâu ký tự T, và P chỉ gồm các ký tự {‘0’ ... ’9’, ‘a’ ... ’z’, ’A’ ... ’Z’}. 
// - Kiểm tra xem P có phải là một xâu con của T hay không?

// PHƯƠNG PHÁP VÉT CẠN:
// Duyệt xâu T bắt đầu từ T[0] đến T[strlen(T) – strlen(P)]. 
// - Với mỗi T[i]: 
// + So sánh P với xâu con của T bắt đầu từ T[i], nếu vượt qua được xâu P thì dừng thuật toán và trả về i (trường hợp P là xâu con của T). 
// + Nếu không vượt qua được xâu P thì kiểm tra i:
//      Nếu i ≤ strlen(T) – strlen(P) thì tiếp tục so sánh P với xâu con của xâu T bắt đầu từ T[i + 1]. 
//      Ngược lại, dừng thuật toán và trả về -1 (trường hợp P không là xâu con của T). 

#include <bits/stdc++.h>
using namespace std;

int index_of(char * t, char * p)
{
    int m = strlen(p);
    int n = strlen(t) - m;
    for (int i = 0; i <= n; i++)
    {
        int j = 0;
        while(j < m && t[i + j] == p[j])
            j++;
        if(j == m)
            return i;
    }
    return -1;
}

int main()
{
    char t[] = "tongdangquang";
    char p[] = "dang";
    int result = index_of(t, p);
    if(result != -1)
        cout << "'" << p  << "'" << " la xau con cua " << "'" << t << "'" << " tai " << result << endl;
    else
        cout << "'" << p  << "'" << " khong la xau con cua " << "'" << t << "'" << endl;
}