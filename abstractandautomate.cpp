/*
  
lab19: abstract & automate lab18
COMSC-210
Naveen Islam
IDE: emacs (i code in emacs and import it into the repo folder)

 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct Node{
  double rating;
  string comments;
  Node* next;
};

// class Movie
class Movie{

// private member variables
private:
  string movieTitle;
  Node* review;

public:
  // constructor
  Movie (string mvTitle) {
    movieTitle = mvTitle;
    review = nullptr;
  }
  
  
  // function nodeToHead. Creates a new node and inputs the users rating and comment and inserts it to the beginning of the list
  void nodeToHead(string& userComments) {
    double randRat = 1.00 + (rand() % 400) / 100.00;
    Node* newNode = new Node();
    newNode->rating = randRat;
    newNode->comments = userComments;
    newNode->next = review;
    review = newNode;
  }

  // function displayLinkedList. displays the users rating and comment for all reviews in the linked list
  void displayLinkedList() {
    int reviewNum = 1;
    double averageAdder = 0;
    cout << "Movie Title: " << movieTitle << endl;
    
    Node* temp = review;

    while (temp!= nullptr) {
      cout << "> Review #" << reviewNum << ": " << temp->rating << ": "<< temp->comments << endl;
      
      averageAdder += temp->rating;
      reviewNum++;
      temp = temp->next;
    }
    // outputs the average
    cout << "> Average: " << (averageAdder / (reviewNum - 1)) << endl;
    cout << endl;
  }
};

// function prototypes
void fileReader(Movie& movie, const string& file);

// function fileReader. reads comments from file and adds it to the movie objects
void fileReader(Movie& movie, const string& file) {
  ifstream inFile(file);
  string comment = "";
  while (getline(inFile, comment)) {
    movie.nodeToHead(comment);
  }
  inFile.close();
}
  

// main function
int main() {
  const int SIZE = 4;

  // creates an array movies of size SIZE (4) with Movie objects
  Movie movies[SIZE] = {Movie("John Wick"), Movie("John Wick 2"), Movie("John Wick 3"), Movie("John Wick 4")};

  // from external files, reads the comments for each file
  fileReader(movies[0], "John_Wick.txt");
  fileReader(movies[1], "John_Wick2.txt");
  fileReader(movies[2], "John_Wick3.txt");
  fileReader(movies[3], "John_Wick4.txt");

  // displays the reviews by calling the displayLinkedList function in a for loop
  for (int i = 0; i < SIZE; i++) {
    movies[i].displayLinkedList();
  }
  
  return 0;
}

