#include <bits/stdc++.h>
using namespace std;

int n;

// các cách di chuyển của quân mã
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// hàm hiển thị kết quả cuối cùng
void show(int ** x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << x[i][j] << "\t";
        }
        cout << endl;
    }
}

// hàm kiểm tra xem một bước đi có hợp lệ không
bool check_step(int x, int y, int ** board)
{
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1);
}

// hàm kiểm tra xem bàn cờ đã đầy hay chưa
bool check_board_full(int ** board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] == -1)
                return false;
        }
    }
    return true;
}

// thuật toán quay lui tìm nước đi cho quân mã ở bước thứ k
bool Try(int k, int x, int y, int ** board)
{
    for (int i = 0; i < 8; i++)
    {
        // chọn nước đi tiếp theo cho quân mã
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(check_step(next_x, next_y, board))
        {
            board[next_x][next_y] = k;
            // nếu quân mã đã đi qua tất cả các ô
            if(k == n*n - 1)
                return true;
            
            // nếu bàn cờ chưa kín thì tiếp tục đệ quy đến bước tiếp theo
            if(!check_board_full(board))
            {
                if(Try(k + 1, next_x, next_y, board))
                {
                    return true; // trường hợp tìm thấy lời giải
                }
                // nếu không tìm thấy lời giải thì xóa nước này đi
                board[next_x][next_y] = -1;
            }
            else
                return true; // trả về true nếu bàn cờ đã kín
        }
    }
    return false; // không tìm được nước đi hoặc không có nước đi hợp lệ
}

int main()
{
    cout << "Nhap so chieu cua ban co: "; cin >> n;
    int ** board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int [n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = -1;
        }
    }
    board[0][0] = 0; // bắt đầu từ ô đầu tiên trong bàn cờ tức ô [0][0]
    
    if(Try(1, 0, 0, board))
        show(board);
    else
        cout << "Khong tim duoc duong di." << endl;
}