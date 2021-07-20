#include <iostream>
using namespace std;

class node{
public:
int seat_no;
bool status=0;
node *prev, *next;
node(){
    prev=next=NULL;
}
 };

 class ll
 {

node *head[10],*tail[10];
public:
ll (){
int num=1;
    for(int i=1;i<11;i++){
        head[i]=NULL;
        tail[i]=NULL;
    }
    for(int j=1;j<11;j++){
        for(int i=1;i<8;i++){
            node *newnode;
newnode=new node;
newnode->seat_no=num;
newnode->status=0;
          if(head[j]==NULL){
head[j]=newnode;
tail[j]=newnode;
newnode->next=head[j];
newnode->prev=tail[j];
num++;
          }
          else{
tail[j]->next=newnode;
newnode->prev=tail[j];
newnode->next=head[j];
tail[j]=newnode;
 head[j]->prev=tail[j];
newnode->seat_no=num;
num++;

          }
        }
      
    }
 
}

void display();
void booking();
void cancle();
 };

void ll::display(){
    node *nodeptr;
    for(int j=1;j<11;j++){
        nodeptr=head[j];
        do{
            cout<<nodeptr->seat_no<<" ";
        
            if(nodeptr->status==0){
                cout<<"E  ";
            }
            else{
                cout<<"B  ";
            }
            nodeptr=nodeptr->next;
        }while(nodeptr!=head[j]);
        cout<<endl;
    }
}


void ll::booking(){
    int ticket, book_seat=0;  //ticket=tot num of ticket want to book
    //book_seat==tt ticket that get booked
    //count=var to traverse over seat array
    string name;
    char opt;
    int count=0;
    cout<<"                        ---------------------------booking counter------------------------------\n";
    cout<<"Enter your name\n";
    cin.get();
    getline(cin, name);
    cout<<"How many tickets you want to book\n";
    cin>>ticket;
    int seat[ticket]; //to keep trak of tickets numbers
    cout<<"Enter seat number you want to book\n";
    for(int i=0;i<ticket;i++){
        cin>>seat[i];
        if(seat[i]<1 || seat[i]>70){
            cout<<"Invalid seat number\n";
            return ;
        }
        
    }
    for(int i=0;i<ticket;i++){   //sorting of  ticket t make search more easier
        int temp; 
        for(int j=0;j<ticket-i;j++){
        if(seat[j]>seat[j+1]){
            temp=seat[j+1];
            seat[j+1]=seat[j];
            seat[j]=temp;

        }
        }
    }
    node *nodeptr;
    for(int i=1;i<11;i++){
        nodeptr=head[i];
        for(int j=1;j<8;j++){
       if(nodeptr->seat_no==seat[count] && nodeptr->status==0){
           nodeptr->status=1;
           count++;
           book_seat++;
       }
       if(nodeptr->seat_no==seat[count] && nodeptr->status==1){
cout<<"seat number "<<nodeptr->seat_no<<" is booked already\n ";
           count++;
       }
       nodeptr=nodeptr->next;
        }
    }

    cout<<"Name: "<<name<<endl;
    cout<<"Total ticket booked: "<<book_seat<<endl;
    cout<<"To pay: "<<"60*"<<book_seat<<" = "<<60*book_seat<<endl;
    cout<<"----------------------------------------------------------------------------------------------------------------\n";
}



void ll::cancle(){
    int no_cancle,count=0;
    //no_cancle=tot ticket to cancle
    int cancle_tic=0;
    //cancle_tic=tot ticket that get canclled
    string name;
    node *nodeptr;
    cout<<"-------------------------------------Ticket Cancellation Counter-------------------------------------------------\n";
    cout<<"Enter your name\n";
    cin.get();
    getline(cin,name);
    cout<<"How many seats reservation you want to cancle\n";
    cin>>no_cancle;
    int cancle_seat[no_cancle]; //to keep track of ticket to cancle
    cout<<"Which seat's reservation you want to cancle\n";
    for(int i=0;i<no_cancle;i++){
        cin>>cancle_seat[i];
    }
    for(int i=1;i<11;i++){
        nodeptr=head[i];
        for(int j=1;j<8;j++){
            if(nodeptr->seat_no==cancle_seat[count] && nodeptr->status==0){
                cout<<cancle_seat[count]<<" Seat is already not reserved\n";
                count++;
            }
            if(nodeptr->seat_no==cancle_seat[count] && nodeptr->status==1){
                nodeptr->status=0;
                cout<<"Your ticket "<<cancle_seat[count]<<"  booking is successfully cancled\n";
                count ++;
                cancle_tic ++;
            }
            nodeptr=nodeptr->next;
        }
        
    }
    if(cancle_tic>0){
    cout<<"Name: "<<name<<endl;
    cout<<"Number of ticket cancle: "<<cancle_tic<<endl;
    cout<<40*cancle_tic<<" rupees will get refund to your account\n";
    cout<<"20 rupees money charges are applied\n";
    cout<<"                           ------------------------------Thank you-------------------------------\n";
    }
    else{
        cout<<"                           ------------------------------Thank you-------------------------------\n";
    }
}





 int main(){
  int ch,ticket;   
  ll l1;
  cout<<"------------------------------------Ticket Booking Centre of Cinemax Theatre-----------------------------------\n";
  cout<<endl<<"                         ----------------------------Menu--------------------------\n";
  do{
      cout<<"Enter 1 to view seats\n";
      cout<<"Enter 2 to book ticket\n";
      cout<<"Enter 3 to cancle ticket\n";
      cout<<"Enter 4 to exit\n";
      cout<<"Enter your choice\n";
cin>>ch;
switch(ch){
    case 1:{
        l1.display();
        break;
    }

    case 2:{
        l1.booking();
        break;
    }

    case 3:{
        l1.cancle();
        break;
    }
}

  }while(ch!=4);
  

 }




 //complexity for each func is O(n*m) => n=rows, m=col