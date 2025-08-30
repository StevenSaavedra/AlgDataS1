#include <iostream>
#include <queue>
#include <string>

int main() {

    std::queue<std::string> printQ;
    int c=0;

    do
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add a Job to the queue" << std::endl;
        std::cout << "2. Process Job" << std::endl;
        std::cout << "3. Show queue" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice:" << std::endl;
        std::cin >> c;

        if(c==1){
            std::string input;
            std::cout << "Enter doc name:" << std::endl;
            std::cin >> input;
            printQ.push(input);
        }
        else if(c==2){
            if(!printQ.empty()){
                std::cout << "Processing: " << printQ.front() << std::endl;
                printQ.pop();
            }
            else{
                std::cout << "The queue is empty." << std::endl;
            }
        }
        else if(c==3){
            std::queue<std::string> temp = printQ;
                    std::cout << "Queue: ";
                    while (!temp.empty()) {
                        std::cout << temp.front() << " ";
                        temp.pop();
                    }
                    std::cout << "\n";
        }
        else if(c==4){
            std::cout << "Exiting program..." << std::endl;
        }
        else{
            std::cout << "Invalid option, please try again." << std::endl;
        }   
    } while (c!=4);
    



    return 0;

}