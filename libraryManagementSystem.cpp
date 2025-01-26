#include<bits/stdc++.h>
using namespace std;
class BookDetails{
    //Encapsulation
    private:
    int bookid;
    string bookName;
    string author;
    string title;
    public:
    BookDetails(int bookid,string bookName,string author,string title):bookid(bookid),bookName(bookName),author(author),title(title){}
    void getDetail()
    {
        cout<<"BookID"<<this->bookid;
        cout<<"BookName"<<this->bookName;
        cout<<"author"<<this->author;
        cout<<"Title"<<this->title;
    }
    int getBookId()
    {
        return this->bookid;
    }
};
class StudentDetail{
    private:
    string studentId;
    string Name;
    string rollNo;
    int noOfbookissued;
    public:
    StudentDetail(string studentId,string Name,string rollNo):studentId(studentId),Name(Name),rollNo(rollNo),noOfbookissued(0){}
    string getstudentId()
    {
        return this->studentId;
    }
    int getNoOfBookIssued()
    {
        return noOfbookissued;
    }
    void update()
    {
        this->noOfbookissued++;
        return ;
    }
};
class Operation{
    private:
    map<int,string>issueBookDatabase;
    time_t issuedTime;
    time_t returnTime;
    static Operation *op;
    Operation(){}

    public:
    static Operation* getInstance()
    {
        if(op==NULL){
            op=new Operation();
            return op;
        }
        else{
            return op;
        }
    }
    void issueBook(StudentDetail &student,BookDetails &book)
    {
        if(issueBookDatabase.find(book.getBookId())!=issueBookDatabase.end())
        {
            cout<<"Book with id"<<book.getBookId()<<"is already issued to the student"<<issueBookDatabase[book.getBookId()]<<endl;
        }
        else{
            this->issuedTime=time(nullptr);
            this->returnTime=issuedTime+(10*86400);
            issueBookDatabase[book.getBookId()]=student.getstudentId();
            cout<<"Book is issued to the student "<<student.getstudentId()<<"on "<<ctime(&this->issuedTime)<<endl;
            student.update();
        }
    }
    void returnBook(StudentDetail &student,BookDetails &book)
    {
        time_t returnTime=this->returnTime;
        time_t currentTime=time(nullptr);
        if(returnTime>=currentTime)
        {
            issueBookDatabase.erase(book.getBookId());
            cout<<"Book Return Successfully on "<<ctime(&(this->returnTime));
        }
        else{
            double calculateFine=fine(returnTime,currentTime);
        }
    }
    double fine(time_t returnTime,time_t currentTime)
    {
        return (currentTime-returnTime)*0.001;
    }
};
Operation *Operation::op=NULL;
int main()
{
    BookDetails b1=BookDetails(123,"mathematics","rahul","12333");
    StudentDetail s1=StudentDetail("cse21238","John","210011");
     StudentDetail s2=StudentDetail("cse212388","Jon","211011");
    Operation *op1=Operation::getInstance();
    Operation *op2=Operation::getInstance();
    op1->issueBook(s1,b1);
    op2->issueBook(s2,b1);
    return 0;
}