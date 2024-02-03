#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<sys/wait.h>


bool is_number(const std::string& s)
{
    return !s.empty() && (s.find_first_not_of("0123456789") == s.npos);
}

unsigned long long findFactorial(unsigned long long n){
    if (n > 20)
    {
        std::cout<<"Число слишком большое. Значение факториала будет вычислено для 20 во избежание переполнения." << std::endl;
        n = 20;
    }
    
    if (n == 0) {
        return 1;
    }
  else {
    return n * findFactorial( n - 1);
    }
    
}

unsigned long long findFibonacci(unsigned long long n)
 {
     if (n > 93){
         std::cout<<"Число слишком большое. Значение Фиббоначчи будет вычислено для 93 во избежание переполнения";
         n = 93;
     }
     if (n==1 || n==2) 
         return 1ull;
     if (n==0) 
         return 0ull;
    return findFibonacci(n-1)+findFibonacci(n-2);
 }

int main(int argc, char* argv[], char *envp []){
    // if (argc != 2)
    // {
    //     std::cout<<"Неверное количество аргументов!" << std::endl;
    // }
    // if (!is_number(argv[1]) || std::stoi(argv[1]) < 0)
    //     {
    //         std::cout<< "Второй аргумент должен быть неотрицательным числом!";
    //         return 0;
    //     }
    // int number = std::stoi(argv[1]);
    int number;
    std::cin>> number;
    pid_t pid, ppid,chpid;
    chpid = fork();
    if (chpid == -1)
    {
        std::cout<< "Что-то случилось"<< std::endl;
    }
    else if (chpid == 0)
    {
        pid_t chpid2 = fork();
        if (chpid2 == -1)
        {
            std::cout<< "Что-то случилось"<< std::endl;
        }
        else if (chpid2 == 0)
        {
            std::cout<< "My pid = " <<getpid() << "; my ppid = " << getppid() << std::endl;
            std::cout<<"Содержимое каталога: ";
            execl("/bin/ls", "/bin/ls", 0);
            std::cout<<getpid()<<" Завершил работу" << std::endl;
            std::cout<<'\n';
            wait(0);
        }
        else{
            std::cout<< "My pid = " <<getpid() << "; my ppid = " << getppid() << std::endl;
            std::cout<< "Факториал числа: "<< findFactorial(number) << std::endl;
            std::cout<<getpid()<<" Завершил работу" << std::endl;
            std::cout<<'\n';
            wait(0);
        }
        
    }
    else{
        std::cout<< "My pid = " <<getpid() << "; my ppid = " << getppid() << std::endl;
        std::cout<< "Число Фиббоначи: "<< findFibonacci(number) << std::endl;
        std::cout<<getpid()<<" Завершил работу" << std::endl;
        std::cout<<'\n';
    }
    return 0;
}