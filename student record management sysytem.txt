#include <bits/stdc++.h>

using namespace std;

//Node class

class Node{
public:
    string Name;
    int Roll;
    string Course;
    int Marks;
    Node* next;
};

Node* head = new Node;   //head of the linked list;


//checking if the entered roll.no is valid
bool check(int x)           
{       
    if(head==NULL)
        return false;
        
    Node* t = new Node;
    t = head;
    
    while(t!=NULL){
        if(t->Roll == x)
            return true;
        
        t = t->next;    
    }
    
    return  false;
}


//function to insert a record
void Insert_Record(int roll, string name, string course, int marks)    
{
    if(check(roll)){
        cout<<"STUDENT WITH THIS RECORD ALREADY EXIXTS" ;
        return ;
    }
    
    //to insert in the begining
    Node* t = new Node;
    t->Roll = roll;
    t->Name = name;
    t->Course = course;
    t->Marks = marks;
    
    if(head == NULL || head->Roll == t->Roll){
        t->next = head;
        head = t;
    }
    else{
        Node* c = head;
         while(c->next!=NULL && c->next->Roll < t->Roll){
            c = c->next ; 
         }
         t->next = c->next;
         c->next = t;
    }
    
    cout<<"Record inserted Successfully\n";
    
}



//functiom to Search a record with given roll number
void Search_Record(int roll){
    if(head==NULL){
        cout<<"NO SUCH RECORD IS AVAILABLE \n";
        return ; 
    }
    else{
        Node* p = head;
        
        while(p!=NULL){
            if(p->Roll == roll){
                cout<<"Roll Nmuber\t"
                     << p->Roll << endl;
                cout << "Name\t\t"
                     << p->Name << endl;
                cout << "Course\t\t"
                     << p->Course << endl;
                cout << "Marks\t\t"
                     << p->Marks << endl;
                return ;
            }
            p = p->next;
        }
        
        if(p==NULL){
            cout<<"NO SUCH RECORD IS AVAILABLE \n";
        }
    }
    
}




//function to delete a particular student record with the given roll number
int Delete_Record(int roll){
    Node* t = head;
    Node* p = NULL;
    
    if(t!=NULL && t->Roll == roll){
        head = t->next;
        delete t;
        
        cout<<"Record deleted Successfully \n";
        return 0;
    }
    
    
    while(t!=NULL && t->Roll != roll){
        p = t;
        t = t->next;
    }
    
    if(t==NULL){
        cout<<"Record does not exist";
        return -1;
    }
    else{
        p->next = t->next;
        delete t;
        cout<<"Record deleted Successfully";
        
        return 0;
    }
    
}



//function to display student record 
void Show_Record(){
    Node* p = head; 
    if(p==NULL){
        cout<<"No record available";
        return ;
    }
    else {
        cout << "Index\tName\t\tCourse"
             << "\t\tMarks\n";
  
        // Until p is not NULL
        p = p->next;
        while (p != NULL) {
            cout << p->Roll << "    \t"
                 << p->Name << "\t\t"
                 << p->Course << "\t\t"
                 << p->Marks << endl;
            p = p->next;
        }
    }

}


//function to Update the record of a particular student
void Update(){
    int st_roll;
    cout << "Enter roll number of the student you want to Update : "<<endl;
    cin>>st_roll;
    
    Node* p = head;
    if(p==NULL){
        cout<<"Record of the student with this roll number is not present";
        return ;
    }
    else{
        while(p!=NULL){
            if(p->Roll == st_roll){
                string st_name;
                cout << "Enter name of the student to be updated" << endl;
                cin >> st_name;
                p->Name = st_name;
                
                string st_course;
                cout << "Enter the course of the student" << endl;
                cin >> st_course;
                p->Course = st_course;
                
                int st_marks;
                cout << "Enter the Marks of the student" <<endl;
                cin >> st_marks;
                p->Marks = st_marks;
                
                return ;
            }
            
            p=p->next;
        }
        
        if(p==NULL)
            cout<<"Record of the student with this roll number is not present...!";
    }
    
}




int main()
{
    cout<<"***********************************************************************************************************************************\n";
    cout<<"                                              WELCOME TO STUDENT MANGEMENT SYSTEM                                                  \n";
    cout<<"***********************************************************************************************************************************\n";
    
    string name,course;
    int marks,roll;
    
   while(true){
        cout << "\n\n\tPress\n\t1 to "
                "create a new Record\n\t2 to delete a "
                "student record\n\t3 to Search a Student "
                "Record\n\t4 to view all students "
                "record\n\t5 to Update a rercord\n\t6 to Exit\n";
        cout << "\nEnter your Choice\n";
        
        int choice;
        cin>>choice;
        
        
        switch(choice){
            
            case 1 :
                cout << "Enter Name of Student\n";
                cin >> name;
                cout << "Enter Roll Number of Student\n";
                cin >> roll;
                cout << "Enter Course of Student \n";
                cin >> course;
                cout << "Enter Total Marks of Student\n";
                cin >> marks;
                Insert_Record(roll, name, course, marks); 
                break;
                
                
            
            case 2 :
                cout << "Enter Roll Number of Student whose record is to be deleted\n";
                cin >> roll;
                Delete_Record(roll);   
                break;
                
            
            
            case 3 :
                cout << "Enter Roll Number of Student whose record you want to Search\n";
                cin >> roll;
                Search_Record(roll);   
                break;
                
                
            
            case 4 :
                Show_Record()  ;          
                break;
            
            
            case 5 :
                Update();
                break;
                
                
            case 6 :
                exit(0);
                break;
                
                
            default :
                cout<<"INVALID CHOICE, TRY AGAIN...!";
                break;
            
            
        }
        
    }

    return 0;
}
