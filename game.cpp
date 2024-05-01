#include <bits/stdc++.h>
#include<windows.h>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
int st;
int lang;
map<char,char> rus;
string rusalphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
void autoperevvod(){
    string s;
    cout << "Пожалуйста, введите аёрАЁР" << endl;
    char x;
    cin >> x;
    for(int i = 0; i < 6; ++i){
        char y = (char)((int)x+i);
        rus[y] = rusalphabet[i];
    }
    for(int i = 7; i < 17; ++i){
        char y = (char)((int)x+i-1);
        rus[y] = rusalphabet[i];
    }
    cin >> x;
    rus[x] = rusalphabet[6];
    cin >> x;
    for(int i = 17; i < 33; ++i){
        char y = (char)((int)x+i-17);
        rus[y] = rusalphabet[i];
    }
    cin >> x;
    for(int i = 0+33; i < 33+6; ++i){
        char y = (char)((int)x+i-33);
        rus[y] = rusalphabet[i];
    }
    for(int i = 7+33; i < 17+33; ++i){
        char y = (char)((int)x+i-34);
        rus[y] = rusalphabet[i];
    }
    cin >> x;
    rus[x] = rusalphabet[33+6];
    cin >> x;
    for(int i = 17+33; i < 33+33; ++i){
        char y = (char)((int)x+i-50);
        rus[y] = rusalphabet[i];
    }
    getline(cin,s);
    rus[' '] = ' ';
    cout << "Введите что-то" << endl;
    getline(cin,s);
    for(int i = 0; i < s.size(); ++i){
        s[i] = rus[s[i]];
    }
    cout << "Вы ввели " << s << "? (напишите 0, если нет, и 1, если да)" << endl;
    bool boo;
    cin >> boo;
    getline(cin,s);
    if(boo) return;
    cout << "Передайте Максиму, что он лошара" << endl;
    while(true){
    cout << "Пожалуйста, введите абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ" << endl;

    getline(cin,s);
    for(int i = 0; i < s.size(); ++i){
        rus[s[i]] = rusalphabet[i];
    }
    cout << "Введите что-то" << endl;
    getline(cin,s);
    for(int i = 0; i < s.size(); ++i){
        s[i] = rus[s[i]];
    }
    cout << "Вы ввели " << s << "? (напишите 0, если нет, и 1, если да)" << endl;
    bool boo;
    cin >> boo;
    getline(cin,s);
    if(boo) return;
    }
}
string word(string s){
    string ans = s;
    for(int i = 0; i < ans.size(); ++i){
        ans[i] = rus[ans[i]];
    }
    return ans;
}
void morale_out (string s, int mp){
    cout << s;
    if(mp == 0){
            cout << "[    ]" << endl;
        }
        else if(mp == 1){
            cout << "[";
            cout << (char)4;
            cout << "   ]" << endl;
        }
        else if(mp == 2){
            cout << "[";
            SetConsoleTextAttribute(h, (((15 << 4) | 4)));
            cout << (char)4 << (char)4;
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
            cout << "  ]" << endl;
        }
        else if(mp == 3){
            cout << "[";
            SetConsoleTextAttribute(h, (((15 << 4) | 14)));
            cout << (char)4 << (char)4 << (char)4;
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
            cout << " ]" << endl;
        }
        else if(mp == 4){
            cout << "[";
            SetConsoleTextAttribute(h, (((15 << 4) | 2)));
            cout << (char)4 << (char)4 << (char)4 << (char)4;
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
            cout << "]" << endl;
        }
}
vector<int> miss_prob_gen(int morale){
    vector<int> ans(5, 1000 + 100*(4-morale));
    return ans;
}
vector<vector<int>> save_prob_gen(int moralesh, int moralegk){
    vector<vector<int>> ans(6, vector<int>(5));
    ans[0][0] = 7000;
    ans[0][1] = 2000;
    ans[0][2] = 250;
    ans[0][3] = 0;
    ans[0][4] = 0;
    ans[1][0] = 2000;
    ans[1][1] = 7000;
    ans[1][2] = 250;
    ans[1][3] = 0;
    ans[1][4] = 0;
    ans[2][0] = 250;
    ans[2][1] = 250;
    ans[2][2] = 8250;
    ans[2][3] = 250;
    ans[2][4] = 250;
    ans[3][0] = 0;
    ans[3][1] = 0;
    ans[3][2] = 250;
    ans[3][3] = 7000;
    ans[3][4] = 2000;
    ans[4][0] = 0;
    ans[4][1] = 0;
    ans[4][2] = 250;
    ans[4][3] = 2000;
    ans[4][4] = 7000;
    ans[5][0] = 1500;
    ans[5][1] = 1500;
    ans[5][2] = 10000;
    ans[5][3] = 1500;
    ans[5][4] = 1500;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            ans[i][j] = ans[i][j] + ans[i][j]*((moralegk-moralesh))/10;
            if(ans[i][j] < 0) ans[i][j] = 0;
            if(ans[i][j] > 10000) ans[i][j] = 10000;
        }
    }
    return ans;
}
int shoot (int sh, int gk, int msh, int mgk){
    //0 is save, 1 is goal and 2 is miss
    vector<int> miss_prob = miss_prob_gen(msh);
    vector<vector<int>> save_prob = save_prob_gen(msh,mgk);
     vector<int> num (10000);
     for(int i = 0; i < 10000; ++i){
        num[i] = i;
     }
     for(int i = 10000-1; i >-1; i--){
        int j = rand()%(i+1);
        swap(num[i],num[j]);
     }
     int x = rand()%10000;
     if(num[x] < save_prob[sh][gk]) return 0;
     int y = rand()%10000;
     if(num[y] < miss_prob[sh]) return 2;
     return 1;
}
int insh (){
    if(lang==1)cout << "It`s your shoot. Choose the angle - left down, left up, middle, right up, right down." << endl;
    if(lang==2)cout << "Ваш удар. Выбирайте угол - левый нижний, левый верхний, центр, правый верхний, правый нижний" << endl;
    string in;
    getline(cin, in); if(lang==2) in=word(in);
    if(in == "left down") return 0;
    if(in == "левый нижний") return 0;
    if(in == "left up") return 1;
    if(in == "левый верхний") return 1;
    if(in == "middle") {
        cout << "Panenka (morale +3/-3) or simple shot (morale +1/-1)? (type 1 or 2)" << endl;
        int pos;
        cin >> pos;
        pos%=2;
        getline(cin,in);
        return 2+3*pos;
    }
    if(in == "центр") {
        cout << "Паненка (мораль +3/-3) или обычный удар (мораль +1/-1)? (напишите 1 или 2)" << endl;
        int pos;
        cin >> pos;
        pos%=2;
        getline(cin,in);
        return 2+3*pos;
    }
    if(in == "right up") return 3;
    if(in == "правый верхний") return 3;
    if(in == "right down") return 4;
    if(in == "правый нижний") return 4;
    if(lang==1)cout << "Sorry I don`t know this word. Please try again." << endl;
    if(lang==2) cout << "Простите, я не знаю этого слова. Пожалуйста, попробуйте ещё раз" << endl;
    return insh();
}
int ingk(){
    if(lang==1)cout << "It`s your opponent`s shoot. Choose the angle - left down, left up, middle, right up, right down." << endl;
    if(lang==2)cout << "Удар Вашего соперника. Выбирайте угол - левый нижний, левый верхний, центр, правый верхний, правый нижний" << endl;
    string in;
    getline(cin, in); if(lang==2) in=word(in);
    if(in == "left down") return 0;
    if(in == "левый нижний") return 0;
    if(in == "left up") return 1;
    if(in == "левый верхний") return 1;
    if(in == "middle") {
        return 2;
    }
    if(in == "центр") {
        return 2;
    }
    if(in == "right up") return 3;
    if(in == "правый верхний") return 3;
    if(in == "right down") return 4;
    if(in == "правый нижний") return 4;
    if(lang==1)cout << "Sorry I don`t know this word. Please try again." << endl;
    if(lang==2) cout << "Простите, я не знаю этого слова. Пожалуйста, попробуйте ещё раз" << endl;
    return ingk();
}
void out_res (vector<vector<int>> res){
    if(lang==1)cout << "You            Computer       Result  Score" << endl;
    if(lang==2)cout << "Вы             Компьютер      Исход   Счёт" << endl;
    for(int i = 0; i < res.size(); ++i){
        if(lang==1){
        if(res[i][0] == 0) cout << "left down      ";
        if(res[i][0] == 1) cout << "left up        ";
        if(res[i][0] == 2) cout << "middle         ";
        if(res[i][0] == 3) cout << "right up       ";
        if(res[i][0] == 4) cout << "right down     ";
        if(res[i][0] == 5) cout << "panenka        ";
        if(res[i][1] == 0) cout << "left down      ";
        if(res[i][1] == 1) cout << "left up        ";
        if(res[i][1] == 2) cout << "middle         ";
        if(res[i][1] == 3) cout << "right up       ";
        if(res[i][1] == 4) cout << "right down     ";
        if(res[i][1] == 5) cout << "panenka        ";
        }
        else {
        if(res[i][0] == 0) cout << "левый нижний   ";
        if(res[i][0] == 1) cout << "левый верхний  ";
        if(res[i][0] == 2) cout << "центр          ";
        if(res[i][0] == 3) cout << "правый верхний ";
        if(res[i][0] == 4) cout << "правый нижний  ";
        if(res[i][0] == 5) cout << "паненка        ";
        if(res[i][1] == 0) cout << "левый нижний   ";
        if(res[i][1] == 1) cout << "левый верхний  ";
        if(res[i][1] == 2) cout << "центр          ";
        if(res[i][1] == 3) cout << "правый верхний ";
        if(res[i][1] == 4) cout << "правый нижний  ";
        if(res[i][1] == 5) cout << "паненка        ";
        }
        if(res[i][2] == 0){
            SetConsoleTextAttribute(h, (((15 << 4) | 4)));
            if(lang==1)cout << "Save!   "; if(lang==2) cout << "Сейв!   ";
        SetConsoleTextAttribute(h, (((15 << 4) | 0)));
        }
        if(res[i][2] == 1) {
            SetConsoleTextAttribute(h, (((15 << 4) | 2)));
            if(lang==1) cout << "GOAL!   "; if(lang==2) cout << "ГОЛ!    ";
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
        }
        if(res[i][2] == 2) {
            SetConsoleTextAttribute(h, (((15 << 4) | 4)));
            if(lang==1)cout << "Miss!   "; if(lang==2) cout << "Мимо!   ";
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
        }
        if(i < 10){
            int j = st;
            for(; j <= i; j+=2){
                if(res[j][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
            for(; j < 10; j+=2){
                cout << ".";
            }
            cout << "-";
            j = 1-st;
            for(; j <= i; j+=2){
                if(res[j][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
            for(; j < 10; j+=2){
                cout << ".";
            }
        }
        else {
            if(i%2==0 && st==0){
                if(res[i][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                cout << "-.";
            }
            else if(i%2==0&&st==1){
                cout << ".-";
                if(res[i][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
            else if (i%2!=0 && st == 0){
                if(res[i-1][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                cout << "-";
                if(res[i][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
            else if(i%2!=0 && st == 1){
                if(res[i][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                cout << "-";
                if(res[i-1][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
        }
        cout << "(" << res[i][3] << ":" << res[i][4] << ")" << endl;
    }
}
int insh2 (string name){
    if(lang==1)cout << name << ", it`s your shoot. Choose the angle - left down, left up, middle, right up, right down." << endl;
    if(lang==2)cout << name << ", Ваш удар. Выбирайте угол - левый нижний, левый верхний, центр, правый верхний, правый нижний" << endl;
    string in;
    getline(cin, in); if(lang==2) in=word(in);
    for(int i = 0; i < 100; ++i){
        cout << '.' << endl;
    }
    if(in == "left down") return 0;
    if(in == "левый нижний") return 0;
    if(in == "left up") return 1;
    if(in == "левый верхний") return 1;
    if(in == "middle") {
        cout << "Panenka (morale +3/-3) or simple shot (morale +1/-1)? (type 1 or 2)" << endl;
        int pos;
        cin >> pos;
        pos%=2;
        getline(cin,in);
        for(int i = 0; i < 100; ++i){
        cout << '.' << endl;
        }
        return 2+3*pos;
    }
    if(in == "центр") {
        cout << "Паненка (мораль +3/-3) или обычный удар (мораль +1/-1)? (напишите 1 или 2)" << endl;
        int pos;
        cin >> pos;
        pos%=2;
        getline(cin,in);
        return 2+3*pos;
    }
    if(in == "right up") return 3;
    if(in == "правый верхний") return 3;
    if(in == "right down") return 4;
    if(in == "правый нижний") return 4;
    if(lang==1)cout << "Sorry I don`t know this word. Please try again." << endl;
    if(lang==2) cout << "Простите, я не знаю этого слова. Пожалуйста, попробуйте ещё раз" << endl;
    return insh2(name);
}
int ingk2 (string name){
    if(lang==1)cout << name << ", it`s your opponent`s shoot. Choose the angle - left down, left up, middle, right up, right down." << endl;
    if(lang==2)cout << name << ", удар Вашего соперника. Выбирайте угол - левый нижний, левый верхний, центр, правый верхний, правый нижний" << endl;
    string in;
    getline(cin, in); if(lang==2) in=word(in);
    for(int i = 0; i < 100; ++i){
        cout << '.' << endl;
    }
    if(in == "left down") return 0;
    if(in == "левый нижний") return 0;
    if(in == "left up") return 1;
    if(in == "левый верхний") return 1;
    if(in == "middle") {
        cout << "Panenka (morale +3/-3) or simple shot (morale +1/-1)? (type 1 or 2)" << endl;
        int pos;
        cin >> pos;
        pos%=2;
        getline(cin,in);
        return 2+3*pos;
    }
    if(in == "центр") {
        cout << "Паненка (мораль +3/-3) или обычный удар (мораль +1/-1)? (напишите 1 или 2)" << endl;
        int pos;
        cin >> pos;
        pos%=2;
        getline(cin,in);
        return 2+3*pos;
    }
    if(in == "right up") return 3;
    if(in == "правый верхний") return 3;
    if(in == "right down") return 4;
    if(in == "правый нижний") return 4;
    if(lang==1)cout << "Sorry I don`t know this word. Please try again." << endl;
    if(lang==2) cout << "Простите, я не знаю этого слова. Пожалуйста, попробуйте ещё раз" << endl;
    return ingk2(name);
}
void out_res2 (vector<vector<int>> res, string p1, string p2){
    cout << p1;
    for(int i = 0; i < 15-p1.size(); ++i){
        cout << " ";
    }
    cout << p2;
    for(int i = 0; i < 15-p2.size(); ++i){
        cout << " ";
    }
    if(lang==1) cout << "Result  Score" << endl;
    if(lang==2) cout << "Исход   Счёт" << endl;
    for(int i = 0; i < res.size(); ++i){
        if(lang==1){
        if(res[i][0] == 0) cout << "left down      ";
        if(res[i][0] == 1) cout << "left up        ";
        if(res[i][0] == 2) cout << "middle         ";
        if(res[i][0] == 3) cout << "right up       ";
        if(res[i][0] == 4) cout << "right down     ";
        if(res[i][0] == 5) cout << "panenka        ";
        if(res[i][1] == 0) cout << "left down      ";
        if(res[i][1] == 1) cout << "left up        ";
        if(res[i][1] == 2) cout << "middle         ";
        if(res[i][1] == 3) cout << "right up       ";
        if(res[i][1] == 4) cout << "right down     ";
        if(res[i][1] == 5) cout << "panenka        ";
        }
        else {
        if(res[i][0] == 0) cout << "левый нижний   ";
        if(res[i][0] == 1) cout << "левый верхний  ";
        if(res[i][0] == 2) cout << "центр          ";
        if(res[i][0] == 3) cout << "правый верхний ";
        if(res[i][0] == 4) cout << "правый нижний  ";
        if(res[i][0] == 5) cout << "паненка        ";
        if(res[i][1] == 0) cout << "левый нижний   ";
        if(res[i][1] == 1) cout << "левый верхний  ";
        if(res[i][1] == 2) cout << "центр          ";
        if(res[i][1] == 3) cout << "правый верхний ";
        if(res[i][1] == 4) cout << "правый нижний  ";
        if(res[i][1] == 5) cout << "паненка        ";
        }
        if(res[i][2] == 0){
            SetConsoleTextAttribute(h, (((15 << 4) | 4)));
            if(lang==1)cout << "Save!   "; if(lang==2) cout << "Сейв!   ";
        SetConsoleTextAttribute(h, (((15 << 4) | 0)));
        }
        if(res[i][2] == 1) {
            SetConsoleTextAttribute(h, (((15 << 4) | 2)));
            if(lang==1) cout << "GOAL!   "; if(lang==2) cout << "ГОЛ!    ";
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
        }
        if(res[i][2] == 2) {
            SetConsoleTextAttribute(h, (((15 << 4) | 4)));
            if(lang==1) cout << "Miss!   "; if(lang==2) cout << "Мимо!   ";
            SetConsoleTextAttribute(h, (((15 << 4) | 0)));
        }
        if(i < 10){
            int j = 0;
            for(; j <= i; j+=2){
                if(res[j][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
            for(; j < 10; j+=2){
                cout << ".";
            }
            cout << "-";
            j = 1;
            for(; j <= i; j+=2){
                if(res[j][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
            for(; j < 10; j+=2){
                cout << ".";
            }
        }
        else {
            if(i%2==0){
                if(res[i][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                cout << "-.";
            }
            else{
                if(res[i-1][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                cout << "-";
                if(res[i][2] == 1){
                    SetConsoleTextAttribute(h, (((15 << 4) | 2)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
                else {
                    SetConsoleTextAttribute(h, (((15 << 4) | 4)));
                    cout << (char)4;
                    SetConsoleTextAttribute(h, (((15 << 4) | 0)));
                }
            }
        }
        cout << "(" << res[i][3] << ":" << res[i][4] << ")" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    system("color F0");
    string in;
    cout << "Choose the language - English (type 1) or Русский (напишите 2)" << endl;
    cin >> lang;
    getline(cin,in);
    if(lang==2) autoperevvod();
    while(true){
    if(lang==1){cout << "So, the whistle is blown, which means that 120 minutes of boring football have ended and the result is 1:1. It`s time for the penalty shootout!" << endl;
    cout << "Would you like to play with a piece of iron without a soul or with a piece of blood and meat which probably doesn`t have a soul too? (type 1 or 2)" << endl;}
    if(lang==2){
        cout << "Итак, прозвучал свисток, что означает, что 120 минут скучного футбола подошли к концу, и счет 1:1. Время серии пенальти!" << endl;
        cout << "Вы бы хотели сыграть с бездушной железякой или с куском плоти и крови, у которого, скорее всего, тоже нет души? (напишите 1 или 2)" << endl;
    }
    string numpls;
    getline(cin, numpls);
    int numpl = stoi(numpls);
    if(numpl==1){
    int x;
    while(true){
    if(lang==1) cout << "Drawing procedure. Choose - heads or tails" << endl;
    if(lang==2) cout << "Жеребьевка. Выбирайте - орёл или решка" << endl;
    getline(cin, in); if(lang==2) in=word(in);
    if(in == "heads" || in == "орёл") {x = 0; break;}
    else if(in == "tails" || in == "решка") {x = 1; break;}
    else {if(lang==1)cout << "Sorry I don`t know this word. Please try again." << endl;
    if(lang==2) cout << "Простите, я не знаю этого слова. Пожалуйста, попробуйте ещё раз." << endl;
    }
    }
    int y = (rand()%1000000000)%2;
    if(x==y){
        if(lang==1) cout << "You`ve won the draw. Choose would you like to shoot first or second (type 1 or 2)" << endl;
        if(lang==2) cout << "Вы выиграли жеребьевку. Выбирайте, Вы хотите бить первыми или вторыми (напишите 1 или 2)" << endl;
        string in;
        getline(cin,in);
        st = stoi(in);
        st--;
    }
    else{
        st = (rand()%1000000000)%2;
        if(lang==1) cout << "You`ve lost the draw. You shoot " << st+1 << endl;
        if(lang==2) cout << "Вы проиграли жеребьевку. Вы бьёте " << st+1 << endl;
    }
    vector<vector<int>> res;
    int gp = 0;
    int gc = 0;
    int slp = 5;
    int slc = 5;
    int t = 0;
    int mp = 4;
    int mc = 4;
    while(gp+slp >= gc && gc+slc >= gp){
        if(slp == 0 && slc == 0){slp++; slc++;}
        if(lang==1){
        morale_out("Your morale is ", mp);
        morale_out("Your opponent`s morale is ", mc);
        }
        if(lang==2){
        morale_out("Ваша мораль ", mp);
        morale_out("Мораль Вашего соперника ", mc);
        }
        if((t+st)%2==0){
            int sh = insh();
            int gk = rand()%5;
            int r = shoot(sh,gk,mp,mc);
            if(r==1) {gp++;
                mp = min(4, mp+1);
                mc = max(0, mc-1);
                if(sh == 5){
                    mp = min(4, mp+2);
                    mc = max(0, mc-2);
                }
            }
            else {
                mc = min(4, mc+1);
                mp = max(0, mp-1);
                if(sh == 5){
                    mc = min(4, mc+2);
                    mp = max(0, mp-2);
                }
            }
            vector<int> temp(5);
            temp[0] = sh;
            temp[1] = gk;
            temp[2] = r;
            temp[3] = gp;
            temp[4] = gc;
            res.push_back(temp);
            out_res(res);
            slp--;
        }
        else {
            int sh = rand()%5;
            int gk = ingk();
            if(sh==2) sh = 2+3*(rand()%1000000000)%2;
            int r = shoot(sh,gk,mc,mp);
            if(r==1) {gc++;
                mc = min(4, mc+1);
                mp = max(0, mp-1);
                if(sh == 5){
                    mc = min(4, mc+2);
                    mp = max(0, mp-2);
                }
            }
            else {
                mp = min(4, mp+1);
                mc = max(0, mc-1);
                if(sh == 5){
                    mp = min(4, mp+2);
                    mc = max(0, mc-2);
                }
            }
            vector<int> temp(5);
            temp[0] = gk;
            temp[1] = sh;
            temp[2] = r;
            temp[3] = gp;
            temp[4] = gc;
            res.push_back(temp);
            out_res(res);
            slc--;
        }
        t++;
    }
    if(gp > gc){
        if(lang==1)cout << "Congratulations! You won!" << endl;
        if(lang==2)cout << "Поздравляю с победой!" << endl;
    }
    else{
    if(lang==1) cout << "You lost :(" << endl;
    if(lang==2) cout << "Пластмассовый мир победил :(" << endl;
    }}
    else {
        if(lang==1)cout << "I`m disappointed of you, little human. You`re just scared to play with me." << endl;
        if(lang==2) cout << "Я разочарован в тебе, маленький человечек. Ты просто боишься играть со мной" << endl;
        string p1, p2;
        if(lang==1) cout << "Write the name of the first nonentity" << endl;
        if(lang==2) cout << "Напишите имя первого ничтожества" << endl;
        getline(cin,p1); if(lang==2) p1=word(p1);
        if(lang==1) cout << "Write the name of the second nonentity" << endl;
        if(lang==2) cout << "Напишите имя второго ничтожества" << endl;
        getline(cin,p2); if(lang==2) p2=word(p2);
        int x;
        while(true){
            if(lang==1) cout << "Drawing procedure. " << p1 << ", choose - heads or tails" << endl;
            if(lang==2) cout << "Жеребьёвка. " << p1 << ", выбирайте - орёл или решка" << endl;
            string in;
            getline(cin, in); if(lang==2) in=word(in);
            if(in == "heads" || in == "орёл") {x = 0; break;}
            else if(in == "tails" || in == "решка") {x = 1; break;}
            else {if(lang==1)cout << "Sorry I don`t know this word. Please try again." << endl;
            if(lang==2) cout << "Простите, я не знаю этого слова. Пожалуйста, попробуйте ещё раз." << endl;
    }
        }
        int y = (rand()%1000000000)%2;
        int st;
        if(x==y){
        if(lang==1)cout << p1 << " won the draw. " << p1 << ", choose would you like to shoot first or second (type 1 or 2)" << endl;
        if(lang==2) cout << p1 << " выиграл(-а) жеребьёвку. " << p1 << ", выбирайте, вы бы хотели бить первыми или вторыми (напишите 1 или 2)" << endl;
        string in;
        getline(cin,in);
        st = stoi(in);
        if(st==2) swap(p1,p2);
        }
        else {
        if(lang==1)cout << p2 << " won the draw. " << p2 << ", choose would you like to shoot first or second (type 1 or 2)" << endl;
        if(lang==2) cout << p2 << " выиграл(-а) жеребьёвку. " << p2 << ", выбирайте, вы бы хотели бить первыми или вторыми (напишите 1 или 2)" << endl;
        string in;
        getline(cin,in);
        st = stoi(in);
        if(st==1) swap(p1,p2);
        }
        vector<vector<int>> res;
    int g1 = 0;
    int g2 = 0;
    int sl1 = 5;
    int sl2 = 5;
    int t = 0;
    int m1 = 4;
    int m2 = 4;
    while(g1+sl1 >= g2 && g2+sl2 >= g1){
        if(sl1 == 0 && sl2 == 0){sl1++; sl2++;}
        cout << p1;
        if(lang==1)morale_out("`s morale is ", m1);
        if(lang==2)morale_out(" - мораль ", m1);
        cout << p2;
        if(lang==1)morale_out("`s morale is ", m2);
        if(lang==2)morale_out(" - мораль ", m2);
        if((t)%2==0){
            int sh = insh2(p1);
            out_res2(res,p1,p2);
            cout << p1;
            if(lang==1)morale_out("`s morale is ", m1);
            if(lang==2)morale_out(" - мораль ", m1);
            cout << p2;
            if(lang==1)morale_out("`s morale is ", m2);
            if(lang==2)morale_out(" - мораль ", m2);
            int gk = ingk2(p2);
            int r = shoot(sh,gk,m1,m2);
            if(r==1) {g1++;
                m1 = min(4, m1+1);
                m2 = max(0, m2-1);
                if(sh == 5){
                    m1 = min(4, m1+2);
                    m2 = max(0, m2-2);
                }
            }
            else {
                m2 = min(4, m2+1);
                m1 = max(0, m1-1);
                if(sh == 5){
                    m2 = min(4, m2+2);
                    m1 = max(0, m1-2);
                }
            }
            vector<int> temp(5);
            temp[0] = sh;
            temp[1] = gk;
            temp[2] = r;
            temp[3] = g1;
            temp[4] = g2;
            res.push_back(temp);
            out_res2(res,p1,p2);
            sl1--;
        }
        else {
            int sh = insh2(p2);
            out_res2(res,p1,p2);
            cout << p1;
            if(lang==1)morale_out("`s morale is ", m1);
            if(lang==2)morale_out(" - мораль ", m1);
            cout << p2;
            if(lang==1)morale_out("`s morale is ", m2);
            if(lang==2)morale_out(" - мораль ", m2);
            int gk = ingk2(p1);
            int r = shoot(sh,gk,m2,m1);
            if(r==1) {g2++;
                m2 = min(4, m2+1);
                m1 = max(0, m1-1);
                if(sh == 5){
                    m2 = min(4, m2+2);
                    m1 = max(0, m1-2);
                }
            }
            else {
                m1 = min(4, m1+1);
                m2 = max(0, m2-1);
                if(sh == 5){
                    m1 = min(4, m1+2);
                    m2 = max(0, m2-2);
                }
            }
            vector<int> temp(5);
            temp[0] = gk;
            temp[1] = sh;
            temp[2] = r;
            temp[3] = g1;
            temp[4] = g2;
            res.push_back(temp);
            out_res2(res,p1,p2);
            sl2--;
        }
        t++;
    }
    if(g1 > g2){
        if(lang==1)cout << p1 << " won!" << endl;
        if(lang==2) cout << p1 << ", с победой!" << endl;
    }
    else{
    if(lang==1)cout << p2 << " won!" << endl;
    if(lang==2) cout << p2 << ", с победой!" << endl;
    }
    }
    if(lang==1) cout << "Play again? (type 0 if no and 1 if yes)" << endl;
    if(lang==2) cout << "Играть ещё? (напишите 0, если нет, и 1, если да)" << endl;
    int pag;
    cin >> pag;
    if(pag==0) return 0;
    getline(cin,in);
    }
}

