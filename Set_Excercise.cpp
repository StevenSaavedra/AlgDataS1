#include <iostream>
#include <set>

int main() {

    int c = 0;
    std::set<int> s;
    while(c!=-1){
        std::cout << "Enter a number to enqueue, -1 to stop" << std::endl;
        std::cin >> c;
        if(c!=-1){
            s.insert(c);
        }


    }

    std::cout << "The numbers in sorted order are: " << std::endl;
    for(auto i : s){
        std::cout << i << " ";
    }



    return 0;
}