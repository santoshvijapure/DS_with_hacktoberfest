# DS_with_hackoberfest

# 🎃 HacktoberFest Starter Project 🎃



Use this project to make your first contribution to an open source project on GitHub. Practice making your first pull request to a public repository before doing the real thing!

Celebrate [Hacktoberfest](https://hacktoberfest.digitalocean.com/) by getting involved in the open source community by completing some simple tasks in this project.

This repository is open to all members of the GitHub community. Any member may contribute to this project without being a collaborator.

[https://github.com/santoshvijapure/DS_with_hacktoberfest/](https://github.com/santoshvijapure/DS_with_hacktoberfest/)

## What is Hacktoberfest?
A month-long celebration from October 1st - 31st sponsored by [Digital Ocean](https://hacktoberfest.digitalocean.com/) and [GitHub](https://github.com/blog/2433-celebrate-open-source-this-october-with-hacktoberfest) to get people involved in [Open Source](https://github.com/open-source). Create your very first pull request to any public repository on GitHub and contribute to the open source developer community.

[https://hacktoberfest.digitalocean.com/](https://hacktoberfest.digitalocean.com/)

## How to contribute to this project
Here are 3 quick and painless ways to contribute to this project:

* Add your name to the `CONTRIBUTORS.md` file
* Add a profile page to the `profiles` directory
* build your favourite  Data Structure(vanilla version) in your favourite language and add it to the respective language folder.
* if the folder of your language is not available then create a new folder and add your code in it.

Choose one or all, make a pull request for your work and wait for it to be merged!

## Getting started
* Fork this repository (Click the Fork button in the top right of this page, click your Profile Image)
* Clone your fork down to your local machine

```markdown
git clone https://github.com/your-username/DS_with_hacktoberfest.git
```

* Create a branch

```markdown
git checkout -b branch-name
```

* Make your changes (choose from any task below)
* Commit and push

```markdown
git add .
git commit -m 'Commit message'
git push origin branch-name
```

* Create a new pull request from your forked repository (Click the `New Pull Request` button located at the top of your repo)
* Wait for your PR review and merge approval!
* __Star this repository__ if you had fun!

## Choose from these tasks
### 1. Add your name
Add your name to the `CONTRIBUTORS.md` file using the below convention:

```markdown
#### Name: [YOUR NAME](GitHub link)
- Place: City, State, Country
- Bio: Who are you?
- GitHub: [GitHub account name](GitHub link)
```

### 2. Add a profile page
Add a `Your_Name.md` file to the `profiles` directory. Use any combination of content and Markdown you'd like. Here is an example:

```markdown
# Your Name

### Location

Your City/Country

### Academics

Your School

### Interests

- Some Things You Like

### Development

- Inventor of the My Pillow

### Projects

- [My Project](GitHub Link) Short Description

### Profile Link

[Your Name](GitHub Link)
```

### 3. Create vanilla version of your favourite data structure in your favouite language 
Add a `nameOfDataStructure_yourusername.xx` Program to Respective folder depending on the programming language of your choice! (add new folder if folder of  your languge is not present) Here is an example:

```C++
// LANGUAGE: c++
// ENV: gcc
// AUTHOR: Santoshvijapure
// GITHUB: https://github.com/santoshvijapure

#include <iostream>
using namespace std; 
int stack[100], n=100, top=-1;
void push(int val) {
   if(top>=n-1)
      cout<<"Stack Overflow"<<endl; 
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
      cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
         cout<<stack[i]<<" ";
         cout<<endl;
   } else
      cout<<"Stack is empty";
}
int main() {
   int ch, val; 
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {   
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4); 
      return 0;
}
```

Name the file `nameOfDataStructure_yourusername.xx`. e.g., `Stack_santoshvijapure.cpp` or `Stack_santoshvijapure.py`.

Don't forget to include the comments as seen above. Feel free to include additional information about the language you choose in your comments too! Like a link to a helpful introduction or tutorial. 

Here is my `Stack_santoshvijapure.cpp` example: [Stack_santoshvijapure.cpp](https://github.com/santoshvijapure/DS_with_hacktoberfest/blob/master/Data_Structures/C%2B%2B/Stack_santoshvijapure.cpp)

## BONUS!
* See profiles submitted by fellow coders from around the globe ... from Kathmandu to Copenhagen.
* Discover some obscure to new and trending languages ... from BrainFuck to Groovy.
* Check out some very creative ways to program data Structures in diffrent languages.

## Reference links
Here is a great tutorial for creating your first pull request by [Roshan Jossey](https://github.com/Roshanjossey):
[https://github.com/Roshanjossey/first-contributions](https://github.com/Roshanjossey/first-contributions)

Managing your Forked Repo: [https://help.github.com/articles/fork-a-repo/](https://help.github.com/articles/fork-a-repo/)

Syncing a Fork: [https://help.github.com/articles/syncing-a-fork/](https://help.github.com/articles/syncing-a-fork/)

Keep Your Fork Synced: [https://gist.github.com/CristinaSolana/1885435](https://gist.github.com/CristinaSolana/1885435)

Checkout this list for README examples - Awesome README [![Awesome](https://cdn.rawgit.com/sindresorhus/awesome/d7305f38d29fed78fa85652e3a63e154dd8e8829/media/badge.svg)](https://github.com/sindresorhus/awesome)

Github-Flavored Markdown [https://guides.github.com/features/mastering-markdown/](https://guides.github.com/features/mastering-markdown/)

## Additional references added by contributors
GitHub license explained [https://choosealicense.com](https://choosealicense.com)


# Maintainers 
* Santosh Vijapure : [github](https://github.com/santoshvijapure),[LinkedIn](https://www.linkedin.com/in/santoshvijapure/),[Website](https://santoshvijapure.xyz)
*Prathamesh More :[github](https://github.com/pprathameshmore),[LinkedIn](https://www.linkedin.com/in/prathamesh-more/),[Website](https://pprathameshmore.github.io)
