#include <iostream>
using namespace std;

string s ="child 3 years old bigger than child 1 year old";
string word = "child";
string add ="ren";

int A3(string s, string word){
	int dem = 0;
	int n = word.length();
	int m = s.length() - n;
	for(int i = 0; i <= m; i++){
		int j = 0;
		while(j < n && s[i+j] == word[j]){
			j++;
		}
		if(j == n)	dem++;
	}
	return dem;
}

string A4(string s, string word, string& news) {
    int dem = 0;
    int n = word.length();
    int m = s.length() - n;
    for (int i = 0; i <= m; i++) {
        int j = 0;
        while (j < n && s[i + j] == word[j]) {
            j++;
        }
        if (j == n) {
            news += "children";
            i+=4;
        }
        else{
            news += s[i];
        }
    }
    return news;
}




int main(){
	cout<<A3(s, word)<<endl;
	string news = "";
	cout<<A4(s, word, news);
	return 0;
}
