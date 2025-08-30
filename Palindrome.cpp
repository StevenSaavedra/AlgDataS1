#include <iostream>
#include <vector>
#include <string>

int main() {

    int c=0;

    std::vector<char> word;

    std:: string Word;
    std::cout << "Enter your word" << std::endl;
    std::cin >> Word;
    while(c<Word.length()){
        word.push_back(Word[c]);
        c++;
    }

    std::vector<char> word_rev;

    for(int j=(word.size()-1); j>=0; j--){

        word_rev.push_back(word[j]);
        
    }

    if(word==word_rev){
        std::cout << "The word is a palindrome" << std::endl;
    }
    else{
        std::cout << "The word is not a palindrome" << std::endl;
    }

    return 0;

    
}