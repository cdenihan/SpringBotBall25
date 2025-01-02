<h1 align="center">BotBall '25: Spring Season!</h1>
<div align="center">
<i>Sponsored by GMHS' Mr. Skinner</i>

<a href="https://github.com/Steam09/SpringBotBall25/blob/master/LICENSE"><img src="https://img.shields.io/github/license/Steam09/SpringBotBall25?color=2b9348" alt="License Badge"/></a>
</div>

# Hello Everyone!
This is the respository which will house (most of) the documentation and code for Team 504 at GMHS. The main goal is for anyone (I mean anyone!) at any skill set to understand the backend of the robots, rather than what is shown on streaming services (e.g. Youtube). 

## 💻 Technologies & Tools
![](https://img.shields.io/badge/OS-Linux-informational?style=flat&logo=linux&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/OS-Ubuntu-informational?style=flat&logo=ubuntu&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/OS-Windows-informational?style=flat&logo=windows11&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Editor-Zed-informational?style=flat&logo=zedindustries&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Notes-Obsidian-informational?style=flat&logo=obsidian&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Code-C++-informational?style=flat&logo=cplusplus&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Code-C-informational?style=flat&logo=c&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Tools-Docker-informational?style=flat&logo=docker&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Tools-GDBServer-informational?style=flat&logo=&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Shell-Bash-informational?style=flat&logo=gnu-bash&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Terminal-GNOME-informational?style=flat&logo=gnometerminal&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Collab-Github-informational?style=flat&logo=github&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/VControl-Git-informational?style=flat&logo=git&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/VControl-Drive-informational?style=flat&logo=googledrive&logoColor=white&color=ccffcc)
![](https://img.shields.io/badge/Comms-Discord-informational?style=flat&logo=discord&logoColor=white&color=ccffcc)

Experience with these will make your lives easier, but are not required! They will be explained throughout. 

## 🎤 Communication

Of course, the biggest part of any project is ample amounts of communication. Things such as Discord, Github, and Google Drive helped our team make sure that we can give each other proper information to do our seperate parts. 

## 🌐 Useful Links

Throughout my programming time, these are the places that I would pull up the **most**, and could be of use to you:

- [Stack Overflow](https://stackoverflow.com/)
- [KIPR 2024 GCER Papers](https://www.kipr.org/gcer-2024)
- [KIPR Library](https://www.kipr.org/doc/modules.html)
- [Github Library](https://github.com/kipr/libwallaby)

## 💾 Compilation

Now you've reached the part where it is better to have coding experience. For BotBall, the given setup is logging into the web IDE through [192.168.125.1:8888](https://192.168.125.1:8888) once you've connected through internet in your respective Wombat. 

This is a **great** idea for first-time programmers, but if you have a lick of experience it can get a bit clunky. Last year at GCER there was a paper explaining [(Read Here!)](https://www.kipr.org/wp-content/uploads/2024/08/Usage_of_Modern_IDEs_for_Developing_Robotics_Applications.pdf) the benefits of compiling on the computer and then running on the wombat. It was then elevated (in the same paper) the benefits of debugging with a GDB server. More on this will be explained how to apply it further down. 

## 🕹️ Programming Cont.

BotBall in the whole is an autonomous robotics program, where once the lights are on, hands are off! This means that we need to implement _proper_ use of the built-in MPU 9250, a 9-axis sensor that contains a gyroscope, accelerometer, and gyrometer. We will use all three in our robots, but you'll need to figure out the semantics yourself (can't be giving out answers).

Now that you have the basic information, head over to ```SpringBotBall25/CodeDocumentation/Beginners.md``` to learn about all of this!

