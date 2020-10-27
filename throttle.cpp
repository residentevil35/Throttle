/********************************************************************************
  * Rachel Coughanour                                                            *
  * CS 372                                                                       *
  * Throttle Program                                                             *
  *                                                                              *
  * Description: This program tests the throttle, fuel, and other functions      *
  * for various machinery                                                        *
  ********************************************************************************/ 
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

class throttle 
{
private:
    int currentPos;  //the current throttle position
    int maxPos;      //the max position
    
public:
    
    //default constructor 
    throttle()
    {
        currentPos=0;
        maxPos=6;
    }
    int set(int c, int m); //sets the current and max positions 
    int shut_off();  //function to move position to 0
    int shift(char operation, int amount); //shifting to a different position 
    double flow(); //return the fuel flow 
    bool is_on(); //returns true only if flow is > than 0
    void display(); //displays information 
    void header();  //file header
    void printPos();  //prints the position header for current position 
    void divider();  //divider to organize each test 
    void displayEnd();  //displays the end text asking if a user would like another test 
};

int throttle::set(int c, int m)  //setting the current and max values 
{
    currentPos=c;
    maxPos=m;
}

int throttle::shift(char operation, int amount)  //function to shift the throttle 
{
    if(operation== '+')
    {
        currentPos+=amount;
    }
    else if(operation== '-')
    {
        currentPos-=amount;
    }
    
    else
    {
        cout<<"The operator must either be a + or -"<<endl;
    }
    
    if(currentPos<0)
    {
        currentPos=0;
    }
    else if(currentPos>maxPos)
    {
        currentPos=maxPos;
    }
    
    return currentPos;
}

int throttle::shut_off()  //function to shut off the throttle completely 
{
    currentPos=0;
    return currentPos;
}

double throttle::flow()
{
    return currentPos/(float)maxPos;
}

bool throttle::is_on()  //using the flow to test if the throttle is on 
{
   return(flow()>0);
}

void header()  //header for file output 
{
    cout<<"***************************************"<<endl;
    cout<<"Output for Throttle Program"<<endl;
    cout<<"***************************************"<<endl<<endl;	
}

void printPos()  //prints the current position 
{
    cout<<"The current position of the throttle is: ";
}

void divider()  //divider to organize the different tests 
{
    cout<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl;
}

void displayEnd()  //this displays the end of the simulation where it asks if you want to do another test 
{
     cout<<"Would you like to run another simulation?"<<endl;
     cout<<"If yes, please enter the number from the menu."<<endl;
     cout<<"If no, please press 6 to quit."<<endl;
}
//beginning of main 
int main()
{ 
    
    cout<<fixed<<setprecision(2);
    
    int currentPos;
    int maxPos;
    int choice;  //the number pertaining to which object to test 
    char operation;  //the addition or subtraction symbol
    int amount;  //amount the user enters to shift 
    bool menu = true; //menu selection that can repeat to run again. 
    
    //objects 
    throttle car;
    throttle truck;
    throttle shuttle;
    throttle lawnmower;
    throttle weedeater;
    
    header();
    
    //menu choices 
    cout<<"Please enter using numbers what type of machinery you would like to test."<<endl;
    cout<<"The choices are: "<<endl;
    cout<<"1 for car"<<endl;
    cout<<"2 for truck"<<endl;
    cout<<"3 for shuttle"<<endl;
    cout<<"4 for lawnmower"<<endl;
    cout<<"5 for weedeater"<<endl;
    cout<<"6 to quit"<<endl<<endl;
    
    do{
        cin>>choice;

      switch(choice)
       {
          //car choice 
          case 1: cout<<"You have chosen the car."<<endl;
              cout<<"What is the current and maximum throttle positions of the car?"<<endl;
            cout<<"Current: ";
            cin>>currentPos;
            cout<<"Max: ";
            cin>>maxPos;
            car.set(currentPos, maxPos);
            
            //print the position  
            cout<<endl;
            printPos();
            cout<<currentPos<<endl;
            
            divider();
            
            
           //testing the flow and is_on functions
            cout<<"Testing the flow"<<endl;
            cout<<"Setting current throttle position to max for testing."<<endl;
            
            //setting the throttle to max for testing the flow 
            operation='+';
            amount=maxPos;
            car.shift(operation, amount);
            
            //while machine is on, check the flow
            while(car.is_on())
            {
                   
                   cout<<"The flow is now: "<<car.flow()<<endl;
                   operation='-';
                   amount=1;
                   car.shift(operation, amount);
            }
            cout<<"The flow is now off."<<endl;
         
            divider();
          
            cout<<"Now testing the shift"<<endl;
            //testing the shift method
            for(int i=0;i<5;i++)
            {
              cout<<"Enter how much you want to shift. Enter the operator and then the number. Ex (+5): ";
              //enter the operator (ex. + or - ) and the amount
              cin>>operation>>amount;
            
              cout<<"Calling the shift function..."<<endl;
              currentPos=car.shift(operation, amount);
              printPos();
              cout<<currentPos<<endl;
            }
          
            divider();

             //testing the shut-off function    
             cout<<"Now testing the shut off function..."<<endl;
             printPos();
             cout<<currentPos<<endl;
             for(int j=0;j<2;j++)
             {
               cout<<"Calling the shut-off function..."<<endl;
               currentPos=car.shut_off();  
               printPos();
               cout<<currentPos<<endl;
             }
             
             divider();
             
             //displaying the end output
             displayEnd();
            
            break;
            
            //truck choice 
          case 2: cout<<"You have chosen the truck."<<endl;
              cout<<"What is the current and maximum positions of the truck?"<<endl;
            cout<<"current: ";
            cin>>currentPos;
            cout<<"Max: ";
            cin>>maxPos;
            truck.set(currentPos, maxPos);
            
              //setting the throttle to max for testing the flow 
            operation='+';
            amount=maxPos;
            truck.shift(operation, amount);
            
            //while machine is on, check the flow
            while(truck.is_on())
            {
                   
                   cout<<"The flow is now: "<<truck.flow()<<endl;
                   operation='-';
                   amount=1;
                   truck.shift(operation, amount);
            }
            cout<<"The flow is now off."<<endl;
         
            divider();
            
             //testing the shift method
            for(int i=0;i<5;i++)
            {
              cout<<"Enter how much you want to shift. Ex (+5): ";
              //enter the operator (ex. + or - ) and the amount
              cin>>operation>>amount;
            
              cout<<"Calling the shift function..."<<endl;
              currentPos=truck.shift(operation, amount);
              printPos();
              cout<<currentPos<<endl;
            }
            
            divider();
            
             //testing the shut-off function    
             cout<<"Now testing the shut off function..."<<endl;
             printPos();
             cout<<currentPos<<endl;
             for(int j=0;j<2;j++)
             {
               cout<<"Calling the shut-off function..."<<endl;
               currentPos=truck.shut_off();  
               printPos();
               cout<<currentPos<<endl;
             }
             
             divider();
             
             //displaying the end output
             displayEnd();
             
            break;
            
            //shuttle choice 
          case 3: cout<<"You have chosen the shuttle."<<endl;
              cout<<"What is the current and maximum positions of the shuttle?"<<endl;
            cout<<"current: ";
            cin>>currentPos;
            cout<<"Max: ";
            cin>>maxPos;
            shuttle.set(currentPos, maxPos);
            
           //testing the flow and is_on functions
            cout<<"Testing the flow"<<endl;
            cout<<"Setting current throttle position to max for testing."<<endl;
            
            //setting the throttle to max for testing the flow 
            operation='+';
            amount=maxPos;
            shuttle.shift(operation, amount);
            
            //while machine is on, check the flow
            while(shuttle.is_on())
            {
                   
                   cout<<"The flow is now: "<<shuttle.flow()<<endl;
                   operation='-';
                   amount=1;
                   shuttle.shift(operation, amount);
            }
            cout<<"The flow is now off."<<endl;
         
            divider();
            
            //testing the shift method
            for(int i=0;i<5;i++)
            {
              cout<<"Enter how much you want to shift. Ex (+5): ";
              //enter the operator (ex. + or - ) and the amount
              cin>>operation>>amount;
            
              cout<<"Calling the shift function..."<<endl;
              currentPos=shuttle.shift(operation, amount);
              printPos();
              cout<<currentPos<<endl;
            }
            
            divider();
            
              //testing the shut-off function    
             cout<<"Now testing the shut off function..."<<endl;
             printPos();
             cout<<currentPos<<endl;
             for(int j=0;j<2;j++)
             {
               cout<<"Calling the shut-off function..."<<endl;
               currentPos=shuttle.shut_off();  
               printPos();
               cout<<currentPos<<endl;
             }
             
             divider();
             
             //displaying the end output
             displayEnd();
            
            break;
            
            //lawnmower choice 
          case 4: cout<<"You have chosen the lawnmower."<<endl;
              cout<<"What is the current and maximum positions of the lawnmower?"<<endl;
            cout<<"current: ";
            cin>>currentPos;
            cout<<"Max: ";
            cin>>maxPos;
            lawnmower.set(currentPos, maxPos);
            
            //testing the flow and is_on functions
            cout<<"Testing the flow"<<endl;
            cout<<"Setting current throttle position to max for testing."<<endl;
            
            //setting the throttle to max for testing the flow 
            operation='+';
            amount=maxPos;
            lawnmower.shift(operation, amount);
            
            //while machine is on, check the flow
            while(lawnmower.is_on())
            {
                   
                   cout<<"The flow is now: "<<lawnmower.flow()<<endl;
                   operation='-';
                   amount=1;
                   lawnmower.shift(operation, amount);
            }
            cout<<"The flow is now off."<<endl;
         
            divider();
            
             //testing the shift method
            for(int i=0;i<5;i++)
            {
              cout<<"Enter how much you want to shift. Ex (+5): ";
              //enter the operator (ex. + or - ) and the amount
              cin>>operation>>amount;
            
              cout<<"Calling the shift function..."<<endl;
              currentPos=lawnmower.shift(operation, amount);
              printPos();
              cout<<currentPos<<endl;
            }
            
            divider();
            
              //testing the shut-off function    
             cout<<"Now testing the shut off function..."<<endl;
             printPos();
             cout<<currentPos<<endl;
             for(int j=0;j<2;j++)
             {
               cout<<"Calling the shut-off function..."<<endl;
               currentPos=lawnmower.shut_off();  
               printPos();
               cout<<currentPos<<endl;
             }
             
             divider();
             
             //displaying the end output
             displayEnd();

            break;
              
            //weedeater choice 
          case 5: cout<<"You have chosen the weedeater."<<endl;
              cout<<"What is the current and maximum positions of the weedeater?"<<endl;
            cout<<"Current: ";
            cin>>currentPos;
            cout<<"Max: ";
            cin>>maxPos;
            weedeater.set(currentPos, maxPos);
            
             //testing the flow and is_on functions
            cout<<"Testing the flow"<<endl;
            cout<<"Setting current throttle position to max for testing."<<endl;
            
            //setting the throttle to max for testing the flow 
            operation='+';
            amount=maxPos;
            weedeater.shift(operation, amount);
            
            //while machine is on, check the flow
            while(weedeater.is_on())
            {
                   
                   cout<<"The flow is now: "<<weedeater.flow()<<endl;
                   operation='-';
                   amount=1;
                   weedeater.shift(operation, amount);
            }
            cout<<"The flow is now off."<<endl;
         
            divider();
            
             //testing the shift method
            for(int i=0;i<5;i++)
            {
              cout<<"Enter how much you want to shift. Ex (+5): ";
              //enter the operator (ex. + or - ) and the amount
              cin>>operation>>amount;
            
              cout<<"Calling the shift function..."<<endl;
              currentPos=weedeater.shift(operation, amount);
              printPos();
              cout<<currentPos<<endl;
            }
            
            divider();
            
            //testing the shut-off function    
             cout<<"Now testing the shut off function..."<<endl;
             printPos();
             cout<<currentPos<<endl;
             for(int j=0;j<2;j++)
             {
               cout<<"Calling the shut-off function..."<<endl;
               currentPos=weedeater.shut_off();  
               printPos();
               cout<<currentPos<<endl;
             }
             
             divider();
             
             //displaying the end output
             displayEnd();
          
            break;
            
          case 6: cout<<"You have chosen to quit the simulation. Goodbye."<<endl;
          break;
            
          default: cout<<"Please enter a number between 1-6 based off of the choices listed above"<<endl;
            break;
       }
    }while(choice!=6);
 
    return 0;
}
