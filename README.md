# SFML-tpl

> A custom template for creating [SFML](http://www.sfml-dev.org/index-fr.php) app in [C++](https://fr.wikipedia.org/wiki/C%2B%2B) with [JetBrains CLion](https://www.jetbrains.com/clion/).

Welcome! This is a custom template I use for creating SFML C++ projects on **JetBrains CLion**.
The idea was to have a starter app ready to develop.
Currently, it is just a basic template. Nothing really awesome, but still useful if you want to have something to start with.

## Initialize a project

There is not a lot of things to do to setup this project. Just follow the three steps explained below.

### First step:

Firstly, you should think about a project name...

Done ?

So remember of it and just do the next command, replacing the `{PROJECT_NAME}` with your project name.

```
$ git clone https://github.com/ShamsGolap/SFML-tpl.git {PROJECT_NAME}
```


Then, you can change the remote address with the next command:

```
$ git remote set-url origin {URL_OF_YOUR_GIT_PROJECT}
```

### Second step:

When the git project is cloned, launch it with CLion.
Go to the `CMakeLists.txt` file and CTRL + R (Find and Replace) `{PROJECT_NAME}` with whatever you want to name your project.

### Third step:

Once all the steps above are done, open the "CMake" panel on the bottom of CLion.

When you open the app for the first time, CLion sees you had errors about the project name.

Just reload it by clicking on the two blue resync arrows on the left.

It should load again the project and allows you to run it with the green run button on the top right.

### Fourth step:

Did I say only three steps? Dude, this last one is just: Enjoy!


## Any troubles?

Let me know if this process represents any failure by creating a new Issue ticket.
Also, let me know if you want to have some screenshots about the CLion interface.
