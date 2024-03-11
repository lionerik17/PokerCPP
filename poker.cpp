#include <bits/stdc++.h>
using namespace std;

//Texas Hold'em Poker game (Aces High)
//Fully operational (finally)

char cards[100][100]=
{"S_2","S_3","S_4","S_5","S_6","S_7","S_8","S_9","S_10","S_J","S_Q","S_K","S_A",
"C_2","C_3","C_4","C_5","C_6","C_7","C_8","C_9","C_10","C_J","C_Q","C_K","C_A",
"D_2","D_3","D_4","D_5","D_6","D_7","D_8","D_9","D_10","D_J","D_Q","D_K","D_A",
"H_2","H_3","H_4","H_5","H_6","H_7","H_8","H_9","H_10","H_J","H_Q","H_K","H_A"};

char deck[100][100],player_cards[100][100],comp_cards[100][100];
char game[10],op[10];
int app[52];
int k1,k2,k3;

void generate_flop()
{
    int i=1;
    while(i<=3)
    {
        int alfa=rand()%52,beta=rand()%52;
        while(alfa!=beta) alfa=rand()%52;
        if(app[alfa]==0)
        {
            app[alfa]=1;
            strcat(deck[k1],cards[alfa]);
            strcat(deck[k1]," ");
            ++k1;
            ++i;
        }
    }
}

void generate_player_cards()
{
    int i=1;
    while(i<=2)
    {
        int alfa=rand()%52,beta=rand()%52;
        while(alfa!=beta) alfa=rand()%52;
        if(app[alfa]==0)
        {
            app[alfa]=1;
            strcat(player_cards[k2],cards[alfa]);
            strcat(player_cards[k2]," ");
            ++k2;
            ++i;
        }
    }
}

void generate_comp_cards()
{
    int i=1;
    while(i<=2)
    {
        int alfa=rand()%52,beta=rand()%52;
        while(alfa!=beta) alfa=rand()%52;
        if(app[alfa]==0)
        {
            app[alfa]=1;
            strcat(comp_cards[k3],cards[alfa]);
            strcat(comp_cards[k3]," ");
            ++k3;
            ++i;
        }
    }
}

void generate_new_card()
{
    int alfa=rand()%52,beta=rand()%52;
    while(alfa!=beta) alfa=rand()%52;
    int i=1;
    while(i<=1)
    {
        int alfa=rand()%52,beta=rand()%52;
        while(alfa!=beta) alfa=rand()%52;
        if(app[alfa]==0)
        {
            app[alfa]=1;
            strcat(deck[k1],cards[alfa]);
            strcat(deck[k1]," ");
            ++k1;
            ++i;
        }
    }
}

void fix()
{
    for(int i=0;i<52;++i)
    {
        strcat(cards[i]," ");
    }
}

void init(int app[52], char rez[100][100], int k)
{
    for(int i=0;i<k;++i)
    {
        int poz=0,ok=0;
        for(int j=0;j<52&&!ok;++j)
        {
            if(strcmp(rez[i],cards[j])==0) ok=1;
            else ++poz;
        }
        app[poz]=1;
    }
}

void count_numlet(char s[100][100], int k, int numbers[9], int letters[4])
{
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
        {
            if(s[i][j]=='2') ++numbers[0];
            if(s[i][j]=='3') ++numbers[1];
            if(s[i][j]=='4') ++numbers[2];
            if(s[i][j]=='5') ++numbers[3];
            if(s[i][j]=='6') ++numbers[4];
            if(s[i][j]=='7') ++numbers[5];
            if(s[i][j]=='8') ++numbers[6];
            if(s[i][j]=='9') ++numbers[7];
            if(s[i][j]=='0') ++numbers[8];
            if(s[i][j]=='J') ++letters[0];
            if(s[i][j]=='Q') ++letters[1];
            if(s[i][j]=='K') ++letters[2];
            if(s[i][j]=='A') ++letters[3];
        }
    }
}

int joker(int n)
{
    if(n==9&&n==22&&n==35&&n==48) return 1;
    return 0;
}

int main()
{
    cout<<"Would you like to play a game of Texas Hold'em Poker?(y/n) "; cin>>op;
    if(strcmp(op,"y")==0) cout<<'\n';
    srand((unsigned)time(0));
    while(strcmp(op,"n"))
    {
        generate_flop();
        generate_player_cards();
        generate_comp_cards();

        cout<<"The current cards are: ";
        for(int i=0;i<k1;++i) cout<<deck[i]; cout<<'\n';
        cout<<"These are your cards: ";
        for(int i=0;i<k2;++i) cout<<player_cards[i]; cout<<'\n';

        cout<<'\n'<<"Would you like to continue?(y/n) "; cin>>game; cout<<'\n';
        if(strcmp(game,"y")==0) generate_new_card();
        else if(strcmp(game,"n")==0) break;

        cout<<"The current cards are: ";
        for(int i=0;i<k1;++i) cout<<deck[i]; cout<<'\n';
        cout<<"These are your cards: ";
        for(int i=0;i<k2;++i) cout<<player_cards[i]; cout<<'\n';

        cout<<'\n'<<"Would you like to continue?(y/n) "; cin>>game; cout<<'\n';
        if(strcmp(game,"y")==0) generate_new_card();
        else if(strcmp(game,"n")==0) break;

        cout<<"The current cards are: ";
        for(int i=0;i<k1;++i) cout<<deck[i]; cout<<'\n';
        cout<<"These are your cards: ";
        for(int i=0;i<k2;++i) cout<<player_cards[i]; cout<<'\n';
        cout<<"These are computer's cards: ";
        for(int i=0;i<k3;++i) cout<<comp_cards[i]; cout<<'\n';

        fix(); cout<<'\n';

        int k=0,l=0;
        char t1[100][100]={0},t2[100][100]={0};
        for(int i=0;i<k2;++i)
        {
            strcpy(t1[k],player_cards[i]);
            ++k;
        }
        for(int i=0;i<k1;++i)
        {
            strcpy(t1[k],deck[i]);
            ++k;
        }

        for(int i=0;i<k3;++i)
        {
            strcpy(t2[l],comp_cards[i]);
            ++l;
        }
        for(int i=0;i<k1;++i)
        {
            strcpy(t2[l],deck[i]);
            ++l;
        }

        int app1[52]={0},app2[52]={0};
        int numbers_player[9]={0},letters_player[4]={0},numbers_comp[9]={0},letters_comp[4]={0};

        init(app1,t1,k);
        init(app2,t2,l);

        count_numlet(t1,k,numbers_player,letters_player);
        count_numlet(t2,l,numbers_comp,letters_comp);

        int high_player=0,high_comp=0;
        int high=0,highest1=0,highest2=0;
        for(int i=0;i<k;++i)
        {
            for(int j=0;j<k;++j)
            {
                if(player_cards[i][j]=='A') {high=13;}
                if(player_cards[i][j]=='K') {high=12;}
                if(player_cards[i][j]=='Q') {high=11;}
                if(player_cards[i][j]=='J') {high=10;}
                if(player_cards[i][j]=='0') {high=9;}
                if(player_cards[i][j]=='9') {high=8;}
                if(player_cards[i][j]=='8') {high=7;}
                if(player_cards[i][j]=='7') {high=6;}
                if(player_cards[i][j]=='6') {high=5;}
                if(player_cards[i][j]=='5') {high=4;}
                if(player_cards[i][j]=='4') {high=3;}
                if(player_cards[i][j]=='3') {high=2;}
                if(player_cards[i][j]=='2') {high=1;}
            }
            if(highest1<high) highest1=high;
        }
        for(int i=0;i<l;++i)
        {
            for(int j=0;j<l;++j)
            {
                if(comp_cards[i][j]=='A') {high=13;}
                if(comp_cards[i][j]=='K') {high=12;}
                if(comp_cards[i][j]=='Q') {high=11;}
                if(comp_cards[i][j]=='J') {high=10;}
                if(comp_cards[i][j]=='0') {high=9;}
                if(comp_cards[i][j]=='9') {high=8;}
                if(comp_cards[i][j]=='8') {high=7;}
                if(comp_cards[i][j]=='7') {high=6;}
                if(comp_cards[i][j]=='6') {high=5;}
                if(comp_cards[i][j]=='5') {high=4;}
                if(comp_cards[i][j]=='4') {high=3;}
                if(comp_cards[i][j]=='3') {high=2;}
                if(comp_cards[i][j]=='2') {high=1;}
            }
            if(highest2<high) highest2=high;
        }
        if(highest1>highest2) high_player=1;
        else if(highest1<highest2) high_comp=1;

        //royal flush, working (good luck getting this)
        int r_player=0,r_comp=0;
        for(int i=0;i<52;i+=13)
        {
            if(app1[i+8]&&app1[i+9]&&app1[i+10]&&app1[i+11]&&app1[i+12]) r_player=1;
            if(app2[i+8]&&app2[i+9]&&app2[i+10]&&app2[i+11]&&app2[i+12]) r_comp=1;
        }
        if(r_player==1&&r_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by royal flush"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by royal flush"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(r_player)
        {
            cout<<"Player wins by royal flush"; break;
        }
        else if(r_comp)
        {
            cout<<"Computer wins by royal flush"; break;
        }
        //straight flush, working
        int sf_player=0,sf_comp=0;
        for(int i=0;i<52;++i)
        {
            if(!joker(i))
            {
                if(app1[i]&&app1[i+1]&&app1[i+2]&&app1[i+3]&&app1[i+4]) sf_player=1;
                if(app2[i]&&app2[i+1]&&app2[i+2]&&app2[i+3]&&app2[i+4]) sf_comp=1;
            }
        }
        if(sf_player==1&&sf_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by straight flush"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by straight flush"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(sf_player)
        {
            cout<<"Player wins by straight flush"; break;
        }
        else if(sf_comp)
        {
            cout<<"Computer wins by straight flush"; break;
        }
        //four of a kind, working
        int four_player=0,four_comp=0;
        for(int i=0;i<9;++i)
        {
            if(numbers_player[i]>=4) four_player=1;
            if(numbers_comp[i]>=4) four_comp=1;
        }
        for(int i=0;i<4;++i)
        {
            if(letters_player[i]>=4) four_player=1;
            if(letters_comp[i]>=4) four_comp=1;
        }
        if(four_player==1&&four_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by four of a kind"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by four of a kind"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(four_player)
        {
            cout<<"Player wins by four of a kind"; break;
        }
        else if(four_comp)
        {
            cout<<"Computer wins by four of a kind"; break;
        }
        //full house, working
        int full_player=0,full_comp=0;
        int var1_p=0,var2_p=0,var3_p=0,var1_c=0,var2_c=0,var3_c=0;
        for(int i=0;i<9;++i)
        {
            for(int j=i+1;j<9;++j)
            {
                if((numbers_player[i]==3&&numbers_player[j]==2)||(numbers_player[i]==2&&numbers_player[j]==3)) var1_p=1;
                if((numbers_comp[i]==3&&numbers_comp[j]==2)||(numbers_comp[i]==2&&numbers_comp[j]==3)) var1_c=1;
            }
        }
        for(int i=0;i<4;++i)
        {
            for(int j=i+1;j<4;++j)
            {
                if((letters_player[i]==3&&letters_player[j]==2)||(letters_player[i]==2&&letters_player[j]==3)) var2_p=1;
                if((letters_comp[i]==3&&letters_comp[j]==2)||(letters_comp[i]==2&&letters_comp[j]==3)) var2_c=1;
            }
        }
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<4;++j)
            {
                if((numbers_player[i]==3&&letters_player[j]==2)||(numbers_player[i]==2&&letters_player[j]==3)) var3_p=1;
                if((numbers_comp[i]==3&&letters_comp[j]==2)||(numbers_comp[i]==2&&letters_comp[j]==3)) var3_c=1;
            }
        }
        if(var1_p==1||var2_p==1||var3_p==1) full_player=1;
        if(var1_c==1||var2_c==1||var3_c==1) full_comp=1;
        if(full_player==1&&full_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by full house"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by full house"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(full_player)
        {
            cout<<"Player wins by full house"; break;
        }
        else if(full_comp)
        {
            cout<<"Computer wins by full house"; break;
        }
        //flush, working
        int flush_player=0,flush_comp=0;
        int S1=0,H1=0,D1=0,C1=0,S2=0,H2=0,D2=0,C2=0;
        for(int i=0;i<k;++i)
        {
            for(int j=0;j<k;++j)
            {
                if(t1[i][j]=='S') ++S1;
                if(t1[i][j]=='H') ++H1;
                if(t1[i][j]=='D') ++D1;
                if(t1[i][j]=='C') ++C1;
            }
        }
        for(int i=0;i<k;++i)
        {
            for(int j=0;j<k;++j)
            {
                if(t2[i][j]=='S') ++S2;
                if(t2[i][j]=='H') ++H2;
                if(t2[i][j]=='D') ++D2;
                if(t2[i][j]=='C') ++C2;
            }
        }
        if(S1>=5||H1>=5||D1>=5||C1>=5) flush_player=1;
        if(S2>=5||H2>=5||D2>=5||C2>=5) flush_comp=1;
        if(flush_player==1&&flush_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by flush"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by flush"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(flush_player)
        {
            cout<<"Player wins by flush"; break;
        }
        else if(flush_comp)
        {
            cout<<"Computer wins by flush"; break;
        }
        //straight, working
        int straight_player=0, straight_comp=0;
        int oks_p=0,oks_c=0;
        for(int i=0;i<9;++i)
        {
            if(numbers_player[i]==1&&numbers_player[i+1]==1&&numbers_player[i+2]==1&&numbers_player[i+3]==1&&numbers_player[i+4]==1) oks_p=1;
            else if(numbers_comp[i]==1&&numbers_comp[i+1]==1&&numbers_comp[i+2]==1&&numbers_comp[i+3]==1&&numbers_comp[i+4]==1) oks_c=1;
        }
        if(numbers_player[8]==1&&letters_player[0]==1&&letters_player[1]==1&&letters_player[2]==1&&letters_player[3]==1) oks_p=1;
        else if(numbers_comp[8]==1&&letters_comp[0]==1&&letters_comp[1]==1&&letters_comp[2]==1&&letters_comp[3]==1) oks_c=1;
        if(oks_p) straight_player=1;
        else if(oks_c) straight_comp=1;
        if(straight_player==1&&straight_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by straight"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by straight"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(straight_player)
        {
            cout<<"Player wins by straight"; break;
        }
        else if(straight_comp)
        {
            cout<<"Computer wins by straight"; break;
        }
        //three of a kind, working
        int three_player=0,three_comp=0;
        for(int i=0;i<9;++i)
        {
            if(numbers_player[i]>=3) three_player=1;
            if(numbers_comp[i]>=3) three_comp=1;
        }
        for(int i=0;i<4;++i)
        {
            if(letters_player[i]>=3) three_player=1;
            if(letters_comp[i]>=3) three_comp=1;
        }
        if(three_player==1&&three_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by three of a kind"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by three of a kind"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(three_player)
        {
            cout<<"Player wins by three of a kind"; break;
        }
        else if(three_comp)
        {
            cout<<"Computer wins by three of a kind"; break;
        }
        //two pair, working
        int two_player=0,two_comp=0;
        int ok2_np=0,ok2_nc=0,ok2_lp=0,ok2_lc=0;
        for(int i=0;i<9;++i)
        {
            if(numbers_player[i]>=2) ++ok2_np;
            if(numbers_comp[i]>=2) ++ok2_nc;
        }
        for(int i=0;i<4;++i)
        {
            if(letters_player[i]>=2) ++ok2_lp;
            if(letters_comp[i]>=2) ++ok2_lc;
        }
        if(ok2_np>=2&&ok2_lp>=2) two_player=1;
        else if(ok2_np>=2||ok2_lp>=2) two_player=1;
        if(ok2_nc>=2&&ok2_lc>=2) two_comp=1;
        else if(ok2_nc>=2||ok2_lc>=2) two_comp=1;
        if(ok2_np==1&&ok2_lp==1) two_player=1;
        else if(ok2_nc==1&&ok2_lc==1) two_comp=1;
        if(two_player==1&&two_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by two pair"; break;
            }
            else if(high_player<high_comp)
            {
                cout<<"Computer wins by two pair"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(two_player)
        {
            cout<<"Player wins by two pair"; break;
        }
        else if(two_comp)
        {
            cout<<"Computer wins by two pair"; break;
        }
        //one pair, working
        int one_player=0,one_comp=0;
        for(int i=0;i<9;++i)
        {
            if(numbers_player[i]>=2) one_player=1;
            if(numbers_comp[i]>=2) one_comp=1;
        }
        for(int i=0;i<4;++i)
        {
            if(letters_player[i]>=2) one_player=1;
            if(letters_comp[i]>=2) one_comp=1;
        }
        if(one_player==1&&one_comp==1)
        {
            if(high_player>high_comp)
            {
                cout<<"Player wins by one pair"; break;
            }
            else if(high_comp>high_player)
            {
                cout<<"Computer wins by one pair"; break;
            }
            else if(high_player==1&&high_comp==1)
            {
                cout<<"Draw"; break;
            }
        }
        else if(one_player)
        {
            cout<<"Player wins by one pair"; break;
        }
        else if(one_comp)
        {
            cout<<"Computer wins by one pair"; break;
        }
        //high card, working
        if(high_player)
        {
            cout<<"Player wins by high card"; break;
        }
        else if(high_comp)
        {
            cout<<"Computer wins by high card"; break;
        }
        else if(high_player==1&&high_comp==1)
        {
            cout<<"Draw"; break;
        }
    }
    if(strcmp(game,"n")==0) cout<<"Computer wins by forfeit";
    cout<<'\n'<<"Thank you for using this application"<<'\n';
}
