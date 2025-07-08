# CPP Lists -> Modules 0 to 4

| ![cpp-list-0to4](https://github.com/user-attachments/assets/04a63315-559b-4bc3-a222-ce8323b7baee "CPP Lists 0 to 4") | WIP project list about C++ Modules (0 to 4), from 42 school - @42sp | Grade: not evaluated yet |
| :-: | :-: | :-: |


> [!Important]
> - Module 00 -> basics about Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff
> - Module 01 -> foundations about Memory allocation, pointers to members, references and switch statements
> - Module 02 -> training Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form
> - Module 03 -> weird Inheritance, lol
> - Module 04 -> more Subtype Polymorphism, Abstract Classes, and Interfaces

https://cplusplus.com/doc/tutorial

https://www.learncpp.com/

> [!NOTE]
> This project has a few tests with Google Tests <br>
> ![image](https://github.com/user-attachments/assets/8b234810-9a88-4903-97ab-0ea2f906fb32)


## Makefile Targets

A set of convenient Makefile targets is provided to help you work with Docker and development tasks in this project:

| Target         | Description                                                                                   |
|----------------|----------------------------------------------------------------------------------------------|
| **build**      | Build and start the Docker container in detached mode.                                        |
| **go**         | Build/start the container, run preparations, then open an interactive shell in the app.       |
| **stop**       | Stop the running Docker container.                                                            |
| **down**       | Stop and remove the Docker container and associated resources.                                |
| **reload-docker** | Stop, rebuild, and restart the Docker container.                                             |
| **ps**         | List all Docker containers.                                                                   |
| **deep-clean** | Clean up unused Docker builder cache (frees disk space).                                      |

### Usage

To run any of these tasks, use:

```sh
make <target>
