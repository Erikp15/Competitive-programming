#include <iostream>

using namespace std;

int calculate_word(string& word){
    int curr_mult=1,word_size=0;
    for(int i=0;i<(int)word.size();i++){
        if(word[i]>'Z'){
            word_size+=curr_mult*(word[i]-'a'+1);
        }else{
            word_size+=curr_mult*(word[i]-'A'+1);
        }
        curr_mult*=2;
    }
    return word_size;
}

int main(){
    int n,largest_word_size=0;
    cin>>n;
    string all_words[n],largest_word;
    for(int i=0;i<n;i++){
        cin>>all_words[i];
        if(largest_word_size<calculate_word(all_words[i])){
            largest_word_size=calculate_word(all_words[i]);
            largest_word=all_words[i];
        }
    }
    cout << largest_word << endl;
    return 0;
}
