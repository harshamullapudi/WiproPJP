#include <bits/stdc++.h>
using namespace std;

struct Book{
    int copy;
    int id;
    string bname;
};
void ReadBooks(const char* fname){
    Book b1;
    ifstream myfile; 
    string line;
    myfile.open(fname);
    int count=0;
    if(myfile){
        while(true){
            cout<<"**********************************************************"<<endl;
            myfile>>b1.copy;
            cout<<"No of Copies: "<<b1.copy<<endl;
            myfile>>b1.id;
            cout<<"Book ID: "<<b1.id<<endl;
            getline(myfile,b1.bname);
            cout<<"Book Name: "<<b1.bname<<endl;
            count++;
            if(count==20){
                break;
            }
        }
    }
    else{
        perror("Error opening file");
    }
    myfile.close();

}

const char* RequestBook(const char* fname){
    Book b1;
    const char* temporaryfile="temp.txt";
    ifstream myfile;
    myfile.open(fname);
    ofstream tempfile;
    tempfile.open(temporaryfile, ios::app | ios::out);
    int search;
    bool valid=false;
    cout<<"Enter ID of the book you want: ";
    cin>>search;
    int count=0;
        while(true){
            myfile>>b1.copy;
            myfile>>b1.id;
            getline(myfile,b1.bname);
            if(search==b1.id){
                valid=true;
                int k=b1.copy;
                if(k==0){
                    cout<<"This Book is Presently not on our shelf. please try later"<<endl;
                }
                else{
                    k=k-1;
                    cout<<"Congratulations Customer. Your Book is Allocated. Please collect it from the shelf"<<endl;
                }
                b1.copy=k;
            }
            tempfile<<b1.copy<<" ";
            tempfile<<b1.id;
            tempfile<<b1.bname<<endl;
            count++;
            if(count==20){
                break;
            }
        }
    if(!valid){
		cout<<"Book id is Incorrect. Please try again"<<endl;
	}
    myfile.close();
    tempfile.close();
    return temporaryfile;

}
const char* ReturnBook(const char* fname){
    Book b1;
    const char* temporaryfile="temp.txt";
    ifstream myfile;
    myfile.open(fname);
    ofstream tempfile;
    tempfile.open(temporaryfile, ios::app | ios::out);
    bool valid=false;
    int  search;
    cout<<"Enter the ID of book you want to return: ";
    cin>>search;
    int count=0;
    while(true){
        myfile>>b1.copy;
        myfile>>b1.id;
        getline(myfile,b1.bname);
        if(search==b1.id){
            valid=true;
            int k=b1.copy;
            k=k+1;
            cout<<"Thankyou Customer. Please place the book back on the shelf"<<endl;
            b1.copy=k;
        }
        tempfile<<b1.copy<<" ";
        tempfile<<b1.id;
        tempfile<<b1.bname<<endl;
        count++;
        if(count==20){
            break;
        }
    }
    if(!valid){
		cout<<"Book id is Incorrect. Please try again"<<endl;
	}
    myfile.close();
    tempfile.close();
    return temporaryfile;
}
int main(void){
    int choice;
    const char* fname="books_database.txt";
    const char* newfile="";
    cout<<"*****Hello Customer. Welcome to GoodWill Library. ******"<<"\n"<<"\n"<<endl;
    while(true){
        cout<<"=========================================================="<<endl;
       cout<<"Please select one option from below:\n1) View list of books on our shelves\n2) Request for a new book\n3) Return a book\n4) Exit\n ";
       cin>>choice;
       switch(choice){
           case 1:
            ReadBooks(fname);
            break;
           case 2:
            newfile=RequestBook(fname);
            remove(fname);
            rename(newfile,fname);
            break;
           case 3:
            newfile=ReturnBook(fname);
            remove(fname);
            rename(newfile,fname);
            break;
           case 4:
            exit(0);
           default:
            cout<<"Please enter a valid choice\n";
            break;
       }

    }
    return 0;
}