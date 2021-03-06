#include "ConvergenceLibrary.hpp"

#include "Convergence/quad/x86/mono/QP_x86.hpp"

#include "Convergence/double/x86/mono/DP_x86.hpp"

#include "Convergence/simple/x86/mono/SP_x86.hpp"

////    ////    ////    ////    ////    ////    ////
#include "Convergence/simple/x86/julia-mono/JU_SP_x86.hpp"
////    ////    ////    ////    ////    ////    ////

ConvergenceLibrary::ConvergenceLibrary()
{

    //
    //
    //

    list.push_back( new SP_x86         (nullptr, 255) );
    list.push_back( new JU_SP_x86      (nullptr, 255) );

    list.push_back( new DP_x86        (nullptr, 255) );
    list.push_back( new QP_x86                (nullptr, 255) );

    std::cout << "INSTANCIATED MODULES:" << std::endl;
    std::cout << "--------------------"  << std::endl;

    listAllModules();

    std::cout << "UNLOADING USELESS MODULES:" << std::endl;
    std::cout << "-------------------------"  << std::endl;

    for(int i=0; i<list.size(); i++){
        const bool enable = list[i]->is_valid();
        if( enable == false )
        {
            cout << list[i]->toString() << std::endl;
            Convergence* c = list[i];
            list.erase( list.begin() + i );
            delete c;
            i -= 1;
        }
    }

    //
    //
    //
    for(int i=0; i<list.size(); i++){
        dico[ list[i]->name() ] = list[i];
        indx[ list[i]->name() ] =      i ;
    }

    counter = 0;

}

ConvergenceLibrary::~ConvergenceLibrary(){

    for(int i=0; i<list.size(); i++)
        delete list[i];

}

Convergence* ConvergenceLibrary::get(std::string name){
    counter = indx[name];
    return get();
}

Convergence* ConvergenceLibrary::get(int num){
    counter = num;
    return get();
}

Convergence* ConvergenceLibrary::get(){
//        printf("GET %d : (%p) name = %s \n", counter, list[counter], list[counter]->name().c_str());
    //printf("Convergence :: get (%d) : (%p) name = %s \n", counter, list[counter], list[counter]->name().c_str());
    std::cout << "(II) Switching to " << list[counter]->toString() << std::endl;
    return list[counter];
}

void ConvergenceLibrary::next(){
    counter = (counter + 1) % list.size();
}

void ConvergenceLibrary::previous(){
    counter = (counter + list.size() - 1) % list.size();
}

void ConvergenceLibrary::listAllModules()
{
    for(int i=0; i<list.size(); i++)
        cout << list[i]->toString() << std::endl;
}
