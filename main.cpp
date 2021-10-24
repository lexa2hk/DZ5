#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void first(){
    int a=1,b=1,nod=1;
    int temp=0;
    cin>>a>>b;
    for(int i=1;i<min(a,b)+1;i++){
        if(a%i==0 && b%i==0) {
            nod = i;
        }
    }
    cout<<"Dividing: "<<nod<<endl;
    nod=1;
    while(a!=b){
        temp = max(a,b)-min(a,b);
        if(a>b){
            a=temp;
        }else{
            b=temp;
        }
    }
    cout<<"Substruction: "<<a<<endl;
}

void second(){
    cout<<"Print n: ";
    int n;
    cin>>n;
    bool *isPrime = new bool[n+1];
    isPrime[0]= false;
    isPrime[1]= true;
    isPrime[2]= true;
    for(int i=2;i<n;i++)
        isPrime[i]= true;

    for(int i=2;i<n;i++){
        if(isPrime[i]){
            for(int j=2*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

void third(){
    //21 6
    cout<<"V 21"<<endl; //redkaya glasnaya


    string s;
    ifstream fin("/Volumes/Samsung/Vuz1/Prog/DZ5/inp.txt");
    const string gl = "aeiouy";
    int cnt[6] = {0,0,0,0,0,0};

    if (!fin)
    {
        cerr << "file_err!" << endl;
        //exit(1);
    }
    if(fin){
        while(fin){
            getline(fin, s);
            //cout<<s;

            for(int i=0;i<s.length();i++){
                for(int j=0;j<gl.length();j++){
                    if(tolower(s[i])==gl[j]){
                        cnt[j]+=1;
                    }
                }
            }
        }

        int mi=INT_MAX;
        int index;
        for(int i=0;i<gl.length();i++){
            if(cnt[i]<mi){
                mi=cnt[i];
                index = i;
            }
        }
        cout<<"rarest vovel: "<<mi<<" "<<(gl[index])<<endl;
    }

    fin.close();


}

void third_2(){

    ifstream fin("/Volumes/Samsung/Vuz1/Prog/DZ5/inp.txt");
    cout<<"V 6"<<endl;
    string s="";
    bool current = true;
    string temp="";
    vector<string> words;

    if (!fin)
    {
        cerr << "file_err!" << endl;
        //exit(1);
    }
    while(!fin.eof()){
        cout<<"get"<<endl;
        //fin>>s;
        getline(fin,s,'\n');
        cout<<s<<endl;
        temp = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                words.push_back(temp);
                temp = "";
            }else{
                temp+=s[i];
            }

        }
    }

    int m_len=INT_MAX;
    string m_string;
    for(int i=0;i<words.size();i++){
        if(words[i].length()<m_len){
            m_len=words[i].length();
            m_string = words[i];
        }
    }
    cout<<m_len<<" "<<m_string<<endl;
    fin.close();
}

void fourd(){
    //47 27

    cout<<"V 47"<<endl;
    int n;
    cout<<"type n (rows and columns): ";
    cin>>n;
    if(n<=0){
        cerr<<"WRONG DATA";
        return;
    }
    double matrix[n][n];

    for(int i=0;i<n;i++){
        cout<<"Type data for "<<i<<" row\n";
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    double sum=0;
    for(int ptr=0;ptr<n;ptr++){
        sum+=matrix[ptr][ptr];
    }
    cout<<"Answer: "<<sum<<endl;


    cout<<"V 27"<<endl;
    int data[95];
    int tr=0;
    for(int i=0;i<95;i++){
        cout<<"Type c "<<i;
        cin>>data[i];
        cout<<endl;
        if(i>2 && (data[i-2]<0 && data[i-1]<0 &&data[i]<0)){
            tr+=1;
        }
    }

}


void fifth(){
    //22
    vector<string> country;
    vector<int> gold;
    vector<int> silver;
    vector<int> bronze;
    string temp;
    int i_temp;
    int n;

    cout<<"Type amount of countries: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Type county name: ";
        cin>>temp;
        country.push_back(temp);
        cout<<"Amount of Gold:";
        cin>>i_temp;
        gold.push_back(i_temp);
        cout<<"Amount of Silver:";
        cin>>i_temp;
        silver.push_back(i_temp);
        cout<<"Amount of Bronze:";
        cin>>i_temp;
        bronze.push_back(i_temp);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(gold[i] > gold[i+1]){
                swap(country[i],country[i+1]);
                swap(gold[i],gold[i+1]);
                swap(silver[i],silver[i+1]);
                swap(bronze[i],bronze[i+1]);
            }
        }
    }

    ofstream fout("/Volumes/Samsung/Vuz1/Prog/DZ5/out_5.txt");
    fout<<"N  Country  ->  Gold  silver  Bronze Total  Pts "<<endl;
    for(int i=n-1;i>=0;i--){
        fout<<n-i<<" "<< country[i]<<" -> "<<gold[i]<<" "<<silver[i]<<" "<<bronze[i]<<" | "<<gold[i]+silver[i]+bronze[i]<<" | "<<7*gold[i]+6*silver[i]+5*bronze[i]<<endl;
    }
    cout<<"Got it!"<<endl;
    fout.close();


}

int main(){
    while(1){
        int trigger;
        cout<<"Type task number(0=exit)\n";
        cin>>trigger;
        switch (trigger)
        {
            case 1:
                first();
                break;
            case 2:
                second();

                break;
            case 3:
                third();
                third_2();
                break;
            case 4:
                fourd();
                break;
            case 5:
                fifth();
                break;
            case 0:
                break;
            default:
                break;
        }
        if(trigger==0){
            break;

        }
    }
    return 0;
}