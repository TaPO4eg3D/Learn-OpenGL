# InitGL

## Overview
### Why another guide?
There are some great resources available online on the basics of graphics programming with OpenGL. Unfortunately, most of them assume that the reader already has all the necessary libraries and software set up beforehand. For those not familiarized with the process of setting up a portable C++ project, it can be quite confusing. I decided to create this guide in order address that issue. By the time you reach the end, you should have everything you need to successfully get started with other OpenGL tutorials.

### What this guide covers
This guide will explain how to create a portable project structure (using CMake), integrate some libraries (GLFW and glad), and build / run a simple OpenGL application.

### Prerequisites
In order to follow this guide, you will need to know the basics of your build system (how to compile / run code). The guide is compatible with any build system that CMake supports (examples include Visual Studio, Xcode, and Makefiles).

## The build system
There are many viable operating systems and compilers available for use today. Trying to set up and manage individual project files for each of them would be a tedious, laborsome, and error-prone task. Luckily, you don't have to! There exists a great tool, named CMake, which manages the specifics of each operating system / compiler / IDE for you. To lazily quote their 'About' page:

> CMake is an extensible, open-source system that manages the build process in an operating system and in a compiler-independent manner.
> (https://cmake.org/overview/)

With CMake, we can write instructions on how to build our code once and have it work in a variety of environments. In order to make use of CMake, you'll need to download and install it from https://cmake.org/download/ (just grab the latest version available for your platform).

## Source control
This guide uses git as source control (it is hosted on GitHub, and it pulls in a library via submodules). You don't necessarily need to use git in order to follow the guide, but it is reccomended. If you don't have git, you can download it from https://git-scm.com/. If you prefer to have a visual client, you can download one from https://desktop.github.com/. If you are not familiar with git (or source control in general), there is a helpful tutorial at https://try.github.io/.
