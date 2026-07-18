#include<string>




std::string removeVowels(std::string &s){
    std::vector<char> vowels(26,false);
    
    vowels['a'-'a']=true;
    vowels['e'-'a']=true;
    vowels['i'-'a']=true;
    vowels['o'-'a']=true;
    vowels['u'-'a']=true;
    int write_idx=0;
    for (int read_idx = 0; read_idx < s.size(); read_idx++){
        //s[0]=l,s[1]=e,s[2]=e
        if(vowels[s[read_idx]-'a']==false){
            //jesli spplgloska ladniejszy zapis if(!vowels[s[read_idx]])
            s[write_idx]=s[read_idx]; //kopiuje litere na pozycje write
            write_idx++;

        }
    }       
    s.resize(write_idx);
    return s;

}

bool isVowel(char st) {
    return (st == 'a' or st == 'e' or st == 'i' or st == 'o' or st == 'u');
}

std::string removeVowelsBuildFromEmpty(std::string s) {

    std::string ans;
    for (char itr : s) {
        if (!isVowel(itr)) {
            ans.push_back(itr);
        }
    }

    return ans;
}