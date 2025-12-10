#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void playing(){
    int random = rand() % 251;
    std::cout<<"Guess a number : ";
    while(true){
        int guess;
        std::cin>>guess;
        if(random == guess){
            std::cout<<"You won !!"<<std::endl;
            break;
        }
        else if(guess < random ){
            std::cout<<"Too low"<<std::endl;
        }
        else{
            std::cout<<"Too high"<<std::endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    int choice;
    do{
        std::cout<<"0.Quit the game "<<std::endl<<"1.Play the game"<<std::endl;
        std::cin>>choice;
        switch (choice)
        {
        case 0:
            std::cout<<"You have quitted the game";

            break;
        
        case 1:
            playing();
            break;
        }

    }while(choice!=0);
}
