# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ Project and Portfolio I ]

- **[ Skyler Roberson ]**
- **[ October 4th, 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear]: Clear the Screen
- [ pwd ]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -a ]: List files and folders, including invisible files
- [ ls -lah ]: List all files and folders, in human readable form
- [ cd folderName ]: Change directory
- [ cd / ]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd ../.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ When I typed cd into terminal and dragged the VersionControl file into it I watched it change the directory from just my C:\Users\windowName to C:\Users\Name\Downloads\VersionControl. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[Local Version Control: Keeps different versions of files on one computer.]
[ Centralized Version Control: Stores files and their history on one central server that multiple people can access. ]
[Distributed Version Control: Gives each user a complete copy of the repository and its history. Git is an example of distributed version control.]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone repositoryURL ]: Clone a repository
- [ git config --global user.name "Your Name" ]: Set-up a global user name
- [ git config --global user.email "YOUR@EMAIL.COM" ]: Set-up a global email address (to match my GitHub account email)
- [ git status ]: Shows the current state of your directory and staging area
- [ git add . ]: Add modified files to the next commit
- [ git commit -m "message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[ To connect to GitHub using HTTPS, I first copied the url of my repository from GitHub. After which I open terminal and use the git clone (URL) command which resulted in the repository being downloaded to my laptop, then I used cd to enter the repository folder and realized I could probably use the git add ., git commit -m "Message", and git push commands from the terminal. ]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [A .gitignore file tells Git which files and folders should not be tracked or uploaded to the repository. It is useful for ignoring temporary files, generated files, and other stuff that you don't have to upload to Git in order to copy a working version from a repository]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [My best guess is that its something to do with mac computers since I've never actually seen one; it probably just stores info on how folders are displayed which isn't really needed for most projects.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [I'd say it'd be a safe bet to add the build folders to .gitignore because it contains files generated when a program is compiled, these files can be created again when the project is built so there's no real point in storing them in the repository]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]
Honestly the resources I found most helpful this week were the terminal lessons and the obsidian lessons, it hadn't really clicked to me before that I could use Git through the terminal or that Obsidian was such a catch all documentation tool



**Terminal Commands**  
[Ubuntu: The Linux Command Line for Beginners](https://ubuntu.com/tutorials/command-line-for-beginners?utm_source=chatgpt.com#1-overview)

**Three Types of Version Control**  
[Git: About Version Control](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control)

**Git Commands**  
[Git Reference Documentation](https://git-scm.com/docs)

**Connecting to GitHub using Terminal**  
[GitHub Docs: Cloning a Repository](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository)

**Using .gitignore and Why it's Important**  
[GitHub Docs: Ignoring Files](https://docs.github.com/en/get-started/git-basics/ignoring-files)
